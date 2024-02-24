#include <iostream>

using namespace std;

// Node class representing a single node in the binary tree
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

// BinarySearchTree class representing the binary search tree
class BinarySearchTree {
private:
    Node* root;

    // Private recursive function to insert a new node into the tree
    Node* insertRecursive(Node* current, int value) {
        if (current == nullptr) {
            return new Node(value);
        }

        if (value < current->data) {
            current->left = insertRecursive(current->left, value);
        } else if (value > current->data) {
            current->right = insertRecursive(current->right, value);
        }

        return current;
    }

public:
    // Constructor
    BinarySearchTree() {
        root = nullptr;
    }

    // Public function to insert a new value into the tree
    void insert(int value) {
        root = insertRecursive(root, value);
    }

private:

    void inorder(Node *root) {
        if (root) {
            inorder(root->left);
            cout << root->data << " ";
            inorder(root->right);
        }
    }

    void preorder(Node *root) {
        if (root) {
            cout << root->data << " ";
            preorder(root->left);
            preorder(root->right);
        }
    }

    void postorder(Node *root) {
        if (root) {
            postorder(root->left);
            postorder(root->right);
            cout << root->data << " ";
        }
    }
       
public:
    void inorderTraversal();
    void preorderTraversal();
    void postorderTraversal();
};


void BinarySearchTree::inorderTraversal(){
        inorder(root);
        cout << endl;

}

void BinarySearchTree::postorderTraversal(){
        postorder(root);
        cout << endl;

}

void BinarySearchTree::preorderTraversal(){
        preorder(root);
        cout << endl;

}





int main() {
    // Create an instance of BinarySearchTree
    BinarySearchTree bst;

    // Insert some values into the tree
    bst.insert(10);
    bst.insert(5);
    bst.insert(15);
    bst.insert(3);
    bst.insert(7);

    bst.inorderTraversal();
    bst.preorderTraversal();
    bst.postorderTraversal();

    // The binary search tree is now constructed
    // You can add more values or perform other operations as needed

    return 0;
}
