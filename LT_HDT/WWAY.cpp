/*
#include <iostream>
#include <string>
using namespace std;
class TRUONG;
class LOPHOC
{
	char TENLOP[30];
	int SOHS;
	char MALOP[30];
	public:
		friend class TRUONG;
		friend void Sapxep(TRUONG k);

};

class TRUONG
{
	char TENTRUONG[30];
	char MATRUONG[30];
	int n;
	LOPHOC *x;
	public:
		void nhap();
		void xuat();
		friend void Sapxep(TRUONG k);
};

void TRUONG::nhap()
{
	cout<<"\nNhap ten truong: ";
	fflush(stdin);
	gets(TENTRUONG);
	cout<<"\nNhap ma truong: ";
	fflush(stdin);
	gets(MATRUONG);
	cout<<"\nNhap n: ";
	cin>>n;
	x=new LOPHOC[n];
	for(int i=0;i<n;i++)
	{
		cout<<"\nNhap ten lop: ";
		fflush(stdin);
		gets(x[i].TENLOP);
		cout<<"\nNhap so hoc sinh trong lop: ";
		fflush(stdin);
		cin>>x[i].SOHS;
		cout<<"\nNhap ma lop (chu +  so): ";
		fflush(stdin);
		gets(x[i].MALOP);
	}
}

void TRUONG::xuat()
{
	cout<<"\n-----------------------\n";
	cout<<"\nTen truong la: "<<TENTRUONG<<endl;
	cout<<"\nMa truong la: "<<MATRUONG<<endl;
	cout<<"\nn= "<<n;
	cout<<"\n------------------------\n";
	for(int i=0;i<n;i++)
	{
		cout<<"\nLop: "<<x[i].TENLOP<<" --- So hoc sinh trong lop la: "<<x[i].SOHS<<" ---Ma lop: "<<x[i].MALOP<<endl;
	}
}

void Sapxep(TRUONG k)
{
	for(int i=0;i<k.n;i++)
	{
		for(int j=i+1;j<k.n;j++)
		{
			if(k.x[i].SOHS>k.x[j].SOHS)
			{
				swap(k.x[i],k.x[j]);
			}
		}
	}
}
int main(){
	TRUONG k;
	k.nhap();
	k.xuat();
	Sapxep(k);
	cout<<"\nSau khi sap xep\n";
	k.xuat();
}
*/
#include <iostream>
#include <string>
#include <iomanip>
#include <string.h>
using namespace std;
class PHIEU;
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
	cout<<"\nNhap ho ten nhan vien: ";
	fflush(stdin);
	gets(HOTEN);
	cout<<"\nNhap chuc vu nhan vien: ";
	fflush(stdin);
	gets(CHUCVU);
}

void NHANVIEN::xuat()
{
	cout<<"\nNhan vien kiem ke: "<<HOTEN<<setw(20)<<"Chuc vu: "<<CHUCVU<<endl;
}

class PHONG
{
	char MAP[30];
	char TENP[30];
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
	gets(TENP);
	cout<<"\nNhap ten truong phong: ";
	fflush(stdin);
	gets(TENTP);
}

void PHONG::xuat()
{
	cout<<"\nKiem ke tai phong: "<<TENP<<setw(20)<<"Ma phong: "<<MAP<<endl;
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
		friend void TIMKIEM(PHIEU k);
		friend void SAPXEP(PHIEU k); 
};

void TAISAN::nhap()
{
	cout<<"\nNhap ten tai san: ";
	fflush(stdin);
	gets(TENTS);
	cout<<"\nNhap so luong: ";
	cin>>SOLUONG;
	cout<<"\nNhap tinh trang: ";
	fflush(stdin);
	gets(TINHTRANG);
}

void TAISAN::xuat()
{
	cout<<TENTS<<setw(25)<<SOLUONG<<setw(25)<<TINHTRANG<<endl;
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
		friend void TIMKIEM(PHIEU k);
		friend void SAPXEP(PHIEU k);
};

void PHIEU::nhap()
{
	cout<<"\nNhap ma phieu: ";
	fflush(stdin);
	gets(MAPH);
	cout<<"\nNhap ngay: ";
	fflush(stdin);
	gets(NGAY);
	x.nhap();
	y.nhap();
	cout<<"\nNhap so san pham: ";
	cin>>n;
	z=new TAISAN[n];
	for(int i=0;i<n;i++)
	{
		z[i].nhap();
	}
}

void PHIEU::xuat()
{
	cout<<setw(45)<<"PHIEU KIEM KE TAI SAN"<<endl;
	cout<<"\nMa phieu: "<<MAPH<<setw(20)<<"Ngay kiem ke: "<<NGAY<<endl;
	x.xuat();
	y.xuat();
	cout<<"Ten tai san"<<setw(25)<<"So luong"<<setw(25)<<"Tinh trang"<<endl;
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
	cout<<"       Tong so luong: "<<T<<endl;
}

//tim kiem
void TIMKIEM(PHIEU k)
{
	int dem=0;
	for(int i=0;i<k.n;i++)
	{
		if(strcmp(k.z[i].TENTS,"May tinh")==0)
		{
			dem++;
		}
	}
	cout<<"\n--------------------------\n";
	if(dem==0)
	{
		cout<<"\n-> Khong co 'May tinh' trong phieu"<<endl;
	}
	else
	{
		cout<<"\n-> Co 'May tinh' trong phieu"<<endl;
	}
}
//sap xep
void SAPXEP(PHIEU k)
{
	for(int i=0;i<k.n;i++)
	{
		for(int j=i+1;j<k.n;j++)
		{
			if(k.z[i].SOLUONG>k.z[j].SOLUONG)
			{
				swap(k.z[i],k.z[j]);
			}
		}
	}
}

int main(){
	PHIEU k;
	k.nhap();
	k.xuat();
	TIMKIEM(k);
	cout<<"\n---------------------\n";
	cout<<"\nPhieu cua ban sau khi sap xep"<<endl;
	SAPXEP(k);
	k.xuat();
}
