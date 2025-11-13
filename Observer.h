#ifndef LISTA_DELLA_SPESA_OBSERVER_H
#define LISTA_DELLA_SPESA_OBSERVER_H

#include <string>

class Observer {
public:
    virtual ~Observer() = default;
    virtual void update(const std::string& nome) = 0;
};

#endif //LISTA_DELLA_SPESA_OBSERVER_H
