#include <iostream>
using namespace std;

// C?u trúc Node
struct Node {
    int data;
    Node* next;

    // Constructor kh?i t?o
    Node(int value) {
        data = value;
        next = NULL;
    }
};

// C?u trúc danh sách móc n?i don
class LinkedList {
public:
    Node* head;

    // Constructor
    LinkedList() {
        head = NULL;
    }

    // Thêm ph?n t? vào d?u danh sách
    void insertAtHead(int value) {
        Node* newNode = new Node(value);
        newNode->next = head;
        head = newNode;
    }

    // Duy?t và in ra danh sách
    void traverse() {
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    // Xóa ph?n t? kh?i danh sách
    void deleteNode(int value) {
        // Tru?ng h?p danh sách r?ng
        if (head == NULL) {
            cout << "Danh sach rong, khong the xoa." << endl;
            return;
        }

        // Tru?ng h?p xóa nút d?u tiên
        if (head->data == value) {
            Node* temp = head;
            head = head->next;  // C?p nh?t head tr? d?n nút ti?p theo
            delete temp;  // Gi?i phóng b? nh?
            return;
        }

        // Duy?t danh sách d? tìm nút c?n xóa
        Node* current = head;
        while (current->next != NULL && current->next->data != value) {
            current = currentn->next;
        }

        // N?u không tìm th?y nút c?n xóa
        if (current->next == NULL) {
            cout << "Khong tim thay gia tri " << value << " trong danh sach." << endl;
            return;
        }

        // Tru?ng h?p xóa nút ? gi?a ho?c cu?i danh sách
        Node* temp = current->next;
        current->next = current->next->next;  // C?p nh?t con tr? c?a nút tru?c
        delete temp;  // Gi?i phóng b? nh?
    }
};

int main() {
    LinkedList list;

    // Thêm các ph?n t? vào danh sách
    list.insertAtHead(10);
    list.insertAtHead(20);
    list.insertAtHead(30);
    list.insertAtHead(40);

    // Duy?t và in ra danh sách
    cout << "Danh sach ban dau: ";
    list.traverse();

    // Xóa ph?n t? có giá tr? 20
    cout << "Xoa phan tu 20." << endl;
    list.deleteNode(20);

    // Duy?t và in ra danh sách sau khi xóa
    cout << "Danh sach sau khi xoa: ";
    list.traverse();

    // Xóa ph?n t? có giá tr? 10 (nút d?u tiên)
    cout << "Xoa phan tu 10." << endl;
    list.deleteNode(10);

    // Duy?t và in ra danh sách sau khi xóa
    cout << "Danh sach sau khi xoa: ";
    list.traverse();

    return 0;
}

