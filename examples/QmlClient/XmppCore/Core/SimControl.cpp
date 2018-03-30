#include "SimControl.h"
#include "SimControl_p.h"

// class SimControl

SimControl::SimControl(SimControlPrivate &dd, QObject *parent)
    : QObject(parent), d_ptr(&dd)
{
    d_ptr->q_ptr = this;
}

SimControl::~SimControl()
{
}

// class SimControlPrivate

SimControlPrivate::SimControlPrivate()
    : q_ptr(nullptr)
{
}

SimControlPrivate::~SimControlPrivate()
{
}
