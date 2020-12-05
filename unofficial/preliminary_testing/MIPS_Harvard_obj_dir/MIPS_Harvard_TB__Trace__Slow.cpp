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
        vcdp->declBit(c+1041,"clk", false,-1);
        vcdp->declBit(c+1049,"reset", false,-1);
        vcdp->declBit(c+1057,"active", false,-1);
        vcdp->declBus(c+1065,"register_v0", false,-1, 31,0);
        vcdp->declBit(c+1073,"clk_enable", false,-1);
        vcdp->declBus(c+1081,"instr_address", false,-1, 31,0);
        vcdp->declBus(c+1089,"instr_readdata", false,-1, 31,0);
        vcdp->declBus(c+1097,"data_address", false,-1, 31,0);
        vcdp->declBit(c+1105,"data_write", false,-1);
        vcdp->declBit(c+1113,"data_read", false,-1);
        vcdp->declBus(c+1121,"data_writedata", false,-1, 31,0);
        vcdp->declBus(c+1129,"data_readdata", false,-1, 31,0);
        vcdp->declBit(c+1041,"mips_cpu clk", false,-1);
        vcdp->declBit(c+1049,"mips_cpu reset", false,-1);
        vcdp->declBit(c+1057,"mips_cpu active", false,-1);
        vcdp->declBus(c+1065,"mips_cpu register_v0", false,-1, 31,0);
        vcdp->declBit(c+1073,"mips_cpu clk_enable", false,-1);
        vcdp->declBus(c+1081,"mips_cpu instr_address", false,-1, 31,0);
        vcdp->declBus(c+1089,"mips_cpu instr_readdata", false,-1, 31,0);
        vcdp->declBus(c+1097,"mips_cpu data_address", false,-1, 31,0);
        vcdp->declBit(c+1105,"mips_cpu data_write", false,-1);
        vcdp->declBit(c+1113,"mips_cpu data_read", false,-1);
        vcdp->declBus(c+1121,"mips_cpu data_writedata", false,-1, 31,0);
        vcdp->declBus(c+1129,"mips_cpu data_readdata", false,-1, 31,0);
        vcdp->declBit(c+1,"mips_cpu internal_clk", false,-1);
        vcdp->declBit(c+1137,"mips_cpu HI_LO_output", false,-1);
        vcdp->declBus(c+337,"mips_cpu program_counter_prime", false,-1, 31,0);
        vcdp->declBus(c+409,"mips_cpu program_counter_fetch", false,-1, 31,0);
        vcdp->declBus(c+417,"mips_cpu program_counter_plus_four_fetch", false,-1, 31,0);
        vcdp->declBus(c+1089,"mips_cpu instruction_fetch", false,-1, 31,0);
        vcdp->declBus(c+345,"mips_cpu program_counter_mux_1_out", false,-1, 31,0);
        vcdp->declBit(c+377,"mips_cpu program_counter_source_decode", false,-1);
        vcdp->declBit(c+17,"mips_cpu register_write_decode", false,-1);
        vcdp->declBit(c+25,"mips_cpu memory_to_register_decode", false,-1);
        vcdp->declBit(c+33,"mips_cpu memory_write_decode", false,-1);
        vcdp->declBit(c+41,"mips_cpu ALU_src_B_decode", false,-1);
        vcdp->declBit(c+49,"mips_cpu register_destination_decode", false,-1);
        vcdp->declBit(c+57,"mips_cpu branch_decode", false,-1);
        vcdp->declBit(c+65,"mips_cpu hi_lo_register_write_decode", false,-1);
        vcdp->declBit(c+353,"mips_cpu equal_decode", false,-1);
        vcdp->declBus(c+73,"mips_cpu ALU_function_decode", false,-1, 5,0);
        vcdp->declBit(c+81,"mips_cpu program_counter_multiplexer_jump_decode", false,-1);
        vcdp->declBit(c+1145,"mips_cpu flush_decode_execute_register", false,-1);
        vcdp->declBus(c+89,"mips_cpu program_counter_branch_decode", false,-1, 31,0);
        vcdp->declBus(c+425,"mips_cpu instruction_decode", false,-1, 31,0);
        vcdp->declBus(c+433,"mips_cpu program_counter_plus_four_decode", false,-1, 31,0);
        vcdp->declBus(c+441,"mips_cpu read_address_1", false,-1, 4,0);
        vcdp->declBus(c+441,"mips_cpu Rs_decode", false,-1, 4,0);
        vcdp->declBus(c+449,"mips_cpu read_address_2", false,-1, 4,0);
        vcdp->declBus(c+449,"mips_cpu Rt_decode", false,-1, 4,0);
        vcdp->declBus(c+457,"mips_cpu Rd_decode", false,-1, 4,0);
        vcdp->declBus(c+465,"mips_cpu immediate", false,-1, 15,0);
        vcdp->declBus(c+97,"mips_cpu shifter_output_decode", false,-1, 31,0);
        vcdp->declBus(c+385,"mips_cpu register_file_output_A_decode", false,-1, 31,0);
        vcdp->declBus(c+393,"mips_cpu register_file_output_B_decode", false,-1, 31,0);
        vcdp->declBus(c+361,"mips_cpu register_file_output_A_resolved_decode", false,-1, 31,0);
        vcdp->declBus(c+369,"mips_cpu register_file_output_B_resolved_decode", false,-1, 31,0);
        vcdp->declBus(c+105,"mips_cpu sign_imm_decode", false,-1, 31,0);
        vcdp->declBit(c+473,"mips_cpu register_destination_execute", false,-1);
        vcdp->declBit(c+481,"mips_cpu memory_to_register_execute", false,-1);
        vcdp->declBit(c+489,"mips_cpu memory_write_execute", false,-1);
        vcdp->declBus(c+113,"mips_cpu write_register_execute", false,-1, 4,0);
        vcdp->declBit(c+497,"mips_cpu ALU_src_B_execute", false,-1);
        vcdp->declBus(c+505,"mips_cpu ALU_function_execute", false,-1, 5,0);
        vcdp->declBit(c+513,"mips_cpu hi_lo_register_write_execute", false,-1);
        vcdp->declBit(c+521,"mips_cpu register_write_execute", false,-1);
        vcdp->declBit(c+529,"mips_cpu program_counter_multiplexer_jump_execute", false,-1);
        vcdp->declBus(c+537,"mips_cpu register_file_output_A_execute", false,-1, 31,0);
        vcdp->declBus(c+545,"mips_cpu register_file_output_B_execute", false,-1, 31,0);
        vcdp->declBus(c+121,"mips_cpu source_A_ALU_execute", false,-1, 31,0);
        vcdp->declBus(c+129,"mips_cpu source_B_ALU_execute", false,-1, 31,0);
        vcdp->declBus(c+137,"mips_cpu write_data_execute", false,-1, 31,0);
        vcdp->declBus(c+145,"mips_cpu ALU_output_execute", false,-1, 31,0);
        vcdp->declBus(c+153,"mips_cpu ALU_HI_output_execute", false,-1, 31,0);
        vcdp->declBus(c+161,"mips_cpu ALU_LO_output_execute", false,-1, 31,0);
        vcdp->declBus(c+553,"mips_cpu Rs_execute", false,-1, 4,0);
        vcdp->declBus(c+561,"mips_cpu Rt_execute", false,-1, 4,0);
        vcdp->declBus(c+569,"mips_cpu Rd_execute", false,-1, 4,0);
        vcdp->declBus(c+577,"mips_cpu sign_imm_execute", false,-1, 31,0);
        vcdp->declBit(c+585,"mips_cpu register_write_memory", false,-1);
        vcdp->declBus(c+593,"mips_cpu write_register_memory", false,-1, 4,0);
        vcdp->declBit(c+601,"mips_cpu memory_to_register_memory", false,-1);
        vcdp->declBit(c+609,"mips_cpu memory_write_memory", false,-1);
        vcdp->declBit(c+617,"mips_cpu hi_lo_register_write_memory", false,-1);
        vcdp->declBit(c+625,"mips_cpu program_counter_multiplexer_jump_memory", false,-1);
        vcdp->declBus(c+633,"mips_cpu ALU_output_memory", false,-1, 31,0);
        vcdp->declBus(c+641,"mips_cpu ALU_HI_output_memory", false,-1, 31,0);
        vcdp->declBus(c+649,"mips_cpu ALU_LO_output_memory", false,-1, 31,0);
        vcdp->declBus(c+1129,"mips_cpu read_data_memory", false,-1, 31,0);
        vcdp->declBus(c+657,"mips_cpu write_data_memory", false,-1, 31,0);
        vcdp->declBit(c+665,"mips_cpu register_write_writeback", false,-1);
        vcdp->declBit(c+673,"mips_cpu hi_lo_register_write_writeback", false,-1);
        vcdp->declBit(c+681,"mips_cpu memory_to_register_writeback", false,-1);
        vcdp->declBit(c+689,"mips_cpu program_counter_multiplexer_jump_writeback", false,-1);
        vcdp->declBus(c+697,"mips_cpu write_register_writeback", false,-1, 4,0);
        vcdp->declBus(c+169,"mips_cpu result_writeback", false,-1, 31,0);
        vcdp->declBus(c+705,"mips_cpu ALU_HI_output_writeback", false,-1, 31,0);
        vcdp->declBus(c+713,"mips_cpu ALU_LO_output_writeback", false,-1, 31,0);
        vcdp->declBus(c+721,"mips_cpu ALU_output_writeback", false,-1, 31,0);
        vcdp->declBus(c+729,"mips_cpu read_data_writeback", false,-1, 31,0);
        vcdp->declBit(c+177,"mips_cpu stall_fetch", false,-1);
        vcdp->declBit(c+185,"mips_cpu stall_decode", false,-1);
        vcdp->declBit(c+737,"mips_cpu forward_A_decode", false,-1);
        vcdp->declBit(c+745,"mips_cpu forward_B_decode", false,-1);
        vcdp->declBit(c+193,"mips_cpu flush_execute_register", false,-1);
        vcdp->declBus(c+201,"mips_cpu forward_A_execute", false,-1, 1,0);
        vcdp->declBus(c+209,"mips_cpu forward_B_execute", false,-1, 1,0);
        vcdp->declBit(c+401,"mips_cpu flush_fetch_decode_register", false,-1);
        vcdp->declBit(c+1,"mips_cpu register_file clk", false,-1);
        vcdp->declBit(c+1153,"mips_cpu register_file pipelined", false,-1);
        vcdp->declBit(c+1137,"mips_cpu register_file HI_LO_output", false,-1);
        vcdp->declBit(c+665,"mips_cpu register_file write_enable", false,-1);
        vcdp->declBit(c+673,"mips_cpu register_file hi_lo_register_write_enable", false,-1);
        vcdp->declBus(c+441,"mips_cpu register_file read_address_1", false,-1, 4,0);
        vcdp->declBus(c+449,"mips_cpu register_file read_address_2", false,-1, 4,0);
        vcdp->declBus(c+697,"mips_cpu register_file write_address", false,-1, 4,0);
        vcdp->declBus(c+169,"mips_cpu register_file write_data", false,-1, 31,0);
        vcdp->declBus(c+705,"mips_cpu register_file HI_write_data", false,-1, 31,0);
        vcdp->declBus(c+713,"mips_cpu register_file LO_write_data", false,-1, 31,0);
        vcdp->declBus(c+385,"mips_cpu register_file read_data_1", false,-1, 31,0);
        vcdp->declBus(c+393,"mips_cpu register_file read_data_2", false,-1, 31,0);
        {int i; for (i=0; i<32; i++) {
                vcdp->declBus(c+769+i*1,"mips_cpu register_file registers", true,(i+0), 31,0);}}
        vcdp->declBus(c+1025,"mips_cpu register_file HI_reg", false,-1, 31,0);
        vcdp->declBus(c+1033,"mips_cpu register_file LO_reg", false,-1, 31,0);
        vcdp->declBus(c+753,"mips_cpu register_file read_data_1_pre_mux", false,-1, 31,0);
        vcdp->declBus(c+761,"mips_cpu register_file read_data_2_pre_mux", false,-1, 31,0);
        vcdp->declBit(c+9,"mips_cpu register_file modified_write_clk", false,-1);
        vcdp->declBit(c+1,"mips_cpu pc clk", false,-1);
        vcdp->declBus(c+337,"mips_cpu pc address_input", false,-1, 31,0);
        vcdp->declBit(c+177,"mips_cpu pc enable", false,-1);
        vcdp->declBus(c+409,"mips_cpu pc address_output", false,-1, 31,0);
        vcdp->declBus(c+409,"mips_cpu plus_four_adder a", false,-1, 31,0);
        vcdp->declBus(c+1161,"mips_cpu plus_four_adder b", false,-1, 31,0);
        vcdp->declBus(c+417,"mips_cpu plus_four_adder z", false,-1, 31,0);
        vcdp->declBus(c+1169,"mips_cpu program_counter_multiplexer BUS_WIDTH", false,-1, 31,0);
        vcdp->declBit(c+377,"mips_cpu program_counter_multiplexer control", false,-1);
        vcdp->declBus(c+417,"mips_cpu program_counter_multiplexer input_0", false,-1, 31,0);
        vcdp->declBus(c+89,"mips_cpu program_counter_multiplexer input_1", false,-1, 31,0);
        vcdp->declBus(c+345,"mips_cpu program_counter_multiplexer resolved", false,-1, 31,0);
        vcdp->declBus(c+1169,"mips_cpu program_counter_multiplexer_two BUS_WIDTH", false,-1, 31,0);
        vcdp->declBit(c+689,"mips_cpu program_counter_multiplexer_two control", false,-1);
        vcdp->declBus(c+345,"mips_cpu program_counter_multiplexer_two input_0", false,-1, 31,0);
        vcdp->declBus(c+169,"mips_cpu program_counter_multiplexer_two input_1", false,-1, 31,0);
        vcdp->declBus(c+337,"mips_cpu program_counter_multiplexer_two resolved", false,-1, 31,0);
        vcdp->declBit(c+1,"mips_cpu fetch_decode_register clk", false,-1);
        vcdp->declBit(c+185,"mips_cpu fetch_decode_register enable", false,-1);
        vcdp->declBit(c+401,"mips_cpu fetch_decode_register clear", false,-1);
        vcdp->declBus(c+1089,"mips_cpu fetch_decode_register instruction_fetch", false,-1, 31,0);
        vcdp->declBus(c+417,"mips_cpu fetch_decode_register program_counter_plus_four_fetch", false,-1, 31,0);
        vcdp->declBus(c+425,"mips_cpu fetch_decode_register instruction_decode", false,-1, 31,0);
        vcdp->declBus(c+433,"mips_cpu fetch_decode_register program_counter_plus_four_decode", false,-1, 31,0);
        vcdp->declBus(c+425,"mips_cpu control_unit instruction", false,-1, 31,0);
        vcdp->declBit(c+17,"mips_cpu control_unit register_write", false,-1);
        vcdp->declBit(c+25,"mips_cpu control_unit memory_to_register", false,-1);
        vcdp->declBit(c+33,"mips_cpu control_unit memory_write", false,-1);
        vcdp->declBit(c+41,"mips_cpu control_unit ALU_src_B", false,-1);
        vcdp->declBit(c+49,"mips_cpu control_unit register_destination", false,-1);
        vcdp->declBit(c+57,"mips_cpu control_unit branch", false,-1);
        vcdp->declBit(c+65,"mips_cpu control_unit hi_lo_register_write", false,-1);
        vcdp->declBus(c+73,"mips_cpu control_unit ALU_function", false,-1, 5,0);
        vcdp->declBit(c+81,"mips_cpu control_unit program_counter_multiplexer_jump", false,-1);
        vcdp->declBus(c+217,"mips_cpu control_unit op", false,-1, 5,0);
        vcdp->declBus(c+449,"mips_cpu control_unit rt", false,-1, 4,0);
        vcdp->declBus(c+225,"mips_cpu control_unit funct", false,-1, 5,0);
        vcdp->declBus(c+1169,"mips_cpu register_file_output_A_mux BUS_WIDTH", false,-1, 31,0);
        vcdp->declBit(c+737,"mips_cpu register_file_output_A_mux control", false,-1);
        vcdp->declBus(c+385,"mips_cpu register_file_output_A_mux input_0", false,-1, 31,0);
        vcdp->declBus(c+633,"mips_cpu register_file_output_A_mux input_1", false,-1, 31,0);
        vcdp->declBus(c+361,"mips_cpu register_file_output_A_mux resolved", false,-1, 31,0);
        vcdp->declBus(c+1169,"mips_cpu register_file_output_B_mux BUS_WIDTH", false,-1, 31,0);
        vcdp->declBit(c+745,"mips_cpu register_file_output_B_mux control", false,-1);
        vcdp->declBus(c+393,"mips_cpu register_file_output_B_mux input_0", false,-1, 31,0);
        vcdp->declBus(c+633,"mips_cpu register_file_output_B_mux input_1", false,-1, 31,0);
        vcdp->declBus(c+369,"mips_cpu register_file_output_B_mux resolved", false,-1, 31,0);
        vcdp->declBus(c+361,"mips_cpu reg_output_comparator a", false,-1, 31,0);
        vcdp->declBus(c+369,"mips_cpu reg_output_comparator b", false,-1, 31,0);
        vcdp->declBit(c+353,"mips_cpu reg_output_comparator c", false,-1);
        vcdp->declBit(c+57,"mips_cpu program_counter_source_and_gate_decode input_A", false,-1);
        vcdp->declBit(c+353,"mips_cpu program_counter_source_and_gate_decode input_B", false,-1);
        vcdp->declBit(c+377,"mips_cpu program_counter_source_and_gate_decode output_C", false,-1);
        vcdp->declBus(c+465,"mips_cpu sign_extender_decode short_input", false,-1, 15,0);
        vcdp->declBus(c+105,"mips_cpu sign_extender_decode extended_output", false,-1, 31,0);
        vcdp->declBus(c+1177,"mips_cpu shifter_decode shift_distance", false,-1, 31,0);
        vcdp->declBus(c+105,"mips_cpu shifter_decode shift_input", false,-1, 31,0);
        vcdp->declBus(c+97,"mips_cpu shifter_decode shift_output", false,-1, 31,0);
        vcdp->declBus(c+97,"mips_cpu adder_decode a", false,-1, 31,0);
        vcdp->declBus(c+433,"mips_cpu adder_decode b", false,-1, 31,0);
        vcdp->declBus(c+89,"mips_cpu adder_decode z", false,-1, 31,0);
        vcdp->declBit(c+1,"mips_cpu decode_execute_register clk", false,-1);
        vcdp->declBit(c+193,"mips_cpu decode_execute_register clear", false,-1);
        vcdp->declBit(c+17,"mips_cpu decode_execute_register register_write_decode", false,-1);
        vcdp->declBit(c+25,"mips_cpu decode_execute_register memory_to_register_decode", false,-1);
        vcdp->declBit(c+33,"mips_cpu decode_execute_register memory_write_decode", false,-1);
        vcdp->declBit(c+41,"mips_cpu decode_execute_register ALU_src_B_decode", false,-1);
        vcdp->declBit(c+49,"mips_cpu decode_execute_register register_destination_decode", false,-1);
        vcdp->declBit(c+65,"mips_cpu decode_execute_register hi_lo_register_write_decode", false,-1);
        vcdp->declBus(c+73,"mips_cpu decode_execute_register ALU_function_decode", false,-1, 5,0);
        vcdp->declBus(c+441,"mips_cpu decode_execute_register Rs_decode", false,-1, 4,0);
        vcdp->declBus(c+449,"mips_cpu decode_execute_register Rt_decode", false,-1, 4,0);
        vcdp->declBus(c+457,"mips_cpu decode_execute_register Rd_decode", false,-1, 4,0);
        vcdp->declBus(c+105,"mips_cpu decode_execute_register sign_imm_decode", false,-1, 31,0);
        vcdp->declBit(c+81,"mips_cpu decode_execute_register program_counter_multiplexer_jump_decode", false,-1);
        vcdp->declBit(c+521,"mips_cpu decode_execute_register register_write_execute", false,-1);
        vcdp->declBit(c+481,"mips_cpu decode_execute_register memory_to_register_execute", false,-1);
        vcdp->declBit(c+489,"mips_cpu decode_execute_register memory_write_execute", false,-1);
        vcdp->declBit(c+497,"mips_cpu decode_execute_register ALU_src_B_execute", false,-1);
        vcdp->declBit(c+473,"mips_cpu decode_execute_register register_destination_execute", false,-1);
        vcdp->declBit(c+513,"mips_cpu decode_execute_register hi_lo_register_write_execute", false,-1);
        vcdp->declBus(c+505,"mips_cpu decode_execute_register ALU_function_execute", false,-1, 5,0);
        vcdp->declBus(c+553,"mips_cpu decode_execute_register Rs_execute", false,-1, 4,0);
        vcdp->declBus(c+561,"mips_cpu decode_execute_register Rt_execute", false,-1, 4,0);
        vcdp->declBus(c+569,"mips_cpu decode_execute_register Rd_execute", false,-1, 4,0);
        vcdp->declBus(c+577,"mips_cpu decode_execute_register sign_imm_execute", false,-1, 31,0);
        vcdp->declBit(c+529,"mips_cpu decode_execute_register program_counter_multiplexer_jump_execute", false,-1);
        vcdp->declBus(c+385,"mips_cpu decode_execute_register read_data_one_decode", false,-1, 31,0);
        vcdp->declBus(c+393,"mips_cpu decode_execute_register read_data_two_decode", false,-1, 31,0);
        vcdp->declBus(c+537,"mips_cpu decode_execute_register read_data_one_execute", false,-1, 31,0);
        vcdp->declBus(c+545,"mips_cpu decode_execute_register read_data_two_execute", false,-1, 31,0);
        vcdp->declBus(c+1185,"mips_cpu write_register_execute_mux BUS_WIDTH", false,-1, 31,0);
        vcdp->declBit(c+473,"mips_cpu write_register_execute_mux control", false,-1);
        vcdp->declBus(c+561,"mips_cpu write_register_execute_mux input_0", false,-1, 4,0);
        vcdp->declBus(c+569,"mips_cpu write_register_execute_mux input_1", false,-1, 4,0);
        vcdp->declBus(c+113,"mips_cpu write_register_execute_mux resolved", false,-1, 4,0);
        vcdp->declBus(c+1169,"mips_cpu register_file_output_A_execute_mux BUS_WIDTH", false,-1, 31,0);
        vcdp->declBus(c+201,"mips_cpu register_file_output_A_execute_mux control", false,-1, 1,0);
        vcdp->declBus(c+537,"mips_cpu register_file_output_A_execute_mux input_0", false,-1, 31,0);
        vcdp->declBus(c+169,"mips_cpu register_file_output_A_execute_mux input_1", false,-1, 31,0);
        vcdp->declBus(c+633,"mips_cpu register_file_output_A_execute_mux input_2", false,-1, 31,0);
        vcdp->declBus(c+713,"mips_cpu register_file_output_A_execute_mux input_3", false,-1, 31,0);
        vcdp->declBus(c+121,"mips_cpu register_file_output_A_execute_mux resolved", false,-1, 31,0);
        vcdp->declBus(c+1169,"mips_cpu register_file_output_B_execute_mux BUS_WIDTH", false,-1, 31,0);
        vcdp->declBus(c+209,"mips_cpu register_file_output_B_execute_mux control", false,-1, 1,0);
        vcdp->declBus(c+545,"mips_cpu register_file_output_B_execute_mux input_0", false,-1, 31,0);
        vcdp->declBus(c+169,"mips_cpu register_file_output_B_execute_mux input_1", false,-1, 31,0);
        vcdp->declBus(c+633,"mips_cpu register_file_output_B_execute_mux input_2", false,-1, 31,0);
        vcdp->declBus(c+705,"mips_cpu register_file_output_B_execute_mux input_3", false,-1, 31,0);
        vcdp->declBus(c+137,"mips_cpu register_file_output_B_execute_mux resolved", false,-1, 31,0);
        vcdp->declBus(c+1169,"mips_cpu source_B_ALU_mux BUS_WIDTH", false,-1, 31,0);
        vcdp->declBit(c+497,"mips_cpu source_B_ALU_mux control", false,-1);
        vcdp->declBus(c+137,"mips_cpu source_B_ALU_mux input_0", false,-1, 31,0);
        vcdp->declBus(c+577,"mips_cpu source_B_ALU_mux input_1", false,-1, 31,0);
        vcdp->declBus(c+129,"mips_cpu source_B_ALU_mux resolved", false,-1, 31,0);
        vcdp->declBus(c+505,"mips_cpu alu ALU_operation", false,-1, 5,0);
        vcdp->declBus(c+121,"mips_cpu alu input_1", false,-1, 31,0);
        vcdp->declBus(c+129,"mips_cpu alu input_2", false,-1, 31,0);
        vcdp->declBus(c+145,"mips_cpu alu ALU_output", false,-1, 31,0);
        vcdp->declBus(c+153,"mips_cpu alu ALU_HI_output", false,-1, 31,0);
        vcdp->declBus(c+161,"mips_cpu alu ALU_LO_output", false,-1, 31,0);
        vcdp->declBus(c+233,"mips_cpu alu shift_amount", false,-1, 4,0);
        vcdp->declQuad(c+241,"mips_cpu alu sign_extened_input_1", false,-1, 63,0);
        vcdp->declQuad(c+257,"mips_cpu alu sign_extened_input_2", false,-1, 63,0);
        vcdp->declQuad(c+273,"mips_cpu alu extended_input_1", false,-1, 63,0);
        vcdp->declQuad(c+289,"mips_cpu alu extended_input_2", false,-1, 63,0);
        vcdp->declQuad(c+305,"mips_cpu alu ALU_HI_LO_output", false,-1, 63,0);
        vcdp->declBit(c+1,"mips_cpu execute_memory_register clk", false,-1);
        vcdp->declBit(c+521,"mips_cpu execute_memory_register register_write_execute", false,-1);
        vcdp->declBit(c+481,"mips_cpu execute_memory_register memory_to_register_execute", false,-1);
        vcdp->declBit(c+489,"mips_cpu execute_memory_register memory_write_execute", false,-1);
        vcdp->declBit(c+513,"mips_cpu execute_memory_register hi_lo_register_write_execute", false,-1);
        vcdp->declBit(c+529,"mips_cpu execute_memory_register program_counter_multiplexer_jump_execute", false,-1);
        vcdp->declBit(c+585,"mips_cpu execute_memory_register register_write_memory", false,-1);
        vcdp->declBit(c+601,"mips_cpu execute_memory_register memory_to_register_memory", false,-1);
        vcdp->declBit(c+609,"mips_cpu execute_memory_register memory_write_memory", false,-1);
        vcdp->declBit(c+617,"mips_cpu execute_memory_register hi_lo_register_write_memory", false,-1);
        vcdp->declBit(c+625,"mips_cpu execute_memory_register program_counter_multiplexer_jump_memory", false,-1);
        vcdp->declBus(c+145,"mips_cpu execute_memory_register ALU_output_execute", false,-1, 31,0);
        vcdp->declBus(c+153,"mips_cpu execute_memory_register ALU_HI_output_execute", false,-1, 31,0);
        vcdp->declBus(c+161,"mips_cpu execute_memory_register ALU_LO_output_execute", false,-1, 31,0);
        vcdp->declBus(c+137,"mips_cpu execute_memory_register write_data_execute", false,-1, 31,0);
        vcdp->declBus(c+113,"mips_cpu execute_memory_register write_register_execute", false,-1, 4,0);
        vcdp->declBus(c+633,"mips_cpu execute_memory_register ALU_output_memory", false,-1, 31,0);
        vcdp->declBus(c+641,"mips_cpu execute_memory_register ALU_HI_output_memory", false,-1, 31,0);
        vcdp->declBus(c+649,"mips_cpu execute_memory_register ALU_LO_output_memory", false,-1, 31,0);
        vcdp->declBus(c+657,"mips_cpu execute_memory_register write_data_memory", false,-1, 31,0);
        vcdp->declBus(c+593,"mips_cpu execute_memory_register write_register_memory", false,-1, 4,0);
        vcdp->declBit(c+1,"mips_cpu memory_writeback_register clk", false,-1);
        vcdp->declBit(c+585,"mips_cpu memory_writeback_register register_write_memory", false,-1);
        vcdp->declBit(c+601,"mips_cpu memory_writeback_register memory_to_register_memory", false,-1);
        vcdp->declBit(c+617,"mips_cpu memory_writeback_register hi_lo_register_write_memory", false,-1);
        vcdp->declBit(c+625,"mips_cpu memory_writeback_register program_counter_multiplexer_jump_memory", false,-1);
        vcdp->declBit(c+665,"mips_cpu memory_writeback_register register_write_writeback", false,-1);
        vcdp->declBit(c+681,"mips_cpu memory_writeback_register memory_to_register_writeback", false,-1);
        vcdp->declBit(c+673,"mips_cpu memory_writeback_register hi_lo_register_write_writeback", false,-1);
        vcdp->declBit(c+689,"mips_cpu memory_writeback_register program_counter_multiplexer_jump_writeback", false,-1);
        vcdp->declBus(c+633,"mips_cpu memory_writeback_register ALU_output_memory", false,-1, 31,0);
        vcdp->declBus(c+593,"mips_cpu memory_writeback_register write_register_memory", false,-1, 4,0);
        vcdp->declBus(c+641,"mips_cpu memory_writeback_register ALU_HI_output_memory", false,-1, 31,0);
        vcdp->declBus(c+649,"mips_cpu memory_writeback_register ALU_LO_output_memory", false,-1, 31,0);
        vcdp->declBus(c+1129,"mips_cpu memory_writeback_register read_data_memory", false,-1, 31,0);
        vcdp->declBus(c+721,"mips_cpu memory_writeback_register ALU_output_writeback", false,-1, 31,0);
        vcdp->declBus(c+697,"mips_cpu memory_writeback_register write_register_writeback", false,-1, 4,0);
        vcdp->declBus(c+705,"mips_cpu memory_writeback_register ALU_HI_output_writeback", false,-1, 31,0);
        vcdp->declBus(c+713,"mips_cpu memory_writeback_register ALU_LO_output_writeback", false,-1, 31,0);
        vcdp->declBus(c+729,"mips_cpu memory_writeback_register read_data_writeback", false,-1, 31,0);
        vcdp->declBus(c+1169,"mips_cpu writeback_mux BUS_WIDTH", false,-1, 31,0);
        vcdp->declBit(c+681,"mips_cpu writeback_mux control", false,-1);
        vcdp->declBus(c+721,"mips_cpu writeback_mux input_0", false,-1, 31,0);
        vcdp->declBus(c+729,"mips_cpu writeback_mux input_1", false,-1, 31,0);
        vcdp->declBus(c+169,"mips_cpu writeback_mux resolved", false,-1, 31,0);
        vcdp->declBit(c+57,"mips_cpu hazard_unit branch_decode", false,-1);
        vcdp->declBus(c+441,"mips_cpu hazard_unit Rs_decode", false,-1, 4,0);
        vcdp->declBus(c+449,"mips_cpu hazard_unit Rt_decode", false,-1, 4,0);
        vcdp->declBus(c+553,"mips_cpu hazard_unit Rs_execute", false,-1, 4,0);
        vcdp->declBus(c+561,"mips_cpu hazard_unit Rt_execute", false,-1, 4,0);
        vcdp->declBus(c+113,"mips_cpu hazard_unit write_register_execute", false,-1, 4,0);
        vcdp->declBit(c+481,"mips_cpu hazard_unit memory_to_register_execute", false,-1);
        vcdp->declBit(c+521,"mips_cpu hazard_unit register_write_execute", false,-1);
        vcdp->declBus(c+593,"mips_cpu hazard_unit write_register_memory", false,-1, 4,0);
        vcdp->declBit(c+601,"mips_cpu hazard_unit memory_to_register_memory", false,-1);
        vcdp->declBit(c+585,"mips_cpu hazard_unit register_write_memory", false,-1);
        vcdp->declBus(c+697,"mips_cpu hazard_unit write_register_writeback", false,-1, 4,0);
        vcdp->declBit(c+665,"mips_cpu hazard_unit register_write_writeback", false,-1);
        vcdp->declBit(c+689,"mips_cpu hazard_unit program_counter_multiplexer_jump_writeback", false,-1);
        vcdp->declBit(c+177,"mips_cpu hazard_unit stall_fetch", false,-1);
        vcdp->declBit(c+185,"mips_cpu hazard_unit stall_decode", false,-1);
        vcdp->declBit(c+737,"mips_cpu hazard_unit forward_register_file_output_1_decode", false,-1);
        vcdp->declBit(c+745,"mips_cpu hazard_unit forward_register_file_output_2_decode", false,-1);
        vcdp->declBit(c+193,"mips_cpu hazard_unit flush_execute_register", false,-1);
        vcdp->declBus(c+201,"mips_cpu hazard_unit forward_register_file_output_1_execute", false,-1, 1,0);
        vcdp->declBus(c+209,"mips_cpu hazard_unit forward_register_file_output_2_execute", false,-1, 1,0);
        vcdp->declBit(c+321,"mips_cpu hazard_unit lwstall", false,-1);
        vcdp->declBit(c+329,"mips_cpu hazard_unit branchstall", false,-1);
        vcdp->declBit(c+689,"mips_cpu or_gate input_A", false,-1);
        vcdp->declBit(c+377,"mips_cpu or_gate input_B", false,-1);
        vcdp->declBit(c+401,"mips_cpu or_gate output_C", false,-1);
    }
}

void MIPS_Harvard_TB::traceFullThis__1(MIPS_Harvard_TB__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    MIPS_Harvard_TB* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
        vcdp->fullBit(c+1,(vlTOPp->mips_cpu__DOT__internal_clk));
        vcdp->fullBit(c+9,((1U & (~ (IData)(vlTOPp->mips_cpu__DOT__internal_clk)))));
        vcdp->fullBit(c+17,(vlTOPp->mips_cpu__DOT__register_write_decode));
        vcdp->fullBit(c+25,(vlTOPp->mips_cpu__DOT__memory_to_register_decode));
        vcdp->fullBit(c+33,(vlTOPp->mips_cpu__DOT__memory_write_decode));
        vcdp->fullBit(c+41,(vlTOPp->mips_cpu__DOT__ALU_src_B_decode));
        vcdp->fullBit(c+49,(vlTOPp->mips_cpu__DOT__register_destination_decode));
        vcdp->fullBit(c+57,(vlTOPp->mips_cpu__DOT__branch_decode));
        vcdp->fullBit(c+65,(vlTOPp->mips_cpu__DOT__hi_lo_register_write_decode));
        vcdp->fullBus(c+73,(vlTOPp->mips_cpu__DOT__ALU_function_decode),6);
        vcdp->fullBit(c+81,(vlTOPp->mips_cpu__DOT__program_counter_multiplexer_jump_decode));
        vcdp->fullBus(c+89,(((vlTOPp->mips_cpu__DOT__sign_imm_decode 
                              << 2U) + vlTOPp->mips_cpu__DOT__program_counter_plus_four_decode)),32);
        vcdp->fullBus(c+97,((vlTOPp->mips_cpu__DOT__sign_imm_decode 
                             << 2U)),32);
        vcdp->fullBus(c+105,(vlTOPp->mips_cpu__DOT__sign_imm_decode),32);
        vcdp->fullBus(c+113,(vlTOPp->mips_cpu__DOT__write_register_execute),5);
        vcdp->fullBus(c+121,(vlTOPp->mips_cpu__DOT__source_A_ALU_execute),32);
        vcdp->fullBus(c+129,(vlTOPp->mips_cpu__DOT__source_B_ALU_execute),32);
        vcdp->fullBus(c+137,(vlTOPp->mips_cpu__DOT__write_data_execute),32);
        vcdp->fullBus(c+145,(vlTOPp->mips_cpu__DOT__ALU_output_execute),32);
        vcdp->fullBus(c+153,(vlTOPp->mips_cpu__DOT__ALU_HI_output_execute),32);
        vcdp->fullBus(c+161,(vlTOPp->mips_cpu__DOT__ALU_LO_output_execute),32);
        vcdp->fullBus(c+169,(vlTOPp->mips_cpu__DOT__result_writeback),32);
        vcdp->fullBit(c+177,(vlTOPp->mips_cpu__DOT__stall_fetch));
        vcdp->fullBit(c+185,(vlTOPp->mips_cpu__DOT__stall_decode));
        vcdp->fullBit(c+193,(vlTOPp->mips_cpu__DOT__flush_execute_register));
        vcdp->fullBus(c+201,(vlTOPp->mips_cpu__DOT__forward_A_execute),2);
        vcdp->fullBus(c+209,(vlTOPp->mips_cpu__DOT__forward_B_execute),2);
        vcdp->fullBus(c+217,(vlTOPp->mips_cpu__DOT__control_unit__DOT__op),6);
        vcdp->fullBus(c+225,(vlTOPp->mips_cpu__DOT__control_unit__DOT__funct),6);
        vcdp->fullBus(c+233,((0x1fU & (vlTOPp->mips_cpu__DOT__source_A_ALU_execute 
                                       >> 6U))),5);
        vcdp->fullQuad(c+241,((((QData)((IData)(VL_NEGATE_I((IData)(
                                                                    (1U 
                                                                     & (vlTOPp->mips_cpu__DOT__source_A_ALU_execute 
                                                                        >> 0x1fU)))))) 
                                << 0x20U) | (QData)((IData)(vlTOPp->mips_cpu__DOT__source_A_ALU_execute)))),64);
        vcdp->fullQuad(c+257,((((QData)((IData)(VL_NEGATE_I((IData)(
                                                                    (1U 
                                                                     & (vlTOPp->mips_cpu__DOT__source_B_ALU_execute 
                                                                        >> 0x1fU)))))) 
                                << 0x20U) | (QData)((IData)(vlTOPp->mips_cpu__DOT__source_B_ALU_execute)))),64);
        vcdp->fullQuad(c+273,((QData)((IData)(vlTOPp->mips_cpu__DOT__source_A_ALU_execute))),64);
        vcdp->fullQuad(c+289,((QData)((IData)(vlTOPp->mips_cpu__DOT__source_B_ALU_execute))),64);
        vcdp->fullQuad(c+305,(vlTOPp->mips_cpu__DOT__alu__DOT__ALU_HI_LO_output),64);
        vcdp->fullBit(c+321,(vlTOPp->mips_cpu__DOT__hazard_unit__DOT__lwstall));
        vcdp->fullBit(c+329,(vlTOPp->mips_cpu__DOT__hazard_unit__DOT__branchstall));
        vcdp->fullBus(c+337,(((IData)(vlTOPp->mips_cpu__DOT__program_counter_multiplexer_jump_writeback)
                               ? vlTOPp->mips_cpu__DOT__result_writeback
                               : ((IData)(vlTOPp->mips_cpu__DOT__program_counter_source_decode)
                                   ? ((vlTOPp->mips_cpu__DOT__sign_imm_decode 
                                       << 2U) + vlTOPp->mips_cpu__DOT__program_counter_plus_four_decode)
                                   : ((IData)(4U) + vlTOPp->mips_cpu__DOT__program_counter_fetch)))),32);
        vcdp->fullBus(c+345,(((IData)(vlTOPp->mips_cpu__DOT__program_counter_source_decode)
                               ? ((vlTOPp->mips_cpu__DOT__sign_imm_decode 
                                   << 2U) + vlTOPp->mips_cpu__DOT__program_counter_plus_four_decode)
                               : ((IData)(4U) + vlTOPp->mips_cpu__DOT__program_counter_fetch))),32);
        vcdp->fullBit(c+353,((((((0U != (0x1fU & (vlTOPp->mips_cpu__DOT__instruction_decode 
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
        vcdp->fullBus(c+361,(((((0U != (0x1fU & (vlTOPp->mips_cpu__DOT__instruction_decode 
                                                 >> 0x15U))) 
                                & ((0x1fU & (vlTOPp->mips_cpu__DOT__instruction_decode 
                                             >> 0x15U)) 
                                   == (IData)(vlTOPp->mips_cpu__DOT__write_register_memory))) 
                               & (IData)(vlTOPp->mips_cpu__DOT__register_write_memory))
                               ? vlTOPp->mips_cpu__DOT__ALU_output_memory
                               : vlTOPp->mips_cpu__DOT__register_file_output_A_decode)),32);
        vcdp->fullBus(c+369,(((((0U != (0x1fU & (vlTOPp->mips_cpu__DOT__instruction_decode 
                                                 >> 0x10U))) 
                                & ((0x1fU & (vlTOPp->mips_cpu__DOT__instruction_decode 
                                             >> 0x10U)) 
                                   == (IData)(vlTOPp->mips_cpu__DOT__write_register_memory))) 
                               & (IData)(vlTOPp->mips_cpu__DOT__register_write_memory))
                               ? vlTOPp->mips_cpu__DOT__ALU_output_memory
                               : vlTOPp->mips_cpu__DOT__register_file_output_B_decode)),32);
        vcdp->fullBit(c+377,(vlTOPp->mips_cpu__DOT__program_counter_source_decode));
        vcdp->fullBus(c+385,(vlTOPp->mips_cpu__DOT__register_file_output_A_decode),32);
        vcdp->fullBus(c+393,(vlTOPp->mips_cpu__DOT__register_file_output_B_decode),32);
        vcdp->fullBit(c+401,(vlTOPp->mips_cpu__DOT__flush_fetch_decode_register));
        vcdp->fullBus(c+409,(vlTOPp->mips_cpu__DOT__program_counter_fetch),32);
        vcdp->fullBus(c+417,(((IData)(4U) + vlTOPp->mips_cpu__DOT__program_counter_fetch)),32);
        vcdp->fullBus(c+425,(vlTOPp->mips_cpu__DOT__instruction_decode),32);
        vcdp->fullBus(c+433,(vlTOPp->mips_cpu__DOT__program_counter_plus_four_decode),32);
        vcdp->fullBus(c+441,((0x1fU & (vlTOPp->mips_cpu__DOT__instruction_decode 
                                       >> 0x15U))),5);
        vcdp->fullBus(c+449,((0x1fU & (vlTOPp->mips_cpu__DOT__instruction_decode 
                                       >> 0x10U))),5);
        vcdp->fullBus(c+457,((0x1fU & (vlTOPp->mips_cpu__DOT__instruction_decode 
                                       >> 0xbU))),5);
        vcdp->fullBus(c+465,((0xffffU & vlTOPp->mips_cpu__DOT__instruction_decode)),16);
        vcdp->fullBit(c+473,(vlTOPp->mips_cpu__DOT__register_destination_execute));
        vcdp->fullBit(c+481,(vlTOPp->mips_cpu__DOT__memory_to_register_execute));
        vcdp->fullBit(c+489,(vlTOPp->mips_cpu__DOT__memory_write_execute));
        vcdp->fullBit(c+497,(vlTOPp->mips_cpu__DOT__ALU_src_B_execute));
        vcdp->fullBus(c+505,(vlTOPp->mips_cpu__DOT__ALU_function_execute),6);
        vcdp->fullBit(c+513,(vlTOPp->mips_cpu__DOT__hi_lo_register_write_execute));
        vcdp->fullBit(c+521,(vlTOPp->mips_cpu__DOT__register_write_execute));
        vcdp->fullBit(c+529,(vlTOPp->mips_cpu__DOT__program_counter_multiplexer_jump_execute));
        vcdp->fullBus(c+537,(vlTOPp->mips_cpu__DOT__register_file_output_A_execute),32);
        vcdp->fullBus(c+545,(vlTOPp->mips_cpu__DOT__register_file_output_B_execute),32);
        vcdp->fullBus(c+553,(vlTOPp->mips_cpu__DOT__Rs_execute),5);
        vcdp->fullBus(c+561,(vlTOPp->mips_cpu__DOT__Rt_execute),5);
        vcdp->fullBus(c+569,(vlTOPp->mips_cpu__DOT__Rd_execute),5);
        vcdp->fullBus(c+577,(vlTOPp->mips_cpu__DOT__sign_imm_execute),32);
        vcdp->fullBit(c+585,(vlTOPp->mips_cpu__DOT__register_write_memory));
        vcdp->fullBus(c+593,(vlTOPp->mips_cpu__DOT__write_register_memory),5);
        vcdp->fullBit(c+601,(vlTOPp->mips_cpu__DOT__memory_to_register_memory));
        vcdp->fullBit(c+609,(vlTOPp->mips_cpu__DOT__memory_write_memory));
        vcdp->fullBit(c+617,(vlTOPp->mips_cpu__DOT__hi_lo_register_write_memory));
        vcdp->fullBit(c+625,(vlTOPp->mips_cpu__DOT__program_counter_multiplexer_jump_memory));
        vcdp->fullBus(c+633,(vlTOPp->mips_cpu__DOT__ALU_output_memory),32);
        vcdp->fullBus(c+641,(vlTOPp->mips_cpu__DOT__ALU_HI_output_memory),32);
        vcdp->fullBus(c+649,(vlTOPp->mips_cpu__DOT__ALU_LO_output_memory),32);
        vcdp->fullBus(c+657,(vlTOPp->mips_cpu__DOT__write_data_memory),32);
        vcdp->fullBit(c+665,(vlTOPp->mips_cpu__DOT__register_write_writeback));
        vcdp->fullBit(c+673,(vlTOPp->mips_cpu__DOT__hi_lo_register_write_writeback));
        vcdp->fullBit(c+681,(vlTOPp->mips_cpu__DOT__memory_to_register_writeback));
        vcdp->fullBit(c+689,(vlTOPp->mips_cpu__DOT__program_counter_multiplexer_jump_writeback));
        vcdp->fullBus(c+697,(vlTOPp->mips_cpu__DOT__write_register_writeback),5);
        vcdp->fullBus(c+705,(vlTOPp->mips_cpu__DOT__ALU_HI_output_writeback),32);
        vcdp->fullBus(c+713,(vlTOPp->mips_cpu__DOT__ALU_LO_output_writeback),32);
        vcdp->fullBus(c+721,(vlTOPp->mips_cpu__DOT__ALU_output_writeback),32);
        vcdp->fullBus(c+729,(vlTOPp->mips_cpu__DOT__read_data_writeback),32);
        vcdp->fullBit(c+737,((((0U != (0x1fU & (vlTOPp->mips_cpu__DOT__instruction_decode 
                                                >> 0x15U))) 
                               & ((0x1fU & (vlTOPp->mips_cpu__DOT__instruction_decode 
                                            >> 0x15U)) 
                                  == (IData)(vlTOPp->mips_cpu__DOT__write_register_memory))) 
                              & (IData)(vlTOPp->mips_cpu__DOT__register_write_memory))));
        vcdp->fullBit(c+745,((((0U != (0x1fU & (vlTOPp->mips_cpu__DOT__instruction_decode 
                                                >> 0x10U))) 
                               & ((0x1fU & (vlTOPp->mips_cpu__DOT__instruction_decode 
                                            >> 0x10U)) 
                                  == (IData)(vlTOPp->mips_cpu__DOT__write_register_memory))) 
                              & (IData)(vlTOPp->mips_cpu__DOT__register_write_memory))));
        vcdp->fullBus(c+753,(((0U != (0x1fU & (vlTOPp->mips_cpu__DOT__instruction_decode 
                                               >> 0x15U)))
                               ? vlTOPp->mips_cpu__DOT__register_file__DOT__registers
                              [(0x1fU & (vlTOPp->mips_cpu__DOT__instruction_decode 
                                         >> 0x15U))]
                               : 0U)),32);
        vcdp->fullBus(c+761,(((0U != (0x1fU & (vlTOPp->mips_cpu__DOT__instruction_decode 
                                               >> 0x10U)))
                               ? vlTOPp->mips_cpu__DOT__register_file__DOT__registers
                              [(0x1fU & (vlTOPp->mips_cpu__DOT__instruction_decode 
                                         >> 0x10U))]
                               : 0U)),32);
        vcdp->fullBus(c+769,(vlTOPp->mips_cpu__DOT__register_file__DOT__registers[0]),32);
        vcdp->fullBus(c+770,(vlTOPp->mips_cpu__DOT__register_file__DOT__registers[1]),32);
        vcdp->fullBus(c+771,(vlTOPp->mips_cpu__DOT__register_file__DOT__registers[2]),32);
        vcdp->fullBus(c+772,(vlTOPp->mips_cpu__DOT__register_file__DOT__registers[3]),32);
        vcdp->fullBus(c+773,(vlTOPp->mips_cpu__DOT__register_file__DOT__registers[4]),32);
        vcdp->fullBus(c+774,(vlTOPp->mips_cpu__DOT__register_file__DOT__registers[5]),32);
        vcdp->fullBus(c+775,(vlTOPp->mips_cpu__DOT__register_file__DOT__registers[6]),32);
        vcdp->fullBus(c+776,(vlTOPp->mips_cpu__DOT__register_file__DOT__registers[7]),32);
        vcdp->fullBus(c+777,(vlTOPp->mips_cpu__DOT__register_file__DOT__registers[8]),32);
        vcdp->fullBus(c+778,(vlTOPp->mips_cpu__DOT__register_file__DOT__registers[9]),32);
        vcdp->fullBus(c+779,(vlTOPp->mips_cpu__DOT__register_file__DOT__registers[10]),32);
        vcdp->fullBus(c+780,(vlTOPp->mips_cpu__DOT__register_file__DOT__registers[11]),32);
        vcdp->fullBus(c+781,(vlTOPp->mips_cpu__DOT__register_file__DOT__registers[12]),32);
        vcdp->fullBus(c+782,(vlTOPp->mips_cpu__DOT__register_file__DOT__registers[13]),32);
        vcdp->fullBus(c+783,(vlTOPp->mips_cpu__DOT__register_file__DOT__registers[14]),32);
        vcdp->fullBus(c+784,(vlTOPp->mips_cpu__DOT__register_file__DOT__registers[15]),32);
        vcdp->fullBus(c+785,(vlTOPp->mips_cpu__DOT__register_file__DOT__registers[16]),32);
        vcdp->fullBus(c+786,(vlTOPp->mips_cpu__DOT__register_file__DOT__registers[17]),32);
        vcdp->fullBus(c+787,(vlTOPp->mips_cpu__DOT__register_file__DOT__registers[18]),32);
        vcdp->fullBus(c+788,(vlTOPp->mips_cpu__DOT__register_file__DOT__registers[19]),32);
        vcdp->fullBus(c+789,(vlTOPp->mips_cpu__DOT__register_file__DOT__registers[20]),32);
        vcdp->fullBus(c+790,(vlTOPp->mips_cpu__DOT__register_file__DOT__registers[21]),32);
        vcdp->fullBus(c+791,(vlTOPp->mips_cpu__DOT__register_file__DOT__registers[22]),32);
        vcdp->fullBus(c+792,(vlTOPp->mips_cpu__DOT__register_file__DOT__registers[23]),32);
        vcdp->fullBus(c+793,(vlTOPp->mips_cpu__DOT__register_file__DOT__registers[24]),32);
        vcdp->fullBus(c+794,(vlTOPp->mips_cpu__DOT__register_file__DOT__registers[25]),32);
        vcdp->fullBus(c+795,(vlTOPp->mips_cpu__DOT__register_file__DOT__registers[26]),32);
        vcdp->fullBus(c+796,(vlTOPp->mips_cpu__DOT__register_file__DOT__registers[27]),32);
        vcdp->fullBus(c+797,(vlTOPp->mips_cpu__DOT__register_file__DOT__registers[28]),32);
        vcdp->fullBus(c+798,(vlTOPp->mips_cpu__DOT__register_file__DOT__registers[29]),32);
        vcdp->fullBus(c+799,(vlTOPp->mips_cpu__DOT__register_file__DOT__registers[30]),32);
        vcdp->fullBus(c+800,(vlTOPp->mips_cpu__DOT__register_file__DOT__registers[31]),32);
        vcdp->fullBus(c+1025,(vlTOPp->mips_cpu__DOT__register_file__DOT__HI_reg),32);
        vcdp->fullBus(c+1033,(vlTOPp->mips_cpu__DOT__register_file__DOT__LO_reg),32);
        vcdp->fullBit(c+1041,(vlTOPp->clk));
        vcdp->fullBit(c+1049,(vlTOPp->reset));
        vcdp->fullBit(c+1057,(vlTOPp->active));
        vcdp->fullBus(c+1065,(vlTOPp->register_v0),32);
        vcdp->fullBit(c+1073,(vlTOPp->clk_enable));
        vcdp->fullBus(c+1081,(vlTOPp->instr_address),32);
        vcdp->fullBus(c+1089,(vlTOPp->instr_readdata),32);
        vcdp->fullBus(c+1097,(vlTOPp->data_address),32);
        vcdp->fullBit(c+1105,(vlTOPp->data_write));
        vcdp->fullBit(c+1113,(vlTOPp->data_read));
        vcdp->fullBus(c+1121,(vlTOPp->data_writedata),32);
        vcdp->fullBus(c+1129,(vlTOPp->data_readdata),32);
        vcdp->fullBit(c+1137,(vlTOPp->mips_cpu__DOT__HI_LO_output));
        vcdp->fullBit(c+1145,(vlTOPp->mips_cpu__DOT__flush_decode_execute_register));
        vcdp->fullBit(c+1153,(1U));
        vcdp->fullBus(c+1161,(4U),32);
        vcdp->fullBus(c+1169,(0x20U),32);
        vcdp->fullBus(c+1177,(2U),32);
        vcdp->fullBus(c+1185,(5U),32);
    }
}
