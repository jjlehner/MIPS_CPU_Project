// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Primary design header
//
// This header should be included by all source files instantiating the design.
// The class here is then constructed to instantiate the design.
// See the Verilator manual for examples.

#ifndef _REGISTER_FILE_TB_H_
#define _REGISTER_FILE_TB_H_  // guard

#include "verilated.h"

//==========

class Register_File_tb__Syms;

//----------

VL_MODULE(Register_File_tb) {
  public:
    
    // PORTS
    // The application code writes and reads these signals to
    // propagate new values into/out from the Verilated model.
    VL_IN8(clk,0,0);
    VL_IN8(pipelined,0,0);
    VL_IN8(write_enable,0,0);
    VL_IN8(read_address_1,4,0);
    VL_IN8(read_address_2,4,0);
    VL_IN8(write_address,4,0);
    VL_IN(write_data,31,0);
    VL_OUT(read_data_1,31,0);
    VL_OUT(read_data_2,31,0);
    
    // LOCAL SIGNALS
    // Internals; generally not touched by application code
    CData/*0:0*/ Register_File__DOT__modified_write_clk;
    IData/*31:0*/ Register_File__DOT__registers[32];
    
    // LOCAL VARIABLES
    // Internals; generally not touched by application code
    CData/*0:0*/ __Vclklast__TOP__Register_File__DOT__modified_write_clk;
    
    // INTERNAL VARIABLES
    // Internals; generally not touched by application code
    Register_File_tb__Syms* __VlSymsp;  // Symbol table
    
    // CONSTRUCTORS
  private:
    VL_UNCOPYABLE(Register_File_tb);  ///< Copying not allowed
  public:
    /// Construct the model; called by application code
    /// The special name  may be used to make a wrapper with a
    /// single model invisible with respect to DPI scope names.
    Register_File_tb(const char* name = "TOP");
    /// Destroy the model; called (often implicitly) by application code
    ~Register_File_tb();
    
    // API METHODS
    /// Evaluate the model.  Application must call when inputs change.
    void eval();
    /// Simulation complete, run final blocks.  Application must call on completion.
    void final();
    
    // INTERNAL METHODS
  private:
    static void _eval_initial_loop(Register_File_tb__Syms* __restrict vlSymsp);
  public:
    void __Vconfigure(Register_File_tb__Syms* symsp, bool first);
  private:
    static QData _change_request(Register_File_tb__Syms* __restrict vlSymsp);
  public:
    static void _combo__TOP__1(Register_File_tb__Syms* __restrict vlSymsp);
    static void _combo__TOP__4(Register_File_tb__Syms* __restrict vlSymsp);
  private:
    void _ctor_var_reset() VL_ATTR_COLD;
  public:
    static void _eval(Register_File_tb__Syms* __restrict vlSymsp);
  private:
#ifdef VL_DEBUG
    void _eval_debug_assertions();
#endif  // VL_DEBUG
  public:
    static void _eval_initial(Register_File_tb__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _eval_settle(Register_File_tb__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _sequent__TOP__3(Register_File_tb__Syms* __restrict vlSymsp);
    static void _settle__TOP__2(Register_File_tb__Syms* __restrict vlSymsp) VL_ATTR_COLD;
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

//----------


#endif  // guard
