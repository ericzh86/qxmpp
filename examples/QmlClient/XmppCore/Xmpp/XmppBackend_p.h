#ifndef XMPPBACKEND_P_H
#define XMPPBACKEND_P_H

#include "XmppBackend.h"
#include "Core/SimBackend_p.h"
#include "QXmppClient.h"

class XmppBackendPrivate : public SimBackendPrivate
{
    Q_DECLARE_PUBLIC(XmppBackend)

public:
    XmppBackendPrivate();
    virtual ~XmppBackendPrivate();
protected:
    QXmppClient *backend;
};

#endif // XMPPBACKEND_P_H
