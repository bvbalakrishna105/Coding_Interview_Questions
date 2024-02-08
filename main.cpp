#include <iostream>
#include <stack>

class MinStack {
private:
    std::stack<int> dataStack;
    std::stack<int> minStack;

public:
    void push(int val) {
        dataStack.push(val);
        if (minStack.empty() || val <= minStack.top()) {
            minStack.push(val);
        }
    }

    void pop() {
        if (dataStack.empty()) {
            std::cout << "Stack is empty. Cannot pop.\n";
            return;
        }
        if (dataStack.top() == minStack.top()) {
            minStack.pop();
        }
        dataStack.pop();
    }

    int top() {
        if (dataStack.empty()) {
            std::cout << "Stack is empty.\n";
            return -1; // or throw an exception
        }
        return dataStack.top();
    }

    int getMin() {
        if (minStack.empty()) {
            std::cout << "Stack is empty.\n";
            return -1; // or throw an exception
        }
        return minStack.top();
    }

    bool empty() {
        return dataStack.empty();
    }
};


void exampleGetMinStackVal() {
    
}

int main() {
    MinStack stack;
    stack.push(3);
    stack.push(2);
    stack.push(5);
    stack.push(1);
    
    std::cout << "Minimum value in the stack: " << stack.getMin() << std::endl;

    stack.pop();
    std::cout << "Minimum value in the stack after popping: " << stack.getMin() << std::endl;

    return 0;
}
