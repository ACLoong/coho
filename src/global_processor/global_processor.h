#ifndef COHO_GLOBAL_PROCESSOR_H
#define COHO_GLOBAL_PROCESSOR_H

#include "handy/handy.h"

namespace coho {

class GlobalProcessor {
public:
    GlobalProcessor(handy::EventBases *event_base) : event_base_(event_base) {}

private:
    handy::EventBases *event_base_;

};

} // namespace coho

#endif //COHO_GLOBAL_PROCESSOR_H
