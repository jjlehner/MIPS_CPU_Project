// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "MIPS_Harvard_TB__Syms.h"


//======================

void MIPS_Harvard_TB::traceChg(VerilatedVcd* vcdp, void* userthis, uint32_t code) {
    // Callback from vcd->dump()
    MIPS_Harvard_TB* t = (MIPS_Harvard_TB*)userthis;
    MIPS_Harvard_TB__Syms* __restrict vlSymsp = t->__VlSymsp;  // Setup global symbol table
    if (vlSymsp->getClearActivity()) {
        t->traceChgThis(vlSymsp, vcdp, code);
    }
}

//======================


void MIPS_Harvard_TB::traceChgThis(MIPS_Harvard_TB__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    MIPS_Harvard_TB* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
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
                                              >> 5U))))) {
            vlTOPp->traceChgThis__3(vlSymsp, vcdp, code);
        }
        if (VL_UNLIKELY((1U & (((vlTOPp->__Vm_traceActivity 
                                 | (vlTOPp->__Vm_traceActivity 
                                    >> 3U)) | (vlTOPp->__Vm_traceActivity 
                                               >> 4U)) 
                               | (vlTOPp->__Vm_traceActivity 
                                  >> 5U))))) {
            vlTOPp->traceChgThis__4(vlSymsp, vcdp, code);
        }
        if (VL_UNLIKELY((1U & (vlTOPp->__Vm_traceActivity 
                               | (vlTOPp->__Vm_traceActivity 
                                  >> 4U))))) {
            vlTOPp->traceChgThis__5(vlSymsp, vcdp, code);
        }
        if (VL_UNLIKELY((1U & (vlTOPp->__Vm_traceActivity 
                               | (vlTOPp->__Vm_traceActivity 
                                  >> 5U))))) {
            vlTOPp->traceChgThis__6(vlSymsp, vcdp, code);
        }
        if (VL_UNLIKELY((2U & vlTOPp->__Vm_traceActivity))) {
            vlTOPp->traceChgThis__7(vlSymsp, vcdp, code);
        }
        if (VL_UNLIKELY((4U & vlTOPp->__Vm_traceActivity))) {
            vlTOPp->traceChgThis__8(vlSymsp, vcdp, code);
        }
        if (VL_UNLIKELY((1U & ((vlTOPp->__Vm_traceActivity 
                                >> 2U) | (vlTOPp->__Vm_traceActivity 
                                          >> 4U))))) {
            vlTOPp->traceChgThis__9(vlSymsp, vcdp, code);
        }
        if (VL_UNLIKELY((8U & vlTOPp->__Vm_traceActivity))) {
            vlTOPp->traceChgThis__10(vlSymsp, vcdp, code);
        }
        if (VL_UNLIKELY((0x10U & vlTOPp->__Vm_traceActivity))) {
            vlTOPp->traceChgThis__11(vlSymsp, vcdp, code);
        }
        vlTOPp->traceChgThis__12(vlSymsp, vcdp, code);
    }
    // Final
    vlTOPp->__Vm_traceActivity = 0U;
}

void MIPS_Harvard_TB::traceChgThis__2(MIPS_Harvard_TB__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    MIPS_Harvard_TB* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
        vcdp->chgBus(c+1,(((vlTOPp->mips_cpu_harvard__DOT__sign_imm_decode 
                            << 2U) + vlTOPp->mips_cpu_harvard__DOT__program_counter_plus_four_decode)),32);
        vcdp->chgBus(c+9,((vlTOPp->mips_cpu_harvard__DOT__sign_imm_decode 
                           << 2U)),32);
        vcdp->chgBus(c+17,(vlTOPp->mips_cpu_harvard__DOT__sign_imm_decode),32);
    }
}

void MIPS_Harvard_TB::traceChgThis__3(MIPS_Harvard_TB__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    MIPS_Harvard_TB* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
        vcdp->chgBus(c+25,(((IData)(vlTOPp->mips_cpu_harvard__DOT__program_counter_src_decode)
                             ? ((vlTOPp->mips_cpu_harvard__DOT__sign_imm_decode 
                                 << 2U) + vlTOPp->mips_cpu_harvard__DOT__program_counter_plus_four_decode)
                             : ((IData)(4U) + vlTOPp->mips_cpu_harvard__DOT__program_counter_fetch))),32);
    }
}

void MIPS_Harvard_TB::traceChgThis__4(MIPS_Harvard_TB__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    MIPS_Harvard_TB* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
        vcdp->chgBus(c+33,(((IData)(vlTOPp->mips_cpu_harvard__DOT__using_HI_LO_decode)
                             ? vlTOPp->mips_cpu_harvard__DOT__register_file__DOT__LO_reg
                             : vlTOPp->mips_cpu_harvard__DOT__register_file_output_A_decode)),32);
        vcdp->chgBus(c+41,(((IData)(vlTOPp->mips_cpu_harvard__DOT__using_HI_LO_decode)
                             ? vlTOPp->mips_cpu_harvard__DOT__register_file__DOT__HI_reg
                             : vlTOPp->mips_cpu_harvard__DOT__register_file_output_B_decode)),32);
    }
}

void MIPS_Harvard_TB::traceChgThis__5(MIPS_Harvard_TB__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    MIPS_Harvard_TB* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
        vcdp->chgBit(c+49,(vlTOPp->mips_cpu_harvard__DOT__register_write_decode));
        vcdp->chgBit(c+57,(vlTOPp->mips_cpu_harvard__DOT__memory_to_register_decode));
        vcdp->chgBit(c+65,(vlTOPp->mips_cpu_harvard__DOT__memory_write_decode));
        vcdp->chgBus(c+73,(vlTOPp->mips_cpu_harvard__DOT__ALU_src_B_decode),2);
        vcdp->chgBus(c+81,(vlTOPp->mips_cpu_harvard__DOT__register_destination_decode),2);
        vcdp->chgBit(c+89,(vlTOPp->mips_cpu_harvard__DOT__branch_decode));
        vcdp->chgBus(c+97,(vlTOPp->mips_cpu_harvard__DOT__ALU_function_decode),6);
        vcdp->chgBit(c+105,(vlTOPp->mips_cpu_harvard__DOT__program_counter_multiplexer_jump_decode));
        vcdp->chgBit(c+113,(vlTOPp->mips_cpu_harvard__DOT__using_HI_LO_decode));
        vcdp->chgBit(c+121,(vlTOPp->mips_cpu_harvard__DOT__j_instruction_decode));
        vcdp->chgBit(c+129,(vlTOPp->mips_cpu_harvard__DOT__HI_register_write_decode));
        vcdp->chgBit(c+137,(vlTOPp->mips_cpu_harvard__DOT__LO_register_write_decode));
        vcdp->chgBus(c+145,(vlTOPp->mips_cpu_harvard__DOT__write_register_execute),5);
        vcdp->chgBus(c+153,(vlTOPp->mips_cpu_harvard__DOT__src_A_ALU_execute),32);
        vcdp->chgBus(c+161,(vlTOPp->mips_cpu_harvard__DOT__src_B_ALU_execute),32);
        vcdp->chgBus(c+169,(vlTOPp->mips_cpu_harvard__DOT__ALU_output_execute),32);
        vcdp->chgBus(c+177,(vlTOPp->mips_cpu_harvard__DOT__ALU_HI_output_execute),32);
        vcdp->chgBus(c+185,(vlTOPp->mips_cpu_harvard__DOT__ALU_LO_output_execute),32);
        vcdp->chgBus(c+193,(vlTOPp->mips_cpu_harvard__DOT__result_writeback),32);
        vcdp->chgBit(c+201,(vlTOPp->mips_cpu_harvard__DOT__stall_fetch));
        vcdp->chgBit(c+209,(vlTOPp->mips_cpu_harvard__DOT__stall_decode));
        vcdp->chgBit(c+217,(vlTOPp->mips_cpu_harvard__DOT__flush_execute_register));
        vcdp->chgBus(c+225,(vlTOPp->mips_cpu_harvard__DOT__forward_A_execute),3);
        vcdp->chgBus(c+233,(vlTOPp->mips_cpu_harvard__DOT__forward_B_execute),3);
        vcdp->chgBus(c+241,(vlTOPp->mips_cpu_harvard__DOT__control_unit__DOT__op),6);
        vcdp->chgBus(c+249,(vlTOPp->mips_cpu_harvard__DOT__control_unit__DOT__rt),5);
        vcdp->chgBus(c+257,(vlTOPp->mips_cpu_harvard__DOT__control_unit__DOT__funct),6);
        vcdp->chgBus(c+265,(vlTOPp->mips_cpu_harvard__DOT__alu_input_mux__DOT__src_mux_input_0),32);
        vcdp->chgBus(c+273,((0x1fU & (vlTOPp->mips_cpu_harvard__DOT__src_A_ALU_execute 
                                      >> 6U))),5);
        vcdp->chgQuad(c+281,((((QData)((IData)(VL_NEGATE_I((IData)(
                                                                   (1U 
                                                                    & (vlTOPp->mips_cpu_harvard__DOT__src_A_ALU_execute 
                                                                       >> 0x1fU)))))) 
                               << 0x20U) | (QData)((IData)(vlTOPp->mips_cpu_harvard__DOT__src_A_ALU_execute)))),64);
        vcdp->chgQuad(c+297,((((QData)((IData)(VL_NEGATE_I((IData)(
                                                                   (1U 
                                                                    & (vlTOPp->mips_cpu_harvard__DOT__src_B_ALU_execute 
                                                                       >> 0x1fU)))))) 
                               << 0x20U) | (QData)((IData)(vlTOPp->mips_cpu_harvard__DOT__src_B_ALU_execute)))),64);
        vcdp->chgQuad(c+313,((QData)((IData)(vlTOPp->mips_cpu_harvard__DOT__src_A_ALU_execute))),64);
        vcdp->chgQuad(c+329,((QData)((IData)(vlTOPp->mips_cpu_harvard__DOT__src_B_ALU_execute))),64);
        vcdp->chgQuad(c+345,(vlTOPp->mips_cpu_harvard__DOT__alu__DOT__ALU_HI_LO_output),64);
        vcdp->chgBit(c+361,(vlTOPp->mips_cpu_harvard__DOT__hazard_unit__DOT__lwstall));
        vcdp->chgBit(c+369,(vlTOPp->mips_cpu_harvard__DOT__hazard_unit__DOT__branchstall));
    }
}

void MIPS_Harvard_TB::traceChgThis__6(MIPS_Harvard_TB__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    MIPS_Harvard_TB* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
        vcdp->chgBus(c+377,(vlTOPp->mips_cpu_harvard__DOT__program_counter_prime),32);
        vcdp->chgBit(c+385,(vlTOPp->mips_cpu_harvard__DOT__program_counter_src_decode));
        vcdp->chgBit(c+393,(vlTOPp->mips_cpu_harvard__DOT__equal_decode));
        vcdp->chgBus(c+401,(vlTOPp->mips_cpu_harvard__DOT__register_file_output_A_decode),32);
        vcdp->chgBus(c+409,(vlTOPp->mips_cpu_harvard__DOT__register_file_output_B_decode),32);
        vcdp->chgBus(c+417,(vlTOPp->mips_cpu_harvard__DOT__comparator_1),32);
        vcdp->chgBus(c+425,(vlTOPp->mips_cpu_harvard__DOT__comparator_2),32);
    }
}

void MIPS_Harvard_TB::traceChgThis__7(MIPS_Harvard_TB__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    MIPS_Harvard_TB* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
        vcdp->chgBit(c+433,(vlTOPp->mips_cpu_harvard__DOT__internal_clk));
        vcdp->chgBit(c+441,((1U & (~ (IData)(vlTOPp->mips_cpu_harvard__DOT__internal_clk)))));
    }
}

void MIPS_Harvard_TB::traceChgThis__8(MIPS_Harvard_TB__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    MIPS_Harvard_TB* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
        vcdp->chgBus(c+449,(vlTOPp->mips_cpu_harvard__DOT__program_counter_fetch),32);
        vcdp->chgBus(c+457,(((IData)(4U) + vlTOPp->mips_cpu_harvard__DOT__program_counter_fetch)),32);
        vcdp->chgBit(c+465,(vlTOPp->mips_cpu_harvard__DOT__HALT_fetch));
        vcdp->chgBit(c+473,(vlTOPp->mips_cpu_harvard__DOT__HALT_decode));
        vcdp->chgBus(c+481,(vlTOPp->mips_cpu_harvard__DOT__instruction_decode),32);
        vcdp->chgBus(c+489,(vlTOPp->mips_cpu_harvard__DOT__program_counter_plus_four_decode),32);
        vcdp->chgBus(c+497,((0x3fU & (vlTOPp->mips_cpu_harvard__DOT__instruction_decode 
                                      >> 0x1aU))),6);
        vcdp->chgBus(c+505,((0x1fU & (vlTOPp->mips_cpu_harvard__DOT__instruction_decode 
                                      >> 0x15U))),5);
        vcdp->chgBus(c+513,((0x1fU & (vlTOPp->mips_cpu_harvard__DOT__instruction_decode 
                                      >> 0x10U))),5);
        vcdp->chgBus(c+521,((0x1fU & (vlTOPp->mips_cpu_harvard__DOT__instruction_decode 
                                      >> 0xbU))),5);
        vcdp->chgBus(c+529,((0xffffU & vlTOPp->mips_cpu_harvard__DOT__instruction_decode)),16);
        vcdp->chgBus(c+537,((0x3ffffffU & vlTOPp->mips_cpu_harvard__DOT__instruction_decode)),26);
        vcdp->chgBus(c+545,(((0xf0000000U & vlTOPp->mips_cpu_harvard__DOT__program_counter_plus_four_decode) 
                             | (0xffffffcU & (vlTOPp->mips_cpu_harvard__DOT__instruction_decode 
                                              << 2U)))),32);
        vcdp->chgBus(c+553,(vlTOPp->mips_cpu_harvard__DOT__register_destination_execute),2);
        vcdp->chgBit(c+561,(vlTOPp->mips_cpu_harvard__DOT__memory_to_register_execute));
        vcdp->chgBit(c+569,(vlTOPp->mips_cpu_harvard__DOT__memory_write_execute));
        vcdp->chgBus(c+577,(vlTOPp->mips_cpu_harvard__DOT__ALU_src_B_execute),2);
        vcdp->chgBus(c+585,(vlTOPp->mips_cpu_harvard__DOT__ALU_function_execute),6);
        vcdp->chgBit(c+593,(vlTOPp->mips_cpu_harvard__DOT__program_counter_multiplexer_jump_execute));
        vcdp->chgBit(c+601,(vlTOPp->mips_cpu_harvard__DOT__j_instruction_execute));
        vcdp->chgBit(c+609,(vlTOPp->mips_cpu_harvard__DOT__using_HI_LO_execute));
        vcdp->chgBit(c+617,(vlTOPp->mips_cpu_harvard__DOT__HALT_execute));
        vcdp->chgBus(c+625,(vlTOPp->mips_cpu_harvard__DOT__src_A_execute),32);
        vcdp->chgBus(c+633,(vlTOPp->mips_cpu_harvard__DOT__src_B_execute),32);
        vcdp->chgBus(c+641,(vlTOPp->mips_cpu_harvard__DOT__Rs_execute),5);
        vcdp->chgBus(c+649,(vlTOPp->mips_cpu_harvard__DOT__Rt_execute),5);
        vcdp->chgBus(c+657,(vlTOPp->mips_cpu_harvard__DOT__Rd_execute),5);
        vcdp->chgBus(c+665,(vlTOPp->mips_cpu_harvard__DOT__sign_imm_execute),32);
        vcdp->chgBus(c+673,(((IData)(4U) + vlTOPp->mips_cpu_harvard__DOT__program_counter_plus_four_execute)),32);
        vcdp->chgBus(c+681,(vlTOPp->mips_cpu_harvard__DOT__program_counter_plus_four_execute),32);
        vcdp->chgBus(c+689,(vlTOPp->mips_cpu_harvard__DOT__j_program_counter_execute),32);
        vcdp->chgBit(c+697,(vlTOPp->mips_cpu_harvard__DOT__memory_to_register_memory));
        vcdp->chgBit(c+705,(vlTOPp->mips_cpu_harvard__DOT__memory_write_memory));
        vcdp->chgBit(c+713,(vlTOPp->mips_cpu_harvard__DOT__program_counter_multiplexer_jump_memory));
        vcdp->chgBit(c+721,(vlTOPp->mips_cpu_harvard__DOT__j_instruction_memory));
        vcdp->chgBit(c+729,(vlTOPp->mips_cpu_harvard__DOT__HALT_memory));
        vcdp->chgBus(c+737,(vlTOPp->mips_cpu_harvard__DOT__ALU_output_memory),32);
        vcdp->chgBus(c+745,(vlTOPp->mips_cpu_harvard__DOT__write_data_memory),32);
        vcdp->chgBus(c+753,(((IData)(vlTOPp->mips_cpu_harvard__DOT__j_instruction_memory)
                              ? vlTOPp->mips_cpu_harvard__DOT__j_program_counter_execute
                              : vlTOPp->mips_cpu_harvard__DOT__ALU_output_memory)),32);
        vcdp->chgBus(c+761,(vlTOPp->mips_cpu_harvard__DOT__j_program_counter_memory),32);
        vcdp->chgBit(c+769,(vlTOPp->mips_cpu_harvard__DOT__memory_to_register_writeback));
        vcdp->chgBit(c+777,(vlTOPp->mips_cpu_harvard__DOT__HALT_writeback));
        vcdp->chgBus(c+785,(vlTOPp->mips_cpu_harvard__DOT__ALU_output_writeback),32);
        vcdp->chgBus(c+793,(vlTOPp->mips_cpu_harvard__DOT__read_data_writeback),32);
    }
}

void MIPS_Harvard_TB::traceChgThis__9(MIPS_Harvard_TB__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    MIPS_Harvard_TB* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
        vcdp->chgBit(c+801,((((0U != (0x1fU & (vlTOPp->mips_cpu_harvard__DOT__instruction_decode 
                                               >> 0x15U))) 
                              & ((0x1fU & (vlTOPp->mips_cpu_harvard__DOT__instruction_decode 
                                           >> 0x15U)) 
                                 == (IData)(vlTOPp->mips_cpu_harvard__DOT__write_register_memory))) 
                             & (IData)(vlTOPp->mips_cpu_harvard__DOT__register_write_memory))));
        vcdp->chgBit(c+809,((((0U != (0x1fU & (vlTOPp->mips_cpu_harvard__DOT__instruction_decode 
                                               >> 0x10U))) 
                              & ((0x1fU & (vlTOPp->mips_cpu_harvard__DOT__instruction_decode 
                                           >> 0x10U)) 
                                 == (IData)(vlTOPp->mips_cpu_harvard__DOT__write_register_memory))) 
                             & (IData)(vlTOPp->mips_cpu_harvard__DOT__register_write_memory))));
    }
}

void MIPS_Harvard_TB::traceChgThis__10(MIPS_Harvard_TB__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    MIPS_Harvard_TB* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
        vcdp->chgBus(c+817,(vlTOPp->mips_cpu_harvard__DOT__register_file__DOT__LO_reg),32);
        vcdp->chgBus(c+825,(vlTOPp->mips_cpu_harvard__DOT__register_file__DOT__HI_reg),32);
        vcdp->chgBus(c+833,(vlTOPp->mips_cpu_harvard__DOT__register_file__DOT__registers[0]),32);
        vcdp->chgBus(c+834,(vlTOPp->mips_cpu_harvard__DOT__register_file__DOT__registers[1]),32);
        vcdp->chgBus(c+835,(vlTOPp->mips_cpu_harvard__DOT__register_file__DOT__registers[2]),32);
        vcdp->chgBus(c+836,(vlTOPp->mips_cpu_harvard__DOT__register_file__DOT__registers[3]),32);
        vcdp->chgBus(c+837,(vlTOPp->mips_cpu_harvard__DOT__register_file__DOT__registers[4]),32);
        vcdp->chgBus(c+838,(vlTOPp->mips_cpu_harvard__DOT__register_file__DOT__registers[5]),32);
        vcdp->chgBus(c+839,(vlTOPp->mips_cpu_harvard__DOT__register_file__DOT__registers[6]),32);
        vcdp->chgBus(c+840,(vlTOPp->mips_cpu_harvard__DOT__register_file__DOT__registers[7]),32);
        vcdp->chgBus(c+841,(vlTOPp->mips_cpu_harvard__DOT__register_file__DOT__registers[8]),32);
        vcdp->chgBus(c+842,(vlTOPp->mips_cpu_harvard__DOT__register_file__DOT__registers[9]),32);
        vcdp->chgBus(c+843,(vlTOPp->mips_cpu_harvard__DOT__register_file__DOT__registers[10]),32);
        vcdp->chgBus(c+844,(vlTOPp->mips_cpu_harvard__DOT__register_file__DOT__registers[11]),32);
        vcdp->chgBus(c+845,(vlTOPp->mips_cpu_harvard__DOT__register_file__DOT__registers[12]),32);
        vcdp->chgBus(c+846,(vlTOPp->mips_cpu_harvard__DOT__register_file__DOT__registers[13]),32);
        vcdp->chgBus(c+847,(vlTOPp->mips_cpu_harvard__DOT__register_file__DOT__registers[14]),32);
        vcdp->chgBus(c+848,(vlTOPp->mips_cpu_harvard__DOT__register_file__DOT__registers[15]),32);
        vcdp->chgBus(c+849,(vlTOPp->mips_cpu_harvard__DOT__register_file__DOT__registers[16]),32);
        vcdp->chgBus(c+850,(vlTOPp->mips_cpu_harvard__DOT__register_file__DOT__registers[17]),32);
        vcdp->chgBus(c+851,(vlTOPp->mips_cpu_harvard__DOT__register_file__DOT__registers[18]),32);
        vcdp->chgBus(c+852,(vlTOPp->mips_cpu_harvard__DOT__register_file__DOT__registers[19]),32);
        vcdp->chgBus(c+853,(vlTOPp->mips_cpu_harvard__DOT__register_file__DOT__registers[20]),32);
        vcdp->chgBus(c+854,(vlTOPp->mips_cpu_harvard__DOT__register_file__DOT__registers[21]),32);
        vcdp->chgBus(c+855,(vlTOPp->mips_cpu_harvard__DOT__register_file__DOT__registers[22]),32);
        vcdp->chgBus(c+856,(vlTOPp->mips_cpu_harvard__DOT__register_file__DOT__registers[23]),32);
        vcdp->chgBus(c+857,(vlTOPp->mips_cpu_harvard__DOT__register_file__DOT__registers[24]),32);
        vcdp->chgBus(c+858,(vlTOPp->mips_cpu_harvard__DOT__register_file__DOT__registers[25]),32);
        vcdp->chgBus(c+859,(vlTOPp->mips_cpu_harvard__DOT__register_file__DOT__registers[26]),32);
        vcdp->chgBus(c+860,(vlTOPp->mips_cpu_harvard__DOT__register_file__DOT__registers[27]),32);
        vcdp->chgBus(c+861,(vlTOPp->mips_cpu_harvard__DOT__register_file__DOT__registers[28]),32);
        vcdp->chgBus(c+862,(vlTOPp->mips_cpu_harvard__DOT__register_file__DOT__registers[29]),32);
        vcdp->chgBus(c+863,(vlTOPp->mips_cpu_harvard__DOT__register_file__DOT__registers[30]),32);
        vcdp->chgBus(c+864,(vlTOPp->mips_cpu_harvard__DOT__register_file__DOT__registers[31]),32);
    }
}

void MIPS_Harvard_TB::traceChgThis__11(MIPS_Harvard_TB__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    MIPS_Harvard_TB* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
        vcdp->chgBit(c+1089,(vlTOPp->mips_cpu_harvard__DOT__HI_register_write_execute));
        vcdp->chgBit(c+1097,(vlTOPp->mips_cpu_harvard__DOT__LO_register_write_execute));
        vcdp->chgBit(c+1105,(vlTOPp->mips_cpu_harvard__DOT__register_write_execute));
        vcdp->chgBit(c+1113,(vlTOPp->mips_cpu_harvard__DOT__register_write_memory));
        vcdp->chgBus(c+1121,(vlTOPp->mips_cpu_harvard__DOT__write_register_memory),5);
        vcdp->chgBit(c+1129,(vlTOPp->mips_cpu_harvard__DOT__HI_register_write_memory));
        vcdp->chgBit(c+1137,(vlTOPp->mips_cpu_harvard__DOT__LO_register_write_memory));
        vcdp->chgBus(c+1145,(vlTOPp->mips_cpu_harvard__DOT__ALU_HI_output_memory),32);
        vcdp->chgBus(c+1153,(vlTOPp->mips_cpu_harvard__DOT__ALU_LO_output_memory),32);
        vcdp->chgBit(c+1161,(vlTOPp->mips_cpu_harvard__DOT__register_write_writeback));
        vcdp->chgBit(c+1169,(vlTOPp->mips_cpu_harvard__DOT__HI_register_write_writeback));
        vcdp->chgBit(c+1177,(vlTOPp->mips_cpu_harvard__DOT__LO_register_write_writeback));
        vcdp->chgBus(c+1185,(vlTOPp->mips_cpu_harvard__DOT__write_register_writeback),5);
        vcdp->chgBus(c+1193,(vlTOPp->mips_cpu_harvard__DOT__ALU_HI_output_writeback),32);
        vcdp->chgBus(c+1201,(vlTOPp->mips_cpu_harvard__DOT__ALU_LO_output_writeback),32);
    }
}

void MIPS_Harvard_TB::traceChgThis__12(MIPS_Harvard_TB__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    MIPS_Harvard_TB* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
        vcdp->chgBit(c+1209,(vlTOPp->clk));
        vcdp->chgBit(c+1217,(vlTOPp->reset));
        vcdp->chgBit(c+1225,(vlTOPp->active));
        vcdp->chgBus(c+1233,(vlTOPp->register_v0),32);
        vcdp->chgBit(c+1241,(vlTOPp->clk_enable));
        vcdp->chgBus(c+1249,(vlTOPp->instr_address),32);
        vcdp->chgBus(c+1257,(vlTOPp->instr_readdata),32);
        vcdp->chgBus(c+1265,(vlTOPp->data_address),32);
        vcdp->chgBit(c+1273,(vlTOPp->data_write));
        vcdp->chgBit(c+1281,(vlTOPp->data_read));
        vcdp->chgBus(c+1289,(vlTOPp->data_writedata),32);
        vcdp->chgBus(c+1297,(vlTOPp->data_readdata),32);
    }
}
