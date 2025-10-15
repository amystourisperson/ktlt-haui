#include <iostream>
#include <iomanip>
#include <string.h>
#include <fstream>
using namespace std;
class PHANSO{
	private:
		int tu;
		int mau;
	public:
		PHANSO();
		PHANSO(int a, int b);
		PHANSO operator*(PHANSO x);
		float operator!();
		friend istream& operator>>(istream& in, PHANSO &x);
		friend ostream& operator<<(ostream& out, PHANSO x);
};

PHANSO::PHANSO(){
	tu = 0;
	mau = 1;  //mau so != 0
}

PHANSO::PHANSO(int a, int b){
	tu = a;
	mau = b;
}

PHANSO PHANSO::operator*(PHANSO x){
	PHANSO k;
	k.tu = tu * x.tu;
	k.mau = mau * x.mau;
	return k;
}

float PHANSO::operator!(){
	return (1.0*tu/mau); //chu y ep kieu
}

istream& operator>>(istream& in, PHANSO &x){
	cout<<"\nNhap tu so: "; in>>x.tu;
	cout<<"\nNhap mau so: "; in>>x.mau;
	return in;
}

ostream& operator<<(ostream& out, PHANSO x){
	out<<x.tu<<"/"<<x.mau<<endl;
	return out;
}

int main(){
	PHANSO z;
	PHANSO t(1,1);
	cout<<"\nNhap gia tri cho phan so thu 1: "<<endl;
	cin>>z;
	cout<<"\nNhap gia tri cho phan so thu 2: "<<endl;
	cin>>t;
	ofstream f("PHANSO.txt", ios::app);
	PHANSO tich = z*t;
	cout<<"\nTich 2 phan so = "<<tich<<endl;
	f<<"\nTich 2 phan so = "<<tich<<endl;
	
	cout<<"\nGia tri thuc = "<<!(tich);
	f<<"\nGia tri thuc = "<<!(tich);
	
	f.close();	
}
