#ifndef SIMCONTACTSADAPTER_P_H
#define SIMCONTACTSADAPTER_P_H

#include "Core/SimBackendAdapter_p.h"
#include "SimContactsAdapter.h"

#include "Models/SimContactsModel.h"

class SimContactsAdapterPrivate : public SimBackendAdapterPrivate
{
    Q_DECLARE_PUBLIC(SimContactsAdapter)

public:
    SimContactsAdapterPrivate();
    virtual ~SimContactsAdapterPrivate();
protected:
    SimContactsModel *model;
};

#endif // SIMCONTACTSADAPTER_P_H
