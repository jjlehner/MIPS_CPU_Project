// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "MIPS_Bus_TB__Syms.h"


//======================

void MIPS_Bus_TB::traceChg(VerilatedVcd* vcdp, void* userthis, uint32_t code) {
    // Callback from vcd->dump()
    MIPS_Bus_TB* t = (MIPS_Bus_TB*)userthis;
    MIPS_Bus_TB__Syms* __restrict vlSymsp = t->__VlSymsp;  // Setup global symbol table
    if (vlSymsp->getClearActivity()) {
        t->traceChgThis(vlSymsp, vcdp, code);
    }
}

//======================


void MIPS_Bus_TB::traceChgThis(MIPS_Bus_TB__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    MIPS_Bus_TB* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
        if (VL_UNLIKELY((1U & (vlTOPp->__Vm_traceActivity 
                               | (vlTOPp->__Vm_traceActivity 
                                  >> 2U))))) {
            vlTOPp->traceChgThis__2(vlSymsp, vcdp, code);
        }
        if (VL_UNLIKELY((1U & ((vlTOPp->__Vm_traceActivity 
                                | (vlTOPp->__Vm_traceActivity 
                                   >> 2U)) | (vlTOPp->__Vm_traceActivity 
                                              >> 3U))))) {
            vlTOPp->traceChgThis__3(vlSymsp, vcdp, code);
        }
        if (VL_UNLIKELY((1U & (((vlTOPp->__Vm_traceActivity 
                                 | (vlTOPp->__Vm_traceActivity 
                                    >> 2U)) | (vlTOPp->__Vm_traceActivity 
                                               >> 3U)) 
                               | (vlTOPp->__Vm_traceActivity 
                                  >> 9U))))) {
            vlTOPp->traceChgThis__4(vlSymsp, vcdp, code);
        }
        if (VL_UNLIKELY((1U & (vlTOPp->__Vm_traceActivity 
                               | (vlTOPp->__Vm_traceActivity 
                                  >> 3U))))) {
            vlTOPp->traceChgThis__5(vlSymsp, vcdp, code);
        }
        if (VL_UNLIKELY((1U & (((vlTOPp->__Vm_traceActivity 
                                 | (vlTOPp->__Vm_traceActivity 
                                    >> 4U)) | (vlTOPp->__Vm_traceActivity 
                                               >> 7U)) 
                               | (vlTOPp->__Vm_traceActivity 
                                  >> 8U))))) {
            vlTOPp->traceChgThis__6(vlSymsp, vcdp, code);
        }
        if (VL_UNLIKELY((1U & (vlTOPp->__Vm_traceActivity 
                               | (vlTOPp->__Vm_traceActivity 
                                  >> 5U))))) {
            vlTOPp->traceChgThis__7(vlSymsp, vcdp, code);
        }
        if (VL_UNLIKELY((1U & (vlTOPp->__Vm_traceActivity 
                               | (vlTOPp->__Vm_traceActivity 
                                  >> 6U))))) {
            vlTOPp->traceChgThis__8(vlSymsp, vcdp, code);
        }
        if (VL_UNLIKELY((1U & (vlTOPp->__Vm_traceActivity 
                               | (vlTOPp->__Vm_traceActivity 
                                  >> 7U))))) {
            vlTOPp->traceChgThis__9(vlSymsp, vcdp, code);
        }
        if (VL_UNLIKELY((1U & (vlTOPp->__Vm_traceActivity 
                               | (vlTOPp->__Vm_traceActivity 
                                  >> 8U))))) {
            vlTOPp->traceChgThis__10(vlSymsp, vcdp, code);
        }
        if (VL_UNLIKELY((1U & (vlTOPp->__Vm_traceActivity 
                               | (vlTOPp->__Vm_traceActivity 
                                  >> 9U))))) {
            vlTOPp->traceChgThis__11(vlSymsp, vcdp, code);
        }
        if (VL_UNLIKELY((1U & (vlTOPp->__Vm_traceActivity 
                               | (vlTOPp->__Vm_traceActivity 
                                  >> 0xaU))))) {
            vlTOPp->traceChgThis__12(vlSymsp, vcdp, code);
        }
        if (VL_UNLIKELY((2U & vlTOPp->__Vm_traceActivity))) {
            vlTOPp->traceChgThis__13(vlSymsp, vcdp, code);
        }
        if (VL_UNLIKELY((4U & vlTOPp->__Vm_traceActivity))) {
            vlTOPp->traceChgThis__14(vlSymsp, vcdp, code);
        }
        if (VL_UNLIKELY((1U & ((vlTOPp->__Vm_traceActivity 
                                >> 2U) | (vlTOPp->__Vm_traceActivity 
                                          >> 3U))))) {
            vlTOPp->traceChgThis__15(vlSymsp, vcdp, code);
        }
        if (VL_UNLIKELY((8U & vlTOPp->__Vm_traceActivity))) {
            vlTOPp->traceChgThis__16(vlSymsp, vcdp, code);
        }
        if (VL_UNLIKELY((0x10U & vlTOPp->__Vm_traceActivity))) {
            vlTOPp->traceChgThis__17(vlSymsp, vcdp, code);
        }
        if (VL_UNLIKELY((0x20U & vlTOPp->__Vm_traceActivity))) {
            vlTOPp->traceChgThis__18(vlSymsp, vcdp, code);
        }
        vlTOPp->traceChgThis__19(vlSymsp, vcdp, code);
    }
    // Final
    vlTOPp->__Vm_traceActivity = 0U;
}

void MIPS_Bus_TB::traceChgThis__2(MIPS_Bus_TB__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    MIPS_Bus_TB* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
        vcdp->chgBus(c+1,(vlTOPp->mips_cpu_bus__DOT__write_register_execute),5);
    }
}

void MIPS_Bus_TB::traceChgThis__3(MIPS_Bus_TB__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    MIPS_Bus_TB* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
        vcdp->chgBus(c+9,(((vlTOPp->mips_cpu_bus__DOT__sign_imm_decode 
                            << 2U) + vlTOPp->mips_cpu_bus__DOT__program_counter_plus_four_decode)),32);
    }
}

void MIPS_Bus_TB::traceChgThis__4(MIPS_Bus_TB__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    MIPS_Bus_TB* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
        vcdp->chgBus(c+17,(((IData)(vlTOPp->mips_cpu_bus__DOT__program_counter_src_decode)
                             ? ((vlTOPp->mips_cpu_bus__DOT__sign_imm_decode 
                                 << 2U) + vlTOPp->mips_cpu_bus__DOT__program_counter_plus_four_decode)
                             : ((IData)(4U) + vlTOPp->mips_cpu_bus__DOT__program_counter_fetch))),32);
    }
}

void MIPS_Bus_TB::traceChgThis__5(MIPS_Bus_TB__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    MIPS_Bus_TB* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
        vcdp->chgBus(c+25,((vlTOPp->mips_cpu_bus__DOT__sign_imm_decode 
                            << 2U)),32);
        vcdp->chgBus(c+33,(vlTOPp->mips_cpu_bus__DOT__sign_imm_decode),32);
    }
}

void MIPS_Bus_TB::traceChgThis__6(MIPS_Bus_TB__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    MIPS_Bus_TB* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
        vcdp->chgBus(c+41,(((IData)(vlTOPp->mips_cpu_bus__DOT__using_HI_LO_decode)
                             ? vlTOPp->mips_cpu_bus__DOT__register_file__DOT__LO_reg
                             : vlTOPp->mips_cpu_bus__DOT__register_file_output_A_decode)),32);
        vcdp->chgBus(c+49,(((IData)(vlTOPp->mips_cpu_bus__DOT__using_HI_LO_decode)
                             ? vlTOPp->mips_cpu_bus__DOT__register_file__DOT__HI_reg
                             : vlTOPp->mips_cpu_bus__DOT__register_file_output_B_decode)),32);
    }
}

void MIPS_Bus_TB::traceChgThis__7(MIPS_Bus_TB__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    MIPS_Bus_TB* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
        vcdp->chgBus(c+57,(vlTOPp->mips_cpu_bus__DOT__forward_A_execute),3);
        vcdp->chgBus(c+65,(vlTOPp->mips_cpu_bus__DOT__forward_B_execute),3);
    }
}

void MIPS_Bus_TB::traceChgThis__8(MIPS_Bus_TB__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    MIPS_Bus_TB* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
        vcdp->chgBus(c+73,(vlTOPp->mips_cpu_bus__DOT__src_A_ALU_execute),32);
        vcdp->chgBus(c+81,(vlTOPp->mips_cpu_bus__DOT__src_B_ALU_execute),32);
        vcdp->chgBus(c+89,(vlTOPp->mips_cpu_bus__DOT__ALU_output_execute),32);
        vcdp->chgBus(c+97,(vlTOPp->mips_cpu_bus__DOT__ALU_HI_output_execute),32);
        vcdp->chgBus(c+105,(vlTOPp->mips_cpu_bus__DOT__ALU_LO_output_execute),32);
        vcdp->chgBus(c+113,(vlTOPp->mips_cpu_bus__DOT__result_writeback),32);
        vcdp->chgBus(c+121,(vlTOPp->mips_cpu_bus__DOT__read_data_writeback_filtered),32);
        vcdp->chgBus(c+129,(vlTOPp->mips_cpu_bus__DOT__alu_input_mux__DOT__src_mux_input_0),32);
        vcdp->chgBus(c+137,((0x1fU & (vlTOPp->mips_cpu_bus__DOT__src_A_ALU_execute 
                                      >> 6U))),5);
        vcdp->chgQuad(c+145,((((QData)((IData)(VL_NEGATE_I((IData)(
                                                                   (1U 
                                                                    & (vlTOPp->mips_cpu_bus__DOT__src_A_ALU_execute 
                                                                       >> 0x1fU)))))) 
                               << 0x20U) | (QData)((IData)(vlTOPp->mips_cpu_bus__DOT__src_A_ALU_execute)))),64);
        vcdp->chgQuad(c+161,((((QData)((IData)(VL_NEGATE_I((IData)(
                                                                   (1U 
                                                                    & (vlTOPp->mips_cpu_bus__DOT__src_B_ALU_execute 
                                                                       >> 0x1fU)))))) 
                               << 0x20U) | (QData)((IData)(vlTOPp->mips_cpu_bus__DOT__src_B_ALU_execute)))),64);
        vcdp->chgQuad(c+177,((QData)((IData)(vlTOPp->mips_cpu_bus__DOT__src_A_ALU_execute))),64);
        vcdp->chgQuad(c+193,((QData)((IData)(vlTOPp->mips_cpu_bus__DOT__src_B_ALU_execute))),64);
        vcdp->chgQuad(c+209,(vlTOPp->mips_cpu_bus__DOT__alu__DOT__ALU_HI_LO_output),64);
        vcdp->chgBus(c+225,(vlTOPp->mips_cpu_bus__DOT__memory_filter__DOT__temp_filtered),32);
    }
}

void MIPS_Bus_TB::traceChgThis__9(MIPS_Bus_TB__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    MIPS_Bus_TB* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
        vcdp->chgBus(c+233,(vlTOPp->mips_cpu_bus__DOT__register_file_output_A_decode),32);
        vcdp->chgBus(c+241,(vlTOPp->mips_cpu_bus__DOT__register_file_output_B_decode),32);
    }
}

void MIPS_Bus_TB::traceChgThis__10(MIPS_Bus_TB__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    MIPS_Bus_TB* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
        vcdp->chgBit(c+249,(vlTOPp->mips_cpu_bus__DOT__register_write_decode));
        vcdp->chgBit(c+257,(vlTOPp->mips_cpu_bus__DOT__memory_to_register_decode));
        vcdp->chgBit(c+265,(vlTOPp->mips_cpu_bus__DOT__memory_write_decode));
        vcdp->chgBus(c+273,(vlTOPp->mips_cpu_bus__DOT__ALU_src_B_decode),2);
        vcdp->chgBus(c+281,(vlTOPp->mips_cpu_bus__DOT__register_destination_decode),2);
        vcdp->chgBit(c+289,(vlTOPp->mips_cpu_bus__DOT__branch_decode));
        vcdp->chgBus(c+297,(vlTOPp->mips_cpu_bus__DOT__ALU_function_decode),6);
        vcdp->chgBit(c+305,(vlTOPp->mips_cpu_bus__DOT__program_counter_multiplexer_jump_decode));
        vcdp->chgBit(c+313,(vlTOPp->mips_cpu_bus__DOT__using_HI_LO_decode));
        vcdp->chgBit(c+321,(vlTOPp->mips_cpu_bus__DOT__j_instruction_decode));
        vcdp->chgBit(c+329,(vlTOPp->mips_cpu_bus__DOT__HI_register_write_decode));
        vcdp->chgBit(c+337,(vlTOPp->mips_cpu_bus__DOT__LO_register_write_decode));
        vcdp->chgBus(c+345,(vlTOPp->mips_cpu_bus__DOT__control_unit__DOT__op),6);
        vcdp->chgBus(c+353,(vlTOPp->mips_cpu_bus__DOT__control_unit__DOT__rt),5);
        vcdp->chgBus(c+361,(vlTOPp->mips_cpu_bus__DOT__control_unit__DOT__funct),6);
    }
}

void MIPS_Bus_TB::traceChgThis__11(MIPS_Bus_TB__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    MIPS_Bus_TB* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
        vcdp->chgBus(c+369,(vlTOPp->mips_cpu_bus__DOT__program_counter_prime),32);
        vcdp->chgBit(c+377,(vlTOPp->mips_cpu_bus__DOT__program_counter_src_decode));
        vcdp->chgBit(c+385,(vlTOPp->mips_cpu_bus__DOT__equal_decode));
        vcdp->chgBus(c+393,(vlTOPp->mips_cpu_bus__DOT__comparator_1),32);
        vcdp->chgBus(c+401,(vlTOPp->mips_cpu_bus__DOT__comparator_2),32);
    }
}

void MIPS_Bus_TB::traceChgThis__12(MIPS_Bus_TB__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    MIPS_Bus_TB* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
        vcdp->chgBit(c+409,(vlTOPp->mips_cpu_bus__DOT__stall_fetch));
        vcdp->chgBit(c+417,(vlTOPp->mips_cpu_bus__DOT__stall_decode));
        vcdp->chgBit(c+425,(vlTOPp->mips_cpu_bus__DOT__flush_execute_register));
        vcdp->chgBit(c+433,(vlTOPp->mips_cpu_bus__DOT__hazard_unit__DOT__lwstall));
        vcdp->chgBit(c+441,(vlTOPp->mips_cpu_bus__DOT__hazard_unit__DOT__branchstall));
    }
}

void MIPS_Bus_TB::traceChgThis__13(MIPS_Bus_TB__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    MIPS_Bus_TB* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
        vcdp->chgBus(c+449,(vlTOPp->mips_cpu_bus__DOT__register_file__DOT__registers[0]),32);
        vcdp->chgBus(c+450,(vlTOPp->mips_cpu_bus__DOT__register_file__DOT__registers[1]),32);
        vcdp->chgBus(c+451,(vlTOPp->mips_cpu_bus__DOT__register_file__DOT__registers[2]),32);
        vcdp->chgBus(c+452,(vlTOPp->mips_cpu_bus__DOT__register_file__DOT__registers[3]),32);
        vcdp->chgBus(c+453,(vlTOPp->mips_cpu_bus__DOT__register_file__DOT__registers[4]),32);
        vcdp->chgBus(c+454,(vlTOPp->mips_cpu_bus__DOT__register_file__DOT__registers[5]),32);
        vcdp->chgBus(c+455,(vlTOPp->mips_cpu_bus__DOT__register_file__DOT__registers[6]),32);
        vcdp->chgBus(c+456,(vlTOPp->mips_cpu_bus__DOT__register_file__DOT__registers[7]),32);
        vcdp->chgBus(c+457,(vlTOPp->mips_cpu_bus__DOT__register_file__DOT__registers[8]),32);
        vcdp->chgBus(c+458,(vlTOPp->mips_cpu_bus__DOT__register_file__DOT__registers[9]),32);
        vcdp->chgBus(c+459,(vlTOPp->mips_cpu_bus__DOT__register_file__DOT__registers[10]),32);
        vcdp->chgBus(c+460,(vlTOPp->mips_cpu_bus__DOT__register_file__DOT__registers[11]),32);
        vcdp->chgBus(c+461,(vlTOPp->mips_cpu_bus__DOT__register_file__DOT__registers[12]),32);
        vcdp->chgBus(c+462,(vlTOPp->mips_cpu_bus__DOT__register_file__DOT__registers[13]),32);
        vcdp->chgBus(c+463,(vlTOPp->mips_cpu_bus__DOT__register_file__DOT__registers[14]),32);
        vcdp->chgBus(c+464,(vlTOPp->mips_cpu_bus__DOT__register_file__DOT__registers[15]),32);
        vcdp->chgBus(c+465,(vlTOPp->mips_cpu_bus__DOT__register_file__DOT__registers[16]),32);
        vcdp->chgBus(c+466,(vlTOPp->mips_cpu_bus__DOT__register_file__DOT__registers[17]),32);
        vcdp->chgBus(c+467,(vlTOPp->mips_cpu_bus__DOT__register_file__DOT__registers[18]),32);
        vcdp->chgBus(c+468,(vlTOPp->mips_cpu_bus__DOT__register_file__DOT__registers[19]),32);
        vcdp->chgBus(c+469,(vlTOPp->mips_cpu_bus__DOT__register_file__DOT__registers[20]),32);
        vcdp->chgBus(c+470,(vlTOPp->mips_cpu_bus__DOT__register_file__DOT__registers[21]),32);
        vcdp->chgBus(c+471,(vlTOPp->mips_cpu_bus__DOT__register_file__DOT__registers[22]),32);
        vcdp->chgBus(c+472,(vlTOPp->mips_cpu_bus__DOT__register_file__DOT__registers[23]),32);
        vcdp->chgBus(c+473,(vlTOPp->mips_cpu_bus__DOT__register_file__DOT__registers[24]),32);
        vcdp->chgBus(c+474,(vlTOPp->mips_cpu_bus__DOT__register_file__DOT__registers[25]),32);
        vcdp->chgBus(c+475,(vlTOPp->mips_cpu_bus__DOT__register_file__DOT__registers[26]),32);
        vcdp->chgBus(c+476,(vlTOPp->mips_cpu_bus__DOT__register_file__DOT__registers[27]),32);
        vcdp->chgBus(c+477,(vlTOPp->mips_cpu_bus__DOT__register_file__DOT__registers[28]),32);
        vcdp->chgBus(c+478,(vlTOPp->mips_cpu_bus__DOT__register_file__DOT__registers[29]),32);
        vcdp->chgBus(c+479,(vlTOPp->mips_cpu_bus__DOT__register_file__DOT__registers[30]),32);
        vcdp->chgBus(c+480,(vlTOPp->mips_cpu_bus__DOT__register_file__DOT__registers[31]),32);
    }
}

void MIPS_Bus_TB::traceChgThis__14(MIPS_Bus_TB__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    MIPS_Bus_TB* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
        vcdp->chgBus(c+705,(vlTOPp->mips_cpu_bus__DOT__program_counter_fetch),32);
        vcdp->chgBus(c+713,(((IData)(4U) + vlTOPp->mips_cpu_bus__DOT__program_counter_fetch)),32);
        vcdp->chgBit(c+721,(vlTOPp->mips_cpu_bus__DOT__HALT_fetch));
        vcdp->chgBit(c+729,(vlTOPp->mips_cpu_bus__DOT__HALT_decode));
        vcdp->chgBus(c+737,(vlTOPp->mips_cpu_bus__DOT__program_counter_plus_four_decode),32);
        vcdp->chgBus(c+745,(vlTOPp->mips_cpu_bus__DOT__register_destination_execute),2);
        vcdp->chgBus(c+753,(vlTOPp->mips_cpu_bus__DOT__ALU_src_B_execute),2);
        vcdp->chgBus(c+761,(vlTOPp->mips_cpu_bus__DOT__ALU_function_execute),6);
        vcdp->chgBit(c+769,(vlTOPp->mips_cpu_bus__DOT__register_write_execute));
        vcdp->chgBit(c+777,(vlTOPp->mips_cpu_bus__DOT__program_counter_multiplexer_jump_execute));
        vcdp->chgBit(c+785,(vlTOPp->mips_cpu_bus__DOT__j_instruction_execute));
        vcdp->chgBit(c+793,(vlTOPp->mips_cpu_bus__DOT__using_HI_LO_execute));
        vcdp->chgBit(c+801,(vlTOPp->mips_cpu_bus__DOT__HALT_execute));
        vcdp->chgBus(c+809,(vlTOPp->mips_cpu_bus__DOT__op_execute),6);
        vcdp->chgBus(c+817,(vlTOPp->mips_cpu_bus__DOT__src_A_execute),32);
        vcdp->chgBus(c+825,(vlTOPp->mips_cpu_bus__DOT__src_B_execute),32);
        vcdp->chgBus(c+833,(vlTOPp->mips_cpu_bus__DOT__Rs_execute),5);
        vcdp->chgBus(c+841,(vlTOPp->mips_cpu_bus__DOT__Rt_execute),5);
        vcdp->chgBus(c+849,(vlTOPp->mips_cpu_bus__DOT__Rd_execute),5);
        vcdp->chgBus(c+857,(vlTOPp->mips_cpu_bus__DOT__sign_imm_execute),32);
        vcdp->chgBus(c+865,(((IData)(4U) + vlTOPp->mips_cpu_bus__DOT__program_counter_plus_four_execute)),32);
        vcdp->chgBus(c+873,(vlTOPp->mips_cpu_bus__DOT__program_counter_plus_four_execute),32);
        vcdp->chgBus(c+881,(vlTOPp->mips_cpu_bus__DOT__j_program_counter_execute),32);
        vcdp->chgBit(c+889,(vlTOPp->mips_cpu_bus__DOT__register_write_memory));
        vcdp->chgBus(c+897,(vlTOPp->mips_cpu_bus__DOT__write_register_memory),5);
        vcdp->chgBit(c+905,(vlTOPp->mips_cpu_bus__DOT__program_counter_multiplexer_jump_memory));
        vcdp->chgBit(c+913,(vlTOPp->mips_cpu_bus__DOT__j_instruction_memory));
        vcdp->chgBit(c+921,(vlTOPp->mips_cpu_bus__DOT__HALT_memory));
        vcdp->chgBus(c+929,(vlTOPp->mips_cpu_bus__DOT__op_memory),6);
        vcdp->chgBus(c+937,(vlTOPp->mips_cpu_bus__DOT__ALU_output_memory),32);
        vcdp->chgBus(c+945,(vlTOPp->mips_cpu_bus__DOT__write_data_memory),32);
        vcdp->chgBus(c+953,(((IData)(vlTOPp->mips_cpu_bus__DOT__j_instruction_memory)
                              ? vlTOPp->mips_cpu_bus__DOT__j_program_counter_memory
                              : vlTOPp->mips_cpu_bus__DOT__ALU_output_memory)),32);
        vcdp->chgBus(c+961,(vlTOPp->mips_cpu_bus__DOT__j_program_counter_memory),32);
        vcdp->chgBus(c+969,(vlTOPp->mips_cpu_bus__DOT__src_A_ALU_memory),32);
        vcdp->chgBit(c+977,(vlTOPp->mips_cpu_bus__DOT__register_write_writeback));
        vcdp->chgBit(c+985,(vlTOPp->mips_cpu_bus__DOT__memory_to_register_writeback));
        vcdp->chgBit(c+993,(vlTOPp->mips_cpu_bus__DOT__HALT_writeback));
        vcdp->chgBus(c+1001,(vlTOPp->mips_cpu_bus__DOT__op_writeback),6);
        vcdp->chgBus(c+1009,(vlTOPp->mips_cpu_bus__DOT__byteenable_writeback),4);
        vcdp->chgBus(c+1017,(vlTOPp->mips_cpu_bus__DOT__src_A_ALU_writeback),32);
        vcdp->chgBus(c+1025,(vlTOPp->mips_cpu_bus__DOT__write_register_writeback),5);
        vcdp->chgBus(c+1033,(vlTOPp->mips_cpu_bus__DOT__ALU_output_writeback),32);
    }
}

void MIPS_Bus_TB::traceChgThis__15(MIPS_Bus_TB__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    MIPS_Bus_TB* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
        vcdp->chgBus(c+1041,(((0xf0000000U & vlTOPp->mips_cpu_bus__DOT__program_counter_plus_four_decode) 
                              | (0xffffffcU & (vlTOPp->mips_cpu_bus__DOT__instruction_decode 
                                               << 2U)))),32);
        vcdp->chgBit(c+1049,((((0U != (0x1fU & (vlTOPp->mips_cpu_bus__DOT__instruction_decode 
                                                >> 0x15U))) 
                               & ((0x1fU & (vlTOPp->mips_cpu_bus__DOT__instruction_decode 
                                            >> 0x15U)) 
                                  == (IData)(vlTOPp->mips_cpu_bus__DOT__write_register_memory))) 
                              & (IData)(vlTOPp->mips_cpu_bus__DOT__register_write_memory))));
        vcdp->chgBit(c+1057,((((0U != (0x1fU & (vlTOPp->mips_cpu_bus__DOT__instruction_decode 
                                                >> 0x10U))) 
                               & ((0x1fU & (vlTOPp->mips_cpu_bus__DOT__instruction_decode 
                                            >> 0x10U)) 
                                  == (IData)(vlTOPp->mips_cpu_bus__DOT__write_register_memory))) 
                              & (IData)(vlTOPp->mips_cpu_bus__DOT__register_write_memory))));
    }
}

void MIPS_Bus_TB::traceChgThis__16(MIPS_Bus_TB__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    MIPS_Bus_TB* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
        vcdp->chgBit(c+1065,(vlTOPp->mips_cpu_bus__DOT__internal_clk));
        vcdp->chgBit(c+1073,(vlTOPp->mips_cpu_bus__DOT__STALL));
        vcdp->chgBus(c+1081,(vlTOPp->mips_cpu_bus__DOT__instruction_decode),32);
        vcdp->chgBus(c+1089,((0x3fU & (vlTOPp->mips_cpu_bus__DOT__instruction_decode 
                                       >> 0x1aU))),6);
        vcdp->chgBus(c+1097,((0x1fU & (vlTOPp->mips_cpu_bus__DOT__instruction_decode 
                                       >> 0x15U))),5);
        vcdp->chgBus(c+1105,((0x1fU & (vlTOPp->mips_cpu_bus__DOT__instruction_decode 
                                       >> 0x10U))),5);
        vcdp->chgBus(c+1113,((0x1fU & (vlTOPp->mips_cpu_bus__DOT__instruction_decode 
                                       >> 0xbU))),5);
        vcdp->chgBus(c+1121,((0xffffU & vlTOPp->mips_cpu_bus__DOT__instruction_decode)),16);
        vcdp->chgBus(c+1129,((0x3ffffffU & vlTOPp->mips_cpu_bus__DOT__instruction_decode)),26);
        vcdp->chgBus(c+1137,(vlTOPp->mips_cpu_bus__DOT__read_data_writeback),32);
        vcdp->chgBit(c+1145,(vlTOPp->mips_cpu_bus__DOT__data_read_write));
        vcdp->chgBit(c+1153,((1U & (~ (IData)(vlTOPp->mips_cpu_bus__DOT__internal_clk)))));
    }
}

void MIPS_Bus_TB::traceChgThis__17(MIPS_Bus_TB__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    MIPS_Bus_TB* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
        vcdp->chgBus(c+1161,(vlTOPp->mips_cpu_bus__DOT__register_file__DOT__LO_reg),32);
        vcdp->chgBus(c+1169,(vlTOPp->mips_cpu_bus__DOT__register_file__DOT__HI_reg),32);
    }
}

void MIPS_Bus_TB::traceChgThis__18(MIPS_Bus_TB__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    MIPS_Bus_TB* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
        vcdp->chgBit(c+1177,(vlTOPp->mips_cpu_bus__DOT__memory_to_register_execute));
        vcdp->chgBit(c+1185,(vlTOPp->mips_cpu_bus__DOT__memory_write_execute));
        vcdp->chgBit(c+1193,(vlTOPp->mips_cpu_bus__DOT__HI_register_write_execute));
        vcdp->chgBit(c+1201,(vlTOPp->mips_cpu_bus__DOT__LO_register_write_execute));
        vcdp->chgBit(c+1209,(vlTOPp->mips_cpu_bus__DOT__memory_to_register_memory));
        vcdp->chgBit(c+1217,(vlTOPp->mips_cpu_bus__DOT__memory_write_memory));
        vcdp->chgBit(c+1225,(vlTOPp->mips_cpu_bus__DOT__HI_register_write_memory));
        vcdp->chgBit(c+1233,(vlTOPp->mips_cpu_bus__DOT__LO_register_write_memory));
        vcdp->chgBus(c+1241,(vlTOPp->mips_cpu_bus__DOT__ALU_HI_output_memory),32);
        vcdp->chgBus(c+1249,(vlTOPp->mips_cpu_bus__DOT__ALU_LO_output_memory),32);
        vcdp->chgBit(c+1257,(vlTOPp->mips_cpu_bus__DOT__HI_register_write_writeback));
        vcdp->chgBit(c+1265,(vlTOPp->mips_cpu_bus__DOT__LO_register_write_writeback));
        vcdp->chgBus(c+1273,(vlTOPp->mips_cpu_bus__DOT__ALU_HI_output_writeback),32);
        vcdp->chgBus(c+1281,(vlTOPp->mips_cpu_bus__DOT__ALU_LO_output_writeback),32);
    }
}

void MIPS_Bus_TB::traceChgThis__19(MIPS_Bus_TB__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    MIPS_Bus_TB* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
        vcdp->chgBit(c+1289,(vlTOPp->clk));
        vcdp->chgBit(c+1297,(vlTOPp->reset));
        vcdp->chgBit(c+1305,(vlTOPp->active));
        vcdp->chgBus(c+1313,(vlTOPp->register_v0),32);
        vcdp->chgBus(c+1321,(vlTOPp->address),32);
        vcdp->chgBit(c+1329,(vlTOPp->write));
        vcdp->chgBit(c+1337,(vlTOPp->read));
        vcdp->chgBit(c+1345,(vlTOPp->waitrequest));
        vcdp->chgBus(c+1353,(vlTOPp->writedata),32);
        vcdp->chgBus(c+1361,(vlTOPp->byteenable),4);
        vcdp->chgBus(c+1369,(vlTOPp->readdata),32);
    }
}
