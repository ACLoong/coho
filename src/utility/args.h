//
// Created by WangQing on 31/01/2018.
//

#ifndef YUANDAO_ARGS_H
#define YUANDAO_ARGS_H

#include <functional>
#include <string>
#include <map>

namespace yd {

    class Args {
    public:
        //Args(int argc = 0, char **argv = nullptr): _argc(argc), _argv(argv) {}
        Args() {}

        void addCommandHandler(const std::string &command, const std::function<void ()> &handler);
        void parseAndRun(int argc, char **argv);

    private:
        int                                             _argc;
        char                                            **_argv;

        std::map<std::string, std::function<void ()>>   _handlers;
    };

}
#endif //YUANDAO_ARGS_H
