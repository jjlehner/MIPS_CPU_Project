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
        vcdp->declBit(c+1209,"clk", false,-1);
        vcdp->declBit(c+1217,"reset", false,-1);
        vcdp->declBit(c+1225,"active", false,-1);
        vcdp->declBus(c+1233,"register_v0", false,-1, 31,0);
        vcdp->declBit(c+1241,"clk_enable", false,-1);
        vcdp->declBus(c+1249,"instr_address", false,-1, 31,0);
        vcdp->declBus(c+1257,"instr_readdata", false,-1, 31,0);
        vcdp->declBus(c+1265,"data_address", false,-1, 31,0);
        vcdp->declBit(c+1273,"data_write", false,-1);
        vcdp->declBit(c+1281,"data_read", false,-1);
        vcdp->declBus(c+1289,"data_writedata", false,-1, 31,0);
        vcdp->declBus(c+1297,"data_readdata", false,-1, 31,0);
        vcdp->declBit(c+1209,"mips_cpu_harvard clk", false,-1);
        vcdp->declBit(c+1217,"mips_cpu_harvard reset", false,-1);
        vcdp->declBit(c+1225,"mips_cpu_harvard active", false,-1);
        vcdp->declBus(c+1233,"mips_cpu_harvard register_v0", false,-1, 31,0);
        vcdp->declBit(c+1241,"mips_cpu_harvard clk_enable", false,-1);
        vcdp->declBus(c+1249,"mips_cpu_harvard instr_address", false,-1, 31,0);
        vcdp->declBus(c+1257,"mips_cpu_harvard instr_readdata", false,-1, 31,0);
        vcdp->declBus(c+1265,"mips_cpu_harvard data_address", false,-1, 31,0);
        vcdp->declBit(c+1273,"mips_cpu_harvard data_write", false,-1);
        vcdp->declBit(c+1281,"mips_cpu_harvard data_read", false,-1);
        vcdp->declBus(c+1289,"mips_cpu_harvard data_writedata", false,-1, 31,0);
        vcdp->declBus(c+1297,"mips_cpu_harvard data_readdata", false,-1, 31,0);
        vcdp->declBit(c+433,"mips_cpu_harvard internal_clk", false,-1);
        vcdp->declBus(c+377,"mips_cpu_harvard program_counter_prime", false,-1, 31,0);
        vcdp->declBus(c+449,"mips_cpu_harvard program_counter_fetch", false,-1, 31,0);
        vcdp->declBus(c+457,"mips_cpu_harvard program_counter_plus_four_fetch", false,-1, 31,0);
        vcdp->declBus(c+1257,"mips_cpu_harvard instruction_fetch", false,-1, 31,0);
        vcdp->declBus(c+25,"mips_cpu_harvard program_counter_mux_1_out", false,-1, 31,0);
        vcdp->declBit(c+465,"mips_cpu_harvard HALT_fetch", false,-1);
        vcdp->declBit(c+385,"mips_cpu_harvard program_counter_src_decode", false,-1);
        vcdp->declBit(c+49,"mips_cpu_harvard register_write_decode", false,-1);
        vcdp->declBit(c+57,"mips_cpu_harvard memory_to_register_decode", false,-1);
        vcdp->declBit(c+65,"mips_cpu_harvard memory_write_decode", false,-1);
        vcdp->declBus(c+73,"mips_cpu_harvard ALU_src_B_decode", false,-1, 1,0);
        vcdp->declBus(c+81,"mips_cpu_harvard register_destination_decode", false,-1, 1,0);
        vcdp->declBit(c+89,"mips_cpu_harvard branch_decode", false,-1);
        vcdp->declBit(c+393,"mips_cpu_harvard equal_decode", false,-1);
        vcdp->declBus(c+97,"mips_cpu_harvard ALU_function_decode", false,-1, 5,0);
        vcdp->declBit(c+105,"mips_cpu_harvard program_counter_multiplexer_jump_decode", false,-1);
        vcdp->declBit(c+1305,"mips_cpu_harvard flush_decode_execute_register", false,-1);
        vcdp->declBit(c+113,"mips_cpu_harvard using_HI_LO_decode", false,-1);
        vcdp->declBit(c+121,"mips_cpu_harvard j_instruction_decode", false,-1);
        vcdp->declBit(c+129,"mips_cpu_harvard HI_register_write_decode", false,-1);
        vcdp->declBit(c+137,"mips_cpu_harvard LO_register_write_decode", false,-1);
        vcdp->declBit(c+473,"mips_cpu_harvard HALT_decode", false,-1);
        vcdp->declBus(c+1,"mips_cpu_harvard program_counter_branch_decode", false,-1, 31,0);
        vcdp->declBus(c+481,"mips_cpu_harvard instruction_decode", false,-1, 31,0);
        vcdp->declBus(c+489,"mips_cpu_harvard program_counter_plus_four_decode", false,-1, 31,0);
        vcdp->declBus(c+497,"mips_cpu_harvard op", false,-1, 5,0);
        vcdp->declBus(c+505,"mips_cpu_harvard read_address_1", false,-1, 4,0);
        vcdp->declBus(c+505,"mips_cpu_harvard Rs_decode", false,-1, 4,0);
        vcdp->declBus(c+513,"mips_cpu_harvard read_address_2", false,-1, 4,0);
        vcdp->declBus(c+513,"mips_cpu_harvard Rt_decode", false,-1, 4,0);
        vcdp->declBus(c+521,"mips_cpu_harvard Rd_decode", false,-1, 4,0);
        vcdp->declBus(c+529,"mips_cpu_harvard immediate", false,-1, 15,0);
        vcdp->declBus(c+537,"mips_cpu_harvard j_offset", false,-1, 25,0);
        vcdp->declBus(c+817,"mips_cpu_harvard register_file_output_LO_decode", false,-1, 31,0);
        vcdp->declBus(c+825,"mips_cpu_harvard register_file_output_HI_decode", false,-1, 31,0);
        vcdp->declBus(c+9,"mips_cpu_harvard shifter_output_decode", false,-1, 31,0);
        vcdp->declBus(c+401,"mips_cpu_harvard register_file_output_A_decode", false,-1, 31,0);
        vcdp->declBus(c+409,"mips_cpu_harvard register_file_output_B_decode", false,-1, 31,0);
        vcdp->declBus(c+33,"mips_cpu_harvard src_A_decode", false,-1, 31,0);
        vcdp->declBus(c+41,"mips_cpu_harvard src_B_decode", false,-1, 31,0);
        vcdp->declBus(c+17,"mips_cpu_harvard sign_imm_decode", false,-1, 31,0);
        vcdp->declBus(c+417,"mips_cpu_harvard comparator_1", false,-1, 31,0);
        vcdp->declBus(c+425,"mips_cpu_harvard comparator_2", false,-1, 31,0);
        vcdp->declBus(c+545,"mips_cpu_harvard j_program_counter_decode", false,-1, 31,0);
        vcdp->declBus(c+553,"mips_cpu_harvard register_destination_execute", false,-1, 1,0);
        vcdp->declBit(c+561,"mips_cpu_harvard memory_to_register_execute", false,-1);
        vcdp->declBit(c+569,"mips_cpu_harvard memory_write_execute", false,-1);
        vcdp->declBus(c+145,"mips_cpu_harvard write_register_execute", false,-1, 4,0);
        vcdp->declBus(c+577,"mips_cpu_harvard ALU_src_B_execute", false,-1, 1,0);
        vcdp->declBus(c+585,"mips_cpu_harvard ALU_function_execute", false,-1, 5,0);
        vcdp->declBit(c+1089,"mips_cpu_harvard HI_register_write_execute", false,-1);
        vcdp->declBit(c+1097,"mips_cpu_harvard LO_register_write_execute", false,-1);
        vcdp->declBit(c+1105,"mips_cpu_harvard register_write_execute", false,-1);
        vcdp->declBit(c+593,"mips_cpu_harvard program_counter_multiplexer_jump_execute", false,-1);
        vcdp->declBit(c+601,"mips_cpu_harvard j_instruction_execute", false,-1);
        vcdp->declBit(c+609,"mips_cpu_harvard using_HI_LO_execute", false,-1);
        vcdp->declBit(c+617,"mips_cpu_harvard HALT_execute", false,-1);
        vcdp->declBus(c+625,"mips_cpu_harvard src_A_execute", false,-1, 31,0);
        vcdp->declBus(c+633,"mips_cpu_harvard src_B_execute", false,-1, 31,0);
        vcdp->declBus(c+153,"mips_cpu_harvard src_A_ALU_execute", false,-1, 31,0);
        vcdp->declBus(c+161,"mips_cpu_harvard src_B_ALU_execute", false,-1, 31,0);
        vcdp->declBus(c+1313,"mips_cpu_harvard write_data_execute", false,-1, 31,0);
        vcdp->declBus(c+169,"mips_cpu_harvard ALU_output_execute", false,-1, 31,0);
        vcdp->declBus(c+177,"mips_cpu_harvard ALU_HI_output_execute", false,-1, 31,0);
        vcdp->declBus(c+185,"mips_cpu_harvard ALU_LO_output_execute", false,-1, 31,0);
        vcdp->declBus(c+641,"mips_cpu_harvard Rs_execute", false,-1, 4,0);
        vcdp->declBus(c+649,"mips_cpu_harvard Rt_execute", false,-1, 4,0);
        vcdp->declBus(c+657,"mips_cpu_harvard Rd_execute", false,-1, 4,0);
        vcdp->declBus(c+665,"mips_cpu_harvard sign_imm_execute", false,-1, 31,0);
        vcdp->declBus(c+673,"mips_cpu_harvard program_counter_plus_eight_execute", false,-1, 31,0);
        vcdp->declBus(c+681,"mips_cpu_harvard program_counter_plus_four_execute", false,-1, 31,0);
        vcdp->declBus(c+689,"mips_cpu_harvard j_program_counter_execute", false,-1, 31,0);
        vcdp->declBit(c+1113,"mips_cpu_harvard register_write_memory", false,-1);
        vcdp->declBus(c+1121,"mips_cpu_harvard write_register_memory", false,-1, 4,0);
        vcdp->declBit(c+697,"mips_cpu_harvard memory_to_register_memory", false,-1);
        vcdp->declBit(c+705,"mips_cpu_harvard memory_write_memory", false,-1);
        vcdp->declBit(c+1129,"mips_cpu_harvard HI_register_write_memory", false,-1);
        vcdp->declBit(c+1137,"mips_cpu_harvard LO_register_write_memory", false,-1);
        vcdp->declBit(c+713,"mips_cpu_harvard program_counter_multiplexer_jump_memory", false,-1);
        vcdp->declBit(c+1321,"mips_cpu_harvard register_file_memory_mux_memory", false,-1);
        vcdp->declBit(c+721,"mips_cpu_harvard j_instruction_memory", false,-1);
        vcdp->declBit(c+729,"mips_cpu_harvard HALT_memory", false,-1);
        vcdp->declBus(c+737,"mips_cpu_harvard ALU_output_memory", false,-1, 31,0);
        vcdp->declBus(c+1145,"mips_cpu_harvard ALU_HI_output_memory", false,-1, 31,0);
        vcdp->declBus(c+1153,"mips_cpu_harvard ALU_LO_output_memory", false,-1, 31,0);
        vcdp->declBus(c+1297,"mips_cpu_harvard read_data_memory", false,-1, 31,0);
        vcdp->declBus(c+745,"mips_cpu_harvard write_data_memory", false,-1, 31,0);
        vcdp->declBus(c+753,"mips_cpu_harvard ALU_output_memory_resolved", false,-1, 31,0);
        vcdp->declBus(c+761,"mips_cpu_harvard j_program_counter_memory", false,-1, 31,0);
        vcdp->declBit(c+1161,"mips_cpu_harvard register_write_writeback", false,-1);
        vcdp->declBit(c+1169,"mips_cpu_harvard HI_register_write_writeback", false,-1);
        vcdp->declBit(c+1177,"mips_cpu_harvard LO_register_write_writeback", false,-1);
        vcdp->declBit(c+769,"mips_cpu_harvard memory_to_register_writeback", false,-1);
        vcdp->declBit(c+777,"mips_cpu_harvard HALT_writeback", false,-1);
        vcdp->declBus(c+1185,"mips_cpu_harvard write_register_writeback", false,-1, 4,0);
        vcdp->declBus(c+193,"mips_cpu_harvard result_writeback", false,-1, 31,0);
        vcdp->declBus(c+1193,"mips_cpu_harvard ALU_HI_output_writeback", false,-1, 31,0);
        vcdp->declBus(c+1201,"mips_cpu_harvard ALU_LO_output_writeback", false,-1, 31,0);
        vcdp->declBus(c+785,"mips_cpu_harvard ALU_output_writeback", false,-1, 31,0);
        vcdp->declBus(c+793,"mips_cpu_harvard read_data_writeback", false,-1, 31,0);
        vcdp->declBit(c+201,"mips_cpu_harvard stall_fetch", false,-1);
        vcdp->declBit(c+209,"mips_cpu_harvard stall_decode", false,-1);
        vcdp->declBit(c+801,"mips_cpu_harvard forward_A_decode", false,-1);
        vcdp->declBit(c+809,"mips_cpu_harvard forward_B_decode", false,-1);
        vcdp->declBit(c+217,"mips_cpu_harvard flush_execute_register", false,-1);
        vcdp->declBus(c+225,"mips_cpu_harvard forward_A_execute", false,-1, 2,0);
        vcdp->declBus(c+233,"mips_cpu_harvard forward_B_execute", false,-1, 2,0);
        vcdp->declBit(c+1329,"mips_cpu_harvard flush_fetch_decode_register", false,-1);
        vcdp->declBit(c+433,"mips_cpu_harvard register_file clk", false,-1);
        vcdp->declBit(c+1337,"mips_cpu_harvard register_file pipelined", false,-1);
        vcdp->declBit(c+1161,"mips_cpu_harvard register_file write_enable", false,-1);
        vcdp->declBit(c+1169,"mips_cpu_harvard register_file HI_write_enable", false,-1);
        vcdp->declBit(c+1177,"mips_cpu_harvard register_file LO_write_enable", false,-1);
        vcdp->declBus(c+505,"mips_cpu_harvard register_file read_address_1", false,-1, 4,0);
        vcdp->declBus(c+513,"mips_cpu_harvard register_file read_address_2", false,-1, 4,0);
        vcdp->declBus(c+1185,"mips_cpu_harvard register_file write_address", false,-1, 4,0);
        vcdp->declBus(c+193,"mips_cpu_harvard register_file write_data", false,-1, 31,0);
        vcdp->declBus(c+1193,"mips_cpu_harvard register_file HI_write_data", false,-1, 31,0);
        vcdp->declBus(c+1201,"mips_cpu_harvard register_file LO_write_data", false,-1, 31,0);
        vcdp->declBus(c+401,"mips_cpu_harvard register_file read_data_1", false,-1, 31,0);
        vcdp->declBus(c+409,"mips_cpu_harvard register_file read_data_2", false,-1, 31,0);
        vcdp->declBus(c+817,"mips_cpu_harvard register_file read_data_LO", false,-1, 31,0);
        vcdp->declBus(c+825,"mips_cpu_harvard register_file read_data_HI", false,-1, 31,0);
        vcdp->declBus(c+1233,"mips_cpu_harvard register_file read_register_2", false,-1, 31,0);
        {int i; for (i=0; i<32; i++) {
                vcdp->declBus(c+833+i*1,"mips_cpu_harvard register_file registers", true,(i+0), 31,0);}}
        vcdp->declBus(c+825,"mips_cpu_harvard register_file HI_reg", false,-1, 31,0);
        vcdp->declBus(c+817,"mips_cpu_harvard register_file LO_reg", false,-1, 31,0);
        vcdp->declBit(c+441,"mips_cpu_harvard register_file modified_write_clk", false,-1);
        vcdp->declBit(c+433,"mips_cpu_harvard pc clk", false,-1);
        vcdp->declBus(c+377,"mips_cpu_harvard pc address_input", false,-1, 31,0);
        vcdp->declBit(c+201,"mips_cpu_harvard pc enable", false,-1);
        vcdp->declBit(c+1217,"mips_cpu_harvard pc reset", false,-1);
        vcdp->declBit(c+465,"mips_cpu_harvard pc halt", false,-1);
        vcdp->declBus(c+449,"mips_cpu_harvard pc address_output", false,-1, 31,0);
        vcdp->declBus(c+449,"mips_cpu_harvard plus_four_adder a", false,-1, 31,0);
        vcdp->declBus(c+1345,"mips_cpu_harvard plus_four_adder b", false,-1, 31,0);
        vcdp->declBus(c+457,"mips_cpu_harvard plus_four_adder z", false,-1, 31,0);
        vcdp->declBus(c+1353,"mips_cpu_harvard program_counter_multiplexer BUS_WIDTH", false,-1, 31,0);
        vcdp->declBit(c+385,"mips_cpu_harvard program_counter_multiplexer control", false,-1);
        vcdp->declBus(c+457,"mips_cpu_harvard program_counter_multiplexer input_0", false,-1, 31,0);
        vcdp->declBus(c+1,"mips_cpu_harvard program_counter_multiplexer input_1", false,-1, 31,0);
        vcdp->declBus(c+25,"mips_cpu_harvard program_counter_multiplexer resolved", false,-1, 31,0);
        vcdp->declBus(c+1353,"mips_cpu_harvard program_counter_multiplexer_two BUS_WIDTH", false,-1, 31,0);
        vcdp->declBit(c+713,"mips_cpu_harvard program_counter_multiplexer_two control", false,-1);
        vcdp->declBus(c+25,"mips_cpu_harvard program_counter_multiplexer_two input_0", false,-1, 31,0);
        vcdp->declBus(c+753,"mips_cpu_harvard program_counter_multiplexer_two input_1", false,-1, 31,0);
        vcdp->declBus(c+377,"mips_cpu_harvard program_counter_multiplexer_two resolved", false,-1, 31,0);
        vcdp->declBit(c+433,"mips_cpu_harvard fetch_decode_register clk", false,-1);
        vcdp->declBit(c+209,"mips_cpu_harvard fetch_decode_register enable", false,-1);
        vcdp->declBit(c+385,"mips_cpu_harvard fetch_decode_register clear", false,-1);
        vcdp->declBit(c+1217,"mips_cpu_harvard fetch_decode_register reset", false,-1);
        vcdp->declBit(c+465,"mips_cpu_harvard fetch_decode_register HALT_fetch", false,-1);
        vcdp->declBit(c+473,"mips_cpu_harvard fetch_decode_register HALT_decode", false,-1);
        vcdp->declBus(c+1257,"mips_cpu_harvard fetch_decode_register instruction_fetch", false,-1, 31,0);
        vcdp->declBus(c+457,"mips_cpu_harvard fetch_decode_register program_counter_plus_four_fetch", false,-1, 31,0);
        vcdp->declBus(c+481,"mips_cpu_harvard fetch_decode_register instruction_decode", false,-1, 31,0);
        vcdp->declBus(c+489,"mips_cpu_harvard fetch_decode_register program_counter_plus_four_decode", false,-1, 31,0);
        vcdp->declBus(c+481,"mips_cpu_harvard control_unit instruction", false,-1, 31,0);
        vcdp->declBit(c+49,"mips_cpu_harvard control_unit register_write", false,-1);
        vcdp->declBit(c+57,"mips_cpu_harvard control_unit memory_to_register", false,-1);
        vcdp->declBit(c+65,"mips_cpu_harvard control_unit memory_write", false,-1);
        vcdp->declBus(c+73,"mips_cpu_harvard control_unit ALU_src_B", false,-1, 1,0);
        vcdp->declBus(c+81,"mips_cpu_harvard control_unit register_destination", false,-1, 1,0);
        vcdp->declBit(c+89,"mips_cpu_harvard control_unit branch", false,-1);
        vcdp->declBus(c+97,"mips_cpu_harvard control_unit ALU_function", false,-1, 5,0);
        vcdp->declBit(c+105,"mips_cpu_harvard control_unit program_counter_multiplexer_jump", false,-1);
        vcdp->declBit(c+121,"mips_cpu_harvard control_unit j_instruction", false,-1);
        vcdp->declBit(c+137,"mips_cpu_harvard control_unit LO_register_write", false,-1);
        vcdp->declBit(c+129,"mips_cpu_harvard control_unit HI_register_write", false,-1);
        vcdp->declBit(c+113,"mips_cpu_harvard control_unit using_HI_LO", false,-1);
        vcdp->declBus(c+241,"mips_cpu_harvard control_unit op", false,-1, 5,0);
        vcdp->declBus(c+249,"mips_cpu_harvard control_unit rt", false,-1, 4,0);
        vcdp->declBus(c+257,"mips_cpu_harvard control_unit funct", false,-1, 5,0);
        vcdp->declBus(c+497,"mips_cpu_harvard reg_output_comparator op", false,-1, 5,0);
        vcdp->declBus(c+513,"mips_cpu_harvard reg_output_comparator rt", false,-1, 4,0);
        vcdp->declBus(c+417,"mips_cpu_harvard reg_output_comparator a", false,-1, 31,0);
        vcdp->declBus(c+425,"mips_cpu_harvard reg_output_comparator b", false,-1, 31,0);
        vcdp->declBit(c+393,"mips_cpu_harvard reg_output_comparator c", false,-1);
        vcdp->declBus(c+9,"mips_cpu_harvard adder_decode a", false,-1, 31,0);
        vcdp->declBus(c+489,"mips_cpu_harvard adder_decode b", false,-1, 31,0);
        vcdp->declBus(c+1,"mips_cpu_harvard adder_decode z", false,-1, 31,0);
        vcdp->declBit(c+433,"mips_cpu_harvard decode_execute_register clk", false,-1);
        vcdp->declBit(c+217,"mips_cpu_harvard decode_execute_register clear", false,-1);
        vcdp->declBit(c+1217,"mips_cpu_harvard decode_execute_register reset", false,-1);
        vcdp->declBit(c+49,"mips_cpu_harvard decode_execute_register register_write_decode", false,-1);
        vcdp->declBit(c+57,"mips_cpu_harvard decode_execute_register memory_to_register_decode", false,-1);
        vcdp->declBit(c+65,"mips_cpu_harvard decode_execute_register memory_write_decode", false,-1);
        vcdp->declBus(c+73,"mips_cpu_harvard decode_execute_register ALU_src_B_decode", false,-1, 1,0);
        vcdp->declBus(c+81,"mips_cpu_harvard decode_execute_register register_destination_decode", false,-1, 1,0);
        vcdp->declBit(c+129,"mips_cpu_harvard decode_execute_register HI_register_write_decode", false,-1);
        vcdp->declBit(c+137,"mips_cpu_harvard decode_execute_register LO_register_write_decode", false,-1);
        vcdp->declBus(c+97,"mips_cpu_harvard decode_execute_register ALU_function_decode", false,-1, 5,0);
        vcdp->declBit(c+105,"mips_cpu_harvard decode_execute_register program_counter_multiplexer_jump_decode", false,-1);
        vcdp->declBit(c+121,"mips_cpu_harvard decode_execute_register j_instruction_decode", false,-1);
        vcdp->declBit(c+113,"mips_cpu_harvard decode_execute_register using_HI_LO_decode", false,-1);
        vcdp->declBit(c+473,"mips_cpu_harvard decode_execute_register HALT_decode", false,-1);
        vcdp->declBit(c+1105,"mips_cpu_harvard decode_execute_register register_write_execute", false,-1);
        vcdp->declBit(c+561,"mips_cpu_harvard decode_execute_register memory_to_register_execute", false,-1);
        vcdp->declBit(c+569,"mips_cpu_harvard decode_execute_register memory_write_execute", false,-1);
        vcdp->declBus(c+577,"mips_cpu_harvard decode_execute_register ALU_src_B_execute", false,-1, 1,0);
        vcdp->declBus(c+553,"mips_cpu_harvard decode_execute_register register_destination_execute", false,-1, 1,0);
        vcdp->declBit(c+1089,"mips_cpu_harvard decode_execute_register HI_register_write_execute", false,-1);
        vcdp->declBit(c+1097,"mips_cpu_harvard decode_execute_register LO_register_write_execute", false,-1);
        vcdp->declBus(c+585,"mips_cpu_harvard decode_execute_register ALU_function_execute", false,-1, 5,0);
        vcdp->declBit(c+593,"mips_cpu_harvard decode_execute_register program_counter_multiplexer_jump_execute", false,-1);
        vcdp->declBit(c+601,"mips_cpu_harvard decode_execute_register j_instruction_execute", false,-1);
        vcdp->declBit(c+609,"mips_cpu_harvard decode_execute_register using_HI_LO_execute", false,-1);
        vcdp->declBit(c+617,"mips_cpu_harvard decode_execute_register HALT_execute", false,-1);
        vcdp->declBus(c+505,"mips_cpu_harvard decode_execute_register Rs_decode", false,-1, 4,0);
        vcdp->declBus(c+513,"mips_cpu_harvard decode_execute_register Rt_decode", false,-1, 4,0);
        vcdp->declBus(c+521,"mips_cpu_harvard decode_execute_register Rd_decode", false,-1, 4,0);
        vcdp->declBus(c+17,"mips_cpu_harvard decode_execute_register sign_imm_decode", false,-1, 31,0);
        vcdp->declBus(c+641,"mips_cpu_harvard decode_execute_register Rs_execute", false,-1, 4,0);
        vcdp->declBus(c+649,"mips_cpu_harvard decode_execute_register Rt_execute", false,-1, 4,0);
        vcdp->declBus(c+657,"mips_cpu_harvard decode_execute_register Rd_execute", false,-1, 4,0);
        vcdp->declBus(c+665,"mips_cpu_harvard decode_execute_register sign_imm_execute", false,-1, 31,0);
        vcdp->declBus(c+33,"mips_cpu_harvard decode_execute_register src_A_decode", false,-1, 31,0);
        vcdp->declBus(c+41,"mips_cpu_harvard decode_execute_register src_B_decode", false,-1, 31,0);
        vcdp->declBus(c+489,"mips_cpu_harvard decode_execute_register program_counter_plus_four_decode", false,-1, 31,0);
        vcdp->declBus(c+545,"mips_cpu_harvard decode_execute_register j_program_counter_decode", false,-1, 31,0);
        vcdp->declBus(c+625,"mips_cpu_harvard decode_execute_register src_A_execute", false,-1, 31,0);
        vcdp->declBus(c+633,"mips_cpu_harvard decode_execute_register src_B_execute", false,-1, 31,0);
        vcdp->declBus(c+681,"mips_cpu_harvard decode_execute_register program_counter_plus_four_execute", false,-1, 31,0);
        vcdp->declBus(c+689,"mips_cpu_harvard decode_execute_register j_program_counter_execute", false,-1, 31,0);
        vcdp->declBus(c+1345,"mips_cpu_harvard plus_four_adder_execute a", false,-1, 31,0);
        vcdp->declBus(c+681,"mips_cpu_harvard plus_four_adder_execute b", false,-1, 31,0);
        vcdp->declBus(c+673,"mips_cpu_harvard plus_four_adder_execute z", false,-1, 31,0);
        vcdp->declBus(c+1361,"mips_cpu_harvard write_register_execute_mux BUS_WIDTH", false,-1, 31,0);
        vcdp->declBus(c+553,"mips_cpu_harvard write_register_execute_mux control", false,-1, 1,0);
        vcdp->declBus(c+649,"mips_cpu_harvard write_register_execute_mux input_0", false,-1, 4,0);
        vcdp->declBus(c+657,"mips_cpu_harvard write_register_execute_mux input_1", false,-1, 4,0);
        vcdp->declBus(c+1369,"mips_cpu_harvard write_register_execute_mux input_2", false,-1, 4,0);
        vcdp->declBus(c+1377,"mips_cpu_harvard write_register_execute_mux input_3", false,-1, 4,0);
        vcdp->declBus(c+145,"mips_cpu_harvard write_register_execute_mux resolved", false,-1, 4,0);
        vcdp->declBus(c+577,"mips_cpu_harvard alu_input_mux ALU_src_B_execute", false,-1, 1,0);
        vcdp->declBus(c+225,"mips_cpu_harvard alu_input_mux forward_one_execute", false,-1, 2,0);
        vcdp->declBus(c+233,"mips_cpu_harvard alu_input_mux forward_two_execute", false,-1, 2,0);
        vcdp->declBus(c+625,"mips_cpu_harvard alu_input_mux read_data_1_reg", false,-1, 31,0);
        vcdp->declBus(c+193,"mips_cpu_harvard alu_input_mux result_writeback", false,-1, 31,0);
        vcdp->declBus(c+737,"mips_cpu_harvard alu_input_mux ALU_output_memory", false,-1, 31,0);
        vcdp->declBus(c+1201,"mips_cpu_harvard alu_input_mux LO_result_writeback", false,-1, 31,0);
        vcdp->declBus(c+1153,"mips_cpu_harvard alu_input_mux ALU_LO_output_memory", false,-1, 31,0);
        vcdp->declBus(c+633,"mips_cpu_harvard alu_input_mux read_data_2_reg", false,-1, 31,0);
        vcdp->declBus(c+1145,"mips_cpu_harvard alu_input_mux ALU_HI_output_memory", false,-1, 31,0);
        vcdp->declBus(c+1193,"mips_cpu_harvard alu_input_mux HI_result_writeback", false,-1, 31,0);
        vcdp->declBus(c+665,"mips_cpu_harvard alu_input_mux sign_imm_execute", false,-1, 31,0);
        vcdp->declBus(c+673,"mips_cpu_harvard alu_input_mux program_counter_plus_eight_execute", false,-1, 31,0);
        vcdp->declBus(c+153,"mips_cpu_harvard alu_input_mux src_A_ALU_execute", false,-1, 31,0);
        vcdp->declBus(c+161,"mips_cpu_harvard alu_input_mux src_B_ALU_execute", false,-1, 31,0);
        vcdp->declBus(c+265,"mips_cpu_harvard alu_input_mux src_mux_input_0", false,-1, 31,0);
        vcdp->declBus(c+585,"mips_cpu_harvard alu ALU_operation", false,-1, 5,0);
        vcdp->declBus(c+153,"mips_cpu_harvard alu input_1", false,-1, 31,0);
        vcdp->declBus(c+161,"mips_cpu_harvard alu input_2", false,-1, 31,0);
        vcdp->declBus(c+169,"mips_cpu_harvard alu ALU_output", false,-1, 31,0);
        vcdp->declBus(c+177,"mips_cpu_harvard alu ALU_HI_output", false,-1, 31,0);
        vcdp->declBus(c+185,"mips_cpu_harvard alu ALU_LO_output", false,-1, 31,0);
        vcdp->declBus(c+273,"mips_cpu_harvard alu shift_amount", false,-1, 4,0);
        vcdp->declQuad(c+281,"mips_cpu_harvard alu sign_extened_input_1", false,-1, 63,0);
        vcdp->declQuad(c+297,"mips_cpu_harvard alu sign_extened_input_2", false,-1, 63,0);
        vcdp->declQuad(c+313,"mips_cpu_harvard alu extended_input_1", false,-1, 63,0);
        vcdp->declQuad(c+329,"mips_cpu_harvard alu extended_input_2", false,-1, 63,0);
        vcdp->declQuad(c+345,"mips_cpu_harvard alu ALU_HI_LO_output", false,-1, 63,0);
        vcdp->declBit(c+433,"mips_cpu_harvard execute_memory_register clk", false,-1);
        vcdp->declBit(c+1217,"mips_cpu_harvard execute_memory_register reset", false,-1);
        vcdp->declBit(c+1105,"mips_cpu_harvard execute_memory_register register_write_execute", false,-1);
        vcdp->declBit(c+561,"mips_cpu_harvard execute_memory_register memory_to_register_execute", false,-1);
        vcdp->declBit(c+569,"mips_cpu_harvard execute_memory_register memory_write_execute", false,-1);
        vcdp->declBit(c+1089,"mips_cpu_harvard execute_memory_register HI_register_write_execute", false,-1);
        vcdp->declBit(c+1097,"mips_cpu_harvard execute_memory_register LO_register_write_execute", false,-1);
        vcdp->declBit(c+593,"mips_cpu_harvard execute_memory_register program_counter_multiplexer_jump_execute", false,-1);
        vcdp->declBit(c+601,"mips_cpu_harvard execute_memory_register j_instruction_execute", false,-1);
        vcdp->declBit(c+617,"mips_cpu_harvard execute_memory_register HALT_execute", false,-1);
        vcdp->declBit(c+1113,"mips_cpu_harvard execute_memory_register register_write_memory", false,-1);
        vcdp->declBit(c+697,"mips_cpu_harvard execute_memory_register memory_to_register_memory", false,-1);
        vcdp->declBit(c+705,"mips_cpu_harvard execute_memory_register memory_write_memory", false,-1);
        vcdp->declBit(c+1129,"mips_cpu_harvard execute_memory_register HI_register_write_memory", false,-1);
        vcdp->declBit(c+1137,"mips_cpu_harvard execute_memory_register LO_register_write_memory", false,-1);
        vcdp->declBit(c+713,"mips_cpu_harvard execute_memory_register program_counter_multiplexer_jump_memory", false,-1);
        vcdp->declBit(c+721,"mips_cpu_harvard execute_memory_register j_instruction_memory", false,-1);
        vcdp->declBit(c+729,"mips_cpu_harvard execute_memory_register HALT_memory", false,-1);
        vcdp->declBus(c+169,"mips_cpu_harvard execute_memory_register ALU_output_execute", false,-1, 31,0);
        vcdp->declBus(c+177,"mips_cpu_harvard execute_memory_register ALU_HI_output_execute", false,-1, 31,0);
        vcdp->declBus(c+185,"mips_cpu_harvard execute_memory_register ALU_LO_output_execute", false,-1, 31,0);
        vcdp->declBus(c+1313,"mips_cpu_harvard execute_memory_register write_data_execute", false,-1, 31,0);
        vcdp->declBus(c+145,"mips_cpu_harvard execute_memory_register write_register_execute", false,-1, 4,0);
        vcdp->declBus(c+689,"mips_cpu_harvard execute_memory_register j_program_counter_execute", false,-1, 31,0);
        vcdp->declBus(c+737,"mips_cpu_harvard execute_memory_register ALU_output_memory", false,-1, 31,0);
        vcdp->declBus(c+1145,"mips_cpu_harvard execute_memory_register ALU_HI_output_memory", false,-1, 31,0);
        vcdp->declBus(c+1153,"mips_cpu_harvard execute_memory_register ALU_LO_output_memory", false,-1, 31,0);
        vcdp->declBus(c+745,"mips_cpu_harvard execute_memory_register write_data_memory", false,-1, 31,0);
        vcdp->declBus(c+1121,"mips_cpu_harvard execute_memory_register write_register_memory", false,-1, 4,0);
        vcdp->declBus(c+761,"mips_cpu_harvard execute_memory_register j_program_counter_memory", false,-1, 31,0);
        vcdp->declBit(c+433,"mips_cpu_harvard memory_writeback_register clk", false,-1);
        vcdp->declBit(c+1217,"mips_cpu_harvard memory_writeback_register reset", false,-1);
        vcdp->declBit(c+1113,"mips_cpu_harvard memory_writeback_register register_write_memory", false,-1);
        vcdp->declBit(c+697,"mips_cpu_harvard memory_writeback_register memory_to_register_memory", false,-1);
        vcdp->declBit(c+1129,"mips_cpu_harvard memory_writeback_register HI_register_write_memory", false,-1);
        vcdp->declBit(c+1137,"mips_cpu_harvard memory_writeback_register LO_register_write_memory", false,-1);
        vcdp->declBit(c+729,"mips_cpu_harvard memory_writeback_register HALT_memory", false,-1);
        vcdp->declBit(c+1161,"mips_cpu_harvard memory_writeback_register register_write_writeback", false,-1);
        vcdp->declBit(c+769,"mips_cpu_harvard memory_writeback_register memory_to_register_writeback", false,-1);
        vcdp->declBit(c+1169,"mips_cpu_harvard memory_writeback_register HI_register_write_writeback", false,-1);
        vcdp->declBit(c+1177,"mips_cpu_harvard memory_writeback_register LO_register_write_writeback", false,-1);
        vcdp->declBit(c+777,"mips_cpu_harvard memory_writeback_register HALT_writeback", false,-1);
        vcdp->declBus(c+737,"mips_cpu_harvard memory_writeback_register ALU_output_memory", false,-1, 31,0);
        vcdp->declBus(c+1121,"mips_cpu_harvard memory_writeback_register write_register_memory", false,-1, 4,0);
        vcdp->declBus(c+1145,"mips_cpu_harvard memory_writeback_register ALU_HI_output_memory", false,-1, 31,0);
        vcdp->declBus(c+1153,"mips_cpu_harvard memory_writeback_register ALU_LO_output_memory", false,-1, 31,0);
        vcdp->declBus(c+1297,"mips_cpu_harvard memory_writeback_register read_data_memory", false,-1, 31,0);
        vcdp->declBus(c+785,"mips_cpu_harvard memory_writeback_register ALU_output_writeback", false,-1, 31,0);
        vcdp->declBus(c+1185,"mips_cpu_harvard memory_writeback_register write_register_writeback", false,-1, 4,0);
        vcdp->declBus(c+1193,"mips_cpu_harvard memory_writeback_register ALU_HI_output_writeback", false,-1, 31,0);
        vcdp->declBus(c+1201,"mips_cpu_harvard memory_writeback_register ALU_LO_output_writeback", false,-1, 31,0);
        vcdp->declBus(c+793,"mips_cpu_harvard memory_writeback_register read_data_writeback", false,-1, 31,0);
        vcdp->declBus(c+1353,"mips_cpu_harvard writeback_mux BUS_WIDTH", false,-1, 31,0);
        vcdp->declBit(c+769,"mips_cpu_harvard writeback_mux control", false,-1);
        vcdp->declBus(c+785,"mips_cpu_harvard writeback_mux input_0", false,-1, 31,0);
        vcdp->declBus(c+793,"mips_cpu_harvard writeback_mux input_1", false,-1, 31,0);
        vcdp->declBus(c+193,"mips_cpu_harvard writeback_mux resolved", false,-1, 31,0);
        vcdp->declBit(c+89,"mips_cpu_harvard hazard_unit branch_decode", false,-1);
        vcdp->declBus(c+505,"mips_cpu_harvard hazard_unit Rs_decode", false,-1, 4,0);
        vcdp->declBus(c+513,"mips_cpu_harvard hazard_unit Rt_decode", false,-1, 4,0);
        vcdp->declBus(c+641,"mips_cpu_harvard hazard_unit Rs_execute", false,-1, 4,0);
        vcdp->declBus(c+649,"mips_cpu_harvard hazard_unit Rt_execute", false,-1, 4,0);
        vcdp->declBus(c+145,"mips_cpu_harvard hazard_unit write_register_execute", false,-1, 4,0);
        vcdp->declBit(c+561,"mips_cpu_harvard hazard_unit memory_to_register_execute", false,-1);
        vcdp->declBit(c+1105,"mips_cpu_harvard hazard_unit register_write_execute", false,-1);
        vcdp->declBus(c+1121,"mips_cpu_harvard hazard_unit write_register_memory", false,-1, 4,0);
        vcdp->declBit(c+697,"mips_cpu_harvard hazard_unit memory_to_register_memory", false,-1);
        vcdp->declBit(c+1113,"mips_cpu_harvard hazard_unit register_write_memory", false,-1);
        vcdp->declBus(c+1185,"mips_cpu_harvard hazard_unit write_register_writeback", false,-1, 4,0);
        vcdp->declBit(c+1161,"mips_cpu_harvard hazard_unit register_write_writeback", false,-1);
        vcdp->declBit(c+593,"mips_cpu_harvard hazard_unit program_counter_multiplexer_jump_execute", false,-1);
        vcdp->declBit(c+1129,"mips_cpu_harvard hazard_unit HI_register_write_memory", false,-1);
        vcdp->declBit(c+1137,"mips_cpu_harvard hazard_unit LO_register_write_memory", false,-1);
        vcdp->declBit(c+1177,"mips_cpu_harvard hazard_unit LO_register_write_writeback", false,-1);
        vcdp->declBit(c+1169,"mips_cpu_harvard hazard_unit HI_register_write_writeback", false,-1);
        vcdp->declBit(c+609,"mips_cpu_harvard hazard_unit using_HI_LO_execute", false,-1);
        vcdp->declBit(c+201,"mips_cpu_harvard hazard_unit stall_fetch", false,-1);
        vcdp->declBit(c+209,"mips_cpu_harvard hazard_unit stall_decode", false,-1);
        vcdp->declBit(c+801,"mips_cpu_harvard hazard_unit forward_register_file_output_A_decode", false,-1);
        vcdp->declBit(c+809,"mips_cpu_harvard hazard_unit forward_register_file_output_B_decode", false,-1);
        vcdp->declBit(c+217,"mips_cpu_harvard hazard_unit flush_execute_register", false,-1);
        vcdp->declBus(c+225,"mips_cpu_harvard hazard_unit forward_register_file_output_A_execute", false,-1, 2,0);
        vcdp->declBus(c+233,"mips_cpu_harvard hazard_unit forward_register_file_output_B_execute", false,-1, 2,0);
        vcdp->declBit(c+361,"mips_cpu_harvard hazard_unit lwstall", false,-1);
        vcdp->declBit(c+369,"mips_cpu_harvard hazard_unit branchstall", false,-1);
    }
}

void MIPS_Harvard_TB::traceFullThis__1(MIPS_Harvard_TB__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    MIPS_Harvard_TB* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
        vcdp->fullBus(c+1,(((vlTOPp->mips_cpu_harvard__DOT__sign_imm_decode 
                             << 2U) + vlTOPp->mips_cpu_harvard__DOT__program_counter_plus_four_decode)),32);
        vcdp->fullBus(c+9,((vlTOPp->mips_cpu_harvard__DOT__sign_imm_decode 
                            << 2U)),32);
        vcdp->fullBus(c+17,(vlTOPp->mips_cpu_harvard__DOT__sign_imm_decode),32);
        vcdp->fullBus(c+25,(((IData)(vlTOPp->mips_cpu_harvard__DOT__program_counter_src_decode)
                              ? ((vlTOPp->mips_cpu_harvard__DOT__sign_imm_decode 
                                  << 2U) + vlTOPp->mips_cpu_harvard__DOT__program_counter_plus_four_decode)
                              : ((IData)(4U) + vlTOPp->mips_cpu_harvard__DOT__program_counter_fetch))),32);
        vcdp->fullBus(c+33,(((IData)(vlTOPp->mips_cpu_harvard__DOT__using_HI_LO_decode)
                              ? vlTOPp->mips_cpu_harvard__DOT__register_file__DOT__LO_reg
                              : vlTOPp->mips_cpu_harvard__DOT__register_file_output_A_decode)),32);
        vcdp->fullBus(c+41,(((IData)(vlTOPp->mips_cpu_harvard__DOT__using_HI_LO_decode)
                              ? vlTOPp->mips_cpu_harvard__DOT__register_file__DOT__HI_reg
                              : vlTOPp->mips_cpu_harvard__DOT__register_file_output_B_decode)),32);
        vcdp->fullBit(c+49,(vlTOPp->mips_cpu_harvard__DOT__register_write_decode));
        vcdp->fullBit(c+57,(vlTOPp->mips_cpu_harvard__DOT__memory_to_register_decode));
        vcdp->fullBit(c+65,(vlTOPp->mips_cpu_harvard__DOT__memory_write_decode));
        vcdp->fullBus(c+73,(vlTOPp->mips_cpu_harvard__DOT__ALU_src_B_decode),2);
        vcdp->fullBus(c+81,(vlTOPp->mips_cpu_harvard__DOT__register_destination_decode),2);
        vcdp->fullBit(c+89,(vlTOPp->mips_cpu_harvard__DOT__branch_decode));
        vcdp->fullBus(c+97,(vlTOPp->mips_cpu_harvard__DOT__ALU_function_decode),6);
        vcdp->fullBit(c+105,(vlTOPp->mips_cpu_harvard__DOT__program_counter_multiplexer_jump_decode));
        vcdp->fullBit(c+113,(vlTOPp->mips_cpu_harvard__DOT__using_HI_LO_decode));
        vcdp->fullBit(c+121,(vlTOPp->mips_cpu_harvard__DOT__j_instruction_decode));
        vcdp->fullBit(c+129,(vlTOPp->mips_cpu_harvard__DOT__HI_register_write_decode));
        vcdp->fullBit(c+137,(vlTOPp->mips_cpu_harvard__DOT__LO_register_write_decode));
        vcdp->fullBus(c+145,(vlTOPp->mips_cpu_harvard__DOT__write_register_execute),5);
        vcdp->fullBus(c+153,(vlTOPp->mips_cpu_harvard__DOT__src_A_ALU_execute),32);
        vcdp->fullBus(c+161,(vlTOPp->mips_cpu_harvard__DOT__src_B_ALU_execute),32);
        vcdp->fullBus(c+169,(vlTOPp->mips_cpu_harvard__DOT__ALU_output_execute),32);
        vcdp->fullBus(c+177,(vlTOPp->mips_cpu_harvard__DOT__ALU_HI_output_execute),32);
        vcdp->fullBus(c+185,(vlTOPp->mips_cpu_harvard__DOT__ALU_LO_output_execute),32);
        vcdp->fullBus(c+193,(vlTOPp->mips_cpu_harvard__DOT__result_writeback),32);
        vcdp->fullBit(c+201,(vlTOPp->mips_cpu_harvard__DOT__stall_fetch));
        vcdp->fullBit(c+209,(vlTOPp->mips_cpu_harvard__DOT__stall_decode));
        vcdp->fullBit(c+217,(vlTOPp->mips_cpu_harvard__DOT__flush_execute_register));
        vcdp->fullBus(c+225,(vlTOPp->mips_cpu_harvard__DOT__forward_A_execute),3);
        vcdp->fullBus(c+233,(vlTOPp->mips_cpu_harvard__DOT__forward_B_execute),3);
        vcdp->fullBus(c+241,(vlTOPp->mips_cpu_harvard__DOT__control_unit__DOT__op),6);
        vcdp->fullBus(c+249,(vlTOPp->mips_cpu_harvard__DOT__control_unit__DOT__rt),5);
        vcdp->fullBus(c+257,(vlTOPp->mips_cpu_harvard__DOT__control_unit__DOT__funct),6);
        vcdp->fullBus(c+265,(vlTOPp->mips_cpu_harvard__DOT__alu_input_mux__DOT__src_mux_input_0),32);
        vcdp->fullBus(c+273,((0x1fU & (vlTOPp->mips_cpu_harvard__DOT__src_A_ALU_execute 
                                       >> 6U))),5);
        vcdp->fullQuad(c+281,((((QData)((IData)(VL_NEGATE_I((IData)(
                                                                    (1U 
                                                                     & (vlTOPp->mips_cpu_harvard__DOT__src_A_ALU_execute 
                                                                        >> 0x1fU)))))) 
                                << 0x20U) | (QData)((IData)(vlTOPp->mips_cpu_harvard__DOT__src_A_ALU_execute)))),64);
        vcdp->fullQuad(c+297,((((QData)((IData)(VL_NEGATE_I((IData)(
                                                                    (1U 
                                                                     & (vlTOPp->mips_cpu_harvard__DOT__src_B_ALU_execute 
                                                                        >> 0x1fU)))))) 
                                << 0x20U) | (QData)((IData)(vlTOPp->mips_cpu_harvard__DOT__src_B_ALU_execute)))),64);
        vcdp->fullQuad(c+313,((QData)((IData)(vlTOPp->mips_cpu_harvard__DOT__src_A_ALU_execute))),64);
        vcdp->fullQuad(c+329,((QData)((IData)(vlTOPp->mips_cpu_harvard__DOT__src_B_ALU_execute))),64);
        vcdp->fullQuad(c+345,(vlTOPp->mips_cpu_harvard__DOT__alu__DOT__ALU_HI_LO_output),64);
        vcdp->fullBit(c+361,(vlTOPp->mips_cpu_harvard__DOT__hazard_unit__DOT__lwstall));
        vcdp->fullBit(c+369,(vlTOPp->mips_cpu_harvard__DOT__hazard_unit__DOT__branchstall));
        vcdp->fullBus(c+377,(vlTOPp->mips_cpu_harvard__DOT__program_counter_prime),32);
        vcdp->fullBit(c+385,(vlTOPp->mips_cpu_harvard__DOT__program_counter_src_decode));
        vcdp->fullBit(c+393,(vlTOPp->mips_cpu_harvard__DOT__equal_decode));
        vcdp->fullBus(c+401,(vlTOPp->mips_cpu_harvard__DOT__register_file_output_A_decode),32);
        vcdp->fullBus(c+409,(vlTOPp->mips_cpu_harvard__DOT__register_file_output_B_decode),32);
        vcdp->fullBus(c+417,(vlTOPp->mips_cpu_harvard__DOT__comparator_1),32);
        vcdp->fullBus(c+425,(vlTOPp->mips_cpu_harvard__DOT__comparator_2),32);
        vcdp->fullBit(c+433,(vlTOPp->mips_cpu_harvard__DOT__internal_clk));
        vcdp->fullBit(c+441,((1U & (~ (IData)(vlTOPp->mips_cpu_harvard__DOT__internal_clk)))));
        vcdp->fullBus(c+449,(vlTOPp->mips_cpu_harvard__DOT__program_counter_fetch),32);
        vcdp->fullBus(c+457,(((IData)(4U) + vlTOPp->mips_cpu_harvard__DOT__program_counter_fetch)),32);
        vcdp->fullBit(c+465,(vlTOPp->mips_cpu_harvard__DOT__HALT_fetch));
        vcdp->fullBit(c+473,(vlTOPp->mips_cpu_harvard__DOT__HALT_decode));
        vcdp->fullBus(c+481,(vlTOPp->mips_cpu_harvard__DOT__instruction_decode),32);
        vcdp->fullBus(c+489,(vlTOPp->mips_cpu_harvard__DOT__program_counter_plus_four_decode),32);
        vcdp->fullBus(c+497,((0x3fU & (vlTOPp->mips_cpu_harvard__DOT__instruction_decode 
                                       >> 0x1aU))),6);
        vcdp->fullBus(c+505,((0x1fU & (vlTOPp->mips_cpu_harvard__DOT__instruction_decode 
                                       >> 0x15U))),5);
        vcdp->fullBus(c+513,((0x1fU & (vlTOPp->mips_cpu_harvard__DOT__instruction_decode 
                                       >> 0x10U))),5);
        vcdp->fullBus(c+521,((0x1fU & (vlTOPp->mips_cpu_harvard__DOT__instruction_decode 
                                       >> 0xbU))),5);
        vcdp->fullBus(c+529,((0xffffU & vlTOPp->mips_cpu_harvard__DOT__instruction_decode)),16);
        vcdp->fullBus(c+537,((0x3ffffffU & vlTOPp->mips_cpu_harvard__DOT__instruction_decode)),26);
        vcdp->fullBus(c+545,(((0xf0000000U & vlTOPp->mips_cpu_harvard__DOT__program_counter_plus_four_decode) 
                              | (0xffffffcU & (vlTOPp->mips_cpu_harvard__DOT__instruction_decode 
                                               << 2U)))),32);
        vcdp->fullBus(c+553,(vlTOPp->mips_cpu_harvard__DOT__register_destination_execute),2);
        vcdp->fullBit(c+561,(vlTOPp->mips_cpu_harvard__DOT__memory_to_register_execute));
        vcdp->fullBit(c+569,(vlTOPp->mips_cpu_harvard__DOT__memory_write_execute));
        vcdp->fullBus(c+577,(vlTOPp->mips_cpu_harvard__DOT__ALU_src_B_execute),2);
        vcdp->fullBus(c+585,(vlTOPp->mips_cpu_harvard__DOT__ALU_function_execute),6);
        vcdp->fullBit(c+593,(vlTOPp->mips_cpu_harvard__DOT__program_counter_multiplexer_jump_execute));
        vcdp->fullBit(c+601,(vlTOPp->mips_cpu_harvard__DOT__j_instruction_execute));
        vcdp->fullBit(c+609,(vlTOPp->mips_cpu_harvard__DOT__using_HI_LO_execute));
        vcdp->fullBit(c+617,(vlTOPp->mips_cpu_harvard__DOT__HALT_execute));
        vcdp->fullBus(c+625,(vlTOPp->mips_cpu_harvard__DOT__src_A_execute),32);
        vcdp->fullBus(c+633,(vlTOPp->mips_cpu_harvard__DOT__src_B_execute),32);
        vcdp->fullBus(c+641,(vlTOPp->mips_cpu_harvard__DOT__Rs_execute),5);
        vcdp->fullBus(c+649,(vlTOPp->mips_cpu_harvard__DOT__Rt_execute),5);
        vcdp->fullBus(c+657,(vlTOPp->mips_cpu_harvard__DOT__Rd_execute),5);
        vcdp->fullBus(c+665,(vlTOPp->mips_cpu_harvard__DOT__sign_imm_execute),32);
        vcdp->fullBus(c+673,(((IData)(4U) + vlTOPp->mips_cpu_harvard__DOT__program_counter_plus_four_execute)),32);
        vcdp->fullBus(c+681,(vlTOPp->mips_cpu_harvard__DOT__program_counter_plus_four_execute),32);
        vcdp->fullBus(c+689,(vlTOPp->mips_cpu_harvard__DOT__j_program_counter_execute),32);
        vcdp->fullBit(c+697,(vlTOPp->mips_cpu_harvard__DOT__memory_to_register_memory));
        vcdp->fullBit(c+705,(vlTOPp->mips_cpu_harvard__DOT__memory_write_memory));
        vcdp->fullBit(c+713,(vlTOPp->mips_cpu_harvard__DOT__program_counter_multiplexer_jump_memory));
        vcdp->fullBit(c+721,(vlTOPp->mips_cpu_harvard__DOT__j_instruction_memory));
        vcdp->fullBit(c+729,(vlTOPp->mips_cpu_harvard__DOT__HALT_memory));
        vcdp->fullBus(c+737,(vlTOPp->mips_cpu_harvard__DOT__ALU_output_memory),32);
        vcdp->fullBus(c+745,(vlTOPp->mips_cpu_harvard__DOT__write_data_memory),32);
        vcdp->fullBus(c+753,(((IData)(vlTOPp->mips_cpu_harvard__DOT__j_instruction_memory)
                               ? vlTOPp->mips_cpu_harvard__DOT__j_program_counter_execute
                               : vlTOPp->mips_cpu_harvard__DOT__ALU_output_memory)),32);
        vcdp->fullBus(c+761,(vlTOPp->mips_cpu_harvard__DOT__j_program_counter_memory),32);
        vcdp->fullBit(c+769,(vlTOPp->mips_cpu_harvard__DOT__memory_to_register_writeback));
        vcdp->fullBit(c+777,(vlTOPp->mips_cpu_harvard__DOT__HALT_writeback));
        vcdp->fullBus(c+785,(vlTOPp->mips_cpu_harvard__DOT__ALU_output_writeback),32);
        vcdp->fullBus(c+793,(vlTOPp->mips_cpu_harvard__DOT__read_data_writeback),32);
        vcdp->fullBit(c+801,((((0U != (0x1fU & (vlTOPp->mips_cpu_harvard__DOT__instruction_decode 
                                                >> 0x15U))) 
                               & ((0x1fU & (vlTOPp->mips_cpu_harvard__DOT__instruction_decode 
                                            >> 0x15U)) 
                                  == (IData)(vlTOPp->mips_cpu_harvard__DOT__write_register_memory))) 
                              & (IData)(vlTOPp->mips_cpu_harvard__DOT__register_write_memory))));
        vcdp->fullBit(c+809,((((0U != (0x1fU & (vlTOPp->mips_cpu_harvard__DOT__instruction_decode 
                                                >> 0x10U))) 
                               & ((0x1fU & (vlTOPp->mips_cpu_harvard__DOT__instruction_decode 
                                            >> 0x10U)) 
                                  == (IData)(vlTOPp->mips_cpu_harvard__DOT__write_register_memory))) 
                              & (IData)(vlTOPp->mips_cpu_harvard__DOT__register_write_memory))));
        vcdp->fullBus(c+817,(vlTOPp->mips_cpu_harvard__DOT__register_file__DOT__LO_reg),32);
        vcdp->fullBus(c+825,(vlTOPp->mips_cpu_harvard__DOT__register_file__DOT__HI_reg),32);
        vcdp->fullBus(c+833,(vlTOPp->mips_cpu_harvard__DOT__register_file__DOT__registers[0]),32);
        vcdp->fullBus(c+834,(vlTOPp->mips_cpu_harvard__DOT__register_file__DOT__registers[1]),32);
        vcdp->fullBus(c+835,(vlTOPp->mips_cpu_harvard__DOT__register_file__DOT__registers[2]),32);
        vcdp->fullBus(c+836,(vlTOPp->mips_cpu_harvard__DOT__register_file__DOT__registers[3]),32);
        vcdp->fullBus(c+837,(vlTOPp->mips_cpu_harvard__DOT__register_file__DOT__registers[4]),32);
        vcdp->fullBus(c+838,(vlTOPp->mips_cpu_harvard__DOT__register_file__DOT__registers[5]),32);
        vcdp->fullBus(c+839,(vlTOPp->mips_cpu_harvard__DOT__register_file__DOT__registers[6]),32);
        vcdp->fullBus(c+840,(vlTOPp->mips_cpu_harvard__DOT__register_file__DOT__registers[7]),32);
        vcdp->fullBus(c+841,(vlTOPp->mips_cpu_harvard__DOT__register_file__DOT__registers[8]),32);
        vcdp->fullBus(c+842,(vlTOPp->mips_cpu_harvard__DOT__register_file__DOT__registers[9]),32);
        vcdp->fullBus(c+843,(vlTOPp->mips_cpu_harvard__DOT__register_file__DOT__registers[10]),32);
        vcdp->fullBus(c+844,(vlTOPp->mips_cpu_harvard__DOT__register_file__DOT__registers[11]),32);
        vcdp->fullBus(c+845,(vlTOPp->mips_cpu_harvard__DOT__register_file__DOT__registers[12]),32);
        vcdp->fullBus(c+846,(vlTOPp->mips_cpu_harvard__DOT__register_file__DOT__registers[13]),32);
        vcdp->fullBus(c+847,(vlTOPp->mips_cpu_harvard__DOT__register_file__DOT__registers[14]),32);
        vcdp->fullBus(c+848,(vlTOPp->mips_cpu_harvard__DOT__register_file__DOT__registers[15]),32);
        vcdp->fullBus(c+849,(vlTOPp->mips_cpu_harvard__DOT__register_file__DOT__registers[16]),32);
        vcdp->fullBus(c+850,(vlTOPp->mips_cpu_harvard__DOT__register_file__DOT__registers[17]),32);
        vcdp->fullBus(c+851,(vlTOPp->mips_cpu_harvard__DOT__register_file__DOT__registers[18]),32);
        vcdp->fullBus(c+852,(vlTOPp->mips_cpu_harvard__DOT__register_file__DOT__registers[19]),32);
        vcdp->fullBus(c+853,(vlTOPp->mips_cpu_harvard__DOT__register_file__DOT__registers[20]),32);
        vcdp->fullBus(c+854,(vlTOPp->mips_cpu_harvard__DOT__register_file__DOT__registers[21]),32);
        vcdp->fullBus(c+855,(vlTOPp->mips_cpu_harvard__DOT__register_file__DOT__registers[22]),32);
        vcdp->fullBus(c+856,(vlTOPp->mips_cpu_harvard__DOT__register_file__DOT__registers[23]),32);
        vcdp->fullBus(c+857,(vlTOPp->mips_cpu_harvard__DOT__register_file__DOT__registers[24]),32);
        vcdp->fullBus(c+858,(vlTOPp->mips_cpu_harvard__DOT__register_file__DOT__registers[25]),32);
        vcdp->fullBus(c+859,(vlTOPp->mips_cpu_harvard__DOT__register_file__DOT__registers[26]),32);
        vcdp->fullBus(c+860,(vlTOPp->mips_cpu_harvard__DOT__register_file__DOT__registers[27]),32);
        vcdp->fullBus(c+861,(vlTOPp->mips_cpu_harvard__DOT__register_file__DOT__registers[28]),32);
        vcdp->fullBus(c+862,(vlTOPp->mips_cpu_harvard__DOT__register_file__DOT__registers[29]),32);
        vcdp->fullBus(c+863,(vlTOPp->mips_cpu_harvard__DOT__register_file__DOT__registers[30]),32);
        vcdp->fullBus(c+864,(vlTOPp->mips_cpu_harvard__DOT__register_file__DOT__registers[31]),32);
        vcdp->fullBit(c+1089,(vlTOPp->mips_cpu_harvard__DOT__HI_register_write_execute));
        vcdp->fullBit(c+1097,(vlTOPp->mips_cpu_harvard__DOT__LO_register_write_execute));
        vcdp->fullBit(c+1105,(vlTOPp->mips_cpu_harvard__DOT__register_write_execute));
        vcdp->fullBit(c+1113,(vlTOPp->mips_cpu_harvard__DOT__register_write_memory));
        vcdp->fullBus(c+1121,(vlTOPp->mips_cpu_harvard__DOT__write_register_memory),5);
        vcdp->fullBit(c+1129,(vlTOPp->mips_cpu_harvard__DOT__HI_register_write_memory));
        vcdp->fullBit(c+1137,(vlTOPp->mips_cpu_harvard__DOT__LO_register_write_memory));
        vcdp->fullBus(c+1145,(vlTOPp->mips_cpu_harvard__DOT__ALU_HI_output_memory),32);
        vcdp->fullBus(c+1153,(vlTOPp->mips_cpu_harvard__DOT__ALU_LO_output_memory),32);
        vcdp->fullBit(c+1161,(vlTOPp->mips_cpu_harvard__DOT__register_write_writeback));
        vcdp->fullBit(c+1169,(vlTOPp->mips_cpu_harvard__DOT__HI_register_write_writeback));
        vcdp->fullBit(c+1177,(vlTOPp->mips_cpu_harvard__DOT__LO_register_write_writeback));
        vcdp->fullBus(c+1185,(vlTOPp->mips_cpu_harvard__DOT__write_register_writeback),5);
        vcdp->fullBus(c+1193,(vlTOPp->mips_cpu_harvard__DOT__ALU_HI_output_writeback),32);
        vcdp->fullBus(c+1201,(vlTOPp->mips_cpu_harvard__DOT__ALU_LO_output_writeback),32);
        vcdp->fullBit(c+1209,(vlTOPp->clk));
        vcdp->fullBit(c+1217,(vlTOPp->reset));
        vcdp->fullBit(c+1225,(vlTOPp->active));
        vcdp->fullBus(c+1233,(vlTOPp->register_v0),32);
        vcdp->fullBit(c+1241,(vlTOPp->clk_enable));
        vcdp->fullBus(c+1249,(vlTOPp->instr_address),32);
        vcdp->fullBus(c+1257,(vlTOPp->instr_readdata),32);
        vcdp->fullBus(c+1265,(vlTOPp->data_address),32);
        vcdp->fullBit(c+1273,(vlTOPp->data_write));
        vcdp->fullBit(c+1281,(vlTOPp->data_read));
        vcdp->fullBus(c+1289,(vlTOPp->data_writedata),32);
        vcdp->fullBus(c+1297,(vlTOPp->data_readdata),32);
        vcdp->fullBit(c+1305,(vlTOPp->mips_cpu_harvard__DOT__flush_decode_execute_register));
        vcdp->fullBus(c+1313,(vlTOPp->mips_cpu_harvard__DOT__write_data_execute),32);
        vcdp->fullBit(c+1321,(vlTOPp->mips_cpu_harvard__DOT__register_file_memory_mux_memory));
        vcdp->fullBit(c+1329,(vlTOPp->mips_cpu_harvard__DOT__flush_fetch_decode_register));
        vcdp->fullBit(c+1337,(1U));
        vcdp->fullBus(c+1345,(4U),32);
        vcdp->fullBus(c+1353,(0x20U),32);
        vcdp->fullBus(c+1361,(5U),32);
        vcdp->fullBus(c+1369,(0x1fU),5);
        vcdp->fullBus(c+1377,(0U),5);
    }
}
