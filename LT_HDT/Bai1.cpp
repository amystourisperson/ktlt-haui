#include <iostream>
#include <string>
using namespace std;
class LOPHOC
{
	char TENLOP[30];
	int SOLUONGHS;
	char MALOP[30];
	public:
		void nhap();
		void xuat();
};

void LOPHOC::nhap()
{
	cout<<"\nNhap ten lop: ";
	fflush(stdin);
	gets(TENLOP);
	cout<<"\nNhap so luong hoc sinh trong lop: ";
	fflush(stdin);
	cin>>SOLUONGHS;
	cout<<"\nNhap ma lop (chu + so): ";
	fflush(stdin);
	gets(MALOP);
}

void LOPHOC::xuat()
{
	cout<<"\n--------------\n"<<endl;
	cout<<"\nTen Lop: "<<TENLOP<<endl;
	cout<<"\nSo luong hoc sinh trong lop: "<<SOLUONGHS<<endl;
	cout<<"\nMa lop hoc: "<<MALOP<<endl;
}

class TRUONG
{
	char TENTRUONG[30];
	char MATRUONG[30];
	int SOTRUONGCON;
	LOPHOC x;
	public:
		void nhap();
		void xuat();
};

void TRUONG::nhap()
{
	cout<<"\nNhap ten truong: ";
	fflush(stdin);
	gets(TENTRUONG);
	cout<<"\nNhap ma truong: ";
	fflush(stdin);
	gets(MATRUONG);
	cout<<"\nNhap so truong con: ";
	fflush(stdin);
	cin>>SOTRUONGCON;
	x.nhap();
}

void TRUONG::xuat()
{
	cout<<"\n------------------\n";
	cout<<"\nten truong: "<<TENTRUONG<<endl;
	cout<<"\nma truong: "<<MATRUONG<<endl;
	cout<<"\nso truong con: "<<SOTRUONGCON<<endl;

	x.xuat();
}
int main(){
	TRUONG k;
	k.nhap();
	k.xuat();
}
