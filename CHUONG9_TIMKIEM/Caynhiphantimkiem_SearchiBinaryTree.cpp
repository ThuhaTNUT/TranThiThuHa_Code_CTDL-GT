#include <iostream>
using namespace std;

// Dinh nghia mot nut trong cay nhi phan
struct Node {
    int data;
    Node* left;
    Node* right;

    // Constructor de khoi tao nut
    Node(int value) : data(value), left(NULL), right(NULL) {}
};

// Ham tim kiem khoa X trong cay nhi phan
Node* search(Node* root, int X) {
    // Neu cay rong hoac tim thay khoa X
    if (root == NULL || root->data == X)
        return root;

    // Neu X nho hon goc, tim kiem trong cay con trai
    if (X < root->data)
        return search(root->left, X);

    // Neu X lon hon goc, tim kiem trong cay con phai
    return search(root->right, X);
}

// Ham chen khoa X vao cay nhi phan tim kiem
Node* insert(Node* root, int X) {
    // Neu cay rong, tao mot nut moi voi khoa X
    if (root == NULL)
        return new Node(X);

    // Neu X nho hon khoa goc, chen vao cay con trai
    if (X < root->data)
        root->left = insert(root->left, X);

    // Neu X lon hon khoa goc, chen vao cay con phai
    else if (X > root->data)
        root->right = insert(root->right, X);

    // Tra ve goc cay khong thay doi
    return root;
}

// Ham duyet cay theo thu tu In-order (trai, goc, phai)
void inorder(Node* root) {
    if (root != NULL) {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}

// Ham chinh
int main() {
    Node* root = NULL;
    int n, X;

    // Nhap so luong phan tu can chen vao cay
    cout << "Nhap so luong phan tu trong cay: ";
    cin >> n;

    // Nhap cac phan tu can chen vao cay
    cout << "Nhap " << n << " phan tu vao cay: ";
    for (int i = 0; i < n; i++) {
        int value;
        cin >> value;
        root = insert(root, value);
    }

    // Duyet cay truoc khi tim kiem
    cout << "Cay truoc khi tim kiem: ";
    inorder(root);
    cout << endl;

    // Nhap khoa X can tim
    cout << "Nhap khoa X can tim: ";
    cin >> X;

    // Kiem tra xem X co trong cay hay khong
    Node* result = search(root, X);
    if (result != NULL) {
        cout << "Tim thay " << X << " trong cay." << endl;
    } else {
        cout << "Khong tim thay " << X << " trong cay. Them " << X << " vao cay." << endl;
        root = insert(root, X);  // Neu khong tim thay X, chen vao cay
    }

    // Duyet cay sau khi tim kiem va chen
    cout << "Cay sau khi tim kiem va chen X: ";
    inorder(root);
    cout << endl;

    return 0;
}

