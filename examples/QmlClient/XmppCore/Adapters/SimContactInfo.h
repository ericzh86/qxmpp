#ifndef SIMCONTACTINFO_H
#define SIMCONTACTINFO_H

#include "Core/SimControl.h"

class SimContactInfoPrivate;
class SimContactInfo : public SimControl
{
    Q_OBJECT
    Q_DECLARE_PRIVATE(SimContactInfo)

    Q_PROPERTY(QString id READ id CONSTANT)

protected:
    SimContactInfo(SimContactInfoPrivate &dd, QObject *parent = nullptr);
public:
    explicit SimContactInfo(QObject *parent = nullptr);
public:
    virtual ~SimContactInfo();

public:
    void init(const QString &id);
    const QString &id() const;
};

#endif // SIMCONTACTINFO_H
