#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
class PERSON
{
	protected: //bat buoc phai co
	char HOTEN[30];
	int TUOI;
	char DIACHI[30];
	public:
		void nhap();
		void xuat();
};
void PERSON::nhap()
{
	cout<<"\nNhap ho ten: ";
	fflush(stdin);
	gets(HOTEN);
	cout<<"\nNhap tuoi: ";
	cin>>TUOI;
	cout<<"\nNhap dia chi: ";
	fflush(stdin);
	gets(DIACHI);
}
void PERSON::xuat()
{
	cout<<setw(15)<<HOTEN<<setw(15)<<TUOI<<setw(15)<<DIACHI<<endl;
}

class STUDENT : public PERSON   //cach khai bao ke thua lop cha
{
	char TRUONG[30];
	char KHOA[30];
	public:
		void nhap();
		void xuat();
};

void STUDENT::nhap(){
	cout<<"\nNhap ten truong: ";
	fflush(stdin);
	gets(TRUONG);
	cout<<"\nNhap ten khoa: ";
	fflush(stdin);
	gets(KHOA);
	
	PERSON::nhap();   //reuse code nhap cua lop cha

void STUDENT::xuat()
{
	cout<<setw(15)<<TRUONG<<setw(15)<<KHOA<<endl;
	
	PERSON::xuat();  //reuse code xuat cua lop cha
}
int main(){
	STUDENT k;
	k.nhap();
	k.xuat();
}
