//Cac thao tac co ban tren Queue
#include <iostream>
using namespace std;
//Khoi tao queue rong
class Queue{
	private: 
		int* QArray;
		int QMax;
		int QNumItems;
		int QFront;
		int QRear;
	public:
	Queue (int size){
		QArray = new int [size];
		QMax = size;
		QFront = QRear = -1;//queue rong
		QNumItems = 0;//chua co phan tu nao trong queue
	}
	//Destructor giai phong bo nho cap phat
	Queue(){
		delete[] QArray;
	}
	//Kiem tra queue rong
	bool isEmpty(){
		return QNumItems == 0;//queue rong
	}
	//Kiem tra queue day
	bool isFull(){
		return QNumItems == QMax;//queue day
	}
	//Them mot phan tu vao queue
	bool append (int newitem){
		if(isFull()){
			cout<<"\nQueue day, khong them duoc phan tu vao queue"<<endl;
			return false;
		}else{
			QRear++;
			QArray[QRear] = newitem;//them phan tu vao cuoi queue
			QNumItems++;
			cout<<"\nDa them "<<newitem<<" thanh cong vao Stack";
			return true;//them thanh cong
		}
	}
	//Lay mot phan tu ra khoi queue
	bool take(int itemout){
		if(isEmpty()){
			cout<<"\nQueue rong, khong lay ra duoc phan tu tu queue";
			return false;
		}else{
			itemout = QArray[QFront];//Lay ptu dau ra
			QFront++;
			QNumItems--;
			if(QFront == QMax)
			QFront = QRear = -1;//Quay tro ve dau mang
			return true;//lay thanh cong
		}
	}
};
int main(){
	int size;
    cout << "Nhap kich thuoc cua Queue: ";
    cin >> size;
    Queue queue(size);//Tao queue voi kich thuoc nhap vao
    //Them phan tu vao queue
    queue.append(10);
    queue.append(20);
    //Lay phan tu ra khoi queue
    int takeitem;
    queue.take(takeitem);
    
    if(queue.isEmpty()){
    	cout<<"\nQueue hien dang rong!";
	}else{
		cout<<"\nQueue hien khong rong";
	}
	return 0;
    
}
