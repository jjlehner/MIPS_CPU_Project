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
	tb.tick();
	tb.m_core->reset = 1;
	tb.tick();
	tb.m_core->reset = 0;
	
	for(int i = 0; tb.m_core->active && i < 20; i++){
		tb.tick();
	}
	
	std::cout<<"Final Register V0 Value - "<<tb.m_core->register_v0<<std::endl;
	
}