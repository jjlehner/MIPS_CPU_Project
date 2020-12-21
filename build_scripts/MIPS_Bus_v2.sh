#!/bin/bash
set -e
cd "$(dirname "$0")"
cd ../unofficial/iverilog_testing/programs/
### get file input 
lower_level=(
	"../../../rtl/mips_cpu/Adder.v"
	"../../../rtl/mips_cpu/ALU_Input_Mux.v"
	"../../../rtl/mips_cpu/ALU.v"
	"../../../rtl/mips_cpu/Control_Unit.v"
	"../../../rtl/mips_cpu/Comparator.v"
	"../../../rtl/mips_cpu/Hazard_Unit.v"
	"../../../rtl/mips_cpu/MUX_2INPUT.v"
	"../../../rtl/mips_cpu/MUX_4INPUT.v"
	"../../../rtl/mips_cpu/Program_Counter.v"
	"../../../rtl/mips_cpu/Register_File.v"
	"../../../rtl/mips_cpu/Memory_Filter.v"
	"../../../rtl/mips_cpu/Decode_Execute_Register.v"
	"../../../rtl/mips_cpu/Execute_Memory_Register.v"
	"../../../rtl/mips_cpu/Fetch_Decode_Register.v"
	"../../../rtl/mips_cpu/Memory_Writeback_Register.v"
	"../../../rtl/mips_cpu/Multiplier.v"
	"../../../rtl/mips_cpu/Divider.v"
	"../../../rtl/mips_cpu/Unsigned_Multiplier.v"
)

programs_to_run=(
	"divider"
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
   iverilog -Wall -g 2012 ../../../rtl/mips_cpu_bus.v ../mips_cpu_bus_tb_delay1.v ../RAM_32x2048_delay1.v ${lower_level[@]} -s mips_cpu_bus_tb_delay1 -Pmips_cpu_bus_tb_delay1.VCD_FILE=\"output/$i/$i.vcd\" -Pmips_cpu_bus_tb_delay1.RAM_INIT_FILE=\"output/$i/${program}\" -o output/$i/$i.exe
	echo "SUCCESSFULLY COMPILED VERILOG"
	echo "----------------------------------------------------------"
	set +e
	output/$i/$i.exe > output/$i/$i.output
	set -e
done

rm stage2_assembler
gtkwave output/${programs_to_run[0]}/${programs_to_run[0]}.vcd
