//
// Created by daniil on 22.04.19.
//

#ifndef OS_JIT_WORKER_H
#define OS_JIT_WORKER_H


#include <cstdio>

class Worker {
    void *func_ptr = nullptr;
    size_t func_size;
    size_t modify;
public:
    Worker(const unsigned char code[], size_t code_size, size_t modify, int &return_code);

    void execute();

    void modify_const(int a);

    ~Worker();
};


#endif //OS_JIT_WORKER_H
