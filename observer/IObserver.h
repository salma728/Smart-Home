#ifndef IOBSERVER_H
#define IOBSERVER_H

#include <string>

using namespace std;

class ISubject;

class IObserver
{
public:
    virtual ~IObserver() = default;
    virtual void update(const string &event, ISubject *sender) = 0;
};

#endif
