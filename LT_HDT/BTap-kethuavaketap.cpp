#include <iostream>
#include <string.h>
#include <iomanip>
using namespace std;
class TIVI;
class NSX{
	char TENNSX[30];
	char DCNSX[30];
	public:
		friend void DEMTIVI(TIVI *k, int n);
		friend class HANG;
		
};

class DATE{
	int D;
	int M;
	int Y;
	public:
		void nhap();
		void xuat();
};

void DATE::nhap(){
	cout<<"\nNhap D: "; cin>>D;
	cout<<"\nNhap M: "; cin>>M;
	cout<<"\nNhap Y: "; cin>>Y;
}

void DATE::xuat(){
	cout<<"\n-> "<<D<<"/"<<M<<"/"<<Y<<endl;
}

class HANG{
	protected:
	char TENH[30];
	NSX x;
	int DONGIA;
	public:
		void nhap();
		void xuat();
		friend void DEMTIVI(TIVI *k, int n);
		
};

void HANG::nhap(){
	cout<<"\nNhap ten hang: "; fflush(stdin); gets(TENH);
	cout<<"\nNhap don gia: "; cin>>DONGIA; 
	//nhap cho nsx
	cout<<"\nNhap ten nsx: "; fflush(stdin); gets(x.TENNSX);
	cout<<"\nNhap dia chi nsx: "; fflush(stdin); gets(x.DCNSX);
}

void HANG::xuat(){
	cout<<"\nTen hang: "<<TENH;
	cout<<"\nTen nsx: "<<x.TENNSX;
	cout<<"\nDia chi nsx: "<<x.DCNSX;
	cout<<"\nDon gia : "<<DONGIA;
}

class TIVI : public HANG
{
	int KICHTHUOC;
	DATE NGAYNHAP;
	public:
		void nhap();
		void xuat();
};

void TIVI::nhap(){
	HANG::nhap();
	cout<<"\nNhap kich thuoc tivi: "; cin>>KICHTHUOC;
	NGAYNHAP.nhap();
}

void TIVI::xuat(){
	HANG::xuat();
	cout<<"\nKich thuoc tivi la: "<<KICHTHUOC<<endl;
	NGAYNHAP.xuat();
}

void DEMTIVI(TIVI *k, int n)
{
	int dem = 0;
	for(int i = 0; i<n;i++){
		if(strcmp(k[i].x.TENNSX,"LG")==0){
			dem++;
		}
	}
	cout<<"\n-> Co "<<dem<<" tivi cua cua hang LG trong ds";
}

int main(){
	TIVI *k;
	int n;
	cout<<"\nNhap so luong tivi: "; cin>>n;
	k = new TIVI[n];
	for(int i = 0 ; i < n ; i++){
		k[i].nhap();
	}
	cout<<"\n----DACH SACH BAN VUA NHAP-----\n";
	for(int i = 0 ; i < n ; i++)
	{
		k[i].xuat();
	}
	DEMTIVI(k,n); 
}

