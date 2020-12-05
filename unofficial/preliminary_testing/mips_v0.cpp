#include "MIPS_Harvard_obj_dir/MIPS_Harvard_TB.h"
#include "tesbench_outline.hpp"
#include "verilated.h"
#include <iostream>

uint32_t getRamValue(uint32_t addr){
	addr /= 4;
	if((addr % 2) == 0 && addr != 0){

		return uint32_t(0b00100110010100000000000000000101);
	}
	if((addr % 2) == 1 && addr != 1){

		return uint32_t(0b00000010001100001000100000100000);
	}

	return uint32_t(0);
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