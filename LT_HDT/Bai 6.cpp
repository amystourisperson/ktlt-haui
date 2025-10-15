#include <iostream>
#include <string>
using namespace std;
class MAY
{
	protected:
		char MAMAY[30];
		char LOAIMAY[30];
		char NHANHIEU[30];
		float GIA;
		//ko co phuong thuc
};
class MAYTINH : public MAY
{
	float CPU, RAM, HDD;
	public:
		void nhap();
		void xuat();
};

void MAYTINH::nhap()
{
	cout<<"\nNhap ma may: ";
	fflush(stdin);
	gets(MAMAY);
	cout<<"\nNhap loai may: ";
	fflush(stdin);
	gets(LOAIMAY);
	cout<<"\nNhap nhan hieu: ";
	fflush(stdin);
	gets(NHANHIEU);
	cout<<"\nNhap gia may: ";
	cin>>GIA;
	cout<<"\nNhap CPU: ";
	cin>>CPU;
	cout<<"\nNhap RAM: ";
	cin>>RAM;
	cout<<"\nNhap HDD: ";
	cin>>HDD;
}

void MAYTINH::xuat()
{
	cout<<"\nLoai may: "<<LOAIMAY<<endl;
	cout<<"\nNhan hieu: "<<NHANHIEU<<endl;
	cout<<"\nGia may: "<<GIA<<endl;
	cout<<"\nCPU: "<<CPU<<endl;
	cout<<"\nRAM: "<<RAM<<endl;
	cout<<"\nHDD: "<<HDD<<endl;
}

int main(){
	MAYTINH k;
	k.nhap();
	k.xuat();
	
	
	return 0;
}
