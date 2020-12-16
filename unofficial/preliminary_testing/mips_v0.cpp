#define BUS

#ifdef BUS
	#include "MIPS_Bus_obj_dir/MIPS_Bus_TB.h"
	#include "testbench_outline_Bus.hpp"
#endif
#ifdef HARVARD
	#include "MIPS_Harvard_obj_dir/MIPS_Harvard_TB.h"
	#include "testbench_outline_Harvard.hpp"
#endif

#include "verilated.h"
#include <iostream>
#include <map>

int main( int argc, char **argv, char **env )
{

	std::cout << "Verilating MIPS_HARVARD" << std::endl;
	Verilated::commandArgs( argc, argv );

	TESTBENCH tb("trace.vcd");
	//tb.load_program("../programs/test_ALU.txt");
	//tb.run_program();
	//tb.load_program("../programs/nop.txt");
	//tb.run_program();
	tb.load_program("../programs/branch_test_ALU.txt");
	tb.dump_memory();
	//tb.run_program();
	//tb.load_program("../programs/memory_access_testing.txt");
	//tb.dump_memory();
	tb.run_program();
	tb.dump_memory();
	
	
}