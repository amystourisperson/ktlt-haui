#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class NHANVIEN
{
	char HOTEN[30];
	char CHUCVU[30];
	public:
		void nhap();
		void xuat();
};

void NHANVIEN::nhap()
{
	cout<<"\nNhap Ho va Ten nhan vien: ";
	fflush(stdin);
	gets(HOTEN);
	cout<<"\nNhap chuc vu nhan vien: ";
	fflush(stdin);
	gets(CHUCVU);
}

void NHANVIEN::xuat()
{
	cout<<"\nNhan vien kiem ke: "<<HOTEN<<setw(15)<<"Chuc vu: "<<CHUCVU<<endl;	
}

class PHONG
{
	char MAP[30];
	char TENPHONG[30];
	char TENTP[30];
	public:
		void nhap();
		void xuat();
};

void PHONG::nhap()
{
	cout<<"\nNhap ma phong: ";
	fflush(stdin);
	gets(MAP);
	cout<<"\nNhap ten phong: ";
	fflush(stdin);
	gets(TENPHONG);
	cout<<"\nNhap ten truong phong: ";
	fflush(stdin);
	gets(TENTP);
}

void PHONG::xuat()
{
	cout<<"\nKiem ke tai phong: "<<TENPHONG<<setw(15)<<"Ma phong: "<<MAP<<endl;
	cout<<"\nTruong phong: "<<TENTP<<endl;
}

class TAISAN
{
	char TENTS[30];
	int SOLUONG;
	char TINHTRANG[30];
	public:
		void nhap();
		void xuat();
		friend class PHIEU;
};

void TAISAN::nhap()
{
	cout<<"\nNhap ten tai san: ";
	fflush(stdin);
	gets(TENTS);
	cout<<"\nNhap so luong: ";
	fflush(stdin);
	cin>>SOLUONG;
	cout<<"\nNhap tinh trang: ";
	fflush(stdin);
	gets(TINHTRANG);
}

void TAISAN::xuat()
{
	cout<<TENTS<<setw(20)<<SOLUONG<<setw(25)<<TINHTRANG<<endl;
}

class PHIEU
{
	char MAPH[30];
	char NGAY[30];
	NHANVIEN x;
	PHONG y;
	TAISAN *z;
	int n;
	public:
		void nhap();
		void xuat();
};

void PHIEU::nhap()
{
	cout<<"\nNhap ma phieu: ";
	fflush(stdin);
	gets(MAPH);
	cout<<"\nNhap ngay kiem ke: ";
	fflush(stdin);
	gets(NGAY);
	cout<<"\nNhap so tai san: ";
	cin>>n;
	z=new TAISAN[n];
	x.nhap();
	y.nhap();
	for(int i=0;i<n;i++)
	{
		z[i].nhap();
	}
}
void PHIEU::xuat()
{
	cout<<setw(40)<<"PHIEU KIEM KE TAI SAN"<<endl;
	cout<<"\nMa phieu: "<<MAPH<<setw(15)<<"Ngay kiem ke: "<<NGAY<<endl;
	x.xuat();
	y.xuat();
	cout<<"Ten tai san"<<setw(20)<<"So luong"<<setw(25)<<"Tinh trang"<<endl;

	for(int i=0;i<n;i++)
	{
		z[i].xuat();
	}
	cout<<"\nSo tai san da kiem ke: "<<n;
	int T=0;
	for(int i=0;i<n;i++)
	{
		T=T+z[i].SOLUONG;
	}
	cout<<"     Tong so luong: "<<T<<endl;
}
int main(){
	PHIEU k;
	k.nhap();
	k.xuat();
}
