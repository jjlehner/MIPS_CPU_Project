// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Register_File_tb.h for the primary calling header

#include "Register_File_tb.h"
#include "Register_File_tb__Syms.h"

//==========

VL_CTOR_IMP(Register_File_tb) {
    Register_File_tb__Syms* __restrict vlSymsp = __VlSymsp = new Register_File_tb__Syms(this, name());
    Register_File_tb* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Reset internal values
    
    // Reset structure values
    _ctor_var_reset();
}

void Register_File_tb::__Vconfigure(Register_File_tb__Syms* vlSymsp, bool first) {
    if (0 && first) {}  // Prevent unused
    this->__VlSymsp = vlSymsp;
}

Register_File_tb::~Register_File_tb() {
    delete __VlSymsp; __VlSymsp=NULL;
}

void Register_File_tb::eval() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Register_File_tb::eval\n"); );
    Register_File_tb__Syms* __restrict vlSymsp = this->__VlSymsp;  // Setup global symbol table
    Register_File_tb* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
#ifdef VL_DEBUG
    // Debug assertions
    _eval_debug_assertions();
#endif  // VL_DEBUG
    // Initialize
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) _eval_initial_loop(vlSymsp);
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    do {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Clock loop\n"););
        _eval(vlSymsp);
        if (VL_UNLIKELY(++__VclockLoop > 100)) {
            // About to fail, so enable debug to see what's not settling.
            // Note you must run make with OPT=-DVL_DEBUG for debug prints.
            int __Vsaved_debug = Verilated::debug();
            Verilated::debug(1);
            __Vchange = _change_request(vlSymsp);
            Verilated::debug(__Vsaved_debug);
            VL_FATAL_MT("Register_File.v", 2, "",
                "Verilated model didn't converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

void Register_File_tb::_eval_initial_loop(Register_File_tb__Syms* __restrict vlSymsp) {
    vlSymsp->__Vm_didInit = true;
    _eval_initial(vlSymsp);
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    do {
        _eval_settle(vlSymsp);
        _eval(vlSymsp);
        if (VL_UNLIKELY(++__VclockLoop > 100)) {
            // About to fail, so enable debug to see what's not settling.
            // Note you must run make with OPT=-DVL_DEBUG for debug prints.
            int __Vsaved_debug = Verilated::debug();
            Verilated::debug(1);
            __Vchange = _change_request(vlSymsp);
            Verilated::debug(__Vsaved_debug);
            VL_FATAL_MT("Register_File.v", 2, "",
                "Verilated model didn't DC converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

VL_INLINE_OPT void Register_File_tb::_combo__TOP__1(Register_File_tb__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Register_File_tb::_combo__TOP__1\n"); );
    Register_File_tb* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->Register_File__DOT__modified_write_clk 
        = ((IData)(vlTOPp->clk) ^ (IData)(vlTOPp->pipelined));
}

void Register_File_tb::_settle__TOP__2(Register_File_tb__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Register_File_tb::_settle__TOP__2\n"); );
    Register_File_tb* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->Register_File__DOT__modified_write_clk 
        = ((IData)(vlTOPp->clk) ^ (IData)(vlTOPp->pipelined));
    vlTOPp->read_data_1 = ((0U != (IData)(vlTOPp->read_address_1))
                            ? vlTOPp->Register_File__DOT__registers
                           [vlTOPp->read_address_1]
                            : 0U);
    vlTOPp->read_data_2 = ((0U != (IData)(vlTOPp->read_address_2))
                            ? vlTOPp->Register_File__DOT__registers
                           [vlTOPp->read_address_2]
                            : 0U);
}

VL_INLINE_OPT void Register_File_tb::_sequent__TOP__3(Register_File_tb__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Register_File_tb::_sequent__TOP__3\n"); );
    Register_File_tb* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    CData/*4:0*/ __Vdlyvdim0__Register_File__DOT__registers__v0;
    CData/*0:0*/ __Vdlyvset__Register_File__DOT__registers__v0;
    IData/*31:0*/ __Vdlyvval__Register_File__DOT__registers__v0;
    // Body
    __Vdlyvset__Register_File__DOT__registers__v0 = 0U;
    if (vlTOPp->write_enable) {
        __Vdlyvval__Register_File__DOT__registers__v0 
            = vlTOPp->write_data;
        __Vdlyvset__Register_File__DOT__registers__v0 = 1U;
        __Vdlyvdim0__Register_File__DOT__registers__v0 
            = vlTOPp->write_address;
    }
    if (__Vdlyvset__Register_File__DOT__registers__v0) {
        vlTOPp->Register_File__DOT__registers[__Vdlyvdim0__Register_File__DOT__registers__v0] 
            = __Vdlyvval__Register_File__DOT__registers__v0;
    }
}

VL_INLINE_OPT void Register_File_tb::_combo__TOP__4(Register_File_tb__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Register_File_tb::_combo__TOP__4\n"); );
    Register_File_tb* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->read_data_1 = ((0U != (IData)(vlTOPp->read_address_1))
                            ? vlTOPp->Register_File__DOT__registers
                           [vlTOPp->read_address_1]
                            : 0U);
    vlTOPp->read_data_2 = ((0U != (IData)(vlTOPp->read_address_2))
                            ? vlTOPp->Register_File__DOT__registers
                           [vlTOPp->read_address_2]
                            : 0U);
}

void Register_File_tb::_eval(Register_File_tb__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Register_File_tb::_eval\n"); );
    Register_File_tb* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_combo__TOP__1(vlSymsp);
    if (((IData)(vlTOPp->Register_File__DOT__modified_write_clk) 
         & (~ (IData)(vlTOPp->__Vclklast__TOP__Register_File__DOT__modified_write_clk)))) {
        vlTOPp->_sequent__TOP__3(vlSymsp);
    }
    vlTOPp->_combo__TOP__4(vlSymsp);
    // Final
    vlTOPp->__Vclklast__TOP__Register_File__DOT__modified_write_clk 
        = vlTOPp->Register_File__DOT__modified_write_clk;
}

void Register_File_tb::_eval_initial(Register_File_tb__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Register_File_tb::_eval_initial\n"); );
    Register_File_tb* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->__Vclklast__TOP__Register_File__DOT__modified_write_clk 
        = vlTOPp->Register_File__DOT__modified_write_clk;
}

void Register_File_tb::final() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Register_File_tb::final\n"); );
    // Variables
    Register_File_tb__Syms* __restrict vlSymsp = this->__VlSymsp;
    Register_File_tb* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void Register_File_tb::_eval_settle(Register_File_tb__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Register_File_tb::_eval_settle\n"); );
    Register_File_tb* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_settle__TOP__2(vlSymsp);
}

VL_INLINE_OPT QData Register_File_tb::_change_request(Register_File_tb__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Register_File_tb::_change_request\n"); );
    Register_File_tb* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // Change detection
    QData __req = false;  // Logically a bool
    return __req;
}

#ifdef VL_DEBUG
void Register_File_tb::_eval_debug_assertions() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Register_File_tb::_eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((clk & 0xfeU))) {
        Verilated::overWidthError("clk");}
    if (VL_UNLIKELY((pipelined & 0xfeU))) {
        Verilated::overWidthError("pipelined");}
    if (VL_UNLIKELY((write_enable & 0xfeU))) {
        Verilated::overWidthError("write_enable");}
    if (VL_UNLIKELY((read_address_1 & 0xe0U))) {
        Verilated::overWidthError("read_address_1");}
    if (VL_UNLIKELY((read_address_2 & 0xe0U))) {
        Verilated::overWidthError("read_address_2");}
    if (VL_UNLIKELY((write_address & 0xe0U))) {
        Verilated::overWidthError("write_address");}
}
#endif  // VL_DEBUG

void Register_File_tb::_ctor_var_reset() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Register_File_tb::_ctor_var_reset\n"); );
    // Body
    clk = VL_RAND_RESET_I(1);
    pipelined = VL_RAND_RESET_I(1);
    write_enable = VL_RAND_RESET_I(1);
    read_address_1 = VL_RAND_RESET_I(5);
    read_address_2 = VL_RAND_RESET_I(5);
    write_address = VL_RAND_RESET_I(5);
    write_data = VL_RAND_RESET_I(32);
    read_data_1 = VL_RAND_RESET_I(32);
    read_data_2 = VL_RAND_RESET_I(32);
    { int __Vi0=0; for (; __Vi0<32; ++__Vi0) {
            Register_File__DOT__registers[__Vi0] = VL_RAND_RESET_I(32);
    }}
    Register_File__DOT__modified_write_clk = VL_RAND_RESET_I(1);
}
