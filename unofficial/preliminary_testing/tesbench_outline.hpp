//Taken from http://zipcpu.com/blog/2017/06/21/looking-at-verilator.html
class TESTBENCH {	
public:
	MIPS_Harvard_TB *m_core;
	unsigned long	m_tickcount;

	TESTBENCH(void) {
		m_core = new MIPS_Harvard_TB;
		m_tickcount = 0l;
		m_core->clk_enable = 1;
	}

	virtual ~TESTBENCH(void) {
		delete m_core;
		m_core = NULL;
	}

	virtual void reset(void) {
		m_core->reset = 1;
		this->tick();
		m_core->reset = 0;
	}

	virtual void tick(void) {
		m_tickcount++;

		m_core->clk = 0;
		m_core->eval();

		m_core->clk = 1;
		m_core->eval();

		m_core->clk = 0;
		m_core->eval();
	}

	virtual bool done(void)
	{ 
		return (Verilated::gotFinish());
	}
	virtual	void	opentrace(const char *vcdname) {
		if (!m_trace) {
			m_trace = new VerilatedVcdC;
			m_core->trace(m_trace, 99);
			m_trace->open(vcdname);
		}
	}
};