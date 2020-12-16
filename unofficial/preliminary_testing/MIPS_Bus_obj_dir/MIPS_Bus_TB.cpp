// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See MIPS_Bus_TB.h for the primary calling header

#include "MIPS_Bus_TB.h"
#include "MIPS_Bus_TB__Syms.h"

//==========

VL_CTOR_IMP(MIPS_Bus_TB) {
    MIPS_Bus_TB__Syms* __restrict vlSymsp = __VlSymsp = new MIPS_Bus_TB__Syms(this, name());
    MIPS_Bus_TB* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Reset internal values
    
    // Reset structure values
    _ctor_var_reset();
}

void MIPS_Bus_TB::__Vconfigure(MIPS_Bus_TB__Syms* vlSymsp, bool first) {
    if (0 && first) {}  // Prevent unused
    this->__VlSymsp = vlSymsp;
}

MIPS_Bus_TB::~MIPS_Bus_TB() {
    delete __VlSymsp; __VlSymsp=NULL;
}

void MIPS_Bus_TB::eval() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate MIPS_Bus_TB::eval\n"); );
    MIPS_Bus_TB__Syms* __restrict vlSymsp = this->__VlSymsp;  // Setup global symbol table
    MIPS_Bus_TB* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
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
        vlSymsp->__Vm_activity = true;
        _eval(vlSymsp);
        if (VL_UNLIKELY(++__VclockLoop > 100)) {
            // About to fail, so enable debug to see what's not settling.
            // Note you must run make with OPT=-DVL_DEBUG for debug prints.
            int __Vsaved_debug = Verilated::debug();
            Verilated::debug(1);
            __Vchange = _change_request(vlSymsp);
            Verilated::debug(__Vsaved_debug);
            VL_FATAL_MT("../../rtl/mips_cpu_bus.v", 5, "",
                "Verilated model didn't converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

void MIPS_Bus_TB::_eval_initial_loop(MIPS_Bus_TB__Syms* __restrict vlSymsp) {
    vlSymsp->__Vm_didInit = true;
    _eval_initial(vlSymsp);
    vlSymsp->__Vm_activity = true;
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
            VL_FATAL_MT("../../rtl/mips_cpu_bus.v", 5, "",
                "Verilated model didn't DC converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

VL_INLINE_OPT void MIPS_Bus_TB::_sequent__TOP__1(MIPS_Bus_TB__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    MIPS_Bus_TB::_sequent__TOP__1\n"); );
    MIPS_Bus_TB* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    CData/*4:0*/ __Vdlyvdim0__mips_cpu_bus__DOT__register_file__DOT__registers__v0;
    CData/*0:0*/ __Vdlyvset__mips_cpu_bus__DOT__register_file__DOT__registers__v0;
    IData/*31:0*/ __Vdlyvval__mips_cpu_bus__DOT__register_file__DOT__registers__v0;
    // Body
    __Vdlyvset__mips_cpu_bus__DOT__register_file__DOT__registers__v0 = 0U;
    if (vlTOPp->mips_cpu_bus__DOT__register_write_writeback) {
        __Vdlyvval__mips_cpu_bus__DOT__register_file__DOT__registers__v0 
            = vlTOPp->mips_cpu_bus__DOT__result_writeback;
        __Vdlyvset__mips_cpu_bus__DOT__register_file__DOT__registers__v0 = 1U;
        __Vdlyvdim0__mips_cpu_bus__DOT__register_file__DOT__registers__v0 
            = vlTOPp->mips_cpu_bus__DOT__write_register_writeback;
    }
    if (__Vdlyvset__mips_cpu_bus__DOT__register_file__DOT__registers__v0) {
        vlTOPp->mips_cpu_bus__DOT__register_file__DOT__registers[__Vdlyvdim0__mips_cpu_bus__DOT__register_file__DOT__registers__v0] 
            = __Vdlyvval__mips_cpu_bus__DOT__register_file__DOT__registers__v0;
    }
}

VL_INLINE_OPT void MIPS_Bus_TB::_sequent__TOP__2(MIPS_Bus_TB__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    MIPS_Bus_TB::_sequent__TOP__2\n"); );
    MIPS_Bus_TB* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    IData/*31:0*/ __Vdly__mips_cpu_bus__DOT__instr_address;
    // Body
    __Vdly__mips_cpu_bus__DOT__instr_address = vlTOPp->mips_cpu_bus__DOT__instr_address;
    vlTOPp->mips_cpu_bus__DOT__write_data_memory = 
        ((IData)(vlTOPp->reset) ? 0U : vlTOPp->mips_cpu_bus__DOT__write_data_execute);
    vlTOPp->mips_cpu_bus__DOT__sign_imm_execute = ((IData)(vlTOPp->mips_cpu_bus__DOT__flush_execute_register)
                                                    ? 0U
                                                    : 
                                                   ((IData)(vlTOPp->reset)
                                                     ? 0U
                                                     : vlTOPp->mips_cpu_bus__DOT__sign_imm_decode));
    vlTOPp->mips_cpu_bus__DOT__ALU_function_execute 
        = ((IData)(vlTOPp->mips_cpu_bus__DOT__flush_execute_register)
            ? 0U : ((IData)(vlTOPp->reset) ? 0U : (IData)(vlTOPp->mips_cpu_bus__DOT__ALU_function_decode)));
    vlTOPp->mips_cpu_bus__DOT__ALU_src_B_execute = 
        ((IData)(vlTOPp->mips_cpu_bus__DOT__flush_execute_register)
          ? 0U : ((IData)(vlTOPp->reset) ? 0U : (IData)(vlTOPp->mips_cpu_bus__DOT__ALU_src_B_decode)));
    vlTOPp->mips_cpu_bus__DOT__register_destination_execute 
        = ((IData)(vlTOPp->mips_cpu_bus__DOT__flush_execute_register)
            ? 0U : ((IData)(vlTOPp->reset) ? 0U : (IData)(vlTOPp->mips_cpu_bus__DOT__register_destination_decode)));
    vlTOPp->mips_cpu_bus__DOT__program_counter_plus_four_execute 
        = ((IData)(vlTOPp->mips_cpu_bus__DOT__flush_execute_register)
            ? 0U : ((IData)(vlTOPp->reset) ? 0U : vlTOPp->mips_cpu_bus__DOT__program_counter_plus_four_decode));
    vlTOPp->mips_cpu_bus__DOT__HALT_writeback = ((~ (IData)(vlTOPp->reset)) 
                                                 & (IData)(vlTOPp->mips_cpu_bus__DOT__HALT_memory));
    vlTOPp->mips_cpu_bus__DOT__using_HI_LO_execute 
        = ((~ (IData)(vlTOPp->mips_cpu_bus__DOT__flush_execute_register)) 
           & ((~ (IData)(vlTOPp->reset)) & (IData)(vlTOPp->mips_cpu_bus__DOT__using_HI_LO_decode)));
    vlTOPp->mips_cpu_bus__DOT__memory_to_register_writeback 
        = ((~ (IData)(vlTOPp->reset)) & (IData)(vlTOPp->mips_cpu_bus__DOT__memory_to_register_memory));
    vlTOPp->mips_cpu_bus__DOT__byteenable_writeback 
        = ((IData)(vlTOPp->reset) ? 0U : (IData)(vlTOPp->mips_cpu_bus__DOT__byteenable_memory));
    vlTOPp->mips_cpu_bus__DOT__ALU_output_writeback 
        = ((IData)(vlTOPp->reset) ? 0U : vlTOPp->mips_cpu_bus__DOT__ALU_output_memory);
    vlTOPp->mips_cpu_bus__DOT__src_A_ALU_writeback 
        = ((IData)(vlTOPp->reset) ? 0U : vlTOPp->mips_cpu_bus__DOT__src_A_ALU_memory);
    vlTOPp->mips_cpu_bus__DOT__src_A_execute = ((IData)(vlTOPp->mips_cpu_bus__DOT__flush_execute_register)
                                                 ? 0U
                                                 : 
                                                ((IData)(vlTOPp->reset)
                                                  ? 0U
                                                  : 
                                                 ((IData)(vlTOPp->mips_cpu_bus__DOT__using_HI_LO_decode)
                                                   ? vlTOPp->mips_cpu_bus__DOT__register_file__DOT__LO_reg
                                                   : vlTOPp->mips_cpu_bus__DOT__register_file_output_A_decode)));
    vlTOPp->mips_cpu_bus__DOT__write_register_writeback 
        = ((IData)(vlTOPp->reset) ? 0U : (IData)(vlTOPp->mips_cpu_bus__DOT__write_register_memory));
    vlTOPp->mips_cpu_bus__DOT__register_write_writeback 
        = ((~ (IData)(vlTOPp->reset)) & (IData)(vlTOPp->mips_cpu_bus__DOT__register_write_memory));
    vlTOPp->mips_cpu_bus__DOT__src_B_execute = ((IData)(vlTOPp->mips_cpu_bus__DOT__flush_execute_register)
                                                 ? 0U
                                                 : 
                                                ((IData)(vlTOPp->reset)
                                                  ? 0U
                                                  : 
                                                 ((IData)(vlTOPp->mips_cpu_bus__DOT__using_HI_LO_decode)
                                                   ? vlTOPp->mips_cpu_bus__DOT__register_file__DOT__HI_reg
                                                   : vlTOPp->mips_cpu_bus__DOT__register_file_output_B_decode)));
    vlTOPp->mips_cpu_bus__DOT__Rd_execute = ((IData)(vlTOPp->mips_cpu_bus__DOT__flush_execute_register)
                                              ? 0U : 
                                             ((IData)(vlTOPp->reset)
                                               ? 0U
                                               : (0x1fU 
                                                  & (vlTOPp->mips_cpu_bus__DOT__instruction_decode 
                                                     >> 0xbU))));
    vlTOPp->mips_cpu_bus__DOT__Rs_execute = ((IData)(vlTOPp->mips_cpu_bus__DOT__flush_execute_register)
                                              ? 0U : 
                                             ((IData)(vlTOPp->reset)
                                               ? 0U
                                               : (0x1fU 
                                                  & (vlTOPp->mips_cpu_bus__DOT__instruction_decode 
                                                     >> 0x15U))));
    vlTOPp->mips_cpu_bus__DOT__Rt_execute = ((IData)(vlTOPp->mips_cpu_bus__DOT__flush_execute_register)
                                              ? 0U : 
                                             ((IData)(vlTOPp->reset)
                                               ? 0U
                                               : (0x1fU 
                                                  & (vlTOPp->mips_cpu_bus__DOT__instruction_decode 
                                                     >> 0x10U))));
    vlTOPp->mips_cpu_bus__DOT__op_writeback = ((IData)(vlTOPp->reset)
                                                ? 0U
                                                : (IData)(vlTOPp->mips_cpu_bus__DOT__op_memory));
    if (vlTOPp->reset) {
        __Vdly__mips_cpu_bus__DOT__instr_address = 0xbfc00000U;
    } else {
        if ((1U & ((~ (IData)(vlTOPp->mips_cpu_bus__DOT__stall_fetch)) 
                   & (~ (IData)(vlTOPp->mips_cpu_bus__DOT__HALT_fetch))))) {
            __Vdly__mips_cpu_bus__DOT__instr_address 
                = ((IData)(vlTOPp->mips_cpu_bus__DOT__program_counter_multiplexer_jump_memory)
                    ? ((IData)(vlTOPp->mips_cpu_bus__DOT__j_instruction_memory)
                        ? vlTOPp->mips_cpu_bus__DOT__j_program_counter_memory
                        : vlTOPp->mips_cpu_bus__DOT__ALU_output_memory)
                    : vlTOPp->mips_cpu_bus__DOT__program_counter_mux_1_out);
        }
    }
    vlTOPp->writedata = vlTOPp->mips_cpu_bus__DOT__write_data_memory;
    vlTOPp->active = (1U & (~ (IData)(vlTOPp->mips_cpu_bus__DOT__HALT_writeback)));
    vlTOPp->mips_cpu_bus__DOT__HALT_memory = ((~ (IData)(vlTOPp->reset)) 
                                              & (IData)(vlTOPp->mips_cpu_bus__DOT__HALT_execute));
    vlTOPp->mips_cpu_bus__DOT__src_A_ALU_memory = ((IData)(vlTOPp->reset)
                                                    ? 0U
                                                    : vlTOPp->mips_cpu_bus__DOT__src_A_ALU_execute);
    vlTOPp->mips_cpu_bus__DOT__write_register_memory 
        = ((IData)(vlTOPp->reset) ? 0U : (IData)(vlTOPp->mips_cpu_bus__DOT__write_register_execute));
    vlTOPp->mips_cpu_bus__DOT__register_write_memory 
        = ((~ (IData)(vlTOPp->reset)) & (IData)(vlTOPp->mips_cpu_bus__DOT__register_write_execute));
    vlTOPp->mips_cpu_bus__DOT__op_memory = ((IData)(vlTOPp->reset)
                                             ? 0U : (IData)(vlTOPp->mips_cpu_bus__DOT__op_execute));
    vlTOPp->mips_cpu_bus__DOT__j_instruction_memory 
        = ((~ (IData)(vlTOPp->reset)) & (IData)(vlTOPp->mips_cpu_bus__DOT__j_instruction_execute));
    vlTOPp->mips_cpu_bus__DOT__program_counter_multiplexer_jump_memory 
        = ((~ (IData)(vlTOPp->reset)) & (IData)(vlTOPp->mips_cpu_bus__DOT__program_counter_multiplexer_jump_execute));
    vlTOPp->mips_cpu_bus__DOT__ALU_output_memory = 
        ((IData)(vlTOPp->reset) ? 0U : vlTOPp->mips_cpu_bus__DOT__ALU_output_execute);
    vlTOPp->mips_cpu_bus__DOT__j_program_counter_memory 
        = ((IData)(vlTOPp->reset) ? 0U : vlTOPp->mips_cpu_bus__DOT__j_program_counter_execute);
    vlTOPp->mips_cpu_bus__DOT__write_register_execute 
        = ((2U & (IData)(vlTOPp->mips_cpu_bus__DOT__register_destination_execute))
            ? ((1U & (IData)(vlTOPp->mips_cpu_bus__DOT__register_destination_execute))
                ? 0U : 0x1fU) : ((1U & (IData)(vlTOPp->mips_cpu_bus__DOT__register_destination_execute))
                                  ? (IData)(vlTOPp->mips_cpu_bus__DOT__Rd_execute)
                                  : (IData)(vlTOPp->mips_cpu_bus__DOT__Rt_execute)));
    vlTOPp->mips_cpu_bus__DOT__HALT_execute = ((~ (IData)(vlTOPp->mips_cpu_bus__DOT__flush_execute_register)) 
                                               & ((~ (IData)(vlTOPp->reset)) 
                                                  & (IData)(vlTOPp->mips_cpu_bus__DOT__HALT_decode)));
    vlTOPp->mips_cpu_bus__DOT__register_write_execute 
        = ((~ (IData)(vlTOPp->mips_cpu_bus__DOT__flush_execute_register)) 
           & ((~ (IData)(vlTOPp->reset)) & (IData)(vlTOPp->mips_cpu_bus__DOT__register_write_decode)));
    vlTOPp->mips_cpu_bus__DOT__op_execute = ((IData)(vlTOPp->mips_cpu_bus__DOT__flush_execute_register)
                                              ? 0U : 
                                             ((IData)(vlTOPp->reset)
                                               ? 0U
                                               : (0x3fU 
                                                  & (vlTOPp->mips_cpu_bus__DOT__instruction_decode 
                                                     >> 0x1aU))));
    vlTOPp->mips_cpu_bus__DOT__j_instruction_execute 
        = ((~ (IData)(vlTOPp->mips_cpu_bus__DOT__flush_execute_register)) 
           & ((~ (IData)(vlTOPp->reset)) & (IData)(vlTOPp->mips_cpu_bus__DOT__j_instruction_decode)));
    vlTOPp->mips_cpu_bus__DOT__program_counter_multiplexer_jump_execute 
        = ((~ (IData)(vlTOPp->mips_cpu_bus__DOT__flush_execute_register)) 
           & ((~ (IData)(vlTOPp->reset)) & (IData)(vlTOPp->mips_cpu_bus__DOT__program_counter_multiplexer_jump_decode)));
    vlTOPp->mips_cpu_bus__DOT__j_program_counter_execute 
        = ((IData)(vlTOPp->mips_cpu_bus__DOT__flush_execute_register)
            ? 0U : ((IData)(vlTOPp->reset) ? 0U : (
                                                   (0xf0000000U 
                                                    & vlTOPp->mips_cpu_bus__DOT__program_counter_plus_four_decode) 
                                                   | (0xffffffcU 
                                                      & (vlTOPp->mips_cpu_bus__DOT__instruction_decode 
                                                         << 2U)))));
    if (vlTOPp->reset) {
        vlTOPp->mips_cpu_bus__DOT__HALT_decode = 0U;
    } else {
        if ((1U & (~ (IData)(vlTOPp->mips_cpu_bus__DOT__stall_decode)))) {
            vlTOPp->mips_cpu_bus__DOT__HALT_decode 
                = ((~ (IData)(vlTOPp->mips_cpu_bus__DOT__program_counter_src_decode)) 
                   & (IData)(vlTOPp->mips_cpu_bus__DOT__HALT_fetch));
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->mips_cpu_bus__DOT__program_counter_plus_four_decode = 0xbfc00004U;
    } else {
        if ((1U & (~ (IData)(vlTOPp->mips_cpu_bus__DOT__stall_decode)))) {
            vlTOPp->mips_cpu_bus__DOT__program_counter_plus_four_decode 
                = ((IData)(vlTOPp->mips_cpu_bus__DOT__program_counter_src_decode)
                    ? 0U : ((IData)(4U) + vlTOPp->mips_cpu_bus__DOT__instr_address));
        }
    }
    vlTOPp->mips_cpu_bus__DOT__instr_address = __Vdly__mips_cpu_bus__DOT__instr_address;
    if (vlTOPp->reset) {
        vlTOPp->mips_cpu_bus__DOT__HALT_fetch = 0U;
    }
}

VL_INLINE_OPT void MIPS_Bus_TB::_sequent__TOP__3(MIPS_Bus_TB__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    MIPS_Bus_TB::_sequent__TOP__3\n"); );
    MIPS_Bus_TB* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    CData/*1:0*/ __Vdly__mips_cpu_bus__DOT__fetch_state;
    // Body
    __Vdly__mips_cpu_bus__DOT__fetch_state = vlTOPp->mips_cpu_bus__DOT__fetch_state;
    if (vlTOPp->reset) {
        vlTOPp->read = 0U;
        vlTOPp->write = 0U;
        vlTOPp->mips_cpu_bus__DOT__instruction_decode = 0U;
        vlTOPp->mips_cpu_bus__DOT__read_data_writeback = 0U;
        vlTOPp->mips_cpu_bus__DOT__internal_clk = 0U;
        __Vdly__mips_cpu_bus__DOT__fetch_state = 3U;
    } else {
        if (vlTOPp->clk) {
            if ((1U & (~ (IData)(vlTOPp->waitrequest)))) {
                if ((0U == (IData)(vlTOPp->mips_cpu_bus__DOT__fetch_state))) {
                    if ((1U & ((~ (IData)(vlTOPp->mips_cpu_bus__DOT__stall_decode)) 
                               & (~ (IData)(vlTOPp->mips_cpu_bus__DOT__program_counter_src_decode))))) {
                        vlTOPp->mips_cpu_bus__DOT__instruction_decode 
                            = vlTOPp->readdata;
                    } else {
                        if (((~ (IData)(vlTOPp->mips_cpu_bus__DOT__stall_decode)) 
                             & (IData)(vlTOPp->mips_cpu_bus__DOT__program_counter_src_decode))) {
                            vlTOPp->mips_cpu_bus__DOT__instruction_decode = 0U;
                        }
                    }
                    __Vdly__mips_cpu_bus__DOT__fetch_state 
                        = (((IData)(vlTOPp->mips_cpu_bus__DOT__memory_to_register_memory) 
                            | (IData)(vlTOPp->mips_cpu_bus__DOT__memory_write_memory))
                            ? 2U : 0U);
                    vlTOPp->read = (1U & (~ (IData)(vlTOPp->mips_cpu_bus__DOT__memory_write_memory)));
                    vlTOPp->write = vlTOPp->mips_cpu_bus__DOT__memory_write_memory;
                    vlTOPp->mips_cpu_bus__DOT__internal_clk = 1U;
                }
                if ((2U == (IData)(vlTOPp->mips_cpu_bus__DOT__fetch_state))) {
                    if ((1U & ((~ (IData)(vlTOPp->mips_cpu_bus__DOT__stall_decode)) 
                               & (~ (IData)(vlTOPp->mips_cpu_bus__DOT__program_counter_src_decode))))) {
                        vlTOPp->mips_cpu_bus__DOT__instruction_decode 
                            = vlTOPp->readdata;
                    } else {
                        if (((~ (IData)(vlTOPp->mips_cpu_bus__DOT__stall_decode)) 
                             & (IData)(vlTOPp->mips_cpu_bus__DOT__program_counter_src_decode))) {
                            vlTOPp->mips_cpu_bus__DOT__instruction_decode = 0U;
                        }
                    }
                    vlTOPp->read = 1U;
                    vlTOPp->write = 0U;
                    vlTOPp->mips_cpu_bus__DOT__internal_clk = 1U;
                } else {
                    if ((1U == (IData)(vlTOPp->mips_cpu_bus__DOT__fetch_state))) {
                        vlTOPp->mips_cpu_bus__DOT__read_data_writeback 
                            = vlTOPp->readdata;
                        __Vdly__mips_cpu_bus__DOT__fetch_state 
                            = (((IData)(vlTOPp->mips_cpu_bus__DOT__memory_to_register_memory) 
                                | (IData)(vlTOPp->mips_cpu_bus__DOT__memory_write_memory))
                                ? 2U : 0U);
                        vlTOPp->read = (1U & (~ (IData)(vlTOPp->mips_cpu_bus__DOT__memory_write_memory)));
                        vlTOPp->write = vlTOPp->mips_cpu_bus__DOT__memory_write_memory;
                        vlTOPp->mips_cpu_bus__DOT__internal_clk = 1U;
                    } else {
                        if ((3U == (IData)(vlTOPp->mips_cpu_bus__DOT__fetch_state))) {
                            __Vdly__mips_cpu_bus__DOT__fetch_state 
                                = (((IData)(vlTOPp->mips_cpu_bus__DOT__memory_to_register_memory) 
                                    | (IData)(vlTOPp->mips_cpu_bus__DOT__memory_write_memory))
                                    ? 2U : 0U);
                            vlTOPp->read = 1U;
                            vlTOPp->write = 0U;
                        }
                    }
                }
            }
        } else {
            vlTOPp->mips_cpu_bus__DOT__internal_clk = 0U;
        }
    }
    vlTOPp->mips_cpu_bus__DOT__fetch_state = __Vdly__mips_cpu_bus__DOT__fetch_state;
    vlTOPp->mips_cpu_bus__DOT__sign_imm_decode = ((0xffff0000U 
                                                   & (VL_NEGATE_I((IData)(
                                                                          (1U 
                                                                           & (vlTOPp->mips_cpu_bus__DOT__instruction_decode 
                                                                              >> 0xfU)))) 
                                                      << 0x10U)) 
                                                  | (0xffffU 
                                                     & vlTOPp->mips_cpu_bus__DOT__instruction_decode));
}

void MIPS_Bus_TB::_settle__TOP__4(MIPS_Bus_TB__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    MIPS_Bus_TB::_settle__TOP__4\n"); );
    MIPS_Bus_TB* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->writedata = vlTOPp->mips_cpu_bus__DOT__write_data_memory;
    vlTOPp->active = (1U & (~ (IData)(vlTOPp->mips_cpu_bus__DOT__HALT_writeback)));
    vlTOPp->mips_cpu_bus__DOT__write_register_execute 
        = ((2U & (IData)(vlTOPp->mips_cpu_bus__DOT__register_destination_execute))
            ? ((1U & (IData)(vlTOPp->mips_cpu_bus__DOT__register_destination_execute))
                ? 0U : 0x1fU) : ((1U & (IData)(vlTOPp->mips_cpu_bus__DOT__register_destination_execute))
                                  ? (IData)(vlTOPp->mips_cpu_bus__DOT__Rd_execute)
                                  : (IData)(vlTOPp->mips_cpu_bus__DOT__Rt_execute)));
    vlTOPp->address = (0xfffffffcU & vlTOPp->address);
    vlTOPp->address = ((3U & vlTOPp->address) | (0xfffffffcU 
                                                 & (((((0U 
                                                        == (IData)(vlTOPp->mips_cpu_bus__DOT__fetch_state)) 
                                                       | (1U 
                                                          == (IData)(vlTOPp->mips_cpu_bus__DOT__fetch_state))) 
                                                      | (3U 
                                                         == (IData)(vlTOPp->mips_cpu_bus__DOT__fetch_state)))
                                                      ? 
                                                     (vlTOPp->mips_cpu_bus__DOT__instr_address 
                                                      >> 2U)
                                                      : 
                                                     (vlTOPp->mips_cpu_bus__DOT__ALU_output_memory 
                                                      >> 2U)) 
                                                    << 2U)));
    vlTOPp->mips_cpu_bus__DOT__byteenable_memory = 
        ((((0U == (IData)(vlTOPp->mips_cpu_bus__DOT__fetch_state)) 
           | (1U == (IData)(vlTOPp->mips_cpu_bus__DOT__fetch_state))) 
          | (3U == (IData)(vlTOPp->mips_cpu_bus__DOT__fetch_state)))
          ? 0xfU : ((0x20U & (IData)(vlTOPp->mips_cpu_bus__DOT__op_memory))
                     ? ((0x10U & (IData)(vlTOPp->mips_cpu_bus__DOT__op_memory))
                         ? 0xfU : ((8U & (IData)(vlTOPp->mips_cpu_bus__DOT__op_memory))
                                    ? ((4U & (IData)(vlTOPp->mips_cpu_bus__DOT__op_memory))
                                        ? 0xfU : ((2U 
                                                   & (IData)(vlTOPp->mips_cpu_bus__DOT__op_memory))
                                                   ? 0xfU
                                                   : 
                                                  ((1U 
                                                    & (IData)(vlTOPp->mips_cpu_bus__DOT__op_memory))
                                                    ? 
                                                   ((0U 
                                                     == 
                                                     (3U 
                                                      & vlTOPp->mips_cpu_bus__DOT__ALU_output_memory))
                                                     ? 3U
                                                     : 
                                                    ((2U 
                                                      == 
                                                      (3U 
                                                       & vlTOPp->mips_cpu_bus__DOT__ALU_output_memory))
                                                      ? 0xcU
                                                      : 0xfU))
                                                    : 
                                                   ((2U 
                                                     & vlTOPp->mips_cpu_bus__DOT__ALU_output_memory)
                                                     ? 
                                                    ((1U 
                                                      & vlTOPp->mips_cpu_bus__DOT__ALU_output_memory)
                                                      ? 8U
                                                      : 4U)
                                                     : 
                                                    ((1U 
                                                      & vlTOPp->mips_cpu_bus__DOT__ALU_output_memory)
                                                      ? 2U
                                                      : 1U)))))
                                    : ((4U & (IData)(vlTOPp->mips_cpu_bus__DOT__op_memory))
                                        ? ((2U & (IData)(vlTOPp->mips_cpu_bus__DOT__op_memory))
                                            ? ((1U 
                                                & (IData)(vlTOPp->mips_cpu_bus__DOT__op_memory))
                                                ? 0xfU
                                                : (
                                                   (2U 
                                                    & vlTOPp->mips_cpu_bus__DOT__ALU_output_memory)
                                                    ? 
                                                   ((1U 
                                                     & vlTOPp->mips_cpu_bus__DOT__ALU_output_memory)
                                                     ? 8U
                                                     : 0xcU)
                                                    : 
                                                   ((1U 
                                                     & vlTOPp->mips_cpu_bus__DOT__ALU_output_memory)
                                                     ? 0xeU
                                                     : 0xfU)))
                                            : ((1U 
                                                & (IData)(vlTOPp->mips_cpu_bus__DOT__op_memory))
                                                ? (
                                                   (0U 
                                                    == 
                                                    (3U 
                                                     & vlTOPp->mips_cpu_bus__DOT__ALU_output_memory))
                                                    ? 3U
                                                    : 
                                                   ((2U 
                                                     == 
                                                     (3U 
                                                      & vlTOPp->mips_cpu_bus__DOT__ALU_output_memory))
                                                     ? 0xcU
                                                     : 0xfU))
                                                : (
                                                   (2U 
                                                    & vlTOPp->mips_cpu_bus__DOT__ALU_output_memory)
                                                    ? 
                                                   ((1U 
                                                     & vlTOPp->mips_cpu_bus__DOT__ALU_output_memory)
                                                     ? 8U
                                                     : 4U)
                                                    : 
                                                   ((1U 
                                                     & vlTOPp->mips_cpu_bus__DOT__ALU_output_memory)
                                                     ? 2U
                                                     : 1U))))
                                        : ((2U & (IData)(vlTOPp->mips_cpu_bus__DOT__op_memory))
                                            ? ((1U 
                                                & (IData)(vlTOPp->mips_cpu_bus__DOT__op_memory))
                                                ? 0xfU
                                                : (
                                                   (2U 
                                                    & vlTOPp->mips_cpu_bus__DOT__ALU_output_memory)
                                                    ? 
                                                   ((1U 
                                                     & vlTOPp->mips_cpu_bus__DOT__ALU_output_memory)
                                                     ? 0xfU
                                                     : 7U)
                                                    : 
                                                   ((1U 
                                                     & vlTOPp->mips_cpu_bus__DOT__ALU_output_memory)
                                                     ? 3U
                                                     : 1U)))
                                            : ((1U 
                                                & (IData)(vlTOPp->mips_cpu_bus__DOT__op_memory))
                                                ? (
                                                   (0U 
                                                    == 
                                                    (3U 
                                                     & vlTOPp->mips_cpu_bus__DOT__ALU_output_memory))
                                                    ? 3U
                                                    : 
                                                   ((2U 
                                                     == 
                                                     (3U 
                                                      & vlTOPp->mips_cpu_bus__DOT__ALU_output_memory))
                                                     ? 0xcU
                                                     : 0xfU))
                                                : (
                                                   (2U 
                                                    & vlTOPp->mips_cpu_bus__DOT__ALU_output_memory)
                                                    ? 
                                                   ((1U 
                                                     & vlTOPp->mips_cpu_bus__DOT__ALU_output_memory)
                                                     ? 8U
                                                     : 4U)
                                                    : 
                                                   ((1U 
                                                     & vlTOPp->mips_cpu_bus__DOT__ALU_output_memory)
                                                     ? 2U
                                                     : 1U)))))))
                     : 0xfU));
    vlTOPp->mips_cpu_bus__DOT__sign_imm_decode = ((0xffff0000U 
                                                   & (VL_NEGATE_I((IData)(
                                                                          (1U 
                                                                           & (vlTOPp->mips_cpu_bus__DOT__instruction_decode 
                                                                              >> 0xfU)))) 
                                                      << 0x10U)) 
                                                  | (0xffffU 
                                                     & vlTOPp->mips_cpu_bus__DOT__instruction_decode));
    vlTOPp->mips_cpu_bus__DOT__forward_A_execute = 
        ((((0U != (IData)(vlTOPp->mips_cpu_bus__DOT__Rs_execute)) 
           & ((IData)(vlTOPp->mips_cpu_bus__DOT__Rs_execute) 
              == (IData)(vlTOPp->mips_cpu_bus__DOT__write_register_memory))) 
          & (IData)(vlTOPp->mips_cpu_bus__DOT__register_write_memory))
          ? 2U : (((IData)(vlTOPp->mips_cpu_bus__DOT__using_HI_LO_execute) 
                   & (IData)(vlTOPp->mips_cpu_bus__DOT__LO_register_write_memory))
                   ? 4U : ((((0U != (IData)(vlTOPp->mips_cpu_bus__DOT__Rs_execute)) 
                             & ((IData)(vlTOPp->mips_cpu_bus__DOT__Rs_execute) 
                                == (IData)(vlTOPp->mips_cpu_bus__DOT__write_register_writeback))) 
                            & (IData)(vlTOPp->mips_cpu_bus__DOT__register_write_writeback))
                            ? 1U : (((IData)(vlTOPp->mips_cpu_bus__DOT__using_HI_LO_execute) 
                                     & (IData)(vlTOPp->mips_cpu_bus__DOT__LO_register_write_writeback))
                                     ? 3U : 0U))));
    vlTOPp->mips_cpu_bus__DOT__register_file_output_A_decode 
        = vlTOPp->mips_cpu_bus__DOT__register_file__DOT__registers
        [(0x1fU & (vlTOPp->mips_cpu_bus__DOT__instruction_decode 
                   >> 0x15U))];
    vlTOPp->mips_cpu_bus__DOT__register_file_output_B_decode 
        = vlTOPp->mips_cpu_bus__DOT__register_file__DOT__registers
        [(0x1fU & (vlTOPp->mips_cpu_bus__DOT__instruction_decode 
                   >> 0x10U))];
    vlTOPp->mips_cpu_bus__DOT__forward_B_execute = 
        ((((0U != (IData)(vlTOPp->mips_cpu_bus__DOT__Rt_execute)) 
           & ((IData)(vlTOPp->mips_cpu_bus__DOT__Rt_execute) 
              == (IData)(vlTOPp->mips_cpu_bus__DOT__write_register_memory))) 
          & (IData)(vlTOPp->mips_cpu_bus__DOT__register_write_memory))
          ? 2U : (((IData)(vlTOPp->mips_cpu_bus__DOT__using_HI_LO_execute) 
                   & (IData)(vlTOPp->mips_cpu_bus__DOT__HI_register_write_memory))
                   ? 4U : ((((0U != (IData)(vlTOPp->mips_cpu_bus__DOT__Rt_execute)) 
                             & ((IData)(vlTOPp->mips_cpu_bus__DOT__Rt_execute) 
                                == (IData)(vlTOPp->mips_cpu_bus__DOT__write_register_writeback))) 
                            & (IData)(vlTOPp->mips_cpu_bus__DOT__register_write_writeback))
                            ? 1U : (((IData)(vlTOPp->mips_cpu_bus__DOT__using_HI_LO_execute) 
                                     & (IData)(vlTOPp->mips_cpu_bus__DOT__HI_register_write_writeback))
                                     ? 3U : 0U))));
    if (vlTOPp->reset) {
        vlTOPp->mips_cpu_bus__DOT__read_data_writeback_filtered = 0U;
    } else {
        if ((0x20U & (IData)(vlTOPp->mips_cpu_bus__DOT__op_writeback))) {
            if ((0x10U & (IData)(vlTOPp->mips_cpu_bus__DOT__op_writeback))) {
                vlTOPp->mips_cpu_bus__DOT__memory_filter__DOT__temp_filtered 
                    = vlTOPp->mips_cpu_bus__DOT__read_data_writeback;
            } else {
                if ((8U & (IData)(vlTOPp->mips_cpu_bus__DOT__op_writeback))) {
                    vlTOPp->mips_cpu_bus__DOT__memory_filter__DOT__temp_filtered 
                        = vlTOPp->mips_cpu_bus__DOT__read_data_writeback;
                } else {
                    if ((4U & (IData)(vlTOPp->mips_cpu_bus__DOT__op_writeback))) {
                        if ((2U & (IData)(vlTOPp->mips_cpu_bus__DOT__op_writeback))) {
                            vlTOPp->mips_cpu_bus__DOT__memory_filter__DOT__temp_filtered 
                                = ((1U & (IData)(vlTOPp->mips_cpu_bus__DOT__op_writeback))
                                    ? vlTOPp->mips_cpu_bus__DOT__read_data_writeback
                                    : ((8U & (IData)(vlTOPp->mips_cpu_bus__DOT__byteenable_writeback))
                                        ? ((4U & (IData)(vlTOPp->mips_cpu_bus__DOT__byteenable_writeback))
                                            ? ((2U 
                                                & (IData)(vlTOPp->mips_cpu_bus__DOT__byteenable_writeback))
                                                ? (
                                                   (1U 
                                                    & (IData)(vlTOPp->mips_cpu_bus__DOT__byteenable_writeback))
                                                    ? vlTOPp->mips_cpu_bus__DOT__read_data_writeback
                                                    : 
                                                   ((0xff000000U 
                                                     & vlTOPp->mips_cpu_bus__DOT__src_A_ALU_writeback) 
                                                    | (0xffffffU 
                                                       & (vlTOPp->mips_cpu_bus__DOT__read_data_writeback 
                                                          >> 8U))))
                                                : (
                                                   (1U 
                                                    & (IData)(vlTOPp->mips_cpu_bus__DOT__byteenable_writeback))
                                                    ? vlTOPp->mips_cpu_bus__DOT__read_data_writeback
                                                    : 
                                                   ((0xffff0000U 
                                                     & vlTOPp->mips_cpu_bus__DOT__src_A_ALU_writeback) 
                                                    | (0xffffU 
                                                       & (vlTOPp->mips_cpu_bus__DOT__read_data_writeback 
                                                          >> 0x10U)))))
                                            : ((2U 
                                                & (IData)(vlTOPp->mips_cpu_bus__DOT__byteenable_writeback))
                                                ? vlTOPp->mips_cpu_bus__DOT__read_data_writeback
                                                : (
                                                   (1U 
                                                    & (IData)(vlTOPp->mips_cpu_bus__DOT__byteenable_writeback))
                                                    ? vlTOPp->mips_cpu_bus__DOT__read_data_writeback
                                                    : 
                                                   ((0xffffff00U 
                                                     & vlTOPp->mips_cpu_bus__DOT__src_A_ALU_writeback) 
                                                    | (0xffU 
                                                       & (vlTOPp->mips_cpu_bus__DOT__read_data_writeback 
                                                          >> 0x18U))))))
                                        : vlTOPp->mips_cpu_bus__DOT__read_data_writeback));
                        } else {
                            if ((1U & (IData)(vlTOPp->mips_cpu_bus__DOT__op_writeback))) {
                                vlTOPp->mips_cpu_bus__DOT__memory_filter__DOT__temp_filtered 
                                    = (0xffffU & vlTOPp->mips_cpu_bus__DOT__read_data_writeback);
                            } else {
                                vlTOPp->mips_cpu_bus__DOT__memory_filter__DOT__temp_filtered 
                                    = ((8U & (IData)(vlTOPp->mips_cpu_bus__DOT__byteenable_writeback))
                                        ? ((4U & (IData)(vlTOPp->mips_cpu_bus__DOT__byteenable_writeback))
                                            ? vlTOPp->mips_cpu_bus__DOT__read_data_writeback
                                            : ((2U 
                                                & (IData)(vlTOPp->mips_cpu_bus__DOT__byteenable_writeback))
                                                ? vlTOPp->mips_cpu_bus__DOT__read_data_writeback
                                                : (
                                                   (1U 
                                                    & (IData)(vlTOPp->mips_cpu_bus__DOT__byteenable_writeback))
                                                    ? vlTOPp->mips_cpu_bus__DOT__read_data_writeback
                                                    : 
                                                   (vlTOPp->mips_cpu_bus__DOT__read_data_writeback 
                                                    >> 0x18U))))
                                        : ((4U & (IData)(vlTOPp->mips_cpu_bus__DOT__byteenable_writeback))
                                            ? ((2U 
                                                & (IData)(vlTOPp->mips_cpu_bus__DOT__byteenable_writeback))
                                                ? vlTOPp->mips_cpu_bus__DOT__read_data_writeback
                                                : (
                                                   (1U 
                                                    & (IData)(vlTOPp->mips_cpu_bus__DOT__byteenable_writeback))
                                                    ? vlTOPp->mips_cpu_bus__DOT__read_data_writeback
                                                    : 
                                                   (vlTOPp->mips_cpu_bus__DOT__read_data_writeback 
                                                    >> 0x10U)))
                                            : ((2U 
                                                & (IData)(vlTOPp->mips_cpu_bus__DOT__byteenable_writeback))
                                                ? (
                                                   (1U 
                                                    & (IData)(vlTOPp->mips_cpu_bus__DOT__byteenable_writeback))
                                                    ? vlTOPp->mips_cpu_bus__DOT__read_data_writeback
                                                    : 
                                                   (vlTOPp->mips_cpu_bus__DOT__read_data_writeback 
                                                    >> 8U))
                                                : vlTOPp->mips_cpu_bus__DOT__read_data_writeback)));
                                vlTOPp->mips_cpu_bus__DOT__memory_filter__DOT__temp_filtered 
                                    = (0xffU & vlTOPp->mips_cpu_bus__DOT__memory_filter__DOT__temp_filtered);
                            }
                        }
                    } else {
                        if ((2U & (IData)(vlTOPp->mips_cpu_bus__DOT__op_writeback))) {
                            vlTOPp->mips_cpu_bus__DOT__memory_filter__DOT__temp_filtered 
                                = ((1U & (IData)(vlTOPp->mips_cpu_bus__DOT__op_writeback))
                                    ? vlTOPp->mips_cpu_bus__DOT__read_data_writeback
                                    : ((8U & (IData)(vlTOPp->mips_cpu_bus__DOT__byteenable_writeback))
                                        ? vlTOPp->mips_cpu_bus__DOT__read_data_writeback
                                        : ((4U & (IData)(vlTOPp->mips_cpu_bus__DOT__byteenable_writeback))
                                            ? ((2U 
                                                & (IData)(vlTOPp->mips_cpu_bus__DOT__byteenable_writeback))
                                                ? (
                                                   (1U 
                                                    & (IData)(vlTOPp->mips_cpu_bus__DOT__byteenable_writeback))
                                                    ? 
                                                   ((0xffffff00U 
                                                     & (vlTOPp->mips_cpu_bus__DOT__read_data_writeback 
                                                        << 8U)) 
                                                    | (0xffU 
                                                       & vlTOPp->mips_cpu_bus__DOT__src_A_ALU_writeback))
                                                    : vlTOPp->mips_cpu_bus__DOT__read_data_writeback)
                                                : vlTOPp->mips_cpu_bus__DOT__read_data_writeback)
                                            : ((2U 
                                                & (IData)(vlTOPp->mips_cpu_bus__DOT__byteenable_writeback))
                                                ? (
                                                   (1U 
                                                    & (IData)(vlTOPp->mips_cpu_bus__DOT__byteenable_writeback))
                                                    ? 
                                                   ((0xffff0000U 
                                                     & (vlTOPp->mips_cpu_bus__DOT__read_data_writeback 
                                                        << 0x10U)) 
                                                    | (0xffffU 
                                                       & vlTOPp->mips_cpu_bus__DOT__src_A_ALU_writeback))
                                                    : vlTOPp->mips_cpu_bus__DOT__read_data_writeback)
                                                : (
                                                   (1U 
                                                    & (IData)(vlTOPp->mips_cpu_bus__DOT__byteenable_writeback))
                                                    ? 
                                                   ((0xff000000U 
                                                     & (vlTOPp->mips_cpu_bus__DOT__read_data_writeback 
                                                        << 0x18U)) 
                                                    | (0xffffffU 
                                                       & vlTOPp->mips_cpu_bus__DOT__src_A_ALU_writeback))
                                                    : vlTOPp->mips_cpu_bus__DOT__read_data_writeback)))));
                        } else {
                            if ((1U & (IData)(vlTOPp->mips_cpu_bus__DOT__op_writeback))) {
                                vlTOPp->mips_cpu_bus__DOT__memory_filter__DOT__temp_filtered 
                                    = ((0xffff0000U 
                                        & (VL_NEGATE_I((IData)(
                                                               (1U 
                                                                & (vlTOPp->mips_cpu_bus__DOT__read_data_writeback 
                                                                   >> 0xfU)))) 
                                           << 0x10U)) 
                                       | (0xffffU & vlTOPp->mips_cpu_bus__DOT__read_data_writeback));
                            } else {
                                vlTOPp->mips_cpu_bus__DOT__memory_filter__DOT__temp_filtered 
                                    = ((8U & (IData)(vlTOPp->mips_cpu_bus__DOT__byteenable_writeback))
                                        ? ((4U & (IData)(vlTOPp->mips_cpu_bus__DOT__byteenable_writeback))
                                            ? vlTOPp->mips_cpu_bus__DOT__read_data_writeback
                                            : ((2U 
                                                & (IData)(vlTOPp->mips_cpu_bus__DOT__byteenable_writeback))
                                                ? vlTOPp->mips_cpu_bus__DOT__read_data_writeback
                                                : (
                                                   (1U 
                                                    & (IData)(vlTOPp->mips_cpu_bus__DOT__byteenable_writeback))
                                                    ? vlTOPp->mips_cpu_bus__DOT__read_data_writeback
                                                    : 
                                                   (vlTOPp->mips_cpu_bus__DOT__read_data_writeback 
                                                    >> 0x18U))))
                                        : ((4U & (IData)(vlTOPp->mips_cpu_bus__DOT__byteenable_writeback))
                                            ? ((2U 
                                                & (IData)(vlTOPp->mips_cpu_bus__DOT__byteenable_writeback))
                                                ? vlTOPp->mips_cpu_bus__DOT__read_data_writeback
                                                : (
                                                   (1U 
                                                    & (IData)(vlTOPp->mips_cpu_bus__DOT__byteenable_writeback))
                                                    ? vlTOPp->mips_cpu_bus__DOT__read_data_writeback
                                                    : 
                                                   (vlTOPp->mips_cpu_bus__DOT__read_data_writeback 
                                                    >> 0x10U)))
                                            : ((2U 
                                                & (IData)(vlTOPp->mips_cpu_bus__DOT__byteenable_writeback))
                                                ? (
                                                   (1U 
                                                    & (IData)(vlTOPp->mips_cpu_bus__DOT__byteenable_writeback))
                                                    ? vlTOPp->mips_cpu_bus__DOT__read_data_writeback
                                                    : 
                                                   (vlTOPp->mips_cpu_bus__DOT__read_data_writeback 
                                                    >> 8U))
                                                : vlTOPp->mips_cpu_bus__DOT__read_data_writeback)));
                                vlTOPp->mips_cpu_bus__DOT__memory_filter__DOT__temp_filtered 
                                    = ((0xffffff00U 
                                        & (VL_NEGATE_I((IData)(
                                                               (1U 
                                                                & (vlTOPp->mips_cpu_bus__DOT__memory_filter__DOT__temp_filtered 
                                                                   >> 7U)))) 
                                           << 8U)) 
                                       | (0xffU & vlTOPp->mips_cpu_bus__DOT__memory_filter__DOT__temp_filtered));
                            }
                        }
                    }
                }
            }
        } else {
            vlTOPp->mips_cpu_bus__DOT__memory_filter__DOT__temp_filtered 
                = vlTOPp->mips_cpu_bus__DOT__read_data_writeback;
        }
        vlTOPp->mips_cpu_bus__DOT__read_data_writeback_filtered 
            = vlTOPp->mips_cpu_bus__DOT__memory_filter__DOT__temp_filtered;
    }
    vlTOPp->mips_cpu_bus__DOT__control_unit__DOT__op 
        = (0x3fU & (vlTOPp->mips_cpu_bus__DOT__instruction_decode 
                    >> 0x1aU));
    vlTOPp->mips_cpu_bus__DOT__control_unit__DOT__rt 
        = (0x1fU & (vlTOPp->mips_cpu_bus__DOT__instruction_decode 
                    >> 0x10U));
    vlTOPp->mips_cpu_bus__DOT__control_unit__DOT__funct 
        = (0x3fU & vlTOPp->mips_cpu_bus__DOT__instruction_decode);
    if ((0x20U & (IData)(vlTOPp->mips_cpu_bus__DOT__control_unit__DOT__op))) {
        if ((0x10U & (IData)(vlTOPp->mips_cpu_bus__DOT__control_unit__DOT__op))) {
            vlTOPp->mips_cpu_bus__DOT__register_write_decode = 0U;
            vlTOPp->mips_cpu_bus__DOT__memory_to_register_decode = 0U;
            vlTOPp->mips_cpu_bus__DOT__memory_write_decode = 0U;
            vlTOPp->mips_cpu_bus__DOT__ALU_src_B_decode = 0U;
            vlTOPp->mips_cpu_bus__DOT__register_destination_decode = 0U;
            vlTOPp->mips_cpu_bus__DOT__branch_decode = 0U;
            vlTOPp->mips_cpu_bus__DOT__HI_register_write_decode = 0U;
            vlTOPp->mips_cpu_bus__DOT__LO_register_write_decode = 0U;
            vlTOPp->mips_cpu_bus__DOT__ALU_function_decode = 0U;
            vlTOPp->mips_cpu_bus__DOT__program_counter_multiplexer_jump_decode = 0U;
            vlTOPp->mips_cpu_bus__DOT__j_instruction_decode = 0U;
            vlTOPp->mips_cpu_bus__DOT__using_HI_LO_decode = 0U;
        } else {
            if ((8U & (IData)(vlTOPp->mips_cpu_bus__DOT__control_unit__DOT__op))) {
                if ((4U & (IData)(vlTOPp->mips_cpu_bus__DOT__control_unit__DOT__op))) {
                    vlTOPp->mips_cpu_bus__DOT__register_write_decode = 0U;
                    vlTOPp->mips_cpu_bus__DOT__memory_to_register_decode = 0U;
                    vlTOPp->mips_cpu_bus__DOT__memory_write_decode = 0U;
                    vlTOPp->mips_cpu_bus__DOT__ALU_src_B_decode = 0U;
                    vlTOPp->mips_cpu_bus__DOT__register_destination_decode = 0U;
                    vlTOPp->mips_cpu_bus__DOT__branch_decode = 0U;
                    vlTOPp->mips_cpu_bus__DOT__HI_register_write_decode = 0U;
                    vlTOPp->mips_cpu_bus__DOT__LO_register_write_decode = 0U;
                    vlTOPp->mips_cpu_bus__DOT__ALU_function_decode = 0U;
                    vlTOPp->mips_cpu_bus__DOT__program_counter_multiplexer_jump_decode = 0U;
                    vlTOPp->mips_cpu_bus__DOT__j_instruction_decode = 0U;
                    vlTOPp->mips_cpu_bus__DOT__using_HI_LO_decode = 0U;
                } else {
                    if ((2U & (IData)(vlTOPp->mips_cpu_bus__DOT__control_unit__DOT__op))) {
                        if ((1U & (IData)(vlTOPp->mips_cpu_bus__DOT__control_unit__DOT__op))) {
                            vlTOPp->mips_cpu_bus__DOT__register_write_decode = 0U;
                            vlTOPp->mips_cpu_bus__DOT__memory_to_register_decode = 0U;
                            vlTOPp->mips_cpu_bus__DOT__memory_write_decode = 1U;
                            vlTOPp->mips_cpu_bus__DOT__ALU_src_B_decode = 1U;
                            vlTOPp->mips_cpu_bus__DOT__register_destination_decode = 0U;
                            vlTOPp->mips_cpu_bus__DOT__branch_decode = 0U;
                            vlTOPp->mips_cpu_bus__DOT__HI_register_write_decode = 0U;
                            vlTOPp->mips_cpu_bus__DOT__LO_register_write_decode = 0U;
                            vlTOPp->mips_cpu_bus__DOT__ALU_function_decode = 0x21U;
                            vlTOPp->mips_cpu_bus__DOT__program_counter_multiplexer_jump_decode = 0U;
                            vlTOPp->mips_cpu_bus__DOT__j_instruction_decode = 0U;
                            vlTOPp->mips_cpu_bus__DOT__using_HI_LO_decode = 0U;
                        } else {
                            vlTOPp->mips_cpu_bus__DOT__register_write_decode = 0U;
                            vlTOPp->mips_cpu_bus__DOT__memory_to_register_decode = 0U;
                            vlTOPp->mips_cpu_bus__DOT__memory_write_decode = 0U;
                            vlTOPp->mips_cpu_bus__DOT__ALU_src_B_decode = 0U;
                            vlTOPp->mips_cpu_bus__DOT__register_destination_decode = 0U;
                            vlTOPp->mips_cpu_bus__DOT__branch_decode = 0U;
                            vlTOPp->mips_cpu_bus__DOT__HI_register_write_decode = 0U;
                            vlTOPp->mips_cpu_bus__DOT__LO_register_write_decode = 0U;
                            vlTOPp->mips_cpu_bus__DOT__ALU_function_decode = 0U;
                            vlTOPp->mips_cpu_bus__DOT__program_counter_multiplexer_jump_decode = 0U;
                            vlTOPp->mips_cpu_bus__DOT__j_instruction_decode = 0U;
                            vlTOPp->mips_cpu_bus__DOT__using_HI_LO_decode = 0U;
                        }
                    } else {
                        vlTOPp->mips_cpu_bus__DOT__register_write_decode = 0U;
                        vlTOPp->mips_cpu_bus__DOT__memory_to_register_decode = 0U;
                        vlTOPp->mips_cpu_bus__DOT__memory_write_decode = 0U;
                        vlTOPp->mips_cpu_bus__DOT__ALU_src_B_decode = 0U;
                        vlTOPp->mips_cpu_bus__DOT__register_destination_decode = 0U;
                        vlTOPp->mips_cpu_bus__DOT__branch_decode = 0U;
                        vlTOPp->mips_cpu_bus__DOT__HI_register_write_decode = 0U;
                        vlTOPp->mips_cpu_bus__DOT__LO_register_write_decode = 0U;
                        vlTOPp->mips_cpu_bus__DOT__ALU_function_decode = 0U;
                        vlTOPp->mips_cpu_bus__DOT__program_counter_multiplexer_jump_decode = 0U;
                        vlTOPp->mips_cpu_bus__DOT__j_instruction_decode = 0U;
                        vlTOPp->mips_cpu_bus__DOT__using_HI_LO_decode = 0U;
                    }
                }
            } else {
                if ((4U & (IData)(vlTOPp->mips_cpu_bus__DOT__control_unit__DOT__op))) {
                    if ((2U & (IData)(vlTOPp->mips_cpu_bus__DOT__control_unit__DOT__op))) {
                        vlTOPp->mips_cpu_bus__DOT__register_write_decode = 0U;
                        vlTOPp->mips_cpu_bus__DOT__memory_to_register_decode = 0U;
                        vlTOPp->mips_cpu_bus__DOT__memory_write_decode = 0U;
                        vlTOPp->mips_cpu_bus__DOT__ALU_src_B_decode = 0U;
                        vlTOPp->mips_cpu_bus__DOT__register_destination_decode = 0U;
                        vlTOPp->mips_cpu_bus__DOT__branch_decode = 0U;
                        vlTOPp->mips_cpu_bus__DOT__HI_register_write_decode = 0U;
                        vlTOPp->mips_cpu_bus__DOT__LO_register_write_decode = 0U;
                        vlTOPp->mips_cpu_bus__DOT__ALU_function_decode = 0U;
                        vlTOPp->mips_cpu_bus__DOT__program_counter_multiplexer_jump_decode = 0U;
                        vlTOPp->mips_cpu_bus__DOT__j_instruction_decode = 0U;
                        vlTOPp->mips_cpu_bus__DOT__using_HI_LO_decode = 0U;
                    } else {
                        if ((1U & (IData)(vlTOPp->mips_cpu_bus__DOT__control_unit__DOT__op))) {
                            vlTOPp->mips_cpu_bus__DOT__register_write_decode = 0U;
                            vlTOPp->mips_cpu_bus__DOT__memory_to_register_decode = 0U;
                            vlTOPp->mips_cpu_bus__DOT__memory_write_decode = 1U;
                            vlTOPp->mips_cpu_bus__DOT__ALU_src_B_decode = 1U;
                            vlTOPp->mips_cpu_bus__DOT__register_destination_decode = 0U;
                            vlTOPp->mips_cpu_bus__DOT__branch_decode = 0U;
                            vlTOPp->mips_cpu_bus__DOT__HI_register_write_decode = 0U;
                            vlTOPp->mips_cpu_bus__DOT__LO_register_write_decode = 0U;
                            vlTOPp->mips_cpu_bus__DOT__ALU_function_decode = 0x21U;
                            vlTOPp->mips_cpu_bus__DOT__program_counter_multiplexer_jump_decode = 0U;
                            vlTOPp->mips_cpu_bus__DOT__j_instruction_decode = 0U;
                            vlTOPp->mips_cpu_bus__DOT__using_HI_LO_decode = 0U;
                        } else {
                            vlTOPp->mips_cpu_bus__DOT__register_write_decode = 0U;
                            vlTOPp->mips_cpu_bus__DOT__memory_to_register_decode = 0U;
                            vlTOPp->mips_cpu_bus__DOT__memory_write_decode = 0U;
                            vlTOPp->mips_cpu_bus__DOT__ALU_src_B_decode = 0U;
                            vlTOPp->mips_cpu_bus__DOT__register_destination_decode = 0U;
                            vlTOPp->mips_cpu_bus__DOT__branch_decode = 0U;
                            vlTOPp->mips_cpu_bus__DOT__HI_register_write_decode = 0U;
                            vlTOPp->mips_cpu_bus__DOT__LO_register_write_decode = 0U;
                            vlTOPp->mips_cpu_bus__DOT__ALU_function_decode = 0U;
                            vlTOPp->mips_cpu_bus__DOT__program_counter_multiplexer_jump_decode = 0U;
                            vlTOPp->mips_cpu_bus__DOT__j_instruction_decode = 0U;
                            vlTOPp->mips_cpu_bus__DOT__using_HI_LO_decode = 0U;
                        }
                    }
                } else {
                    vlTOPp->mips_cpu_bus__DOT__register_write_decode = 0U;
                    vlTOPp->mips_cpu_bus__DOT__memory_to_register_decode = 0U;
                    vlTOPp->mips_cpu_bus__DOT__memory_write_decode = 0U;
                    vlTOPp->mips_cpu_bus__DOT__ALU_src_B_decode = 0U;
                    vlTOPp->mips_cpu_bus__DOT__register_destination_decode = 0U;
                    vlTOPp->mips_cpu_bus__DOT__branch_decode = 0U;
                    vlTOPp->mips_cpu_bus__DOT__HI_register_write_decode = 0U;
                    vlTOPp->mips_cpu_bus__DOT__LO_register_write_decode = 0U;
                    vlTOPp->mips_cpu_bus__DOT__ALU_function_decode = 0U;
                    vlTOPp->mips_cpu_bus__DOT__program_counter_multiplexer_jump_decode = 0U;
                    vlTOPp->mips_cpu_bus__DOT__j_instruction_decode = 0U;
                    vlTOPp->mips_cpu_bus__DOT__using_HI_LO_decode = 0U;
                }
            }
        }
    } else {
        if ((0x10U & (IData)(vlTOPp->mips_cpu_bus__DOT__control_unit__DOT__op))) {
            vlTOPp->mips_cpu_bus__DOT__register_write_decode = 0U;
            vlTOPp->mips_cpu_bus__DOT__memory_to_register_decode = 0U;
            vlTOPp->mips_cpu_bus__DOT__memory_write_decode = 0U;
            vlTOPp->mips_cpu_bus__DOT__ALU_src_B_decode = 0U;
            vlTOPp->mips_cpu_bus__DOT__register_destination_decode = 0U;
            vlTOPp->mips_cpu_bus__DOT__branch_decode = 0U;
            vlTOPp->mips_cpu_bus__DOT__HI_register_write_decode = 0U;
            vlTOPp->mips_cpu_bus__DOT__LO_register_write_decode = 0U;
            vlTOPp->mips_cpu_bus__DOT__ALU_function_decode = 0U;
            vlTOPp->mips_cpu_bus__DOT__program_counter_multiplexer_jump_decode = 0U;
            vlTOPp->mips_cpu_bus__DOT__j_instruction_decode = 0U;
            vlTOPp->mips_cpu_bus__DOT__using_HI_LO_decode = 0U;
        } else {
            if ((8U & (IData)(vlTOPp->mips_cpu_bus__DOT__control_unit__DOT__op))) {
                if ((4U & (IData)(vlTOPp->mips_cpu_bus__DOT__control_unit__DOT__op))) {
                    if ((2U & (IData)(vlTOPp->mips_cpu_bus__DOT__control_unit__DOT__op))) {
                        if ((1U & (IData)(vlTOPp->mips_cpu_bus__DOT__control_unit__DOT__op))) {
                            vlTOPp->mips_cpu_bus__DOT__register_write_decode = 1U;
                            vlTOPp->mips_cpu_bus__DOT__memory_to_register_decode = 0U;
                            vlTOPp->mips_cpu_bus__DOT__memory_write_decode = 0U;
                            vlTOPp->mips_cpu_bus__DOT__ALU_src_B_decode = 1U;
                            vlTOPp->mips_cpu_bus__DOT__register_destination_decode = 0U;
                            vlTOPp->mips_cpu_bus__DOT__branch_decode = 0U;
                            vlTOPp->mips_cpu_bus__DOT__HI_register_write_decode = 0U;
                            vlTOPp->mips_cpu_bus__DOT__LO_register_write_decode = 0U;
                            vlTOPp->mips_cpu_bus__DOT__ALU_function_decode = 0x3fU;
                            vlTOPp->mips_cpu_bus__DOT__program_counter_multiplexer_jump_decode = 0U;
                            vlTOPp->mips_cpu_bus__DOT__j_instruction_decode = 0U;
                            vlTOPp->mips_cpu_bus__DOT__using_HI_LO_decode = 0U;
                        } else {
                            vlTOPp->mips_cpu_bus__DOT__register_write_decode = 1U;
                            vlTOPp->mips_cpu_bus__DOT__memory_to_register_decode = 0U;
                            vlTOPp->mips_cpu_bus__DOT__memory_write_decode = 0U;
                            vlTOPp->mips_cpu_bus__DOT__ALU_src_B_decode = 1U;
                            vlTOPp->mips_cpu_bus__DOT__register_destination_decode = 0U;
                            vlTOPp->mips_cpu_bus__DOT__branch_decode = 0U;
                            vlTOPp->mips_cpu_bus__DOT__HI_register_write_decode = 0U;
                            vlTOPp->mips_cpu_bus__DOT__LO_register_write_decode = 0U;
                            vlTOPp->mips_cpu_bus__DOT__ALU_function_decode = 0x26U;
                            vlTOPp->mips_cpu_bus__DOT__program_counter_multiplexer_jump_decode = 0U;
                            vlTOPp->mips_cpu_bus__DOT__j_instruction_decode = 0U;
                            vlTOPp->mips_cpu_bus__DOT__using_HI_LO_decode = 0U;
                        }
                    } else {
                        if ((1U & (IData)(vlTOPp->mips_cpu_bus__DOT__control_unit__DOT__op))) {
                            vlTOPp->mips_cpu_bus__DOT__register_write_decode = 1U;
                            vlTOPp->mips_cpu_bus__DOT__memory_to_register_decode = 0U;
                            vlTOPp->mips_cpu_bus__DOT__memory_write_decode = 0U;
                            vlTOPp->mips_cpu_bus__DOT__ALU_src_B_decode = 1U;
                            vlTOPp->mips_cpu_bus__DOT__register_destination_decode = 0U;
                            vlTOPp->mips_cpu_bus__DOT__branch_decode = 0U;
                            vlTOPp->mips_cpu_bus__DOT__HI_register_write_decode = 0U;
                            vlTOPp->mips_cpu_bus__DOT__LO_register_write_decode = 0U;
                            vlTOPp->mips_cpu_bus__DOT__ALU_function_decode = 0x25U;
                            vlTOPp->mips_cpu_bus__DOT__program_counter_multiplexer_jump_decode = 0U;
                            vlTOPp->mips_cpu_bus__DOT__j_instruction_decode = 0U;
                            vlTOPp->mips_cpu_bus__DOT__using_HI_LO_decode = 0U;
                        } else {
                            vlTOPp->mips_cpu_bus__DOT__register_write_decode = 1U;
                            vlTOPp->mips_cpu_bus__DOT__memory_to_register_decode = 0U;
                            vlTOPp->mips_cpu_bus__DOT__memory_write_decode = 0U;
                            vlTOPp->mips_cpu_bus__DOT__ALU_src_B_decode = 1U;
                            vlTOPp->mips_cpu_bus__DOT__register_destination_decode = 0U;
                            vlTOPp->mips_cpu_bus__DOT__branch_decode = 0U;
                            vlTOPp->mips_cpu_bus__DOT__HI_register_write_decode = 0U;
                            vlTOPp->mips_cpu_bus__DOT__LO_register_write_decode = 0U;
                            vlTOPp->mips_cpu_bus__DOT__ALU_function_decode = 0x24U;
                            vlTOPp->mips_cpu_bus__DOT__program_counter_multiplexer_jump_decode = 0U;
                            vlTOPp->mips_cpu_bus__DOT__j_instruction_decode = 0U;
                            vlTOPp->mips_cpu_bus__DOT__using_HI_LO_decode = 0U;
                        }
                    }
                } else {
                    if ((2U & (IData)(vlTOPp->mips_cpu_bus__DOT__control_unit__DOT__op))) {
                        if ((1U & (IData)(vlTOPp->mips_cpu_bus__DOT__control_unit__DOT__op))) {
                            vlTOPp->mips_cpu_bus__DOT__register_write_decode = 0U;
                            vlTOPp->mips_cpu_bus__DOT__memory_to_register_decode = 0U;
                            vlTOPp->mips_cpu_bus__DOT__memory_write_decode = 0U;
                            vlTOPp->mips_cpu_bus__DOT__ALU_src_B_decode = 0U;
                            vlTOPp->mips_cpu_bus__DOT__register_destination_decode = 0U;
                            vlTOPp->mips_cpu_bus__DOT__branch_decode = 0U;
                            vlTOPp->mips_cpu_bus__DOT__HI_register_write_decode = 0U;
                            vlTOPp->mips_cpu_bus__DOT__LO_register_write_decode = 0U;
                            vlTOPp->mips_cpu_bus__DOT__ALU_function_decode = 0U;
                            vlTOPp->mips_cpu_bus__DOT__program_counter_multiplexer_jump_decode = 0U;
                            vlTOPp->mips_cpu_bus__DOT__j_instruction_decode = 0U;
                            vlTOPp->mips_cpu_bus__DOT__using_HI_LO_decode = 0U;
                        } else {
                            vlTOPp->mips_cpu_bus__DOT__register_write_decode = 1U;
                            vlTOPp->mips_cpu_bus__DOT__memory_to_register_decode = 0U;
                            vlTOPp->mips_cpu_bus__DOT__memory_write_decode = 0U;
                            vlTOPp->mips_cpu_bus__DOT__ALU_src_B_decode = 1U;
                            vlTOPp->mips_cpu_bus__DOT__register_destination_decode = 0U;
                            vlTOPp->mips_cpu_bus__DOT__branch_decode = 0U;
                            vlTOPp->mips_cpu_bus__DOT__HI_register_write_decode = 0U;
                            vlTOPp->mips_cpu_bus__DOT__LO_register_write_decode = 0U;
                            vlTOPp->mips_cpu_bus__DOT__ALU_function_decode = 0x21U;
                            vlTOPp->mips_cpu_bus__DOT__program_counter_multiplexer_jump_decode = 0U;
                            vlTOPp->mips_cpu_bus__DOT__j_instruction_decode = 0U;
                            vlTOPp->mips_cpu_bus__DOT__using_HI_LO_decode = 0U;
                        }
                    } else {
                        if ((1U & (IData)(vlTOPp->mips_cpu_bus__DOT__control_unit__DOT__op))) {
                            vlTOPp->mips_cpu_bus__DOT__register_write_decode = 1U;
                            vlTOPp->mips_cpu_bus__DOT__memory_to_register_decode = 0U;
                            vlTOPp->mips_cpu_bus__DOT__memory_write_decode = 0U;
                            vlTOPp->mips_cpu_bus__DOT__ALU_src_B_decode = 1U;
                            vlTOPp->mips_cpu_bus__DOT__register_destination_decode = 0U;
                            vlTOPp->mips_cpu_bus__DOT__branch_decode = 0U;
                            vlTOPp->mips_cpu_bus__DOT__HI_register_write_decode = 0U;
                            vlTOPp->mips_cpu_bus__DOT__LO_register_write_decode = 0U;
                            vlTOPp->mips_cpu_bus__DOT__ALU_function_decode = 0x21U;
                            vlTOPp->mips_cpu_bus__DOT__program_counter_multiplexer_jump_decode = 0U;
                            vlTOPp->mips_cpu_bus__DOT__j_instruction_decode = 0U;
                            vlTOPp->mips_cpu_bus__DOT__using_HI_LO_decode = 0U;
                        } else {
                            vlTOPp->mips_cpu_bus__DOT__register_write_decode = 1U;
                            vlTOPp->mips_cpu_bus__DOT__memory_to_register_decode = 0U;
                            vlTOPp->mips_cpu_bus__DOT__memory_write_decode = 0U;
                            vlTOPp->mips_cpu_bus__DOT__ALU_src_B_decode = 1U;
                            vlTOPp->mips_cpu_bus__DOT__register_destination_decode = 0U;
                            vlTOPp->mips_cpu_bus__DOT__branch_decode = 0U;
                            vlTOPp->mips_cpu_bus__DOT__HI_register_write_decode = 0U;
                            vlTOPp->mips_cpu_bus__DOT__LO_register_write_decode = 0U;
                            vlTOPp->mips_cpu_bus__DOT__ALU_function_decode = 0x20U;
                            vlTOPp->mips_cpu_bus__DOT__program_counter_multiplexer_jump_decode = 0U;
                            vlTOPp->mips_cpu_bus__DOT__j_instruction_decode = 0U;
                            vlTOPp->mips_cpu_bus__DOT__using_HI_LO_decode = 0U;
                        }
                    }
                }
            } else {
                if ((4U & (IData)(vlTOPp->mips_cpu_bus__DOT__control_unit__DOT__op))) {
                    if ((2U & (IData)(vlTOPp->mips_cpu_bus__DOT__control_unit__DOT__op))) {
                        if ((1U & (IData)(vlTOPp->mips_cpu_bus__DOT__control_unit__DOT__op))) {
                            vlTOPp->mips_cpu_bus__DOT__register_write_decode = 0U;
                            vlTOPp->mips_cpu_bus__DOT__memory_to_register_decode = 0U;
                            vlTOPp->mips_cpu_bus__DOT__memory_write_decode = 0U;
                            vlTOPp->mips_cpu_bus__DOT__ALU_src_B_decode = 0U;
                            vlTOPp->mips_cpu_bus__DOT__register_destination_decode = 0U;
                            vlTOPp->mips_cpu_bus__DOT__branch_decode = 1U;
                            vlTOPp->mips_cpu_bus__DOT__HI_register_write_decode = 0U;
                            vlTOPp->mips_cpu_bus__DOT__LO_register_write_decode = 0U;
                            vlTOPp->mips_cpu_bus__DOT__ALU_function_decode = 0x3fU;
                            vlTOPp->mips_cpu_bus__DOT__program_counter_multiplexer_jump_decode = 0U;
                            vlTOPp->mips_cpu_bus__DOT__j_instruction_decode = 0U;
                            vlTOPp->mips_cpu_bus__DOT__using_HI_LO_decode = 0U;
                        } else {
                            vlTOPp->mips_cpu_bus__DOT__register_write_decode = 0U;
                            vlTOPp->mips_cpu_bus__DOT__memory_to_register_decode = 0U;
                            vlTOPp->mips_cpu_bus__DOT__memory_write_decode = 0U;
                            vlTOPp->mips_cpu_bus__DOT__ALU_src_B_decode = 0U;
                            vlTOPp->mips_cpu_bus__DOT__register_destination_decode = 0U;
                            vlTOPp->mips_cpu_bus__DOT__branch_decode = 1U;
                            vlTOPp->mips_cpu_bus__DOT__HI_register_write_decode = 0U;
                            vlTOPp->mips_cpu_bus__DOT__LO_register_write_decode = 0U;
                            vlTOPp->mips_cpu_bus__DOT__ALU_function_decode = 0x3fU;
                            vlTOPp->mips_cpu_bus__DOT__program_counter_multiplexer_jump_decode = 0U;
                            vlTOPp->mips_cpu_bus__DOT__j_instruction_decode = 0U;
                            vlTOPp->mips_cpu_bus__DOT__using_HI_LO_decode = 0U;
                        }
                    } else {
                        if ((1U & (IData)(vlTOPp->mips_cpu_bus__DOT__control_unit__DOT__op))) {
                            vlTOPp->mips_cpu_bus__DOT__register_write_decode = 0U;
                            vlTOPp->mips_cpu_bus__DOT__memory_to_register_decode = 0U;
                            vlTOPp->mips_cpu_bus__DOT__memory_write_decode = 0U;
                            vlTOPp->mips_cpu_bus__DOT__ALU_src_B_decode = 0U;
                            vlTOPp->mips_cpu_bus__DOT__register_destination_decode = 0U;
                            vlTOPp->mips_cpu_bus__DOT__branch_decode = 1U;
                            vlTOPp->mips_cpu_bus__DOT__HI_register_write_decode = 0U;
                            vlTOPp->mips_cpu_bus__DOT__LO_register_write_decode = 0U;
                            vlTOPp->mips_cpu_bus__DOT__ALU_function_decode = 0x3fU;
                            vlTOPp->mips_cpu_bus__DOT__program_counter_multiplexer_jump_decode = 0U;
                            vlTOPp->mips_cpu_bus__DOT__j_instruction_decode = 0U;
                            vlTOPp->mips_cpu_bus__DOT__using_HI_LO_decode = 0U;
                        } else {
                            vlTOPp->mips_cpu_bus__DOT__register_write_decode = 0U;
                            vlTOPp->mips_cpu_bus__DOT__memory_to_register_decode = 0U;
                            vlTOPp->mips_cpu_bus__DOT__memory_write_decode = 0U;
                            vlTOPp->mips_cpu_bus__DOT__ALU_src_B_decode = 0U;
                            vlTOPp->mips_cpu_bus__DOT__register_destination_decode = 0U;
                            vlTOPp->mips_cpu_bus__DOT__branch_decode = 1U;
                            vlTOPp->mips_cpu_bus__DOT__HI_register_write_decode = 0U;
                            vlTOPp->mips_cpu_bus__DOT__LO_register_write_decode = 0U;
                            vlTOPp->mips_cpu_bus__DOT__ALU_function_decode = 0x3fU;
                            vlTOPp->mips_cpu_bus__DOT__program_counter_multiplexer_jump_decode = 0U;
                            vlTOPp->mips_cpu_bus__DOT__j_instruction_decode = 0U;
                            vlTOPp->mips_cpu_bus__DOT__using_HI_LO_decode = 0U;
                        }
                    }
                } else {
                    if ((2U & (IData)(vlTOPp->mips_cpu_bus__DOT__control_unit__DOT__op))) {
                        if ((1U & (IData)(vlTOPp->mips_cpu_bus__DOT__control_unit__DOT__op))) {
                            vlTOPp->mips_cpu_bus__DOT__register_write_decode = 1U;
                            vlTOPp->mips_cpu_bus__DOT__memory_to_register_decode = 0U;
                            vlTOPp->mips_cpu_bus__DOT__memory_write_decode = 0U;
                            vlTOPp->mips_cpu_bus__DOT__ALU_src_B_decode = 2U;
                            vlTOPp->mips_cpu_bus__DOT__register_destination_decode = 2U;
                            vlTOPp->mips_cpu_bus__DOT__branch_decode = 1U;
                            vlTOPp->mips_cpu_bus__DOT__HI_register_write_decode = 0U;
                            vlTOPp->mips_cpu_bus__DOT__LO_register_write_decode = 0U;
                            vlTOPp->mips_cpu_bus__DOT__ALU_function_decode = 0x3fU;
                            vlTOPp->mips_cpu_bus__DOT__program_counter_multiplexer_jump_decode = 1U;
                            vlTOPp->mips_cpu_bus__DOT__j_instruction_decode = 1U;
                            vlTOPp->mips_cpu_bus__DOT__using_HI_LO_decode = 0U;
                        } else {
                            vlTOPp->mips_cpu_bus__DOT__register_write_decode = 0U;
                            vlTOPp->mips_cpu_bus__DOT__memory_to_register_decode = 0U;
                            vlTOPp->mips_cpu_bus__DOT__memory_write_decode = 0U;
                            vlTOPp->mips_cpu_bus__DOT__ALU_src_B_decode = 2U;
                            vlTOPp->mips_cpu_bus__DOT__register_destination_decode = 2U;
                            vlTOPp->mips_cpu_bus__DOT__branch_decode = 1U;
                            vlTOPp->mips_cpu_bus__DOT__HI_register_write_decode = 0U;
                            vlTOPp->mips_cpu_bus__DOT__LO_register_write_decode = 0U;
                            vlTOPp->mips_cpu_bus__DOT__ALU_function_decode = 0x3fU;
                            vlTOPp->mips_cpu_bus__DOT__program_counter_multiplexer_jump_decode = 1U;
                            vlTOPp->mips_cpu_bus__DOT__j_instruction_decode = 1U;
                            vlTOPp->mips_cpu_bus__DOT__using_HI_LO_decode = 0U;
                        }
                    } else {
                        if ((1U & (IData)(vlTOPp->mips_cpu_bus__DOT__control_unit__DOT__op))) {
                            vlTOPp->mips_cpu_bus__DOT__register_write_decode 
                                = ((0x11U == (IData)(vlTOPp->mips_cpu_bus__DOT__control_unit__DOT__rt)) 
                                   | (0x10U == (IData)(vlTOPp->mips_cpu_bus__DOT__control_unit__DOT__rt)));
                            vlTOPp->mips_cpu_bus__DOT__memory_to_register_decode = 0U;
                            vlTOPp->mips_cpu_bus__DOT__memory_write_decode = 0U;
                            vlTOPp->mips_cpu_bus__DOT__ALU_src_B_decode = 2U;
                            vlTOPp->mips_cpu_bus__DOT__register_destination_decode = 2U;
                            vlTOPp->mips_cpu_bus__DOT__branch_decode = 1U;
                            vlTOPp->mips_cpu_bus__DOT__HI_register_write_decode = 0U;
                            vlTOPp->mips_cpu_bus__DOT__LO_register_write_decode = 0U;
                            vlTOPp->mips_cpu_bus__DOT__ALU_function_decode = 0x3fU;
                            vlTOPp->mips_cpu_bus__DOT__program_counter_multiplexer_jump_decode = 0U;
                            vlTOPp->mips_cpu_bus__DOT__j_instruction_decode = 0U;
                            vlTOPp->mips_cpu_bus__DOT__using_HI_LO_decode = 0U;
                        } else {
                            vlTOPp->mips_cpu_bus__DOT__register_write_decode = 1U;
                            vlTOPp->mips_cpu_bus__DOT__memory_to_register_decode = 0U;
                            vlTOPp->mips_cpu_bus__DOT__memory_write_decode = 0U;
                            vlTOPp->mips_cpu_bus__DOT__ALU_src_B_decode = 0U;
                            vlTOPp->mips_cpu_bus__DOT__register_destination_decode = 1U;
                            vlTOPp->mips_cpu_bus__DOT__branch_decode = 0U;
                            vlTOPp->mips_cpu_bus__DOT__HI_register_write_decode 
                                = (((((0x18U == (IData)(vlTOPp->mips_cpu_bus__DOT__control_unit__DOT__funct)) 
                                      | (0x19U == (IData)(vlTOPp->mips_cpu_bus__DOT__control_unit__DOT__funct))) 
                                     | (0x1aU == (IData)(vlTOPp->mips_cpu_bus__DOT__control_unit__DOT__funct))) 
                                    | (0x1bU == (IData)(vlTOPp->mips_cpu_bus__DOT__control_unit__DOT__funct))) 
                                   | (0x11U == (IData)(vlTOPp->mips_cpu_bus__DOT__control_unit__DOT__funct)));
                            vlTOPp->mips_cpu_bus__DOT__j_instruction_decode = 0U;
                            vlTOPp->mips_cpu_bus__DOT__LO_register_write_decode 
                                = (((((0x18U == (IData)(vlTOPp->mips_cpu_bus__DOT__control_unit__DOT__funct)) 
                                      | (0x19U == (IData)(vlTOPp->mips_cpu_bus__DOT__control_unit__DOT__funct))) 
                                     | (0x1aU == (IData)(vlTOPp->mips_cpu_bus__DOT__control_unit__DOT__funct))) 
                                    | (0x1bU == (IData)(vlTOPp->mips_cpu_bus__DOT__control_unit__DOT__funct))) 
                                   | (0x13U == (IData)(vlTOPp->mips_cpu_bus__DOT__control_unit__DOT__funct)));
                            vlTOPp->mips_cpu_bus__DOT__ALU_function_decode 
                                = ((0x20U & (IData)(vlTOPp->mips_cpu_bus__DOT__control_unit__DOT__funct))
                                    ? (IData)(vlTOPp->mips_cpu_bus__DOT__control_unit__DOT__funct)
                                    : ((0x10U & (IData)(vlTOPp->mips_cpu_bus__DOT__control_unit__DOT__funct))
                                        ? ((8U & (IData)(vlTOPp->mips_cpu_bus__DOT__control_unit__DOT__funct))
                                            ? (IData)(vlTOPp->mips_cpu_bus__DOT__control_unit__DOT__funct)
                                            : ((4U 
                                                & (IData)(vlTOPp->mips_cpu_bus__DOT__control_unit__DOT__funct))
                                                ? (IData)(vlTOPp->mips_cpu_bus__DOT__control_unit__DOT__funct)
                                                : (
                                                   (2U 
                                                    & (IData)(vlTOPp->mips_cpu_bus__DOT__control_unit__DOT__funct))
                                                    ? 
                                                   ((1U 
                                                     & (IData)(vlTOPp->mips_cpu_bus__DOT__control_unit__DOT__funct))
                                                     ? 0x3eU
                                                     : 0x3fU)
                                                    : 
                                                   ((1U 
                                                     & (IData)(vlTOPp->mips_cpu_bus__DOT__control_unit__DOT__funct))
                                                     ? 0x3fU
                                                     : 0x3eU))))
                                        : (IData)(vlTOPp->mips_cpu_bus__DOT__control_unit__DOT__funct)));
                            vlTOPp->mips_cpu_bus__DOT__program_counter_multiplexer_jump_decode 
                                = ((8U == (IData)(vlTOPp->mips_cpu_bus__DOT__control_unit__DOT__funct)) 
                                   | (9U == (IData)(vlTOPp->mips_cpu_bus__DOT__control_unit__DOT__funct)));
                            vlTOPp->mips_cpu_bus__DOT__using_HI_LO_decode 
                                = ((0x10U == (IData)(vlTOPp->mips_cpu_bus__DOT__control_unit__DOT__funct)) 
                                   | (0x12U == (IData)(vlTOPp->mips_cpu_bus__DOT__control_unit__DOT__funct)));
                        }
                    }
                }
            }
        }
    }
    vlTOPp->byteenable = vlTOPp->mips_cpu_bus__DOT__byteenable_memory;
    vlTOPp->mips_cpu_bus__DOT__comparator_1 = ((((0U 
                                                  != 
                                                  (0x1fU 
                                                   & (vlTOPp->mips_cpu_bus__DOT__instruction_decode 
                                                      >> 0x15U))) 
                                                 & ((0x1fU 
                                                     & (vlTOPp->mips_cpu_bus__DOT__instruction_decode 
                                                        >> 0x15U)) 
                                                    == (IData)(vlTOPp->mips_cpu_bus__DOT__write_register_memory))) 
                                                & (IData)(vlTOPp->mips_cpu_bus__DOT__register_write_memory))
                                                ? vlTOPp->mips_cpu_bus__DOT__ALU_output_memory
                                                : vlTOPp->mips_cpu_bus__DOT__register_file_output_A_decode);
    vlTOPp->mips_cpu_bus__DOT__comparator_2 = ((((0U 
                                                  != 
                                                  (0x1fU 
                                                   & (vlTOPp->mips_cpu_bus__DOT__instruction_decode 
                                                      >> 0x10U))) 
                                                 & ((0x1fU 
                                                     & (vlTOPp->mips_cpu_bus__DOT__instruction_decode 
                                                        >> 0x10U)) 
                                                    == (IData)(vlTOPp->mips_cpu_bus__DOT__write_register_memory))) 
                                                & (IData)(vlTOPp->mips_cpu_bus__DOT__register_write_memory))
                                                ? vlTOPp->mips_cpu_bus__DOT__ALU_output_memory
                                                : vlTOPp->mips_cpu_bus__DOT__register_file_output_B_decode);
    vlTOPp->mips_cpu_bus__DOT__result_writeback = ((IData)(vlTOPp->mips_cpu_bus__DOT__memory_to_register_writeback)
                                                    ? vlTOPp->mips_cpu_bus__DOT__read_data_writeback_filtered
                                                    : vlTOPp->mips_cpu_bus__DOT__ALU_output_writeback);
    vlTOPp->mips_cpu_bus__DOT__hazard_unit__DOT__lwstall 
        = ((((0x1fU & (vlTOPp->mips_cpu_bus__DOT__instruction_decode 
                       >> 0x15U)) == (IData)(vlTOPp->mips_cpu_bus__DOT__Rt_execute)) 
            | ((0x1fU & (vlTOPp->mips_cpu_bus__DOT__instruction_decode 
                         >> 0x10U)) == (IData)(vlTOPp->mips_cpu_bus__DOT__Rt_execute))) 
           & (IData)(vlTOPp->mips_cpu_bus__DOT__memory_to_register_execute));
    vlTOPp->mips_cpu_bus__DOT__hazard_unit__DOT__branchstall 
        = ((((IData)(vlTOPp->mips_cpu_bus__DOT__branch_decode) 
             & (IData)(vlTOPp->mips_cpu_bus__DOT__register_write_execute)) 
            & (((IData)(vlTOPp->mips_cpu_bus__DOT__write_register_execute) 
                == (0x1fU & (vlTOPp->mips_cpu_bus__DOT__instruction_decode 
                             >> 0x15U))) | ((IData)(vlTOPp->mips_cpu_bus__DOT__write_register_execute) 
                                            == (0x1fU 
                                                & (vlTOPp->mips_cpu_bus__DOT__instruction_decode 
                                                   >> 0x10U))))) 
           | (((IData)(vlTOPp->mips_cpu_bus__DOT__branch_decode) 
               & (IData)(vlTOPp->mips_cpu_bus__DOT__memory_to_register_memory)) 
              & (((IData)(vlTOPp->mips_cpu_bus__DOT__write_register_memory) 
                  == (0x1fU & (vlTOPp->mips_cpu_bus__DOT__instruction_decode 
                               >> 0x15U))) | ((IData)(vlTOPp->mips_cpu_bus__DOT__write_register_memory) 
                                              == (0x1fU 
                                                  & (vlTOPp->mips_cpu_bus__DOT__instruction_decode 
                                                     >> 0x10U))))));
    vlTOPp->mips_cpu_bus__DOT__stall_fetch = (((IData)(vlTOPp->mips_cpu_bus__DOT__hazard_unit__DOT__branchstall) 
                                               | (IData)(vlTOPp->mips_cpu_bus__DOT__hazard_unit__DOT__lwstall)) 
                                              | (IData)(vlTOPp->mips_cpu_bus__DOT__program_counter_multiplexer_jump_execute));
    vlTOPp->mips_cpu_bus__DOT__stall_decode = (((IData)(vlTOPp->mips_cpu_bus__DOT__hazard_unit__DOT__branchstall) 
                                                | (IData)(vlTOPp->mips_cpu_bus__DOT__hazard_unit__DOT__lwstall)) 
                                               | (IData)(vlTOPp->mips_cpu_bus__DOT__program_counter_multiplexer_jump_execute));
    vlTOPp->mips_cpu_bus__DOT__flush_execute_register 
        = ((IData)(vlTOPp->mips_cpu_bus__DOT__hazard_unit__DOT__branchstall) 
           | (IData)(vlTOPp->mips_cpu_bus__DOT__hazard_unit__DOT__lwstall));
    vlTOPp->mips_cpu_bus__DOT__program_counter_src_decode 
        = ((IData)(vlTOPp->mips_cpu_bus__DOT__branch_decode) 
           & ((~ (vlTOPp->mips_cpu_bus__DOT__instruction_decode 
                  >> 0x1fU)) & ((~ (vlTOPp->mips_cpu_bus__DOT__instruction_decode 
                                    >> 0x1eU)) & ((~ 
                                                   (vlTOPp->mips_cpu_bus__DOT__instruction_decode 
                                                    >> 0x1dU)) 
                                                  & ((0x10000000U 
                                                      & vlTOPp->mips_cpu_bus__DOT__instruction_decode)
                                                      ? 
                                                     ((0x8000000U 
                                                       & vlTOPp->mips_cpu_bus__DOT__instruction_decode)
                                                       ? 
                                                      ((0x4000000U 
                                                        & vlTOPp->mips_cpu_bus__DOT__instruction_decode)
                                                        ? 
                                                       VL_LTS_III(1,32,32, 0U, vlTOPp->mips_cpu_bus__DOT__comparator_1)
                                                        : 
                                                       VL_GTES_III(1,32,32, 0U, vlTOPp->mips_cpu_bus__DOT__comparator_1))
                                                       : 
                                                      ((0x4000000U 
                                                        & vlTOPp->mips_cpu_bus__DOT__instruction_decode)
                                                        ? 
                                                       (vlTOPp->mips_cpu_bus__DOT__comparator_1 
                                                        != vlTOPp->mips_cpu_bus__DOT__comparator_2)
                                                        : 
                                                       (vlTOPp->mips_cpu_bus__DOT__comparator_1 
                                                        == vlTOPp->mips_cpu_bus__DOT__comparator_2)))
                                                      : 
                                                     ((~ 
                                                       (vlTOPp->mips_cpu_bus__DOT__instruction_decode 
                                                        >> 0x1bU)) 
                                                      & ((vlTOPp->mips_cpu_bus__DOT__instruction_decode 
                                                          >> 0x1aU) 
                                                         & (((1U 
                                                              == 
                                                              (0x1fU 
                                                               & (vlTOPp->mips_cpu_bus__DOT__instruction_decode 
                                                                  >> 0x10U))) 
                                                             | (0x11U 
                                                                == 
                                                                (0x1fU 
                                                                 & (vlTOPp->mips_cpu_bus__DOT__instruction_decode 
                                                                    >> 0x10U))))
                                                             ? 
                                                            VL_LTES_III(1,32,32, 0U, vlTOPp->mips_cpu_bus__DOT__comparator_1)
                                                             : 
                                                            (((0U 
                                                               == 
                                                               (0x1fU 
                                                                & (vlTOPp->mips_cpu_bus__DOT__instruction_decode 
                                                                   >> 0x10U))) 
                                                              | (0x10U 
                                                                 == 
                                                                 (0x1fU 
                                                                  & (vlTOPp->mips_cpu_bus__DOT__instruction_decode 
                                                                     >> 0x10U)))) 
                                                             & VL_GTS_III(1,32,32, 0U, vlTOPp->mips_cpu_bus__DOT__comparator_1))))))))));
    vlTOPp->register_v0 = ((2U == (IData)(vlTOPp->mips_cpu_bus__DOT__write_register_memory))
                            ? vlTOPp->mips_cpu_bus__DOT__ALU_output_memory
                            : ((2U == (IData)(vlTOPp->mips_cpu_bus__DOT__write_register_writeback))
                                ? vlTOPp->mips_cpu_bus__DOT__result_writeback
                                : vlTOPp->mips_cpu_bus__DOT__register_file__DOT__registers
                               [2U]));
    vlTOPp->mips_cpu_bus__DOT__src_A_ALU_execute = 
        ((4U & (IData)(vlTOPp->mips_cpu_bus__DOT__forward_A_execute))
          ? ((2U & (IData)(vlTOPp->mips_cpu_bus__DOT__forward_A_execute))
              ? 0U : ((1U & (IData)(vlTOPp->mips_cpu_bus__DOT__forward_A_execute))
                       ? 0U : vlTOPp->mips_cpu_bus__DOT__ALU_LO_output_memory))
          : ((2U & (IData)(vlTOPp->mips_cpu_bus__DOT__forward_A_execute))
              ? ((1U & (IData)(vlTOPp->mips_cpu_bus__DOT__forward_A_execute))
                  ? vlTOPp->mips_cpu_bus__DOT__ALU_LO_output_writeback
                  : vlTOPp->mips_cpu_bus__DOT__ALU_output_memory)
              : ((1U & (IData)(vlTOPp->mips_cpu_bus__DOT__forward_A_execute))
                  ? vlTOPp->mips_cpu_bus__DOT__result_writeback
                  : vlTOPp->mips_cpu_bus__DOT__src_A_execute)));
    vlTOPp->mips_cpu_bus__DOT__alu_input_mux__DOT__src_mux_input_0 
        = ((4U & (IData)(vlTOPp->mips_cpu_bus__DOT__forward_B_execute))
            ? ((2U & (IData)(vlTOPp->mips_cpu_bus__DOT__forward_B_execute))
                ? 0U : ((1U & (IData)(vlTOPp->mips_cpu_bus__DOT__forward_B_execute))
                         ? 0U : vlTOPp->mips_cpu_bus__DOT__ALU_HI_output_memory))
            : ((2U & (IData)(vlTOPp->mips_cpu_bus__DOT__forward_B_execute))
                ? ((1U & (IData)(vlTOPp->mips_cpu_bus__DOT__forward_B_execute))
                    ? vlTOPp->mips_cpu_bus__DOT__ALU_HI_output_writeback
                    : vlTOPp->mips_cpu_bus__DOT__ALU_output_memory)
                : ((1U & (IData)(vlTOPp->mips_cpu_bus__DOT__forward_B_execute))
                    ? vlTOPp->mips_cpu_bus__DOT__result_writeback
                    : vlTOPp->mips_cpu_bus__DOT__src_B_execute)));
    vlTOPp->mips_cpu_bus__DOT__src_B_ALU_execute = 
        ((0U == (IData)(vlTOPp->mips_cpu_bus__DOT__ALU_src_B_execute))
          ? vlTOPp->mips_cpu_bus__DOT__alu_input_mux__DOT__src_mux_input_0
          : ((1U == (IData)(vlTOPp->mips_cpu_bus__DOT__ALU_src_B_execute))
              ? vlTOPp->mips_cpu_bus__DOT__sign_imm_execute
              : ((2U == (IData)(vlTOPp->mips_cpu_bus__DOT__ALU_src_B_execute))
                  ? ((IData)(4U) + vlTOPp->mips_cpu_bus__DOT__program_counter_plus_four_execute)
                  : 0U)));
    vlTOPp->mips_cpu_bus__DOT__write_data_execute = vlTOPp->mips_cpu_bus__DOT__alu_input_mux__DOT__src_mux_input_0;
    vlTOPp->mips_cpu_bus__DOT__program_counter_mux_1_out 
        = ((IData)(vlTOPp->mips_cpu_bus__DOT__program_counter_src_decode)
            ? ((vlTOPp->mips_cpu_bus__DOT__sign_imm_decode 
                << 2U) + vlTOPp->mips_cpu_bus__DOT__program_counter_plus_four_decode)
            : ((IData)(4U) + vlTOPp->mips_cpu_bus__DOT__instr_address));
    vlTOPp->mips_cpu_bus__DOT__ALU_output_execute = 0U;
    if ((0x20U & (IData)(vlTOPp->mips_cpu_bus__DOT__ALU_function_execute))) {
        if ((0x10U & (IData)(vlTOPp->mips_cpu_bus__DOT__ALU_function_execute))) {
            if ((8U & (IData)(vlTOPp->mips_cpu_bus__DOT__ALU_function_execute))) {
                if ((4U & (IData)(vlTOPp->mips_cpu_bus__DOT__ALU_function_execute))) {
                    if ((2U & (IData)(vlTOPp->mips_cpu_bus__DOT__ALU_function_execute))) {
                        vlTOPp->mips_cpu_bus__DOT__ALU_output_execute 
                            = ((1U & (IData)(vlTOPp->mips_cpu_bus__DOT__ALU_function_execute))
                                ? vlTOPp->mips_cpu_bus__DOT__src_B_ALU_execute
                                : vlTOPp->mips_cpu_bus__DOT__src_A_ALU_execute);
                    }
                } else {
                    vlTOPp->mips_cpu_bus__DOT__ALU_output_execute = 0U;
                }
            } else {
                vlTOPp->mips_cpu_bus__DOT__ALU_output_execute = 0U;
            }
        } else {
            vlTOPp->mips_cpu_bus__DOT__ALU_output_execute 
                = ((8U & (IData)(vlTOPp->mips_cpu_bus__DOT__ALU_function_execute))
                    ? ((4U & (IData)(vlTOPp->mips_cpu_bus__DOT__ALU_function_execute))
                        ? 0U : ((2U & (IData)(vlTOPp->mips_cpu_bus__DOT__ALU_function_execute))
                                 ? ((1U & (IData)(vlTOPp->mips_cpu_bus__DOT__ALU_function_execute))
                                     ? ((vlTOPp->mips_cpu_bus__DOT__src_A_ALU_execute 
                                         < vlTOPp->mips_cpu_bus__DOT__src_B_ALU_execute)
                                         ? 1U : 0U)
                                     : (VL_LTS_III(1,32,32, vlTOPp->mips_cpu_bus__DOT__src_A_ALU_execute, vlTOPp->mips_cpu_bus__DOT__src_B_ALU_execute)
                                         ? 1U : 0U))
                                 : 0U)) : ((4U & (IData)(vlTOPp->mips_cpu_bus__DOT__ALU_function_execute))
                                            ? ((2U 
                                                & (IData)(vlTOPp->mips_cpu_bus__DOT__ALU_function_execute))
                                                ? (
                                                   (1U 
                                                    & (IData)(vlTOPp->mips_cpu_bus__DOT__ALU_function_execute))
                                                    ? 
                                                   (~ 
                                                    (vlTOPp->mips_cpu_bus__DOT__src_A_ALU_execute 
                                                     | vlTOPp->mips_cpu_bus__DOT__src_B_ALU_execute))
                                                    : 
                                                   (vlTOPp->mips_cpu_bus__DOT__src_A_ALU_execute 
                                                    ^ ~ vlTOPp->mips_cpu_bus__DOT__src_B_ALU_execute))
                                                : (
                                                   (1U 
                                                    & (IData)(vlTOPp->mips_cpu_bus__DOT__ALU_function_execute))
                                                    ? 
                                                   (vlTOPp->mips_cpu_bus__DOT__src_A_ALU_execute 
                                                    | vlTOPp->mips_cpu_bus__DOT__src_B_ALU_execute)
                                                    : 
                                                   (vlTOPp->mips_cpu_bus__DOT__src_A_ALU_execute 
                                                    & vlTOPp->mips_cpu_bus__DOT__src_B_ALU_execute)))
                                            : ((2U 
                                                & (IData)(vlTOPp->mips_cpu_bus__DOT__ALU_function_execute))
                                                ? (
                                                   (1U 
                                                    & (IData)(vlTOPp->mips_cpu_bus__DOT__ALU_function_execute))
                                                    ? 
                                                   (vlTOPp->mips_cpu_bus__DOT__src_A_ALU_execute 
                                                    - vlTOPp->mips_cpu_bus__DOT__src_B_ALU_execute)
                                                    : 
                                                   (vlTOPp->mips_cpu_bus__DOT__src_A_ALU_execute 
                                                    - vlTOPp->mips_cpu_bus__DOT__src_B_ALU_execute))
                                                : (
                                                   (1U 
                                                    & (IData)(vlTOPp->mips_cpu_bus__DOT__ALU_function_execute))
                                                    ? 
                                                   (vlTOPp->mips_cpu_bus__DOT__src_A_ALU_execute 
                                                    + vlTOPp->mips_cpu_bus__DOT__src_B_ALU_execute)
                                                    : 
                                                   (vlTOPp->mips_cpu_bus__DOT__src_A_ALU_execute 
                                                    + vlTOPp->mips_cpu_bus__DOT__src_B_ALU_execute)))));
        }
    } else {
        if ((0x10U & (IData)(vlTOPp->mips_cpu_bus__DOT__ALU_function_execute))) {
            if ((8U & (IData)(vlTOPp->mips_cpu_bus__DOT__ALU_function_execute))) {
                if ((4U & (IData)(vlTOPp->mips_cpu_bus__DOT__ALU_function_execute))) {
                    vlTOPp->mips_cpu_bus__DOT__ALU_output_execute = 0U;
                }
            } else {
                vlTOPp->mips_cpu_bus__DOT__ALU_output_execute 
                    = ((4U & (IData)(vlTOPp->mips_cpu_bus__DOT__ALU_function_execute))
                        ? 0U : vlTOPp->mips_cpu_bus__DOT__src_B_ALU_execute);
            }
        } else {
            vlTOPp->mips_cpu_bus__DOT__ALU_output_execute 
                = ((8U & (IData)(vlTOPp->mips_cpu_bus__DOT__ALU_function_execute))
                    ? ((4U & (IData)(vlTOPp->mips_cpu_bus__DOT__ALU_function_execute))
                        ? 0U : ((2U & (IData)(vlTOPp->mips_cpu_bus__DOT__ALU_function_execute))
                                 ? 0U : vlTOPp->mips_cpu_bus__DOT__src_B_ALU_execute))
                    : ((4U & (IData)(vlTOPp->mips_cpu_bus__DOT__ALU_function_execute))
                        ? ((2U & (IData)(vlTOPp->mips_cpu_bus__DOT__ALU_function_execute))
                            ? ((1U & (IData)(vlTOPp->mips_cpu_bus__DOT__ALU_function_execute))
                                ? (vlTOPp->mips_cpu_bus__DOT__src_B_ALU_execute 
                                   >> (0x1fU & vlTOPp->mips_cpu_bus__DOT__src_A_ALU_execute))
                                : (vlTOPp->mips_cpu_bus__DOT__src_B_ALU_execute 
                                   >> (0x1fU & vlTOPp->mips_cpu_bus__DOT__src_A_ALU_execute)))
                            : ((1U & (IData)(vlTOPp->mips_cpu_bus__DOT__ALU_function_execute))
                                ? 0U : (vlTOPp->mips_cpu_bus__DOT__src_B_ALU_execute 
                                        << (0x1fU & vlTOPp->mips_cpu_bus__DOT__src_A_ALU_execute))))
                        : ((2U & (IData)(vlTOPp->mips_cpu_bus__DOT__ALU_function_execute))
                            ? ((1U & (IData)(vlTOPp->mips_cpu_bus__DOT__ALU_function_execute))
                                ? (vlTOPp->mips_cpu_bus__DOT__src_B_ALU_execute 
                                   >> (0x1fU & (vlTOPp->mips_cpu_bus__DOT__src_A_ALU_execute 
                                                >> 6U)))
                                : 0U) : ((1U & (IData)(vlTOPp->mips_cpu_bus__DOT__ALU_function_execute))
                                          ? (vlTOPp->mips_cpu_bus__DOT__src_B_ALU_execute 
                                             >> (0x1fU 
                                                 & (vlTOPp->mips_cpu_bus__DOT__src_A_ALU_execute 
                                                    >> 6U)))
                                          : (vlTOPp->mips_cpu_bus__DOT__src_B_ALU_execute 
                                             << (0x1fU 
                                                 & (vlTOPp->mips_cpu_bus__DOT__src_A_ALU_execute 
                                                    >> 6U)))))));
        }
    }
    vlTOPp->mips_cpu_bus__DOT__alu__DOT__ALU_HI_LO_output = VL_ULL(0);
    if ((0x20U & (IData)(vlTOPp->mips_cpu_bus__DOT__ALU_function_execute))) {
        if ((0x10U & (IData)(vlTOPp->mips_cpu_bus__DOT__ALU_function_execute))) {
            if ((8U & (IData)(vlTOPp->mips_cpu_bus__DOT__ALU_function_execute))) {
                if ((4U & (IData)(vlTOPp->mips_cpu_bus__DOT__ALU_function_execute))) {
                    if ((1U & (~ ((IData)(vlTOPp->mips_cpu_bus__DOT__ALU_function_execute) 
                                  >> 1U)))) {
                        vlTOPp->mips_cpu_bus__DOT__alu__DOT__ALU_HI_LO_output 
                            = ((1U & (IData)(vlTOPp->mips_cpu_bus__DOT__ALU_function_execute))
                                ? ((QData)((IData)(vlTOPp->mips_cpu_bus__DOT__src_A_ALU_execute)) 
                                   << 0x20U) : (QData)((IData)(vlTOPp->mips_cpu_bus__DOT__src_A_ALU_execute)));
                    }
                }
            }
        }
    } else {
        if ((0x10U & (IData)(vlTOPp->mips_cpu_bus__DOT__ALU_function_execute))) {
            if ((8U & (IData)(vlTOPp->mips_cpu_bus__DOT__ALU_function_execute))) {
                if ((1U & (~ ((IData)(vlTOPp->mips_cpu_bus__DOT__ALU_function_execute) 
                              >> 2U)))) {
                    if ((2U & (IData)(vlTOPp->mips_cpu_bus__DOT__ALU_function_execute))) {
                        if ((1U & (IData)(vlTOPp->mips_cpu_bus__DOT__ALU_function_execute))) {
                            vlTOPp->mips_cpu_bus__DOT__alu__DOT__ALU_HI_LO_output 
                                = ((QData)((IData)(
                                                   VL_DIV_III(32, vlTOPp->mips_cpu_bus__DOT__src_A_ALU_execute, vlTOPp->mips_cpu_bus__DOT__src_B_ALU_execute))) 
                                   << 0x20U);
                            vlTOPp->mips_cpu_bus__DOT__alu__DOT__ALU_HI_LO_output 
                                = (vlTOPp->mips_cpu_bus__DOT__alu__DOT__ALU_HI_LO_output 
                                   + (QData)((IData)(
                                                     VL_MODDIV_III(32, vlTOPp->mips_cpu_bus__DOT__src_A_ALU_execute, vlTOPp->mips_cpu_bus__DOT__src_B_ALU_execute))));
                        } else {
                            vlTOPp->mips_cpu_bus__DOT__alu__DOT__ALU_HI_LO_output 
                                = ((QData)((IData)(
                                                   VL_DIVS_III(32, vlTOPp->mips_cpu_bus__DOT__src_A_ALU_execute, vlTOPp->mips_cpu_bus__DOT__src_B_ALU_execute))) 
                                   << 0x20U);
                            vlTOPp->mips_cpu_bus__DOT__alu__DOT__ALU_HI_LO_output 
                                = (vlTOPp->mips_cpu_bus__DOT__alu__DOT__ALU_HI_LO_output 
                                   + (QData)((IData)(
                                                     VL_MODDIVS_III(32, vlTOPp->mips_cpu_bus__DOT__src_A_ALU_execute, vlTOPp->mips_cpu_bus__DOT__src_B_ALU_execute))));
                        }
                    } else {
                        vlTOPp->mips_cpu_bus__DOT__alu__DOT__ALU_HI_LO_output 
                            = ((1U & (IData)(vlTOPp->mips_cpu_bus__DOT__ALU_function_execute))
                                ? ((QData)((IData)(vlTOPp->mips_cpu_bus__DOT__src_A_ALU_execute)) 
                                   * (QData)((IData)(vlTOPp->mips_cpu_bus__DOT__src_B_ALU_execute)))
                                : VL_MULS_QQQ(64,64,64, 
                                              (((QData)((IData)(
                                                                VL_NEGATE_I((IData)(
                                                                                (1U 
                                                                                & (vlTOPp->mips_cpu_bus__DOT__src_A_ALU_execute 
                                                                                >> 0x1fU)))))) 
                                                << 0x20U) 
                                               | (QData)((IData)(vlTOPp->mips_cpu_bus__DOT__src_A_ALU_execute))), 
                                              (((QData)((IData)(
                                                                VL_NEGATE_I((IData)(
                                                                                (1U 
                                                                                & (vlTOPp->mips_cpu_bus__DOT__src_B_ALU_execute 
                                                                                >> 0x1fU)))))) 
                                                << 0x20U) 
                                               | (QData)((IData)(vlTOPp->mips_cpu_bus__DOT__src_B_ALU_execute)))));
                    }
                }
            }
        }
    }
    vlTOPp->mips_cpu_bus__DOT__ALU_HI_output_execute 
        = (IData)((vlTOPp->mips_cpu_bus__DOT__alu__DOT__ALU_HI_LO_output 
                   >> 0x20U));
    vlTOPp->mips_cpu_bus__DOT__ALU_LO_output_execute 
        = (IData)(vlTOPp->mips_cpu_bus__DOT__alu__DOT__ALU_HI_LO_output);
}

VL_INLINE_OPT void MIPS_Bus_TB::_sequent__TOP__5(MIPS_Bus_TB__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    MIPS_Bus_TB::_sequent__TOP__5\n"); );
    MIPS_Bus_TB* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if (vlTOPp->mips_cpu_bus__DOT__LO_register_write_writeback) {
        vlTOPp->mips_cpu_bus__DOT__register_file__DOT__LO_reg 
            = vlTOPp->mips_cpu_bus__DOT__ALU_LO_output_writeback;
    }
    if (vlTOPp->mips_cpu_bus__DOT__HI_register_write_writeback) {
        vlTOPp->mips_cpu_bus__DOT__register_file__DOT__HI_reg 
            = vlTOPp->mips_cpu_bus__DOT__ALU_HI_output_writeback;
    }
}

VL_INLINE_OPT void MIPS_Bus_TB::_sequent__TOP__6(MIPS_Bus_TB__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    MIPS_Bus_TB::_sequent__TOP__6\n"); );
    MIPS_Bus_TB* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->mips_cpu_bus__DOT__memory_write_memory 
        = ((~ (IData)(vlTOPp->reset)) & (IData)(vlTOPp->mips_cpu_bus__DOT__memory_write_execute));
    vlTOPp->mips_cpu_bus__DOT__memory_to_register_memory 
        = ((~ (IData)(vlTOPp->reset)) & (IData)(vlTOPp->mips_cpu_bus__DOT__memory_to_register_execute));
    vlTOPp->mips_cpu_bus__DOT__ALU_LO_output_writeback 
        = ((IData)(vlTOPp->reset) ? 0U : vlTOPp->mips_cpu_bus__DOT__ALU_LO_output_memory);
    vlTOPp->mips_cpu_bus__DOT__LO_register_write_writeback 
        = ((~ (IData)(vlTOPp->reset)) & (IData)(vlTOPp->mips_cpu_bus__DOT__LO_register_write_memory));
    vlTOPp->mips_cpu_bus__DOT__ALU_HI_output_writeback 
        = ((IData)(vlTOPp->reset) ? 0U : vlTOPp->mips_cpu_bus__DOT__ALU_HI_output_memory);
    vlTOPp->mips_cpu_bus__DOT__HI_register_write_writeback 
        = ((~ (IData)(vlTOPp->reset)) & (IData)(vlTOPp->mips_cpu_bus__DOT__HI_register_write_memory));
    vlTOPp->mips_cpu_bus__DOT__memory_write_execute 
        = ((~ (IData)(vlTOPp->mips_cpu_bus__DOT__flush_execute_register)) 
           & ((~ (IData)(vlTOPp->reset)) & (IData)(vlTOPp->mips_cpu_bus__DOT__memory_write_decode)));
    vlTOPp->mips_cpu_bus__DOT__memory_to_register_execute 
        = ((~ (IData)(vlTOPp->mips_cpu_bus__DOT__flush_execute_register)) 
           & ((~ (IData)(vlTOPp->reset)) & (IData)(vlTOPp->mips_cpu_bus__DOT__memory_to_register_decode)));
    vlTOPp->mips_cpu_bus__DOT__ALU_LO_output_memory 
        = ((IData)(vlTOPp->reset) ? 0U : vlTOPp->mips_cpu_bus__DOT__ALU_LO_output_execute);
    vlTOPp->mips_cpu_bus__DOT__LO_register_write_memory 
        = ((~ (IData)(vlTOPp->reset)) & (IData)(vlTOPp->mips_cpu_bus__DOT__LO_register_write_execute));
    vlTOPp->mips_cpu_bus__DOT__ALU_HI_output_memory 
        = ((IData)(vlTOPp->reset) ? 0U : vlTOPp->mips_cpu_bus__DOT__ALU_HI_output_execute);
    vlTOPp->mips_cpu_bus__DOT__HI_register_write_memory 
        = ((~ (IData)(vlTOPp->reset)) & (IData)(vlTOPp->mips_cpu_bus__DOT__HI_register_write_execute));
    vlTOPp->mips_cpu_bus__DOT__forward_A_execute = 
        ((((0U != (IData)(vlTOPp->mips_cpu_bus__DOT__Rs_execute)) 
           & ((IData)(vlTOPp->mips_cpu_bus__DOT__Rs_execute) 
              == (IData)(vlTOPp->mips_cpu_bus__DOT__write_register_memory))) 
          & (IData)(vlTOPp->mips_cpu_bus__DOT__register_write_memory))
          ? 2U : (((IData)(vlTOPp->mips_cpu_bus__DOT__using_HI_LO_execute) 
                   & (IData)(vlTOPp->mips_cpu_bus__DOT__LO_register_write_memory))
                   ? 4U : ((((0U != (IData)(vlTOPp->mips_cpu_bus__DOT__Rs_execute)) 
                             & ((IData)(vlTOPp->mips_cpu_bus__DOT__Rs_execute) 
                                == (IData)(vlTOPp->mips_cpu_bus__DOT__write_register_writeback))) 
                            & (IData)(vlTOPp->mips_cpu_bus__DOT__register_write_writeback))
                            ? 1U : (((IData)(vlTOPp->mips_cpu_bus__DOT__using_HI_LO_execute) 
                                     & (IData)(vlTOPp->mips_cpu_bus__DOT__LO_register_write_writeback))
                                     ? 3U : 0U))));
    vlTOPp->mips_cpu_bus__DOT__LO_register_write_execute 
        = ((~ (IData)(vlTOPp->mips_cpu_bus__DOT__flush_execute_register)) 
           & ((~ (IData)(vlTOPp->reset)) & (IData)(vlTOPp->mips_cpu_bus__DOT__LO_register_write_decode)));
    vlTOPp->mips_cpu_bus__DOT__forward_B_execute = 
        ((((0U != (IData)(vlTOPp->mips_cpu_bus__DOT__Rt_execute)) 
           & ((IData)(vlTOPp->mips_cpu_bus__DOT__Rt_execute) 
              == (IData)(vlTOPp->mips_cpu_bus__DOT__write_register_memory))) 
          & (IData)(vlTOPp->mips_cpu_bus__DOT__register_write_memory))
          ? 2U : (((IData)(vlTOPp->mips_cpu_bus__DOT__using_HI_LO_execute) 
                   & (IData)(vlTOPp->mips_cpu_bus__DOT__HI_register_write_memory))
                   ? 4U : ((((0U != (IData)(vlTOPp->mips_cpu_bus__DOT__Rt_execute)) 
                             & ((IData)(vlTOPp->mips_cpu_bus__DOT__Rt_execute) 
                                == (IData)(vlTOPp->mips_cpu_bus__DOT__write_register_writeback))) 
                            & (IData)(vlTOPp->mips_cpu_bus__DOT__register_write_writeback))
                            ? 1U : (((IData)(vlTOPp->mips_cpu_bus__DOT__using_HI_LO_execute) 
                                     & (IData)(vlTOPp->mips_cpu_bus__DOT__HI_register_write_writeback))
                                     ? 3U : 0U))));
    vlTOPp->mips_cpu_bus__DOT__HI_register_write_execute 
        = ((~ (IData)(vlTOPp->mips_cpu_bus__DOT__flush_execute_register)) 
           & ((~ (IData)(vlTOPp->reset)) & (IData)(vlTOPp->mips_cpu_bus__DOT__HI_register_write_decode)));
}

VL_INLINE_OPT void MIPS_Bus_TB::_multiclk__TOP__7(MIPS_Bus_TB__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    MIPS_Bus_TB::_multiclk__TOP__7\n"); );
    MIPS_Bus_TB* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->address = (0xfffffffcU & vlTOPp->address);
    vlTOPp->address = ((3U & vlTOPp->address) | (0xfffffffcU 
                                                 & (((((0U 
                                                        == (IData)(vlTOPp->mips_cpu_bus__DOT__fetch_state)) 
                                                       | (1U 
                                                          == (IData)(vlTOPp->mips_cpu_bus__DOT__fetch_state))) 
                                                      | (3U 
                                                         == (IData)(vlTOPp->mips_cpu_bus__DOT__fetch_state)))
                                                      ? 
                                                     (vlTOPp->mips_cpu_bus__DOT__instr_address 
                                                      >> 2U)
                                                      : 
                                                     (vlTOPp->mips_cpu_bus__DOT__ALU_output_memory 
                                                      >> 2U)) 
                                                    << 2U)));
    vlTOPp->mips_cpu_bus__DOT__byteenable_memory = 
        ((((0U == (IData)(vlTOPp->mips_cpu_bus__DOT__fetch_state)) 
           | (1U == (IData)(vlTOPp->mips_cpu_bus__DOT__fetch_state))) 
          | (3U == (IData)(vlTOPp->mips_cpu_bus__DOT__fetch_state)))
          ? 0xfU : ((0x20U & (IData)(vlTOPp->mips_cpu_bus__DOT__op_memory))
                     ? ((0x10U & (IData)(vlTOPp->mips_cpu_bus__DOT__op_memory))
                         ? 0xfU : ((8U & (IData)(vlTOPp->mips_cpu_bus__DOT__op_memory))
                                    ? ((4U & (IData)(vlTOPp->mips_cpu_bus__DOT__op_memory))
                                        ? 0xfU : ((2U 
                                                   & (IData)(vlTOPp->mips_cpu_bus__DOT__op_memory))
                                                   ? 0xfU
                                                   : 
                                                  ((1U 
                                                    & (IData)(vlTOPp->mips_cpu_bus__DOT__op_memory))
                                                    ? 
                                                   ((0U 
                                                     == 
                                                     (3U 
                                                      & vlTOPp->mips_cpu_bus__DOT__ALU_output_memory))
                                                     ? 3U
                                                     : 
                                                    ((2U 
                                                      == 
                                                      (3U 
                                                       & vlTOPp->mips_cpu_bus__DOT__ALU_output_memory))
                                                      ? 0xcU
                                                      : 0xfU))
                                                    : 
                                                   ((2U 
                                                     & vlTOPp->mips_cpu_bus__DOT__ALU_output_memory)
                                                     ? 
                                                    ((1U 
                                                      & vlTOPp->mips_cpu_bus__DOT__ALU_output_memory)
                                                      ? 8U
                                                      : 4U)
                                                     : 
                                                    ((1U 
                                                      & vlTOPp->mips_cpu_bus__DOT__ALU_output_memory)
                                                      ? 2U
                                                      : 1U)))))
                                    : ((4U & (IData)(vlTOPp->mips_cpu_bus__DOT__op_memory))
                                        ? ((2U & (IData)(vlTOPp->mips_cpu_bus__DOT__op_memory))
                                            ? ((1U 
                                                & (IData)(vlTOPp->mips_cpu_bus__DOT__op_memory))
                                                ? 0xfU
                                                : (
                                                   (2U 
                                                    & vlTOPp->mips_cpu_bus__DOT__ALU_output_memory)
                                                    ? 
                                                   ((1U 
                                                     & vlTOPp->mips_cpu_bus__DOT__ALU_output_memory)
                                                     ? 8U
                                                     : 0xcU)
                                                    : 
                                                   ((1U 
                                                     & vlTOPp->mips_cpu_bus__DOT__ALU_output_memory)
                                                     ? 0xeU
                                                     : 0xfU)))
                                            : ((1U 
                                                & (IData)(vlTOPp->mips_cpu_bus__DOT__op_memory))
                                                ? (
                                                   (0U 
                                                    == 
                                                    (3U 
                                                     & vlTOPp->mips_cpu_bus__DOT__ALU_output_memory))
                                                    ? 3U
                                                    : 
                                                   ((2U 
                                                     == 
                                                     (3U 
                                                      & vlTOPp->mips_cpu_bus__DOT__ALU_output_memory))
                                                     ? 0xcU
                                                     : 0xfU))
                                                : (
                                                   (2U 
                                                    & vlTOPp->mips_cpu_bus__DOT__ALU_output_memory)
                                                    ? 
                                                   ((1U 
                                                     & vlTOPp->mips_cpu_bus__DOT__ALU_output_memory)
                                                     ? 8U
                                                     : 4U)
                                                    : 
                                                   ((1U 
                                                     & vlTOPp->mips_cpu_bus__DOT__ALU_output_memory)
                                                     ? 2U
                                                     : 1U))))
                                        : ((2U & (IData)(vlTOPp->mips_cpu_bus__DOT__op_memory))
                                            ? ((1U 
                                                & (IData)(vlTOPp->mips_cpu_bus__DOT__op_memory))
                                                ? 0xfU
                                                : (
                                                   (2U 
                                                    & vlTOPp->mips_cpu_bus__DOT__ALU_output_memory)
                                                    ? 
                                                   ((1U 
                                                     & vlTOPp->mips_cpu_bus__DOT__ALU_output_memory)
                                                     ? 0xfU
                                                     : 7U)
                                                    : 
                                                   ((1U 
                                                     & vlTOPp->mips_cpu_bus__DOT__ALU_output_memory)
                                                     ? 3U
                                                     : 1U)))
                                            : ((1U 
                                                & (IData)(vlTOPp->mips_cpu_bus__DOT__op_memory))
                                                ? (
                                                   (0U 
                                                    == 
                                                    (3U 
                                                     & vlTOPp->mips_cpu_bus__DOT__ALU_output_memory))
                                                    ? 3U
                                                    : 
                                                   ((2U 
                                                     == 
                                                     (3U 
                                                      & vlTOPp->mips_cpu_bus__DOT__ALU_output_memory))
                                                     ? 0xcU
                                                     : 0xfU))
                                                : (
                                                   (2U 
                                                    & vlTOPp->mips_cpu_bus__DOT__ALU_output_memory)
                                                    ? 
                                                   ((1U 
                                                     & vlTOPp->mips_cpu_bus__DOT__ALU_output_memory)
                                                     ? 8U
                                                     : 4U)
                                                    : 
                                                   ((1U 
                                                     & vlTOPp->mips_cpu_bus__DOT__ALU_output_memory)
                                                     ? 2U
                                                     : 1U)))))))
                     : 0xfU));
    vlTOPp->byteenable = vlTOPp->mips_cpu_bus__DOT__byteenable_memory;
}

VL_INLINE_OPT void MIPS_Bus_TB::_combo__TOP__8(MIPS_Bus_TB__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    MIPS_Bus_TB::_combo__TOP__8\n"); );
    MIPS_Bus_TB* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if (vlTOPp->reset) {
        vlTOPp->mips_cpu_bus__DOT__read_data_writeback_filtered = 0U;
    } else {
        if ((0x20U & (IData)(vlTOPp->mips_cpu_bus__DOT__op_writeback))) {
            if ((0x10U & (IData)(vlTOPp->mips_cpu_bus__DOT__op_writeback))) {
                vlTOPp->mips_cpu_bus__DOT__memory_filter__DOT__temp_filtered 
                    = vlTOPp->mips_cpu_bus__DOT__read_data_writeback;
            } else {
                if ((8U & (IData)(vlTOPp->mips_cpu_bus__DOT__op_writeback))) {
                    vlTOPp->mips_cpu_bus__DOT__memory_filter__DOT__temp_filtered 
                        = vlTOPp->mips_cpu_bus__DOT__read_data_writeback;
                } else {
                    if ((4U & (IData)(vlTOPp->mips_cpu_bus__DOT__op_writeback))) {
                        if ((2U & (IData)(vlTOPp->mips_cpu_bus__DOT__op_writeback))) {
                            vlTOPp->mips_cpu_bus__DOT__memory_filter__DOT__temp_filtered 
                                = ((1U & (IData)(vlTOPp->mips_cpu_bus__DOT__op_writeback))
                                    ? vlTOPp->mips_cpu_bus__DOT__read_data_writeback
                                    : ((8U & (IData)(vlTOPp->mips_cpu_bus__DOT__byteenable_writeback))
                                        ? ((4U & (IData)(vlTOPp->mips_cpu_bus__DOT__byteenable_writeback))
                                            ? ((2U 
                                                & (IData)(vlTOPp->mips_cpu_bus__DOT__byteenable_writeback))
                                                ? (
                                                   (1U 
                                                    & (IData)(vlTOPp->mips_cpu_bus__DOT__byteenable_writeback))
                                                    ? vlTOPp->mips_cpu_bus__DOT__read_data_writeback
                                                    : 
                                                   ((0xff000000U 
                                                     & vlTOPp->mips_cpu_bus__DOT__src_A_ALU_writeback) 
                                                    | (0xffffffU 
                                                       & (vlTOPp->mips_cpu_bus__DOT__read_data_writeback 
                                                          >> 8U))))
                                                : (
                                                   (1U 
                                                    & (IData)(vlTOPp->mips_cpu_bus__DOT__byteenable_writeback))
                                                    ? vlTOPp->mips_cpu_bus__DOT__read_data_writeback
                                                    : 
                                                   ((0xffff0000U 
                                                     & vlTOPp->mips_cpu_bus__DOT__src_A_ALU_writeback) 
                                                    | (0xffffU 
                                                       & (vlTOPp->mips_cpu_bus__DOT__read_data_writeback 
                                                          >> 0x10U)))))
                                            : ((2U 
                                                & (IData)(vlTOPp->mips_cpu_bus__DOT__byteenable_writeback))
                                                ? vlTOPp->mips_cpu_bus__DOT__read_data_writeback
                                                : (
                                                   (1U 
                                                    & (IData)(vlTOPp->mips_cpu_bus__DOT__byteenable_writeback))
                                                    ? vlTOPp->mips_cpu_bus__DOT__read_data_writeback
                                                    : 
                                                   ((0xffffff00U 
                                                     & vlTOPp->mips_cpu_bus__DOT__src_A_ALU_writeback) 
                                                    | (0xffU 
                                                       & (vlTOPp->mips_cpu_bus__DOT__read_data_writeback 
                                                          >> 0x18U))))))
                                        : vlTOPp->mips_cpu_bus__DOT__read_data_writeback));
                        } else {
                            if ((1U & (IData)(vlTOPp->mips_cpu_bus__DOT__op_writeback))) {
                                vlTOPp->mips_cpu_bus__DOT__memory_filter__DOT__temp_filtered 
                                    = (0xffffU & vlTOPp->mips_cpu_bus__DOT__read_data_writeback);
                            } else {
                                vlTOPp->mips_cpu_bus__DOT__memory_filter__DOT__temp_filtered 
                                    = ((8U & (IData)(vlTOPp->mips_cpu_bus__DOT__byteenable_writeback))
                                        ? ((4U & (IData)(vlTOPp->mips_cpu_bus__DOT__byteenable_writeback))
                                            ? vlTOPp->mips_cpu_bus__DOT__read_data_writeback
                                            : ((2U 
                                                & (IData)(vlTOPp->mips_cpu_bus__DOT__byteenable_writeback))
                                                ? vlTOPp->mips_cpu_bus__DOT__read_data_writeback
                                                : (
                                                   (1U 
                                                    & (IData)(vlTOPp->mips_cpu_bus__DOT__byteenable_writeback))
                                                    ? vlTOPp->mips_cpu_bus__DOT__read_data_writeback
                                                    : 
                                                   (vlTOPp->mips_cpu_bus__DOT__read_data_writeback 
                                                    >> 0x18U))))
                                        : ((4U & (IData)(vlTOPp->mips_cpu_bus__DOT__byteenable_writeback))
                                            ? ((2U 
                                                & (IData)(vlTOPp->mips_cpu_bus__DOT__byteenable_writeback))
                                                ? vlTOPp->mips_cpu_bus__DOT__read_data_writeback
                                                : (
                                                   (1U 
                                                    & (IData)(vlTOPp->mips_cpu_bus__DOT__byteenable_writeback))
                                                    ? vlTOPp->mips_cpu_bus__DOT__read_data_writeback
                                                    : 
                                                   (vlTOPp->mips_cpu_bus__DOT__read_data_writeback 
                                                    >> 0x10U)))
                                            : ((2U 
                                                & (IData)(vlTOPp->mips_cpu_bus__DOT__byteenable_writeback))
                                                ? (
                                                   (1U 
                                                    & (IData)(vlTOPp->mips_cpu_bus__DOT__byteenable_writeback))
                                                    ? vlTOPp->mips_cpu_bus__DOT__read_data_writeback
                                                    : 
                                                   (vlTOPp->mips_cpu_bus__DOT__read_data_writeback 
                                                    >> 8U))
                                                : vlTOPp->mips_cpu_bus__DOT__read_data_writeback)));
                                vlTOPp->mips_cpu_bus__DOT__memory_filter__DOT__temp_filtered 
                                    = (0xffU & vlTOPp->mips_cpu_bus__DOT__memory_filter__DOT__temp_filtered);
                            }
                        }
                    } else {
                        if ((2U & (IData)(vlTOPp->mips_cpu_bus__DOT__op_writeback))) {
                            vlTOPp->mips_cpu_bus__DOT__memory_filter__DOT__temp_filtered 
                                = ((1U & (IData)(vlTOPp->mips_cpu_bus__DOT__op_writeback))
                                    ? vlTOPp->mips_cpu_bus__DOT__read_data_writeback
                                    : ((8U & (IData)(vlTOPp->mips_cpu_bus__DOT__byteenable_writeback))
                                        ? vlTOPp->mips_cpu_bus__DOT__read_data_writeback
                                        : ((4U & (IData)(vlTOPp->mips_cpu_bus__DOT__byteenable_writeback))
                                            ? ((2U 
                                                & (IData)(vlTOPp->mips_cpu_bus__DOT__byteenable_writeback))
                                                ? (
                                                   (1U 
                                                    & (IData)(vlTOPp->mips_cpu_bus__DOT__byteenable_writeback))
                                                    ? 
                                                   ((0xffffff00U 
                                                     & (vlTOPp->mips_cpu_bus__DOT__read_data_writeback 
                                                        << 8U)) 
                                                    | (0xffU 
                                                       & vlTOPp->mips_cpu_bus__DOT__src_A_ALU_writeback))
                                                    : vlTOPp->mips_cpu_bus__DOT__read_data_writeback)
                                                : vlTOPp->mips_cpu_bus__DOT__read_data_writeback)
                                            : ((2U 
                                                & (IData)(vlTOPp->mips_cpu_bus__DOT__byteenable_writeback))
                                                ? (
                                                   (1U 
                                                    & (IData)(vlTOPp->mips_cpu_bus__DOT__byteenable_writeback))
                                                    ? 
                                                   ((0xffff0000U 
                                                     & (vlTOPp->mips_cpu_bus__DOT__read_data_writeback 
                                                        << 0x10U)) 
                                                    | (0xffffU 
                                                       & vlTOPp->mips_cpu_bus__DOT__src_A_ALU_writeback))
                                                    : vlTOPp->mips_cpu_bus__DOT__read_data_writeback)
                                                : (
                                                   (1U 
                                                    & (IData)(vlTOPp->mips_cpu_bus__DOT__byteenable_writeback))
                                                    ? 
                                                   ((0xff000000U 
                                                     & (vlTOPp->mips_cpu_bus__DOT__read_data_writeback 
                                                        << 0x18U)) 
                                                    | (0xffffffU 
                                                       & vlTOPp->mips_cpu_bus__DOT__src_A_ALU_writeback))
                                                    : vlTOPp->mips_cpu_bus__DOT__read_data_writeback)))));
                        } else {
                            if ((1U & (IData)(vlTOPp->mips_cpu_bus__DOT__op_writeback))) {
                                vlTOPp->mips_cpu_bus__DOT__memory_filter__DOT__temp_filtered 
                                    = ((0xffff0000U 
                                        & (VL_NEGATE_I((IData)(
                                                               (1U 
                                                                & (vlTOPp->mips_cpu_bus__DOT__read_data_writeback 
                                                                   >> 0xfU)))) 
                                           << 0x10U)) 
                                       | (0xffffU & vlTOPp->mips_cpu_bus__DOT__read_data_writeback));
                            } else {
                                vlTOPp->mips_cpu_bus__DOT__memory_filter__DOT__temp_filtered 
                                    = ((8U & (IData)(vlTOPp->mips_cpu_bus__DOT__byteenable_writeback))
                                        ? ((4U & (IData)(vlTOPp->mips_cpu_bus__DOT__byteenable_writeback))
                                            ? vlTOPp->mips_cpu_bus__DOT__read_data_writeback
                                            : ((2U 
                                                & (IData)(vlTOPp->mips_cpu_bus__DOT__byteenable_writeback))
                                                ? vlTOPp->mips_cpu_bus__DOT__read_data_writeback
                                                : (
                                                   (1U 
                                                    & (IData)(vlTOPp->mips_cpu_bus__DOT__byteenable_writeback))
                                                    ? vlTOPp->mips_cpu_bus__DOT__read_data_writeback
                                                    : 
                                                   (vlTOPp->mips_cpu_bus__DOT__read_data_writeback 
                                                    >> 0x18U))))
                                        : ((4U & (IData)(vlTOPp->mips_cpu_bus__DOT__byteenable_writeback))
                                            ? ((2U 
                                                & (IData)(vlTOPp->mips_cpu_bus__DOT__byteenable_writeback))
                                                ? vlTOPp->mips_cpu_bus__DOT__read_data_writeback
                                                : (
                                                   (1U 
                                                    & (IData)(vlTOPp->mips_cpu_bus__DOT__byteenable_writeback))
                                                    ? vlTOPp->mips_cpu_bus__DOT__read_data_writeback
                                                    : 
                                                   (vlTOPp->mips_cpu_bus__DOT__read_data_writeback 
                                                    >> 0x10U)))
                                            : ((2U 
                                                & (IData)(vlTOPp->mips_cpu_bus__DOT__byteenable_writeback))
                                                ? (
                                                   (1U 
                                                    & (IData)(vlTOPp->mips_cpu_bus__DOT__byteenable_writeback))
                                                    ? vlTOPp->mips_cpu_bus__DOT__read_data_writeback
                                                    : 
                                                   (vlTOPp->mips_cpu_bus__DOT__read_data_writeback 
                                                    >> 8U))
                                                : vlTOPp->mips_cpu_bus__DOT__read_data_writeback)));
                                vlTOPp->mips_cpu_bus__DOT__memory_filter__DOT__temp_filtered 
                                    = ((0xffffff00U 
                                        & (VL_NEGATE_I((IData)(
                                                               (1U 
                                                                & (vlTOPp->mips_cpu_bus__DOT__memory_filter__DOT__temp_filtered 
                                                                   >> 7U)))) 
                                           << 8U)) 
                                       | (0xffU & vlTOPp->mips_cpu_bus__DOT__memory_filter__DOT__temp_filtered));
                            }
                        }
                    }
                }
            }
        } else {
            vlTOPp->mips_cpu_bus__DOT__memory_filter__DOT__temp_filtered 
                = vlTOPp->mips_cpu_bus__DOT__read_data_writeback;
        }
        vlTOPp->mips_cpu_bus__DOT__read_data_writeback_filtered 
            = vlTOPp->mips_cpu_bus__DOT__memory_filter__DOT__temp_filtered;
    }
    vlTOPp->mips_cpu_bus__DOT__result_writeback = ((IData)(vlTOPp->mips_cpu_bus__DOT__memory_to_register_writeback)
                                                    ? vlTOPp->mips_cpu_bus__DOT__read_data_writeback_filtered
                                                    : vlTOPp->mips_cpu_bus__DOT__ALU_output_writeback);
    vlTOPp->register_v0 = ((2U == (IData)(vlTOPp->mips_cpu_bus__DOT__write_register_memory))
                            ? vlTOPp->mips_cpu_bus__DOT__ALU_output_memory
                            : ((2U == (IData)(vlTOPp->mips_cpu_bus__DOT__write_register_writeback))
                                ? vlTOPp->mips_cpu_bus__DOT__result_writeback
                                : vlTOPp->mips_cpu_bus__DOT__register_file__DOT__registers
                               [2U]));
    vlTOPp->mips_cpu_bus__DOT__src_A_ALU_execute = 
        ((4U & (IData)(vlTOPp->mips_cpu_bus__DOT__forward_A_execute))
          ? ((2U & (IData)(vlTOPp->mips_cpu_bus__DOT__forward_A_execute))
              ? 0U : ((1U & (IData)(vlTOPp->mips_cpu_bus__DOT__forward_A_execute))
                       ? 0U : vlTOPp->mips_cpu_bus__DOT__ALU_LO_output_memory))
          : ((2U & (IData)(vlTOPp->mips_cpu_bus__DOT__forward_A_execute))
              ? ((1U & (IData)(vlTOPp->mips_cpu_bus__DOT__forward_A_execute))
                  ? vlTOPp->mips_cpu_bus__DOT__ALU_LO_output_writeback
                  : vlTOPp->mips_cpu_bus__DOT__ALU_output_memory)
              : ((1U & (IData)(vlTOPp->mips_cpu_bus__DOT__forward_A_execute))
                  ? vlTOPp->mips_cpu_bus__DOT__result_writeback
                  : vlTOPp->mips_cpu_bus__DOT__src_A_execute)));
    vlTOPp->mips_cpu_bus__DOT__alu_input_mux__DOT__src_mux_input_0 
        = ((4U & (IData)(vlTOPp->mips_cpu_bus__DOT__forward_B_execute))
            ? ((2U & (IData)(vlTOPp->mips_cpu_bus__DOT__forward_B_execute))
                ? 0U : ((1U & (IData)(vlTOPp->mips_cpu_bus__DOT__forward_B_execute))
                         ? 0U : vlTOPp->mips_cpu_bus__DOT__ALU_HI_output_memory))
            : ((2U & (IData)(vlTOPp->mips_cpu_bus__DOT__forward_B_execute))
                ? ((1U & (IData)(vlTOPp->mips_cpu_bus__DOT__forward_B_execute))
                    ? vlTOPp->mips_cpu_bus__DOT__ALU_HI_output_writeback
                    : vlTOPp->mips_cpu_bus__DOT__ALU_output_memory)
                : ((1U & (IData)(vlTOPp->mips_cpu_bus__DOT__forward_B_execute))
                    ? vlTOPp->mips_cpu_bus__DOT__result_writeback
                    : vlTOPp->mips_cpu_bus__DOT__src_B_execute)));
    vlTOPp->mips_cpu_bus__DOT__src_B_ALU_execute = 
        ((0U == (IData)(vlTOPp->mips_cpu_bus__DOT__ALU_src_B_execute))
          ? vlTOPp->mips_cpu_bus__DOT__alu_input_mux__DOT__src_mux_input_0
          : ((1U == (IData)(vlTOPp->mips_cpu_bus__DOT__ALU_src_B_execute))
              ? vlTOPp->mips_cpu_bus__DOT__sign_imm_execute
              : ((2U == (IData)(vlTOPp->mips_cpu_bus__DOT__ALU_src_B_execute))
                  ? ((IData)(4U) + vlTOPp->mips_cpu_bus__DOT__program_counter_plus_four_execute)
                  : 0U)));
    vlTOPp->mips_cpu_bus__DOT__write_data_execute = vlTOPp->mips_cpu_bus__DOT__alu_input_mux__DOT__src_mux_input_0;
    vlTOPp->mips_cpu_bus__DOT__ALU_output_execute = 0U;
    if ((0x20U & (IData)(vlTOPp->mips_cpu_bus__DOT__ALU_function_execute))) {
        if ((0x10U & (IData)(vlTOPp->mips_cpu_bus__DOT__ALU_function_execute))) {
            if ((8U & (IData)(vlTOPp->mips_cpu_bus__DOT__ALU_function_execute))) {
                if ((4U & (IData)(vlTOPp->mips_cpu_bus__DOT__ALU_function_execute))) {
                    if ((2U & (IData)(vlTOPp->mips_cpu_bus__DOT__ALU_function_execute))) {
                        vlTOPp->mips_cpu_bus__DOT__ALU_output_execute 
                            = ((1U & (IData)(vlTOPp->mips_cpu_bus__DOT__ALU_function_execute))
                                ? vlTOPp->mips_cpu_bus__DOT__src_B_ALU_execute
                                : vlTOPp->mips_cpu_bus__DOT__src_A_ALU_execute);
                    }
                } else {
                    vlTOPp->mips_cpu_bus__DOT__ALU_output_execute = 0U;
                }
            } else {
                vlTOPp->mips_cpu_bus__DOT__ALU_output_execute = 0U;
            }
        } else {
            vlTOPp->mips_cpu_bus__DOT__ALU_output_execute 
                = ((8U & (IData)(vlTOPp->mips_cpu_bus__DOT__ALU_function_execute))
                    ? ((4U & (IData)(vlTOPp->mips_cpu_bus__DOT__ALU_function_execute))
                        ? 0U : ((2U & (IData)(vlTOPp->mips_cpu_bus__DOT__ALU_function_execute))
                                 ? ((1U & (IData)(vlTOPp->mips_cpu_bus__DOT__ALU_function_execute))
                                     ? ((vlTOPp->mips_cpu_bus__DOT__src_A_ALU_execute 
                                         < vlTOPp->mips_cpu_bus__DOT__src_B_ALU_execute)
                                         ? 1U : 0U)
                                     : (VL_LTS_III(1,32,32, vlTOPp->mips_cpu_bus__DOT__src_A_ALU_execute, vlTOPp->mips_cpu_bus__DOT__src_B_ALU_execute)
                                         ? 1U : 0U))
                                 : 0U)) : ((4U & (IData)(vlTOPp->mips_cpu_bus__DOT__ALU_function_execute))
                                            ? ((2U 
                                                & (IData)(vlTOPp->mips_cpu_bus__DOT__ALU_function_execute))
                                                ? (
                                                   (1U 
                                                    & (IData)(vlTOPp->mips_cpu_bus__DOT__ALU_function_execute))
                                                    ? 
                                                   (~ 
                                                    (vlTOPp->mips_cpu_bus__DOT__src_A_ALU_execute 
                                                     | vlTOPp->mips_cpu_bus__DOT__src_B_ALU_execute))
                                                    : 
                                                   (vlTOPp->mips_cpu_bus__DOT__src_A_ALU_execute 
                                                    ^ ~ vlTOPp->mips_cpu_bus__DOT__src_B_ALU_execute))
                                                : (
                                                   (1U 
                                                    & (IData)(vlTOPp->mips_cpu_bus__DOT__ALU_function_execute))
                                                    ? 
                                                   (vlTOPp->mips_cpu_bus__DOT__src_A_ALU_execute 
                                                    | vlTOPp->mips_cpu_bus__DOT__src_B_ALU_execute)
                                                    : 
                                                   (vlTOPp->mips_cpu_bus__DOT__src_A_ALU_execute 
                                                    & vlTOPp->mips_cpu_bus__DOT__src_B_ALU_execute)))
                                            : ((2U 
                                                & (IData)(vlTOPp->mips_cpu_bus__DOT__ALU_function_execute))
                                                ? (
                                                   (1U 
                                                    & (IData)(vlTOPp->mips_cpu_bus__DOT__ALU_function_execute))
                                                    ? 
                                                   (vlTOPp->mips_cpu_bus__DOT__src_A_ALU_execute 
                                                    - vlTOPp->mips_cpu_bus__DOT__src_B_ALU_execute)
                                                    : 
                                                   (vlTOPp->mips_cpu_bus__DOT__src_A_ALU_execute 
                                                    - vlTOPp->mips_cpu_bus__DOT__src_B_ALU_execute))
                                                : (
                                                   (1U 
                                                    & (IData)(vlTOPp->mips_cpu_bus__DOT__ALU_function_execute))
                                                    ? 
                                                   (vlTOPp->mips_cpu_bus__DOT__src_A_ALU_execute 
                                                    + vlTOPp->mips_cpu_bus__DOT__src_B_ALU_execute)
                                                    : 
                                                   (vlTOPp->mips_cpu_bus__DOT__src_A_ALU_execute 
                                                    + vlTOPp->mips_cpu_bus__DOT__src_B_ALU_execute)))));
        }
    } else {
        if ((0x10U & (IData)(vlTOPp->mips_cpu_bus__DOT__ALU_function_execute))) {
            if ((8U & (IData)(vlTOPp->mips_cpu_bus__DOT__ALU_function_execute))) {
                if ((4U & (IData)(vlTOPp->mips_cpu_bus__DOT__ALU_function_execute))) {
                    vlTOPp->mips_cpu_bus__DOT__ALU_output_execute = 0U;
                }
            } else {
                vlTOPp->mips_cpu_bus__DOT__ALU_output_execute 
                    = ((4U & (IData)(vlTOPp->mips_cpu_bus__DOT__ALU_function_execute))
                        ? 0U : vlTOPp->mips_cpu_bus__DOT__src_B_ALU_execute);
            }
        } else {
            vlTOPp->mips_cpu_bus__DOT__ALU_output_execute 
                = ((8U & (IData)(vlTOPp->mips_cpu_bus__DOT__ALU_function_execute))
                    ? ((4U & (IData)(vlTOPp->mips_cpu_bus__DOT__ALU_function_execute))
                        ? 0U : ((2U & (IData)(vlTOPp->mips_cpu_bus__DOT__ALU_function_execute))
                                 ? 0U : vlTOPp->mips_cpu_bus__DOT__src_B_ALU_execute))
                    : ((4U & (IData)(vlTOPp->mips_cpu_bus__DOT__ALU_function_execute))
                        ? ((2U & (IData)(vlTOPp->mips_cpu_bus__DOT__ALU_function_execute))
                            ? ((1U & (IData)(vlTOPp->mips_cpu_bus__DOT__ALU_function_execute))
                                ? (vlTOPp->mips_cpu_bus__DOT__src_B_ALU_execute 
                                   >> (0x1fU & vlTOPp->mips_cpu_bus__DOT__src_A_ALU_execute))
                                : (vlTOPp->mips_cpu_bus__DOT__src_B_ALU_execute 
                                   >> (0x1fU & vlTOPp->mips_cpu_bus__DOT__src_A_ALU_execute)))
                            : ((1U & (IData)(vlTOPp->mips_cpu_bus__DOT__ALU_function_execute))
                                ? 0U : (vlTOPp->mips_cpu_bus__DOT__src_B_ALU_execute 
                                        << (0x1fU & vlTOPp->mips_cpu_bus__DOT__src_A_ALU_execute))))
                        : ((2U & (IData)(vlTOPp->mips_cpu_bus__DOT__ALU_function_execute))
                            ? ((1U & (IData)(vlTOPp->mips_cpu_bus__DOT__ALU_function_execute))
                                ? (vlTOPp->mips_cpu_bus__DOT__src_B_ALU_execute 
                                   >> (0x1fU & (vlTOPp->mips_cpu_bus__DOT__src_A_ALU_execute 
                                                >> 6U)))
                                : 0U) : ((1U & (IData)(vlTOPp->mips_cpu_bus__DOT__ALU_function_execute))
                                          ? (vlTOPp->mips_cpu_bus__DOT__src_B_ALU_execute 
                                             >> (0x1fU 
                                                 & (vlTOPp->mips_cpu_bus__DOT__src_A_ALU_execute 
                                                    >> 6U)))
                                          : (vlTOPp->mips_cpu_bus__DOT__src_B_ALU_execute 
                                             << (0x1fU 
                                                 & (vlTOPp->mips_cpu_bus__DOT__src_A_ALU_execute 
                                                    >> 6U)))))));
        }
    }
    vlTOPp->mips_cpu_bus__DOT__alu__DOT__ALU_HI_LO_output = VL_ULL(0);
    if ((0x20U & (IData)(vlTOPp->mips_cpu_bus__DOT__ALU_function_execute))) {
        if ((0x10U & (IData)(vlTOPp->mips_cpu_bus__DOT__ALU_function_execute))) {
            if ((8U & (IData)(vlTOPp->mips_cpu_bus__DOT__ALU_function_execute))) {
                if ((4U & (IData)(vlTOPp->mips_cpu_bus__DOT__ALU_function_execute))) {
                    if ((1U & (~ ((IData)(vlTOPp->mips_cpu_bus__DOT__ALU_function_execute) 
                                  >> 1U)))) {
                        vlTOPp->mips_cpu_bus__DOT__alu__DOT__ALU_HI_LO_output 
                            = ((1U & (IData)(vlTOPp->mips_cpu_bus__DOT__ALU_function_execute))
                                ? ((QData)((IData)(vlTOPp->mips_cpu_bus__DOT__src_A_ALU_execute)) 
                                   << 0x20U) : (QData)((IData)(vlTOPp->mips_cpu_bus__DOT__src_A_ALU_execute)));
                    }
                }
            }
        }
    } else {
        if ((0x10U & (IData)(vlTOPp->mips_cpu_bus__DOT__ALU_function_execute))) {
            if ((8U & (IData)(vlTOPp->mips_cpu_bus__DOT__ALU_function_execute))) {
                if ((1U & (~ ((IData)(vlTOPp->mips_cpu_bus__DOT__ALU_function_execute) 
                              >> 2U)))) {
                    if ((2U & (IData)(vlTOPp->mips_cpu_bus__DOT__ALU_function_execute))) {
                        if ((1U & (IData)(vlTOPp->mips_cpu_bus__DOT__ALU_function_execute))) {
                            vlTOPp->mips_cpu_bus__DOT__alu__DOT__ALU_HI_LO_output 
                                = ((QData)((IData)(
                                                   VL_DIV_III(32, vlTOPp->mips_cpu_bus__DOT__src_A_ALU_execute, vlTOPp->mips_cpu_bus__DOT__src_B_ALU_execute))) 
                                   << 0x20U);
                            vlTOPp->mips_cpu_bus__DOT__alu__DOT__ALU_HI_LO_output 
                                = (vlTOPp->mips_cpu_bus__DOT__alu__DOT__ALU_HI_LO_output 
                                   + (QData)((IData)(
                                                     VL_MODDIV_III(32, vlTOPp->mips_cpu_bus__DOT__src_A_ALU_execute, vlTOPp->mips_cpu_bus__DOT__src_B_ALU_execute))));
                        } else {
                            vlTOPp->mips_cpu_bus__DOT__alu__DOT__ALU_HI_LO_output 
                                = ((QData)((IData)(
                                                   VL_DIVS_III(32, vlTOPp->mips_cpu_bus__DOT__src_A_ALU_execute, vlTOPp->mips_cpu_bus__DOT__src_B_ALU_execute))) 
                                   << 0x20U);
                            vlTOPp->mips_cpu_bus__DOT__alu__DOT__ALU_HI_LO_output 
                                = (vlTOPp->mips_cpu_bus__DOT__alu__DOT__ALU_HI_LO_output 
                                   + (QData)((IData)(
                                                     VL_MODDIVS_III(32, vlTOPp->mips_cpu_bus__DOT__src_A_ALU_execute, vlTOPp->mips_cpu_bus__DOT__src_B_ALU_execute))));
                        }
                    } else {
                        vlTOPp->mips_cpu_bus__DOT__alu__DOT__ALU_HI_LO_output 
                            = ((1U & (IData)(vlTOPp->mips_cpu_bus__DOT__ALU_function_execute))
                                ? ((QData)((IData)(vlTOPp->mips_cpu_bus__DOT__src_A_ALU_execute)) 
                                   * (QData)((IData)(vlTOPp->mips_cpu_bus__DOT__src_B_ALU_execute)))
                                : VL_MULS_QQQ(64,64,64, 
                                              (((QData)((IData)(
                                                                VL_NEGATE_I((IData)(
                                                                                (1U 
                                                                                & (vlTOPp->mips_cpu_bus__DOT__src_A_ALU_execute 
                                                                                >> 0x1fU)))))) 
                                                << 0x20U) 
                                               | (QData)((IData)(vlTOPp->mips_cpu_bus__DOT__src_A_ALU_execute))), 
                                              (((QData)((IData)(
                                                                VL_NEGATE_I((IData)(
                                                                                (1U 
                                                                                & (vlTOPp->mips_cpu_bus__DOT__src_B_ALU_execute 
                                                                                >> 0x1fU)))))) 
                                                << 0x20U) 
                                               | (QData)((IData)(vlTOPp->mips_cpu_bus__DOT__src_B_ALU_execute)))));
                    }
                }
            }
        }
    }
    vlTOPp->mips_cpu_bus__DOT__ALU_HI_output_execute 
        = (IData)((vlTOPp->mips_cpu_bus__DOT__alu__DOT__ALU_HI_LO_output 
                   >> 0x20U));
    vlTOPp->mips_cpu_bus__DOT__ALU_LO_output_execute 
        = (IData)(vlTOPp->mips_cpu_bus__DOT__alu__DOT__ALU_HI_LO_output);
}

VL_INLINE_OPT void MIPS_Bus_TB::_multiclk__TOP__9(MIPS_Bus_TB__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    MIPS_Bus_TB::_multiclk__TOP__9\n"); );
    MIPS_Bus_TB* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->mips_cpu_bus__DOT__register_file_output_A_decode 
        = vlTOPp->mips_cpu_bus__DOT__register_file__DOT__registers
        [(0x1fU & (vlTOPp->mips_cpu_bus__DOT__instruction_decode 
                   >> 0x15U))];
    vlTOPp->mips_cpu_bus__DOT__register_file_output_B_decode 
        = vlTOPp->mips_cpu_bus__DOT__register_file__DOT__registers
        [(0x1fU & (vlTOPp->mips_cpu_bus__DOT__instruction_decode 
                   >> 0x10U))];
}

VL_INLINE_OPT void MIPS_Bus_TB::_sequent__TOP__10(MIPS_Bus_TB__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    MIPS_Bus_TB::_sequent__TOP__10\n"); );
    MIPS_Bus_TB* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->mips_cpu_bus__DOT__control_unit__DOT__op 
        = (0x3fU & (vlTOPp->mips_cpu_bus__DOT__instruction_decode 
                    >> 0x1aU));
    vlTOPp->mips_cpu_bus__DOT__control_unit__DOT__rt 
        = (0x1fU & (vlTOPp->mips_cpu_bus__DOT__instruction_decode 
                    >> 0x10U));
    vlTOPp->mips_cpu_bus__DOT__control_unit__DOT__funct 
        = (0x3fU & vlTOPp->mips_cpu_bus__DOT__instruction_decode);
    if ((0x20U & (IData)(vlTOPp->mips_cpu_bus__DOT__control_unit__DOT__op))) {
        if ((0x10U & (IData)(vlTOPp->mips_cpu_bus__DOT__control_unit__DOT__op))) {
            vlTOPp->mips_cpu_bus__DOT__register_write_decode = 0U;
            vlTOPp->mips_cpu_bus__DOT__memory_to_register_decode = 0U;
            vlTOPp->mips_cpu_bus__DOT__memory_write_decode = 0U;
            vlTOPp->mips_cpu_bus__DOT__ALU_src_B_decode = 0U;
            vlTOPp->mips_cpu_bus__DOT__register_destination_decode = 0U;
            vlTOPp->mips_cpu_bus__DOT__branch_decode = 0U;
            vlTOPp->mips_cpu_bus__DOT__HI_register_write_decode = 0U;
            vlTOPp->mips_cpu_bus__DOT__LO_register_write_decode = 0U;
            vlTOPp->mips_cpu_bus__DOT__ALU_function_decode = 0U;
            vlTOPp->mips_cpu_bus__DOT__program_counter_multiplexer_jump_decode = 0U;
            vlTOPp->mips_cpu_bus__DOT__j_instruction_decode = 0U;
            vlTOPp->mips_cpu_bus__DOT__using_HI_LO_decode = 0U;
        } else {
            if ((8U & (IData)(vlTOPp->mips_cpu_bus__DOT__control_unit__DOT__op))) {
                if ((4U & (IData)(vlTOPp->mips_cpu_bus__DOT__control_unit__DOT__op))) {
                    vlTOPp->mips_cpu_bus__DOT__register_write_decode = 0U;
                    vlTOPp->mips_cpu_bus__DOT__memory_to_register_decode = 0U;
                    vlTOPp->mips_cpu_bus__DOT__memory_write_decode = 0U;
                    vlTOPp->mips_cpu_bus__DOT__ALU_src_B_decode = 0U;
                    vlTOPp->mips_cpu_bus__DOT__register_destination_decode = 0U;
                    vlTOPp->mips_cpu_bus__DOT__branch_decode = 0U;
                    vlTOPp->mips_cpu_bus__DOT__HI_register_write_decode = 0U;
                    vlTOPp->mips_cpu_bus__DOT__LO_register_write_decode = 0U;
                    vlTOPp->mips_cpu_bus__DOT__ALU_function_decode = 0U;
                    vlTOPp->mips_cpu_bus__DOT__program_counter_multiplexer_jump_decode = 0U;
                    vlTOPp->mips_cpu_bus__DOT__j_instruction_decode = 0U;
                    vlTOPp->mips_cpu_bus__DOT__using_HI_LO_decode = 0U;
                } else {
                    if ((2U & (IData)(vlTOPp->mips_cpu_bus__DOT__control_unit__DOT__op))) {
                        if ((1U & (IData)(vlTOPp->mips_cpu_bus__DOT__control_unit__DOT__op))) {
                            vlTOPp->mips_cpu_bus__DOT__register_write_decode = 0U;
                            vlTOPp->mips_cpu_bus__DOT__memory_to_register_decode = 0U;
                            vlTOPp->mips_cpu_bus__DOT__memory_write_decode = 1U;
                            vlTOPp->mips_cpu_bus__DOT__ALU_src_B_decode = 1U;
                            vlTOPp->mips_cpu_bus__DOT__register_destination_decode = 0U;
                            vlTOPp->mips_cpu_bus__DOT__branch_decode = 0U;
                            vlTOPp->mips_cpu_bus__DOT__HI_register_write_decode = 0U;
                            vlTOPp->mips_cpu_bus__DOT__LO_register_write_decode = 0U;
                            vlTOPp->mips_cpu_bus__DOT__ALU_function_decode = 0x21U;
                            vlTOPp->mips_cpu_bus__DOT__program_counter_multiplexer_jump_decode = 0U;
                            vlTOPp->mips_cpu_bus__DOT__j_instruction_decode = 0U;
                            vlTOPp->mips_cpu_bus__DOT__using_HI_LO_decode = 0U;
                        } else {
                            vlTOPp->mips_cpu_bus__DOT__register_write_decode = 0U;
                            vlTOPp->mips_cpu_bus__DOT__memory_to_register_decode = 0U;
                            vlTOPp->mips_cpu_bus__DOT__memory_write_decode = 0U;
                            vlTOPp->mips_cpu_bus__DOT__ALU_src_B_decode = 0U;
                            vlTOPp->mips_cpu_bus__DOT__register_destination_decode = 0U;
                            vlTOPp->mips_cpu_bus__DOT__branch_decode = 0U;
                            vlTOPp->mips_cpu_bus__DOT__HI_register_write_decode = 0U;
                            vlTOPp->mips_cpu_bus__DOT__LO_register_write_decode = 0U;
                            vlTOPp->mips_cpu_bus__DOT__ALU_function_decode = 0U;
                            vlTOPp->mips_cpu_bus__DOT__program_counter_multiplexer_jump_decode = 0U;
                            vlTOPp->mips_cpu_bus__DOT__j_instruction_decode = 0U;
                            vlTOPp->mips_cpu_bus__DOT__using_HI_LO_decode = 0U;
                        }
                    } else {
                        vlTOPp->mips_cpu_bus__DOT__register_write_decode = 0U;
                        vlTOPp->mips_cpu_bus__DOT__memory_to_register_decode = 0U;
                        vlTOPp->mips_cpu_bus__DOT__memory_write_decode = 0U;
                        vlTOPp->mips_cpu_bus__DOT__ALU_src_B_decode = 0U;
                        vlTOPp->mips_cpu_bus__DOT__register_destination_decode = 0U;
                        vlTOPp->mips_cpu_bus__DOT__branch_decode = 0U;
                        vlTOPp->mips_cpu_bus__DOT__HI_register_write_decode = 0U;
                        vlTOPp->mips_cpu_bus__DOT__LO_register_write_decode = 0U;
                        vlTOPp->mips_cpu_bus__DOT__ALU_function_decode = 0U;
                        vlTOPp->mips_cpu_bus__DOT__program_counter_multiplexer_jump_decode = 0U;
                        vlTOPp->mips_cpu_bus__DOT__j_instruction_decode = 0U;
                        vlTOPp->mips_cpu_bus__DOT__using_HI_LO_decode = 0U;
                    }
                }
            } else {
                if ((4U & (IData)(vlTOPp->mips_cpu_bus__DOT__control_unit__DOT__op))) {
                    if ((2U & (IData)(vlTOPp->mips_cpu_bus__DOT__control_unit__DOT__op))) {
                        vlTOPp->mips_cpu_bus__DOT__register_write_decode = 0U;
                        vlTOPp->mips_cpu_bus__DOT__memory_to_register_decode = 0U;
                        vlTOPp->mips_cpu_bus__DOT__memory_write_decode = 0U;
                        vlTOPp->mips_cpu_bus__DOT__ALU_src_B_decode = 0U;
                        vlTOPp->mips_cpu_bus__DOT__register_destination_decode = 0U;
                        vlTOPp->mips_cpu_bus__DOT__branch_decode = 0U;
                        vlTOPp->mips_cpu_bus__DOT__HI_register_write_decode = 0U;
                        vlTOPp->mips_cpu_bus__DOT__LO_register_write_decode = 0U;
                        vlTOPp->mips_cpu_bus__DOT__ALU_function_decode = 0U;
                        vlTOPp->mips_cpu_bus__DOT__program_counter_multiplexer_jump_decode = 0U;
                        vlTOPp->mips_cpu_bus__DOT__j_instruction_decode = 0U;
                        vlTOPp->mips_cpu_bus__DOT__using_HI_LO_decode = 0U;
                    } else {
                        if ((1U & (IData)(vlTOPp->mips_cpu_bus__DOT__control_unit__DOT__op))) {
                            vlTOPp->mips_cpu_bus__DOT__register_write_decode = 0U;
                            vlTOPp->mips_cpu_bus__DOT__memory_to_register_decode = 0U;
                            vlTOPp->mips_cpu_bus__DOT__memory_write_decode = 1U;
                            vlTOPp->mips_cpu_bus__DOT__ALU_src_B_decode = 1U;
                            vlTOPp->mips_cpu_bus__DOT__register_destination_decode = 0U;
                            vlTOPp->mips_cpu_bus__DOT__branch_decode = 0U;
                            vlTOPp->mips_cpu_bus__DOT__HI_register_write_decode = 0U;
                            vlTOPp->mips_cpu_bus__DOT__LO_register_write_decode = 0U;
                            vlTOPp->mips_cpu_bus__DOT__ALU_function_decode = 0x21U;
                            vlTOPp->mips_cpu_bus__DOT__program_counter_multiplexer_jump_decode = 0U;
                            vlTOPp->mips_cpu_bus__DOT__j_instruction_decode = 0U;
                            vlTOPp->mips_cpu_bus__DOT__using_HI_LO_decode = 0U;
                        } else {
                            vlTOPp->mips_cpu_bus__DOT__register_write_decode = 0U;
                            vlTOPp->mips_cpu_bus__DOT__memory_to_register_decode = 0U;
                            vlTOPp->mips_cpu_bus__DOT__memory_write_decode = 0U;
                            vlTOPp->mips_cpu_bus__DOT__ALU_src_B_decode = 0U;
                            vlTOPp->mips_cpu_bus__DOT__register_destination_decode = 0U;
                            vlTOPp->mips_cpu_bus__DOT__branch_decode = 0U;
                            vlTOPp->mips_cpu_bus__DOT__HI_register_write_decode = 0U;
                            vlTOPp->mips_cpu_bus__DOT__LO_register_write_decode = 0U;
                            vlTOPp->mips_cpu_bus__DOT__ALU_function_decode = 0U;
                            vlTOPp->mips_cpu_bus__DOT__program_counter_multiplexer_jump_decode = 0U;
                            vlTOPp->mips_cpu_bus__DOT__j_instruction_decode = 0U;
                            vlTOPp->mips_cpu_bus__DOT__using_HI_LO_decode = 0U;
                        }
                    }
                } else {
                    vlTOPp->mips_cpu_bus__DOT__register_write_decode = 0U;
                    vlTOPp->mips_cpu_bus__DOT__memory_to_register_decode = 0U;
                    vlTOPp->mips_cpu_bus__DOT__memory_write_decode = 0U;
                    vlTOPp->mips_cpu_bus__DOT__ALU_src_B_decode = 0U;
                    vlTOPp->mips_cpu_bus__DOT__register_destination_decode = 0U;
                    vlTOPp->mips_cpu_bus__DOT__branch_decode = 0U;
                    vlTOPp->mips_cpu_bus__DOT__HI_register_write_decode = 0U;
                    vlTOPp->mips_cpu_bus__DOT__LO_register_write_decode = 0U;
                    vlTOPp->mips_cpu_bus__DOT__ALU_function_decode = 0U;
                    vlTOPp->mips_cpu_bus__DOT__program_counter_multiplexer_jump_decode = 0U;
                    vlTOPp->mips_cpu_bus__DOT__j_instruction_decode = 0U;
                    vlTOPp->mips_cpu_bus__DOT__using_HI_LO_decode = 0U;
                }
            }
        }
    } else {
        if ((0x10U & (IData)(vlTOPp->mips_cpu_bus__DOT__control_unit__DOT__op))) {
            vlTOPp->mips_cpu_bus__DOT__register_write_decode = 0U;
            vlTOPp->mips_cpu_bus__DOT__memory_to_register_decode = 0U;
            vlTOPp->mips_cpu_bus__DOT__memory_write_decode = 0U;
            vlTOPp->mips_cpu_bus__DOT__ALU_src_B_decode = 0U;
            vlTOPp->mips_cpu_bus__DOT__register_destination_decode = 0U;
            vlTOPp->mips_cpu_bus__DOT__branch_decode = 0U;
            vlTOPp->mips_cpu_bus__DOT__HI_register_write_decode = 0U;
            vlTOPp->mips_cpu_bus__DOT__LO_register_write_decode = 0U;
            vlTOPp->mips_cpu_bus__DOT__ALU_function_decode = 0U;
            vlTOPp->mips_cpu_bus__DOT__program_counter_multiplexer_jump_decode = 0U;
            vlTOPp->mips_cpu_bus__DOT__j_instruction_decode = 0U;
            vlTOPp->mips_cpu_bus__DOT__using_HI_LO_decode = 0U;
        } else {
            if ((8U & (IData)(vlTOPp->mips_cpu_bus__DOT__control_unit__DOT__op))) {
                if ((4U & (IData)(vlTOPp->mips_cpu_bus__DOT__control_unit__DOT__op))) {
                    if ((2U & (IData)(vlTOPp->mips_cpu_bus__DOT__control_unit__DOT__op))) {
                        if ((1U & (IData)(vlTOPp->mips_cpu_bus__DOT__control_unit__DOT__op))) {
                            vlTOPp->mips_cpu_bus__DOT__register_write_decode = 1U;
                            vlTOPp->mips_cpu_bus__DOT__memory_to_register_decode = 0U;
                            vlTOPp->mips_cpu_bus__DOT__memory_write_decode = 0U;
                            vlTOPp->mips_cpu_bus__DOT__ALU_src_B_decode = 1U;
                            vlTOPp->mips_cpu_bus__DOT__register_destination_decode = 0U;
                            vlTOPp->mips_cpu_bus__DOT__branch_decode = 0U;
                            vlTOPp->mips_cpu_bus__DOT__HI_register_write_decode = 0U;
                            vlTOPp->mips_cpu_bus__DOT__LO_register_write_decode = 0U;
                            vlTOPp->mips_cpu_bus__DOT__ALU_function_decode = 0x3fU;
                            vlTOPp->mips_cpu_bus__DOT__program_counter_multiplexer_jump_decode = 0U;
                            vlTOPp->mips_cpu_bus__DOT__j_instruction_decode = 0U;
                            vlTOPp->mips_cpu_bus__DOT__using_HI_LO_decode = 0U;
                        } else {
                            vlTOPp->mips_cpu_bus__DOT__register_write_decode = 1U;
                            vlTOPp->mips_cpu_bus__DOT__memory_to_register_decode = 0U;
                            vlTOPp->mips_cpu_bus__DOT__memory_write_decode = 0U;
                            vlTOPp->mips_cpu_bus__DOT__ALU_src_B_decode = 1U;
                            vlTOPp->mips_cpu_bus__DOT__register_destination_decode = 0U;
                            vlTOPp->mips_cpu_bus__DOT__branch_decode = 0U;
                            vlTOPp->mips_cpu_bus__DOT__HI_register_write_decode = 0U;
                            vlTOPp->mips_cpu_bus__DOT__LO_register_write_decode = 0U;
                            vlTOPp->mips_cpu_bus__DOT__ALU_function_decode = 0x26U;
                            vlTOPp->mips_cpu_bus__DOT__program_counter_multiplexer_jump_decode = 0U;
                            vlTOPp->mips_cpu_bus__DOT__j_instruction_decode = 0U;
                            vlTOPp->mips_cpu_bus__DOT__using_HI_LO_decode = 0U;
                        }
                    } else {
                        if ((1U & (IData)(vlTOPp->mips_cpu_bus__DOT__control_unit__DOT__op))) {
                            vlTOPp->mips_cpu_bus__DOT__register_write_decode = 1U;
                            vlTOPp->mips_cpu_bus__DOT__memory_to_register_decode = 0U;
                            vlTOPp->mips_cpu_bus__DOT__memory_write_decode = 0U;
                            vlTOPp->mips_cpu_bus__DOT__ALU_src_B_decode = 1U;
                            vlTOPp->mips_cpu_bus__DOT__register_destination_decode = 0U;
                            vlTOPp->mips_cpu_bus__DOT__branch_decode = 0U;
                            vlTOPp->mips_cpu_bus__DOT__HI_register_write_decode = 0U;
                            vlTOPp->mips_cpu_bus__DOT__LO_register_write_decode = 0U;
                            vlTOPp->mips_cpu_bus__DOT__ALU_function_decode = 0x25U;
                            vlTOPp->mips_cpu_bus__DOT__program_counter_multiplexer_jump_decode = 0U;
                            vlTOPp->mips_cpu_bus__DOT__j_instruction_decode = 0U;
                            vlTOPp->mips_cpu_bus__DOT__using_HI_LO_decode = 0U;
                        } else {
                            vlTOPp->mips_cpu_bus__DOT__register_write_decode = 1U;
                            vlTOPp->mips_cpu_bus__DOT__memory_to_register_decode = 0U;
                            vlTOPp->mips_cpu_bus__DOT__memory_write_decode = 0U;
                            vlTOPp->mips_cpu_bus__DOT__ALU_src_B_decode = 1U;
                            vlTOPp->mips_cpu_bus__DOT__register_destination_decode = 0U;
                            vlTOPp->mips_cpu_bus__DOT__branch_decode = 0U;
                            vlTOPp->mips_cpu_bus__DOT__HI_register_write_decode = 0U;
                            vlTOPp->mips_cpu_bus__DOT__LO_register_write_decode = 0U;
                            vlTOPp->mips_cpu_bus__DOT__ALU_function_decode = 0x24U;
                            vlTOPp->mips_cpu_bus__DOT__program_counter_multiplexer_jump_decode = 0U;
                            vlTOPp->mips_cpu_bus__DOT__j_instruction_decode = 0U;
                            vlTOPp->mips_cpu_bus__DOT__using_HI_LO_decode = 0U;
                        }
                    }
                } else {
                    if ((2U & (IData)(vlTOPp->mips_cpu_bus__DOT__control_unit__DOT__op))) {
                        if ((1U & (IData)(vlTOPp->mips_cpu_bus__DOT__control_unit__DOT__op))) {
                            vlTOPp->mips_cpu_bus__DOT__register_write_decode = 0U;
                            vlTOPp->mips_cpu_bus__DOT__memory_to_register_decode = 0U;
                            vlTOPp->mips_cpu_bus__DOT__memory_write_decode = 0U;
                            vlTOPp->mips_cpu_bus__DOT__ALU_src_B_decode = 0U;
                            vlTOPp->mips_cpu_bus__DOT__register_destination_decode = 0U;
                            vlTOPp->mips_cpu_bus__DOT__branch_decode = 0U;
                            vlTOPp->mips_cpu_bus__DOT__HI_register_write_decode = 0U;
                            vlTOPp->mips_cpu_bus__DOT__LO_register_write_decode = 0U;
                            vlTOPp->mips_cpu_bus__DOT__ALU_function_decode = 0U;
                            vlTOPp->mips_cpu_bus__DOT__program_counter_multiplexer_jump_decode = 0U;
                            vlTOPp->mips_cpu_bus__DOT__j_instruction_decode = 0U;
                            vlTOPp->mips_cpu_bus__DOT__using_HI_LO_decode = 0U;
                        } else {
                            vlTOPp->mips_cpu_bus__DOT__register_write_decode = 1U;
                            vlTOPp->mips_cpu_bus__DOT__memory_to_register_decode = 0U;
                            vlTOPp->mips_cpu_bus__DOT__memory_write_decode = 0U;
                            vlTOPp->mips_cpu_bus__DOT__ALU_src_B_decode = 1U;
                            vlTOPp->mips_cpu_bus__DOT__register_destination_decode = 0U;
                            vlTOPp->mips_cpu_bus__DOT__branch_decode = 0U;
                            vlTOPp->mips_cpu_bus__DOT__HI_register_write_decode = 0U;
                            vlTOPp->mips_cpu_bus__DOT__LO_register_write_decode = 0U;
                            vlTOPp->mips_cpu_bus__DOT__ALU_function_decode = 0x21U;
                            vlTOPp->mips_cpu_bus__DOT__program_counter_multiplexer_jump_decode = 0U;
                            vlTOPp->mips_cpu_bus__DOT__j_instruction_decode = 0U;
                            vlTOPp->mips_cpu_bus__DOT__using_HI_LO_decode = 0U;
                        }
                    } else {
                        if ((1U & (IData)(vlTOPp->mips_cpu_bus__DOT__control_unit__DOT__op))) {
                            vlTOPp->mips_cpu_bus__DOT__register_write_decode = 1U;
                            vlTOPp->mips_cpu_bus__DOT__memory_to_register_decode = 0U;
                            vlTOPp->mips_cpu_bus__DOT__memory_write_decode = 0U;
                            vlTOPp->mips_cpu_bus__DOT__ALU_src_B_decode = 1U;
                            vlTOPp->mips_cpu_bus__DOT__register_destination_decode = 0U;
                            vlTOPp->mips_cpu_bus__DOT__branch_decode = 0U;
                            vlTOPp->mips_cpu_bus__DOT__HI_register_write_decode = 0U;
                            vlTOPp->mips_cpu_bus__DOT__LO_register_write_decode = 0U;
                            vlTOPp->mips_cpu_bus__DOT__ALU_function_decode = 0x21U;
                            vlTOPp->mips_cpu_bus__DOT__program_counter_multiplexer_jump_decode = 0U;
                            vlTOPp->mips_cpu_bus__DOT__j_instruction_decode = 0U;
                            vlTOPp->mips_cpu_bus__DOT__using_HI_LO_decode = 0U;
                        } else {
                            vlTOPp->mips_cpu_bus__DOT__register_write_decode = 1U;
                            vlTOPp->mips_cpu_bus__DOT__memory_to_register_decode = 0U;
                            vlTOPp->mips_cpu_bus__DOT__memory_write_decode = 0U;
                            vlTOPp->mips_cpu_bus__DOT__ALU_src_B_decode = 1U;
                            vlTOPp->mips_cpu_bus__DOT__register_destination_decode = 0U;
                            vlTOPp->mips_cpu_bus__DOT__branch_decode = 0U;
                            vlTOPp->mips_cpu_bus__DOT__HI_register_write_decode = 0U;
                            vlTOPp->mips_cpu_bus__DOT__LO_register_write_decode = 0U;
                            vlTOPp->mips_cpu_bus__DOT__ALU_function_decode = 0x20U;
                            vlTOPp->mips_cpu_bus__DOT__program_counter_multiplexer_jump_decode = 0U;
                            vlTOPp->mips_cpu_bus__DOT__j_instruction_decode = 0U;
                            vlTOPp->mips_cpu_bus__DOT__using_HI_LO_decode = 0U;
                        }
                    }
                }
            } else {
                if ((4U & (IData)(vlTOPp->mips_cpu_bus__DOT__control_unit__DOT__op))) {
                    if ((2U & (IData)(vlTOPp->mips_cpu_bus__DOT__control_unit__DOT__op))) {
                        if ((1U & (IData)(vlTOPp->mips_cpu_bus__DOT__control_unit__DOT__op))) {
                            vlTOPp->mips_cpu_bus__DOT__register_write_decode = 0U;
                            vlTOPp->mips_cpu_bus__DOT__memory_to_register_decode = 0U;
                            vlTOPp->mips_cpu_bus__DOT__memory_write_decode = 0U;
                            vlTOPp->mips_cpu_bus__DOT__ALU_src_B_decode = 0U;
                            vlTOPp->mips_cpu_bus__DOT__register_destination_decode = 0U;
                            vlTOPp->mips_cpu_bus__DOT__branch_decode = 1U;
                            vlTOPp->mips_cpu_bus__DOT__HI_register_write_decode = 0U;
                            vlTOPp->mips_cpu_bus__DOT__LO_register_write_decode = 0U;
                            vlTOPp->mips_cpu_bus__DOT__ALU_function_decode = 0x3fU;
                            vlTOPp->mips_cpu_bus__DOT__program_counter_multiplexer_jump_decode = 0U;
                            vlTOPp->mips_cpu_bus__DOT__j_instruction_decode = 0U;
                            vlTOPp->mips_cpu_bus__DOT__using_HI_LO_decode = 0U;
                        } else {
                            vlTOPp->mips_cpu_bus__DOT__register_write_decode = 0U;
                            vlTOPp->mips_cpu_bus__DOT__memory_to_register_decode = 0U;
                            vlTOPp->mips_cpu_bus__DOT__memory_write_decode = 0U;
                            vlTOPp->mips_cpu_bus__DOT__ALU_src_B_decode = 0U;
                            vlTOPp->mips_cpu_bus__DOT__register_destination_decode = 0U;
                            vlTOPp->mips_cpu_bus__DOT__branch_decode = 1U;
                            vlTOPp->mips_cpu_bus__DOT__HI_register_write_decode = 0U;
                            vlTOPp->mips_cpu_bus__DOT__LO_register_write_decode = 0U;
                            vlTOPp->mips_cpu_bus__DOT__ALU_function_decode = 0x3fU;
                            vlTOPp->mips_cpu_bus__DOT__program_counter_multiplexer_jump_decode = 0U;
                            vlTOPp->mips_cpu_bus__DOT__j_instruction_decode = 0U;
                            vlTOPp->mips_cpu_bus__DOT__using_HI_LO_decode = 0U;
                        }
                    } else {
                        if ((1U & (IData)(vlTOPp->mips_cpu_bus__DOT__control_unit__DOT__op))) {
                            vlTOPp->mips_cpu_bus__DOT__register_write_decode = 0U;
                            vlTOPp->mips_cpu_bus__DOT__memory_to_register_decode = 0U;
                            vlTOPp->mips_cpu_bus__DOT__memory_write_decode = 0U;
                            vlTOPp->mips_cpu_bus__DOT__ALU_src_B_decode = 0U;
                            vlTOPp->mips_cpu_bus__DOT__register_destination_decode = 0U;
                            vlTOPp->mips_cpu_bus__DOT__branch_decode = 1U;
                            vlTOPp->mips_cpu_bus__DOT__HI_register_write_decode = 0U;
                            vlTOPp->mips_cpu_bus__DOT__LO_register_write_decode = 0U;
                            vlTOPp->mips_cpu_bus__DOT__ALU_function_decode = 0x3fU;
                            vlTOPp->mips_cpu_bus__DOT__program_counter_multiplexer_jump_decode = 0U;
                            vlTOPp->mips_cpu_bus__DOT__j_instruction_decode = 0U;
                            vlTOPp->mips_cpu_bus__DOT__using_HI_LO_decode = 0U;
                        } else {
                            vlTOPp->mips_cpu_bus__DOT__register_write_decode = 0U;
                            vlTOPp->mips_cpu_bus__DOT__memory_to_register_decode = 0U;
                            vlTOPp->mips_cpu_bus__DOT__memory_write_decode = 0U;
                            vlTOPp->mips_cpu_bus__DOT__ALU_src_B_decode = 0U;
                            vlTOPp->mips_cpu_bus__DOT__register_destination_decode = 0U;
                            vlTOPp->mips_cpu_bus__DOT__branch_decode = 1U;
                            vlTOPp->mips_cpu_bus__DOT__HI_register_write_decode = 0U;
                            vlTOPp->mips_cpu_bus__DOT__LO_register_write_decode = 0U;
                            vlTOPp->mips_cpu_bus__DOT__ALU_function_decode = 0x3fU;
                            vlTOPp->mips_cpu_bus__DOT__program_counter_multiplexer_jump_decode = 0U;
                            vlTOPp->mips_cpu_bus__DOT__j_instruction_decode = 0U;
                            vlTOPp->mips_cpu_bus__DOT__using_HI_LO_decode = 0U;
                        }
                    }
                } else {
                    if ((2U & (IData)(vlTOPp->mips_cpu_bus__DOT__control_unit__DOT__op))) {
                        if ((1U & (IData)(vlTOPp->mips_cpu_bus__DOT__control_unit__DOT__op))) {
                            vlTOPp->mips_cpu_bus__DOT__register_write_decode = 1U;
                            vlTOPp->mips_cpu_bus__DOT__memory_to_register_decode = 0U;
                            vlTOPp->mips_cpu_bus__DOT__memory_write_decode = 0U;
                            vlTOPp->mips_cpu_bus__DOT__ALU_src_B_decode = 2U;
                            vlTOPp->mips_cpu_bus__DOT__register_destination_decode = 2U;
                            vlTOPp->mips_cpu_bus__DOT__branch_decode = 1U;
                            vlTOPp->mips_cpu_bus__DOT__HI_register_write_decode = 0U;
                            vlTOPp->mips_cpu_bus__DOT__LO_register_write_decode = 0U;
                            vlTOPp->mips_cpu_bus__DOT__ALU_function_decode = 0x3fU;
                            vlTOPp->mips_cpu_bus__DOT__program_counter_multiplexer_jump_decode = 1U;
                            vlTOPp->mips_cpu_bus__DOT__j_instruction_decode = 1U;
                            vlTOPp->mips_cpu_bus__DOT__using_HI_LO_decode = 0U;
                        } else {
                            vlTOPp->mips_cpu_bus__DOT__register_write_decode = 0U;
                            vlTOPp->mips_cpu_bus__DOT__memory_to_register_decode = 0U;
                            vlTOPp->mips_cpu_bus__DOT__memory_write_decode = 0U;
                            vlTOPp->mips_cpu_bus__DOT__ALU_src_B_decode = 2U;
                            vlTOPp->mips_cpu_bus__DOT__register_destination_decode = 2U;
                            vlTOPp->mips_cpu_bus__DOT__branch_decode = 1U;
                            vlTOPp->mips_cpu_bus__DOT__HI_register_write_decode = 0U;
                            vlTOPp->mips_cpu_bus__DOT__LO_register_write_decode = 0U;
                            vlTOPp->mips_cpu_bus__DOT__ALU_function_decode = 0x3fU;
                            vlTOPp->mips_cpu_bus__DOT__program_counter_multiplexer_jump_decode = 1U;
                            vlTOPp->mips_cpu_bus__DOT__j_instruction_decode = 1U;
                            vlTOPp->mips_cpu_bus__DOT__using_HI_LO_decode = 0U;
                        }
                    } else {
                        if ((1U & (IData)(vlTOPp->mips_cpu_bus__DOT__control_unit__DOT__op))) {
                            vlTOPp->mips_cpu_bus__DOT__register_write_decode 
                                = ((0x11U == (IData)(vlTOPp->mips_cpu_bus__DOT__control_unit__DOT__rt)) 
                                   | (0x10U == (IData)(vlTOPp->mips_cpu_bus__DOT__control_unit__DOT__rt)));
                            vlTOPp->mips_cpu_bus__DOT__memory_to_register_decode = 0U;
                            vlTOPp->mips_cpu_bus__DOT__memory_write_decode = 0U;
                            vlTOPp->mips_cpu_bus__DOT__ALU_src_B_decode = 2U;
                            vlTOPp->mips_cpu_bus__DOT__register_destination_decode = 2U;
                            vlTOPp->mips_cpu_bus__DOT__branch_decode = 1U;
                            vlTOPp->mips_cpu_bus__DOT__HI_register_write_decode = 0U;
                            vlTOPp->mips_cpu_bus__DOT__LO_register_write_decode = 0U;
                            vlTOPp->mips_cpu_bus__DOT__ALU_function_decode = 0x3fU;
                            vlTOPp->mips_cpu_bus__DOT__program_counter_multiplexer_jump_decode = 0U;
                            vlTOPp->mips_cpu_bus__DOT__j_instruction_decode = 0U;
                            vlTOPp->mips_cpu_bus__DOT__using_HI_LO_decode = 0U;
                        } else {
                            vlTOPp->mips_cpu_bus__DOT__register_write_decode = 1U;
                            vlTOPp->mips_cpu_bus__DOT__memory_to_register_decode = 0U;
                            vlTOPp->mips_cpu_bus__DOT__memory_write_decode = 0U;
                            vlTOPp->mips_cpu_bus__DOT__ALU_src_B_decode = 0U;
                            vlTOPp->mips_cpu_bus__DOT__register_destination_decode = 1U;
                            vlTOPp->mips_cpu_bus__DOT__branch_decode = 0U;
                            vlTOPp->mips_cpu_bus__DOT__HI_register_write_decode 
                                = (((((0x18U == (IData)(vlTOPp->mips_cpu_bus__DOT__control_unit__DOT__funct)) 
                                      | (0x19U == (IData)(vlTOPp->mips_cpu_bus__DOT__control_unit__DOT__funct))) 
                                     | (0x1aU == (IData)(vlTOPp->mips_cpu_bus__DOT__control_unit__DOT__funct))) 
                                    | (0x1bU == (IData)(vlTOPp->mips_cpu_bus__DOT__control_unit__DOT__funct))) 
                                   | (0x11U == (IData)(vlTOPp->mips_cpu_bus__DOT__control_unit__DOT__funct)));
                            vlTOPp->mips_cpu_bus__DOT__j_instruction_decode = 0U;
                            vlTOPp->mips_cpu_bus__DOT__LO_register_write_decode 
                                = (((((0x18U == (IData)(vlTOPp->mips_cpu_bus__DOT__control_unit__DOT__funct)) 
                                      | (0x19U == (IData)(vlTOPp->mips_cpu_bus__DOT__control_unit__DOT__funct))) 
                                     | (0x1aU == (IData)(vlTOPp->mips_cpu_bus__DOT__control_unit__DOT__funct))) 
                                    | (0x1bU == (IData)(vlTOPp->mips_cpu_bus__DOT__control_unit__DOT__funct))) 
                                   | (0x13U == (IData)(vlTOPp->mips_cpu_bus__DOT__control_unit__DOT__funct)));
                            vlTOPp->mips_cpu_bus__DOT__ALU_function_decode 
                                = ((0x20U & (IData)(vlTOPp->mips_cpu_bus__DOT__control_unit__DOT__funct))
                                    ? (IData)(vlTOPp->mips_cpu_bus__DOT__control_unit__DOT__funct)
                                    : ((0x10U & (IData)(vlTOPp->mips_cpu_bus__DOT__control_unit__DOT__funct))
                                        ? ((8U & (IData)(vlTOPp->mips_cpu_bus__DOT__control_unit__DOT__funct))
                                            ? (IData)(vlTOPp->mips_cpu_bus__DOT__control_unit__DOT__funct)
                                            : ((4U 
                                                & (IData)(vlTOPp->mips_cpu_bus__DOT__control_unit__DOT__funct))
                                                ? (IData)(vlTOPp->mips_cpu_bus__DOT__control_unit__DOT__funct)
                                                : (
                                                   (2U 
                                                    & (IData)(vlTOPp->mips_cpu_bus__DOT__control_unit__DOT__funct))
                                                    ? 
                                                   ((1U 
                                                     & (IData)(vlTOPp->mips_cpu_bus__DOT__control_unit__DOT__funct))
                                                     ? 0x3eU
                                                     : 0x3fU)
                                                    : 
                                                   ((1U 
                                                     & (IData)(vlTOPp->mips_cpu_bus__DOT__control_unit__DOT__funct))
                                                     ? 0x3fU
                                                     : 0x3eU))))
                                        : (IData)(vlTOPp->mips_cpu_bus__DOT__control_unit__DOT__funct)));
                            vlTOPp->mips_cpu_bus__DOT__program_counter_multiplexer_jump_decode 
                                = ((8U == (IData)(vlTOPp->mips_cpu_bus__DOT__control_unit__DOT__funct)) 
                                   | (9U == (IData)(vlTOPp->mips_cpu_bus__DOT__control_unit__DOT__funct)));
                            vlTOPp->mips_cpu_bus__DOT__using_HI_LO_decode 
                                = ((0x10U == (IData)(vlTOPp->mips_cpu_bus__DOT__control_unit__DOT__funct)) 
                                   | (0x12U == (IData)(vlTOPp->mips_cpu_bus__DOT__control_unit__DOT__funct)));
                        }
                    }
                }
            }
        }
    }
}

VL_INLINE_OPT void MIPS_Bus_TB::_multiclk__TOP__11(MIPS_Bus_TB__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    MIPS_Bus_TB::_multiclk__TOP__11\n"); );
    MIPS_Bus_TB* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->mips_cpu_bus__DOT__comparator_1 = ((((0U 
                                                  != 
                                                  (0x1fU 
                                                   & (vlTOPp->mips_cpu_bus__DOT__instruction_decode 
                                                      >> 0x15U))) 
                                                 & ((0x1fU 
                                                     & (vlTOPp->mips_cpu_bus__DOT__instruction_decode 
                                                        >> 0x15U)) 
                                                    == (IData)(vlTOPp->mips_cpu_bus__DOT__write_register_memory))) 
                                                & (IData)(vlTOPp->mips_cpu_bus__DOT__register_write_memory))
                                                ? vlTOPp->mips_cpu_bus__DOT__ALU_output_memory
                                                : vlTOPp->mips_cpu_bus__DOT__register_file_output_A_decode);
    vlTOPp->mips_cpu_bus__DOT__comparator_2 = ((((0U 
                                                  != 
                                                  (0x1fU 
                                                   & (vlTOPp->mips_cpu_bus__DOT__instruction_decode 
                                                      >> 0x10U))) 
                                                 & ((0x1fU 
                                                     & (vlTOPp->mips_cpu_bus__DOT__instruction_decode 
                                                        >> 0x10U)) 
                                                    == (IData)(vlTOPp->mips_cpu_bus__DOT__write_register_memory))) 
                                                & (IData)(vlTOPp->mips_cpu_bus__DOT__register_write_memory))
                                                ? vlTOPp->mips_cpu_bus__DOT__ALU_output_memory
                                                : vlTOPp->mips_cpu_bus__DOT__register_file_output_B_decode);
    vlTOPp->mips_cpu_bus__DOT__program_counter_src_decode 
        = ((IData)(vlTOPp->mips_cpu_bus__DOT__branch_decode) 
           & ((~ (vlTOPp->mips_cpu_bus__DOT__instruction_decode 
                  >> 0x1fU)) & ((~ (vlTOPp->mips_cpu_bus__DOT__instruction_decode 
                                    >> 0x1eU)) & ((~ 
                                                   (vlTOPp->mips_cpu_bus__DOT__instruction_decode 
                                                    >> 0x1dU)) 
                                                  & ((0x10000000U 
                                                      & vlTOPp->mips_cpu_bus__DOT__instruction_decode)
                                                      ? 
                                                     ((0x8000000U 
                                                       & vlTOPp->mips_cpu_bus__DOT__instruction_decode)
                                                       ? 
                                                      ((0x4000000U 
                                                        & vlTOPp->mips_cpu_bus__DOT__instruction_decode)
                                                        ? 
                                                       VL_LTS_III(1,32,32, 0U, vlTOPp->mips_cpu_bus__DOT__comparator_1)
                                                        : 
                                                       VL_GTES_III(1,32,32, 0U, vlTOPp->mips_cpu_bus__DOT__comparator_1))
                                                       : 
                                                      ((0x4000000U 
                                                        & vlTOPp->mips_cpu_bus__DOT__instruction_decode)
                                                        ? 
                                                       (vlTOPp->mips_cpu_bus__DOT__comparator_1 
                                                        != vlTOPp->mips_cpu_bus__DOT__comparator_2)
                                                        : 
                                                       (vlTOPp->mips_cpu_bus__DOT__comparator_1 
                                                        == vlTOPp->mips_cpu_bus__DOT__comparator_2)))
                                                      : 
                                                     ((~ 
                                                       (vlTOPp->mips_cpu_bus__DOT__instruction_decode 
                                                        >> 0x1bU)) 
                                                      & ((vlTOPp->mips_cpu_bus__DOT__instruction_decode 
                                                          >> 0x1aU) 
                                                         & (((1U 
                                                              == 
                                                              (0x1fU 
                                                               & (vlTOPp->mips_cpu_bus__DOT__instruction_decode 
                                                                  >> 0x10U))) 
                                                             | (0x11U 
                                                                == 
                                                                (0x1fU 
                                                                 & (vlTOPp->mips_cpu_bus__DOT__instruction_decode 
                                                                    >> 0x10U))))
                                                             ? 
                                                            VL_LTES_III(1,32,32, 0U, vlTOPp->mips_cpu_bus__DOT__comparator_1)
                                                             : 
                                                            (((0U 
                                                               == 
                                                               (0x1fU 
                                                                & (vlTOPp->mips_cpu_bus__DOT__instruction_decode 
                                                                   >> 0x10U))) 
                                                              | (0x10U 
                                                                 == 
                                                                 (0x1fU 
                                                                  & (vlTOPp->mips_cpu_bus__DOT__instruction_decode 
                                                                     >> 0x10U)))) 
                                                             & VL_GTS_III(1,32,32, 0U, vlTOPp->mips_cpu_bus__DOT__comparator_1))))))))));
    vlTOPp->mips_cpu_bus__DOT__program_counter_mux_1_out 
        = ((IData)(vlTOPp->mips_cpu_bus__DOT__program_counter_src_decode)
            ? ((vlTOPp->mips_cpu_bus__DOT__sign_imm_decode 
                << 2U) + vlTOPp->mips_cpu_bus__DOT__program_counter_plus_four_decode)
            : ((IData)(4U) + vlTOPp->mips_cpu_bus__DOT__instr_address));
}

VL_INLINE_OPT void MIPS_Bus_TB::_multiclk__TOP__12(MIPS_Bus_TB__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    MIPS_Bus_TB::_multiclk__TOP__12\n"); );
    MIPS_Bus_TB* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->mips_cpu_bus__DOT__hazard_unit__DOT__lwstall 
        = ((((0x1fU & (vlTOPp->mips_cpu_bus__DOT__instruction_decode 
                       >> 0x15U)) == (IData)(vlTOPp->mips_cpu_bus__DOT__Rt_execute)) 
            | ((0x1fU & (vlTOPp->mips_cpu_bus__DOT__instruction_decode 
                         >> 0x10U)) == (IData)(vlTOPp->mips_cpu_bus__DOT__Rt_execute))) 
           & (IData)(vlTOPp->mips_cpu_bus__DOT__memory_to_register_execute));
    vlTOPp->mips_cpu_bus__DOT__hazard_unit__DOT__branchstall 
        = ((((IData)(vlTOPp->mips_cpu_bus__DOT__branch_decode) 
             & (IData)(vlTOPp->mips_cpu_bus__DOT__register_write_execute)) 
            & (((IData)(vlTOPp->mips_cpu_bus__DOT__write_register_execute) 
                == (0x1fU & (vlTOPp->mips_cpu_bus__DOT__instruction_decode 
                             >> 0x15U))) | ((IData)(vlTOPp->mips_cpu_bus__DOT__write_register_execute) 
                                            == (0x1fU 
                                                & (vlTOPp->mips_cpu_bus__DOT__instruction_decode 
                                                   >> 0x10U))))) 
           | (((IData)(vlTOPp->mips_cpu_bus__DOT__branch_decode) 
               & (IData)(vlTOPp->mips_cpu_bus__DOT__memory_to_register_memory)) 
              & (((IData)(vlTOPp->mips_cpu_bus__DOT__write_register_memory) 
                  == (0x1fU & (vlTOPp->mips_cpu_bus__DOT__instruction_decode 
                               >> 0x15U))) | ((IData)(vlTOPp->mips_cpu_bus__DOT__write_register_memory) 
                                              == (0x1fU 
                                                  & (vlTOPp->mips_cpu_bus__DOT__instruction_decode 
                                                     >> 0x10U))))));
    vlTOPp->mips_cpu_bus__DOT__stall_fetch = (((IData)(vlTOPp->mips_cpu_bus__DOT__hazard_unit__DOT__branchstall) 
                                               | (IData)(vlTOPp->mips_cpu_bus__DOT__hazard_unit__DOT__lwstall)) 
                                              | (IData)(vlTOPp->mips_cpu_bus__DOT__program_counter_multiplexer_jump_execute));
    vlTOPp->mips_cpu_bus__DOT__stall_decode = (((IData)(vlTOPp->mips_cpu_bus__DOT__hazard_unit__DOT__branchstall) 
                                                | (IData)(vlTOPp->mips_cpu_bus__DOT__hazard_unit__DOT__lwstall)) 
                                               | (IData)(vlTOPp->mips_cpu_bus__DOT__program_counter_multiplexer_jump_execute));
    vlTOPp->mips_cpu_bus__DOT__flush_execute_register 
        = ((IData)(vlTOPp->mips_cpu_bus__DOT__hazard_unit__DOT__branchstall) 
           | (IData)(vlTOPp->mips_cpu_bus__DOT__hazard_unit__DOT__lwstall));
}

void MIPS_Bus_TB::_eval(MIPS_Bus_TB__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    MIPS_Bus_TB::_eval\n"); );
    MIPS_Bus_TB* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if (((~ (IData)(vlTOPp->__VinpClk__TOP__mips_cpu_bus__DOT__internal_clk)) 
         & (IData)(vlTOPp->__Vclklast__TOP____VinpClk__TOP__mips_cpu_bus__DOT__internal_clk))) {
        vlTOPp->_sequent__TOP__1(vlSymsp);
        vlTOPp->__Vm_traceActivity = (2U | vlTOPp->__Vm_traceActivity);
    }
    if ((((IData)(vlTOPp->__VinpClk__TOP__mips_cpu_bus__DOT__internal_clk) 
          & (~ (IData)(vlTOPp->__Vclklast__TOP____VinpClk__TOP__mips_cpu_bus__DOT__internal_clk))) 
         | ((IData)(vlTOPp->reset) & (~ (IData)(vlTOPp->__Vclklast__TOP__reset))))) {
        vlTOPp->_sequent__TOP__2(vlSymsp);
        vlTOPp->__Vm_traceActivity = (4U | vlTOPp->__Vm_traceActivity);
    }
    if ((((IData)(vlTOPp->clk) ^ (IData)(vlTOPp->__Vclklast__TOP__clk)) 
         | ((IData)(vlTOPp->reset) & (~ (IData)(vlTOPp->__Vclklast__TOP__reset))))) {
        vlTOPp->_sequent__TOP__3(vlSymsp);
        vlTOPp->__Vm_traceActivity = (8U | vlTOPp->__Vm_traceActivity);
    }
    if (((~ (IData)(vlTOPp->__VinpClk__TOP__mips_cpu_bus__DOT__internal_clk)) 
         & (IData)(vlTOPp->__Vclklast__TOP____VinpClk__TOP__mips_cpu_bus__DOT__internal_clk))) {
        vlTOPp->_sequent__TOP__5(vlSymsp);
        vlTOPp->__Vm_traceActivity = (0x10U | vlTOPp->__Vm_traceActivity);
    }
    if ((((IData)(vlTOPp->__VinpClk__TOP__mips_cpu_bus__DOT__internal_clk) 
          & (~ (IData)(vlTOPp->__Vclklast__TOP____VinpClk__TOP__mips_cpu_bus__DOT__internal_clk))) 
         | ((IData)(vlTOPp->reset) & (~ (IData)(vlTOPp->__Vclklast__TOP__reset))))) {
        vlTOPp->_sequent__TOP__6(vlSymsp);
        vlTOPp->__Vm_traceActivity = (0x20U | vlTOPp->__Vm_traceActivity);
    }
    if (((((IData)(vlTOPp->clk) ^ (IData)(vlTOPp->__Vclklast__TOP__clk)) 
          | ((IData)(vlTOPp->__VinpClk__TOP__mips_cpu_bus__DOT__internal_clk) 
             & (~ (IData)(vlTOPp->__Vclklast__TOP____VinpClk__TOP__mips_cpu_bus__DOT__internal_clk)))) 
         | ((IData)(vlTOPp->reset) & (~ (IData)(vlTOPp->__Vclklast__TOP__reset))))) {
        vlTOPp->_multiclk__TOP__7(vlSymsp);
        vlTOPp->__Vm_traceActivity = (0x40U | vlTOPp->__Vm_traceActivity);
    }
    vlTOPp->_combo__TOP__8(vlSymsp);
    vlTOPp->__Vm_traceActivity = (0x80U | vlTOPp->__Vm_traceActivity);
    if (((((IData)(vlTOPp->clk) ^ (IData)(vlTOPp->__Vclklast__TOP__clk)) 
          | ((~ (IData)(vlTOPp->__VinpClk__TOP__mips_cpu_bus__DOT__internal_clk)) 
             & (IData)(vlTOPp->__Vclklast__TOP____VinpClk__TOP__mips_cpu_bus__DOT__internal_clk))) 
         | ((IData)(vlTOPp->reset) & (~ (IData)(vlTOPp->__Vclklast__TOP__reset))))) {
        vlTOPp->_multiclk__TOP__9(vlSymsp);
        vlTOPp->__Vm_traceActivity = (0x100U | vlTOPp->__Vm_traceActivity);
    }
    if ((((IData)(vlTOPp->clk) ^ (IData)(vlTOPp->__Vclklast__TOP__clk)) 
         | ((IData)(vlTOPp->reset) & (~ (IData)(vlTOPp->__Vclklast__TOP__reset))))) {
        vlTOPp->_sequent__TOP__10(vlSymsp);
        vlTOPp->__Vm_traceActivity = (0x200U | vlTOPp->__Vm_traceActivity);
    }
    if (((((IData)(vlTOPp->clk) ^ (IData)(vlTOPp->__Vclklast__TOP__clk)) 
          | ((IData)(vlTOPp->__VinpClk__TOP__mips_cpu_bus__DOT__internal_clk) 
             ^ (IData)(vlTOPp->__Vclklast__TOP____VinpClk__TOP__mips_cpu_bus__DOT__internal_clk))) 
         | ((IData)(vlTOPp->reset) & (~ (IData)(vlTOPp->__Vclklast__TOP__reset))))) {
        vlTOPp->_multiclk__TOP__11(vlSymsp);
        vlTOPp->__Vm_traceActivity = (0x400U | vlTOPp->__Vm_traceActivity);
    }
    if (((((IData)(vlTOPp->clk) ^ (IData)(vlTOPp->__Vclklast__TOP__clk)) 
          | ((IData)(vlTOPp->__VinpClk__TOP__mips_cpu_bus__DOT__internal_clk) 
             & (~ (IData)(vlTOPp->__Vclklast__TOP____VinpClk__TOP__mips_cpu_bus__DOT__internal_clk)))) 
         | ((IData)(vlTOPp->reset) & (~ (IData)(vlTOPp->__Vclklast__TOP__reset))))) {
        vlTOPp->_multiclk__TOP__12(vlSymsp);
        vlTOPp->__Vm_traceActivity = (0x800U | vlTOPp->__Vm_traceActivity);
    }
    // Final
    vlTOPp->__Vclklast__TOP____VinpClk__TOP__mips_cpu_bus__DOT__internal_clk 
        = vlTOPp->__VinpClk__TOP__mips_cpu_bus__DOT__internal_clk;
    vlTOPp->__Vclklast__TOP__reset = vlTOPp->reset;
    vlTOPp->__Vclklast__TOP__clk = vlTOPp->clk;
    vlTOPp->__VinpClk__TOP__mips_cpu_bus__DOT__internal_clk 
        = vlTOPp->mips_cpu_bus__DOT__internal_clk;
}

void MIPS_Bus_TB::_eval_initial(MIPS_Bus_TB__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    MIPS_Bus_TB::_eval_initial\n"); );
    MIPS_Bus_TB* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->__Vclklast__TOP____VinpClk__TOP__mips_cpu_bus__DOT__internal_clk 
        = vlTOPp->__VinpClk__TOP__mips_cpu_bus__DOT__internal_clk;
    vlTOPp->__Vclklast__TOP__reset = vlTOPp->reset;
    vlTOPp->__Vclklast__TOP__clk = vlTOPp->clk;
}

void MIPS_Bus_TB::final() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    MIPS_Bus_TB::final\n"); );
    // Variables
    MIPS_Bus_TB__Syms* __restrict vlSymsp = this->__VlSymsp;
    MIPS_Bus_TB* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void MIPS_Bus_TB::_eval_settle(MIPS_Bus_TB__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    MIPS_Bus_TB::_eval_settle\n"); );
    MIPS_Bus_TB* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_settle__TOP__4(vlSymsp);
    vlTOPp->__Vm_traceActivity = (1U | vlTOPp->__Vm_traceActivity);
}

VL_INLINE_OPT QData MIPS_Bus_TB::_change_request(MIPS_Bus_TB__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    MIPS_Bus_TB::_change_request\n"); );
    MIPS_Bus_TB* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // Change detection
    QData __req = false;  // Logically a bool
    __req |= ((vlTOPp->mips_cpu_bus__DOT__internal_clk ^ vlTOPp->__Vchglast__TOP__mips_cpu_bus__DOT__internal_clk));
    VL_DEBUG_IF( if(__req && ((vlTOPp->mips_cpu_bus__DOT__internal_clk ^ vlTOPp->__Vchglast__TOP__mips_cpu_bus__DOT__internal_clk))) VL_DBG_MSGF("        CHANGE: ../../rtl/mips_cpu_bus.v:22: mips_cpu_bus.internal_clk\n"); );
    // Final
    vlTOPp->__Vchglast__TOP__mips_cpu_bus__DOT__internal_clk 
        = vlTOPp->mips_cpu_bus__DOT__internal_clk;
    return __req;
}

#ifdef VL_DEBUG
void MIPS_Bus_TB::_eval_debug_assertions() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    MIPS_Bus_TB::_eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((clk & 0xfeU))) {
        Verilated::overWidthError("clk");}
    if (VL_UNLIKELY((reset & 0xfeU))) {
        Verilated::overWidthError("reset");}
    if (VL_UNLIKELY((waitrequest & 0xfeU))) {
        Verilated::overWidthError("waitrequest");}
}
#endif  // VL_DEBUG

void MIPS_Bus_TB::_ctor_var_reset() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    MIPS_Bus_TB::_ctor_var_reset\n"); );
    // Body
    clk = VL_RAND_RESET_I(1);
    reset = VL_RAND_RESET_I(1);
    active = VL_RAND_RESET_I(1);
    register_v0 = VL_RAND_RESET_I(32);
    address = VL_RAND_RESET_I(32);
    write = VL_RAND_RESET_I(1);
    read = VL_RAND_RESET_I(1);
    waitrequest = VL_RAND_RESET_I(1);
    writedata = VL_RAND_RESET_I(32);
    byteenable = VL_RAND_RESET_I(4);
    readdata = VL_RAND_RESET_I(32);
    mips_cpu_bus__DOT__internal_clk = VL_RAND_RESET_I(1);
    mips_cpu_bus__DOT__instr_address = VL_RAND_RESET_I(32);
    mips_cpu_bus__DOT__program_counter_mux_1_out = VL_RAND_RESET_I(32);
    mips_cpu_bus__DOT__HALT_fetch = VL_RAND_RESET_I(1);
    mips_cpu_bus__DOT__program_counter_src_decode = VL_RAND_RESET_I(1);
    mips_cpu_bus__DOT__register_write_decode = VL_RAND_RESET_I(1);
    mips_cpu_bus__DOT__memory_to_register_decode = VL_RAND_RESET_I(1);
    mips_cpu_bus__DOT__memory_write_decode = VL_RAND_RESET_I(1);
    mips_cpu_bus__DOT__ALU_src_B_decode = VL_RAND_RESET_I(2);
    mips_cpu_bus__DOT__register_destination_decode = VL_RAND_RESET_I(2);
    mips_cpu_bus__DOT__branch_decode = VL_RAND_RESET_I(1);
    mips_cpu_bus__DOT__ALU_function_decode = VL_RAND_RESET_I(6);
    mips_cpu_bus__DOT__program_counter_multiplexer_jump_decode = VL_RAND_RESET_I(1);
    mips_cpu_bus__DOT__using_HI_LO_decode = VL_RAND_RESET_I(1);
    mips_cpu_bus__DOT__j_instruction_decode = VL_RAND_RESET_I(1);
    mips_cpu_bus__DOT__HI_register_write_decode = VL_RAND_RESET_I(1);
    mips_cpu_bus__DOT__LO_register_write_decode = VL_RAND_RESET_I(1);
    mips_cpu_bus__DOT__HALT_decode = VL_RAND_RESET_I(1);
    mips_cpu_bus__DOT__instruction_decode = VL_RAND_RESET_I(32);
    mips_cpu_bus__DOT__program_counter_plus_four_decode = VL_RAND_RESET_I(32);
    mips_cpu_bus__DOT__register_file_output_A_decode = VL_RAND_RESET_I(32);
    mips_cpu_bus__DOT__register_file_output_B_decode = VL_RAND_RESET_I(32);
    mips_cpu_bus__DOT__sign_imm_decode = VL_RAND_RESET_I(32);
    mips_cpu_bus__DOT__comparator_1 = VL_RAND_RESET_I(32);
    mips_cpu_bus__DOT__comparator_2 = VL_RAND_RESET_I(32);
    mips_cpu_bus__DOT__register_destination_execute = VL_RAND_RESET_I(2);
    mips_cpu_bus__DOT__memory_to_register_execute = VL_RAND_RESET_I(1);
    mips_cpu_bus__DOT__memory_write_execute = VL_RAND_RESET_I(1);
    mips_cpu_bus__DOT__write_register_execute = VL_RAND_RESET_I(5);
    mips_cpu_bus__DOT__ALU_src_B_execute = VL_RAND_RESET_I(2);
    mips_cpu_bus__DOT__ALU_function_execute = VL_RAND_RESET_I(6);
    mips_cpu_bus__DOT__HI_register_write_execute = VL_RAND_RESET_I(1);
    mips_cpu_bus__DOT__LO_register_write_execute = VL_RAND_RESET_I(1);
    mips_cpu_bus__DOT__register_write_execute = VL_RAND_RESET_I(1);
    mips_cpu_bus__DOT__program_counter_multiplexer_jump_execute = VL_RAND_RESET_I(1);
    mips_cpu_bus__DOT__j_instruction_execute = VL_RAND_RESET_I(1);
    mips_cpu_bus__DOT__using_HI_LO_execute = VL_RAND_RESET_I(1);
    mips_cpu_bus__DOT__HALT_execute = VL_RAND_RESET_I(1);
    mips_cpu_bus__DOT__op_execute = VL_RAND_RESET_I(6);
    mips_cpu_bus__DOT__src_A_execute = VL_RAND_RESET_I(32);
    mips_cpu_bus__DOT__src_B_execute = VL_RAND_RESET_I(32);
    mips_cpu_bus__DOT__src_A_ALU_execute = VL_RAND_RESET_I(32);
    mips_cpu_bus__DOT__src_B_ALU_execute = VL_RAND_RESET_I(32);
    mips_cpu_bus__DOT__write_data_execute = VL_RAND_RESET_I(32);
    mips_cpu_bus__DOT__ALU_output_execute = VL_RAND_RESET_I(32);
    mips_cpu_bus__DOT__ALU_HI_output_execute = VL_RAND_RESET_I(32);
    mips_cpu_bus__DOT__ALU_LO_output_execute = VL_RAND_RESET_I(32);
    mips_cpu_bus__DOT__Rs_execute = VL_RAND_RESET_I(5);
    mips_cpu_bus__DOT__Rt_execute = VL_RAND_RESET_I(5);
    mips_cpu_bus__DOT__Rd_execute = VL_RAND_RESET_I(5);
    mips_cpu_bus__DOT__sign_imm_execute = VL_RAND_RESET_I(32);
    mips_cpu_bus__DOT__program_counter_plus_four_execute = VL_RAND_RESET_I(32);
    mips_cpu_bus__DOT__j_program_counter_execute = VL_RAND_RESET_I(32);
    mips_cpu_bus__DOT__register_write_memory = VL_RAND_RESET_I(1);
    mips_cpu_bus__DOT__write_register_memory = VL_RAND_RESET_I(5);
    mips_cpu_bus__DOT__memory_to_register_memory = VL_RAND_RESET_I(1);
    mips_cpu_bus__DOT__memory_write_memory = VL_RAND_RESET_I(1);
    mips_cpu_bus__DOT__HI_register_write_memory = VL_RAND_RESET_I(1);
    mips_cpu_bus__DOT__LO_register_write_memory = VL_RAND_RESET_I(1);
    mips_cpu_bus__DOT__program_counter_multiplexer_jump_memory = VL_RAND_RESET_I(1);
    mips_cpu_bus__DOT__j_instruction_memory = VL_RAND_RESET_I(1);
    mips_cpu_bus__DOT__HALT_memory = VL_RAND_RESET_I(1);
    mips_cpu_bus__DOT__op_memory = VL_RAND_RESET_I(6);
    mips_cpu_bus__DOT__byteenable_memory = VL_RAND_RESET_I(4);
    mips_cpu_bus__DOT__ALU_output_memory = VL_RAND_RESET_I(32);
    mips_cpu_bus__DOT__ALU_HI_output_memory = VL_RAND_RESET_I(32);
    mips_cpu_bus__DOT__ALU_LO_output_memory = VL_RAND_RESET_I(32);
    mips_cpu_bus__DOT__write_data_memory = VL_RAND_RESET_I(32);
    mips_cpu_bus__DOT__j_program_counter_memory = VL_RAND_RESET_I(32);
    mips_cpu_bus__DOT__src_A_ALU_memory = VL_RAND_RESET_I(32);
    mips_cpu_bus__DOT__register_write_writeback = VL_RAND_RESET_I(1);
    mips_cpu_bus__DOT__HI_register_write_writeback = VL_RAND_RESET_I(1);
    mips_cpu_bus__DOT__LO_register_write_writeback = VL_RAND_RESET_I(1);
    mips_cpu_bus__DOT__memory_to_register_writeback = VL_RAND_RESET_I(1);
    mips_cpu_bus__DOT__HALT_writeback = VL_RAND_RESET_I(1);
    mips_cpu_bus__DOT__op_writeback = VL_RAND_RESET_I(6);
    mips_cpu_bus__DOT__byteenable_writeback = VL_RAND_RESET_I(4);
    mips_cpu_bus__DOT__src_A_ALU_writeback = VL_RAND_RESET_I(32);
    mips_cpu_bus__DOT__write_register_writeback = VL_RAND_RESET_I(5);
    mips_cpu_bus__DOT__result_writeback = VL_RAND_RESET_I(32);
    mips_cpu_bus__DOT__ALU_HI_output_writeback = VL_RAND_RESET_I(32);
    mips_cpu_bus__DOT__ALU_LO_output_writeback = VL_RAND_RESET_I(32);
    mips_cpu_bus__DOT__ALU_output_writeback = VL_RAND_RESET_I(32);
    mips_cpu_bus__DOT__read_data_writeback = VL_RAND_RESET_I(32);
    mips_cpu_bus__DOT__read_data_writeback_filtered = VL_RAND_RESET_I(32);
    mips_cpu_bus__DOT__stall_fetch = VL_RAND_RESET_I(1);
    mips_cpu_bus__DOT__stall_decode = VL_RAND_RESET_I(1);
    mips_cpu_bus__DOT__flush_execute_register = VL_RAND_RESET_I(1);
    mips_cpu_bus__DOT__forward_A_execute = VL_RAND_RESET_I(3);
    mips_cpu_bus__DOT__forward_B_execute = VL_RAND_RESET_I(3);
    mips_cpu_bus__DOT__fetch_state = VL_RAND_RESET_I(2);
    { int __Vi0=0; for (; __Vi0<32; ++__Vi0) {
            mips_cpu_bus__DOT__register_file__DOT__registers[__Vi0] = VL_RAND_RESET_I(32);
    }}
    mips_cpu_bus__DOT__register_file__DOT__HI_reg = VL_RAND_RESET_I(32);
    mips_cpu_bus__DOT__register_file__DOT__LO_reg = VL_RAND_RESET_I(32);
    mips_cpu_bus__DOT__control_unit__DOT__op = VL_RAND_RESET_I(6);
    mips_cpu_bus__DOT__control_unit__DOT__rt = VL_RAND_RESET_I(5);
    mips_cpu_bus__DOT__control_unit__DOT__funct = VL_RAND_RESET_I(6);
    mips_cpu_bus__DOT__alu_input_mux__DOT__src_mux_input_0 = VL_RAND_RESET_I(32);
    mips_cpu_bus__DOT__alu__DOT__ALU_HI_LO_output = VL_RAND_RESET_Q(64);
    mips_cpu_bus__DOT__memory_filter__DOT__temp_filtered = VL_RAND_RESET_I(32);
    mips_cpu_bus__DOT__hazard_unit__DOT__lwstall = VL_RAND_RESET_I(1);
    mips_cpu_bus__DOT__hazard_unit__DOT__branchstall = VL_RAND_RESET_I(1);
    __VinpClk__TOP__mips_cpu_bus__DOT__internal_clk = VL_RAND_RESET_I(1);
    __Vchglast__TOP__mips_cpu_bus__DOT__internal_clk = VL_RAND_RESET_I(1);
    __Vm_traceActivity = 0;
}
