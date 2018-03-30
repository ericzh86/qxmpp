#ifndef SIMCONTROL_H
#define SIMCONTROL_H

#include <QObject>

class SimControlPrivate;
class SimControl : public QObject
{
    Q_OBJECT
    Q_DECLARE_PRIVATE(SimControl)

protected:
    SimControl(SimControlPrivate &dd, QObject *parent = nullptr);
protected:
    QScopedPointer<SimControlPrivate> d_ptr;
public:
    virtual ~SimControl();
};

#endif // SIMCONTROL_H
