//
// Created by WangQing on 31/01/2018.
//

#include "args.h"

namespace yd {

    void Args::addCommandHandler(const std::string &command, const std::function<void()> &handler) {
        _handlers.insert(std::make_pair(command, handler));
    }

    void Args::parseAndRun(int argc, char **argv) {
        if (argc <= 1) {

            if (nullptr != _errorHandler) {
                _errorHandler("Count of command arguments is too few.");
            }
        }

        if (argc > 2) {
            if (nullptr != _errorHandler) {
                _errorHandler("Count of command arguments is too many.");
            }
        }

        auto &func = _handlers.at(std::string(argv[1]));
        if (nullptr != func) {
            func();
        }
    }

    void Args::addErrorHandler(const std::function<void(const std::string &err) > &handler) {
        _errorHandler = handler;
    }
}


