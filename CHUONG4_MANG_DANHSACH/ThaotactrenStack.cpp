//Cac thao tac co ban tren Stack
#include <iostream>
using namespace std;

// Khoi tao stack rong
class Cstack {
private:
    int* StkArr;  // Mang luu tru cac phan tu cua stack
    int StkTop;   // Dinh cua stack
    int StkMax;   // Kich thuoc toi da cua stack

public:
    // Constructor Khoi tao stack voi kich thuoc toi da
    Cstack(int size) {
        StkArr = new int[size]; // Cap phat mang
        StkMax = size;          // Gan kick thuoc toi da 
        StkTop = -1;            // Stack rong ban dau
    }

    // Destructor giai phong bo nho da cap phat
    ~Cstack() {
        delete[] StkArr;
    }

    // Kiem tra stack rong
    bool isEmpty() {
        return StkTop == -1;
    }

    // Kiem tra stack day
    bool isFull() {
        return StkTop == StkMax - 1;
    }

    // Thao tac Pob, lay ra mot phan tu tu dinh stack
    bool Pop(int &outitem) {
        if (isEmpty()) {
            cout << "Stack rong, khong lay duoc phan tu" << endl;
            return false; // Stack rong, khong lay ra duoc
        } else {
            outitem = StkArr[StkTop];
            StkTop--;
            cout << "Da lay duoc " << outitem << " ra khoi stack." << endl;
            return true;  // Lay ra thanh cong
        }
    }

    // Thao tac Push, dua mot phan tu vao dinh stack
    bool Push(int initem) {
        if (isFull()) {
            cout << "Stack da day, khong them duoc phan tu vao stack" << endl;
            return false;
        } else {
            StkTop++;  // Tang stack
            StkArr[StkTop] = initem;  // Them phan tu vao danh sach
            cout << "Da them " << initem << " thanh cong vao stack!" << endl;
            return true;  // Them thanh cong
        }
    }
};

int main() {
    int size;
    cout << "Nhap kich thuoc cua Stack: ";
    cin >> size;
    
    Cstack stack(size);  // Tao stack voi kich thuoc nhap vao

    // Them mot phan tu vao stack
    stack.Push(10);
    stack.Push(20);

    // Lay mot phan tu ra khoi stack
    int poppedItem;
    stack.Pop(poppedItem);

    if (stack.isEmpty()) {
        cout << "Stack hien tai dang rong." << endl;
    } else {
        cout << "Stack hien tai khong rong." << endl;
    }

    return 0;
}

