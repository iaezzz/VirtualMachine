//
//  fvmcmdtest.cpp
//
//  Created by Fantom Foundation
//  Copyright © 2018 Fantom Foundation. All rights reserved.
//


#include <iostream>
#include <vector>
#include <sstream>
#include "VirtualMachine.hpp"

using std::string_literals::operator""s;

int main(int argc, const char * argv[]) {
    // insert code here...
    // VirtualMachine vm;
    auto vm = VirtualMachine{};
    vm.bDebugMode = true;

    std::stringstream ss;
    
    //ss << "\x12\x0a\xff\x20\xfa";
    ss <<  "\x12\x0a\xff\x00\x00\x00\x00\x27\xff\x02\x80\xfe\xff\x0e\x10\x45\x21\x1e\x0a\x21\xff\x02\x20\xa4\x41\x37\x09\x83\xff\xfe\xf0\x23\x12\x0a\x7c\x11\xff\xfe\x88\x0d\x09\xbc\x74\x00\x00\x0f\x00\x00\x47\x0d\x15\x8a\x0d\x09\xbc\x74\x4d\x0d\x17\x86\x0d\x09\xbc\x74\x84\x0d\x09\xbc\x74\x15\xff\xff\x86\xff\xfb\xe7\xdc\xff\xcc\x27\xfe\x0a\x20\x9c\x20\xcd\x82\xd9\xbc\x74\x83\x04\xff\xff\x87"s;
    
    vm.LoadOpCode(ss);
    
    for(;;)
    {
        auto ret = vm.Execute();
        if (ret.bTerminated)
            break;
    }
    
    return 0;
}
