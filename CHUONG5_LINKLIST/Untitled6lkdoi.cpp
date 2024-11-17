#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;

    Node(int value) {
        data = value;
        prev = NULL;
        next = NULL;
    }
};

struct DoublyLinkedList {
    Node* head;
    Node* tail;

    DoublyLinkedList() {
        head = NULL;
        tail = NULL;
    }

    void insertAtHead(int value) {
        Node* newNode = new Node(value);
        if (head == NULL) {
            head = tail = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    void insertAtTail(int value) {
        Node* newNode = new Node(value);
        if (tail == NULL) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    void deleteNode(int value) {
        if (head == NULL) return;

        Node* temp = head;

        while (temp != NULL && temp->data != value) {
            temp = temp->next;
        }

        if (temp == NULL) {
            cout << "Khong tim thay phan tu " << value << " trong danh sach!" << endl;
            return;
        }

        if (temp == head) {
            head = temp->next;
            if (head != NULL) {
                head->prev = NULL;
            }
        } else if (temp == tail) {
            tail = temp->prev;
            if (tail != NULL) {
                tail->next = NULL;
            }
        } else {
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
        }

        delete temp;
    }

    void display() {
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    DoublyLinkedList list;

    list.insertAtHead(10);
    list.insertAtHead(20);
    list.insertAtTail(5);
    list.insertAtTail(1);

    cout << "Danh sach sau khi them phan tu: ";
    list.display();

    list.deleteNode(20);
    cout << "Danh sach sau khi xoa phan tu 20: ";
    list.display();

    list.deleteNode(5);
    cout << "Danh sach sau khi xoa phan tu 5: ";
    list.display();

    return 0;
}

