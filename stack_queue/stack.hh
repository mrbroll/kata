#include <list>

#ifndef _STACK_HH
#define _STACK_HH

template <class T> 
class Stack
{
public:
Stack(void)
{
    _data = new std::list<T>();
}

~Stack(void)
{
    delete _data;
}

void push(T &element)
{
    _data->push_front(element);
}

void pop(void)
{
    _data->pop_front();
}

T &getTop(void)
{
    return _data->front();
}

protected:
std::list<T> *_data;
};

#endif
