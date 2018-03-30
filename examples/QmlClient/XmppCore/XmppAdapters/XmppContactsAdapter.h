#ifndef XMPPCONTACTSADAPTER_H
#define XMPPCONTACTSADAPTER_H

#include "Adapters/SimContactsAdapter.h"

class XmppContactsAdapterPrivate;
class XmppContactsAdapter : public SimContactsAdapter
{
    Q_OBJECT

public:
    explicit XmppContactsAdapter(QObject *parent = nullptr);
    virtual ~XmppContactsAdapter();

protected:
    bool initialize(SimBackend *backend) final;

private:
    void updateContacts();
};

#endif // XMPPCONTACTSADAPTER_H
