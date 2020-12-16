// Taken from http://zipcpu.com/blog/2017/06/21/looking-at-verilator.html
#include <filesystem>
#include <fstream>
#include <iostream>
#include <cassert>
#include <sstream>
#include <verilated_vcd_c.h>
#include <bitset>

const int ISA = 0xBFC00000; //INSTRUCTION_START_ADDRESS
const int RAM_SIZE = 1 << 31; 

class RAM{
private:
	std::map<uint32_t, uint8_t> memory;
public:
	uint32_t operator[](uint32_t pos){
		uint32_t temp = 0;
		for(int i = 0; i <4; i++){
			temp += ((uint32_t)memory[pos + i]) << (8 * i);
		}
		return temp;
	}
	void set(const uint32_t& pos, const uint32_t value, const uint8_t byteenable){
		std::bitset<8> encoded_byteenable(byteenable);
		if(memory.find(pos) == memory.end()){memory[pos] = 0;}
		if(memory.find(pos+1) == memory.end()){memory[pos+1] = 0;}
		if(memory.find(pos+2) == memory.end()){memory[pos+2] = 0;}
		if(memory.find(pos+3) == memory.end()){memory[pos+3] = 0;}

		if(encoded_byteenable[3]) memory[pos + 3] = (value>>24);
		if(encoded_byteenable[2]) memory[pos + 2] = (value<<8)>>24;
		if(encoded_byteenable[1]) memory[pos + 1] = (value<<16)>>24;
		if(encoded_byteenable[0]) memory[pos] = (value<<24)>>24;
	}
	void clear(){
		memory.clear();
	}
	void dump_memory() const{
		int i = 0;
		uint32_t temp = 0;
		for(auto x : memory){
			temp += ((uint32_t)x.second) << (8*i);
			i++;
			if(i == 4){
				std::cout<<std::hex<<x.first - 3<<" "<<temp<<std::endl;
				temp = 0;
				i= 0;
			}
		}
	}
};
class TESTBENCH
{
public:
	const unsigned int TIME_UNIT = 2;
	unsigned long m_tickcount;
	VerilatedVcdC *m_trace = nullptr;
	MIPS_Bus_TB *m_core = nullptr;
	bool trace = true;

	std::string vcdname;
	std::string curr_program_name = "NULL";
	RAM memory;
	virtual void opentrace( const char *vcdname )
	{
		if ( !m_trace )
		{
			std::cout << "Started Tracing" << std::endl;
			Verilated::traceEverOn( true );
			m_trace = new VerilatedVcdC;
			m_core->trace( m_trace, 99 );
			m_trace->open( vcdname );
		}
	}
	// Close a trace file
	virtual void close( void )
	{
		std::cout << "Writing trace to" << std::filesystem::current_path() << "/" << vcdname << std::endl;
		if ( m_trace )
		{
			m_trace->close();
			m_trace = NULL;
		}
	}
	TESTBENCH( const char *vcdname )
	{
		m_core = new MIPS_Bus_TB;
		opentrace( vcdname );
		this->vcdname = std::string( vcdname );
		m_tickcount = 0l;
	}

	void load_program(std::string program){
		memory.clear();
		curr_program_name = program;
		std::fstream file;
		file.open(program);
		assert(file.is_open());
		std::string line;
		for(int i = 0;std::getline(file, line);i+=4){
			if(line[0]=='.'){
				std::string pos = line.substr(1, pos.size() -1 );
				if(pos == "main") i = ISA - 4; 
				else{
					i = std::stol(pos,nullptr,16);
					i -= 4;
				}
				continue;
			}
			std::stringstream ss(line);
			uint32_t hex;
			ss>>std::hex>>hex;
			memory.set(i,hex, 31);
		}
	}
	bool run_program(int limit=100){
		reset();
		for(int i = 0; m_core->active;){
			tick();
			i++;
			if(i==limit){
				std::cout<<"\n\tFailed Program - "<<curr_program_name<<"\n\tClock limit surpassed"<<std::endl;
				return false;
			}
		}
		std::cout<<"\tPassed Program - "<<curr_program_name<<std::endl;
		return true;
	}
	void dump_memory(){
		memory.dump_memory();
	}
	virtual ~TESTBENCH( void )
	{
		close();
		delete m_core;
		m_core = NULL;
	}

	virtual void reset( void )
	{
		m_core->reset = 0;
		m_core->eval();
		m_core->reset = 1;
		this->tick();
		m_core->reset = 0;
	}

	virtual void tick( void )
	{
		m_tickcount++;
		for(int clk = 0; clk < 2; ++clk)
        {
            m_core->eval();
        	m_trace->dump((2 * m_tickcount) + clk);

            if (clk==1) m_core->clk = !m_core->clk;

         }
			if( m_core->write == 1){
				update_memory_file();
			}
			if(m_core->read == 1){
				update_data_output();
			}

	}

	void update_data_output(){
		if(m_core->read){
			m_core->readdata = memory[m_core->address];
		}
	}
	void update_memory_file(){
		std::cout<<"now "<<m_core->address<<std::endl;
		memory.set(m_core->address,m_core->writedata, m_core->byteenable);
	}


	virtual bool done( void )
	{
		return ( Verilated::gotFinish() );
	}
	// Open/create a trace file
};