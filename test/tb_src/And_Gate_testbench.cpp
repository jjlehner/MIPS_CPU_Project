#include <iostream>

#include "And_Gate.h"

using namespace std;

/*
  TestBench to test 'And_Gate.v' which contains the 'And_Gate' module
    logic inputs: 'branch_d' and 'equal_id'
    logic output: 'PC_src_D'
  Since there are only 4 possible combinations - an exhaustive method is used
  and iterates through all combinations checking for correctness
*/

int main(int argc, char **argv, char **env){
  Verilated::commandArgs(argc, argv);
  And_Gate* and_gate_module = new And_Gate;

  for(int i = 0; i <= 1; i++){
    for(int j = 0; j <= 1; j++){
      and_gate_module->branch_d = (bool)i;
      and_gate_module->equal_id = (bool)j;
      and_gate_module->eval();

      if(and_gate_module->PC_src_D != ((bool)i & (bool)j)){
        cout << "And_Gate TestBench FAILED! Operation: " << (bool)i << " & " << (bool)j << " Got: " << and_gate_module->PC_src_D << " Expected: " << ((bool)i & (bool)j) << endl;
        return 1;
      }
    }
  }

  cout << "And_Gate TestBench PASSED!" << endl;
  and_gate_module->final();
  delete and_gate_module;
  return 0;
}
