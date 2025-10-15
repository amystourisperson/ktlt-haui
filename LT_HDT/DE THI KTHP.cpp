#include <iostream>
#include <iomanip>
#include <string>
#include <string.h>

using namespace std;
class BAIXE;
class PHUONGTIEN
{
	protected:
		
	char MAPT[30];
	char LOAI[30];
	int GIA;
	char HANG_SX[30];
	public:
		void nhap();
		void xuat();
		friend class BAIXE;
};

void PHUONGTIEN::nhap()
{
	cout<<"\nMAPT: ";
	fflush(stdin);
	gets(MAPT);
	cout<<"\nLOAI: ";
	fflush(stdin);
	gets(LOAI);
	cout<<"\nGIA: ";
	cin>>GIA;
	cout<<"\nHANG SX: ";
	fflush(stdin);
	gets(HANG_SX );
}

void PHUONGTIEN::xuat()
{
	cout<<MAPT<<setw(15)<<LOAI;
	cout<<setw(15)<<GIA<<setw(15)<<HANG_SX <<endl;
}

class XEMAY : public PHUONGTIEN
{
	char MAXE[30];
	char TENXE[30];
	int DUNGTICH;
	char BIENSO[30];
	public:
		void nhap();
		void xuat();
		friend class BAIXE;
		friend void Sort(BAIXE k);

};

void XEMAY::nhap()
{
	PHUONGTIEN::nhap();
	cout<<"\nMA XE: ";
	fflush(stdin);
	gets(MAXE);
	cout<<"\nTEN XE: ";
	fflush(stdin);
	gets(TENXE);
	cout<<"\nDUNG TICH: ";
	cin>>DUNGTICH;
	cout<<"\nBIEN SO: ";
	fflush(stdin);
	gets(BIENSO);
}

void XEMAY::xuat()
{
	PHUONGTIEN::xuat();
	cout<<MAXE<<setw(15)<<TENXE<<setw(15)<<DUNGTICH<<setw(15)<<BIENSO<<endl;
}

class BAIXE
{
	char MABX[30];
	char TENBX[30];
	int DIENTICH;
	XEMAY *x;
	int n;
	public:
		void nhap();
		void xuat();
		friend void SUA(BAIXE &k);
		friend void Sort(BAIXE k);
};

void BAIXE::nhap()
{
	cout<<"\nMA BX: ";
	fflush(stdin);
	gets(MABX);
	cout<<"\nTEN BX: ";
	fflush(stdin);
	gets(TENBX );
	cout<<"\nDIEN TICH: ";
	cin>>DIENTICH;
	cout<<"\nNhap so luong xe: ";
	cin>>n;
	
	x= new XEMAY[n];
	for(int i=0;i<n;i++)
	{
		x[i].nhap();
	}

}

void BAIXE::xuat()
{
	cout<<"\n------PARKING LOT-----------\n";
	cout<<"\nMA BX: "<<MABX <<endl;
	cout<<"\nTEN BX: "<<TENBX <<endl;
	cout<<"\nDIEN TICH: "<<DIENTICH<<endl;
	cout<<"MA XE"<<setw(15)<<"TEN XE"<<setw(15)<<"DUNG TICH"<<setw(15)<<"BIEN SO"<<endl;
	for(int i=0;i<n;i++)
	{
		x[i].xuat();
	}
	
}

void SUA(BAIXE &k)
{
	strcpy(k.TENBX,"MAI DICH");
}


void Sort(BAIXE k)
{
	for(int i=0;i<k.n;i++)
	{
		for(int j=i+1;j<k.n;j++)
		{
			if(k.x[i].DUNGTICH>k.x[j].DUNGTICH)
			{
				swap(k.x[i],k.x[j]);
			}
		}
	}
}

int main(){
	BAIXE k;
	k.nhap();
	k.xuat();
	SUA(k);
	cout<<"\nBai xe sau khi sx"<<endl;
	Sort(k);
	k.xuat();  
}






