//Chuong 8 SAP XEP CHEN TOAN TU INSERTION SORT
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
//Ham sap xep chen insertion sort
void insertsort(int a[], int n){
	int x, i, j;
	for(int i = 1; i<n; i++){
		x = a[i];
		j = i-1;
		while(x < a[j] && (j >= 0)){
			a[j+1] = a[j];
			j = j -1;
			
		}
		a[j + 1] = x;
	}
}
int main (){
	int a[100], n;
	cout<<"Nhap so phan tu n: "; cin>>n;
	cout << "\nNhap mang: "<<endl;
    Nhapmang(a, n);

    cout << "\nMang ban dau: ";
    Xuatmang(a, n);

    // Goi ham sap xep
    insertsort(a, n);

    cout << "\nMang sau khi sap xep: ";
    Xuatmang(a, n);
}
