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

int main(int argc, const char * argv[]) {
    // insert code here...
    // VirtualMachine vm;
    auto vm = VirtualMachine{};
    vm.bDebugMode = true;

    std::stringstream ss;
    
    ss << "\x12\x0a\xff\x20\xfa";
    
    vm.LoadOpCode(ss);
    
    for(;;)
    {
        auto ret = vm.Execute();
        if (ret.bTerminated)
            break;
    }
    
    return 0;
}
