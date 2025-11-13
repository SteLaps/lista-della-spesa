#ifndef LISTA_DELLA_SPESA_SUBJECT_H
#define LISTA_DELLA_SPESA_SUBJECT_H

#include "Observer.h"

class Subject {
public:
    virtual ~Subject() = default;
    virtual void notify() = 0;
    virtual void attach(Observer* o) = 0;
    virtual void detach(Observer* o) = 0;
};

#endif //LISTA_DELLA_SPESA_SUBJECT_H
