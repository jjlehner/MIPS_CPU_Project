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
                                  >> 1U))))) {
            vlTOPp->traceChgThis__2(vlSymsp, vcdp, code);
        }
        if (VL_UNLIKELY((1U & (vlTOPp->__Vm_traceActivity 
                               | (vlTOPp->__Vm_traceActivity 
                                  >> 2U))))) {
            vlTOPp->traceChgThis__3(vlSymsp, vcdp, code);
        }
        if (VL_UNLIKELY((1U & ((vlTOPp->__Vm_traceActivity 
                                | (vlTOPp->__Vm_traceActivity 
                                   >> 2U)) | (vlTOPp->__Vm_traceActivity 
                                              >> 4U))))) {
            vlTOPp->traceChgThis__4(vlSymsp, vcdp, code);
        }
        if (VL_UNLIKELY((1U & (vlTOPp->__Vm_traceActivity 
                               | (vlTOPp->__Vm_traceActivity 
                                  >> 4U))))) {
            vlTOPp->traceChgThis__5(vlSymsp, vcdp, code);
        }
        if (VL_UNLIKELY((4U & vlTOPp->__Vm_traceActivity))) {
            vlTOPp->traceChgThis__6(vlSymsp, vcdp, code);
        }
        if (VL_UNLIKELY((1U & ((vlTOPp->__Vm_traceActivity 
                                >> 2U) | (vlTOPp->__Vm_traceActivity 
                                          >> 3U))))) {
            vlTOPp->traceChgThis__7(vlSymsp, vcdp, code);
        }
        if (VL_UNLIKELY((8U & vlTOPp->__Vm_traceActivity))) {
            vlTOPp->traceChgThis__8(vlSymsp, vcdp, code);
        }
        vlTOPp->traceChgThis__9(vlSymsp, vcdp, code);
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
        vcdp->chgBit(c+1,(vlTOPp->mips_cpu__DOT__internal_clk));
        vcdp->chgBit(c+9,((1U & (~ (IData)(vlTOPp->mips_cpu__DOT__internal_clk)))));
    }
}

void MIPS_Harvard_TB::traceChgThis__3(MIPS_Harvard_TB__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    MIPS_Harvard_TB* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
        vcdp->chgBit(c+17,(vlTOPp->mips_cpu__DOT__register_write_decode));
        vcdp->chgBit(c+25,(vlTOPp->mips_cpu__DOT__memory_to_register_decode));
        vcdp->chgBit(c+33,(vlTOPp->mips_cpu__DOT__memory_write_decode));
        vcdp->chgBit(c+41,(vlTOPp->mips_cpu__DOT__ALU_src_B_decode));
        vcdp->chgBit(c+49,(vlTOPp->mips_cpu__DOT__register_destination_decode));
        vcdp->chgBit(c+57,(vlTOPp->mips_cpu__DOT__branch_decode));
        vcdp->chgBit(c+65,(vlTOPp->mips_cpu__DOT__hi_lo_register_write_decode));
        vcdp->chgBus(c+73,(vlTOPp->mips_cpu__DOT__ALU_function_decode),6);
        vcdp->chgBus(c+81,(((vlTOPp->mips_cpu__DOT__sign_imm_decode 
                             << 2U) + vlTOPp->mips_cpu__DOT__program_counter_plus_four_decode)),32);
        vcdp->chgBus(c+89,((vlTOPp->mips_cpu__DOT__sign_imm_decode 
                            << 2U)),32);
        vcdp->chgBus(c+97,(vlTOPp->mips_cpu__DOT__sign_imm_decode),32);
        vcdp->chgBus(c+105,(vlTOPp->mips_cpu__DOT__write_register_execute),5);
        vcdp->chgBus(c+113,(vlTOPp->mips_cpu__DOT__source_A_ALU_execute),32);
        vcdp->chgBus(c+121,(vlTOPp->mips_cpu__DOT__source_B_ALU_execute),32);
        vcdp->chgBus(c+129,(vlTOPp->mips_cpu__DOT__write_data_execute),32);
        vcdp->chgBus(c+137,(vlTOPp->mips_cpu__DOT__ALU_output_execute),32);
        vcdp->chgBus(c+145,(vlTOPp->mips_cpu__DOT__ALU_HI_output_execute),32);
        vcdp->chgBus(c+153,(vlTOPp->mips_cpu__DOT__ALU_LO_output_execute),32);
        vcdp->chgBus(c+161,(vlTOPp->mips_cpu__DOT__result_writeback),32);
        vcdp->chgBit(c+169,(vlTOPp->mips_cpu__DOT__stall_fetch));
        vcdp->chgBit(c+177,(vlTOPp->mips_cpu__DOT__stall_decode));
        vcdp->chgBit(c+185,(vlTOPp->mips_cpu__DOT__flush_execute_register));
        vcdp->chgBus(c+193,(vlTOPp->mips_cpu__DOT__forward_A_execute),2);
        vcdp->chgBus(c+201,(vlTOPp->mips_cpu__DOT__forward_B_execute),2);
        vcdp->chgBus(c+209,(vlTOPp->mips_cpu__DOT__control_unit__DOT__op),6);
        vcdp->chgBus(c+217,(vlTOPp->mips_cpu__DOT__control_unit__DOT__funct),6);
        vcdp->chgBus(c+225,((0x1fU & (vlTOPp->mips_cpu__DOT__source_A_ALU_execute 
                                      >> 6U))),5);
        vcdp->chgQuad(c+233,((((QData)((IData)(VL_NEGATE_I((IData)(
                                                                   (1U 
                                                                    & (vlTOPp->mips_cpu__DOT__source_A_ALU_execute 
                                                                       >> 0x1fU)))))) 
                               << 0x20U) | (QData)((IData)(vlTOPp->mips_cpu__DOT__source_A_ALU_execute)))),64);
        vcdp->chgQuad(c+249,((((QData)((IData)(VL_NEGATE_I((IData)(
                                                                   (1U 
                                                                    & (vlTOPp->mips_cpu__DOT__source_B_ALU_execute 
                                                                       >> 0x1fU)))))) 
                               << 0x20U) | (QData)((IData)(vlTOPp->mips_cpu__DOT__source_B_ALU_execute)))),64);
        vcdp->chgQuad(c+265,((QData)((IData)(vlTOPp->mips_cpu__DOT__source_A_ALU_execute))),64);
        vcdp->chgQuad(c+281,((QData)((IData)(vlTOPp->mips_cpu__DOT__source_B_ALU_execute))),64);
        vcdp->chgQuad(c+297,(vlTOPp->mips_cpu__DOT__alu__DOT__ALU_HI_LO_output),64);
        vcdp->chgBit(c+313,(vlTOPp->mips_cpu__DOT__hazard_unit__DOT__lwstall));
        vcdp->chgBit(c+321,(vlTOPp->mips_cpu__DOT__hazard_unit__DOT__branchstall));
    }
}

void MIPS_Harvard_TB::traceChgThis__4(MIPS_Harvard_TB__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    MIPS_Harvard_TB* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
        vcdp->chgBus(c+329,(((IData)(vlTOPp->mips_cpu__DOT__program_counter_source_decode)
                              ? ((vlTOPp->mips_cpu__DOT__sign_imm_decode 
                                  << 2U) + vlTOPp->mips_cpu__DOT__program_counter_plus_four_decode)
                              : ((IData)(4U) + vlTOPp->mips_cpu__DOT__program_counter_fetch))),32);
        vcdp->chgBit(c+337,((((((0U != (0x1fU & (vlTOPp->mips_cpu__DOT__instruction_decode 
                                                 >> 0x15U))) 
                                & ((0x1fU & (vlTOPp->mips_cpu__DOT__instruction_decode 
                                             >> 0x15U)) 
                                   == (IData)(vlTOPp->mips_cpu__DOT__write_register_memory))) 
                               & (IData)(vlTOPp->mips_cpu__DOT__register_write_memory))
                               ? vlTOPp->mips_cpu__DOT__ALU_output_memory
                               : vlTOPp->mips_cpu__DOT__register_file_output_A_decode) 
                             == ((((0U != (0x1fU & 
                                           (vlTOPp->mips_cpu__DOT__instruction_decode 
                                            >> 0x10U))) 
                                   & ((0x1fU & (vlTOPp->mips_cpu__DOT__instruction_decode 
                                                >> 0x10U)) 
                                      == (IData)(vlTOPp->mips_cpu__DOT__write_register_memory))) 
                                  & (IData)(vlTOPp->mips_cpu__DOT__register_write_memory))
                                  ? vlTOPp->mips_cpu__DOT__ALU_output_memory
                                  : vlTOPp->mips_cpu__DOT__register_file_output_B_decode))));
        vcdp->chgBus(c+345,(((((0U != (0x1fU & (vlTOPp->mips_cpu__DOT__instruction_decode 
                                                >> 0x15U))) 
                               & ((0x1fU & (vlTOPp->mips_cpu__DOT__instruction_decode 
                                            >> 0x15U)) 
                                  == (IData)(vlTOPp->mips_cpu__DOT__write_register_memory))) 
                              & (IData)(vlTOPp->mips_cpu__DOT__register_write_memory))
                              ? vlTOPp->mips_cpu__DOT__ALU_output_memory
                              : vlTOPp->mips_cpu__DOT__register_file_output_A_decode)),32);
        vcdp->chgBus(c+353,(((((0U != (0x1fU & (vlTOPp->mips_cpu__DOT__instruction_decode 
                                                >> 0x10U))) 
                               & ((0x1fU & (vlTOPp->mips_cpu__DOT__instruction_decode 
                                            >> 0x10U)) 
                                  == (IData)(vlTOPp->mips_cpu__DOT__write_register_memory))) 
                              & (IData)(vlTOPp->mips_cpu__DOT__register_write_memory))
                              ? vlTOPp->mips_cpu__DOT__ALU_output_memory
                              : vlTOPp->mips_cpu__DOT__register_file_output_B_decode)),32);
    }
}

void MIPS_Harvard_TB::traceChgThis__5(MIPS_Harvard_TB__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    MIPS_Harvard_TB* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
        vcdp->chgBit(c+361,(vlTOPp->mips_cpu__DOT__program_counter_source_decode));
        vcdp->chgBus(c+369,(vlTOPp->mips_cpu__DOT__register_file_output_A_decode),32);
        vcdp->chgBus(c+377,(vlTOPp->mips_cpu__DOT__register_file_output_B_decode),32);
    }
}

void MIPS_Harvard_TB::traceChgThis__6(MIPS_Harvard_TB__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    MIPS_Harvard_TB* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
        vcdp->chgBus(c+385,(vlTOPp->mips_cpu__DOT__program_counter_fetch),32);
        vcdp->chgBus(c+393,(((IData)(4U) + vlTOPp->mips_cpu__DOT__program_counter_fetch)),32);
        vcdp->chgBus(c+401,(vlTOPp->mips_cpu__DOT__instruction_decode),32);
        vcdp->chgBus(c+409,(vlTOPp->mips_cpu__DOT__program_counter_plus_four_decode),32);
        vcdp->chgBus(c+417,((0x1fU & (vlTOPp->mips_cpu__DOT__instruction_decode 
                                      >> 0x15U))),5);
        vcdp->chgBus(c+425,((0x1fU & (vlTOPp->mips_cpu__DOT__instruction_decode 
                                      >> 0x10U))),5);
        vcdp->chgBus(c+433,((0x1fU & (vlTOPp->mips_cpu__DOT__instruction_decode 
                                      >> 0xbU))),5);
        vcdp->chgBus(c+441,((0xffffU & vlTOPp->mips_cpu__DOT__instruction_decode)),16);
        vcdp->chgBit(c+449,(vlTOPp->mips_cpu__DOT__register_destination_execute));
        vcdp->chgBit(c+457,(vlTOPp->mips_cpu__DOT__memory_to_register_execute));
        vcdp->chgBit(c+465,(vlTOPp->mips_cpu__DOT__memory_write_execute));
        vcdp->chgBit(c+473,(vlTOPp->mips_cpu__DOT__ALU_src_B_execute));
        vcdp->chgBus(c+481,(vlTOPp->mips_cpu__DOT__ALU_function_execute),6);
        vcdp->chgBit(c+489,(vlTOPp->mips_cpu__DOT__hi_lo_register_write_execute));
        vcdp->chgBit(c+497,(vlTOPp->mips_cpu__DOT__register_write_execute));
        vcdp->chgBus(c+505,(vlTOPp->mips_cpu__DOT__register_file_output_A_execute),32);
        vcdp->chgBus(c+513,(vlTOPp->mips_cpu__DOT__register_file_output_B_execute),32);
        vcdp->chgBus(c+521,(vlTOPp->mips_cpu__DOT__Rs_execute),5);
        vcdp->chgBus(c+529,(vlTOPp->mips_cpu__DOT__Rt_execute),5);
        vcdp->chgBus(c+537,(vlTOPp->mips_cpu__DOT__Rd_execute),5);
        vcdp->chgBus(c+545,(vlTOPp->mips_cpu__DOT__sign_imm_execute),32);
        vcdp->chgBit(c+553,(vlTOPp->mips_cpu__DOT__register_write_memory));
        vcdp->chgBus(c+561,(vlTOPp->mips_cpu__DOT__write_register_memory),5);
        vcdp->chgBit(c+569,(vlTOPp->mips_cpu__DOT__memory_to_register_memory));
        vcdp->chgBit(c+577,(vlTOPp->mips_cpu__DOT__memory_write_memory));
        vcdp->chgBit(c+585,(vlTOPp->mips_cpu__DOT__hi_lo_register_write_memory));
        vcdp->chgBus(c+593,(vlTOPp->mips_cpu__DOT__ALU_output_memory),32);
        vcdp->chgBus(c+601,(vlTOPp->mips_cpu__DOT__ALU_HI_output_memory),32);
        vcdp->chgBus(c+609,(vlTOPp->mips_cpu__DOT__ALU_LO_output_memory),32);
        vcdp->chgBus(c+617,(vlTOPp->mips_cpu__DOT__write_data_memory),32);
        vcdp->chgBit(c+625,(vlTOPp->mips_cpu__DOT__register_write_writeback));
        vcdp->chgBit(c+633,(vlTOPp->mips_cpu__DOT__hi_lo_register_write_writeback));
        vcdp->chgBit(c+641,(vlTOPp->mips_cpu__DOT__memory_to_register_writeback));
        vcdp->chgBus(c+649,(vlTOPp->mips_cpu__DOT__write_register_writeback),5);
        vcdp->chgBus(c+657,(vlTOPp->mips_cpu__DOT__ALU_HI_output_writeback),32);
        vcdp->chgBus(c+665,(vlTOPp->mips_cpu__DOT__ALU_LO_output_writeback),32);
        vcdp->chgBus(c+673,(vlTOPp->mips_cpu__DOT__ALU_output_writeback),32);
        vcdp->chgBus(c+681,(vlTOPp->mips_cpu__DOT__read_data_writeback),32);
        vcdp->chgBit(c+689,((((0U != (0x1fU & (vlTOPp->mips_cpu__DOT__instruction_decode 
                                               >> 0x15U))) 
                              & ((0x1fU & (vlTOPp->mips_cpu__DOT__instruction_decode 
                                           >> 0x15U)) 
                                 == (IData)(vlTOPp->mips_cpu__DOT__write_register_memory))) 
                             & (IData)(vlTOPp->mips_cpu__DOT__register_write_memory))));
        vcdp->chgBit(c+697,((((0U != (0x1fU & (vlTOPp->mips_cpu__DOT__instruction_decode 
                                               >> 0x10U))) 
                              & ((0x1fU & (vlTOPp->mips_cpu__DOT__instruction_decode 
                                           >> 0x10U)) 
                                 == (IData)(vlTOPp->mips_cpu__DOT__write_register_memory))) 
                             & (IData)(vlTOPp->mips_cpu__DOT__register_write_memory))));
    }
}

void MIPS_Harvard_TB::traceChgThis__7(MIPS_Harvard_TB__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    MIPS_Harvard_TB* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
        vcdp->chgBus(c+705,(((0U != (0x1fU & (vlTOPp->mips_cpu__DOT__instruction_decode 
                                              >> 0x15U)))
                              ? vlTOPp->mips_cpu__DOT__register_file__DOT__registers
                             [(0x1fU & (vlTOPp->mips_cpu__DOT__instruction_decode 
                                        >> 0x15U))]
                              : 0U)),32);
        vcdp->chgBus(c+713,(((0U != (0x1fU & (vlTOPp->mips_cpu__DOT__instruction_decode 
                                              >> 0x10U)))
                              ? vlTOPp->mips_cpu__DOT__register_file__DOT__registers
                             [(0x1fU & (vlTOPp->mips_cpu__DOT__instruction_decode 
                                        >> 0x10U))]
                              : 0U)),32);
    }
}

void MIPS_Harvard_TB::traceChgThis__8(MIPS_Harvard_TB__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    MIPS_Harvard_TB* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
        vcdp->chgBus(c+721,(vlTOPp->mips_cpu__DOT__register_file__DOT__registers[0]),32);
        vcdp->chgBus(c+722,(vlTOPp->mips_cpu__DOT__register_file__DOT__registers[1]),32);
        vcdp->chgBus(c+723,(vlTOPp->mips_cpu__DOT__register_file__DOT__registers[2]),32);
        vcdp->chgBus(c+724,(vlTOPp->mips_cpu__DOT__register_file__DOT__registers[3]),32);
        vcdp->chgBus(c+725,(vlTOPp->mips_cpu__DOT__register_file__DOT__registers[4]),32);
        vcdp->chgBus(c+726,(vlTOPp->mips_cpu__DOT__register_file__DOT__registers[5]),32);
        vcdp->chgBus(c+727,(vlTOPp->mips_cpu__DOT__register_file__DOT__registers[6]),32);
        vcdp->chgBus(c+728,(vlTOPp->mips_cpu__DOT__register_file__DOT__registers[7]),32);
        vcdp->chgBus(c+729,(vlTOPp->mips_cpu__DOT__register_file__DOT__registers[8]),32);
        vcdp->chgBus(c+730,(vlTOPp->mips_cpu__DOT__register_file__DOT__registers[9]),32);
        vcdp->chgBus(c+731,(vlTOPp->mips_cpu__DOT__register_file__DOT__registers[10]),32);
        vcdp->chgBus(c+732,(vlTOPp->mips_cpu__DOT__register_file__DOT__registers[11]),32);
        vcdp->chgBus(c+733,(vlTOPp->mips_cpu__DOT__register_file__DOT__registers[12]),32);
        vcdp->chgBus(c+734,(vlTOPp->mips_cpu__DOT__register_file__DOT__registers[13]),32);
        vcdp->chgBus(c+735,(vlTOPp->mips_cpu__DOT__register_file__DOT__registers[14]),32);
        vcdp->chgBus(c+736,(vlTOPp->mips_cpu__DOT__register_file__DOT__registers[15]),32);
        vcdp->chgBus(c+737,(vlTOPp->mips_cpu__DOT__register_file__DOT__registers[16]),32);
        vcdp->chgBus(c+738,(vlTOPp->mips_cpu__DOT__register_file__DOT__registers[17]),32);
        vcdp->chgBus(c+739,(vlTOPp->mips_cpu__DOT__register_file__DOT__registers[18]),32);
        vcdp->chgBus(c+740,(vlTOPp->mips_cpu__DOT__register_file__DOT__registers[19]),32);
        vcdp->chgBus(c+741,(vlTOPp->mips_cpu__DOT__register_file__DOT__registers[20]),32);
        vcdp->chgBus(c+742,(vlTOPp->mips_cpu__DOT__register_file__DOT__registers[21]),32);
        vcdp->chgBus(c+743,(vlTOPp->mips_cpu__DOT__register_file__DOT__registers[22]),32);
        vcdp->chgBus(c+744,(vlTOPp->mips_cpu__DOT__register_file__DOT__registers[23]),32);
        vcdp->chgBus(c+745,(vlTOPp->mips_cpu__DOT__register_file__DOT__registers[24]),32);
        vcdp->chgBus(c+746,(vlTOPp->mips_cpu__DOT__register_file__DOT__registers[25]),32);
        vcdp->chgBus(c+747,(vlTOPp->mips_cpu__DOT__register_file__DOT__registers[26]),32);
        vcdp->chgBus(c+748,(vlTOPp->mips_cpu__DOT__register_file__DOT__registers[27]),32);
        vcdp->chgBus(c+749,(vlTOPp->mips_cpu__DOT__register_file__DOT__registers[28]),32);
        vcdp->chgBus(c+750,(vlTOPp->mips_cpu__DOT__register_file__DOT__registers[29]),32);
        vcdp->chgBus(c+751,(vlTOPp->mips_cpu__DOT__register_file__DOT__registers[30]),32);
        vcdp->chgBus(c+752,(vlTOPp->mips_cpu__DOT__register_file__DOT__registers[31]),32);
        vcdp->chgBus(c+977,(vlTOPp->mips_cpu__DOT__register_file__DOT__HI_reg),32);
        vcdp->chgBus(c+985,(vlTOPp->mips_cpu__DOT__register_file__DOT__LO_reg),32);
    }
}

void MIPS_Harvard_TB::traceChgThis__9(MIPS_Harvard_TB__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    MIPS_Harvard_TB* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
        vcdp->chgBit(c+993,(vlTOPp->clk));
        vcdp->chgBit(c+1001,(vlTOPp->reset));
        vcdp->chgBit(c+1009,(vlTOPp->active));
        vcdp->chgBus(c+1017,(vlTOPp->register_v0),32);
        vcdp->chgBit(c+1025,(vlTOPp->clk_enable));
        vcdp->chgBus(c+1033,(vlTOPp->instr_address),32);
        vcdp->chgBus(c+1041,(vlTOPp->instr_readdata),32);
        vcdp->chgBus(c+1049,(vlTOPp->data_address),32);
        vcdp->chgBit(c+1057,(vlTOPp->data_write));
        vcdp->chgBit(c+1065,(vlTOPp->data_read));
        vcdp->chgBus(c+1073,(vlTOPp->data_writedata),32);
        vcdp->chgBus(c+1081,(vlTOPp->data_readdata),32);
    }
}
