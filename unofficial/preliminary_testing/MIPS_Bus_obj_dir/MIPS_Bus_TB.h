// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Primary design header
//
// This header should be included by all source files instantiating the design.
// The class here is then constructed to instantiate the design.
// See the Verilator manual for examples.

#ifndef _MIPS_BUS_TB_H_
#define _MIPS_BUS_TB_H_  // guard

#include "verilated.h"

//==========

class MIPS_Bus_TB__Syms;
class MIPS_Bus_TB_VerilatedVcd;


//----------

VL_MODULE(MIPS_Bus_TB) {
  public:
    
    // PORTS
    // The application code writes and reads these signals to
    // propagate new values into/out from the Verilated model.
    VL_IN8(clk,0,0);
    VL_IN8(reset,0,0);
    VL_OUT8(active,0,0);
    VL_OUT8(write,0,0);
    VL_OUT8(read,0,0);
    VL_IN8(waitrequest,0,0);
    VL_OUT8(byteenable,3,0);
    VL_OUT(register_v0,31,0);
    VL_OUT(address,31,0);
    VL_OUT(writedata,31,0);
    VL_IN(readdata,31,0);
    
    // LOCAL SIGNALS
    // Internals; generally not touched by application code
    // Anonymous structures to workaround compiler member-count bugs
    struct {
        CData/*0:0*/ mips_cpu_bus__DOT__internal_clk;
        CData/*0:0*/ mips_cpu_bus__DOT__HALT_fetch;
        CData/*0:0*/ mips_cpu_bus__DOT__program_counter_src_decode;
        CData/*0:0*/ mips_cpu_bus__DOT__register_write_decode;
        CData/*0:0*/ mips_cpu_bus__DOT__memory_to_register_decode;
        CData/*0:0*/ mips_cpu_bus__DOT__memory_write_decode;
        CData/*1:0*/ mips_cpu_bus__DOT__ALU_src_B_decode;
        CData/*1:0*/ mips_cpu_bus__DOT__register_destination_decode;
        CData/*0:0*/ mips_cpu_bus__DOT__branch_decode;
        CData/*5:0*/ mips_cpu_bus__DOT__ALU_function_decode;
        CData/*0:0*/ mips_cpu_bus__DOT__program_counter_multiplexer_jump_decode;
        CData/*0:0*/ mips_cpu_bus__DOT__using_HI_LO_decode;
        CData/*0:0*/ mips_cpu_bus__DOT__j_instruction_decode;
        CData/*0:0*/ mips_cpu_bus__DOT__HI_register_write_decode;
        CData/*0:0*/ mips_cpu_bus__DOT__LO_register_write_decode;
        CData/*0:0*/ mips_cpu_bus__DOT__HALT_decode;
        CData/*1:0*/ mips_cpu_bus__DOT__register_destination_execute;
        CData/*0:0*/ mips_cpu_bus__DOT__memory_to_register_execute;
        CData/*0:0*/ mips_cpu_bus__DOT__memory_write_execute;
        CData/*4:0*/ mips_cpu_bus__DOT__write_register_execute;
        CData/*1:0*/ mips_cpu_bus__DOT__ALU_src_B_execute;
        CData/*5:0*/ mips_cpu_bus__DOT__ALU_function_execute;
        CData/*0:0*/ mips_cpu_bus__DOT__HI_register_write_execute;
        CData/*0:0*/ mips_cpu_bus__DOT__LO_register_write_execute;
        CData/*0:0*/ mips_cpu_bus__DOT__register_write_execute;
        CData/*0:0*/ mips_cpu_bus__DOT__program_counter_multiplexer_jump_execute;
        CData/*0:0*/ mips_cpu_bus__DOT__j_instruction_execute;
        CData/*0:0*/ mips_cpu_bus__DOT__using_HI_LO_execute;
        CData/*0:0*/ mips_cpu_bus__DOT__HALT_execute;
        CData/*5:0*/ mips_cpu_bus__DOT__op_execute;
        CData/*4:0*/ mips_cpu_bus__DOT__Rs_execute;
        CData/*4:0*/ mips_cpu_bus__DOT__Rt_execute;
        CData/*4:0*/ mips_cpu_bus__DOT__Rd_execute;
        CData/*0:0*/ mips_cpu_bus__DOT__register_write_memory;
        CData/*4:0*/ mips_cpu_bus__DOT__write_register_memory;
        CData/*0:0*/ mips_cpu_bus__DOT__memory_to_register_memory;
        CData/*0:0*/ mips_cpu_bus__DOT__memory_write_memory;
        CData/*0:0*/ mips_cpu_bus__DOT__HI_register_write_memory;
        CData/*0:0*/ mips_cpu_bus__DOT__LO_register_write_memory;
        CData/*0:0*/ mips_cpu_bus__DOT__program_counter_multiplexer_jump_memory;
        CData/*0:0*/ mips_cpu_bus__DOT__j_instruction_memory;
        CData/*0:0*/ mips_cpu_bus__DOT__HALT_memory;
        CData/*5:0*/ mips_cpu_bus__DOT__op_memory;
        CData/*3:0*/ mips_cpu_bus__DOT__byteenable_memory;
        CData/*0:0*/ mips_cpu_bus__DOT__register_write_writeback;
        CData/*0:0*/ mips_cpu_bus__DOT__HI_register_write_writeback;
        CData/*0:0*/ mips_cpu_bus__DOT__LO_register_write_writeback;
        CData/*0:0*/ mips_cpu_bus__DOT__memory_to_register_writeback;
        CData/*0:0*/ mips_cpu_bus__DOT__HALT_writeback;
        CData/*5:0*/ mips_cpu_bus__DOT__op_writeback;
        CData/*3:0*/ mips_cpu_bus__DOT__byteenable_writeback;
        CData/*4:0*/ mips_cpu_bus__DOT__write_register_writeback;
        CData/*0:0*/ mips_cpu_bus__DOT__stall_fetch;
        CData/*0:0*/ mips_cpu_bus__DOT__stall_decode;
        CData/*0:0*/ mips_cpu_bus__DOT__flush_execute_register;
        CData/*2:0*/ mips_cpu_bus__DOT__forward_A_execute;
        CData/*2:0*/ mips_cpu_bus__DOT__forward_B_execute;
        CData/*1:0*/ mips_cpu_bus__DOT__fetch_state;
        CData/*5:0*/ mips_cpu_bus__DOT__control_unit__DOT__op;
        CData/*4:0*/ mips_cpu_bus__DOT__control_unit__DOT__rt;
        CData/*5:0*/ mips_cpu_bus__DOT__control_unit__DOT__funct;
        CData/*0:0*/ mips_cpu_bus__DOT__hazard_unit__DOT__lwstall;
        CData/*0:0*/ mips_cpu_bus__DOT__hazard_unit__DOT__branchstall;
        IData/*31:0*/ mips_cpu_bus__DOT__instr_address;
    };
    struct {
        IData/*31:0*/ mips_cpu_bus__DOT__program_counter_mux_1_out;
        IData/*31:0*/ mips_cpu_bus__DOT__instruction_decode;
        IData/*31:0*/ mips_cpu_bus__DOT__program_counter_plus_four_decode;
        IData/*31:0*/ mips_cpu_bus__DOT__register_file_output_A_decode;
        IData/*31:0*/ mips_cpu_bus__DOT__register_file_output_B_decode;
        IData/*31:0*/ mips_cpu_bus__DOT__sign_imm_decode;
        IData/*31:0*/ mips_cpu_bus__DOT__comparator_1;
        IData/*31:0*/ mips_cpu_bus__DOT__comparator_2;
        IData/*31:0*/ mips_cpu_bus__DOT__src_A_execute;
        IData/*31:0*/ mips_cpu_bus__DOT__src_B_execute;
        IData/*31:0*/ mips_cpu_bus__DOT__src_A_ALU_execute;
        IData/*31:0*/ mips_cpu_bus__DOT__src_B_ALU_execute;
        IData/*31:0*/ mips_cpu_bus__DOT__write_data_execute;
        IData/*31:0*/ mips_cpu_bus__DOT__ALU_output_execute;
        IData/*31:0*/ mips_cpu_bus__DOT__ALU_HI_output_execute;
        IData/*31:0*/ mips_cpu_bus__DOT__ALU_LO_output_execute;
        IData/*31:0*/ mips_cpu_bus__DOT__sign_imm_execute;
        IData/*31:0*/ mips_cpu_bus__DOT__program_counter_plus_four_execute;
        IData/*31:0*/ mips_cpu_bus__DOT__j_program_counter_execute;
        IData/*31:0*/ mips_cpu_bus__DOT__ALU_output_memory;
        IData/*31:0*/ mips_cpu_bus__DOT__ALU_HI_output_memory;
        IData/*31:0*/ mips_cpu_bus__DOT__ALU_LO_output_memory;
        IData/*31:0*/ mips_cpu_bus__DOT__write_data_memory;
        IData/*31:0*/ mips_cpu_bus__DOT__j_program_counter_memory;
        IData/*31:0*/ mips_cpu_bus__DOT__src_A_ALU_memory;
        IData/*31:0*/ mips_cpu_bus__DOT__src_A_ALU_writeback;
        IData/*31:0*/ mips_cpu_bus__DOT__result_writeback;
        IData/*31:0*/ mips_cpu_bus__DOT__ALU_HI_output_writeback;
        IData/*31:0*/ mips_cpu_bus__DOT__ALU_LO_output_writeback;
        IData/*31:0*/ mips_cpu_bus__DOT__ALU_output_writeback;
        IData/*31:0*/ mips_cpu_bus__DOT__read_data_writeback;
        IData/*31:0*/ mips_cpu_bus__DOT__read_data_writeback_filtered;
        IData/*31:0*/ mips_cpu_bus__DOT__register_file__DOT__HI_reg;
        IData/*31:0*/ mips_cpu_bus__DOT__register_file__DOT__LO_reg;
        IData/*31:0*/ mips_cpu_bus__DOT__alu_input_mux__DOT__src_mux_input_0;
        IData/*31:0*/ mips_cpu_bus__DOT__memory_filter__DOT__temp_filtered;
        QData/*63:0*/ mips_cpu_bus__DOT__alu__DOT__ALU_HI_LO_output;
        IData/*31:0*/ mips_cpu_bus__DOT__register_file__DOT__registers[32];
    };
    
    // LOCAL VARIABLES
    // Internals; generally not touched by application code
    CData/*0:0*/ __VinpClk__TOP__mips_cpu_bus__DOT__internal_clk;
    CData/*0:0*/ __Vclklast__TOP____VinpClk__TOP__mips_cpu_bus__DOT__internal_clk;
    CData/*0:0*/ __Vclklast__TOP__reset;
    CData/*0:0*/ __Vclklast__TOP__clk;
    CData/*0:0*/ __Vchglast__TOP__mips_cpu_bus__DOT__internal_clk;
    IData/*31:0*/ __Vm_traceActivity;
    
    // INTERNAL VARIABLES
    // Internals; generally not touched by application code
    MIPS_Bus_TB__Syms* __VlSymsp;  // Symbol table
    
    // CONSTRUCTORS
  private:
    VL_UNCOPYABLE(MIPS_Bus_TB);  ///< Copying not allowed
  public:
    /// Construct the model; called by application code
    /// The special name  may be used to make a wrapper with a
    /// single model invisible with respect to DPI scope names.
    MIPS_Bus_TB(const char* name = "TOP");
    /// Destroy the model; called (often implicitly) by application code
    ~MIPS_Bus_TB();
    /// Trace signals in the model; called by application code
    void trace(VerilatedVcdC* tfp, int levels, int options = 0);
    
    // API METHODS
    /// Evaluate the model.  Application must call when inputs change.
    void eval();
    /// Simulation complete, run final blocks.  Application must call on completion.
    void final();
    
    // INTERNAL METHODS
  private:
    static void _eval_initial_loop(MIPS_Bus_TB__Syms* __restrict vlSymsp);
  public:
    void __Vconfigure(MIPS_Bus_TB__Syms* symsp, bool first);
  private:
    static QData _change_request(MIPS_Bus_TB__Syms* __restrict vlSymsp);
  public:
    static void _combo__TOP__8(MIPS_Bus_TB__Syms* __restrict vlSymsp);
  private:
    void _ctor_var_reset() VL_ATTR_COLD;
  public:
    static void _eval(MIPS_Bus_TB__Syms* __restrict vlSymsp);
  private:
#ifdef VL_DEBUG
    void _eval_debug_assertions();
#endif  // VL_DEBUG
  public:
    static void _eval_initial(MIPS_Bus_TB__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _eval_settle(MIPS_Bus_TB__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _multiclk__TOP__11(MIPS_Bus_TB__Syms* __restrict vlSymsp);
    static void _multiclk__TOP__12(MIPS_Bus_TB__Syms* __restrict vlSymsp);
    static void _multiclk__TOP__7(MIPS_Bus_TB__Syms* __restrict vlSymsp);
    static void _multiclk__TOP__9(MIPS_Bus_TB__Syms* __restrict vlSymsp);
    static void _sequent__TOP__1(MIPS_Bus_TB__Syms* __restrict vlSymsp);
    static void _sequent__TOP__10(MIPS_Bus_TB__Syms* __restrict vlSymsp);
    static void _sequent__TOP__2(MIPS_Bus_TB__Syms* __restrict vlSymsp);
    static void _sequent__TOP__3(MIPS_Bus_TB__Syms* __restrict vlSymsp);
    static void _sequent__TOP__5(MIPS_Bus_TB__Syms* __restrict vlSymsp);
    static void _sequent__TOP__6(MIPS_Bus_TB__Syms* __restrict vlSymsp);
    static void _settle__TOP__4(MIPS_Bus_TB__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void traceChgThis(MIPS_Bus_TB__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void traceChgThis__10(MIPS_Bus_TB__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void traceChgThis__11(MIPS_Bus_TB__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void traceChgThis__12(MIPS_Bus_TB__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void traceChgThis__13(MIPS_Bus_TB__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void traceChgThis__14(MIPS_Bus_TB__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void traceChgThis__15(MIPS_Bus_TB__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void traceChgThis__16(MIPS_Bus_TB__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void traceChgThis__17(MIPS_Bus_TB__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void traceChgThis__18(MIPS_Bus_TB__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void traceChgThis__19(MIPS_Bus_TB__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void traceChgThis__2(MIPS_Bus_TB__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void traceChgThis__20(MIPS_Bus_TB__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void traceChgThis__21(MIPS_Bus_TB__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void traceChgThis__3(MIPS_Bus_TB__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void traceChgThis__4(MIPS_Bus_TB__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void traceChgThis__5(MIPS_Bus_TB__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void traceChgThis__6(MIPS_Bus_TB__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void traceChgThis__7(MIPS_Bus_TB__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void traceChgThis__8(MIPS_Bus_TB__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void traceChgThis__9(MIPS_Bus_TB__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void traceFullThis(MIPS_Bus_TB__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) VL_ATTR_COLD;
    static void traceFullThis__1(MIPS_Bus_TB__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) VL_ATTR_COLD;
    static void traceInitThis(MIPS_Bus_TB__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) VL_ATTR_COLD;
    static void traceInitThis__1(MIPS_Bus_TB__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) VL_ATTR_COLD;
    static void traceInit(VerilatedVcd* vcdp, void* userthis, uint32_t code);
    static void traceFull(VerilatedVcd* vcdp, void* userthis, uint32_t code);
    static void traceChg(VerilatedVcd* vcdp, void* userthis, uint32_t code);
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

//----------


#endif  // guard
