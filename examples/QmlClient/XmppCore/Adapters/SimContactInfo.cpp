#include "SimContactInfo.h"
#include "SimContactInfo_p.h"

// class SimContactInfo

SimContactInfo::SimContactInfo(SimContactInfoPrivate &dd, QObject *parent)
    : SimControl(dd, parent)
{
}

SimContactInfo::SimContactInfo(QObject *parent)
    : SimControl(*new SimContactInfoPrivate(), parent)
{
}

SimContactInfo::~SimContactInfo()
{
}

void SimContactInfo::init(const QString &id)
{
    Q_D(SimContactInfo);

    if (!d->id.isEmpty()
            || id.isEmpty()) {
        Q_ASSERT(!id.isEmpty());
        Q_ASSERT(d->id.isEmpty());
        return;
    }

    d->id = id;
}

const QString &SimContactInfo::id() const
{
    Q_D(const SimContactInfo);

    return d->id;
}

// class SimContactInfoPrivate

SimContactInfoPrivate::SimContactInfoPrivate()
{
}

SimContactInfoPrivate::~SimContactInfoPrivate()
{
}
