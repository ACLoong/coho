#include <iostream>
#include <memory>

#include "utility/args.h"

int main (int argc, char *argv[]) {
    std::cout << "hello world" << std::endl;

    yd::Args args;
    args.addCommandHandler("start", []() {std::cout << "starting..." <<std::endl;});
    args.parseAndRun(argc, argv);

    return 0;
}