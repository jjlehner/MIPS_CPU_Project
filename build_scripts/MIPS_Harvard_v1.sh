#!/bin/bash
set -e
cd "$(dirname "$0")"
cd ../src

top_level=("../../src/mips_cpu.v")
lower_level=(
    "../../src/Adder.v"
    "../../src/ALU.v"
    "../../src/And_Gate.v"
    "../../src/Control_Unit.v"
    "../../src/Equal_Comparator.v"
    "../../src/Hazard_Unit.v"
    "../../src/Left_Shift.v"
    "../../src/MUX_2INPUT.v"
    "../../src/MUX_4INPUT.v"
    "../../src/Program_Counter.v"
    "../../src/Register_File.v"
    "../../src/Sign_Extension.v"
    "../../src/pipeline_registers/Decode_Execute_Register.v"
    "../../src/pipeline_registers/Execute_Memory_Register.v"
    "../../src/pipeline_registers/Fetch_Decode_Register.v"
    "../../src/pipeline_registers/Memory_Writeback_Register.v"
)
while getopts gcl flag
do
    case "${flag}" in
        g) cd ../unofficial/preliminary_testing;
            verilator -Wall --trace +1800-2012ext+.v --debug -cc  $top_level ${lower_level[@]} --prefix MIPS_Harvard_TB --Mdir MIPS_Harvard_obj_dir;
            echo "generating c++ code"
            
            exit 0 ;;
        c)  cd ../unofficial/preliminary_testing;
            verilator -Wall --trace +1800-2012ext+.v --debug -cc  $top_level ${lower_level[@]} --prefix MIPS_Harvard_TB --Mdir MIPS_Harvard_obj_dir --exe mips_v0.cpp -CFLAGS "-std=c++17 -g";
            echo "compiling"
            
            cd MIPS_Harvard_obj_dir;
            make -j4 -f MIPS_Harvard_TB.mk MIPS_Harvard_TB;
            
            ./MIPS_Harvard_TB;
            gtkwave trace.vcd;
            exit 0 ;;
        l) cd ../unofficial/preliminary_testing;
            echo "linting";
            verilator -Wall --trace +1800-2012ext+.v $top_level ${lower_level[@]} --lint-only;
            
            exit 0 ;;
    esac
done
echo "No flag passed options are:"
echo "  (-g to generate c++ headers from verilog)"
echo "  (-l for lint)"
echo "  (-c for compile and run)"
exit 1