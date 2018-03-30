#ifndef XMPPCLIENT_H
#define XMPPCLIENT_H

#include <QAbstractItemModel>
#include "Core/SimControl.h"

class XmppClientPrivate;
class XmppClient : public SimControl
{
    Q_OBJECT
    Q_DECLARE_PRIVATE(XmppClient)

    Q_PROPERTY(State state READ state NOTIFY stateChanged)

    Q_PROPERTY(QAbstractItemModel *contacts READ contactModel CONSTANT)
    Q_PROPERTY(QAbstractItemModel *groups READ groupModel CONSTANT)
    Q_PROPERTY(QAbstractItemModel *sessions READ sessionModel CONSTANT)

public:
    explicit XmppClient(QObject *parent = nullptr);
    virtual ~XmppClient();

public:
    enum State {
        UnconnectedState,
        ConnectingState,
        ConnectedState,
    };
    Q_ENUM(State)
signals:
    void stateChanged();
public:
    State state() const;

public:
    QAbstractItemModel *contactModel() const;
    QAbstractItemModel *groupModel() const;
    QAbstractItemModel *sessionModel() const;

public slots:
    void connectToServer(const QString &username,
                         const QString &password);
    void disconnectFromServer();
};

#endif // XMPPCLIENT_H
