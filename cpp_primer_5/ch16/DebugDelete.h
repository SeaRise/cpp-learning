#ifndef CPP_LEARNING_DEBUGDELETE_H
#define CPP_LEARNING_DEBUGDELETE_H

#include "iostream"

class DebugDelete {
public:
    explicit DebugDelete(std::ostream &o = std::cerr): os(o) {}
    template<typename T> void operator()(T *p) const {
        os << "deleting unique_ptr" << std::endl;
        delete p;
    }
private:
    std::ostream &os;
};

#endif //CPP_LEARNING_DEBUGDELETE_H
