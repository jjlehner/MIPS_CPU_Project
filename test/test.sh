#!/bin/bash

mkdir -p bin/assembler
mkdir -p test/hex
mkdir -p test/results
mkdir -p test/simulator
touch test/results/result.csv
### get file input 
### DEPENDS ON TESTBENCH.V NEED TO FIX

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
	bin/assembler <test/tests/${TESTCASE}.asm.txt > test/hex/${TESTCASE}.hex.txt

###compile testbench
	iverilog -g 2012 \
		src/mips_cpu.v test/mips_cpu_bus_tb_delay1.v/RAM_32x2048_delay1.v \
		-s mips_cpu_bus_tb_delay1 \
		-Pmips_cpu_bus_tb_delay1.RAM_INIT_FILE=\ "test/hex/${testType}.hex.txt" \
		-o test/simulator/mips_cpu_bus_tb_delay1_${testType}

###run testbench
	set +e
	test/simulator/mips_cpu_bus_tb_delay1_${testType} > test/results/mips_cpu_bus_tb_delay1_${testType}.stdout
	output = $?
	set -e

###compare output to expected
	bool = "fail"
	if [$output -eq $expectedValue]; then
		bool = "pass"
	fi

	echo "$testType, $expectedValue, $output" >> test/results/result.csv

done
