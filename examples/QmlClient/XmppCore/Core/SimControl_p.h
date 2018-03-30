#ifndef SIMCONTROL_P_H
#define SIMCONTROL_P_H

#include "SimControl.h"

class SimControlPrivate
{
    Q_DECLARE_PUBLIC(SimControl)

public:
    SimControlPrivate();
    virtual ~SimControlPrivate();
protected:
    SimControl *q_ptr;
};

#endif // SIMCONTROL_P_H
