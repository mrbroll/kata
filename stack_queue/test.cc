#include "queue.hh"
#include "stack.hh"
#include "queue_stack.hh"
#include "stack_queue.hh"
#include <cassert>
#include <iostream>

int main(int argc, char *argv[])
{
    size_t testDataSize = 5;
    int testInts[] = {4, 29, 90, -37, 208};

    Queue<int> *testQueue = new Queue<int>();
    Stack<int> *testStack = new Stack<int>();
    QueueStack<int> *testQueueStack = new QueueStack<int>();
    StackQueue<int> *testStackQueue = new StackQueue<int>();

    // populate the data structures that we want to test
    for (int i = 0; i < testDataSize; ++i)
    {
        testQueue->enqueue(testInts[i]);
        testStack->push(testInts[i]);
        testQueueStack->enqueue(testInts[i]);
        testStackQueue->push(testInts[i]);
    }

    // now let's test these classes by unloading them and checking their contents
    std::cout << "running tests..." << std::endl;

    int queueBack;
    int stackTop;
    int testInt;

    for (int i = 0; i < testDataSize; ++i)
    {
        queueBack = testQueue->getBack();
        testInt = testInts[i];
        assert(queueBack == testInt);
        testQueue->dequeue();

        queueBack = testQueueStack->getBack();
        assert(queueBack = testInt);
        testQueueStack->dequeue();

        stackTop = testStack->getTop();
        testInt = testInts[testDataSize - 1 - i];
        assert(stackTop == testInt);
        testStack->pop();

        stackTop = testStackQueue->getTop();
        assert(stackTop == testInt);
        testStackQueue->pop();
    }

    delete testQueue;
    delete testStack;
    delete testQueueStack;
    delete testStackQueue;

    std::cout << "all tests passed!" << std::endl;

    return 0;
}
