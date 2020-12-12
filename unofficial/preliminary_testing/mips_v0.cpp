#include "MIPS_Harvard_obj_dir/MIPS_Harvard_TB.h"
#include "tesbench_outline.hpp"
#include "verilated.h"
#include <iostream>
#include <map>

int main( int argc, char **argv, char **env )
{

	std::cout << "Verilating" << std::endl;
	Verilated::commandArgs( argc, argv );

	TESTBENCH tb("trace.vcd");
	tb.load_program("../programs/test_ALU.txt");
	tb.dump_memory();
	tb.run_program();
	std::cout<<"Final Register V0 Value - "<<tb.m_core->register_v0<<std::endl;
	
}