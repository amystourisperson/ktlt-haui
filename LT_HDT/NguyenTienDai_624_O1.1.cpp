#include <iostream>
#include <iomanip>
#include <string.h>
using namespace std;
class NCC{
	private:
	char MaNCC[30];
	char TenNCC[30];
	char DiaChi[30];
	public:
		void nhap();
		void xuat();
};

void NCC::nhap(){
	cout<<"\nNhap ma ncc: "; fflush(stdin); gets(MaNCC);
	cout<<"\nNhap ten ncc: "; fflush(stdin); gets(TenNCC);
	cout<<"\nNhap dia chi: "; fflush(stdin); gets(DiaChi);
}

void NCC::xuat(){
	cout<<"\nMa NCC: "<<MaNCC<<setw(15)<<"Ten NCC: "<<TenNCC;
	cout<<"\nDia chi: "<<DiaChi;
}

class HANG{
	private:
	char TenHang[30];
	float DonGia;
	int SL;
	public:
		void nhap();
		void xuat();
		friend class PHIEU;
};

void HANG::nhap(){
	cout<<"\nNhap ten hang: "; fflush(stdin); gets(TenHang);
	cout<<"\nNhap don gia: "; cin>>DonGia;
	cout<<"\nNhap so luong: "; cin>>SL;
}

void HANG::xuat(){
	cout<<TenHang<<setw(15)<<DonGia<<setw(15)<<SL<<setw(15)<<(float)DonGia*SL<<endl;
}

class PHIEU{
	private:
	char MaPhieu[30];
	char Ngay[30];
	NCC x;
	HANG y[100];
	int n;
	public:
		void nhap();
		void xuat();
};

void PHIEU::nhap(){
	cout<<"\nNhap ma phieu: "; fflush(stdin); gets(MaPhieu);
	cout<<"\nNhap Ngay lap: "; fflush(stdin); gets(Ngay);
	x.nhap();
	cout<<"\nNhap so luong hang hoa: "; cin>>n;
	for(int i=0;i<n;i++){
		y[i].nhap();
	}
}

void PHIEU::xuat(){
	cout<<"\n----PHIEU NHAP HANG----\n";
	cout<<"\nMa phieu: "<<MaPhieu<<setw(15)<<"Ngay"<<Ngay;
	x.xuat();
	cout<<"\nTen hang"<<setw(15)<<"Don gia"<<setw(15)<<"So luong"<<setw(15)<<"Thanh tien"<<endl;

	for(int i=0;i<n;i++){
		y[i].xuat();
	}
	
	float tong = 0;
	for(int i=0;i<n;i++){
		tong = tong + y[i].DonGia * y[i].SL;
	}
	
	cout<<setw(30)<<"Cong thanh tien: "<<tong<<endl;
}

int main(){
	PHIEU k;
	k.nhap();
	k.xuat();
}
