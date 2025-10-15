#include <iostream>
#include <string.h>
#include <iomanip>
using namespace std;
class NSX{
	private:
		char TenNSX[30];
		char DiaChi[30];
	public:
		void nhap();
		void xuat();
};
void NSX::nhap(){
	cout<<"\nNhap ten NSX: "; fflush(stdin); gets(TenNSX);
	cout<<"\nNhap dia chi: "; fflush(stdin); gets(DiaChi);
}

void NSX::xuat(){
	cout<<"\nTen NSX: "<<TenNSX <<setw(15)<<"Dia chi: "<<DiaChi<<endl;
}

class DATE{
	private: 
		char D[30];
		char M[30];
		char Y[30];
	public:
		void nhap();
		void xuat();	
	
};
void DATE::nhap(){
	cout<<"\nNhap Day: "; fflush(stdin); gets(D);
	cout<<"\nNhap Month: "; fflush(stdin); gets(M);
	cout<<"\nNhap Year: "; fflush(stdin); gets(Y);
}
void DATE::xuat(){
	cout<<"\nNgay "<<D<<" Thang "<<M<<" Nam "<<Y<<endl;
}

class HANG{
	protected:
		char TenHang[30];
		int DonGia;
		NSX x;
	public:
		void nhap();
		void xuat();
		HANG();
};

void HANG::nhap(){
	cout<<"\nNhap ten hang: "; fflush(stdin); gets(TenHang);
	cout<<"\nNhap don gia: "; cin>>DonGia;
	x.nhap();
}

void HANG::xuat(){
	cout<<"\nTen Hang: "<<TenHang;
	cout<<"\nDon gia: "<<DonGia;
	x.xuat();
}

HANG::HANG(){
	strcpy(TenHang , " ");
	DonGia = 0;
}

class TIVI : public HANG{
	private: 
		int KichThuoc;
		DATE NgayNhap;
	public:
		void nhap();
		void xuat();
		TIVI();
};

void TIVI::nhap(){
	HANG::nhap();
	cout<<"\nNhap kich thuoc: "; cin>>KichThuoc;
	NgayNhap.nhap();
}

void TIVI::xuat(){
	HANG::xuat();
	cout<<"\nKich thuoc tivi la: "<<KichThuoc<<endl;
	NgayNhap.xuat();
}

TIVI::TIVI() : HANG()
{
	KichThuoc = 0;
}
int main(){
	TIVI k;
	k.nhap();
	k.xuat();
}
