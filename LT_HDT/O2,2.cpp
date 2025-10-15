#include <iostream>
#include <iomanip>
#include <string.h>
using namespace std;
class STUDENT;
class SCHOOL{
	private:
		char Name[30];
		char Date[30];
	public:
		friend class FACULTY;
		friend void SUA(STUDENT &k);
};

class FACULTY{
	private:
		char Ten[30];
		char Ngay[30];
		SCHOOL x;
	public:
		void nhap();
		void xuat();
		friend void SUA(STUDENT &k);
};

void FACULTY::nhap(){
	cout<<"\nNhap ten truong: "; fflush(stdin); gets(x.Name);
	cout<<"\nNhap ngay: "; fflush(stdin); gets(x.Date);
	cout<<"\nNhap ten faculty: "; fflush(stdin); gets(Ten);
	cout<<"\nNhap ngay tiep: "; fflush(stdin); gets(Ngay);
}

void FACULTY::xuat(){
	cout<<"\nTen truong: "<<x.Name;
	cout<<"\nDate: "<<x.Date;
	cout<<"\nTen khoa: "<<Ten;
	cout<<"\nNgay: "<<Ngay;
}

class PERSON{
	protected:
		char TenNguoi[30];
		char NgaySinh[30];
		char DiaChi[30];
	public:
		void nhap();
		void xuat();
		PERSON();
		
};

void PERSON::nhap(){
	cout<<"\nNhap Ten nguoi: "; fflush(stdin); gets(TenNguoi);
	cout<<"\nNhap Ngay sinh : "; fflush(stdin); gets(NgaySinh);
	cout<<"\nNhap Dia chi: "; fflush(stdin); gets(DiaChi);
}
void PERSON::xuat(){
	cout<<"\nTen nguoi: "<<TenNguoi;
	cout<<"\nNgay sinh: "<<NgaySinh;
	cout<<"\nDia chi: "<<DiaChi;
}

PERSON::PERSON(){
	strcpy(TenNguoi," ");
	strcpy(NgaySinh, " ");
	strcpy(DiaChi," ");
}

class STUDENT :public PERSON {
	private:
		int LOP;
		float score;
		FACULTY y;
	public:
		void nhap();
		void xuat();
		STUDENT();
		friend void SUA(STUDENT &k);
};

void STUDENT::nhap(){
	y.nhap();
	cout<<"\nNhap lop: "; cin>>LOP;
	cout<<"\nNhap diem: "; cin>>score;
	PERSON::nhap();
}

void STUDENT::xuat(){
	y.xuat();
	cout<<"\nLop: "<<LOP;
	cout<<"\nDiem: "<<score;
	PERSON::xuat();
}

STUDENT::STUDENT() : PERSON (){
	LOP = 0;
	score = 0;
}

//bonus1:
void SUA(STUDENT &k){
	strcpy(k.y.x.Name,"DHCNHN");
}
int main(){
	STUDENT k;
	k.nhap();
	k.xuat();
	cout<<"\n---Sau khi sua lai ten truong---\n";
	SUA(k);
	k.xuat(); 
}
