#ifndef SIMBACKEND_H
#define SIMBACKEND_H

#include <QObject>

class SimBackendPrivate;
class SimBackend : public QObject
{
    Q_OBJECT
    Q_DECLARE_PRIVATE(SimBackend)

protected:
    SimBackend(SimBackendPrivate &dd, QObject *parent = nullptr);
protected:
    QScopedPointer<SimBackendPrivate> d_ptr;
public:
    virtual ~SimBackend();

public:
    virtual void *backendHandle() const = 0;
};

#endif // SIMBACKEND_H
