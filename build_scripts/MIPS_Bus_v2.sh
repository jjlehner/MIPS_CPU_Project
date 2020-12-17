#!/bin/bash
set -e
cd "$(dirname "$0")"
cd ../unofficial/iverilog_testing/programs/
### get file input 
lower_level=(
	"../../../rtl/Adder.v"
	"../../../rtl/ALU_Input_Mux.v"
	"../../../rtl/ALU.v"
	"../../../rtl/And_Gate.v"
	"../../../rtl/Control_Unit.v"
	"../../../rtl/Comparator.v"
	"../../../rtl/Hazard_Unit.v"
	"../../../rtl/Left_Shift.v"
	"../../../rtl/MUX_2INPUT.v"
	"../../../rtl/MUX_4INPUT.v"
	"../../../rtl/Program_Counter.v"
	"../../../rtl/Register_File.v"
	"../../../rtl/Sign_Extension.v"
	"../../../rtl/Or_Gate.v"
	"../../../rtl/Memory_Filter.v"
	"../../../rtl/pipeline_registers_bus/Decode_Execute_Register.v"
	"../../../rtl/pipeline_registers_bus/Execute_Memory_Register.v"
	"../../../rtl/pipeline_registers_bus/Fetch_Decode_Register.v"
	"../../../rtl/pipeline_registers_bus/Memory_Writeback_Register.v"
)

programs_to_run=(
	"branch_test_ALU"
)

g++ stage2_assembler.cpp -o stage2_assembler
for i in "${programs_to_run[@]}"
do
	mkdir -p output/$i
	echo "----------------------------------------------------------"
	program="${i}_clean.hex"
	echo "compiling and running" ${i}.txt
	./stage2_assembler ${i} >output/$i/${program}
	echo program
   iverilog -g 2012 ../../../rtl/mips_cpu_bus.v ../mips_cpu_bus_tb_delay1.v ../RAM_32x2048_delay1.v ${lower_level[@]} -s mips_cpu_bus_tb_delay1 -Pmips_cpu_bus_tb_delay1.VCD_FILE=\"output/$i/$i.vcd\" -Pmips_cpu_bus_tb_delay1.RAM_INIT_FILE=\"output/$i/${program}\" -o output/$i/$i.exe  &>output/$i/${i}_vcompilation_output.txt

	echo "\n \n \n----------------------------------------------------------\n\n\n"
	set +e
	output/$i/$i.exe > output/$i/$i.output
	set -e
done

rm stage2_assembler
gtkwave output/${programs_to_run[0]}/branch_test_ALU.vcd
