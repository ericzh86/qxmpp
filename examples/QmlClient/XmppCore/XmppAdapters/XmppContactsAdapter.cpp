#include "XmppContactsAdapter.h"
#include "XmppContactsAdapter_p.h"

#include "QXmppClient.h"
#include "QXmppRosterManager.h"

#include "Adapters/SimContactInfo.h"
#include "Models/SimContactsModel.h"

// class XmppContactsAdapter

XmppContactsAdapter::XmppContactsAdapter(QObject *parent)
    : SimContactsAdapter(parent)
{
}

XmppContactsAdapter::~XmppContactsAdapter()
{
}

bool XmppContactsAdapter::initialize(SimBackend *backend)
{
    auto client = reinterpret_cast<QXmppClient *>(backend->backendHandle());

    connect(&client->rosterManager(), &QXmppRosterManager::rosterReceived,
            this, &XmppContactsAdapter::updateContacts);

    return true;
}

void XmppContactsAdapter::updateContacts()
{
    qInfo("WWWWW");

    auto client = reinterpret_cast<QXmppClient *>(backend()->backendHandle());

    for (auto jid : client->rosterManager().getRosterBareJids()) {
        qInfo("%s", qPrintable(jid));
        auto info = contactsModel()->info(jid);
        if (!info) {
            info = new SimContactInfo(contactsModel());
            info->init(jid);
            contactsModel()->updateInfo(info);
        }
    }
}
