#include "XmppModule.h"

#include <QtQml>

#include "Xmpp/XmppClient.h"

static QObject *xmppProvider(QQmlEngine *engine, QJSEngine *)
{
    return new XmppClient(engine);
}

void QtXmpp::initialize()
{
    qmlRegisterSingletonType<XmppClient>("QtShark.Xmpp", 1, 0, "Xmpp", xmppProvider);
}
