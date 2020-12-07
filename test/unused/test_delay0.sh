#!/bin/bash

mkdir -p bin/assembler0
mkdir -p test/hex0
mkdir -p test/results0
mkdir -p test/simulator0
touch test/results0/result0.csv
### get file input 

TESTS = "test/tests/*.s"
for t in TESTS; do
	TESTCASE = "$t"
	exec 2< $t

### first line specifies what is being tested
	read -r line <&2
	testType = "${line:1:${#line}-1}"

### gives the expected value
	read -r line <&2
	expectedValue = "${line:1:${#line}-1}"


### assemble input file
	bin/assembler <test/tests/${TESTCASE}.asm.txt > test/hex0/${TESTCASE}.hex.txt

###compile testbench
	iverilog -g 2012 \
		src/mips_cpu.v test/mips_cpu_bus_tb_delay0.v/RAM_32x2048_delay0.v \
		-s mips_cpu_bus_tb_delay0 \
		-Pmips_cpu_bus_tb_delay0.RAM_INIT_FILE=\ "test/hex0/${testType}.hex.txt" \
		-o test/simulator0/mips_cpu_bus_tb_delay0_${testType}

###run testbench
	set +e
	test/simulator0/mips_cpu_bus_tb_delay0_${testType} > test/results0/mips_cpu_bus_tb_delay0_${testType}.stdout
	output = $?
	set -e

###compare output to expected
	bool = "fail"
	if [$output -eq $expectedValue]; then
		bool = "pass"
	fi

	echo "$testType, $expectedValue, $output" >> test/results0/result0.csv

done
