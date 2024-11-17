#include <iostream>
#include <queue>
#include <iomanip> // De can chinh khi in cay
using namespace std;

// Dinh nghia cau truc Node cho cay nhi phan
struct Node {
    int data;
    Node* left;  // Con trai
    Node* right; // Con phai

    Node(int value) : data(value), left(NULL), right(NULL) {}
};

// Ham them mot nut moi vao cay nhi phan
void addNode(Node*& root, int value) {
    Node* newNode = new Node(value);
    if (root == NULL) {
        root = newNode; // Neu cay rong, gan nut moi lam goc
        return;
    }

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* temp = q.front();
        q.pop();

        if (temp->left == NULL) {
            temp->left = newNode;
            return;
        } else {
            q.push(temp->left);
        }

        if (temp->right == NULL) {
            temp->right = newNode;
            return;
        } else {
            q.push(temp->right);
        }
    }
}

// Ham tim chieu cao cua cay
int treeHeight(Node* root) {
    if (root == NULL) return 0;
    return 1 + max(treeHeight(root->left), treeHeight(root->right));
}

// Ham ve cay nhi phan ra man hinh
void printTree(Node* root, int space = 0, int indent = 6) {
    if (root == NULL) return;

    space += indent;
    printTree(root->right, space);

    cout << endl;
    for (int i = indent; i < space; i++) cout << " ";
    cout << root->data << endl;

    printTree(root->left, space);
}

// Ham xoa mot nut trong cay nhi phan
void deleteNode(Node*& root, int value) {
    if (root == NULL) {
        cout << "Cay rong, khong the xoa!" << endl;
        return;
    }

    queue<Node*> q;
    q.push(root);

    Node* targetNode = NULL; // Nut can xoa
    Node* lastNode = NULL;   // Nut cuoi cung
    Node* parentOfLast = NULL; // Cha cua nut cuoi cung

    while (!q.empty()) {
        Node* temp = q.front();
        q.pop();

        if (temp->data == value) {
            targetNode = temp;
        }

        if (temp->left) {
            parentOfLast = temp;
            q.push(temp->left);
        }
        if (temp->right) {
            parentOfLast = temp;
            q.push(temp->right);
        }

        lastNode = temp;
    }

    if (targetNode == NULL) {
        cout << "Khong tim thay gia tri can xoa!" << endl;
        return;
    }

    // Thay the gia tri cua targetNode bang gia tri cua lastNode
    targetNode->data = lastNode->data;

    // Xoa lastNode khoi cay
    if (parentOfLast->left == lastNode) {
        delete parentOfLast->left;
        parentOfLast->left = NULL;
    } else if (parentOfLast->right == lastNode) {
        delete parentOfLast->right;
        parentOfLast->right = NULL;
    } else {
        // Neu nut cuoi chinh la goc
        delete root;
        root = NULL;
    }
}

// Duyet cay theo thu tu truoc (preorder)
void preorderTraversal(Node* root) {
    if (root == NULL) return;
    cout << root->data << " ";
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

// Duyet cay theo thu tu giua (inorder)
void inorderTraversal(Node* root) {
    if (root == NULL) return;
    inorderTraversal(root->left);
    cout << root->data << " ";
    inorderTraversal(root->right);
}

// Duyet cay theo thu tu sau (postorder)
void postorderTraversal(Node* root) {
    if (root == NULL) return;
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    cout << root->data << " ";
}

// Giai phong bo nho cay
void freeTree(Node*& root) {
    if (root == NULL) return;
    freeTree(root->left);
    freeTree(root->right);
    delete root;
    root = NULL;
}

int main() {
    Node* root = NULL;
    int choice, value;

    do {
        cout << "\n----- MENU -----\n";
        cout << "1. Them nut vao cay\n";
        cout << "2. Xoa nut khoi cay\n";
        cout << "3. Duyet cay (Preorder)\n";
        cout << "4. Duyet cay (Inorder)\n";
        cout << "5. Duyet cay (Postorder)\n";
        cout << "6. Ve cay\n";
        cout << "7. Thoat\n";
        cout << "Lua chon: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Nhap gia tri can them: ";
                cin >> value;
                addNode(root, value);
                break;

            case 2:
                cout << "Nhap gia tri can xoa: ";
                cin >> value;
                deleteNode(root, value);
                break;

            case 3:
                cout << "Duyet cay (Preorder): ";
                preorderTraversal(root);
                cout << endl;
                break;

            case 4:
                cout << "Duyet cay (Inorder): ";
                inorderTraversal(root);
                cout << endl;
                break;

            case 5:
                cout << "Duyet cay (Postorder): ";
                postorderTraversal(root);
                cout << endl;
                break;

            case 6:
                cout << "So do cay:\n";
                printTree(root);
                break;

            case 7:
                cout << "Thoat chuong trinh.\n";
                break;

            default:
                cout << "Lua chon khong hop le! Vui long thu lai.\n";
        }
    } while (choice != 7);

    // Giai phong bo nho
    freeTree(root);
    return 0;
}

