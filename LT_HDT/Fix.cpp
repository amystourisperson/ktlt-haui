#include<iostream>
#include<iomanip>
using namespace std;
class NCC{
private:
	char Ten[30];
	char Macc[30];
	int SDT;
	char DiaChi[30];
public:
	void nhap();
	void xuat();
};
void NCC::nhap(){
	cout<<"\nten nha cung cap:";fflush(stdin);gets(Ten);
	cout<<"\nMa cung cap:";fflush(stdin);gets(Macc);
	cout<<"\nso dien thoai:";cin>>SDT;
	cout<<"\nDia chi:";fflush(stdin);gets(DiaChi);
}
void NCC::xuat(){
	cout<<setw(10)<<"\nMa cung cap:"<<Macc<<setw(10)<<"\nten nha cung cap:"<<Ten;
	cout<<setw(10)<<"\nDia chi:"<<setw(10)<<"\nso dien thoai:"<<SDT<<endl;
}
class sanpham{
	char Masp[30];
	char Tensp[30];
	int soluong;
	int dongia;
public:
	void xuat();
	void nhap();
	friend class PHIEU; 
	
};
void sanpham::nhap(){
	cout<<"\nma san pham:";fflush(stdin);gets(Masp);
		cout<<"\nten san pham:";fflush(stdin);gets(Tensp);
	cout<<"\nso luong:";cin>>soluong;
	cout<<"\ndon gia:";cin>>dongia;
	
}
void sanpham::xuat(){
	cout<<setw(10)<<"\nma san pham:"<<Masp;
	cout<<setw(10)<<"\nTen san pham:"<<Tensp;
	cout<<setw(10)<<"\nso luong:"<<soluong;
	cout<<setw(10)<<"\ndon gia:"<<dongia<<endl;
}
class PHIEU{
private:
	char MaPH[30];
	char Ngay[30];
	NCC x;
	sanpham *y;
	int n;
public:
	void xuat();
	void nhap();
};
void PHIEU::nhap(){
cout<<"\nma phieu:";fflush(stdin);gets(MaPH);
cout<<"\nngay nhap:";fflush(stdin);gets(Ngay);
x.nhap();
cout<<"\nnhap so luong san pham:";cin>>n;
y= new sanpham[n];
for(int i=0;i<n;i++)
y[i].nhap();
}
void PHIEU::xuat(){
	cout<<"\nÐai Hoc VIctory"<<endl;
	cout<<setw(15)<<"\nPhIEU NHAP VAN PHONG PHAM"<<endl;
	cout<<"\nma phieu:"<<MaPH<<setw(10)<<"\nngay nhap:"<<Ngay<<endl;
	x.xuat();
	int tong=0;
cout<<"Ma sp"<<setw(10)<<"Ten san pham"<<setw(10)<<"So luong"<<setw(10)<<"Don gia"<<setw(10)<<"Thanh tien"<<endl;	
for(int i=0;i<n;i++){
y[i].xuat();
tong = tong + (y[i].soluong * y[i].dongia);
}
	cout<<"\nThanh tien:"<<tong;
	cout<<"Hieu truong"<<setw(10)<<"Phong tai chinh"<<setw(10)<<"Nguoi lap"<<endl;
}




int main(){
	PHIEU k;
	k.nhap();
	cout<<"\n-----------------------\n";
	k.xuat();
	return 0;
}
