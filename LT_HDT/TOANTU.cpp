#include <iostream>
#include <string.h>
#include <math.h>
using namespace std;
class PHANSO{
	private:
		float tu;
		float mau;
	public:
		friend istream& operator>>(istream& in, PHANSO &x);
		friend ostream& operator<<(ostream& out, PHANSO x);
		PHANSO operator + (PHANSO x);
		PHANSO operator - (PHANSO x);
		PHANSO operator * (PHANSO x);
		PHANSO operator / (PHANSO x);
};

istream& operator>>(istream& in, PHANSO &x){
	cout<<"\nNhap tu so: "; in>>x.tu;
	cout<<"\nNhap mau so: "; in>>x.mau;
	return in;
}

ostream& operator<<(ostream& out, PHANSO x){
	out<<x.tu<<"/"<<x.mau<<endl;
	return out;
}

PHANSO PHANSO::operator *(PHANSO x) //nhan 2 phan so tra ve la phan so
{
	PHANSO k;
	k.tu = tu*x.tu;
	k.mau = mau*x.mau;
	return k;
}

PHANSO PHANSO::operator + (PHANSO x){
	PHANSO k;
	k.tu = tu*x.mau + mau *x.tu;
	k.mau = mau * x.mau;
	return k;	
}

PHANSO PHANSO::operator -(PHANSO x){
	PHANSO k;
	k.tu = tu*x.mau - mau *x.tu;
	k.mau = mau * x.mau;
	return k;
}

PHANSO PHANSO::operator /(PHANSO x){
	PHANSO k;
	k.tu = tu * x.mau;
	k.mau = mau * x.tu;
	return k;
}
int main(){
	PHANSO z,t;
	cout<<"\nNhap gia tri cho phan so thu 1: "<<endl;
	cin>>z;
	cout<<"\nNhap gia tri cho phan so thu 2: "<<endl;
	cin>>t;
	cout<<"\nCong = "<<z + t;
	cout<<"\nTru = "<<z - t;
	cout<<"\nNhan =  "<<z*t;
	cout<<"\nChia = "<<z/t;
}
