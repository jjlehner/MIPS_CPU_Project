#include "MIPS_Harvard_obj_dir/MIPS_Harvard_TB.h"
#include "tesbench_outline.hpp"
#include "verilated.h"
#include <iostream>

uint32_t getRamValue(uint32_t addr){
	
	return uint32_t(0x00000008);
}
int main( int argc, char **argv, char **env )
{

	std::cout << "Verilating" << std::endl;
	Verilated::commandArgs( argc, argv );

	TESTBENCH tb("trace.vcd");
	tb.m_core->instr_readdata = 0;
	tb.tick();
	for(int i = 0; i < 200; i++){
		tb.m_core->instr_readdata = getRamValue(tb.m_core->instr_address);
		std::cout<<tb.m_core->instr_address<<" "<<getRamValue(tb.m_core->instr_address)<<" "<<std::endl;
		tb.tick();

	}

	
}