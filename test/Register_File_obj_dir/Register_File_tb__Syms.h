// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header,
// unless using verilator public meta comments.

#ifndef _REGISTER_FILE_TB__SYMS_H_
#define _REGISTER_FILE_TB__SYMS_H_  // guard

#include "verilated.h"

// INCLUDE MODULE CLASSES
#include "Register_File_tb.h"

// SYMS CLASS
class Register_File_tb__Syms : public VerilatedSyms {
  public:
    
    // LOCAL STATE
    const char* __Vm_namep;
    bool __Vm_didInit;
    
    // SUBCELL STATE
    Register_File_tb*              TOPp;
    
    // CREATORS
    Register_File_tb__Syms(Register_File_tb* topp, const char* namep);
    ~Register_File_tb__Syms() {}
    
    // METHODS
    inline const char* name() { return __Vm_namep; }
    
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

#endif  // guard
