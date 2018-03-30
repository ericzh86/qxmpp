#include "SimBackend.h"
#include "SimBackend_p.h"

// class SimBackend

SimBackend::SimBackend(SimBackendPrivate &dd, QObject *parent)
    : QObject(parent), d_ptr(&dd)
{
    d_ptr->q_ptr = this;
}

SimBackend::~SimBackend()
{
}

// class SimBackendPrivate

SimBackendPrivate::SimBackendPrivate()
    : q_ptr(nullptr)
{
}

SimBackendPrivate::~SimBackendPrivate()
{
}
