//
// Created by daniil on 22.04.19.
//

#include "worker.h"
#include "function.h"

int main() {
    int return_code;
    Worker worker = Worker(function::code, function::code_size, function::modify, return_code);
    if (return_code == -1) {
        std::cout << "exiting...\n";
        return 0;
    }
    function::print_info();
    while (true) {
        std::string s;
        std::cin >> s;
        if (s == "exit") {
            break;
        } else if (s == "execute") {
            worker.execute();
        } else if (s == "change") {
            int a;
            std::cin >> a;
            worker.modify_const(a);
        } else {
            std::cerr << "Illegal command: wrong name" << std::endl;
        }
    }
    return 0;
}