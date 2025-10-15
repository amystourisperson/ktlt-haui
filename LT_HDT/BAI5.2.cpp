#include <iostream>
#include <string.h>
#include <math.h>
using namespace std;
class SOPHUC{
	private:
		int thuc;
		int ao;
	public:
		SOPHUC();
		SOPHUC(int a, int b);
		friend ostream& operator<<(ostream& out, SOPHUC x);
		SOPHUC operator+(SOPHUC x);
		SOPHUC operator-(SOPHUC x);
}; 

SOPHUC::SOPHUC(){
	thuc = 0;
	ao = 0;
}

SOPHUC::SOPHUC(int a, int b){
	thuc = a;
	ao = b;
}

ostream& operator<<(ostream& out, SOPHUC x){
	out<<x.thuc<<"+i*"<<x.ao<<endl;
	return out;
}

SOPHUC SOPHUC::operator+(SOPHUC x){
	SOPHUC k;
	k.thuc = thuc + x.thuc;
	k.ao = ao + x.ao;
	return k;
}

SOPHUC SOPHUC::operator-(SOPHUC x){
	SOPHUC k;
	k.thuc = thuc - x.thuc;
	k.ao = ao - x.ao;
	return k;
}
int main(){
	SOPHUC z(3,2);
	SOPHUC t(1,4);
	SOPHUC sp3 = z + t;
	SOPHUC sp4 = z - t;
	cout<<"\nTong 2 so phuc = "<<sp3;
	cout<<"\nHieu 2 so phuc = "<<sp4;	
}
