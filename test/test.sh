#!/bin/bash

mkdir -p test/results
tocuh test/results/result.csv

### get file input 
### DEPENDS ON TESTBENCH.V NEED TO FIX

TESTS = "test/tests/*.s"
for t in TESTS; do

	exec 2< $t

### first line specifies what is being tested
	read -r line <&2
	testType = "${line:1:${#line}-1}"

### gives the expected value
	read -r line <&2
	expectedValue = "${line:1:${#line}-1}"

###execute tests here
### DEPENDS ON TESTBENCH.V NEED TO FIX
	output = $?
	
###compare output to expected
	bool = "fail"
	if [$output -eq $expectedValue]; then
		bool = "pass"
	fi
	
	echo "$testType, $expectedValue, $output" >> test/results/result.csv

done
