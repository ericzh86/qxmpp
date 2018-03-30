#ifndef XMPPBACKEND_H
#define XMPPBACKEND_H

#include "Core/SimBackend.h"

class XmppBackendPrivate;
class XmppBackend : public SimBackend
{
    Q_OBJECT
    Q_DECLARE_PRIVATE(XmppBackend)

public:
    explicit XmppBackend(QObject *parent = nullptr);
    virtual ~XmppBackend();

public:
    void *backendHandle() const final;
};

#endif // XMPPBACKEND_H
