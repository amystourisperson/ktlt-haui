/*
#include <iostream>
#include <math.h>
#include <string.h>
#include <iomanip>
using namespace std;
class PHIEU;
class NHANVIEN{
	private:
		char MaNV[30];
		char HoTen[30];
	public:
		void nhap();
		void xuat();
};

void NHANVIEN::nhap(){
	cout<<"\nNhap ma nhan vien: "; fflush(stdin); gets(MaNV);
	cout<<"\nNhap ho ten nhan vien: "; fflush(stdin); gets(HoTen);
}

void NHANVIEN::xuat(){
	cout<<"\nMa nhan vien: "<<MaNV<<setw(15)<<"Ho va Ten: "<<HoTen;
}

class KHO{
	private:
		char MaKho[30];
		char DiaChi[30];
	public:
		void nhap();
		void xuat();
};

void KHO::nhap(){
	cout<<"\nNhap ma kho: "; fflush(stdin); gets(MaKho);
	cout<<"\nNhap dia chi kho: "; fflush(stdin); gets(DiaChi);
}

void KHO::xuat(){
	cout<<"\nMa kho: "<<MaKho<<setw(15)<<"Dia chi kho: "<<DiaChi;
}

class THIETBI{
	private:
		char MaTB[30];
		char TenTB[30];
		int SL;
		int DONGIA;
	public:
		void nhap();
		void xuat();
		friend class PHIEU;
		friend void Sort(PHIEU k);
};

void THIETBI::nhap(){
	cout<<"\nNhap ma thiet bi: "; fflush(stdin); gets(MaTB);
	cout<<"\nNhap ten thiet bi: "; fflush(stdin); gets(TenTB);
	cout<<"\nNhao so luong: "; cin>>SL;
	cout<<"\nNhap don gia: "; cin>>DONGIA;
}

void THIETBI::xuat(){
	cout<<MaTB<<setw(15)<<TenTB<<setw(15)<<SL<<setw(15)<<DONGIA<<setw(15)<<DONGIA*SL<<endl;
}

class PHIEU{
	private:
		char MaPhieu[30];
		char NgayLap[30];
		int n;
		NHANVIEN x;
		KHO y;
		THIETBI z[100];
	public:
		void nhap();
		void xuat();
		friend void Sort(PHIEU k);
		friend void CHANGE_NAME(PHIEU &k, const char *re_name);
};

void PHIEU::nhap(){
	cout<<"\nNhap ma phieu: "; fflush(stdin); gets(MaPhieu);
	cout<<"\nNhap ngay lap: "; fflush(stdin); gets(NgayLap);
	x.nhap();
	y.nhap();
	cout<<"\nNhap so luong thiet bi: "; cin>>n;
	for(int i=0;i<n;i++){
		z[i].nhap();
	}
}

void PHIEU::xuat(){
	cout<<"\nDIEN MAY ABC\n";
	cout<<setw(30)<<"PHIEU NHAP KHO"<<endl;
	cout<<"\nMa phieu: "<<MaPhieu<<setw(15)<<"Ngay lap: "<<NgayLap<<endl;
	x.xuat();
	y.xuat();
	int dem_sl = 0;
	int tong_tien = 0;
	cout<<"\nMa TB"<<setw(15)<<"Ten thiet bi"<<setw(15)<<"So luong"<<setw(15)<<"Don gia"<<setw(15)<<"Thanh tien"<<endl;
	for(int i=0;i<n;i++){
		z[i].xuat();
		dem_sl = dem_sl + z[i].SL;
		tong_tien = tong_tien + z[i].SL * z[i].DONGIA;
	}
	
	cout<<setw(10)<<"\nTong so: "<<dem_sl<<setw(45)<<tong_tien<<endl;
	cout<<setw(45)<<"\nHa noi, ngay...thang....nam 2021\n";
}

//bonus1: 
void CHANGE_NAME(PHIEU &k, const char *re_name){
	strcpy(k.NgayLap, re_name);
}

//bonus2:
void Sort(PHIEU k){
	for(int i=0;i<k.n-1;i++){
		for(int j=i+1;j<k.n;j++){
			if(k.z[i].DONGIA > k.z[j].DONGIA){
				THIETBI tmp = k.z[i];
				k.z[i] = k.z[j];
				k.z[j] = tmp;
			}
		}
	}
}

int main(){
	PHIEU k;
	k.nhap();
	k.xuat();
	cout<<"\n---Sau khi doi ten----\n";
	CHANGE_NAME(k,"22/12/2021");
	cout<<"\n----Sau khi dc sx----\n";
	Sort(k);
	k.xuat();  
	
	return 0;
}

*/

#include <iostream>
#include <iomanip>
#include <string.h>
using namespace std;
class THUADAT{
	private:
		int DAI;
		int RONG;
		int GiaTien;
	public:
		THUADAT();
		THUADAT(int d, int r, int t);
		float operator*();
		bool operator==(THUADAT x);
		friend istream& operator>>(istream &in, THUADAT &k);
		friend ostream& operator<<(ostream &out, THUADAT k);
};

THUADAT::THUADAT(){
	DAI = 0;
	RONG = 0;
	GiaTien = 0;
}

THUADAT::THUADAT(int d,int r, int t){
	DAI = d;
	RONG = r;
	GiaTien = t;
}

float THUADAT::operator*(){
	return DAI*RONG;
}

bool THUADAT::operator==(THUADAT x){
	if((DAI*RONG == x.DAI*x.RONG)&&(GiaTien == x.GiaTien)){
		return true;
	}
	return false;
}

istream& operator>>(istream &in, THUADAT &k)
{
	cout<<"\nNhap chieu dai: "; in>>k.DAI;
	cout<<"\nNhap chieu rong: "; in>>k.RONG;
	cout<<"\nNhap gia tien: "; in>>k.GiaTien;
}

ostream& operator<<(ostream &out, THUADAT k){
	out<<"\nChieu dai: "<<k.DAI;
	out<<"\nChieu rong: "<<k.RONG;
	out<<"\nGia tien: "<<k.GiaTien;
}
int main(){
	THUADAT a;
	THUADAT b(2,3,50);
	cout<<"\nNhap thong tin cho thua dat thu 1: "<<endl;
	cin>>a;
	cout<<"\nNhap thong tin cho thua dat thu 2: "<<endl;
	cin>>b;
	cout<<"\nThong tin thua dat thu 1: "<<endl;
	cout<<a;
	cout<<"\nThong tin thua dat thu 2: "<<endl;	
	cout<<b;
	
	cout<<"\nDien tich thua dat thu 1 la: "<<*a<<endl;
	cout<<"\nDien tich thua dat thu 2 la: "<<*b<<endl;
	
	
	bool sosanh = (a==b);
	if(sosanh){
		cout<<"\nTrue !";
	}else
	{
		cout<<"\nFalse !";
	}
	
}







