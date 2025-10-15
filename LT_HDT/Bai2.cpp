#include <iostream>
#include <string.h>
using namespace std;
class TRUONG;
class KHOA
{
	char TENLOP[30];
	int SOLUONGHS;
	char MANGANH[30];
	public:
		friend class TRUONG;
		friend void TIMKIEM(TRUONG k);
		//do TRUONG phai duoc khai bao truoc moi thuc hien duoc nen ta phai khai bao truoc
		friend void Sapxep(TRUONG k);
};
class TRUONG
{
	char TENTRUONG[30];
	char MATRUONG[30];
	KHOA *x;
	int n;
	public:
		void nhap();
		void xuat();
		friend void TIMKIEM(TRUONG k);
		friend void Sapxep(TRUONG k);
};

void TRUONG::nhap()
{
	cout<<"\nNhap ten truong : ";
	fflush(stdin);
	gets(TENTRUONG);
	cout<<"\nNhap ma truong (chu + so): ";
	fflush(stdin);
	gets(MATRUONG);
	cout<<"\nNhap n: ";
	cin>>n;
	//cap phat dong cho x
	x=new KHOA[n];
	//do bai kh co y/c nhap xuat cho khoa len minh kh the dung reus nhu bai1
	for(int i=0;i<n;i++)
	{
		cout<<"\nNhap ten lop: ";
		fflush(stdin);
		gets(x[i].TENLOP);
		cout<<"\nNhap so luong hoc sinh trong lop: ";
		fflush(stdin);
		cin>>x[i].SOLUONGHS;
		cout<<"\nNhap ma nganh cua lop (chu + so): ";
		fflush(stdin);
		gets(x[i].MANGANH);
	}
}

void TRUONG::xuat()
{
	cout<<"\n--------------------------------\n";
	cout<<"\nTen truong la: "<<TENTRUONG<<endl;
	cout<<"\nMa truong la: "<<MATRUONG<<endl;
	cout<<"\nn= "<<n<<endl;
	for(int i=0;i<n;i++)
	{
		//hoac dung setw(<do dan cach>) vd: setw(20)<<
		cout<<"\nLop: "<<x[i].TENLOP<<"---Co so luong hoc sinh la: "<<x[i].SOLUONGHS<<"---Ma Nganh: "<<x[i].MANGANH<<endl;
	}
}

void TIMKIEM(TRUONG k)
{
	int dem=0;
	for(int i=0;i<k.n;i++)
	{
		if(strcmp(k.x[i].TENLOP,"KHMT")==0)
		{
			dem++;
		}
	}
	if(dem==0)
	{
		cout<<"\nKhong co lop khmt";
	}
	else
	{
		cout<<"\nCo lop khmt";
	}
}

void Sapxep(TRUONG k)
{
	for(int i=0;i<k.n;i++)
	{
		for(int j=i+1;j<k.n;j++)
		{
			if(k.x[i].SOLUONGHS>k.x[j].SOLUONGHS)
			{
				//do chi duoc sx so luong hs, neu ta .SOLUONGHS thi moi khoa se bi doi sl hs->sai
				swap(k.x[i],k.x[j]);
			}
		}
	}
}
int main(){
	//KHOA *x; int n;
	TRUONG k;
	k.nhap();
	k.xuat();
	//meo!: ham main co cai gi thi ta cho cai day | TIMKIEM(k.x, k.n) -> khong duoc (tuy ko sai)
	TIMKIEM(k);
	Sapxep(k);
	//sx xong ta xuat
	k.xuat();
	
	//ham main kh la ban lop cua ham nao het, de lam dc ham tim kiem ta phai tao ham rieng
}
