#include <iostream>

using namespace std;

// Node class representing a single node in the doubly linked list
class Node {
public:
    int data;
    Node* prev;
    Node* next;

    // Constructor
    Node(int value) {
        data = value;
        prev = nullptr;
        next = nullptr;
    }
};

// DoublyLinkedList class representing the doubly linked list
class DoublyLinkedList {
private:
    Node* head;
    Node* tail;

public:
    // Constructor
    DoublyLinkedList() {
        head = nullptr;
        tail = nullptr;
    }

    // Function to insert a new node at the end of the list
    void append(int value) {
        Node* newNode = new Node(value);
        if (tail == nullptr) {
            // List is empty
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    // Function to display the list
    void display() {
        Node* current = head;
        while (current != nullptr) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }

    // Function to display the list in reverse order
    void displayReverse() {
        Node* current = tail;
        while (current != nullptr) {
            std::cout << current->data << " ";
            current = current->prev;
        }
        std::cout << std::endl;
    }
};

int main() {
    // Create an instance of DoublyLinkedList
    DoublyLinkedList dll;

    // Insert some values into the list
    dll.append(1);
    dll.append(2);
    dll.append(3);
    dll.append(4);
    dll.append(5);

    // Display the list
    std::cout << "Doubly Linked List:" << std::endl;
    dll.display();

    // Display the list in reverse order
    std::cout << "Doubly Linked List in reverse order:" << std::endl;
    dll.displayReverse();

    return 0;
}
