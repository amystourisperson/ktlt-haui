#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
class VE
{
	protected:
	float GIAGOC;
	char NGAY[30];
	public:
		void nhap();
		void xuat();
};

void VE::nhap()
{
	cout<<"\nNhap gia goc: ";
	cin>>GIAGOC;
	cout<<"\nNhap ngay: ";
	fflush(stdin);
	gets(NGAY);
}

void VE::xuat(){
	cout<<"\nGia goc = "<<GIAGOC<<setw(15)<<"Ngay: "<<NGAY<<endl;
}

class VENGUOILON : public VE
{
	float GIAM;
	float GIAVE;
	public:
		void nhap();
		void xuat();
};

void VENGUOILON::nhap()
{
	VE::nhap();
	cout<<"\nGIAM (%): ";
	cin>>GIAM;
	cout<<"\nGIAVE: ";
	cin>>GIAVE;
}
void VENGUOILON::xuat()
{
	VE::xuat();
	cout<<"\nGiam: "<<GIAM<<endl;
	cout<<"\nGia ve: "<<GIAVE<<endl;
}

class VETREEM : public VE
{
	float GIAM;
	float GIAVE;
	public:
		void nhap();
		void xuat();
};

void VETREEM::nhap()
{
	VE::nhap();
	cout<<"\nGIAM (%): ";
	cin>>GIAM;
	cout<<"\nGIAVE: ";
	cin>>GIAVE;
}

void VETREEM::xuat()
{
	VE::xuat();
	cout<<"\nGiam: "<<GIAM<<endl;
	cout<<"\nGia ve: "<<GIAVE<<endl;
}
int main(){
	VENGUOILON x;
	VETREEM y;
	cout<<"\nVe nguoi lon"<<endl;
	x.nhap();
	x.xuat();
	cout<<"\nVe tre em"<<endl;
	y.nhap();
	y.xuat();
}
