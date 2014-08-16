// stack implementation using queues
#include "queue.hh"


#ifndef _STACK_QUEUE_HH
#define _STACK_QUEUE_HH

template <class T>
class StackQueue
{
public:
StackQueue(void) : _length(0)
{
    _mainQueue = new Queue<T>();
    _tempQueue = new Queue<T>();
}

~StackQueue(void)
{
    delete _mainQueue;
    delete _tempQueue;
    _length = 0;
}

void push(T &element)
{
    for (int i = 0; i < _length; ++i)
    {
        _tempQueue->enqueue(_mainQueue->getBack());
        _mainQueue->dequeue();
    }

    _mainQueue->enqueue(element);

    for (int i = 0; i < _length; ++i)
    {
        _mainQueue->enqueue(_tempQueue->getBack());
        _tempQueue->dequeue();
    }

    _length++;
}

void pop(void)
{
    if (_length)
    {
        _mainQueue->dequeue();
        _length--;
    }
}

T &getTop(void)
{
    return _mainQueue->getBack();
}

private:
size_t _length;
Queue<T> *_mainQueue;
Queue<T> *_tempQueue;
};

#endif
