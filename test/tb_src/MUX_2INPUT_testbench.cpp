#include <iostream>

#include "MUX_2INPUT.h"

using namespace std;

int main(int argc, char **argv, char **env){
  Verilated::commandArgs(argc, argv);
  MUX_2INPUT* mux_module = new MUX_2INPUT;

  mux_module->input_0 = 0;
  mux_module->input_1 = 1;
  mux_module->control = 0;
  mux_module->eval();

  if(mux_module->resolved == 1){
    cout << "MUX_2INPUT Testbench FAILED! Got: " << (bool)mux_module->resolved << "; Expected: 0; Control: 0" << endl;
  }

  mux_module->control = 1;
  mux_module->eval();

  if(mux_module->resolved == 0){
    cout << "MUX_2INPUT Testbench FAILED! Got: " << (bool)mux_module->resolved << "; Expected: 1; Control: 1" << endl;
  }

  cout << "MUX_2INPUT Testbench PASSED!" << endl;
}
