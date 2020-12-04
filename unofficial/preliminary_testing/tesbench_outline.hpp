// Taken from http://zipcpu.com/blog/2017/06/21/looking-at-verilator.html
#include <filesystem>
#include <iostream>
#include <verilated_vcd_c.h>

class TESTBENCH
{
public:
	unsigned long m_tickcount;
	VerilatedVcdC *m_trace = nullptr;
	MIPS_Harvard_TB *m_core = nullptr;
	bool trace = true;

	std::string vcdname;
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

		//
		// Here's the new item:
		//
		//	Dump values to our trace file
		//
		if ( trace )
			m_trace->dump( 10 * m_tickcount - 2 );

		// Repeat for the positive edge of the clock
		m_core->clk = 1;
		m_core->eval();
		if ( trace )
			m_trace->dump( 10 * m_tickcount );

		// Now the negative edge
		m_core->clk = 0;
		m_core->eval();
		if ( m_trace )
		{
			// This portion, though, is a touch different.
			// After dumping our values as they exist on the
			// negative clock edge ...
			m_trace->dump( 10 * m_tickcount + 5 );
			//
			// We'll also need to make sure we flush any I/O to
			// the trace file, so that we can use the assert()
			// function between now and the next tick if we want to.
			m_trace->flush();
		}
	}

	virtual bool done( void )
	{
		return ( Verilated::gotFinish() );
	}
	// Open/create a trace file
};