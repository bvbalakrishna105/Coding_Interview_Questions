#include "coding_interviews.h"

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
    MinStack stack;
    stack.push(3);
    stack.push(2);
    stack.push(5);
    stack.push(1);
    
    std::cout << "Minimum value in the stack: " << stack.getMin() << std::endl;

    stack.pop();
    std::cout << "Minimum value in the stack after popping: " << stack.getMin() << std::endl;
}

// Function to toggle bit at a given position
int toggleBit(int num, int position) {
    // Create a mask with only the bit at the given position set (1)
    int mask = 1 << position;

    // XOR the number with the mask to toggle the bit
    return num ^ mask;
}

void exampleToggleBits() {

    // Toggle the bit at the given position
    int position = 2;
    int result = toggleBit(10, position);

    // Output the result
    std::cout << "Number after toggling bit at position " << position << ": " << result << std::endl;
}


template<typename T>
class ThreadSafeLinkedList {
private:
    struct Node {
        T data;
        Node* next;
        Node(const T& val) : data(val), next(nullptr) {}
    };

    Node* head;
    std::mutex mtx;

public:
    ThreadSafeLinkedList() : head(nullptr) {}

    ~ThreadSafeLinkedList() {
        Node* current = head;
        while (current) {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
    }

    void insert(const T& val) {
        std::lock_guard<std::mutex> lock(mtx);
        Node* newNode = new Node(val);
        newNode->next = head;
        head = newNode;
    }

    void display() {
        std::lock_guard<std::mutex> lock(mtx);
        Node* current = head;
        while (current) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }
};


void exampleThreadSafeLinkedList() {
    ThreadSafeLinkedList<int> list;

    // Insert elements into the list from multiple threads
    list.insert(10);
    list.insert(20);
    list.insert(30);

    // Display the contents of the list from multiple threads
    list.display();

}


int main() {
    exampleGetMinStackVal();
    exampleToggleBits();
    exampleThreadSafeLinkedList();

    //std::cout << "Show static variable val : "<< a << std::endl;

    return 0;
}
