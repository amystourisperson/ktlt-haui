#include <iostream>
#include <string.h>
using namespace std;
class DOCGIA;
class SACH{
	private:
		char MaSach[30];
		char TenSach[30];
		char TacGia[30];
		int Gia;
		int SL;
	public:
		void nhap();
		void xuat();
		friend void DEM(DOCGIA k);
		friend void SUA(DOCGIA &k);
};

void SACH::nhap(){
	cout<<"\nNhap ma sach: "; fflush(stdin); gets(MaSach);
	cout<<"\nNhap ten sach: "; fflush(stdin); gets(TenSach);
	cout<<"\nNhap ten tac gia: "; fflush(stdin); gets(TacGia);
	cout<<"\nNhap gia quyen sach: "; cin>>Gia;
	cout<<"\nNhap so luong sach hien co: "; cin>>SL;
}

void SACH::xuat(){
	cout<<"\nMa sach: "<<MaSach;
	cout<<"\nTen sach: "<<TenSach;
	cout<<"\nTen tac gia: "<<TacGia;
	cout<<"\nGia: "<<Gia;
	cout<<"\nSo luong: "<<SL;
}

class NGUOI
{
	protected:
		char HoTen[30];
		char MaThe[30];
		char NgayCap[30];
	public:
		void nhap();
		void xuat();
};

void NGUOI::nhap(){
	cout<<"\nNhap ho ten: "; fflush(stdin); gets(HoTen);
	cout<<"\nNhap ma the: "; fflush(stdin); gets(MaThe);
	cout<<"\nNhap ngay cap: "; fflush(stdin); gets(NgayCap);

}

void NGUOI::xuat(){
	cout<<"\nHo ten: "<<HoTen;
	cout<<"\nMa the: "<<MaThe;
	cout<<"\nNgay cap: "<<NgayCap;

}

class DOCGIA : public NGUOI
{
	private:
		char TheLoai[30];
		char TinhTrang[30];
		SACH x[100];
		int n;
	public:
		void nhap();
		void xuat();
		friend void DEM(DOCGIA k);
		friend void SUA(DOCGIA &k);
};

void DOCGIA::nhap(){
	NGUOI::nhap();
	cout<<"\nNhap the loai sach: "; fflush(stdin); gets(TheLoai);
	cout<<"\nNhap tinh trang: "; fflush(stdin); gets(TinhTrang);
	cout<<"\nNhap so luong sach: "; cin>>n;
	for(int i = 0; i < n; i++){
		x[i].nhap();
	}
	
}

void DOCGIA::xuat(){
	NGUOI::xuat();
	cout<<"\nThe loai sach la: "<<TheLoai;
	cout<<"\nTinh trang: "<<TinhTrang;
	for(int i = 0;i< n;i++){
		x[i].xuat();
	}
	
}
//bonus1:
void SUA(DOCGIA &k){
	for(int i=0;i<k.n;i++){
		if(strcmp(k.x[i].TenSach,"Lap Trinh Python")==0){
			k.x[i].SL = 10 ;
		}
	}

}

//bonus2:
void DEM(DOCGIA k){
	int dem = 0;
	for(int i=0;i<k.n;i++){
		if(k.x[i].Gia > 50000 || k.x[i].SL > 5){
			dem++;
		}
	}
	
	cout<<"\nCo "<<dem<<" sach co gia > 50000 hoac sl muon >5";
}

int main(){
	
	DOCGIA k;
	k.nhap();
	cout<<"\n---THONG TIN BAN VUA NHAP---\n";
	k.xuat();
	
	SUA(k);
	k.xuat();
	
	DEM(k);
	k.xuat(); 
}
