// Taken from http://zipcpu.com/blog/2017/06/21/looking-at-verilator.html
#include <filesystem>
#include <iostream>
#include <verilated_vcd_c.h>

const int ISA = 0xBFC00000; //INSTRUCTION_START_ADDRESS
const int RAM_SIZE = 1 << 31; 

class TESTBENCH
{
public:
	const unsigned int TIME_UNIT = 2;
	unsigned long m_tickcount;
	VerilatedVcdC *m_trace = nullptr;
	MIPS_Harvard_TB *m_core = nullptr;
	bool trace = true;

	std::string vcdname;
	std::map<int, uint32_t> memory;

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
		m_core = new MIPS_Harvard_TB;
		opentrace( vcdname );
		this->vcdname = std::string( vcdname );
		m_tickcount = 0l;
		m_core->clk_enable = 1;

		memory[ISA + 0] = uint32_t(0b00100100000000100000000100000000); //addiu v0 zero 0x100, 0x24020100
		memory[ISA + 4] = uint32_t(0b10001100000000100000000001100100);
		memory[ISA + 8] = uint32_t(0b00000000000000000000000000001000); //jr 0
		memory[100] = 100;
	}

	virtual ~TESTBENCH( void )
	{
		close();
		delete m_core;
		m_core = NULL;
	}

	virtual void reset( void )
	{
		m_core->reset = 1;
		this->tick();
		m_core->reset = 0;
	}

	virtual void tick( void )
	{
		// we do this
		m_tickcount++;

		// Allow any combinatorial logic to settle before we tick
		// the clock.  This becomes necessary in the case where
		// we may have modified or adjusted the inputs prior to
		// coming into here, since we need all combinatorial logic
		// to be settled before we call for a clock tick.
		//
		m_core->clk = 0;
		m_core->eval();
		update_instruction_output();

		//
		// Here's the new item:
		//
		//	Dump values to our trace file
		//
		if ( trace )
			m_trace->dump( TIME_UNIT * m_tickcount - 2 );

		// Repeat for the positive edge of the clock
		m_core->clk = 1;
		m_core->eval();
		update_RAM_output();
		update_instruction_output();
		m_core->eval();
		if ( trace )
			m_trace->dump( TIME_UNIT * m_tickcount );

		// Now the negative edge
		m_core->clk = 0;
		m_core->eval();
		update_instruction_output();
		m_core->eval();
		if ( m_trace )
		{
			// This portion, though, is a touch different.
			// After dumping our values as they exist on the
			// negative clock edge ...
			m_trace->dump( TIME_UNIT * m_tickcount + TIME_UNIT / 2);
			//
			// We'll also need to make sure we flush any I/O to
			// the trace file, so that we can use the assert()
			// function between now and the next tick if we want to.
			m_trace->flush();
		}
	}

	void update_RAM_output(){
		m_core->data_readdata = memory[m_core->data_address];
	}

	void update_instruction_output(){
		m_core->instr_readdata = memory[m_core->instr_address];
	}
	virtual bool done( void )
	{
		return ( Verilated::gotFinish() );
	}
	// Open/create a trace file
};