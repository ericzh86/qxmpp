INCLUDEPATH += $$PWD

HEADERS += \
    $$PWD/XmppModule.h
SOURCES += \
    $$PWD/XmppModule.cpp

include(Core/Core.pri)
include(Models/Models.pri)
include(Adapters/Adapters.pri)

include(Xmpp/Xmpp.pri)
include(XmppAdapters/XmppAdapters.pri)
