#!/bin/bash
set -e
cd "$(dirname "$0")"
cd ../unofficial/iverilog_testing/programs/
### get file input 
lower_level=(
	"../../../rtl/Adder.v"
	"../../../rtl/ALU_Input_Mux.v"
	"../../../rtl/ALU.v"
	"../../../rtl/Control_Unit.v"
	"../../../rtl/Comparator.v"
	"../../../rtl/Hazard_Unit.v"
	"../../../rtl/MUX_2INPUT.v"
	"../../../rtl/MUX_4INPUT.v"
	"../../../rtl/Program_Counter.v"
	"../../../rtl/Register_File.v"
	"../../../rtl/Memory_Filter.v"
	"../../../rtl/pipeline_registers_bus/Decode_Execute_Register.v"
	"../../../rtl/pipeline_registers_bus/Execute_Memory_Register.v"
	"../../../rtl/pipeline_registers_bus/Fetch_Decode_Register.v"
	"../../../rtl/pipeline_registers_bus/Memory_Writeback_Register.v"
)

programs_to_run=(
	"ram_access"
)

g++ stage2_assembler.cpp -o stage2_assembler

#verilator -Wall ../../../rtl/mips_cpu_bus.v ${lower_level[@]} --lint-only

for i in "${programs_to_run[@]}"
do
	mkdir -p output/$i
	echo "----------------------------------------------------------"
	program="${i}_clean.hex"
	echo "compiling and running" ${i}.txt
	./stage2_assembler ${i} >output/$i/${program}
	echo program
	echo "COMPILING VERILOG"
   iverilog -Wall -g 2012 ../../../rtl/mips_cpu_bus.v ../mips_cpu_bus_tb_delay1.v ../RAM_32x2048_delay1.v ${lower_level[@]} -s mips_cpu_bus_tb_delay1 -Pmips_cpu_bus_tb_delay1.VCD_FILE=\"output/$i/$i.vcd\" -Pmips_cpu_bus_tb_delay1.RAM_INIT_FILE=\"output/$i/${program}\" -o output/$i/$i.exe  &>output/$i/${i}_vcompilation_output.txt
	echo "SUCCESFULY COMPILED VERILOG"
	echo "\n \n \n----------------------------------------------------------\n\n\n"
	set +e
	output/$i/$i.exe > output/$i/$i.output
	set -e
done

rm stage2_assembler
gtkwave output/${programs_to_run[0]}/${programs_to_run[0]}.vcd
