#include <iostream>
#include <string>
using namespace std;

class HINH
{
	protected:
		int MS;
		int VI;
	public:
		void nhap();
		void xuat();
		// khoi tao co doi
		HINH(int x, int y);
};

void HINH::nhap()
{
	cout<<"\nNhap mau sac: ";
	cin>>MS;
	cout<<"\nNhap vien: ";
	cin>>VI;
}

void HINH::xuat()
{
	cout<<"\nMau sac: "<<MS<<endl;
	cout<<"\nVien: "<<VI<<endl;
}

HINH::HINH(int x, int y)
{
	MS=x;
	VI=y;
}

class HCN : public HINH
{
	float D, R;
	public:
		void nhap();
		void xuat();
		HCN(int x, int y, float z, float t);
};

void HCN::nhap()
{
	HINH::nhap();
	cout<<"\nD = ";
	cin>>D;
	cout<<"\nR = ";
	cin>>R;
}

void HCN::xuat(){
	HINH::xuat();
	cout<<"\nD = "<<D<<endl;
	cout<<"\nR = "<<R<<endl;
	
}

HCN::HCN(int x, int y, float z, float t) : HINH(x,y)  //2 cai x, y dau la danh rieng cho HINH (ben trong class HINH se tu khoi tao co doi cho x,y)
{
	//phuong thuc khoi tao kh the di truyen dc, k the reuse
	//x,y o day se kh can nua
//	MS=x;
//	VI=y;
	D=z;
	R=t;
}
/*phuong thuc khoi tao co doi cua lop con
<Tenlopcon>(<Cacdoi>) : <Tenlopcha>(<cacdoidanhcholopcha>)
{
	khoi gan cac gia tri thuoc tinh cho lop con
}
*/

int main(){
	HCN k(1,3,5,2);
	k.xuat();
}
