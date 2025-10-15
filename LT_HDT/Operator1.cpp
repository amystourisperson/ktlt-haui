#include <iostream>
using namespace std;

class TTB2{
	int a, b,c;
	public:
		void nhap();
		void xuat();
		TTB2 operator + (TTB2 Q);
		friend ostream& operator<<(ostream out, TTB2 x);
};

TTB2 TTB2::operator +(TTB2 Q){
	TTB2 K;
	K.a = a + Q.a;
	K.b = b + Q.b;
	K.c = c + Q.c;
	return K;
}

void TTB2::nhap(){
	cout<<"\nNhap a = "; cin>>a;
	cout<<"\nNhap b = "; cin>>b;
	cout<<"\nNhap c = "; cin>>c;
}

void TTB2::xuat(){
	cout<<"\n a = "<<a;
	cout<<"\n b = "<<b;
	cout<<"\n c = "<<c;
}

ostream &operator<<(ostream out, TTB2 x){
	out<<"\n a = "<<x.a<<"b = "<<x.b<<"c = "<<x.c<<endl;
	return out;
}

int main(){
	TTB2 x,y;
	x.nhap();
	x.xuat();
	y.nhap();
	y.xuat();
	
	cout<<"\n a+b = "<<x + y;
}
