#include <iostream>

#include "handy/handy.h"
#include "global_processor.h"

int main(int argc, char *argv[]) {
    std::cout << "Hello this is global_processor." << std::endl;

    handy::EventBase event_base;
    handy::Signal::signal(SIGINT, [&]{
        event_base.exit();
    });

    coho::GlobalProcessor global_processor(&event_base);

    event_base.loop();

    return 0;
}
