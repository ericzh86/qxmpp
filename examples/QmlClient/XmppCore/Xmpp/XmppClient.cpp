#include "XmppClient.h"
#include "XmppClient_p.h"

#include <QQmlEngine>

#include "XmppAdapters/XmppContactsAdapter.h"
// #include "Adaptors/SimGroupModelAdaptor.h"
// #include "Adaptors/SimSessionModelAdaptor.h"

// class XmppClient

#include "QXmppClient.h"

XmppClient::XmppClient(QObject *parent)
    : SimControl(*new XmppClientPrivate(), parent)
{
    Q_D(XmppClient);
    d->qxcBackend = new XmppBackend(this);
    QQmlEngine::setObjectOwnership(this, QQmlEngine::CppOwnership);

    d->contactsAdaptor = new XmppContactsAdapter(this);
    // d->groupModelAdaptor = new SimGroupModelAdaptor(this);
    // d->sessionModelAdaptor = new SimSessionModelAdaptor(this);

    d->contactsAdaptor->initAdapter(d->qxcBackend);

    QXmppClient *backend = reinterpret_cast<QXmppClient *>(d->qxcBackend->backendHandle());

    connect(backend, &QXmppClient::connected,
            this, [=] { d->setState(ConnectedState); });
    connect(backend, &QXmppClient::disconnected,
            this, [=] { d->setState(UnconnectedState); });
}

XmppClient::~XmppClient()
{
}

XmppClient::State XmppClient::state() const
{
    Q_D(const XmppClient);

    return d->state;
}

QAbstractItemModel *XmppClient::contactModel() const
{
    Q_D(const XmppClient);

    return d->contactsAdaptor->contactsModel();
}

QAbstractItemModel *XmppClient::groupModel() const
{
    Q_D(const XmppClient);

    return nullptr; // d->groupModel;
}

QAbstractItemModel *XmppClient::sessionModel() const
{
    Q_D(const XmppClient);

    return nullptr; // d->sessionModel;
}

void XmppClient::connectToServer(const QString &username, const QString &password)
{
    Q_D(XmppClient);

    if (UnconnectedState == d->state) {
        d->setState(ConnectingState);

        QXmppClient *backend = reinterpret_cast<QXmppClient *>(d->qxcBackend->backendHandle());

        QString jid = username + "@xmpp.jp";
        backend->connectToServer(jid, password);
    }
}

void XmppClient::disconnectFromServer()
{
    Q_D(XmppClient);

    QXmppClient *backend = reinterpret_cast<QXmppClient *>(d->qxcBackend->backendHandle());

    backend->disconnectFromServer();
}

// class XmppClientPrivate

XmppClientPrivate::XmppClientPrivate()
    : qxcBackend(nullptr)
    , state(XmppClient::UnconnectedState)
    // Models
    , contactsAdaptor(nullptr)
    , groupModelAdaptor(nullptr)
    , sessionModelAdaptor(nullptr)
{
}

XmppClientPrivate::~XmppClientPrivate()
{
}

void XmppClientPrivate::setState(XmppClient::State state)
{
    Q_Q(XmppClient);

    if (state != this->state) {
        this->state = state;
        emit q->stateChanged();
    }
}
