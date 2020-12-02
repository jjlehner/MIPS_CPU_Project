#include "MIPS_Harvard_obj_dir/MIPS_Harvard_TB.h"
#include "verilated.h"
#include "tesbench_outline.hpp"
#include <iostream>

int main( int argc, char **argv, char **env )
{
	Verilated::commandArgs( argc, argv );

	MIPS_Harvard_TB *mips = new MIPS_Harvard_TB;
	TESTBENCH testbench;
	testbench.m_core->instr_readdata = uint32_t(0b100011000000000100000000000000);

	
}