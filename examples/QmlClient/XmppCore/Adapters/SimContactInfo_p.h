#ifndef SIMCONTACTINFO_P_H
#define SIMCONTACTINFO_P_H

#include "Core/SimControl_p.h"
#include "SimContactInfo.h"

class SimContactInfoPrivate : public SimControlPrivate
{
    Q_DECLARE_PUBLIC(SimContactInfo)

public:
    SimContactInfoPrivate();
    virtual ~SimContactInfoPrivate();

protected:
    QString id;
};

#endif // SIMCONTACTINFO_P_H
