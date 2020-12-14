#!/bin/bash

mkdir -p test/bin1
mkdir -p test/bin1/r_type
mkdir -p test/bin1/i_type
mkdir -p test/bin1/j_type
mkdir -p test/tmp1
mkdir -p test/tmp1/r_type
mkdir -p test/tmp1/i_type
mkdir -p test/tmp1/j_type
mkdir -p test/hex1
mkdir -p test/hex1/r_type
mkdir -p test/hex1/i_type
mkdir -p test/hex1/j_type
mkdir -p test/results1
mkdir -p test/simulator1

### get file input 

SOURCEDIR="$1"
INSTRUCTION="$2"
lower_level=(
	"${SOURCEDIR}/Adder.v"
	"${SOURCEDIR}/ALU_Input_Mux.v"
	"${SOURCEDIR}/ALU.v"
	"${SOURCEDIR}/And_Gate.v"
	"${SOURCEDIR}/Control_Unit.v"
	"${SOURCEDIR}/Comparator.v"
	"${SOURCEDIR}/Hazard_Unit.v"
	"${SOURCEDIR}/Left_Shift.v"
	"${SOURCEDIR}/MUX_2INPUT.v"
	"${SOURCEDIR}/MUX_4INPUT.v"
	"${SOURCEDIR}/Program_Counter.v"
	"${SOURCEDIR}/Register_File.v"
	"${SOURCEDIR}/Sign_Extension.v"
	"${SOURCEDIR}/Or_Gate.v"
	"${SOURCEDIR}/pipeline_registers/Decode_Execute_Register.v"
	"${SOURCEDIR}/pipeline_registers/Execute_Memory_Register.v"
	"${SOURCEDIR}/pipeline_registers/Fetch_Decode_Register.v"
	"${SOURCEDIR}/pipeline_registers/Memory_Writeback_Register.v"
)

if [ -z "$INSTRUCTION" ]; then
	touch test/results1/result1.csv
	>&2 echo "Instruction has not been specified. Proceeding with all functional tests."
	for type in r i j ; do
		TESTS="test/tests/${type}_type/*.s"

		>&2 echo "Commencing ${type} type instruction tests."	
		echo "${type} tests:" >> test/results1/result1.csv

		for t in $TESTS; do
			TESTCASE="$t"
			basename "$TESTCASE"
			hexname="$(basename -- $TESTCASE)"
			hexed="${hexname%.*.*}"
			exec 5< $t	

			### first line specifies what is being tested
			read -r line <&5
			testType="${line:1:${#line}-1}"

			### gives the expected value
			read -r line <&5
			expectedValue="${line:1:${#line}-1}"

			### read test id
			read -r line <&5
			testId="${line:1:${#line}-1}"

			### read additional comment
			read -r line <&5
			comment="${line:1:${#line}-1}"

			### assemble input file
			mipsel-linux-gnu-gcc -c -O3 test/tests/${type}_type/$hexed.s -o test/tmp1/${type}_type/$hexed.o
				
			mipsel-linux-gnu-objcopy -O binary --only-section=.text test/tmp1/${type}_type/$hexed.o test/bin1/${type}_type/$hexed.bin
				
			hexdump test/bin1/${type}_type/$hexed.bin > test/hex1/${type}_type/$hexed.hex.txt

			###compile testbench
			iverilog -g 2012 \
				${SOURCEDIR}/mips_cpu_bus.v test/mips_cpu_bus_tb_delay1.v test/RAM_32x2048_delay1.v ${lower_level[@]} -s mips_cpu_bus_tb_delay1 -Pmips_cpu_bus_tb_delay1.RAM_INIT_FILE=\"test/hex1/${type}_type/$hexed.hex.txt\" -o test/simulator1/mips_cpu_bus_tb_delay1_$hexed


			###run testbench
			set +e
			test/simulator1/mips_cpu_bus_tb_delay1_$hexed > test/results1/mips_cpu_bus_tb_delay1_$hexed.stdout
			output=$?
			set -e

			echo "fix check $output $expectedValue "

			###testing for failure code
			if [[ "${output}" -ne 0 ]]; then
				echo "${testType}_${testId} "fail" ${output}" >> test/results1/result1.csv
			fi

		
			###compare output to expected
			bool="fail"
			if [ $output -eq $expectedValue ]; then
				bool="pass"
			fi

			echo "${testType}_${testId} ${bool} ${comment}" >> test/results1/result1.csv

		done
	done


else
	for type in r i j ; do
		TESTS="test/tests/${type}_type/*.s"
		touch test/results1/result1_${INSTRUCTION}.csv
		>&2 echo "Instruction has been specified. Proceeding with ${INSTRUCTION} test."

		for t in $TESTS; do
			TESTCASE="$t"
			basename "$TESTCASE"
			hexname="$(basename -- $TESTCASE)"
			hexed="${hexname%.*}"
			exec 5< $t

			### first line specifies what is being tested
			read -r line <&5
			testType="${line:1:${#line}-1}"

			### gives the expected value
			read -r line <&5
			expectedValue="${line:1:${#line}-1}"

			### read test id
			read -r line <&5
			testId="${line:1:${#line}-1}"

			### read additional comment
			read -r line <&5
			comment="${line:1:${#line}-1}"

			if [ "$testType" == "$INSTRUCTION" ]; then
		
				### assemble input file
				mipsel-linux-gnu-gcc -c test/tests/${type}_type/$hexed.s -o test/tmp1/${type}_type/$hexed.o
				
				mipsel-linux-gnu-objcopy -O binary --only-section=.text test/tmp1/${type}_type/$hexed.o test/bin1/${type}_type/$hexed.bin
				
				hexdump test/bin1/${type}_type/$hexed.bin > test/hex1/${type}_type/$hexed.hex.txt
				

				###compile testbench
				iverilog -g 2012 \
					${SOURCEDIR}/mips_cpu_bus.v test/mips_cpu_bus_tb_delay1.v test/RAM_32x2048_delay1.v ${lower_level[@]} -s mips_cpu_bus_tb_delay1 -Pmips_cpu_bus_tb_delay1.RAM_INIT_FILE=\"test/hex1/${type}_type/$hexed.hex.txt\" -o test/simulator1/mips_cpu_bus_tb_delay1_$hexed

				###run testbench
				set +e
				test/simulator1/mips_cpu_bus_tb_delay1_$hexed > test/results1/mips_cpu_bus_tb_delay1_$hexed.stdout
				output=$?
				echo "out $output"
				echo "exp $expectedValue"
				set -e

				###testing for failure code
				if [[ "${output}" -ne 0 ]]; then
					echo "${testType}_${testId} "fail" ${output}" >> test/results1/result1_${INSTRUCTION}.csv
				fi

			
				###compare output to expected
				bool="fail"
				if [ $output -eq $expectedValue ]; then
					bool="pass"
				fi

				echo "${testType}_${testId} ${bool} ${comment}" >> test/results1/result1_${INSTRUCTION}.csv
			fi

		done
	done

fi


