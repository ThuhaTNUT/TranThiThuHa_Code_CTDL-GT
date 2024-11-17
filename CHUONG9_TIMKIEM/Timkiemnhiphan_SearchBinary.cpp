#include <iostream>
#include <vector>
using namespace std;

int binarySearch(vector<int>& k, int n, int X) {
    int l = 0;  // Chi so bat dau (l) cua mang
    int r = n - 1;  // Chi so cuoi (r) cua mang
    int m;

    while (l <= r) {
        m = (l + r) / 2;  // Tinh chi so giua m

        if (X < k[m]) {
            r = m - 1;  // Neu X nho hon phan tu giua, tim trong nua trai
        } else if (X > k[m]) {
            l = m + 1;  // Neu X lon hon phan tu giua, tim trong nua phai
        } else {
            return m;  // Neu tim thay X, tra ve chi so cua no
        }
    }

    return -1;  // Neu khong tim thay X trong mang
}

int main() {
    int n, X;

    // Nhap so luong phan tu cua mang
    cout << "Nhap so luong phan tu cua mang: ";
    cin >> n;

    vector<int> k(n);

    // Nhap cac phan tu cua mang da sap xep
    cout << "Nhap " << n << " phan tu cua mang (da sap xep):" << endl;
    for (int i = 0; i < n; i++) {
        cin >> k[i];
    }

    // Nhap gia tri X can tim
    cout << "Nhap gia tri X can tim: ";
    cin >> X;

    // Tim kiem nhi phan
    int result = binarySearch(k, n, X);

    if (result != -1) {
        cout << "Gia tri " << X << " duoc tim thay tai chi so " << result << endl;
    } else {
        cout << "Gia tri " << X << " khong co trong mang." << endl;
    }

    return 0;
}

