#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;  // Con tro den node tiep theo
    Node* prev;  // Con tro den node truoc
};

// Them node vao dau danh sach lien ket doi
void insertAtHead(Node*& head, int newData) {
    Node* newNode = new Node();
    newNode->data = newData;
    newNode->next = head;
    newNode->prev = NULL;

    if (head != NULL) {
        head->prev = newNode;
    }
    head = newNode;
}

// In danh sach lien ket doi tu dau den cuoi
void printList(Node* head) {
    while (head != NULL) {
        cout << head->data << " <-> ";
        head = head->next;
    }
    cout << "null" << endl;
}

// Xoa mot node khoi danh sach lien ket doi
void deleteNode(Node*& head, int value) {
    if (head == NULL) {
        cout << "Danh sach rong, khong can xoa." << endl;
        return;
    }

    Node* current = head;

    // Duyet tim node chua gia tri can xoa
    while (current != NULL && current->data != value) {
        current = current->next;
    }

    //Neu khong tim thay gia tri
    if (current == NULL) {
        cout << "Khong tim thay gia tri " << value << " trong danh sach." << endl;
        return;
    }

    // Truong hop node can xoa la node dau tien
    if (current == head) {
        head = current->next;  //Cap nhat head
        if (head != NULL) {
            head->prev = NULL;  // Neu con node phia sau, cap nhat prev thanh NULL
        }
    }
    // Truong hop node nam giua hoac cuoi
    else {
        if (current->next != NULL) {  // Neu khong phai node cuoi
            current->next->prev = current->prev;
        }
        if (current->prev != NULL) { //Neu khong phai node dau
            current->prev->next = current->next;
        }
    }

    // Giai phong bo nho node can xoa
    delete current;
    cout << "Xoa thanh cong node co gia tri " << value << "." << endl;
}

int main() {
    Node* head = NULL;
    int n, value, xoa;

    cout << "Nhap so luong node muon them vao danh sach: ";
    cin >> n;

    // Them cac node vao danh sach
    for (int i = 0; i < n; i++) {
        cout << "Nhap gia tri cho node " << i + 1 << ": ";
        cin >> value;
        insertAtHead(head, value);
    }

    // In danh sach lien ket doi
    cout << "Danh sach lien ket doi sau khi them cac node: " << endl;
    printList(head);

    // Xoa mot node ra khoi danh sach
    cout << "Nhap gia tri muon xoa: ";
    cin >> xoa;
    deleteNode(head, xoa);

    // In danh sach sau khi xoa
    cout << "Danh sach sau khi xoa node: " << endl;
    printList(head);

    return 0;
}

