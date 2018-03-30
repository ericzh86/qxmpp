#ifndef SIMCONTACTSADAPTER_H
#define SIMCONTACTSADAPTER_H

#include "Core/SimBackendAdapter.h"
#include "Models/SimContactsModel.h"

class SimContactInfo;
class SimContactsAdapterPrivate;
class SimContactsAdapter : public SimBackendAdapter
{
    Q_OBJECT
    Q_DECLARE_PRIVATE(SimContactsAdapter)

    Q_PROPERTY(SimContactsModel *contactsModel READ contactsModel CONSTANT)

protected:
    SimContactsAdapter(SimContactsAdapterPrivate &dd, QObject *parent = nullptr);
public:
    explicit SimContactsAdapter(QObject *parent = nullptr);
public:
    virtual ~SimContactsAdapter();

public:
    SimContactsModel *contactsModel() const;
};

#endif // SIMCONTACTSADAPTER_H
