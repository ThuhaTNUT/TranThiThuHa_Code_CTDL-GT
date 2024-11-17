#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

// Ham chen phan tu vao cuoi danh sach lien ket vong
void insert(Node** head, int newData) {
    Node* newNode = new Node();
    newNode->data = newData;
    newNode->next = *head;

    if (*head == NULL) {  // Neu danh sach trong
        *head = newNode;
        newNode->next = *head;
    } else {  // Neu danh sach da co phan tu
        Node* temp = *head;
        while (temp->next != *head) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = *head;
    }
}

// Ham in danh sach lien ket vong
void printList(Node* head) {
    if (head == NULL) return;

    Node* temp = head;
    cout << "Danh sach lien ket vong: ";
    do {
        cout << temp->data << " -> ";
        temp = temp->next;
    } while (temp != head);
    cout << "(quay lai dau)\n";
}

// Ham them phan tu moi vao vi tri bat ky trong danh sach
void addElement(Node** head, int newData, int pos) {
    Node* newNode = new Node();
    newNode->data = newData;

    if (*head == NULL) {
        *head = newNode;
        newNode->next = *head;
    } else if (pos == 0) {
        Node* temp = *head;
        while (temp->next != *head) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = *head;
        *head = newNode;
    } else {
        Node* temp = *head;
        for (int i = 1; i < pos && temp->next != *head; i++) {
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }
}

// Ham xoa phan tu co gia tri x trong danh sach lien ket vong
void deleteElement(Node** head, int x) {
    if (*head == NULL) return;

    Node* temp = *head;
    Node* prev = NULL;

    // Neu phan tu dau la x
    if ((*head)->data == x) {
        while (temp->next != *head) {
            temp = temp->next;
        }
        Node* delNode = *head;
        temp->next = (*head)->next;
        *head = (*head)->next;
        delete delNode;
        return;
    }

    // Tim phan tu co gia tri x va xoa no
    do {
        prev = temp;
        temp = temp->next;
    } while (temp != *head && temp->data != x);

    if (temp->data == x) {
        prev->next = temp->next;
        delete temp;
    } else {
        cout << "Khong tim thay phan tu co gia tri " << x << " de xoa.\n";
    }
}

int main() {
    Node* head = NULL;
    int n, data, pos, x;

    // Nhap danh sach ban dau
    cout << "Nhap so luong phan tu ban dau trong danh sach: ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        cout << "Nhap phan tu thu " << i + 1 << ": ";
        cin >> data;
        insert(&head, data);
    }
    printList(head);

    // Them phan tu moi vao danh sach
    cout << "\nNhap gia tri phan tu can them: ";
    cin >> data;
    cout << "Nhap vi tri can them (bat dau tu 0): ";
    cin >> pos;
    addElement(&head, data, pos);
    cout << "Danh sach sau khi them phan tu: ";
    printList(head);

    // Xoa phan tu trong danh sach
    cout << "\nNhap gia tri phan tu can xoa: ";
    cin >> x;
    deleteElement(&head, x);
    cout << "Danh sach sau khi xoa phan tu: ";
    printList(head);

    return 0;
}

