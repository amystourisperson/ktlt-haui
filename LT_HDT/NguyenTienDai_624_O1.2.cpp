#include <iostream>
#include <string.h>
#include <iomanip>
using namespace std;

class SINHVIEN{
	private:
	char MSV[30];
	char TenSV[30];
	char LOP[30];
	int Khoa;
	public:
		void nhap();
		void xuat();
};

void SINHVIEN::nhap(){
	cout<<"\nNhap ma sinh vien: "; fflush(stdin); gets(MSV);
	cout<<"\nNhap ten sinh vien: "; fflush(stdin); gets(TenSV);
	cout<<"\nNhap lop: "; fflush(stdin); gets(LOP);
	cout<<"\nNhap khoa: "; cin>>Khoa;
}

void SINHVIEN::xuat(){
	cout<<"\nMa sinh vien: "<<MSV<<setw(15)<<"Ten sinh vien: "<<TenSV;
	cout<<"\nLop: "<<LOP<<setw(15)<<"Khoa: "<<Khoa<<endl;
}

class MON{
	private:
	char TenMon[30];
	int SoTrinh;
	float Diem;
	public:
		void nhap();
		void xuat();
		friend class PHIEU;
};

void MON::nhap(){
	cout<<"\nNhap ten mon: "; fflush(stdin); gets(TenMon);
	cout<<"\nNhap so trinh: "; cin>>SoTrinh;
	cout<<"\nNhap diem: "; cin>>Diem;
}

void MON::xuat(){
	cout<<TenMon<<setw(15)<<SoTrinh<<setw(15)<<Diem<<endl;
}

class PHIEU{
	private:
	SINHVIEN x;
	int n;
	MON y[100];
	public:
		void nhap();
		void xuat();
};

void PHIEU::nhap(){
	x.nhap();
	cout<<"\nNhap so luong mon: "; cin>>n;
	for(int i=0;i<n;i++){
		y[i].nhap();
	}
}

void PHIEU::xuat(){
	cout<<"------PHIEU BAO DIEM-----\n";
	x.xuat();
	cout<<"Ten mon"<<setw(15)<<"So trinh"<<setw(15)<<"Diem"<<endl;

	for(int i=0;i<n;i++){
		y[i].xuat();
	}
	
	float tong = 0;
	for(int i=0;i<n;i++){
		tong = tong + y[i].Diem;
	}
	float dtb = (float)(tong/1.0*n);
	cout<<setw(30)<<"\nDiem trung binh: "<<dtb<<endl;
}

int main(){
	PHIEU k;
	k.nhap();
	k.xuat();
}
