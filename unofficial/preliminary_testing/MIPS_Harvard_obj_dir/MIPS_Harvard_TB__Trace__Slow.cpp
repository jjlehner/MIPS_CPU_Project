// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "MIPS_Harvard_TB__Syms.h"


//======================

void MIPS_Harvard_TB::trace(VerilatedVcdC* tfp, int, int) {
    tfp->spTrace()->addCallback(&MIPS_Harvard_TB::traceInit, &MIPS_Harvard_TB::traceFull, &MIPS_Harvard_TB::traceChg, this);
}
void MIPS_Harvard_TB::traceInit(VerilatedVcd* vcdp, void* userthis, uint32_t code) {
    // Callback from vcd->open()
    MIPS_Harvard_TB* t = (MIPS_Harvard_TB*)userthis;
    MIPS_Harvard_TB__Syms* __restrict vlSymsp = t->__VlSymsp;  // Setup global symbol table
    if (!Verilated::calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
                        "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vcdp->scopeEscape(' ');
    t->traceInitThis(vlSymsp, vcdp, code);
    vcdp->scopeEscape('.');
}
void MIPS_Harvard_TB::traceFull(VerilatedVcd* vcdp, void* userthis, uint32_t code) {
    // Callback from vcd->dump()
    MIPS_Harvard_TB* t = (MIPS_Harvard_TB*)userthis;
    MIPS_Harvard_TB__Syms* __restrict vlSymsp = t->__VlSymsp;  // Setup global symbol table
    t->traceFullThis(vlSymsp, vcdp, code);
}

//======================


void MIPS_Harvard_TB::traceInitThis(MIPS_Harvard_TB__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    MIPS_Harvard_TB* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (0 && vcdp && c) {}  // Prevent unused
    vcdp->module(vlSymsp->name());  // Setup signal names
    // Body
    {
        vlTOPp->traceInitThis__1(vlSymsp, vcdp, code);
    }
}

void MIPS_Harvard_TB::traceFullThis(MIPS_Harvard_TB__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    MIPS_Harvard_TB* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
        vlTOPp->traceFullThis__1(vlSymsp, vcdp, code);
    }
    // Final
    vlTOPp->__Vm_traceActivity = 0U;
}

void MIPS_Harvard_TB::traceInitThis__1(MIPS_Harvard_TB__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    MIPS_Harvard_TB* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
        vcdp->declBit(c+1057,"clk", false,-1);
        vcdp->declBit(c+1065,"reset", false,-1);
        vcdp->declBit(c+1073,"active", false,-1);
        vcdp->declBus(c+1081,"register_v0", false,-1, 31,0);
        vcdp->declBit(c+1089,"clk_enable", false,-1);
        vcdp->declBus(c+1097,"instr_address", false,-1, 31,0);
        vcdp->declBus(c+1105,"instr_readdata", false,-1, 31,0);
        vcdp->declBus(c+1113,"data_address", false,-1, 31,0);
        vcdp->declBit(c+1121,"data_write", false,-1);
        vcdp->declBit(c+1129,"data_read", false,-1);
        vcdp->declBus(c+1137,"data_writedata", false,-1, 31,0);
        vcdp->declBus(c+1145,"data_readdata", false,-1, 31,0);
        vcdp->declBit(c+1057,"mips_cpu_harvard clk", false,-1);
        vcdp->declBit(c+1065,"mips_cpu_harvard reset", false,-1);
        vcdp->declBit(c+1073,"mips_cpu_harvard active", false,-1);
        vcdp->declBus(c+1081,"mips_cpu_harvard register_v0", false,-1, 31,0);
        vcdp->declBit(c+1089,"mips_cpu_harvard clk_enable", false,-1);
        vcdp->declBus(c+1097,"mips_cpu_harvard instr_address", false,-1, 31,0);
        vcdp->declBus(c+1105,"mips_cpu_harvard instr_readdata", false,-1, 31,0);
        vcdp->declBus(c+1113,"mips_cpu_harvard data_address", false,-1, 31,0);
        vcdp->declBit(c+1121,"mips_cpu_harvard data_write", false,-1);
        vcdp->declBit(c+1129,"mips_cpu_harvard data_read", false,-1);
        vcdp->declBus(c+1137,"mips_cpu_harvard data_writedata", false,-1, 31,0);
        vcdp->declBus(c+1145,"mips_cpu_harvard data_readdata", false,-1, 31,0);
        vcdp->declBit(c+1,"mips_cpu_harvard internal_clk", false,-1);
        vcdp->declBit(c+1153,"mips_cpu_harvard HI_LO_output", false,-1);
        vcdp->declBus(c+41,"mips_cpu_harvard program_counter_prime", false,-1, 31,0);
        vcdp->declBus(c+409,"mips_cpu_harvard program_counter_fetch", false,-1, 31,0);
        vcdp->declBus(c+417,"mips_cpu_harvard program_counter_plus_four_fetch", false,-1, 31,0);
        vcdp->declBus(c+1105,"mips_cpu_harvard instruction_fetch", false,-1, 31,0);
        vcdp->declBus(c+49,"mips_cpu_harvard program_counter_mux_1_out", false,-1, 31,0);
        vcdp->declBit(c+425,"mips_cpu_harvard halt", false,-1);
        vcdp->declBit(c+353,"mips_cpu_harvard program_counter_source_decode", false,-1);
        vcdp->declBit(c+57,"mips_cpu_harvard register_write_decode", false,-1);
        vcdp->declBit(c+65,"mips_cpu_harvard memory_to_register_decode", false,-1);
        vcdp->declBit(c+73,"mips_cpu_harvard memory_write_decode", false,-1);
        vcdp->declBit(c+81,"mips_cpu_harvard ALU_src_B_decode", false,-1);
        vcdp->declBit(c+89,"mips_cpu_harvard register_destination_decode", false,-1);
        vcdp->declBit(c+97,"mips_cpu_harvard branch_decode", false,-1);
        vcdp->declBit(c+105,"mips_cpu_harvard hi_lo_register_write_decode", false,-1);
        vcdp->declBit(c+361,"mips_cpu_harvard equal_decode", false,-1);
        vcdp->declBus(c+113,"mips_cpu_harvard ALU_function_decode", false,-1, 5,0);
        vcdp->declBit(c+121,"mips_cpu_harvard program_counter_multiplexer_jump_decode", false,-1);
        vcdp->declBit(c+1161,"mips_cpu_harvard flush_decode_execute_register", false,-1);
        vcdp->declBus(c+17,"mips_cpu_harvard program_counter_branch_decode", false,-1, 31,0);
        vcdp->declBus(c+433,"mips_cpu_harvard instruction_decode", false,-1, 31,0);
        vcdp->declBus(c+441,"mips_cpu_harvard program_counter_plus_four_decode", false,-1, 31,0);
        vcdp->declBus(c+449,"mips_cpu_harvard op", false,-1, 5,0);
        vcdp->declBus(c+457,"mips_cpu_harvard read_address_1", false,-1, 4,0);
        vcdp->declBus(c+457,"mips_cpu_harvard Rs_decode", false,-1, 4,0);
        vcdp->declBus(c+465,"mips_cpu_harvard read_address_2", false,-1, 4,0);
        vcdp->declBus(c+465,"mips_cpu_harvard Rt_decode", false,-1, 4,0);
        vcdp->declBus(c+473,"mips_cpu_harvard Rd_decode", false,-1, 4,0);
        vcdp->declBus(c+481,"mips_cpu_harvard immediate", false,-1, 15,0);
        vcdp->declBus(c+25,"mips_cpu_harvard shifter_output_decode", false,-1, 31,0);
        vcdp->declBus(c+369,"mips_cpu_harvard register_file_output_A_decode", false,-1, 31,0);
        vcdp->declBus(c+377,"mips_cpu_harvard register_file_output_B_decode", false,-1, 31,0);
        vcdp->declBus(c+385,"mips_cpu_harvard register_file_output_A_resolved_decode", false,-1, 31,0);
        vcdp->declBus(c+393,"mips_cpu_harvard register_file_output_B_resolved_decode", false,-1, 31,0);
        vcdp->declBus(c+33,"mips_cpu_harvard sign_imm_decode", false,-1, 31,0);
        vcdp->declBit(c+489,"mips_cpu_harvard register_destination_execute", false,-1);
        vcdp->declBit(c+497,"mips_cpu_harvard memory_to_register_execute", false,-1);
        vcdp->declBit(c+505,"mips_cpu_harvard memory_write_execute", false,-1);
        vcdp->declBus(c+129,"mips_cpu_harvard write_register_execute", false,-1, 4,0);
        vcdp->declBit(c+513,"mips_cpu_harvard ALU_src_B_execute", false,-1);
        vcdp->declBus(c+521,"mips_cpu_harvard ALU_function_execute", false,-1, 5,0);
        vcdp->declBit(c+961,"mips_cpu_harvard hi_lo_register_write_execute", false,-1);
        vcdp->declBit(c+969,"mips_cpu_harvard register_write_execute", false,-1);
        vcdp->declBit(c+529,"mips_cpu_harvard program_counter_multiplexer_jump_execute", false,-1);
        vcdp->declBus(c+537,"mips_cpu_harvard register_file_output_A_execute", false,-1, 31,0);
        vcdp->declBus(c+545,"mips_cpu_harvard register_file_output_B_execute", false,-1, 31,0);
        vcdp->declBus(c+137,"mips_cpu_harvard source_A_ALU_execute", false,-1, 31,0);
        vcdp->declBus(c+145,"mips_cpu_harvard source_B_ALU_execute", false,-1, 31,0);
        vcdp->declBus(c+153,"mips_cpu_harvard write_data_execute", false,-1, 31,0);
        vcdp->declBus(c+161,"mips_cpu_harvard ALU_output_execute", false,-1, 31,0);
        vcdp->declBus(c+169,"mips_cpu_harvard ALU_HI_output_execute", false,-1, 31,0);
        vcdp->declBus(c+177,"mips_cpu_harvard ALU_LO_output_execute", false,-1, 31,0);
        vcdp->declBus(c+553,"mips_cpu_harvard Rs_execute", false,-1, 4,0);
        vcdp->declBus(c+561,"mips_cpu_harvard Rt_execute", false,-1, 4,0);
        vcdp->declBus(c+569,"mips_cpu_harvard Rd_execute", false,-1, 4,0);
        vcdp->declBus(c+577,"mips_cpu_harvard sign_imm_execute", false,-1, 31,0);
        vcdp->declBit(c+977,"mips_cpu_harvard register_write_memory", false,-1);
        vcdp->declBus(c+985,"mips_cpu_harvard write_register_memory", false,-1, 4,0);
        vcdp->declBit(c+585,"mips_cpu_harvard memory_to_register_memory", false,-1);
        vcdp->declBit(c+593,"mips_cpu_harvard memory_write_memory", false,-1);
        vcdp->declBit(c+993,"mips_cpu_harvard hi_lo_register_write_memory", false,-1);
        vcdp->declBit(c+601,"mips_cpu_harvard program_counter_multiplexer_jump_memory", false,-1);
        vcdp->declBus(c+609,"mips_cpu_harvard ALU_output_memory", false,-1, 31,0);
        vcdp->declBus(c+1001,"mips_cpu_harvard ALU_HI_output_memory", false,-1, 31,0);
        vcdp->declBus(c+1009,"mips_cpu_harvard ALU_LO_output_memory", false,-1, 31,0);
        vcdp->declBus(c+1145,"mips_cpu_harvard read_data_memory", false,-1, 31,0);
        vcdp->declBus(c+617,"mips_cpu_harvard write_data_memory", false,-1, 31,0);
        vcdp->declBit(c+1017,"mips_cpu_harvard register_write_writeback", false,-1);
        vcdp->declBit(c+1025,"mips_cpu_harvard hi_lo_register_write_writeback", false,-1);
        vcdp->declBit(c+625,"mips_cpu_harvard memory_to_register_writeback", false,-1);
        vcdp->declBit(c+633,"mips_cpu_harvard program_counter_multiplexer_jump_writeback", false,-1);
        vcdp->declBus(c+1033,"mips_cpu_harvard write_register_writeback", false,-1, 4,0);
        vcdp->declBus(c+185,"mips_cpu_harvard result_writeback", false,-1, 31,0);
        vcdp->declBus(c+1041,"mips_cpu_harvard ALU_HI_output_writeback", false,-1, 31,0);
        vcdp->declBus(c+1049,"mips_cpu_harvard ALU_LO_output_writeback", false,-1, 31,0);
        vcdp->declBus(c+641,"mips_cpu_harvard ALU_output_writeback", false,-1, 31,0);
        vcdp->declBus(c+649,"mips_cpu_harvard read_data_writeback", false,-1, 31,0);
        vcdp->declBit(c+193,"mips_cpu_harvard stall_fetch", false,-1);
        vcdp->declBit(c+201,"mips_cpu_harvard stall_decode", false,-1);
        vcdp->declBit(c+673,"mips_cpu_harvard forward_A_decode", false,-1);
        vcdp->declBit(c+681,"mips_cpu_harvard forward_B_decode", false,-1);
        vcdp->declBit(c+209,"mips_cpu_harvard flush_execute_register", false,-1);
        vcdp->declBus(c+217,"mips_cpu_harvard forward_A_execute", false,-1, 1,0);
        vcdp->declBus(c+225,"mips_cpu_harvard forward_B_execute", false,-1, 1,0);
        vcdp->declBit(c+401,"mips_cpu_harvard flush_fetch_decode_register", false,-1);
        vcdp->declBit(c+1,"mips_cpu_harvard register_file clk", false,-1);
        vcdp->declBit(c+1169,"mips_cpu_harvard register_file pipelined", false,-1);
        vcdp->declBit(c+1153,"mips_cpu_harvard register_file HI_LO_output", false,-1);
        vcdp->declBit(c+1017,"mips_cpu_harvard register_file write_enable", false,-1);
        vcdp->declBit(c+1025,"mips_cpu_harvard register_file hi_lo_register_write_enable", false,-1);
        vcdp->declBus(c+457,"mips_cpu_harvard register_file read_address_1", false,-1, 4,0);
        vcdp->declBus(c+465,"mips_cpu_harvard register_file read_address_2", false,-1, 4,0);
        vcdp->declBus(c+1033,"mips_cpu_harvard register_file write_address", false,-1, 4,0);
        vcdp->declBus(c+185,"mips_cpu_harvard register_file write_data", false,-1, 31,0);
        vcdp->declBus(c+1041,"mips_cpu_harvard register_file HI_write_data", false,-1, 31,0);
        vcdp->declBus(c+1049,"mips_cpu_harvard register_file LO_write_data", false,-1, 31,0);
        vcdp->declBus(c+369,"mips_cpu_harvard register_file read_data_1", false,-1, 31,0);
        vcdp->declBus(c+377,"mips_cpu_harvard register_file read_data_2", false,-1, 31,0);
        vcdp->declBus(c+1081,"mips_cpu_harvard register_file read_register_2", false,-1, 31,0);
        {int i; for (i=0; i<32; i++) {
                vcdp->declBus(c+689+i*1,"mips_cpu_harvard register_file registers", true,(i+0), 31,0);}}
        vcdp->declBus(c+945,"mips_cpu_harvard register_file HI_reg", false,-1, 31,0);
        vcdp->declBus(c+953,"mips_cpu_harvard register_file LO_reg", false,-1, 31,0);
        vcdp->declBus(c+657,"mips_cpu_harvard register_file read_data_1_pre_mux", false,-1, 31,0);
        vcdp->declBus(c+665,"mips_cpu_harvard register_file read_data_2_pre_mux", false,-1, 31,0);
        vcdp->declBit(c+9,"mips_cpu_harvard register_file modified_write_clk", false,-1);
        vcdp->declBit(c+1,"mips_cpu_harvard pc clk", false,-1);
        vcdp->declBus(c+41,"mips_cpu_harvard pc address_input", false,-1, 31,0);
        vcdp->declBit(c+193,"mips_cpu_harvard pc enable", false,-1);
        vcdp->declBit(c+1065,"mips_cpu_harvard pc reset", false,-1);
        vcdp->declBit(c+425,"mips_cpu_harvard pc halt", false,-1);
        vcdp->declBus(c+409,"mips_cpu_harvard pc address_output", false,-1, 31,0);
        vcdp->declBus(c+409,"mips_cpu_harvard plus_four_adder a", false,-1, 31,0);
        vcdp->declBus(c+1177,"mips_cpu_harvard plus_four_adder b", false,-1, 31,0);
        vcdp->declBus(c+417,"mips_cpu_harvard plus_four_adder z", false,-1, 31,0);
        vcdp->declBus(c+1185,"mips_cpu_harvard program_counter_multiplexer BUS_WIDTH", false,-1, 31,0);
        vcdp->declBit(c+353,"mips_cpu_harvard program_counter_multiplexer control", false,-1);
        vcdp->declBus(c+417,"mips_cpu_harvard program_counter_multiplexer input_0", false,-1, 31,0);
        vcdp->declBus(c+17,"mips_cpu_harvard program_counter_multiplexer input_1", false,-1, 31,0);
        vcdp->declBus(c+49,"mips_cpu_harvard program_counter_multiplexer resolved", false,-1, 31,0);
        vcdp->declBus(c+1185,"mips_cpu_harvard program_counter_multiplexer_two BUS_WIDTH", false,-1, 31,0);
        vcdp->declBit(c+633,"mips_cpu_harvard program_counter_multiplexer_two control", false,-1);
        vcdp->declBus(c+49,"mips_cpu_harvard program_counter_multiplexer_two input_0", false,-1, 31,0);
        vcdp->declBus(c+185,"mips_cpu_harvard program_counter_multiplexer_two input_1", false,-1, 31,0);
        vcdp->declBus(c+41,"mips_cpu_harvard program_counter_multiplexer_two resolved", false,-1, 31,0);
        vcdp->declBit(c+1,"mips_cpu_harvard fetch_decode_register clk", false,-1);
        vcdp->declBit(c+201,"mips_cpu_harvard fetch_decode_register enable", false,-1);
        vcdp->declBit(c+401,"mips_cpu_harvard fetch_decode_register clear", false,-1);
        vcdp->declBit(c+1065,"mips_cpu_harvard fetch_decode_register reset", false,-1);
        vcdp->declBus(c+1105,"mips_cpu_harvard fetch_decode_register instruction_fetch", false,-1, 31,0);
        vcdp->declBus(c+417,"mips_cpu_harvard fetch_decode_register program_counter_plus_four_fetch", false,-1, 31,0);
        vcdp->declBus(c+433,"mips_cpu_harvard fetch_decode_register instruction_decode", false,-1, 31,0);
        vcdp->declBus(c+441,"mips_cpu_harvard fetch_decode_register program_counter_plus_four_decode", false,-1, 31,0);
        vcdp->declBus(c+433,"mips_cpu_harvard control_unit instruction", false,-1, 31,0);
        vcdp->declBit(c+57,"mips_cpu_harvard control_unit register_write", false,-1);
        vcdp->declBit(c+65,"mips_cpu_harvard control_unit memory_to_register", false,-1);
        vcdp->declBit(c+73,"mips_cpu_harvard control_unit memory_write", false,-1);
        vcdp->declBit(c+81,"mips_cpu_harvard control_unit ALU_src_B", false,-1);
        vcdp->declBit(c+89,"mips_cpu_harvard control_unit register_destination", false,-1);
        vcdp->declBit(c+97,"mips_cpu_harvard control_unit branch", false,-1);
        vcdp->declBit(c+105,"mips_cpu_harvard control_unit hi_lo_register_write", false,-1);
        vcdp->declBus(c+113,"mips_cpu_harvard control_unit ALU_function", false,-1, 5,0);
        vcdp->declBit(c+121,"mips_cpu_harvard control_unit program_counter_multiplexer_jump", false,-1);
        vcdp->declBus(c+233,"mips_cpu_harvard control_unit op", false,-1, 5,0);
        vcdp->declBus(c+465,"mips_cpu_harvard control_unit rt", false,-1, 4,0);
        vcdp->declBus(c+241,"mips_cpu_harvard control_unit funct", false,-1, 5,0);
        vcdp->declBus(c+1185,"mips_cpu_harvard register_file_output_A_mux BUS_WIDTH", false,-1, 31,0);
        vcdp->declBit(c+673,"mips_cpu_harvard register_file_output_A_mux control", false,-1);
        vcdp->declBus(c+369,"mips_cpu_harvard register_file_output_A_mux input_0", false,-1, 31,0);
        vcdp->declBus(c+609,"mips_cpu_harvard register_file_output_A_mux input_1", false,-1, 31,0);
        vcdp->declBus(c+385,"mips_cpu_harvard register_file_output_A_mux resolved", false,-1, 31,0);
        vcdp->declBus(c+1185,"mips_cpu_harvard register_file_output_B_mux BUS_WIDTH", false,-1, 31,0);
        vcdp->declBit(c+681,"mips_cpu_harvard register_file_output_B_mux control", false,-1);
        vcdp->declBus(c+377,"mips_cpu_harvard register_file_output_B_mux input_0", false,-1, 31,0);
        vcdp->declBus(c+609,"mips_cpu_harvard register_file_output_B_mux input_1", false,-1, 31,0);
        vcdp->declBus(c+393,"mips_cpu_harvard register_file_output_B_mux resolved", false,-1, 31,0);
        vcdp->declBus(c+449,"mips_cpu_harvard reg_output_comparator op", false,-1, 5,0);
        vcdp->declBus(c+465,"mips_cpu_harvard reg_output_comparator rt", false,-1, 4,0);
        vcdp->declBus(c+385,"mips_cpu_harvard reg_output_comparator a", false,-1, 31,0);
        vcdp->declBus(c+393,"mips_cpu_harvard reg_output_comparator b", false,-1, 31,0);
        vcdp->declBit(c+361,"mips_cpu_harvard reg_output_comparator c", false,-1);
        vcdp->declBit(c+97,"mips_cpu_harvard program_counter_source_and_gate_decode input_A", false,-1);
        vcdp->declBit(c+361,"mips_cpu_harvard program_counter_source_and_gate_decode input_B", false,-1);
        vcdp->declBit(c+353,"mips_cpu_harvard program_counter_source_and_gate_decode output_C", false,-1);
        vcdp->declBus(c+481,"mips_cpu_harvard sign_extender_decode short_input", false,-1, 15,0);
        vcdp->declBus(c+33,"mips_cpu_harvard sign_extender_decode extended_output", false,-1, 31,0);
        vcdp->declBus(c+1193,"mips_cpu_harvard shifter_decode shift_distance", false,-1, 31,0);
        vcdp->declBus(c+33,"mips_cpu_harvard shifter_decode shift_input", false,-1, 31,0);
        vcdp->declBus(c+25,"mips_cpu_harvard shifter_decode shift_output", false,-1, 31,0);
        vcdp->declBus(c+25,"mips_cpu_harvard adder_decode a", false,-1, 31,0);
        vcdp->declBus(c+441,"mips_cpu_harvard adder_decode b", false,-1, 31,0);
        vcdp->declBus(c+17,"mips_cpu_harvard adder_decode z", false,-1, 31,0);
        vcdp->declBit(c+1,"mips_cpu_harvard decode_execute_register clk", false,-1);
        vcdp->declBit(c+209,"mips_cpu_harvard decode_execute_register clear", false,-1);
        vcdp->declBit(c+1065,"mips_cpu_harvard decode_execute_register reset", false,-1);
        vcdp->declBit(c+57,"mips_cpu_harvard decode_execute_register register_write_decode", false,-1);
        vcdp->declBit(c+65,"mips_cpu_harvard decode_execute_register memory_to_register_decode", false,-1);
        vcdp->declBit(c+73,"mips_cpu_harvard decode_execute_register memory_write_decode", false,-1);
        vcdp->declBit(c+81,"mips_cpu_harvard decode_execute_register ALU_src_B_decode", false,-1);
        vcdp->declBit(c+89,"mips_cpu_harvard decode_execute_register register_destination_decode", false,-1);
        vcdp->declBit(c+105,"mips_cpu_harvard decode_execute_register hi_lo_register_write_decode", false,-1);
        vcdp->declBus(c+113,"mips_cpu_harvard decode_execute_register ALU_function_decode", false,-1, 5,0);
        vcdp->declBus(c+457,"mips_cpu_harvard decode_execute_register Rs_decode", false,-1, 4,0);
        vcdp->declBus(c+465,"mips_cpu_harvard decode_execute_register Rt_decode", false,-1, 4,0);
        vcdp->declBus(c+473,"mips_cpu_harvard decode_execute_register Rd_decode", false,-1, 4,0);
        vcdp->declBus(c+33,"mips_cpu_harvard decode_execute_register sign_imm_decode", false,-1, 31,0);
        vcdp->declBit(c+121,"mips_cpu_harvard decode_execute_register program_counter_multiplexer_jump_decode", false,-1);
        vcdp->declBit(c+969,"mips_cpu_harvard decode_execute_register register_write_execute", false,-1);
        vcdp->declBit(c+497,"mips_cpu_harvard decode_execute_register memory_to_register_execute", false,-1);
        vcdp->declBit(c+505,"mips_cpu_harvard decode_execute_register memory_write_execute", false,-1);
        vcdp->declBit(c+513,"mips_cpu_harvard decode_execute_register ALU_src_B_execute", false,-1);
        vcdp->declBit(c+489,"mips_cpu_harvard decode_execute_register register_destination_execute", false,-1);
        vcdp->declBit(c+961,"mips_cpu_harvard decode_execute_register hi_lo_register_write_execute", false,-1);
        vcdp->declBus(c+521,"mips_cpu_harvard decode_execute_register ALU_function_execute", false,-1, 5,0);
        vcdp->declBus(c+553,"mips_cpu_harvard decode_execute_register Rs_execute", false,-1, 4,0);
        vcdp->declBus(c+561,"mips_cpu_harvard decode_execute_register Rt_execute", false,-1, 4,0);
        vcdp->declBus(c+569,"mips_cpu_harvard decode_execute_register Rd_execute", false,-1, 4,0);
        vcdp->declBus(c+577,"mips_cpu_harvard decode_execute_register sign_imm_execute", false,-1, 31,0);
        vcdp->declBit(c+529,"mips_cpu_harvard decode_execute_register program_counter_multiplexer_jump_execute", false,-1);
        vcdp->declBus(c+369,"mips_cpu_harvard decode_execute_register read_data_one_decode", false,-1, 31,0);
        vcdp->declBus(c+377,"mips_cpu_harvard decode_execute_register read_data_two_decode", false,-1, 31,0);
        vcdp->declBus(c+537,"mips_cpu_harvard decode_execute_register read_data_one_execute", false,-1, 31,0);
        vcdp->declBus(c+545,"mips_cpu_harvard decode_execute_register read_data_two_execute", false,-1, 31,0);
        vcdp->declBus(c+1201,"mips_cpu_harvard write_register_execute_mux BUS_WIDTH", false,-1, 31,0);
        vcdp->declBit(c+489,"mips_cpu_harvard write_register_execute_mux control", false,-1);
        vcdp->declBus(c+561,"mips_cpu_harvard write_register_execute_mux input_0", false,-1, 4,0);
        vcdp->declBus(c+569,"mips_cpu_harvard write_register_execute_mux input_1", false,-1, 4,0);
        vcdp->declBus(c+129,"mips_cpu_harvard write_register_execute_mux resolved", false,-1, 4,0);
        vcdp->declBus(c+1185,"mips_cpu_harvard register_file_output_A_execute_mux BUS_WIDTH", false,-1, 31,0);
        vcdp->declBus(c+217,"mips_cpu_harvard register_file_output_A_execute_mux control", false,-1, 1,0);
        vcdp->declBus(c+537,"mips_cpu_harvard register_file_output_A_execute_mux input_0", false,-1, 31,0);
        vcdp->declBus(c+185,"mips_cpu_harvard register_file_output_A_execute_mux input_1", false,-1, 31,0);
        vcdp->declBus(c+609,"mips_cpu_harvard register_file_output_A_execute_mux input_2", false,-1, 31,0);
        vcdp->declBus(c+1049,"mips_cpu_harvard register_file_output_A_execute_mux input_3", false,-1, 31,0);
        vcdp->declBus(c+137,"mips_cpu_harvard register_file_output_A_execute_mux resolved", false,-1, 31,0);
        vcdp->declBus(c+1185,"mips_cpu_harvard register_file_output_B_execute_mux BUS_WIDTH", false,-1, 31,0);
        vcdp->declBus(c+225,"mips_cpu_harvard register_file_output_B_execute_mux control", false,-1, 1,0);
        vcdp->declBus(c+545,"mips_cpu_harvard register_file_output_B_execute_mux input_0", false,-1, 31,0);
        vcdp->declBus(c+185,"mips_cpu_harvard register_file_output_B_execute_mux input_1", false,-1, 31,0);
        vcdp->declBus(c+609,"mips_cpu_harvard register_file_output_B_execute_mux input_2", false,-1, 31,0);
        vcdp->declBus(c+1041,"mips_cpu_harvard register_file_output_B_execute_mux input_3", false,-1, 31,0);
        vcdp->declBus(c+153,"mips_cpu_harvard register_file_output_B_execute_mux resolved", false,-1, 31,0);
        vcdp->declBus(c+1185,"mips_cpu_harvard source_B_ALU_mux BUS_WIDTH", false,-1, 31,0);
        vcdp->declBit(c+513,"mips_cpu_harvard source_B_ALU_mux control", false,-1);
        vcdp->declBus(c+153,"mips_cpu_harvard source_B_ALU_mux input_0", false,-1, 31,0);
        vcdp->declBus(c+577,"mips_cpu_harvard source_B_ALU_mux input_1", false,-1, 31,0);
        vcdp->declBus(c+145,"mips_cpu_harvard source_B_ALU_mux resolved", false,-1, 31,0);
        vcdp->declBus(c+521,"mips_cpu_harvard alu ALU_operation", false,-1, 5,0);
        vcdp->declBus(c+137,"mips_cpu_harvard alu input_1", false,-1, 31,0);
        vcdp->declBus(c+145,"mips_cpu_harvard alu input_2", false,-1, 31,0);
        vcdp->declBus(c+161,"mips_cpu_harvard alu ALU_output", false,-1, 31,0);
        vcdp->declBus(c+169,"mips_cpu_harvard alu ALU_HI_output", false,-1, 31,0);
        vcdp->declBus(c+177,"mips_cpu_harvard alu ALU_LO_output", false,-1, 31,0);
        vcdp->declBus(c+249,"mips_cpu_harvard alu shift_amount", false,-1, 4,0);
        vcdp->declQuad(c+257,"mips_cpu_harvard alu sign_extened_input_1", false,-1, 63,0);
        vcdp->declQuad(c+273,"mips_cpu_harvard alu sign_extened_input_2", false,-1, 63,0);
        vcdp->declQuad(c+289,"mips_cpu_harvard alu extended_input_1", false,-1, 63,0);
        vcdp->declQuad(c+305,"mips_cpu_harvard alu extended_input_2", false,-1, 63,0);
        vcdp->declQuad(c+321,"mips_cpu_harvard alu ALU_HI_LO_output", false,-1, 63,0);
        vcdp->declBit(c+1,"mips_cpu_harvard execute_memory_register clk", false,-1);
        vcdp->declBit(c+1065,"mips_cpu_harvard execute_memory_register reset", false,-1);
        vcdp->declBit(c+969,"mips_cpu_harvard execute_memory_register register_write_execute", false,-1);
        vcdp->declBit(c+497,"mips_cpu_harvard execute_memory_register memory_to_register_execute", false,-1);
        vcdp->declBit(c+505,"mips_cpu_harvard execute_memory_register memory_write_execute", false,-1);
        vcdp->declBit(c+961,"mips_cpu_harvard execute_memory_register hi_lo_register_write_execute", false,-1);
        vcdp->declBit(c+529,"mips_cpu_harvard execute_memory_register program_counter_multiplexer_jump_execute", false,-1);
        vcdp->declBit(c+977,"mips_cpu_harvard execute_memory_register register_write_memory", false,-1);
        vcdp->declBit(c+585,"mips_cpu_harvard execute_memory_register memory_to_register_memory", false,-1);
        vcdp->declBit(c+593,"mips_cpu_harvard execute_memory_register memory_write_memory", false,-1);
        vcdp->declBit(c+993,"mips_cpu_harvard execute_memory_register hi_lo_register_write_memory", false,-1);
        vcdp->declBit(c+601,"mips_cpu_harvard execute_memory_register program_counter_multiplexer_jump_memory", false,-1);
        vcdp->declBus(c+161,"mips_cpu_harvard execute_memory_register ALU_output_execute", false,-1, 31,0);
        vcdp->declBus(c+169,"mips_cpu_harvard execute_memory_register ALU_HI_output_execute", false,-1, 31,0);
        vcdp->declBus(c+177,"mips_cpu_harvard execute_memory_register ALU_LO_output_execute", false,-1, 31,0);
        vcdp->declBus(c+153,"mips_cpu_harvard execute_memory_register write_data_execute", false,-1, 31,0);
        vcdp->declBus(c+129,"mips_cpu_harvard execute_memory_register write_register_execute", false,-1, 4,0);
        vcdp->declBus(c+609,"mips_cpu_harvard execute_memory_register ALU_output_memory", false,-1, 31,0);
        vcdp->declBus(c+1001,"mips_cpu_harvard execute_memory_register ALU_HI_output_memory", false,-1, 31,0);
        vcdp->declBus(c+1009,"mips_cpu_harvard execute_memory_register ALU_LO_output_memory", false,-1, 31,0);
        vcdp->declBus(c+617,"mips_cpu_harvard execute_memory_register write_data_memory", false,-1, 31,0);
        vcdp->declBus(c+985,"mips_cpu_harvard execute_memory_register write_register_memory", false,-1, 4,0);
        vcdp->declBit(c+1,"mips_cpu_harvard memory_writeback_register clk", false,-1);
        vcdp->declBit(c+1065,"mips_cpu_harvard memory_writeback_register reset", false,-1);
        vcdp->declBit(c+977,"mips_cpu_harvard memory_writeback_register register_write_memory", false,-1);
        vcdp->declBit(c+585,"mips_cpu_harvard memory_writeback_register memory_to_register_memory", false,-1);
        vcdp->declBit(c+993,"mips_cpu_harvard memory_writeback_register hi_lo_register_write_memory", false,-1);
        vcdp->declBit(c+601,"mips_cpu_harvard memory_writeback_register program_counter_multiplexer_jump_memory", false,-1);
        vcdp->declBit(c+1017,"mips_cpu_harvard memory_writeback_register register_write_writeback", false,-1);
        vcdp->declBit(c+625,"mips_cpu_harvard memory_writeback_register memory_to_register_writeback", false,-1);
        vcdp->declBit(c+1025,"mips_cpu_harvard memory_writeback_register hi_lo_register_write_writeback", false,-1);
        vcdp->declBit(c+633,"mips_cpu_harvard memory_writeback_register program_counter_multiplexer_jump_writeback", false,-1);
        vcdp->declBus(c+609,"mips_cpu_harvard memory_writeback_register ALU_output_memory", false,-1, 31,0);
        vcdp->declBus(c+985,"mips_cpu_harvard memory_writeback_register write_register_memory", false,-1, 4,0);
        vcdp->declBus(c+1001,"mips_cpu_harvard memory_writeback_register ALU_HI_output_memory", false,-1, 31,0);
        vcdp->declBus(c+1009,"mips_cpu_harvard memory_writeback_register ALU_LO_output_memory", false,-1, 31,0);
        vcdp->declBus(c+1145,"mips_cpu_harvard memory_writeback_register read_data_memory", false,-1, 31,0);
        vcdp->declBus(c+641,"mips_cpu_harvard memory_writeback_register ALU_output_writeback", false,-1, 31,0);
        vcdp->declBus(c+1033,"mips_cpu_harvard memory_writeback_register write_register_writeback", false,-1, 4,0);
        vcdp->declBus(c+1041,"mips_cpu_harvard memory_writeback_register ALU_HI_output_writeback", false,-1, 31,0);
        vcdp->declBus(c+1049,"mips_cpu_harvard memory_writeback_register ALU_LO_output_writeback", false,-1, 31,0);
        vcdp->declBus(c+649,"mips_cpu_harvard memory_writeback_register read_data_writeback", false,-1, 31,0);
        vcdp->declBus(c+1185,"mips_cpu_harvard writeback_mux BUS_WIDTH", false,-1, 31,0);
        vcdp->declBit(c+625,"mips_cpu_harvard writeback_mux control", false,-1);
        vcdp->declBus(c+641,"mips_cpu_harvard writeback_mux input_0", false,-1, 31,0);
        vcdp->declBus(c+649,"mips_cpu_harvard writeback_mux input_1", false,-1, 31,0);
        vcdp->declBus(c+185,"mips_cpu_harvard writeback_mux resolved", false,-1, 31,0);
        vcdp->declBit(c+97,"mips_cpu_harvard hazard_unit branch_decode", false,-1);
        vcdp->declBus(c+457,"mips_cpu_harvard hazard_unit Rs_decode", false,-1, 4,0);
        vcdp->declBus(c+465,"mips_cpu_harvard hazard_unit Rt_decode", false,-1, 4,0);
        vcdp->declBus(c+553,"mips_cpu_harvard hazard_unit Rs_execute", false,-1, 4,0);
        vcdp->declBus(c+561,"mips_cpu_harvard hazard_unit Rt_execute", false,-1, 4,0);
        vcdp->declBus(c+129,"mips_cpu_harvard hazard_unit write_register_execute", false,-1, 4,0);
        vcdp->declBit(c+497,"mips_cpu_harvard hazard_unit memory_to_register_execute", false,-1);
        vcdp->declBit(c+969,"mips_cpu_harvard hazard_unit register_write_execute", false,-1);
        vcdp->declBus(c+985,"mips_cpu_harvard hazard_unit write_register_memory", false,-1, 4,0);
        vcdp->declBit(c+585,"mips_cpu_harvard hazard_unit memory_to_register_memory", false,-1);
        vcdp->declBit(c+977,"mips_cpu_harvard hazard_unit register_write_memory", false,-1);
        vcdp->declBus(c+1033,"mips_cpu_harvard hazard_unit write_register_writeback", false,-1, 4,0);
        vcdp->declBit(c+1017,"mips_cpu_harvard hazard_unit register_write_writeback", false,-1);
        vcdp->declBit(c+633,"mips_cpu_harvard hazard_unit program_counter_multiplexer_jump_writeback", false,-1);
        vcdp->declBit(c+193,"mips_cpu_harvard hazard_unit stall_fetch", false,-1);
        vcdp->declBit(c+201,"mips_cpu_harvard hazard_unit stall_decode", false,-1);
        vcdp->declBit(c+673,"mips_cpu_harvard hazard_unit forward_register_file_output_1_decode", false,-1);
        vcdp->declBit(c+681,"mips_cpu_harvard hazard_unit forward_register_file_output_2_decode", false,-1);
        vcdp->declBit(c+209,"mips_cpu_harvard hazard_unit flush_execute_register", false,-1);
        vcdp->declBus(c+217,"mips_cpu_harvard hazard_unit forward_register_file_output_1_execute", false,-1, 1,0);
        vcdp->declBus(c+225,"mips_cpu_harvard hazard_unit forward_register_file_output_2_execute", false,-1, 1,0);
        vcdp->declBit(c+337,"mips_cpu_harvard hazard_unit lwstall", false,-1);
        vcdp->declBit(c+345,"mips_cpu_harvard hazard_unit branchstall", false,-1);
        vcdp->declBit(c+633,"mips_cpu_harvard or_gate input_A", false,-1);
        vcdp->declBit(c+353,"mips_cpu_harvard or_gate input_B", false,-1);
        vcdp->declBit(c+401,"mips_cpu_harvard or_gate output_C", false,-1);
    }
}

void MIPS_Harvard_TB::traceFullThis__1(MIPS_Harvard_TB__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    MIPS_Harvard_TB* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
        vcdp->fullBit(c+1,(vlTOPp->mips_cpu_harvard__DOT__internal_clk));
        vcdp->fullBit(c+9,((1U & (~ (IData)(vlTOPp->mips_cpu_harvard__DOT__internal_clk)))));
        vcdp->fullBus(c+17,(((vlTOPp->mips_cpu_harvard__DOT__sign_imm_decode 
                              << 2U) + vlTOPp->mips_cpu_harvard__DOT__program_counter_plus_four_decode)),32);
        vcdp->fullBus(c+25,((vlTOPp->mips_cpu_harvard__DOT__sign_imm_decode 
                             << 2U)),32);
        vcdp->fullBus(c+33,(vlTOPp->mips_cpu_harvard__DOT__sign_imm_decode),32);
        vcdp->fullBus(c+41,(((IData)(vlTOPp->mips_cpu_harvard__DOT__program_counter_multiplexer_jump_writeback)
                              ? vlTOPp->mips_cpu_harvard__DOT__result_writeback
                              : ((IData)(vlTOPp->mips_cpu_harvard__DOT__program_counter_source_decode)
                                  ? ((vlTOPp->mips_cpu_harvard__DOT__sign_imm_decode 
                                      << 2U) + vlTOPp->mips_cpu_harvard__DOT__program_counter_plus_four_decode)
                                  : ((IData)(4U) + vlTOPp->mips_cpu_harvard__DOT__program_counter_fetch)))),32);
        vcdp->fullBus(c+49,(((IData)(vlTOPp->mips_cpu_harvard__DOT__program_counter_source_decode)
                              ? ((vlTOPp->mips_cpu_harvard__DOT__sign_imm_decode 
                                  << 2U) + vlTOPp->mips_cpu_harvard__DOT__program_counter_plus_four_decode)
                              : ((IData)(4U) + vlTOPp->mips_cpu_harvard__DOT__program_counter_fetch))),32);
        vcdp->fullBit(c+57,(vlTOPp->mips_cpu_harvard__DOT__register_write_decode));
        vcdp->fullBit(c+65,(vlTOPp->mips_cpu_harvard__DOT__memory_to_register_decode));
        vcdp->fullBit(c+73,(vlTOPp->mips_cpu_harvard__DOT__memory_write_decode));
        vcdp->fullBit(c+81,(vlTOPp->mips_cpu_harvard__DOT__ALU_src_B_decode));
        vcdp->fullBit(c+89,(vlTOPp->mips_cpu_harvard__DOT__register_destination_decode));
        vcdp->fullBit(c+97,(vlTOPp->mips_cpu_harvard__DOT__branch_decode));
        vcdp->fullBit(c+105,(vlTOPp->mips_cpu_harvard__DOT__hi_lo_register_write_decode));
        vcdp->fullBus(c+113,(vlTOPp->mips_cpu_harvard__DOT__ALU_function_decode),6);
        vcdp->fullBit(c+121,(vlTOPp->mips_cpu_harvard__DOT__program_counter_multiplexer_jump_decode));
        vcdp->fullBus(c+129,(vlTOPp->mips_cpu_harvard__DOT__write_register_execute),5);
        vcdp->fullBus(c+137,(vlTOPp->mips_cpu_harvard__DOT__source_A_ALU_execute),32);
        vcdp->fullBus(c+145,(vlTOPp->mips_cpu_harvard__DOT__source_B_ALU_execute),32);
        vcdp->fullBus(c+153,(vlTOPp->mips_cpu_harvard__DOT__write_data_execute),32);
        vcdp->fullBus(c+161,(vlTOPp->mips_cpu_harvard__DOT__ALU_output_execute),32);
        vcdp->fullBus(c+169,(vlTOPp->mips_cpu_harvard__DOT__ALU_HI_output_execute),32);
        vcdp->fullBus(c+177,(vlTOPp->mips_cpu_harvard__DOT__ALU_LO_output_execute),32);
        vcdp->fullBus(c+185,(vlTOPp->mips_cpu_harvard__DOT__result_writeback),32);
        vcdp->fullBit(c+193,(vlTOPp->mips_cpu_harvard__DOT__stall_fetch));
        vcdp->fullBit(c+201,(vlTOPp->mips_cpu_harvard__DOT__stall_decode));
        vcdp->fullBit(c+209,(vlTOPp->mips_cpu_harvard__DOT__flush_execute_register));
        vcdp->fullBus(c+217,(vlTOPp->mips_cpu_harvard__DOT__forward_A_execute),2);
        vcdp->fullBus(c+225,(vlTOPp->mips_cpu_harvard__DOT__forward_B_execute),2);
        vcdp->fullBus(c+233,(vlTOPp->mips_cpu_harvard__DOT__control_unit__DOT__op),6);
        vcdp->fullBus(c+241,(vlTOPp->mips_cpu_harvard__DOT__control_unit__DOT__funct),6);
        vcdp->fullBus(c+249,((0x1fU & (vlTOPp->mips_cpu_harvard__DOT__source_A_ALU_execute 
                                       >> 6U))),5);
        vcdp->fullQuad(c+257,((((QData)((IData)(VL_NEGATE_I((IData)(
                                                                    (1U 
                                                                     & (vlTOPp->mips_cpu_harvard__DOT__source_A_ALU_execute 
                                                                        >> 0x1fU)))))) 
                                << 0x20U) | (QData)((IData)(vlTOPp->mips_cpu_harvard__DOT__source_A_ALU_execute)))),64);
        vcdp->fullQuad(c+273,((((QData)((IData)(VL_NEGATE_I((IData)(
                                                                    (1U 
                                                                     & (vlTOPp->mips_cpu_harvard__DOT__source_B_ALU_execute 
                                                                        >> 0x1fU)))))) 
                                << 0x20U) | (QData)((IData)(vlTOPp->mips_cpu_harvard__DOT__source_B_ALU_execute)))),64);
        vcdp->fullQuad(c+289,((QData)((IData)(vlTOPp->mips_cpu_harvard__DOT__source_A_ALU_execute))),64);
        vcdp->fullQuad(c+305,((QData)((IData)(vlTOPp->mips_cpu_harvard__DOT__source_B_ALU_execute))),64);
        vcdp->fullQuad(c+321,(vlTOPp->mips_cpu_harvard__DOT__alu__DOT__ALU_HI_LO_output),64);
        vcdp->fullBit(c+337,(vlTOPp->mips_cpu_harvard__DOT__hazard_unit__DOT__lwstall));
        vcdp->fullBit(c+345,(vlTOPp->mips_cpu_harvard__DOT__hazard_unit__DOT__branchstall));
        vcdp->fullBit(c+353,(vlTOPp->mips_cpu_harvard__DOT__program_counter_source_decode));
        vcdp->fullBit(c+361,(vlTOPp->mips_cpu_harvard__DOT__equal_decode));
        vcdp->fullBus(c+369,(vlTOPp->mips_cpu_harvard__DOT__register_file_output_A_decode),32);
        vcdp->fullBus(c+377,(vlTOPp->mips_cpu_harvard__DOT__register_file_output_B_decode),32);
        vcdp->fullBus(c+385,(vlTOPp->mips_cpu_harvard__DOT__register_file_output_A_resolved_decode),32);
        vcdp->fullBus(c+393,(vlTOPp->mips_cpu_harvard__DOT__register_file_output_B_resolved_decode),32);
        vcdp->fullBit(c+401,(vlTOPp->mips_cpu_harvard__DOT__flush_fetch_decode_register));
        vcdp->fullBus(c+409,(vlTOPp->mips_cpu_harvard__DOT__program_counter_fetch),32);
        vcdp->fullBus(c+417,(((IData)(4U) + vlTOPp->mips_cpu_harvard__DOT__program_counter_fetch)),32);
        vcdp->fullBit(c+425,((0U == vlTOPp->mips_cpu_harvard__DOT__program_counter_fetch)));
        vcdp->fullBus(c+433,(vlTOPp->mips_cpu_harvard__DOT__instruction_decode),32);
        vcdp->fullBus(c+441,(vlTOPp->mips_cpu_harvard__DOT__program_counter_plus_four_decode),32);
        vcdp->fullBus(c+449,((0x3fU & (vlTOPp->mips_cpu_harvard__DOT__instruction_decode 
                                       >> 0x1aU))),6);
        vcdp->fullBus(c+457,((0x1fU & (vlTOPp->mips_cpu_harvard__DOT__instruction_decode 
                                       >> 0x15U))),5);
        vcdp->fullBus(c+465,((0x1fU & (vlTOPp->mips_cpu_harvard__DOT__instruction_decode 
                                       >> 0x10U))),5);
        vcdp->fullBus(c+473,((0x1fU & (vlTOPp->mips_cpu_harvard__DOT__instruction_decode 
                                       >> 0xbU))),5);
        vcdp->fullBus(c+481,((0xffffU & vlTOPp->mips_cpu_harvard__DOT__instruction_decode)),16);
        vcdp->fullBit(c+489,(vlTOPp->mips_cpu_harvard__DOT__register_destination_execute));
        vcdp->fullBit(c+497,(vlTOPp->mips_cpu_harvard__DOT__memory_to_register_execute));
        vcdp->fullBit(c+505,(vlTOPp->mips_cpu_harvard__DOT__memory_write_execute));
        vcdp->fullBit(c+513,(vlTOPp->mips_cpu_harvard__DOT__ALU_src_B_execute));
        vcdp->fullBus(c+521,(vlTOPp->mips_cpu_harvard__DOT__ALU_function_execute),6);
        vcdp->fullBit(c+529,(vlTOPp->mips_cpu_harvard__DOT__program_counter_multiplexer_jump_execute));
        vcdp->fullBus(c+537,(vlTOPp->mips_cpu_harvard__DOT__register_file_output_A_execute),32);
        vcdp->fullBus(c+545,(vlTOPp->mips_cpu_harvard__DOT__register_file_output_B_execute),32);
        vcdp->fullBus(c+553,(vlTOPp->mips_cpu_harvard__DOT__Rs_execute),5);
        vcdp->fullBus(c+561,(vlTOPp->mips_cpu_harvard__DOT__Rt_execute),5);
        vcdp->fullBus(c+569,(vlTOPp->mips_cpu_harvard__DOT__Rd_execute),5);
        vcdp->fullBus(c+577,(vlTOPp->mips_cpu_harvard__DOT__sign_imm_execute),32);
        vcdp->fullBit(c+585,(vlTOPp->mips_cpu_harvard__DOT__memory_to_register_memory));
        vcdp->fullBit(c+593,(vlTOPp->mips_cpu_harvard__DOT__memory_write_memory));
        vcdp->fullBit(c+601,(vlTOPp->mips_cpu_harvard__DOT__program_counter_multiplexer_jump_memory));
        vcdp->fullBus(c+609,(vlTOPp->mips_cpu_harvard__DOT__ALU_output_memory),32);
        vcdp->fullBus(c+617,(vlTOPp->mips_cpu_harvard__DOT__write_data_memory),32);
        vcdp->fullBit(c+625,(vlTOPp->mips_cpu_harvard__DOT__memory_to_register_writeback));
        vcdp->fullBit(c+633,(vlTOPp->mips_cpu_harvard__DOT__program_counter_multiplexer_jump_writeback));
        vcdp->fullBus(c+641,(vlTOPp->mips_cpu_harvard__DOT__ALU_output_writeback),32);
        vcdp->fullBus(c+649,(vlTOPp->mips_cpu_harvard__DOT__read_data_writeback),32);
        vcdp->fullBus(c+657,(((0U != (0x1fU & (vlTOPp->mips_cpu_harvard__DOT__instruction_decode 
                                               >> 0x15U)))
                               ? vlTOPp->mips_cpu_harvard__DOT__register_file__DOT__registers
                              [(0x1fU & (vlTOPp->mips_cpu_harvard__DOT__instruction_decode 
                                         >> 0x15U))]
                               : 0U)),32);
        vcdp->fullBus(c+665,(((0U != (0x1fU & (vlTOPp->mips_cpu_harvard__DOT__instruction_decode 
                                               >> 0x10U)))
                               ? vlTOPp->mips_cpu_harvard__DOT__register_file__DOT__registers
                              [(0x1fU & (vlTOPp->mips_cpu_harvard__DOT__instruction_decode 
                                         >> 0x10U))]
                               : 0U)),32);
        vcdp->fullBit(c+673,((((0U != (0x1fU & (vlTOPp->mips_cpu_harvard__DOT__instruction_decode 
                                                >> 0x15U))) 
                               & ((0x1fU & (vlTOPp->mips_cpu_harvard__DOT__instruction_decode 
                                            >> 0x15U)) 
                                  == (IData)(vlTOPp->mips_cpu_harvard__DOT__write_register_memory))) 
                              & (IData)(vlTOPp->mips_cpu_harvard__DOT__register_write_memory))));
        vcdp->fullBit(c+681,((((0U != (0x1fU & (vlTOPp->mips_cpu_harvard__DOT__instruction_decode 
                                                >> 0x10U))) 
                               & ((0x1fU & (vlTOPp->mips_cpu_harvard__DOT__instruction_decode 
                                            >> 0x10U)) 
                                  == (IData)(vlTOPp->mips_cpu_harvard__DOT__write_register_memory))) 
                              & (IData)(vlTOPp->mips_cpu_harvard__DOT__register_write_memory))));
        vcdp->fullBus(c+689,(vlTOPp->mips_cpu_harvard__DOT__register_file__DOT__registers[0]),32);
        vcdp->fullBus(c+690,(vlTOPp->mips_cpu_harvard__DOT__register_file__DOT__registers[1]),32);
        vcdp->fullBus(c+691,(vlTOPp->mips_cpu_harvard__DOT__register_file__DOT__registers[2]),32);
        vcdp->fullBus(c+692,(vlTOPp->mips_cpu_harvard__DOT__register_file__DOT__registers[3]),32);
        vcdp->fullBus(c+693,(vlTOPp->mips_cpu_harvard__DOT__register_file__DOT__registers[4]),32);
        vcdp->fullBus(c+694,(vlTOPp->mips_cpu_harvard__DOT__register_file__DOT__registers[5]),32);
        vcdp->fullBus(c+695,(vlTOPp->mips_cpu_harvard__DOT__register_file__DOT__registers[6]),32);
        vcdp->fullBus(c+696,(vlTOPp->mips_cpu_harvard__DOT__register_file__DOT__registers[7]),32);
        vcdp->fullBus(c+697,(vlTOPp->mips_cpu_harvard__DOT__register_file__DOT__registers[8]),32);
        vcdp->fullBus(c+698,(vlTOPp->mips_cpu_harvard__DOT__register_file__DOT__registers[9]),32);
        vcdp->fullBus(c+699,(vlTOPp->mips_cpu_harvard__DOT__register_file__DOT__registers[10]),32);
        vcdp->fullBus(c+700,(vlTOPp->mips_cpu_harvard__DOT__register_file__DOT__registers[11]),32);
        vcdp->fullBus(c+701,(vlTOPp->mips_cpu_harvard__DOT__register_file__DOT__registers[12]),32);
        vcdp->fullBus(c+702,(vlTOPp->mips_cpu_harvard__DOT__register_file__DOT__registers[13]),32);
        vcdp->fullBus(c+703,(vlTOPp->mips_cpu_harvard__DOT__register_file__DOT__registers[14]),32);
        vcdp->fullBus(c+704,(vlTOPp->mips_cpu_harvard__DOT__register_file__DOT__registers[15]),32);
        vcdp->fullBus(c+705,(vlTOPp->mips_cpu_harvard__DOT__register_file__DOT__registers[16]),32);
        vcdp->fullBus(c+706,(vlTOPp->mips_cpu_harvard__DOT__register_file__DOT__registers[17]),32);
        vcdp->fullBus(c+707,(vlTOPp->mips_cpu_harvard__DOT__register_file__DOT__registers[18]),32);
        vcdp->fullBus(c+708,(vlTOPp->mips_cpu_harvard__DOT__register_file__DOT__registers[19]),32);
        vcdp->fullBus(c+709,(vlTOPp->mips_cpu_harvard__DOT__register_file__DOT__registers[20]),32);
        vcdp->fullBus(c+710,(vlTOPp->mips_cpu_harvard__DOT__register_file__DOT__registers[21]),32);
        vcdp->fullBus(c+711,(vlTOPp->mips_cpu_harvard__DOT__register_file__DOT__registers[22]),32);
        vcdp->fullBus(c+712,(vlTOPp->mips_cpu_harvard__DOT__register_file__DOT__registers[23]),32);
        vcdp->fullBus(c+713,(vlTOPp->mips_cpu_harvard__DOT__register_file__DOT__registers[24]),32);
        vcdp->fullBus(c+714,(vlTOPp->mips_cpu_harvard__DOT__register_file__DOT__registers[25]),32);
        vcdp->fullBus(c+715,(vlTOPp->mips_cpu_harvard__DOT__register_file__DOT__registers[26]),32);
        vcdp->fullBus(c+716,(vlTOPp->mips_cpu_harvard__DOT__register_file__DOT__registers[27]),32);
        vcdp->fullBus(c+717,(vlTOPp->mips_cpu_harvard__DOT__register_file__DOT__registers[28]),32);
        vcdp->fullBus(c+718,(vlTOPp->mips_cpu_harvard__DOT__register_file__DOT__registers[29]),32);
        vcdp->fullBus(c+719,(vlTOPp->mips_cpu_harvard__DOT__register_file__DOT__registers[30]),32);
        vcdp->fullBus(c+720,(vlTOPp->mips_cpu_harvard__DOT__register_file__DOT__registers[31]),32);
        vcdp->fullBus(c+945,(vlTOPp->mips_cpu_harvard__DOT__register_file__DOT__HI_reg),32);
        vcdp->fullBus(c+953,(vlTOPp->mips_cpu_harvard__DOT__register_file__DOT__LO_reg),32);
        vcdp->fullBit(c+961,(vlTOPp->mips_cpu_harvard__DOT__hi_lo_register_write_execute));
        vcdp->fullBit(c+969,(vlTOPp->mips_cpu_harvard__DOT__register_write_execute));
        vcdp->fullBit(c+977,(vlTOPp->mips_cpu_harvard__DOT__register_write_memory));
        vcdp->fullBus(c+985,(vlTOPp->mips_cpu_harvard__DOT__write_register_memory),5);
        vcdp->fullBit(c+993,(vlTOPp->mips_cpu_harvard__DOT__hi_lo_register_write_memory));
        vcdp->fullBus(c+1001,(vlTOPp->mips_cpu_harvard__DOT__ALU_HI_output_memory),32);
        vcdp->fullBus(c+1009,(vlTOPp->mips_cpu_harvard__DOT__ALU_LO_output_memory),32);
        vcdp->fullBit(c+1017,(vlTOPp->mips_cpu_harvard__DOT__register_write_writeback));
        vcdp->fullBit(c+1025,(vlTOPp->mips_cpu_harvard__DOT__hi_lo_register_write_writeback));
        vcdp->fullBus(c+1033,(vlTOPp->mips_cpu_harvard__DOT__write_register_writeback),5);
        vcdp->fullBus(c+1041,(vlTOPp->mips_cpu_harvard__DOT__ALU_HI_output_writeback),32);
        vcdp->fullBus(c+1049,(vlTOPp->mips_cpu_harvard__DOT__ALU_LO_output_writeback),32);
        vcdp->fullBit(c+1057,(vlTOPp->clk));
        vcdp->fullBit(c+1065,(vlTOPp->reset));
        vcdp->fullBit(c+1073,(vlTOPp->active));
        vcdp->fullBus(c+1081,(vlTOPp->register_v0),32);
        vcdp->fullBit(c+1089,(vlTOPp->clk_enable));
        vcdp->fullBus(c+1097,(vlTOPp->instr_address),32);
        vcdp->fullBus(c+1105,(vlTOPp->instr_readdata),32);
        vcdp->fullBus(c+1113,(vlTOPp->data_address),32);
        vcdp->fullBit(c+1121,(vlTOPp->data_write));
        vcdp->fullBit(c+1129,(vlTOPp->data_read));
        vcdp->fullBus(c+1137,(vlTOPp->data_writedata),32);
        vcdp->fullBus(c+1145,(vlTOPp->data_readdata),32);
        vcdp->fullBit(c+1153,(vlTOPp->mips_cpu_harvard__DOT__HI_LO_output));
        vcdp->fullBit(c+1161,(vlTOPp->mips_cpu_harvard__DOT__flush_decode_execute_register));
        vcdp->fullBit(c+1169,(1U));
        vcdp->fullBus(c+1177,(4U),32);
        vcdp->fullBus(c+1185,(0x20U),32);
        vcdp->fullBus(c+1193,(2U),32);
        vcdp->fullBus(c+1201,(5U),32);
    }
}
