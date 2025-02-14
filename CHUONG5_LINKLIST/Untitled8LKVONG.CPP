#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    
    Node(int value) {
        data = value;
        next = NULL;
    }
};

class CircularLinkedList {
public:
    Node* head;

    CircularLinkedList() {
        head = NULL;
    }

    // Th�m ph?n t? v�o d?u danh s�ch
    void insertAtHead(int value) {
        Node* newNode = new Node(value);
        if (head == NULL) {
            head = newNode;
            newNode->next = head;  // Tr? v? ch�nh n� (danh s�ch ch? c� 1 ph?n t?)
        } else {
            Node* temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->next = head;  // C?p nh?t con tr? c?a ph?n t? m?i
            head = newNode;
        }
    }

    // Th�m ph?n t? v�o cu?i danh s�ch
    void insertAtTail(int value) {
        Node* newNode = new Node(value);
        if (head == NULL) {
            head = newNode;
            newNode->next = head;  // Tr? v? ch�nh n�
        } else {
            Node* temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->next = head;  // C?p nh?t con tr? c?a ph?n t? m?i
        }
    }

    // X�a ph?n t? d?u ti�n
    void deleteAtHead() {
        if (head == NULL) return; // N?u danh s�ch r?ng
        
        if (head->next == head) {  // N?u ch? c� 1 ph?n t?
            delete head;
            head = NULL;
        } else {
            Node* temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            temp->next = head->next;  // C?p nh?t con tr? cu?i c�ng
            delete head;
            head = temp->next;
        }
    }

    // Duy?t danh s�ch
    void display() {
        if (head == NULL) {
            cout << "Danh sach rong!" << endl;
            return;
        }
        Node* temp = head;
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);
        cout << endl;
    }
};

int main() {
    CircularLinkedList list;

    // Th�m ph?n t? v�o d?u danh s�ch
    list.insertAtHead(10);
    list.insertAtHead(20);
    list.insertAtTail(30);
    list.insertAtTail(40);

    // Duy?t danh s�ch
    cout << "Danh sach sau khi them phan tu: ";
    list.display();

    // X�a ph?n t? d?u ti�n
    list.deleteAtHead();
    cout << "Danh sach sau khi xoa phan tu dau: ";
    list.display();

    return 0;
}

