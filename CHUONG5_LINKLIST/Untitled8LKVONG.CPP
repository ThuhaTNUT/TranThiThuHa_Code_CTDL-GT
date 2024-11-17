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

    // Thêm ph?n t? vào d?u danh sách
    void insertAtHead(int value) {
        Node* newNode = new Node(value);
        if (head == NULL) {
            head = newNode;
            newNode->next = head;  // Tr? v? chính nó (danh sách ch? có 1 ph?n t?)
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

    // Thêm ph?n t? vào cu?i danh sách
    void insertAtTail(int value) {
        Node* newNode = new Node(value);
        if (head == NULL) {
            head = newNode;
            newNode->next = head;  // Tr? v? chính nó
        } else {
            Node* temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->next = head;  // C?p nh?t con tr? c?a ph?n t? m?i
        }
    }

    // Xóa ph?n t? d?u tiên
    void deleteAtHead() {
        if (head == NULL) return; // N?u danh sách r?ng
        
        if (head->next == head) {  // N?u ch? có 1 ph?n t?
            delete head;
            head = NULL;
        } else {
            Node* temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            temp->next = head->next;  // C?p nh?t con tr? cu?i cùng
            delete head;
            head = temp->next;
        }
    }

    // Duy?t danh sách
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

    // Thêm ph?n t? vào d?u danh sách
    list.insertAtHead(10);
    list.insertAtHead(20);
    list.insertAtTail(30);
    list.insertAtTail(40);

    // Duy?t danh sách
    cout << "Danh sach sau khi them phan tu: ";
    list.display();

    // Xóa ph?n t? d?u tiên
    list.deleteAtHead();
    cout << "Danh sach sau khi xoa phan tu dau: ";
    list.display();

    return 0;
}

