#include <iostream>
#include <iomanip>
#include <string.h>
using namespace std;

class NHANVIEN{
	private:
	char TENNV[30];
	char CHUCVU[30];
	public:
		void nhap();
		void xuat();
};

void NHANVIEN::nhap(){
	cout<<"\nNhap ten nhan vien kiem ke: "; fflush(stdin); gets(TENNV);
	cout<<"\nNhap chuc vu: "; fflush(stdin); gets(CHUCVU);
}

void NHANVIEN::xuat(){
	cout<<"\nNhan vien kiem ke: "<<TENNV<<setw(20)<<"Chuc vu: "<<CHUCVU;
}

class PHONG{
	private:
	char PHONGKIEMKE[30];
	char MAPH[30];
	char TPH[30];
	public:
		void nhap();
		void xuat();
};

void PHONG::nhap(){
	cout<<"\nNhap phong kiem ke: "; fflush(stdin); gets(PHONGKIEMKE);
	cout<<"\nNhap ma phong: "; fflush(stdin); gets(MAPH);
	cout<<"\nNhap ten truong phong: "; fflush(stdin); gets(TPH);
}

void PHONG::xuat(){
	cout<<"\nKiem ke tai phong: "<<PHONGKIEMKE<<setw(20)<<"Ma phong: "<<MAPH;
	cout<<"\nTruong phong: "<<TPH<<endl;
}

class TAISAN{
	private:
	char TENTS[30];
	int SL;
	char TINHTRANG[30];
	public:
		void nhap();
		void xuat();
		friend class PHIEU;
};

void TAISAN::nhap(){
	cout<<"\nNhap ten tai san: "; fflush(stdin); gets(TENTS);
	cout<<"\nNhap so luong: "; cin>>SL;
	cout<<"\nNhap tinh trang: "; fflush(stdin); gets(TINHTRANG);
}

void TAISAN::xuat(){
	cout<<TENTS<<setw(15)<<SL<<setw(15)<<TINHTRANG<<endl;
}

class PHIEU{
	private:
	char MAPHIEU[30];
	char NGAY[30];
	NHANVIEN x;
	PHONG y;
	TAISAN z[100];
	int n;
	public:
		void nhap();
		void xuat();
};

void PHIEU::nhap(){
	cout<<"\nNhap ma phieu: "; fflush(stdin); gets(MAPHIEU);
	cout<<"\nNhap ngay: "; fflush(stdin); gets(NGAY);
	x.nhap();
	y.nhap();
	cout<<"\nNhap so luong tai san: "; cin>>n;
	for(int i=0;i<n;i++){
		z[i].nhap();
	}
}

void PHIEU::xuat(){
	cout<<"\n----PHIEU KIEM KE TAI SAN----\n";
	cout<<"\nMa phieu: "<<MAPHIEU<<setw(20)<<"Ngay kiem ke: "<<NGAY;
	x.xuat();
	y.xuat();
	
	cout<<"\nTen tai san"<<setw(15)<<"So luong"<<setw(15)<<"Tinh trang"<<endl;
	for(int i=0;i<n;i++)
	{
		z[i].xuat();
	}
	
	cout<<"\nSo tai san da kiem ke: "<<n;
	
	int tong = 0;
	for(int i=0;i<n;i++){
		tong = tong + z[i].SL;
	}
	cout<<setw(20)<<"Tong so luong: "<<tong;
}


int main(){
	PHIEU k;
	k.nhap();
	k.xuat();
}
