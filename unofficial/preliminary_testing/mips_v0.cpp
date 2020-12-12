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
	tb.run_program();
	tb.load_program("../programs/branch_test_ALU.txt");
	tb.run_program();
	
}