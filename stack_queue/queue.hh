#include <list>

#ifndef _QUEUE_HH
#define _QUEUE_HH

template <class T>
class Queue
{
public:
Queue(void)
{
    _data = new std::list<T>();
}

~Queue(void)
{
    delete _data;
}

void enqueue(T &element)
{
    _data->push_front(element);
}
void dequeue(void)
{
    _data->pop_back();
}
T &getBack(void)
{
    return _data->back();
}

protected:
std::list<T> *_data;
};

#endif
