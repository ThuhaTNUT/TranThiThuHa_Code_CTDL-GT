//Chuong 8 Sap xep noi bot bubble sort
#include <iostream>
using namespace std;
//Ham nhap mang
void Nhapmang(int a[], int &n) {
    for(int i = 0; i < n; i++) {
        cout << "a[" << i << "] = ";
        cin >> a[i];
    }
}
//Ham xuat mang
void Xuatmang(int a[], int n) {
    for(int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}
//Ham sap xep bubble sort tang dan
void bublesort(int a[], int n){
	int tmp;
	for(int i = 0; i<n; i++){
		for(int j = 0; j<n-i-1; j++){
			if(a[j+1] < a[j]){
				tmp = a[j+1];
				a[j+1] = a[j];
				a[j] = tmp;
			}
		}
	}
}
int main(){
	int a[100], n;
	cout<<"Nhap so phan tu n: "; cin>>n;
	cout << "\nNhap mang: "<<endl;
    Nhapmang(a, n);

    cout << "\nMang ban dau: ";
    Xuatmang(a, n);

    // Goi ham sap xep
    bublesort(a, n);

    cout << "\nMang sau khi sap xep: ";
    Xuatmang(a, n);
	
}
