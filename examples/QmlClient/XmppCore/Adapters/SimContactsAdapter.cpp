#include "SimContactsAdapter.h"
#include "SimContactsAdapter_p.h"

#include "SimContactInfo.h"

// class SimContactsAdapter

SimContactsAdapter::SimContactsAdapter(QObject *parent)
    : SimBackendAdapter(*new SimContactsAdapterPrivate(), parent)
{
    Q_D(SimContactsAdapter);

    d->model = new SimContactsModel(this);
}

SimContactsAdapter::~SimContactsAdapter()
{
}

SimContactsModel *SimContactsAdapter::contactsModel() const
{
    Q_D(const SimContactsAdapter);

    return d->model;
}

// class SimContactsAdapterPrivate

SimContactsAdapterPrivate::SimContactsAdapterPrivate()
    : model(nullptr)
{
}

SimContactsAdapterPrivate::~SimContactsAdapterPrivate()
{
}
