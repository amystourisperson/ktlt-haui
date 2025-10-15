#include <iostream>
#include <iomanip>
#include <string.h>
using namespace std;
class PHIEU;
class NCC{
	char MaNCC[30];
	char TenNCC[30];
	char Dc[30];
	int SDT;
	public:
		void nhap();
		void xuat();
};

void NCC::nhap(){
	cout<<"\nNhap ma nha cung cap: "; fflush(stdin); gets(MaNCC);
	cout<<"\nNhap Ten nha cung cap: "; fflush(stdin); gets(TenNCC);
	cout<<"\nNhap dia chi: "; fflush(stdin); gets(Dc);
	cout<<"\nNhap so dien thoai: "; cin>>SDT;
}

void NCC::xuat(){
	cout<<"\nMa nha cung cap: "<<MaNCC<<setw(15)<<"\tTen nha cung cap: "<<TenNCC<<endl;
	cout<<"\nDia chi: "<<Dc<<setw(15)<<"SDT: "<<SDT<<endl;
}

class SANPHAM{
	char MASP[30];
	char TenSP[30];
	int SOLUONG;
	int DONGIA;
	public:
		void nhap();
		void xuat();
		friend class PHIEU;
		friend void check_sl(PHIEU k); //truy cap thuoc tinh rieng tu cua sl
		friend void swap_dg(PHIEU k); //rieng tu cua don gia
		
};

void SANPHAM::nhap(){
	cout<<"\nNhap ma san pham: "; fflush(stdin); gets(MASP);
	cout<<"\nNhap ten san pham: "; fflush(stdin); gets(TenSP);
	cout<<"\nNhap so luong: "; cin>>SOLUONG;
	cout<<"\nNhap don gia: "; cin>>DONGIA;
}

void SANPHAM::xuat(){
	cout<<MASP<<setw(15)<<TenSP<<setw(15)<<SOLUONG<<setw(15)<<DONGIA<<setw(15)<<DONGIA * SOLUONG <<endl;
}

class PHIEU{
	char MAPH[30];
	char NGAY[30];
	NCC x;
	int n;
	SANPHAM *y;
	public:
		void nhap();
		void xuat();
		friend void check_sl(PHIEU k); //rieng tu cua n
		friend void swap_dg(PHIEU k); //rieng tu cua n
	
		
};

void PHIEU::nhap(){
	cout<<"\nNhap ma phieu: "; fflush(stdin); gets(MAPH);
	cout<<"\nNhap ngay lap: "; fflush(stdin); gets(NGAY);
	x.nhap();
	cout<<"\nNhap so luong san pham: "; cin>>n;
	y = new SANPHAM[n];
	for(int i = 0 ;i < n; i++){
		y[i].nhap();
	}
}

void PHIEU::xuat(){
	cout<<"\nDai hoc Victory"<<endl;
	cout<<setw(35)<<"PHIEU NHAP VAN PHONG PHAM"<<endl;
	cout<<"Ma phieu: "<<MAPH<<setw(15)<<"Ngay lap: "<<NGAY<<endl;
	x.xuat();
	int tong = 0;
	cout<<"Ma SP"<<setw(15)<<"Ten san pham"<<setw(15)<<"So luong"<<setw(15)<<"Don gia"<<setw(15)<<"Thanh tien"<<endl;
	for(int i = 0 ; i < n ;i++)
	{
		y[i].xuat();
		tong = tong + (y[i].SOLUONG * y[i].DONGIA);
	}
	cout<<"\nTong = "<<tong<<endl;
	cout<<"Hieu truong"<<setw(15)<<"Phong tai chinh"<<setw(15)<<"Nguoi lap"<<endl;
}

void check_sl(PHIEU k){
	int dem = 0;
	for(int i = 0 ;i < k.n; i++){
		if(k.y[i].SOLUONG < 80){
			dem++;
		}
	}
	cout<<"\n-> Co "<<dem<<" san pham co sl nhap nho hon 80 trong phieu"<<endl;
}

void swap_dg(PHIEU k){
	for(int i = 0; i < k.n; i++){
		for(int j = i+1; j<k.n; j++){
			if(k.y[i].DONGIA > k.y[j].DONGIA){
				swap(k.y[i],k.y[j]);
				
				/*int swap = k.y[i];
				k.y[i] = k.y[j];
				k.y[j] = swap;
				*/
			}
		}
	}
}

int main(){
	PHIEU k;
	k.nhap();
	cout<<"\n-----------------------\n";
	k.xuat();
	check_sl(k);
	cout<<"\n----Sau khi sap xep----\n";
	swap_dg(k);
	k.xuat();	
}
