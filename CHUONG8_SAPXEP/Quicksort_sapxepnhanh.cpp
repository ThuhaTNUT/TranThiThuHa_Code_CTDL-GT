//Chuong 8. Sap xep nhanh Quicksort
#include <iostream>
using namespace std;

// Ham nhap mang
void Nhapmang(int a[], int n) {
    for(int i = 0; i < n; i++) {
        cout << "a[" << i << "] = ";
        cin >> a[i];
    }
}

// Ham xuat mang
void Xuatmang(int a[], int n) {
    for(int i = 0; i < n; i++) {
        cout <<a[i]<<" ";
    }
}

// Ham sap xep Quicksort 
void Quicksort(int a[], int l, int r) {
    int i = l, j = r;
    int x = a[(l + r) / 2];  // Chon phan tu o giua lam chot
    do{
		while(a[i] < x) i++;  // Tim phan tu lon hon hoac bang chot tu trai sang phai
        while(a[j] > x) j--;  // Tim phan tu nho hon hoac bang chot tu phai sang trai
        if(i <= j){
        	int tmp;
        	tmp = a[i];
        	a[i] = a[j];
        	a[j] = tmp;
        	i++;
        	j--;
		}
    }while(i <= j);

    // De quy sap xep hai phan
    if(l < j) Quicksort(a, l, j);  // Sap xep phan ben trai
    if(i < r) Quicksort(a, i, r);  // Sap xep phan ben phai
}


int main() {
    int a[100], n;
    cout << "Nhap so phan tu cua mang: n = ";
    cin >> n;
    cout << "\nNhap mang " << n << " phan tu: " << endl;
    Nhapmang(a, n);
    
    cout << "\nMang truoc khi sap xep: " << endl;
    Xuatmang(a, n);
    
    // Goi ham Quicksort sap xep mag
    Quicksort(a, 0, n - 1);
    
    cout << "\nMang sau khi sap xep: " << endl;
    Xuatmang(a, n);
    
    return 0;
}

