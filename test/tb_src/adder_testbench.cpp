#include <iostream>

#include "Adder.h"

using namespace std;

/*
  Testbench to test 'Adder.v' which contains the 'Adder' module.
    32 bit inputs: 'a' and 'b'
    32 bit output: 'z'
  Works in 2's complement so the range should be:
    [-2,147,483,648 : 2,147,483,647]
  Variables are set to be int32_t which are signed 32 bit intergers - overflow
  is handled automatically.
  Adder Output 'z' cast to the same type for clarity when debugging
  but not strictly necessary.
*/

int main(int argc, char **argv, char **env){
  Verilated::commandArgs(argc, argv);
  Adder* add_module = new Adder;

  int32_t i = 0;
  int32_t j = 0;

  add_module->a = i;
  add_module->b = j;
  add_module->eval();

  //441 additions
  for(i = -10; i <= 10; i++){
    for(j = -10; j <= 10; j++){
      add_module->a = i;
      add_module->b = j;
      add_module->eval();

      if((int32_t)add_module->z == (i + j)){
        // cout << "Operands: " << i << ", " << j << " Expected: " << i+j << " Got:" << (int32_t)add_module->z << endl;
          continue;
      }else{
        cout << "Adder TestBench FAILED! Operation: " << i << " + " << j << " Got: " << (int32_t)add_module->z << "; Expected: " << i+j << endl;
        return 1;
      }
    }
  }

  cout << "Adder TestBench PASSED!" << endl;
  add_module->final();
  delete add_module;
  return 0;
}
