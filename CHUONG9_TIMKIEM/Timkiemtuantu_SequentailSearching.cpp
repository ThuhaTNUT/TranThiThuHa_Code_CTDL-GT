#include <iostream>
#include <vector>
using namespace std;

int SEQUEN_SEARCH(const vector<int>& k, int n, int X) {
    int i = 0;                 // Buoc 1: Khoi dau
    vector<int> arr = k;       // Sao chep mang de khong anh huong den du lieu goc
    arr.push_back(X);          // Them X vao vi tri cuoi mang de dung vong lap neu khong tim thay
    
    while (arr[i] != X) {      // Buoc 2: Tim khoa trong day
        i++;
    }

    if (i == n) {               // Buoc 3: Kiem tra ket qua
        return 0;               // Neu khong tim thay
    } else {
        return i + 1;           // Tra ve vi tri tim thay (bat dau tu 1)
    }
}

int main() {
    int n, X;
    
    // Nhap kich thuoc cua mang
    cout << "Nhap so phan tu trong mang: ";
    cin >> n;

    vector<int> k(n);
    
    // Nhap cac phan tu cua mang
    cout << "Nhap cac phan tu trong mang: ";
    for (int i = 0; i < n; i++) {
        cin >> k[i];
    }
    
    // Nhap gia tri X can tim
    cout << "Nhap phan tu can tim X: ";
    cin >> X;

    int result = SEQUEN_SEARCH(k, n, X);
    if (result == 0) {
        cout << "Khong tim thay phan tu " << X << " trong mang." << endl;
    } else {
        cout << "Phan tu " << X << " duoc tim thay tai vi tri: " << result << endl;
    }
    
    return 0;
}

