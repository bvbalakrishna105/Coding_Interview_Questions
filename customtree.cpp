#include <iostream>
#include <stack>

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
    void inorderIteratorTraversal();
    void preorderIteratorTraversal();
    void postorderIteratorTraversal();

};


void BinarySearchTree::inorderTraversal(){
    cout << "Inorder : ";
    inorder(root);
    cout << endl;

}

void BinarySearchTree::postorderTraversal(){
    cout << "Postorder : ";
    postorder(root);
    cout << endl;

}

void BinarySearchTree::preorderTraversal(){
    cout << "Preorder : ";
    preorder(root);
    cout << endl;

}

void BinarySearchTree::inorderIteratorTraversal(){

    cout << "inorderIteratorTraversal : ";
    stack<Node*> st;

    Node *tmp = NULL;

    while(1) {

        if (root) {
            st.push(root);
            root = root->left;
            continue;
        }

        if (st.empty()){
            cout << endl;
            break;
        }

        tmp = st.top();

        if (tmp->left == NULL && tmp->right == NULL) {
            cout << tmp->data << " ";
            st.pop();
            continue;
        }

        if (tmp->right) {
            cout << tmp->data << " ";
            st.pop();
            root = tmp->right;
        }
    }
}

void BinarySearchTree::preorderIteratorTraversal() {

    cout << "BinarySearchTree::preorderIteratorTraversal : ";
    stack<Node*> st;

    Node *tmp = NULL;

    while(1) {

        if(root) {
            cout << root->data << " ";
            st.push(root);
            root = root->left;
            continue;
        }

        if (st.empty()) {
            cout << endl;
            break;
        }

        tmp = st.top();

        if (tmp->left == NULL && tmp->right == NULL) {
            st.pop();
            continue;
        }

        if(tmp->right) {
            st.pop();
            root = tmp->right;
        }
    }

}


void BinarySearchTree::postorderIteratorTraversal() {
    cout << "BinarySearchTree::postorderIteratorTraversal : ";

    Node *tmpRoot = root;
    Node *tmp = NULL;
    stack<Node*> st;

    while(1) {

        if (tmpRoot) {
            st.push(tmpRoot);
            tmpRoot = tmpRoot->left;
            continue;
        }

        if(st.empty()) {
            cout << endl;
            break;
        }

        tmp = st.top();

        // To make sure that visited node should not visit once again
        if (tmp->data < 0) {
            cout << -(tmp->data) << " ";
            st.pop();
            continue;
        }

        if(tmp->left == NULL && tmp->right == NULL) {
            cout << tmp->data << " ";
            st.pop();
            continue;
        }

        if (tmp->right) {
            st.pop();
            tmp->data = -(tmp->data);
            st.push(tmp);
            tmpRoot = tmp->right;
        }

    }
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
    bst.insert(13);
    bst.insert(17);

    // The binary search tree is now constructed
    // You can add more values or perform other operations as needed

    bst.inorderTraversal();
    bst.preorderTraversal();
    bst.postorderTraversal();
    //bst.inorderIteratorTraversal();
    //bst.preorderIteratorTraversal();
    //bst.postorderIteratorTraversal();

    return 0;
}
