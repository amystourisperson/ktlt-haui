#include <iostream>
#include <iomanip>
#include <string.h>
using namespace std;
class NGUOI{
	protected:
	char HOTEN[30];
	char NGAYSINH[30];
	char QUEQUAN[30];
	public:
		void nhap();
		void xuat();
};

void NGUOI::nhap(){
	cout<<"\nNhap ho ten: "; fflush(stdin); gets(HOTEN);
	cout<<"\nNhap ngay sinh: "; fflush(stdin); gets(NGAYSINH);
	cout<<"\nNhap que quan: "; fflush(stdin); gets(QUEQUAN);
}

void NGUOI::xuat(){
	cout<<"\nho ten: "<<HOTEN;
	cout<<"\nngay sinh: "<<NGAYSINH;
	cout<<"\nque quan: "<<QUEQUAN;
}

class SINHVIEN:public NGUOI{
	private:
	int MSV;
	char NGANH[30];
	int KHOAHOC;
	public:
		void nhap();
		void xuat();
};

void SINHVIEN::nhap(){
	NGUOI::nhap();
	cout<<"\nNhap ma sinh vien: "; cin>>MSV;
	cout<<"\nNhap nganh hoc: "; fflush(stdin); gets(NGANH);
	cout<<"\nNhap khoa hoc: "; cin>>KHOAHOC;
}

void SINHVIEN::xuat(){
	NGUOI::xuat();
	cout<<"\nMa sinh vien: "<<MSV;
	cout<<"\nNganh hoc: "<<NGANH;
	cout<<"\nKhoa hoc: "<<KHOAHOC;
}

class LOPHOC{
	private:
		char MALH[30];
		char TENLOP[30];
		char NGAYMO[30];
		SINHVIEN x[100];
		int n;
		char GIAOVIEN[30];
	public:
		void nhap();
		void xuat();
};

void LOPHOC::nhap(){
	cout<<"\nNhap ma lop hoc: "; fflush(stdin); gets(MALH);
	cout<<"\nNhap ten lop hoc: "; fflush(stdin); gets(TENLOP);
	cout<<"\nNhap ngay mo: "; fflush(stdin); gets(NGAYMO);
	cout<<"\nNhap ten giao vien: "; fflush(stdin); gets(GIAOVIEN);
	cout<<"\nNhap so luong sinh vien trong lop: "; cin>>n;
	for(int i=0;i<n;i++){
		cout<<"\nNhap thong tin sinh vien thu: "<<(i+1)<<":"<<endl;
		x[i].nhap();
	}
}

void LOPHOC::xuat(){
	cout<<"\nMa lop hoc: "<<MALH;
	cout<<"\nTen lop hoc: "<<TENLOP;
	cout<<"\nNgay mo: "<<NGAYMO;
	cout<<"\nGiao vien: "<<GIAOVIEN;
	for(int i=0;i<n;i++){
		cout<<"\nThong tin sinh vien thu: "<<(i+1)<<" la:";
		x[i].xuat();
	}
}

int main(){
	LOPHOC k;
	k.nhap();
	k.xuat();
}

