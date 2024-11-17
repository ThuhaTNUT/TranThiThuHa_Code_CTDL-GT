#include <iostream>
using namespace std;

// Ham nhap mang
void nhapmang(int arr[], int &n) {
    cout << "Nhap so luong phan tu cua mang: ";
    cin >> n; // Cho phep nguoi dung nhap so luong phan tu
    cout << "Nhap cac phan tu cua mang: " << endl;
    for (int i = 0; i < n; i++) {
        cout << "a[" << i << "] = ";
        cin >> arr[i];
    }
    cout << endl;
}

// Ham hien thi mang
void hienThiMang(int arr[], int n) {
    if (n == 0) {
        cout << "Mang dang rong!" << endl;
        return;
    }
    cout << "Mang hien tai: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// Ham tim kiem tuyen tinh trong mang
int timKiem(int arr[], int n, int x) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == x)
            return i; // Tra ve vi tri tim thay
    }
    return -1; // Tra ve -1 neu khong tim thay
}

// Ham chen phan tu vao mang
void chenPhanTu(int arr[], int& n, int value, int pos) {
    if (pos < 0 || pos > n) {
        cout << "Vi tri khong hop le!" << endl;
        return;
    }
    for (int i = n; i > pos; i--) {
        arr[i] = arr[i - 1];
    }
    arr[pos] = value;
    n++;
}

// Ham xoa phan tu trong mang
void xoaPhanTu(int arr[], int& n, int pos) {
    if (pos < 0 || pos >= n) {
        cout << "Vi tri khong hop le!" << endl;
        return;
    }
    for (int i = pos; i < n - 1; i++) {
        arr[i] = arr[i + 1];
    }
    n--;
}

// Ham sap xep tang dan (Bubble Sort)
void sapXepTangDan(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Chuong trinh chinh
int main() {
    int arr[100]; // Mang co kich thuoc toi da 100
    int n = 0;    // So luong phan tu trong mang

    int luaChon;
    do {
        system("cls");
        cout << "\n========== MENU ==========" << endl;
        cout << "1. Nhap mang" << endl;
        cout << "2. Xuat mang" << endl;
        cout << "3. Chen phan tu vao mang" << endl;
        cout << "4. Xoa phan tu khoi mang" << endl;
        cout << "5. Tim kiem phan tu trong mang" << endl;
        cout << "6. Sap xep mang tang dan" << endl;
        cout << "7. Thoat" << endl;
        cout << "Nhap lua chon cua ban: ";
        cin >> luaChon;

        switch (luaChon) {
            case 1: // Nhap mang
                system("cls");
                nhapmang(arr, n);
                break;

            case 2: // Hien thi mang
                system("cls");
                hienThiMang(arr, n);
                system("pause"); // T?m d?ng d? ngu?i dùng xem k?t qu?
                break;

            case 3: { // Chen phan tu vao mang
                int value, pos;
                cout << "Nhap gia tri muon chen: ";
                cin >> value;
                cout << "Nhap vi tri muon chen (0 - " << n << "): ";
                cin >> pos;
                chenPhanTu(arr, n, value, pos);
                break;
            }

            case 4: { // Xoa phan tu khoi mang
                int pos;
                cout << "Nhap vi tri muon xoa (0 - " << n - 1 << "): ";
                cin >> pos;
                xoaPhanTu(arr, n, pos);
                break;
            }

            case 5: { // Tim kiem phan tu
                int x;
                cout << "Nhap gia tri can tim: ";
                cin >> x;
                int viTri = timKiem(arr, n, x);
                if (viTri != -1)
                    cout << "Tim thay " << x << " o vi tri: " << viTri << endl;
                else
                    cout << x << " khong co trong mang." << endl;
                hienThiMang(arr, n);
                system("pause"); 
                break;
                
            }

            case 6: // Sap xep mang tang dan
                sapXepTangDan(arr, n);
                cout<<"Mang sau khi duoc sap xep: ";
                hienThiMang(arr, n);
                system("pause"); 
                break;

            case 7: // Thoat
                cout << "Thoat chuong trinh." << endl;
                break;

            default:
                cout << "Lua chon khong hop le!" << endl;
                break;
        }
    } while (luaChon != 7);

    return 0;
}

