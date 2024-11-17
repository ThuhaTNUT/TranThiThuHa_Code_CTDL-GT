//Bieu dien so nguyen 95 sang nhi phan theo co che hoat dong cua Stack
#include <iostream>
#include <stack>  
using namespace std;

// Ham chuyen doi so nguyen sang so nhi phan theo co che stack
void decimalToBinary(int n) {
    stack<int> binaryStack;  // Tao stack luu tru phan du

    // Chia 2 va luu phan du vao stack
    while (n > 0) {
        int remainder = n % 2;
        binaryStack.push(remainder);  //Day phan du vao stack
        n = n / 2;
    }

    // In ra kq nhi phan bang cach lay phan tu ra khoi Stack
    cout << "So nhi phan la: ";
    while (!binaryStack.empty()) {
        cout << binaryStack.top();  // Lay phan tu tren dinh stack
        binaryStack.pop();  // Xoa phan tu khoi stack
    }
    cout << endl;
}

int main() {
    int n;  
    cout<<"Nhap so thap phan n = ";
    cin>>n;
    decimalToBinary(n);  // Goi ham chuyen doi va in ket qua ra man hinh

    return 0;
}

