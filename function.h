//
// Created by daniil on 22.04.19.
//

#ifndef OS_JIT_FUNCTION_H
#define OS_JIT_FUNCTION_H

#include <cstdio>
#include <string>
#include <iostream>
#include <cstring>

namespace function {

    void print_info() {
        std::cout << "Info: \n" <<
                  " This function returns a%2, where a = 1\n" <<
                  " If you want to change 'a' with value p(p must int value), type: 'change p'\n" <<
                  " If you want to execute function type: 'execute'\n" <<
                  " If you want to exit type: 'exit'\n";
    }


    int function() {
        volatile const int a = 1;
        return a % 2;
    }

    const unsigned char code[] = {0x55, 0x48, 0x89, 0xe5, 0xc7, 0x45, 0xfc,
                                  0x01, 0x00, 0x00, 0x00, //const a
                                  0x8b, 0x45, 0xfc, 0x99, 0xc1, 0xea, 0x1f, 0x01, 0xd0, 0x83, 0xe0, 0x01, 0x29, 0xd0,
                                  0x5d, 0xc3};

    const size_t modify = 7;
    const size_t code_size = sizeof(code);
}
#endif //OS_JIT_FUNCTION_H
