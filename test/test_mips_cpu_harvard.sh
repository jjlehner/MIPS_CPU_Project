#!/bin/bash

mkdir -p bin/assembler0
mkdir -p test/hex0
mkdir -p test/results0
mkdir -p test/simulator0

### get file input 

SOURCEDIR = "$1"
INSTRUCTION = "$2"

if ["${INSTRUCTION}" -eq 0]
then
	touch test/results0/result0.csv
	>&2 echo "Instruction has not been specified. Proceeding with all functional tests."

	TESTS = "test/tests/*.asm.txt"
	for t in TESTS; do
		TESTCASE = "$t"
		exec 5< $t

		### first line specifies what is being tested
		read -r line <&5
		testType = "${line:1:${#line}-1}"

		### gives the expected value
		read -r line <&5
		expectedValue = "${line:1:${#line}-1}"

		### read test id
		read -r line <&5
		testId = "${line:1:${#line}-1}"
		### read additional comment
		read -r line <&5
		comment = "${line:1:${#line}-1}"

		### assemble input file
		test/assembler/bin/parser test/tests/${TESTCASE}.asm.txt test/hex0/${TESTCASE}.hex.txt

		###compile testbench
		iverilog -g 2012 \
			${SOURCEDIR}/mips_cpu.v test/mips_cpu_bus_tb_delay0.v/RAM_32x2048_delay0.v \
			-s mips_cpu_bus_tb_delay0 \
			-Pmips_cpu_bus_tb_delay0.RAM_INIT_FILE=\ "test/hex0/${TESTCASE}.hex.txt" \
			-o test/simulator0/mips_cpu_bus_tb_delay0_${TESTCASE}

		###run testbench
		set +e
		test/simulator0/mips_cpu_bus_tb_delay0_${testType} > test/results0/mips_cpu_bus_tb_delay0_${testType}.stdout
		output = $?
		set -e

		###testing for failure code
		if [[ "${output}" -ne 0 ]]; then
			echo "${testType}_${testId} "fail" ${output}" >> test/results0/result0.csv
		fi

	
		###compare output to expected
		bool = "fail"
		if [$output -eq $expectedValue]; then
			bool = "pass"
		fi

		echo "${testType}_${testId} ${bool} ${comment}" >> test/results0/result0.csv

	done



else
	touch test/results0/result0_${INSTRUCTION}.csv
	>&2 echo "Instruction has been specified. Proceeding with ${INSTRUCTION} test."
	TESTS = "test/tests/*.asm.txt"
	for t in TESTS; do
		TESTCASE = "$t"
		exec 5< $t

		### first line specifies what is being tested
		read -r line <&5
		testType = "${line:1:${#line}-1}"

		### gives the expected value
		read -r line <&5
		expectedValue = "${line:1:${#line}-1}"

		### read test id
		read -r line <&5
		testId = "${line:1:${#line}-1}"
		### read additional comment
		read -r line <&5
		comment = "${line:1:${#line}-1}"

		if [[ "${testType}" -eq "${INSTRUCTION}"]]; then
	
			### assemble input file
			test/assembler/bin/parser test/tests/${TESTCASE}.asm.txt test/hex0/${TESTCASE}.hex.txt

			###compile testbench
			iverilog -g 2012 \
				${SOURCEDIR}/mips_cpu.v test/mips_cpu_bus_tb_delay0.v/RAM_32x2048_delay0.v \
				-s mips_cpu_bus_tb_delay0 \
				-Pmips_cpu_bus_tb_delay0.RAM_INIT_FILE=\ "test/hex0/${TESTCASE}.hex.txt" \
				-o test/simulator0/mips_cpu_bus_tb_delay0_${TESTCASE}

			###run testbench
			set +e
			test/simulator0/mips_cpu_bus_tb_delay0_${testType} > test/results0/mips_cpu_bus_tb_delay0_${testType}.stdout
			output = $?
			set -e

			###testing for failure code
			if [[ "${output}" -ne 0 ]]; then
				echo "${testType}_${testId} "fail" ${output}" >> test/results0/result0_${INSTRUCTION}.csv
			fi

		
			###compare output to expected
			bool = "fail"
			if [$output -eq $expectedValue]; then
				bool = "pass"
			fi

			echo "${testType}_${testId} ${bool} ${comment}" >> test/results0/result0_${INSTRUCTION}.csv
		fi

	done

fi


