#!/bin/bash
set -e
cd "$(dirname "$0")"
cd ../src
while getopts bcl flag
do
    case "${flag}" in
        b) verilator -Wall --trace +1800-2012ext+.v -cc mips_cpu.v *[^mips_cpu].v pipeline_registers/*.v --prefix MIPS_Harvard_TB --Mdir ../unofficial/preliminary_testing/MIPS_Harvard_obj_dir;
			exit 0 ;;
        c) verilator -Wall --trace +1800-2012ext+.v -cc mips_cpu.v *[^mips_cpu].v pipeline_registers/*.v --prefix MIPS_Harvard_TB --Mdir ../unofficial/preliminary_testing/MIPS_Harvard_obj_dir --exe ./unofficial/preliminary_testing/mips_v0.cpp -CFLAGS "-std=c++11";
            exit 0 ;;
        l) verilator -Wall +1800-2012ext+.v -cc mips_cpu.v *[^mips_cpu].v pipeline_registers/*.v --lint-only --top-module mips_cpu;
			exit 0 ;;
    esac
done

echo "No flag passed options are -b for build -l for lint"
exit 1