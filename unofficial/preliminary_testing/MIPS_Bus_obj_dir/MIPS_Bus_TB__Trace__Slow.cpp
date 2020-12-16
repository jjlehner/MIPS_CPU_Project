// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "MIPS_Bus_TB__Syms.h"


//======================

void MIPS_Bus_TB::trace(VerilatedVcdC* tfp, int, int) {
    tfp->spTrace()->addCallback(&MIPS_Bus_TB::traceInit, &MIPS_Bus_TB::traceFull, &MIPS_Bus_TB::traceChg, this);
}
void MIPS_Bus_TB::traceInit(VerilatedVcd* vcdp, void* userthis, uint32_t code) {
    // Callback from vcd->open()
    MIPS_Bus_TB* t = (MIPS_Bus_TB*)userthis;
    MIPS_Bus_TB__Syms* __restrict vlSymsp = t->__VlSymsp;  // Setup global symbol table
    if (!Verilated::calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
                        "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vcdp->scopeEscape(' ');
    t->traceInitThis(vlSymsp, vcdp, code);
    vcdp->scopeEscape('.');
}
void MIPS_Bus_TB::traceFull(VerilatedVcd* vcdp, void* userthis, uint32_t code) {
    // Callback from vcd->dump()
    MIPS_Bus_TB* t = (MIPS_Bus_TB*)userthis;
    MIPS_Bus_TB__Syms* __restrict vlSymsp = t->__VlSymsp;  // Setup global symbol table
    t->traceFullThis(vlSymsp, vcdp, code);
}

//======================


void MIPS_Bus_TB::traceInitThis(MIPS_Bus_TB__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    MIPS_Bus_TB* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (0 && vcdp && c) {}  // Prevent unused
    vcdp->module(vlSymsp->name());  // Setup signal names
    // Body
    {
        vlTOPp->traceInitThis__1(vlSymsp, vcdp, code);
    }
}

void MIPS_Bus_TB::traceFullThis(MIPS_Bus_TB__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    MIPS_Bus_TB* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
        vlTOPp->traceFullThis__1(vlSymsp, vcdp, code);
    }
    // Final
    vlTOPp->__Vm_traceActivity = 0U;
}

void MIPS_Bus_TB::traceInitThis__1(MIPS_Bus_TB__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    MIPS_Bus_TB* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
        vcdp->declBit(c+1305,"clk", false,-1);
        vcdp->declBit(c+1313,"reset", false,-1);
        vcdp->declBit(c+1321,"active", false,-1);
        vcdp->declBus(c+1329,"register_v0", false,-1, 31,0);
        vcdp->declBus(c+1337,"address", false,-1, 31,0);
        vcdp->declBit(c+1345,"write", false,-1);
        vcdp->declBit(c+1353,"read", false,-1);
        vcdp->declBit(c+1361,"waitrequest", false,-1);
        vcdp->declBus(c+1369,"writedata", false,-1, 31,0);
        vcdp->declBus(c+1377,"byteenable", false,-1, 3,0);
        vcdp->declBus(c+1385,"readdata", false,-1, 31,0);
        vcdp->declBit(c+1305,"mips_cpu_bus clk", false,-1);
        vcdp->declBit(c+1313,"mips_cpu_bus reset", false,-1);
        vcdp->declBit(c+1321,"mips_cpu_bus active", false,-1);
        vcdp->declBus(c+1329,"mips_cpu_bus register_v0", false,-1, 31,0);
        vcdp->declBus(c+1337,"mips_cpu_bus address", false,-1, 31,0);
        vcdp->declBit(c+1345,"mips_cpu_bus write", false,-1);
        vcdp->declBit(c+1353,"mips_cpu_bus read", false,-1);
        vcdp->declBit(c+1361,"mips_cpu_bus waitrequest", false,-1);
        vcdp->declBus(c+1369,"mips_cpu_bus writedata", false,-1, 31,0);
        vcdp->declBus(c+1377,"mips_cpu_bus byteenable", false,-1, 3,0);
        vcdp->declBus(c+1385,"mips_cpu_bus readdata", false,-1, 31,0);
        vcdp->declBit(c+1089,"mips_cpu_bus internal_clk", false,-1);
        vcdp->declBus(c+17,"mips_cpu_bus program_counter_prime", false,-1, 31,0);
        vcdp->declBus(c+729,"mips_cpu_bus instr_address", false,-1, 31,0);
        vcdp->declBus(c+737,"mips_cpu_bus program_counter_plus_four_fetch", false,-1, 31,0);
        vcdp->declBus(c+25,"mips_cpu_bus program_counter_mux_1_out", false,-1, 31,0);
        vcdp->declBit(c+745,"mips_cpu_bus HALT_fetch", false,-1);
        vcdp->declBit(c+401,"mips_cpu_bus program_counter_src_decode", false,-1);
        vcdp->declBit(c+281,"mips_cpu_bus register_write_decode", false,-1);
        vcdp->declBit(c+289,"mips_cpu_bus memory_to_register_decode", false,-1);
        vcdp->declBit(c+297,"mips_cpu_bus memory_write_decode", false,-1);
        vcdp->declBus(c+305,"mips_cpu_bus ALU_src_B_decode", false,-1, 1,0);
        vcdp->declBus(c+313,"mips_cpu_bus register_destination_decode", false,-1, 1,0);
        vcdp->declBit(c+321,"mips_cpu_bus branch_decode", false,-1);
        vcdp->declBit(c+49,"mips_cpu_bus equal_decode", false,-1);
        vcdp->declBus(c+329,"mips_cpu_bus ALU_function_decode", false,-1, 5,0);
        vcdp->declBit(c+337,"mips_cpu_bus program_counter_multiplexer_jump_decode", false,-1);
        vcdp->declBit(c+345,"mips_cpu_bus using_HI_LO_decode", false,-1);
        vcdp->declBit(c+353,"mips_cpu_bus j_instruction_decode", false,-1);
        vcdp->declBit(c+361,"mips_cpu_bus HI_register_write_decode", false,-1);
        vcdp->declBit(c+369,"mips_cpu_bus LO_register_write_decode", false,-1);
        vcdp->declBit(c+753,"mips_cpu_bus HALT_decode", false,-1);
        vcdp->declBus(c+9,"mips_cpu_bus program_counter_branch_decode", false,-1, 31,0);
        vcdp->declBus(c+1097,"mips_cpu_bus instruction_decode", false,-1, 31,0);
        vcdp->declBus(c+761,"mips_cpu_bus program_counter_plus_four_decode", false,-1, 31,0);
        vcdp->declBus(c+1105,"mips_cpu_bus op", false,-1, 5,0);
        vcdp->declBus(c+1113,"mips_cpu_bus read_address_1", false,-1, 4,0);
        vcdp->declBus(c+1113,"mips_cpu_bus Rs_decode", false,-1, 4,0);
        vcdp->declBus(c+1121,"mips_cpu_bus read_address_2", false,-1, 4,0);
        vcdp->declBus(c+1121,"mips_cpu_bus Rt_decode", false,-1, 4,0);
        vcdp->declBus(c+1129,"mips_cpu_bus Rd_decode", false,-1, 4,0);
        vcdp->declBus(c+1137,"mips_cpu_bus immediate", false,-1, 15,0);
        vcdp->declBus(c+1145,"mips_cpu_bus j_offset", false,-1, 25,0);
        vcdp->declBus(c+1177,"mips_cpu_bus register_file_output_LO_decode", false,-1, 31,0);
        vcdp->declBus(c+1185,"mips_cpu_bus register_file_output_HI_decode", false,-1, 31,0);
        vcdp->declBus(c+33,"mips_cpu_bus shifter_output_decode", false,-1, 31,0);
        vcdp->declBus(c+265,"mips_cpu_bus register_file_output_A_decode", false,-1, 31,0);
        vcdp->declBus(c+273,"mips_cpu_bus register_file_output_B_decode", false,-1, 31,0);
        vcdp->declBus(c+57,"mips_cpu_bus src_A_decode", false,-1, 31,0);
        vcdp->declBus(c+65,"mips_cpu_bus src_B_decode", false,-1, 31,0);
        vcdp->declBus(c+41,"mips_cpu_bus sign_imm_decode", false,-1, 31,0);
        vcdp->declBus(c+409,"mips_cpu_bus comparator_1", false,-1, 31,0);
        vcdp->declBus(c+417,"mips_cpu_bus comparator_2", false,-1, 31,0);
        vcdp->declBus(c+1065,"mips_cpu_bus j_program_counter_decode", false,-1, 31,0);
        vcdp->declBus(c+769,"mips_cpu_bus register_destination_execute", false,-1, 1,0);
        vcdp->declBit(c+1193,"mips_cpu_bus memory_to_register_execute", false,-1);
        vcdp->declBit(c+1201,"mips_cpu_bus memory_write_execute", false,-1);
        vcdp->declBus(c+1,"mips_cpu_bus write_register_execute", false,-1, 4,0);
        vcdp->declBus(c+777,"mips_cpu_bus ALU_src_B_execute", false,-1, 1,0);
        vcdp->declBus(c+785,"mips_cpu_bus ALU_function_execute", false,-1, 5,0);
        vcdp->declBit(c+1209,"mips_cpu_bus HI_register_write_execute", false,-1);
        vcdp->declBit(c+1217,"mips_cpu_bus LO_register_write_execute", false,-1);
        vcdp->declBit(c+793,"mips_cpu_bus register_write_execute", false,-1);
        vcdp->declBit(c+801,"mips_cpu_bus program_counter_multiplexer_jump_execute", false,-1);
        vcdp->declBit(c+809,"mips_cpu_bus j_instruction_execute", false,-1);
        vcdp->declBit(c+817,"mips_cpu_bus using_HI_LO_execute", false,-1);
        vcdp->declBit(c+825,"mips_cpu_bus HALT_execute", false,-1);
        vcdp->declBus(c+833,"mips_cpu_bus op_execute", false,-1, 5,0);
        vcdp->declBus(c+841,"mips_cpu_bus src_A_execute", false,-1, 31,0);
        vcdp->declBus(c+849,"mips_cpu_bus src_B_execute", false,-1, 31,0);
        vcdp->declBus(c+97,"mips_cpu_bus src_A_ALU_execute", false,-1, 31,0);
        vcdp->declBus(c+105,"mips_cpu_bus src_B_ALU_execute", false,-1, 31,0);
        vcdp->declBus(c+113,"mips_cpu_bus write_data_execute", false,-1, 31,0);
        vcdp->declBus(c+121,"mips_cpu_bus ALU_output_execute", false,-1, 31,0);
        vcdp->declBus(c+129,"mips_cpu_bus ALU_HI_output_execute", false,-1, 31,0);
        vcdp->declBus(c+137,"mips_cpu_bus ALU_LO_output_execute", false,-1, 31,0);
        vcdp->declBus(c+857,"mips_cpu_bus Rs_execute", false,-1, 4,0);
        vcdp->declBus(c+865,"mips_cpu_bus Rt_execute", false,-1, 4,0);
        vcdp->declBus(c+873,"mips_cpu_bus Rd_execute", false,-1, 4,0);
        vcdp->declBus(c+881,"mips_cpu_bus sign_imm_execute", false,-1, 31,0);
        vcdp->declBus(c+889,"mips_cpu_bus program_counter_plus_eight_execute", false,-1, 31,0);
        vcdp->declBus(c+897,"mips_cpu_bus program_counter_plus_four_execute", false,-1, 31,0);
        vcdp->declBus(c+905,"mips_cpu_bus j_program_counter_execute", false,-1, 31,0);
        vcdp->declBit(c+913,"mips_cpu_bus register_write_memory", false,-1);
        vcdp->declBus(c+921,"mips_cpu_bus write_register_memory", false,-1, 4,0);
        vcdp->declBit(c+1225,"mips_cpu_bus memory_to_register_memory", false,-1);
        vcdp->declBit(c+1233,"mips_cpu_bus memory_write_memory", false,-1);
        vcdp->declBit(c+1241,"mips_cpu_bus HI_register_write_memory", false,-1);
        vcdp->declBit(c+1249,"mips_cpu_bus LO_register_write_memory", false,-1);
        vcdp->declBit(c+929,"mips_cpu_bus program_counter_multiplexer_jump_memory", false,-1);
        vcdp->declBit(c+937,"mips_cpu_bus j_instruction_memory", false,-1);
        vcdp->declBit(c+945,"mips_cpu_bus HALT_memory", false,-1);
        vcdp->declBus(c+953,"mips_cpu_bus op_memory", false,-1, 5,0);
        vcdp->declBus(c+89,"mips_cpu_bus byteenable_memory", false,-1, 3,0);
        vcdp->declBus(c+961,"mips_cpu_bus ALU_output_memory", false,-1, 31,0);
        vcdp->declBus(c+1257,"mips_cpu_bus ALU_HI_output_memory", false,-1, 31,0);
        vcdp->declBus(c+1265,"mips_cpu_bus ALU_LO_output_memory", false,-1, 31,0);
        vcdp->declBus(c+969,"mips_cpu_bus write_data_memory", false,-1, 31,0);
        vcdp->declBus(c+977,"mips_cpu_bus ALU_output_memory_resolved", false,-1, 31,0);
        vcdp->declBus(c+985,"mips_cpu_bus j_program_counter_memory", false,-1, 31,0);
        vcdp->declBus(c+993,"mips_cpu_bus src_A_ALU_memory", false,-1, 31,0);
        vcdp->declBit(c+1001,"mips_cpu_bus register_write_writeback", false,-1);
        vcdp->declBit(c+1273,"mips_cpu_bus HI_register_write_writeback", false,-1);
        vcdp->declBit(c+1281,"mips_cpu_bus LO_register_write_writeback", false,-1);
        vcdp->declBit(c+1009,"mips_cpu_bus memory_to_register_writeback", false,-1);
        vcdp->declBit(c+1017,"mips_cpu_bus HALT_writeback", false,-1);
        vcdp->declBus(c+1025,"mips_cpu_bus op_writeback", false,-1, 5,0);
        vcdp->declBus(c+1033,"mips_cpu_bus byteenable_writeback", false,-1, 3,0);
        vcdp->declBus(c+1041,"mips_cpu_bus src_A_ALU_writeback", false,-1, 31,0);
        vcdp->declBus(c+1049,"mips_cpu_bus write_register_writeback", false,-1, 4,0);
        vcdp->declBus(c+145,"mips_cpu_bus result_writeback", false,-1, 31,0);
        vcdp->declBus(c+1289,"mips_cpu_bus ALU_HI_output_writeback", false,-1, 31,0);
        vcdp->declBus(c+1297,"mips_cpu_bus ALU_LO_output_writeback", false,-1, 31,0);
        vcdp->declBus(c+1057,"mips_cpu_bus ALU_output_writeback", false,-1, 31,0);
        vcdp->declBus(c+1153,"mips_cpu_bus read_data_writeback", false,-1, 31,0);
        vcdp->declBus(c+153,"mips_cpu_bus read_data_writeback_filtered", false,-1, 31,0);
        vcdp->declBit(c+425,"mips_cpu_bus stall_fetch", false,-1);
        vcdp->declBit(c+433,"mips_cpu_bus stall_decode", false,-1);
        vcdp->declBit(c+1073,"mips_cpu_bus forward_A_decode", false,-1);
        vcdp->declBit(c+1081,"mips_cpu_bus forward_B_decode", false,-1);
        vcdp->declBit(c+441,"mips_cpu_bus flush_execute_register", false,-1);
        vcdp->declBus(c+73,"mips_cpu_bus forward_A_execute", false,-1, 2,0);
        vcdp->declBus(c+81,"mips_cpu_bus forward_B_execute", false,-1, 2,0);
        vcdp->declBus(c+961,"mips_cpu_bus data_address", false,-1, 31,0);
        vcdp->declBus(c+465,"mips_cpu_bus register_v0_reg_file", false,-1, 31,0);
        vcdp->declBus(c+1161,"mips_cpu_bus fetch_state", false,-1, 1,0);
        vcdp->declBit(c+1089,"mips_cpu_bus register_file clk", false,-1);
        vcdp->declBit(c+1393,"mips_cpu_bus register_file pipelined", false,-1);
        vcdp->declBit(c+1001,"mips_cpu_bus register_file write_enable", false,-1);
        vcdp->declBit(c+1273,"mips_cpu_bus register_file HI_write_enable", false,-1);
        vcdp->declBit(c+1281,"mips_cpu_bus register_file LO_write_enable", false,-1);
        vcdp->declBus(c+1113,"mips_cpu_bus register_file read_address_1", false,-1, 4,0);
        vcdp->declBus(c+1121,"mips_cpu_bus register_file read_address_2", false,-1, 4,0);
        vcdp->declBus(c+1049,"mips_cpu_bus register_file write_address", false,-1, 4,0);
        vcdp->declBus(c+145,"mips_cpu_bus register_file write_data", false,-1, 31,0);
        vcdp->declBus(c+1289,"mips_cpu_bus register_file HI_write_data", false,-1, 31,0);
        vcdp->declBus(c+1297,"mips_cpu_bus register_file LO_write_data", false,-1, 31,0);
        vcdp->declBus(c+265,"mips_cpu_bus register_file read_data_1", false,-1, 31,0);
        vcdp->declBus(c+273,"mips_cpu_bus register_file read_data_2", false,-1, 31,0);
        vcdp->declBus(c+1177,"mips_cpu_bus register_file read_data_LO", false,-1, 31,0);
        vcdp->declBus(c+1185,"mips_cpu_bus register_file read_data_HI", false,-1, 31,0);
        vcdp->declBus(c+465,"mips_cpu_bus register_file read_register_2", false,-1, 31,0);
        {int i; for (i=0; i<32; i++) {
                vcdp->declBus(c+473+i*1,"mips_cpu_bus register_file registers", true,(i+0), 31,0);}}
        vcdp->declBus(c+1185,"mips_cpu_bus register_file HI_reg", false,-1, 31,0);
        vcdp->declBus(c+1177,"mips_cpu_bus register_file LO_reg", false,-1, 31,0);
        vcdp->declBit(c+1169,"mips_cpu_bus register_file modified_write_clk", false,-1);
        vcdp->declBit(c+1089,"mips_cpu_bus pc clk", false,-1);
        vcdp->declBus(c+17,"mips_cpu_bus pc address_input", false,-1, 31,0);
        vcdp->declBit(c+425,"mips_cpu_bus pc enable", false,-1);
        vcdp->declBit(c+1313,"mips_cpu_bus pc reset", false,-1);
        vcdp->declBit(c+745,"mips_cpu_bus pc halt", false,-1);
        vcdp->declBus(c+729,"mips_cpu_bus pc address_output", false,-1, 31,0);
        vcdp->declBus(c+729,"mips_cpu_bus plus_four_adder a", false,-1, 31,0);
        vcdp->declBus(c+1401,"mips_cpu_bus plus_four_adder b", false,-1, 31,0);
        vcdp->declBus(c+737,"mips_cpu_bus plus_four_adder z", false,-1, 31,0);
        vcdp->declBus(c+1409,"mips_cpu_bus program_counter_multiplexer BUS_WIDTH", false,-1, 31,0);
        vcdp->declBit(c+401,"mips_cpu_bus program_counter_multiplexer control", false,-1);
        vcdp->declBus(c+737,"mips_cpu_bus program_counter_multiplexer input_0", false,-1, 31,0);
        vcdp->declBus(c+9,"mips_cpu_bus program_counter_multiplexer input_1", false,-1, 31,0);
        vcdp->declBus(c+25,"mips_cpu_bus program_counter_multiplexer resolved", false,-1, 31,0);
        vcdp->declBus(c+1409,"mips_cpu_bus program_counter_multiplexer_two BUS_WIDTH", false,-1, 31,0);
        vcdp->declBit(c+929,"mips_cpu_bus program_counter_multiplexer_two control", false,-1);
        vcdp->declBus(c+25,"mips_cpu_bus program_counter_multiplexer_two input_0", false,-1, 31,0);
        vcdp->declBus(c+977,"mips_cpu_bus program_counter_multiplexer_two input_1", false,-1, 31,0);
        vcdp->declBus(c+17,"mips_cpu_bus program_counter_multiplexer_two resolved", false,-1, 31,0);
        vcdp->declBit(c+1089,"mips_cpu_bus fetch_decode_register clk", false,-1);
        vcdp->declBit(c+433,"mips_cpu_bus fetch_decode_register enable", false,-1);
        vcdp->declBit(c+401,"mips_cpu_bus fetch_decode_register clear", false,-1);
        vcdp->declBit(c+1313,"mips_cpu_bus fetch_decode_register reset", false,-1);
        vcdp->declBit(c+745,"mips_cpu_bus fetch_decode_register HALT_fetch", false,-1);
        vcdp->declBit(c+753,"mips_cpu_bus fetch_decode_register HALT_decode", false,-1);
        vcdp->declBus(c+737,"mips_cpu_bus fetch_decode_register program_counter_plus_four_fetch", false,-1, 31,0);
        vcdp->declBus(c+761,"mips_cpu_bus fetch_decode_register program_counter_plus_four_decode", false,-1, 31,0);
        vcdp->declBus(c+1097,"mips_cpu_bus control_unit instruction", false,-1, 31,0);
        vcdp->declBit(c+281,"mips_cpu_bus control_unit register_write", false,-1);
        vcdp->declBit(c+289,"mips_cpu_bus control_unit memory_to_register", false,-1);
        vcdp->declBit(c+297,"mips_cpu_bus control_unit memory_write", false,-1);
        vcdp->declBus(c+305,"mips_cpu_bus control_unit ALU_src_B", false,-1, 1,0);
        vcdp->declBus(c+313,"mips_cpu_bus control_unit register_destination", false,-1, 1,0);
        vcdp->declBit(c+321,"mips_cpu_bus control_unit branch", false,-1);
        vcdp->declBus(c+329,"mips_cpu_bus control_unit ALU_function", false,-1, 5,0);
        vcdp->declBit(c+337,"mips_cpu_bus control_unit program_counter_multiplexer_jump", false,-1);
        vcdp->declBit(c+353,"mips_cpu_bus control_unit j_instruction", false,-1);
        vcdp->declBit(c+369,"mips_cpu_bus control_unit LO_register_write", false,-1);
        vcdp->declBit(c+361,"mips_cpu_bus control_unit HI_register_write", false,-1);
        vcdp->declBit(c+345,"mips_cpu_bus control_unit using_HI_LO", false,-1);
        vcdp->declBus(c+377,"mips_cpu_bus control_unit op", false,-1, 5,0);
        vcdp->declBus(c+385,"mips_cpu_bus control_unit rt", false,-1, 4,0);
        vcdp->declBus(c+393,"mips_cpu_bus control_unit funct", false,-1, 5,0);
        vcdp->declBus(c+1105,"mips_cpu_bus reg_output_comparator op", false,-1, 5,0);
        vcdp->declBus(c+1121,"mips_cpu_bus reg_output_comparator rt", false,-1, 4,0);
        vcdp->declBus(c+409,"mips_cpu_bus reg_output_comparator a", false,-1, 31,0);
        vcdp->declBus(c+417,"mips_cpu_bus reg_output_comparator b", false,-1, 31,0);
        vcdp->declBit(c+49,"mips_cpu_bus reg_output_comparator c", false,-1);
        vcdp->declBus(c+33,"mips_cpu_bus adder_decode a", false,-1, 31,0);
        vcdp->declBus(c+761,"mips_cpu_bus adder_decode b", false,-1, 31,0);
        vcdp->declBus(c+9,"mips_cpu_bus adder_decode z", false,-1, 31,0);
        vcdp->declBit(c+1089,"mips_cpu_bus decode_execute_register clk", false,-1);
        vcdp->declBit(c+441,"mips_cpu_bus decode_execute_register clear", false,-1);
        vcdp->declBit(c+1313,"mips_cpu_bus decode_execute_register reset", false,-1);
        vcdp->declBit(c+281,"mips_cpu_bus decode_execute_register register_write_decode", false,-1);
        vcdp->declBit(c+289,"mips_cpu_bus decode_execute_register memory_to_register_decode", false,-1);
        vcdp->declBit(c+297,"mips_cpu_bus decode_execute_register memory_write_decode", false,-1);
        vcdp->declBus(c+305,"mips_cpu_bus decode_execute_register ALU_src_B_decode", false,-1, 1,0);
        vcdp->declBus(c+313,"mips_cpu_bus decode_execute_register register_destination_decode", false,-1, 1,0);
        vcdp->declBit(c+361,"mips_cpu_bus decode_execute_register HI_register_write_decode", false,-1);
        vcdp->declBit(c+369,"mips_cpu_bus decode_execute_register LO_register_write_decode", false,-1);
        vcdp->declBus(c+329,"mips_cpu_bus decode_execute_register ALU_function_decode", false,-1, 5,0);
        vcdp->declBit(c+337,"mips_cpu_bus decode_execute_register program_counter_multiplexer_jump_decode", false,-1);
        vcdp->declBit(c+353,"mips_cpu_bus decode_execute_register j_instruction_decode", false,-1);
        vcdp->declBit(c+345,"mips_cpu_bus decode_execute_register using_HI_LO_decode", false,-1);
        vcdp->declBit(c+753,"mips_cpu_bus decode_execute_register HALT_decode", false,-1);
        vcdp->declBus(c+1105,"mips_cpu_bus decode_execute_register op_decode", false,-1, 5,0);
        vcdp->declBit(c+793,"mips_cpu_bus decode_execute_register register_write_execute", false,-1);
        vcdp->declBit(c+1193,"mips_cpu_bus decode_execute_register memory_to_register_execute", false,-1);
        vcdp->declBit(c+1201,"mips_cpu_bus decode_execute_register memory_write_execute", false,-1);
        vcdp->declBus(c+777,"mips_cpu_bus decode_execute_register ALU_src_B_execute", false,-1, 1,0);
        vcdp->declBus(c+769,"mips_cpu_bus decode_execute_register register_destination_execute", false,-1, 1,0);
        vcdp->declBit(c+1209,"mips_cpu_bus decode_execute_register HI_register_write_execute", false,-1);
        vcdp->declBit(c+1217,"mips_cpu_bus decode_execute_register LO_register_write_execute", false,-1);
        vcdp->declBus(c+785,"mips_cpu_bus decode_execute_register ALU_function_execute", false,-1, 5,0);
        vcdp->declBit(c+801,"mips_cpu_bus decode_execute_register program_counter_multiplexer_jump_execute", false,-1);
        vcdp->declBit(c+809,"mips_cpu_bus decode_execute_register j_instruction_execute", false,-1);
        vcdp->declBit(c+817,"mips_cpu_bus decode_execute_register using_HI_LO_execute", false,-1);
        vcdp->declBit(c+825,"mips_cpu_bus decode_execute_register HALT_execute", false,-1);
        vcdp->declBus(c+833,"mips_cpu_bus decode_execute_register op_execute", false,-1, 5,0);
        vcdp->declBus(c+1113,"mips_cpu_bus decode_execute_register Rs_decode", false,-1, 4,0);
        vcdp->declBus(c+1121,"mips_cpu_bus decode_execute_register Rt_decode", false,-1, 4,0);
        vcdp->declBus(c+1129,"mips_cpu_bus decode_execute_register Rd_decode", false,-1, 4,0);
        vcdp->declBus(c+41,"mips_cpu_bus decode_execute_register sign_imm_decode", false,-1, 31,0);
        vcdp->declBus(c+857,"mips_cpu_bus decode_execute_register Rs_execute", false,-1, 4,0);
        vcdp->declBus(c+865,"mips_cpu_bus decode_execute_register Rt_execute", false,-1, 4,0);
        vcdp->declBus(c+873,"mips_cpu_bus decode_execute_register Rd_execute", false,-1, 4,0);
        vcdp->declBus(c+881,"mips_cpu_bus decode_execute_register sign_imm_execute", false,-1, 31,0);
        vcdp->declBus(c+57,"mips_cpu_bus decode_execute_register src_A_decode", false,-1, 31,0);
        vcdp->declBus(c+65,"mips_cpu_bus decode_execute_register src_B_decode", false,-1, 31,0);
        vcdp->declBus(c+761,"mips_cpu_bus decode_execute_register program_counter_plus_four_decode", false,-1, 31,0);
        vcdp->declBus(c+1065,"mips_cpu_bus decode_execute_register j_program_counter_decode", false,-1, 31,0);
        vcdp->declBus(c+841,"mips_cpu_bus decode_execute_register src_A_execute", false,-1, 31,0);
        vcdp->declBus(c+849,"mips_cpu_bus decode_execute_register src_B_execute", false,-1, 31,0);
        vcdp->declBus(c+897,"mips_cpu_bus decode_execute_register program_counter_plus_four_execute", false,-1, 31,0);
        vcdp->declBus(c+905,"mips_cpu_bus decode_execute_register j_program_counter_execute", false,-1, 31,0);
        vcdp->declBus(c+1401,"mips_cpu_bus plus_four_adder_execute a", false,-1, 31,0);
        vcdp->declBus(c+897,"mips_cpu_bus plus_four_adder_execute b", false,-1, 31,0);
        vcdp->declBus(c+889,"mips_cpu_bus plus_four_adder_execute z", false,-1, 31,0);
        vcdp->declBus(c+1417,"mips_cpu_bus write_register_execute_mux BUS_WIDTH", false,-1, 31,0);
        vcdp->declBus(c+769,"mips_cpu_bus write_register_execute_mux control", false,-1, 1,0);
        vcdp->declBus(c+865,"mips_cpu_bus write_register_execute_mux input_0", false,-1, 4,0);
        vcdp->declBus(c+873,"mips_cpu_bus write_register_execute_mux input_1", false,-1, 4,0);
        vcdp->declBus(c+1425,"mips_cpu_bus write_register_execute_mux input_2", false,-1, 4,0);
        vcdp->declBus(c+1433,"mips_cpu_bus write_register_execute_mux input_3", false,-1, 4,0);
        vcdp->declBus(c+1,"mips_cpu_bus write_register_execute_mux resolved", false,-1, 4,0);
        vcdp->declBus(c+777,"mips_cpu_bus alu_input_mux ALU_src_B_execute", false,-1, 1,0);
        vcdp->declBus(c+73,"mips_cpu_bus alu_input_mux forward_one_execute", false,-1, 2,0);
        vcdp->declBus(c+81,"mips_cpu_bus alu_input_mux forward_two_execute", false,-1, 2,0);
        vcdp->declBus(c+841,"mips_cpu_bus alu_input_mux read_data_1_reg", false,-1, 31,0);
        vcdp->declBus(c+145,"mips_cpu_bus alu_input_mux result_writeback", false,-1, 31,0);
        vcdp->declBus(c+961,"mips_cpu_bus alu_input_mux ALU_output_memory", false,-1, 31,0);
        vcdp->declBus(c+1297,"mips_cpu_bus alu_input_mux LO_result_writeback", false,-1, 31,0);
        vcdp->declBus(c+1265,"mips_cpu_bus alu_input_mux ALU_LO_output_memory", false,-1, 31,0);
        vcdp->declBus(c+849,"mips_cpu_bus alu_input_mux read_data_2_reg", false,-1, 31,0);
        vcdp->declBus(c+1257,"mips_cpu_bus alu_input_mux ALU_HI_output_memory", false,-1, 31,0);
        vcdp->declBus(c+1289,"mips_cpu_bus alu_input_mux HI_result_writeback", false,-1, 31,0);
        vcdp->declBus(c+881,"mips_cpu_bus alu_input_mux sign_imm_execute", false,-1, 31,0);
        vcdp->declBus(c+889,"mips_cpu_bus alu_input_mux program_counter_plus_eight_execute", false,-1, 31,0);
        vcdp->declBus(c+97,"mips_cpu_bus alu_input_mux src_A_ALU_execute", false,-1, 31,0);
        vcdp->declBus(c+105,"mips_cpu_bus alu_input_mux src_B_ALU_execute", false,-1, 31,0);
        vcdp->declBus(c+113,"mips_cpu_bus alu_input_mux write_data_execute", false,-1, 31,0);
        vcdp->declBus(c+161,"mips_cpu_bus alu_input_mux src_mux_input_0", false,-1, 31,0);
        vcdp->declBus(c+785,"mips_cpu_bus alu ALU_operation", false,-1, 5,0);
        vcdp->declBus(c+97,"mips_cpu_bus alu input_1", false,-1, 31,0);
        vcdp->declBus(c+105,"mips_cpu_bus alu input_2", false,-1, 31,0);
        vcdp->declBus(c+121,"mips_cpu_bus alu ALU_output", false,-1, 31,0);
        vcdp->declBus(c+129,"mips_cpu_bus alu ALU_HI_output", false,-1, 31,0);
        vcdp->declBus(c+137,"mips_cpu_bus alu ALU_LO_output", false,-1, 31,0);
        vcdp->declBus(c+169,"mips_cpu_bus alu shift_amount", false,-1, 4,0);
        vcdp->declQuad(c+177,"mips_cpu_bus alu sign_extened_input_1", false,-1, 63,0);
        vcdp->declQuad(c+193,"mips_cpu_bus alu sign_extened_input_2", false,-1, 63,0);
        vcdp->declQuad(c+209,"mips_cpu_bus alu extended_input_1", false,-1, 63,0);
        vcdp->declQuad(c+225,"mips_cpu_bus alu extended_input_2", false,-1, 63,0);
        vcdp->declQuad(c+241,"mips_cpu_bus alu ALU_HI_LO_output", false,-1, 63,0);
        vcdp->declBit(c+1089,"mips_cpu_bus execute_memory_register clk", false,-1);
        vcdp->declBit(c+1313,"mips_cpu_bus execute_memory_register reset", false,-1);
        vcdp->declBit(c+793,"mips_cpu_bus execute_memory_register register_write_execute", false,-1);
        vcdp->declBit(c+1193,"mips_cpu_bus execute_memory_register memory_to_register_execute", false,-1);
        vcdp->declBit(c+1201,"mips_cpu_bus execute_memory_register memory_write_execute", false,-1);
        vcdp->declBit(c+1209,"mips_cpu_bus execute_memory_register HI_register_write_execute", false,-1);
        vcdp->declBit(c+1217,"mips_cpu_bus execute_memory_register LO_register_write_execute", false,-1);
        vcdp->declBit(c+801,"mips_cpu_bus execute_memory_register program_counter_multiplexer_jump_execute", false,-1);
        vcdp->declBit(c+809,"mips_cpu_bus execute_memory_register j_instruction_execute", false,-1);
        vcdp->declBit(c+825,"mips_cpu_bus execute_memory_register HALT_execute", false,-1);
        vcdp->declBus(c+833,"mips_cpu_bus execute_memory_register op_execute", false,-1, 5,0);
        vcdp->declBus(c+97,"mips_cpu_bus execute_memory_register src_A_ALU_execute", false,-1, 31,0);
        vcdp->declBit(c+913,"mips_cpu_bus execute_memory_register register_write_memory", false,-1);
        vcdp->declBit(c+1225,"mips_cpu_bus execute_memory_register memory_to_register_memory", false,-1);
        vcdp->declBit(c+1233,"mips_cpu_bus execute_memory_register memory_write_memory", false,-1);
        vcdp->declBit(c+1241,"mips_cpu_bus execute_memory_register HI_register_write_memory", false,-1);
        vcdp->declBit(c+1249,"mips_cpu_bus execute_memory_register LO_register_write_memory", false,-1);
        vcdp->declBit(c+929,"mips_cpu_bus execute_memory_register program_counter_multiplexer_jump_memory", false,-1);
        vcdp->declBit(c+937,"mips_cpu_bus execute_memory_register j_instruction_memory", false,-1);
        vcdp->declBit(c+945,"mips_cpu_bus execute_memory_register HALT_memory", false,-1);
        vcdp->declBus(c+953,"mips_cpu_bus execute_memory_register op_memory", false,-1, 5,0);
        vcdp->declBus(c+993,"mips_cpu_bus execute_memory_register src_A_ALU_memory", false,-1, 31,0);
        vcdp->declBus(c+121,"mips_cpu_bus execute_memory_register ALU_output_execute", false,-1, 31,0);
        vcdp->declBus(c+129,"mips_cpu_bus execute_memory_register ALU_HI_output_execute", false,-1, 31,0);
        vcdp->declBus(c+137,"mips_cpu_bus execute_memory_register ALU_LO_output_execute", false,-1, 31,0);
        vcdp->declBus(c+113,"mips_cpu_bus execute_memory_register write_data_execute", false,-1, 31,0);
        vcdp->declBus(c+1,"mips_cpu_bus execute_memory_register write_register_execute", false,-1, 4,0);
        vcdp->declBus(c+905,"mips_cpu_bus execute_memory_register j_program_counter_execute", false,-1, 31,0);
        vcdp->declBus(c+961,"mips_cpu_bus execute_memory_register ALU_output_memory", false,-1, 31,0);
        vcdp->declBus(c+1257,"mips_cpu_bus execute_memory_register ALU_HI_output_memory", false,-1, 31,0);
        vcdp->declBus(c+1265,"mips_cpu_bus execute_memory_register ALU_LO_output_memory", false,-1, 31,0);
        vcdp->declBus(c+969,"mips_cpu_bus execute_memory_register write_data_memory", false,-1, 31,0);
        vcdp->declBus(c+921,"mips_cpu_bus execute_memory_register write_register_memory", false,-1, 4,0);
        vcdp->declBus(c+985,"mips_cpu_bus execute_memory_register j_program_counter_memory", false,-1, 31,0);
        vcdp->declBus(c+1025,"mips_cpu_bus memory_filter op_writeback", false,-1, 5,0);
        vcdp->declBus(c+1033,"mips_cpu_bus memory_filter byteenable_writeback", false,-1, 3,0);
        vcdp->declBus(c+1041,"mips_cpu_bus memory_filter src_A_writeback", false,-1, 31,0);
        vcdp->declBus(c+1153,"mips_cpu_bus memory_filter read_data_writeback", false,-1, 31,0);
        vcdp->declBit(c+1313,"mips_cpu_bus memory_filter reset", false,-1);
        vcdp->declBus(c+153,"mips_cpu_bus memory_filter filtered_output_writeback", false,-1, 31,0);
        vcdp->declBus(c+257,"mips_cpu_bus memory_filter temp_filtered", false,-1, 31,0);
        vcdp->declBit(c+1089,"mips_cpu_bus memory_writeback_register clk", false,-1);
        vcdp->declBit(c+1313,"mips_cpu_bus memory_writeback_register reset", false,-1);
        vcdp->declBit(c+913,"mips_cpu_bus memory_writeback_register register_write_memory", false,-1);
        vcdp->declBit(c+1225,"mips_cpu_bus memory_writeback_register memory_to_register_memory", false,-1);
        vcdp->declBit(c+1241,"mips_cpu_bus memory_writeback_register HI_register_write_memory", false,-1);
        vcdp->declBit(c+1249,"mips_cpu_bus memory_writeback_register LO_register_write_memory", false,-1);
        vcdp->declBit(c+945,"mips_cpu_bus memory_writeback_register HALT_memory", false,-1);
        vcdp->declBus(c+953,"mips_cpu_bus memory_writeback_register op_memory", false,-1, 5,0);
        vcdp->declBus(c+89,"mips_cpu_bus memory_writeback_register byteenable_memory", false,-1, 3,0);
        vcdp->declBus(c+993,"mips_cpu_bus memory_writeback_register src_A_ALU_memory", false,-1, 31,0);
        vcdp->declBit(c+1001,"mips_cpu_bus memory_writeback_register register_write_writeback", false,-1);
        vcdp->declBit(c+1009,"mips_cpu_bus memory_writeback_register memory_to_register_writeback", false,-1);
        vcdp->declBit(c+1273,"mips_cpu_bus memory_writeback_register HI_register_write_writeback", false,-1);
        vcdp->declBit(c+1281,"mips_cpu_bus memory_writeback_register LO_register_write_writeback", false,-1);
        vcdp->declBit(c+1017,"mips_cpu_bus memory_writeback_register HALT_writeback", false,-1);
        vcdp->declBus(c+1025,"mips_cpu_bus memory_writeback_register op_writeback", false,-1, 5,0);
        vcdp->declBus(c+1033,"mips_cpu_bus memory_writeback_register byteenable_writeback", false,-1, 3,0);
        vcdp->declBus(c+1041,"mips_cpu_bus memory_writeback_register src_A_ALU_writeback", false,-1, 31,0);
        vcdp->declBus(c+961,"mips_cpu_bus memory_writeback_register ALU_output_memory", false,-1, 31,0);
        vcdp->declBus(c+921,"mips_cpu_bus memory_writeback_register write_register_memory", false,-1, 4,0);
        vcdp->declBus(c+1257,"mips_cpu_bus memory_writeback_register ALU_HI_output_memory", false,-1, 31,0);
        vcdp->declBus(c+1265,"mips_cpu_bus memory_writeback_register ALU_LO_output_memory", false,-1, 31,0);
        vcdp->declBus(c+1057,"mips_cpu_bus memory_writeback_register ALU_output_writeback", false,-1, 31,0);
        vcdp->declBus(c+1049,"mips_cpu_bus memory_writeback_register write_register_writeback", false,-1, 4,0);
        vcdp->declBus(c+1289,"mips_cpu_bus memory_writeback_register ALU_HI_output_writeback", false,-1, 31,0);
        vcdp->declBus(c+1297,"mips_cpu_bus memory_writeback_register ALU_LO_output_writeback", false,-1, 31,0);
        vcdp->declBus(c+1409,"mips_cpu_bus writeback_mux BUS_WIDTH", false,-1, 31,0);
        vcdp->declBit(c+1009,"mips_cpu_bus writeback_mux control", false,-1);
        vcdp->declBus(c+1057,"mips_cpu_bus writeback_mux input_0", false,-1, 31,0);
        vcdp->declBus(c+153,"mips_cpu_bus writeback_mux input_1", false,-1, 31,0);
        vcdp->declBus(c+145,"mips_cpu_bus writeback_mux resolved", false,-1, 31,0);
        vcdp->declBit(c+321,"mips_cpu_bus hazard_unit branch_decode", false,-1);
        vcdp->declBus(c+1113,"mips_cpu_bus hazard_unit Rs_decode", false,-1, 4,0);
        vcdp->declBus(c+1121,"mips_cpu_bus hazard_unit Rt_decode", false,-1, 4,0);
        vcdp->declBus(c+857,"mips_cpu_bus hazard_unit Rs_execute", false,-1, 4,0);
        vcdp->declBus(c+865,"mips_cpu_bus hazard_unit Rt_execute", false,-1, 4,0);
        vcdp->declBus(c+1,"mips_cpu_bus hazard_unit write_register_execute", false,-1, 4,0);
        vcdp->declBit(c+1193,"mips_cpu_bus hazard_unit memory_to_register_execute", false,-1);
        vcdp->declBit(c+793,"mips_cpu_bus hazard_unit register_write_execute", false,-1);
        vcdp->declBus(c+921,"mips_cpu_bus hazard_unit write_register_memory", false,-1, 4,0);
        vcdp->declBit(c+1225,"mips_cpu_bus hazard_unit memory_to_register_memory", false,-1);
        vcdp->declBit(c+913,"mips_cpu_bus hazard_unit register_write_memory", false,-1);
        vcdp->declBus(c+1049,"mips_cpu_bus hazard_unit write_register_writeback", false,-1, 4,0);
        vcdp->declBit(c+1001,"mips_cpu_bus hazard_unit register_write_writeback", false,-1);
        vcdp->declBit(c+801,"mips_cpu_bus hazard_unit program_counter_multiplexer_jump_execute", false,-1);
        vcdp->declBit(c+1241,"mips_cpu_bus hazard_unit HI_register_write_memory", false,-1);
        vcdp->declBit(c+1249,"mips_cpu_bus hazard_unit LO_register_write_memory", false,-1);
        vcdp->declBit(c+1281,"mips_cpu_bus hazard_unit LO_register_write_writeback", false,-1);
        vcdp->declBit(c+1273,"mips_cpu_bus hazard_unit HI_register_write_writeback", false,-1);
        vcdp->declBit(c+817,"mips_cpu_bus hazard_unit using_HI_LO_execute", false,-1);
        vcdp->declBit(c+425,"mips_cpu_bus hazard_unit stall_fetch", false,-1);
        vcdp->declBit(c+433,"mips_cpu_bus hazard_unit stall_decode", false,-1);
        vcdp->declBit(c+1073,"mips_cpu_bus hazard_unit forward_register_file_output_A_decode", false,-1);
        vcdp->declBit(c+1081,"mips_cpu_bus hazard_unit forward_register_file_output_B_decode", false,-1);
        vcdp->declBit(c+441,"mips_cpu_bus hazard_unit flush_execute_register", false,-1);
        vcdp->declBus(c+73,"mips_cpu_bus hazard_unit forward_register_file_output_A_execute", false,-1, 2,0);
        vcdp->declBus(c+81,"mips_cpu_bus hazard_unit forward_register_file_output_B_execute", false,-1, 2,0);
        vcdp->declBit(c+449,"mips_cpu_bus hazard_unit lwstall", false,-1);
        vcdp->declBit(c+457,"mips_cpu_bus hazard_unit branchstall", false,-1);
    }
}

void MIPS_Bus_TB::traceFullThis__1(MIPS_Bus_TB__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    MIPS_Bus_TB* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
        vcdp->fullBus(c+1,(vlTOPp->mips_cpu_bus__DOT__write_register_execute),5);
        vcdp->fullBus(c+9,(((vlTOPp->mips_cpu_bus__DOT__sign_imm_decode 
                             << 2U) + vlTOPp->mips_cpu_bus__DOT__program_counter_plus_four_decode)),32);
        vcdp->fullBus(c+17,(((IData)(vlTOPp->mips_cpu_bus__DOT__program_counter_multiplexer_jump_memory)
                              ? ((IData)(vlTOPp->mips_cpu_bus__DOT__j_instruction_memory)
                                  ? vlTOPp->mips_cpu_bus__DOT__j_program_counter_memory
                                  : vlTOPp->mips_cpu_bus__DOT__ALU_output_memory)
                              : ((IData)(vlTOPp->mips_cpu_bus__DOT__program_counter_src_decode)
                                  ? ((vlTOPp->mips_cpu_bus__DOT__sign_imm_decode 
                                      << 2U) + vlTOPp->mips_cpu_bus__DOT__program_counter_plus_four_decode)
                                  : ((IData)(4U) + vlTOPp->mips_cpu_bus__DOT__instr_address)))),32);
        vcdp->fullBus(c+25,(((IData)(vlTOPp->mips_cpu_bus__DOT__program_counter_src_decode)
                              ? ((vlTOPp->mips_cpu_bus__DOT__sign_imm_decode 
                                  << 2U) + vlTOPp->mips_cpu_bus__DOT__program_counter_plus_four_decode)
                              : ((IData)(4U) + vlTOPp->mips_cpu_bus__DOT__instr_address))),32);
        vcdp->fullBus(c+33,((vlTOPp->mips_cpu_bus__DOT__sign_imm_decode 
                             << 2U)),32);
        vcdp->fullBus(c+41,(vlTOPp->mips_cpu_bus__DOT__sign_imm_decode),32);
        vcdp->fullBit(c+49,(((~ (vlTOPp->mips_cpu_bus__DOT__instruction_decode 
                                 >> 0x1fU)) & ((~ (vlTOPp->mips_cpu_bus__DOT__instruction_decode 
                                                   >> 0x1eU)) 
                                               & ((~ 
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
                                                             & VL_GTS_III(1,32,32, 0U, vlTOPp->mips_cpu_bus__DOT__comparator_1)))))))))));
        vcdp->fullBus(c+57,(((IData)(vlTOPp->mips_cpu_bus__DOT__using_HI_LO_decode)
                              ? vlTOPp->mips_cpu_bus__DOT__register_file__DOT__LO_reg
                              : vlTOPp->mips_cpu_bus__DOT__register_file_output_A_decode)),32);
        vcdp->fullBus(c+65,(((IData)(vlTOPp->mips_cpu_bus__DOT__using_HI_LO_decode)
                              ? vlTOPp->mips_cpu_bus__DOT__register_file__DOT__HI_reg
                              : vlTOPp->mips_cpu_bus__DOT__register_file_output_B_decode)),32);
        vcdp->fullBus(c+73,(vlTOPp->mips_cpu_bus__DOT__forward_A_execute),3);
        vcdp->fullBus(c+81,(vlTOPp->mips_cpu_bus__DOT__forward_B_execute),3);
        vcdp->fullBus(c+89,(vlTOPp->mips_cpu_bus__DOT__byteenable_memory),4);
        vcdp->fullBus(c+97,(vlTOPp->mips_cpu_bus__DOT__src_A_ALU_execute),32);
        vcdp->fullBus(c+105,(vlTOPp->mips_cpu_bus__DOT__src_B_ALU_execute),32);
        vcdp->fullBus(c+113,(vlTOPp->mips_cpu_bus__DOT__write_data_execute),32);
        vcdp->fullBus(c+121,(vlTOPp->mips_cpu_bus__DOT__ALU_output_execute),32);
        vcdp->fullBus(c+129,(vlTOPp->mips_cpu_bus__DOT__ALU_HI_output_execute),32);
        vcdp->fullBus(c+137,(vlTOPp->mips_cpu_bus__DOT__ALU_LO_output_execute),32);
        vcdp->fullBus(c+145,(vlTOPp->mips_cpu_bus__DOT__result_writeback),32);
        vcdp->fullBus(c+153,(vlTOPp->mips_cpu_bus__DOT__read_data_writeback_filtered),32);
        vcdp->fullBus(c+161,(vlTOPp->mips_cpu_bus__DOT__alu_input_mux__DOT__src_mux_input_0),32);
        vcdp->fullBus(c+169,((0x1fU & (vlTOPp->mips_cpu_bus__DOT__src_A_ALU_execute 
                                       >> 6U))),5);
        vcdp->fullQuad(c+177,((((QData)((IData)(VL_NEGATE_I((IData)(
                                                                    (1U 
                                                                     & (vlTOPp->mips_cpu_bus__DOT__src_A_ALU_execute 
                                                                        >> 0x1fU)))))) 
                                << 0x20U) | (QData)((IData)(vlTOPp->mips_cpu_bus__DOT__src_A_ALU_execute)))),64);
        vcdp->fullQuad(c+193,((((QData)((IData)(VL_NEGATE_I((IData)(
                                                                    (1U 
                                                                     & (vlTOPp->mips_cpu_bus__DOT__src_B_ALU_execute 
                                                                        >> 0x1fU)))))) 
                                << 0x20U) | (QData)((IData)(vlTOPp->mips_cpu_bus__DOT__src_B_ALU_execute)))),64);
        vcdp->fullQuad(c+209,((QData)((IData)(vlTOPp->mips_cpu_bus__DOT__src_A_ALU_execute))),64);
        vcdp->fullQuad(c+225,((QData)((IData)(vlTOPp->mips_cpu_bus__DOT__src_B_ALU_execute))),64);
        vcdp->fullQuad(c+241,(vlTOPp->mips_cpu_bus__DOT__alu__DOT__ALU_HI_LO_output),64);
        vcdp->fullBus(c+257,(vlTOPp->mips_cpu_bus__DOT__memory_filter__DOT__temp_filtered),32);
        vcdp->fullBus(c+265,(vlTOPp->mips_cpu_bus__DOT__register_file_output_A_decode),32);
        vcdp->fullBus(c+273,(vlTOPp->mips_cpu_bus__DOT__register_file_output_B_decode),32);
        vcdp->fullBit(c+281,(vlTOPp->mips_cpu_bus__DOT__register_write_decode));
        vcdp->fullBit(c+289,(vlTOPp->mips_cpu_bus__DOT__memory_to_register_decode));
        vcdp->fullBit(c+297,(vlTOPp->mips_cpu_bus__DOT__memory_write_decode));
        vcdp->fullBus(c+305,(vlTOPp->mips_cpu_bus__DOT__ALU_src_B_decode),2);
        vcdp->fullBus(c+313,(vlTOPp->mips_cpu_bus__DOT__register_destination_decode),2);
        vcdp->fullBit(c+321,(vlTOPp->mips_cpu_bus__DOT__branch_decode));
        vcdp->fullBus(c+329,(vlTOPp->mips_cpu_bus__DOT__ALU_function_decode),6);
        vcdp->fullBit(c+337,(vlTOPp->mips_cpu_bus__DOT__program_counter_multiplexer_jump_decode));
        vcdp->fullBit(c+345,(vlTOPp->mips_cpu_bus__DOT__using_HI_LO_decode));
        vcdp->fullBit(c+353,(vlTOPp->mips_cpu_bus__DOT__j_instruction_decode));
        vcdp->fullBit(c+361,(vlTOPp->mips_cpu_bus__DOT__HI_register_write_decode));
        vcdp->fullBit(c+369,(vlTOPp->mips_cpu_bus__DOT__LO_register_write_decode));
        vcdp->fullBus(c+377,(vlTOPp->mips_cpu_bus__DOT__control_unit__DOT__op),6);
        vcdp->fullBus(c+385,(vlTOPp->mips_cpu_bus__DOT__control_unit__DOT__rt),5);
        vcdp->fullBus(c+393,(vlTOPp->mips_cpu_bus__DOT__control_unit__DOT__funct),6);
        vcdp->fullBit(c+401,(vlTOPp->mips_cpu_bus__DOT__program_counter_src_decode));
        vcdp->fullBus(c+409,(vlTOPp->mips_cpu_bus__DOT__comparator_1),32);
        vcdp->fullBus(c+417,(vlTOPp->mips_cpu_bus__DOT__comparator_2),32);
        vcdp->fullBit(c+425,(vlTOPp->mips_cpu_bus__DOT__stall_fetch));
        vcdp->fullBit(c+433,(vlTOPp->mips_cpu_bus__DOT__stall_decode));
        vcdp->fullBit(c+441,(vlTOPp->mips_cpu_bus__DOT__flush_execute_register));
        vcdp->fullBit(c+449,(vlTOPp->mips_cpu_bus__DOT__hazard_unit__DOT__lwstall));
        vcdp->fullBit(c+457,(vlTOPp->mips_cpu_bus__DOT__hazard_unit__DOT__branchstall));
        vcdp->fullBus(c+465,(vlTOPp->mips_cpu_bus__DOT__register_file__DOT__registers
                             [2U]),32);
        vcdp->fullBus(c+473,(vlTOPp->mips_cpu_bus__DOT__register_file__DOT__registers[0]),32);
        vcdp->fullBus(c+474,(vlTOPp->mips_cpu_bus__DOT__register_file__DOT__registers[1]),32);
        vcdp->fullBus(c+475,(vlTOPp->mips_cpu_bus__DOT__register_file__DOT__registers[2]),32);
        vcdp->fullBus(c+476,(vlTOPp->mips_cpu_bus__DOT__register_file__DOT__registers[3]),32);
        vcdp->fullBus(c+477,(vlTOPp->mips_cpu_bus__DOT__register_file__DOT__registers[4]),32);
        vcdp->fullBus(c+478,(vlTOPp->mips_cpu_bus__DOT__register_file__DOT__registers[5]),32);
        vcdp->fullBus(c+479,(vlTOPp->mips_cpu_bus__DOT__register_file__DOT__registers[6]),32);
        vcdp->fullBus(c+480,(vlTOPp->mips_cpu_bus__DOT__register_file__DOT__registers[7]),32);
        vcdp->fullBus(c+481,(vlTOPp->mips_cpu_bus__DOT__register_file__DOT__registers[8]),32);
        vcdp->fullBus(c+482,(vlTOPp->mips_cpu_bus__DOT__register_file__DOT__registers[9]),32);
        vcdp->fullBus(c+483,(vlTOPp->mips_cpu_bus__DOT__register_file__DOT__registers[10]),32);
        vcdp->fullBus(c+484,(vlTOPp->mips_cpu_bus__DOT__register_file__DOT__registers[11]),32);
        vcdp->fullBus(c+485,(vlTOPp->mips_cpu_bus__DOT__register_file__DOT__registers[12]),32);
        vcdp->fullBus(c+486,(vlTOPp->mips_cpu_bus__DOT__register_file__DOT__registers[13]),32);
        vcdp->fullBus(c+487,(vlTOPp->mips_cpu_bus__DOT__register_file__DOT__registers[14]),32);
        vcdp->fullBus(c+488,(vlTOPp->mips_cpu_bus__DOT__register_file__DOT__registers[15]),32);
        vcdp->fullBus(c+489,(vlTOPp->mips_cpu_bus__DOT__register_file__DOT__registers[16]),32);
        vcdp->fullBus(c+490,(vlTOPp->mips_cpu_bus__DOT__register_file__DOT__registers[17]),32);
        vcdp->fullBus(c+491,(vlTOPp->mips_cpu_bus__DOT__register_file__DOT__registers[18]),32);
        vcdp->fullBus(c+492,(vlTOPp->mips_cpu_bus__DOT__register_file__DOT__registers[19]),32);
        vcdp->fullBus(c+493,(vlTOPp->mips_cpu_bus__DOT__register_file__DOT__registers[20]),32);
        vcdp->fullBus(c+494,(vlTOPp->mips_cpu_bus__DOT__register_file__DOT__registers[21]),32);
        vcdp->fullBus(c+495,(vlTOPp->mips_cpu_bus__DOT__register_file__DOT__registers[22]),32);
        vcdp->fullBus(c+496,(vlTOPp->mips_cpu_bus__DOT__register_file__DOT__registers[23]),32);
        vcdp->fullBus(c+497,(vlTOPp->mips_cpu_bus__DOT__register_file__DOT__registers[24]),32);
        vcdp->fullBus(c+498,(vlTOPp->mips_cpu_bus__DOT__register_file__DOT__registers[25]),32);
        vcdp->fullBus(c+499,(vlTOPp->mips_cpu_bus__DOT__register_file__DOT__registers[26]),32);
        vcdp->fullBus(c+500,(vlTOPp->mips_cpu_bus__DOT__register_file__DOT__registers[27]),32);
        vcdp->fullBus(c+501,(vlTOPp->mips_cpu_bus__DOT__register_file__DOT__registers[28]),32);
        vcdp->fullBus(c+502,(vlTOPp->mips_cpu_bus__DOT__register_file__DOT__registers[29]),32);
        vcdp->fullBus(c+503,(vlTOPp->mips_cpu_bus__DOT__register_file__DOT__registers[30]),32);
        vcdp->fullBus(c+504,(vlTOPp->mips_cpu_bus__DOT__register_file__DOT__registers[31]),32);
        vcdp->fullBus(c+729,(vlTOPp->mips_cpu_bus__DOT__instr_address),32);
        vcdp->fullBus(c+737,(((IData)(4U) + vlTOPp->mips_cpu_bus__DOT__instr_address)),32);
        vcdp->fullBit(c+745,(vlTOPp->mips_cpu_bus__DOT__HALT_fetch));
        vcdp->fullBit(c+753,(vlTOPp->mips_cpu_bus__DOT__HALT_decode));
        vcdp->fullBus(c+761,(vlTOPp->mips_cpu_bus__DOT__program_counter_plus_four_decode),32);
        vcdp->fullBus(c+769,(vlTOPp->mips_cpu_bus__DOT__register_destination_execute),2);
        vcdp->fullBus(c+777,(vlTOPp->mips_cpu_bus__DOT__ALU_src_B_execute),2);
        vcdp->fullBus(c+785,(vlTOPp->mips_cpu_bus__DOT__ALU_function_execute),6);
        vcdp->fullBit(c+793,(vlTOPp->mips_cpu_bus__DOT__register_write_execute));
        vcdp->fullBit(c+801,(vlTOPp->mips_cpu_bus__DOT__program_counter_multiplexer_jump_execute));
        vcdp->fullBit(c+809,(vlTOPp->mips_cpu_bus__DOT__j_instruction_execute));
        vcdp->fullBit(c+817,(vlTOPp->mips_cpu_bus__DOT__using_HI_LO_execute));
        vcdp->fullBit(c+825,(vlTOPp->mips_cpu_bus__DOT__HALT_execute));
        vcdp->fullBus(c+833,(vlTOPp->mips_cpu_bus__DOT__op_execute),6);
        vcdp->fullBus(c+841,(vlTOPp->mips_cpu_bus__DOT__src_A_execute),32);
        vcdp->fullBus(c+849,(vlTOPp->mips_cpu_bus__DOT__src_B_execute),32);
        vcdp->fullBus(c+857,(vlTOPp->mips_cpu_bus__DOT__Rs_execute),5);
        vcdp->fullBus(c+865,(vlTOPp->mips_cpu_bus__DOT__Rt_execute),5);
        vcdp->fullBus(c+873,(vlTOPp->mips_cpu_bus__DOT__Rd_execute),5);
        vcdp->fullBus(c+881,(vlTOPp->mips_cpu_bus__DOT__sign_imm_execute),32);
        vcdp->fullBus(c+889,(((IData)(4U) + vlTOPp->mips_cpu_bus__DOT__program_counter_plus_four_execute)),32);
        vcdp->fullBus(c+897,(vlTOPp->mips_cpu_bus__DOT__program_counter_plus_four_execute),32);
        vcdp->fullBus(c+905,(vlTOPp->mips_cpu_bus__DOT__j_program_counter_execute),32);
        vcdp->fullBit(c+913,(vlTOPp->mips_cpu_bus__DOT__register_write_memory));
        vcdp->fullBus(c+921,(vlTOPp->mips_cpu_bus__DOT__write_register_memory),5);
        vcdp->fullBit(c+929,(vlTOPp->mips_cpu_bus__DOT__program_counter_multiplexer_jump_memory));
        vcdp->fullBit(c+937,(vlTOPp->mips_cpu_bus__DOT__j_instruction_memory));
        vcdp->fullBit(c+945,(vlTOPp->mips_cpu_bus__DOT__HALT_memory));
        vcdp->fullBus(c+953,(vlTOPp->mips_cpu_bus__DOT__op_memory),6);
        vcdp->fullBus(c+961,(vlTOPp->mips_cpu_bus__DOT__ALU_output_memory),32);
        vcdp->fullBus(c+969,(vlTOPp->mips_cpu_bus__DOT__write_data_memory),32);
        vcdp->fullBus(c+977,(((IData)(vlTOPp->mips_cpu_bus__DOT__j_instruction_memory)
                               ? vlTOPp->mips_cpu_bus__DOT__j_program_counter_memory
                               : vlTOPp->mips_cpu_bus__DOT__ALU_output_memory)),32);
        vcdp->fullBus(c+985,(vlTOPp->mips_cpu_bus__DOT__j_program_counter_memory),32);
        vcdp->fullBus(c+993,(vlTOPp->mips_cpu_bus__DOT__src_A_ALU_memory),32);
        vcdp->fullBit(c+1001,(vlTOPp->mips_cpu_bus__DOT__register_write_writeback));
        vcdp->fullBit(c+1009,(vlTOPp->mips_cpu_bus__DOT__memory_to_register_writeback));
        vcdp->fullBit(c+1017,(vlTOPp->mips_cpu_bus__DOT__HALT_writeback));
        vcdp->fullBus(c+1025,(vlTOPp->mips_cpu_bus__DOT__op_writeback),6);
        vcdp->fullBus(c+1033,(vlTOPp->mips_cpu_bus__DOT__byteenable_writeback),4);
        vcdp->fullBus(c+1041,(vlTOPp->mips_cpu_bus__DOT__src_A_ALU_writeback),32);
        vcdp->fullBus(c+1049,(vlTOPp->mips_cpu_bus__DOT__write_register_writeback),5);
        vcdp->fullBus(c+1057,(vlTOPp->mips_cpu_bus__DOT__ALU_output_writeback),32);
        vcdp->fullBus(c+1065,(((0xf0000000U & vlTOPp->mips_cpu_bus__DOT__program_counter_plus_four_decode) 
                               | (0xffffffcU & (vlTOPp->mips_cpu_bus__DOT__instruction_decode 
                                                << 2U)))),32);
        vcdp->fullBit(c+1073,((((0U != (0x1fU & (vlTOPp->mips_cpu_bus__DOT__instruction_decode 
                                                 >> 0x15U))) 
                                & ((0x1fU & (vlTOPp->mips_cpu_bus__DOT__instruction_decode 
                                             >> 0x15U)) 
                                   == (IData)(vlTOPp->mips_cpu_bus__DOT__write_register_memory))) 
                               & (IData)(vlTOPp->mips_cpu_bus__DOT__register_write_memory))));
        vcdp->fullBit(c+1081,((((0U != (0x1fU & (vlTOPp->mips_cpu_bus__DOT__instruction_decode 
                                                 >> 0x10U))) 
                                & ((0x1fU & (vlTOPp->mips_cpu_bus__DOT__instruction_decode 
                                             >> 0x10U)) 
                                   == (IData)(vlTOPp->mips_cpu_bus__DOT__write_register_memory))) 
                               & (IData)(vlTOPp->mips_cpu_bus__DOT__register_write_memory))));
        vcdp->fullBit(c+1089,(vlTOPp->mips_cpu_bus__DOT__internal_clk));
        vcdp->fullBus(c+1097,(vlTOPp->mips_cpu_bus__DOT__instruction_decode),32);
        vcdp->fullBus(c+1105,((0x3fU & (vlTOPp->mips_cpu_bus__DOT__instruction_decode 
                                        >> 0x1aU))),6);
        vcdp->fullBus(c+1113,((0x1fU & (vlTOPp->mips_cpu_bus__DOT__instruction_decode 
                                        >> 0x15U))),5);
        vcdp->fullBus(c+1121,((0x1fU & (vlTOPp->mips_cpu_bus__DOT__instruction_decode 
                                        >> 0x10U))),5);
        vcdp->fullBus(c+1129,((0x1fU & (vlTOPp->mips_cpu_bus__DOT__instruction_decode 
                                        >> 0xbU))),5);
        vcdp->fullBus(c+1137,((0xffffU & vlTOPp->mips_cpu_bus__DOT__instruction_decode)),16);
        vcdp->fullBus(c+1145,((0x3ffffffU & vlTOPp->mips_cpu_bus__DOT__instruction_decode)),26);
        vcdp->fullBus(c+1153,(vlTOPp->mips_cpu_bus__DOT__read_data_writeback),32);
        vcdp->fullBus(c+1161,(vlTOPp->mips_cpu_bus__DOT__fetch_state),2);
        vcdp->fullBit(c+1169,((1U & (~ (IData)(vlTOPp->mips_cpu_bus__DOT__internal_clk)))));
        vcdp->fullBus(c+1177,(vlTOPp->mips_cpu_bus__DOT__register_file__DOT__LO_reg),32);
        vcdp->fullBus(c+1185,(vlTOPp->mips_cpu_bus__DOT__register_file__DOT__HI_reg),32);
        vcdp->fullBit(c+1193,(vlTOPp->mips_cpu_bus__DOT__memory_to_register_execute));
        vcdp->fullBit(c+1201,(vlTOPp->mips_cpu_bus__DOT__memory_write_execute));
        vcdp->fullBit(c+1209,(vlTOPp->mips_cpu_bus__DOT__HI_register_write_execute));
        vcdp->fullBit(c+1217,(vlTOPp->mips_cpu_bus__DOT__LO_register_write_execute));
        vcdp->fullBit(c+1225,(vlTOPp->mips_cpu_bus__DOT__memory_to_register_memory));
        vcdp->fullBit(c+1233,(vlTOPp->mips_cpu_bus__DOT__memory_write_memory));
        vcdp->fullBit(c+1241,(vlTOPp->mips_cpu_bus__DOT__HI_register_write_memory));
        vcdp->fullBit(c+1249,(vlTOPp->mips_cpu_bus__DOT__LO_register_write_memory));
        vcdp->fullBus(c+1257,(vlTOPp->mips_cpu_bus__DOT__ALU_HI_output_memory),32);
        vcdp->fullBus(c+1265,(vlTOPp->mips_cpu_bus__DOT__ALU_LO_output_memory),32);
        vcdp->fullBit(c+1273,(vlTOPp->mips_cpu_bus__DOT__HI_register_write_writeback));
        vcdp->fullBit(c+1281,(vlTOPp->mips_cpu_bus__DOT__LO_register_write_writeback));
        vcdp->fullBus(c+1289,(vlTOPp->mips_cpu_bus__DOT__ALU_HI_output_writeback),32);
        vcdp->fullBus(c+1297,(vlTOPp->mips_cpu_bus__DOT__ALU_LO_output_writeback),32);
        vcdp->fullBit(c+1305,(vlTOPp->clk));
        vcdp->fullBit(c+1313,(vlTOPp->reset));
        vcdp->fullBit(c+1321,(vlTOPp->active));
        vcdp->fullBus(c+1329,(vlTOPp->register_v0),32);
        vcdp->fullBus(c+1337,(vlTOPp->address),32);
        vcdp->fullBit(c+1345,(vlTOPp->write));
        vcdp->fullBit(c+1353,(vlTOPp->read));
        vcdp->fullBit(c+1361,(vlTOPp->waitrequest));
        vcdp->fullBus(c+1369,(vlTOPp->writedata),32);
        vcdp->fullBus(c+1377,(vlTOPp->byteenable),4);
        vcdp->fullBus(c+1385,(vlTOPp->readdata),32);
        vcdp->fullBit(c+1393,(1U));
        vcdp->fullBus(c+1401,(4U),32);
        vcdp->fullBus(c+1409,(0x20U),32);
        vcdp->fullBus(c+1417,(5U),32);
        vcdp->fullBus(c+1425,(0x1fU),5);
        vcdp->fullBus(c+1433,(0U),5);
    }
}
