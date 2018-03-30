#ifndef SIMBACKEND_P_H
#define SIMBACKEND_P_H

#include "SimBackend.h"

class SimBackendPrivate
{
    Q_DECLARE_PUBLIC(SimBackend)

public:
    SimBackendPrivate();
    virtual ~SimBackendPrivate();
protected:
    SimBackend *q_ptr;
};

#endif // SIMBACKEND_P_H
