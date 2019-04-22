//
// Created by daniil on 22.04.19.
//

#include "worker.h"
#include <sys/mman.h>
#include <iostream>
#include <cstring>

void print_error(const std::string &message) {
    std::cerr << message << strerror(errno) << std::endl;
}


Worker::Worker(const unsigned char *code, size_t code_size, size_t modify, int &return_code) {
    func_size = code_size;
    func_ptr = mmap(nullptr, func_size, PROT_WRITE | PROT_READ, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
    this->modify = modify;
    if (func_ptr == MAP_FAILED) {
        print_error("Can't allocate memory: ");
        return_code = -1;
        return;
    }
    std::memcpy(func_ptr, code, func_size);
    return_code = 0;
}

void Worker::execute() {
    if (mprotect(func_ptr, func_size, PROT_READ | PROT_EXEC) == -1) {
        print_error("Can't change privileges: ");
        return;
    }
    std::cout << ((int (*)()) func_ptr)() << std::endl;
}

void Worker::modify_const(int a) {
    if (mprotect(func_ptr, func_size, PROT_READ | PROT_WRITE) == -1) {
        print_error("Can't change privileges: ");
        return;
    }
    for (int i = 0; i < 4; i++) {
        ((unsigned char *) func_ptr)[modify + i] = static_cast<unsigned char>(a % 256);
        a /= 256;
    }
    std::cout << "Modification done" << std::endl;
}

Worker::~Worker() {
    if (munmap(func_ptr, func_size) == -1) {
        print_error("Can't free memory: ");
    }
}
