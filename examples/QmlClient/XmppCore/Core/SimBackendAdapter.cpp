#include "SimBackendAdapter.h"
#include "SimBackendAdapter_p.h"

// class SimBackendAdapter

SimBackendAdapter::SimBackendAdapter(SimBackendAdapterPrivate &dd, QObject *parent)
    : SimControl(dd, parent)
{
}

SimBackendAdapter::SimBackendAdapter(QObject *parent)
    : SimControl(*new SimBackendAdapterPrivate(), parent)
{
}

SimBackendAdapter::~SimBackendAdapter()
{
}

bool SimBackendAdapter::initAdapter(SimBackend *backend)
{
    Q_D(SimBackendAdapter);

    if (d->backend) {
        Q_ASSERT(!d->backend);
        return false;
    }

    if (!initialize(backend)) {
        return false;
    }

    d->backend = backend;

    return true;
}

SimBackend *SimBackendAdapter::backend() const
{
    Q_D(const SimBackendAdapter);

    return d->backend;
}

// class SimBackendAdapterPrivate

SimBackendAdapterPrivate::SimBackendAdapterPrivate()
    : backend(nullptr)
{
}

SimBackendAdapterPrivate::~SimBackendAdapterPrivate()
{
}
