#ifndef SIMBACKENDADAPTER_P_H
#define SIMBACKENDADAPTER_P_H

#include "SimControl_p.h"
#include "SimBackendAdapter.h"

class SimBackendAdapterPrivate : public SimControlPrivate
{
    Q_DECLARE_PUBLIC(SimBackendAdapter)

public:
    SimBackendAdapterPrivate();
    virtual ~SimBackendAdapterPrivate();
protected:
    SimBackend *backend;
};

#endif // SIMBACKENDADAPTER_P_H
