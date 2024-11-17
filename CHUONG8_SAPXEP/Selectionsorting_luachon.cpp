//Chuong 8 sap xep lua chon
#include <iostream>
using namespace std;

void Nhapmang(int a[], int &n) {
    for(int i = 0; i < n; i++) {
        cout << "a[" << i << "] = ";
        cin >> a[i];
    }
}

void Xuatmang(int a[], int n) {
    for(int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}

// Thuat toan sap xep Selection Sort (Sap xep tang dan)
void Selectionsorting(int a[], int n) {
    int tmp;
    for(int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for(int j = i + 1; j < n; j++) {
            if(a[minIndex] > a[j]) {
                minIndex = j;
            }
        }
        // Hoan doi gia tri i voi minIndex
        tmp = a[minIndex];
        a[minIndex] = a[i];
        a[i] = tmp;
    }
}

int main() {
    int a[100], n;
    cout << "Nhap so phan tu cua mang: n = "; 
    cin >> n;

    cout << "\nNhap mang: ";
    Nhapmang(a, n);

    cout << "\nMang ban dau: ";
    Xuatmang(a, n);

    //Goi ham sap xep
    Selectionsorting(a, n);

    cout << "\nMang sau khi sap xep: ";
    Xuatmang(a, n);

    return 0;
}

