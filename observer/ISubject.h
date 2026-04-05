#ifndef ISUBJECT_H
#define ISUBJECT_H

#include <string>

using namespace std;

class IObserver;

class ISubject
{
public:
    virtual ~ISubject() = default;

    virtual void attach(IObserver *o) = 0;
    virtual void detach(IObserver *o) = 0;
    virtual void notify(const string &event) = 0;
};

#endif
