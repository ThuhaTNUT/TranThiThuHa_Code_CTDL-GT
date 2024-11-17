#include <iostream>
#include <iomanip>
using namespace std;

struct Node {
    char data;
    Node* left;
    Node* right;

    Node(char val) {
        data = val;
        left = right = NULL;
    }
};

void preOrder(Node* root) {
    if (root) {
        cout << root->data << " ";
        preOrder(root->left);
        preOrder(root->right);
    }
}

void inOrder(Node* root) {
    if (root) {
        inOrder(root->left);
        cout << root->data << " ";
        inOrder(root->right);
    }
}

void postOrder(Node* root) {
    if (root) {
        postOrder(root->left);
        postOrder(root->right);
        cout << root->data << " ";
    }
}

void printTree(Node* root, int space = 0, int height = 10) {
    if (root == NULL) return;
    space += height;
    printTree(root->right, space);
    cout << endl;
    for (int i = height; i < space; i++) cout << " ";
    cout << root->data << "\n";
    printTree(root->left, space);
}

int main() {
    Node* root = new Node('/'); 
    root->left = new Node('*');
    root->right = new Node('e');
    root->left->left = new Node('a');
    root->left->right = new Node('+');
    root->left->right->left = new Node('-');
    root->left->right->right = new Node('d');
    root->left->right->left->left = new Node('b');
    root->left->right->left->right = new Node('c');

    cout << "Cay nhi phan:\n";
    printTree(root);

    cout << "\nDuyet theo thu tu truoc (Pre-order): ";
    preOrder(root);
    cout << endl;

    cout << "Duyet theo thu tu giua (In-order): ";
    inOrder(root);
    cout << endl;

    cout << "Duyet theo thu tu sau (Post-order): ";
    postOrder(root);
    cout << endl;

    delete root->left->right->left->right;
    delete root->left->right->left->left;
    delete root->left->right->right;
    delete root->left->right->left;
    delete root->left->left;
    delete root->left->right;
    delete root->right;
    delete root;

    return 0;
}
