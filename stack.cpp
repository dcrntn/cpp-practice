#include <iostream>

#define MAX 10

class MyStack
{
public:
    int items[MAX] = {};
    int top;

    MyStack()
    {
        this->createEmptyStack();
    }

    void pushElement(int elem)
    {
        if (this->isFull())
        {
            std::cout << "Stack is full value " << elem << " is dropped" << std::endl;
            return;
        }
        this->top++;
        this->items[this->top] = elem;
    }

    void popElement()
    {
        if (this->isEmpty())
        {
            std::cout << "Stack is empty" << std::endl;
            return;
        }
        std::cout << "Popped element: " << this->items[this->top] << std::endl;
        this->top--;
    }

    int isFull()
    {
        if (this->top == (MAX - 1))
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }

    int isEmpty()
    {
        if (this->top == -1)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }

    void printElements()
    {
        std::cout << "Elements in stack: " << std::endl;
        for (int i = 0; i <= this->top; i++)
        {
            std::cout << this->items[i] << std::endl;
        }
    }

private:
    void createEmptyStack()
    {
        this->top = -1;
    }
};

int main()
{
    MyStack mStack;
    mStack.popElement();
    mStack.pushElement(1);
    mStack.pushElement(2);
    mStack.pushElement(3);
    mStack.pushElement(4);
    mStack.pushElement(5);
    mStack.pushElement(6);
    mStack.pushElement(7);
    mStack.pushElement(8);
    mStack.pushElement(9);
    mStack.pushElement(10);
    mStack.pushElement(11);
    mStack.pushElement(12);

    mStack.printElements();
    mStack.popElement();
    mStack.printElements();
    return 0;
}