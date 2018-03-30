#ifndef XMPPCLIENT_P_H
#define XMPPCLIENT_P_H

#include "Core/SimControl_p.h"
#include "XmppClient.h"

class XmppContactsAdapter;
class SimGroupModelAdaptor;
class SimSessionModelAdaptor;

#include "XmppBackend.h"

class XmppClientPrivate : public SimControlPrivate
{
    Q_DECLARE_PUBLIC(XmppClient)

public:
    XmppClientPrivate();
    virtual ~XmppClientPrivate();

protected:
    XmppBackend *qxcBackend;
public:
    void setState(XmppClient::State state);
protected:
    XmppClient::State state;

protected:
    XmppContactsAdapter *contactsAdaptor;
    SimGroupModelAdaptor *groupModelAdaptor;
    SimSessionModelAdaptor *sessionModelAdaptor;
};

#endif // XMPPCLIENT_P_H
