//
// Created by WangQing on 31/01/2018.
//

#include "args.h"

namespace yd {

    void Args::addCommandHandler(const std::string &command, const std::function<void()> &handler) {
        _handlers.insert(std::make_pair(command, handler));
    }

    void Args::parseAndRun(int argc, char **argv) {
        //TODO
    }
}