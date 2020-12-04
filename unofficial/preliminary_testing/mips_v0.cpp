#include "MIPS_Harvard_obj_dir/MIPS_Harvard_TB.h"
#include "tesbench_outline.hpp"
#include "verilated.h"
#include <iostream>

int main( int argc, char **argv, char **env )
{

	std::cout << "Verilating" << std::endl;
	Verilated::commandArgs( argc, argv );

	TESTBENCH tb("trace.vcd");
	tb.tick();
	tb.m_core->instr_readdata = uint32_t( 0b100011000000000100000000000000 );
	for(int i = 0; i < 50; i++){
		tb.tick();
		tb.m_core->instr_readdata = uint32_t( 0b100111000000000100000000000000 );
	
	}
	
}