#!/bin/bash

cd "$(dirname "$0")"
cd ../src
verilator -Wall +1800-2012ext+.v -cc mips_cpu.v *[^mips_cpu].v pipeline_registers/*.v --lint-only --top-module mips_cpu

#verilator -Wall +1800-2012ext+.v -cc mips_cpu.v *[^mips_cpu].v pipeline_registers/*.v --prefix MIPS_Harvard_TB --Mdir ../test/MIPS_Harvard_obj_dir
