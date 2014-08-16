// queue implementation using stacks

#include "stack.hh"

#ifndef _QUEUE_STACK_HH
#define _QUEUE_STACK_HH

template <class T>
class QueueStack
{
public:
QueueStack(void) : _length(0)
{
    _mainStack = new Stack<T>();
    _tempStack = new Stack<T>();
}

~QueueStack(void)
{
    delete _mainStack;
    delete _tempStack;
    _length = 0;
}

void enqueue(T &element)
{
    for (int i = 0; i < _length; ++i)
    {
        _tempStack->push(_mainStack->getTop());
        _mainStack->pop();
    }

    _mainStack->push(element);

    for (int i = 0; i < _length; ++i)
    {
        _mainStack->push(_tempStack->getTop());
        _tempStack->pop();
    }

    _length++;
}

void dequeue(void)
{
    if (_length)
    {
        _mainStack->pop();
        _length--;
    }
}

T &getBack(void)
{
    return _mainStack->getTop();
}

private:
size_t _length;
Stack<T> *_mainStack;
Stack<T> *_tempStack;
};

#endif
