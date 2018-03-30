#include "XmppBackend.h"
#include "XmppBackend_p.h"

// class XmppBackend

XmppBackend::XmppBackend(QObject *parent)
    : SimBackend(*new XmppBackendPrivate(), parent)
{
    Q_D(XmppBackend);

    d->backend = new QXmppClient(this);
}

XmppBackend::~XmppBackend()
{
}

void *XmppBackend::backendHandle() const
{
    Q_D(const XmppBackend);

    return d->backend;
}

// class XmppBackendPrivate

XmppBackendPrivate::XmppBackendPrivate()
    : backend(nullptr)
{
}

XmppBackendPrivate::~XmppBackendPrivate()
{
}
