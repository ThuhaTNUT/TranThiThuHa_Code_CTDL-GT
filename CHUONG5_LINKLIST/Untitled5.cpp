#include <iostream>
using namespace std;

// C?u tr�c Node
struct Node {
    int data;
    Node* next;

    // Constructor kh?i t?o
    Node(int value) {
        data = value;
        next = NULL;
    }
};

// C?u tr�c danh s�ch m�c n?i don
class LinkedList {
public:
    Node* head;

    // Constructor
    LinkedList() {
        head = NULL;
    }

    // Th�m ph?n t? v�o d?u danh s�ch
    void insertAtHead(int value) {
        Node* newNode = new Node(value);
        newNode->next = head;
        head = newNode;
    }

    // Duy?t v� in ra danh s�ch
    void traverse() {
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    // X�a ph?n t? kh?i danh s�ch
    void deleteNode(int value) {
        // Tru?ng h?p danh s�ch r?ng
        if (head == NULL) {
            cout << "Danh sach rong, khong the xoa." << endl;
            return;
        }

        // Tru?ng h?p x�a n�t d?u ti�n
        if (head->data == value) {
            Node* temp = head;
            head = head->next;  // C?p nh?t head tr? d?n n�t ti?p theo
            delete temp;  // Gi?i ph�ng b? nh?
            return;
        }

        // Duy?t danh s�ch d? t�m n�t c?n x�a
        Node* current = head;
        while (current->next != NULL && current->next->data != value) {
            current = currentn->next;
        }

        // N?u kh�ng t�m th?y n�t c?n x�a
        if (current->next == NULL) {
            cout << "Khong tim thay gia tri " << value << " trong danh sach." << endl;
            return;
        }

        // Tru?ng h?p x�a n�t ? gi?a ho?c cu?i danh s�ch
        Node* temp = current->next;
        current->next = current->next->next;  // C?p nh?t con tr? c?a n�t tru?c
        delete temp;  // Gi?i ph�ng b? nh?
    }
};

int main() {
    LinkedList list;

    // Th�m c�c ph?n t? v�o danh s�ch
    list.insertAtHead(10);
    list.insertAtHead(20);
    list.insertAtHead(30);
    list.insertAtHead(40);

    // Duy?t v� in ra danh s�ch
    cout << "Danh sach ban dau: ";
    list.traverse();

    // X�a ph?n t? c� gi� tr? 20
    cout << "Xoa phan tu 20." << endl;
    list.deleteNode(20);

    // Duy?t v� in ra danh s�ch sau khi x�a
    cout << "Danh sach sau khi xoa: ";
    list.traverse();

    // X�a ph?n t? c� gi� tr? 10 (n�t d?u ti�n)
    cout << "Xoa phan tu 10." << endl;
    list.deleteNode(10);

    // Duy?t v� in ra danh s�ch sau khi x�a
    cout << "Danh sach sau khi xoa: ";
    list.traverse();

    return 0;
}

