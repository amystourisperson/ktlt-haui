#include <iostream>
#include <iomanip>
using namespace std;
class PHIEU;
class NCC
{
	char MaNCC[30];
	char TenNCC[30];
	char DiaChi[30];
	int SDT;
	public:
		void nhap();
		void xuat();
		friend class PHIEU;
};

void NCC::nhap(){
	cout<<"\nMa Nha Cung Cap: "; fflush(stdin);  gets(MaNCC);
	cout<<"\nTen NCC:  "; fflush(stdin);  gets(TenNCC);
	cout<<"\nDia Chi: "; fflush(stdin);  gets(DiaChi);
	cout<<"\nSDT: "; cin>>SDT;
}

void NCC::xuat(){
	cout<<"\nMa nha cung cap: "<<MaNCC;
	cout<<setw(20)<<"Ten nha cung cap: "<<TenNCC<<endl; 
	cout<<"Dia chi: "<<DiaChi<<setw(20)<<"SDT: "<<SDT<<endl; 
}

class SANPHAM
{
	char MaSP[30];
	char TenSP[30];
	int SL;
	int DonGia;
	public:
		void nhap();
		void xuat();
		friend class PHIEU;
};

void SANPHAM::nhap(){
	cout<<"\nMa SP: ";  fflush(stdin);  gets(MaSP);
	cout<<"\nTen SP: "; fflush(stdin);  gets(TenSP);
	cout<<"\nSo luong: "; cin>>SL ;
	cout<<"\nDon gia: ";  cin>>DonGia ;
}

void SANPHAM::xuat()
{
	cout<<MaSP<<setw(20)<<TenSP<<setw(25)<<SL<<setw(20)<<DonGia<<endl; 
}

class PHIEU
{
	char MaPH[30];
	char Ngay[30];
	NCC x;
	int n;
	SANPHAM *y;
	public:
		void nhap();
		void xuat();
};

void PHIEU::nhap(){
	cout<<"\nMa Phieu: "; fflush(stdin); gets(MaPH);
	cout<<"\nNgay lap: "; fflush(stdin); gets(Ngay);
	x.nhap();
	cout<<"\nNhap so luong san pham: ";
	cin>>n;
	y = new SANPHAM[n];
	for(int i = 0; i<n;i++){
		y[i].nhap();
	}
}

void PHIEU::xuat()
{
	cout<<"\nDai hoc Victory"<<endl;
	cout<<setw(40)<<"PHIEU NHAP VAN PHONG PHAM"<<endl;
	cout<<"\nMa phieu: "<<MaPH<<setw(20)<<"Ngay lap: "<<Ngay<<endl;
	x.xuat();
	cout<<"Ma SP"<<setw(20)<<"Ten san pham"<<setw(25)<<"So luong"<<setw(20)<<"Don gia"<<endl; 	
	for(int i = 0; i<n;i++){
		y[i].xuat();
	}
	
	cout<<"\nHieu truong"<<setw(20)<<"Phong tai chinh"<<setw(20)<<"Nguoi lap"<<endl;
}


int main(){
	PHIEU k;
	k.nhap();
	k.xuat();
}
