#include <iostream>
using namespace std;

// Cau truc Node
struct Node {
    int data;
    Node* next;

    // Constructor khoi tao
    Node(int value) {
        data = value;
        next = NULL;
    }
};

// Cau truc danh sach moc noi don
class LinkedList {
public:
    Node* head;

    // Constructor
    LinkedList() {
        head = NULL;
    }

    // Them phan tu vao dau danh sach
    void insertAtHead(int value) {
        Node* newNode = new Node(value);
        newNode->next = head;
        head = newNode;
    }

    // Them phan tu vao cuoi danh sach
    void insertAtTail(int value) {
        Node* newNode = new Node(value);
        if (head == NULL) {  // Danh sach rong
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newNode;  // Nguoi cuoi cung tro den node moi
        }
    }

    // Duyet va in ra danh sach
    void traverse() {
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    // Xoa phan tu khoi danh sach
    void deleteNode(int value) {
        // Truong hop danh sach rong
        if (head == NULL) {
            cout << "Danh sach rong, khong the xoa." << endl;
            return;
        }

        // Truong hop xoa nut dau tien
        if (head->data == value) {
            Node* temp = head;
            head = head->next;  // Cap nhat head tro den nut tiep theo
            delete temp;  // Giai phong bo nho
            return;
        }

        // Duyet danh sach de tim nut can xoa
        Node* current = head;
        while (current->next != NULL && current->next->data != value) {
            current = current->next;
        }

        // Neu khong tim thay nut can xoa
        if (current->next == NULL) {
            cout << "Khong tim thay gia tri " << value << " trong danh sach." << endl;
            return;
        }

        // Truong hop xoa nut o giua hoac cuoi danh sach
        Node* temp = current->next;
        current->next = current->next->next;  // Cap nhat con tro cua nut truoc
        delete temp;  // Giai phong bo nho
    }
    
    //chen mot phan tu sau mot gia tri cho truoc
    void insertAfter(int target, int value) {
        Node* temp = head;
        while (temp != NULL && temp->data != target) {
            temp = temp->next;
        }

        if (temp != NULL) {  // Tim thay gia tri can chen sau
            Node* newNode = new Node(value);
            newNode->next = temp->next;
            temp->next = newNode;
        } else {
            cout << "Gia tri " << target << " khong ton tai trong danh sach." << endl;
        }
    }

};

int main() {
    LinkedList list;

    // Them cac phan tu vao dau danh sach
    list.insertAtHead(10);
    list.insertAtHead(5);
    list.insertAtHead(8);
    list.insertAtHead(9);

    // Duyet va in ra danh sach
    cout << "Danh sach ban dau: ";
    list.traverse();

    // Them phan tu vao cuoi danh sach
    cout << "Them phan tu 50 vao cuoi danh sach." << endl;
    list.insertAtTail(50);
    list.traverse();

    // Them phan tu vao cuoi danh sach
    cout << "Them phan tu 60 vao cuoi danh sach." << endl;
    list.insertAtTail(60);
    list.traverse();
    
    // //chen mot phan tu sau mot gia tri cho truoc
    list.insertAfter(10, 15);
    cout << "Danh sach sau khi chen phan tu 15 sau phan tu 10: ";
    list.traverse();

    // Xoa phan tu co gia tri 20
    cout << "Xoa phan tu 20." << endl;
    list.deleteNode(20);
    list.traverse();

    return 0;
}

