#ifndef SIMBACKENDADAPTER_H
#define SIMBACKENDADAPTER_H

#include "SimBackend.h"
#include "SimControl.h"

class SimBackendAdapterPrivate;
class SimBackendAdapter : public SimControl
{
    Q_OBJECT
    Q_DECLARE_PRIVATE(SimBackendAdapter)

protected:
    SimBackendAdapter(SimBackendAdapterPrivate &dd, QObject *parent = nullptr);
public:
    explicit SimBackendAdapter(QObject *parent = nullptr);
public:
    virtual ~SimBackendAdapter();

protected:
    virtual bool initialize(SimBackend *backend) = 0;
public:
    bool initAdapter(SimBackend *backend);
public:
    SimBackend *backend() const;
};

#endif // SIMBACKENDADAPTER_H
