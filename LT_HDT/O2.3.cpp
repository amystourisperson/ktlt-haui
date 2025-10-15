#include <iostream>
#include <string.h>
#include <iomanip>
using namespace std;
class TRUONGDH;
class KHOA{
	private:
		char MaKhoa[30];
		char TenKhoa[30];
		char TruongKhoa[30];
	public: 
		friend class TRUONG;
		friend class TRUONGDH;
		friend void XOA(TRUONGDH &k);
};

class BAN{
	private:
		char MaBan[30];
		char TenBan[30];
		char NgayTL[30];
	public:
		friend class TRUONG;
		friend class TRUONGDH;
};

class TRUONG{
	protected:
		char MaTruong[30];
		char TenTruong[30];
		char DiaChi[30];
	public:
		void nhap();
		void xuat();
};

void TRUONG::nhap(){
	cout<<"\nNhap ma truong: "; fflush(stdin); gets(MaTruong);
	cout<<"\nNhap ten truong: "; fflush(stdin); gets(TenTruong);
	cout<<"\nNhap dia chi: "; fflush(stdin); gets(DiaChi);
}

void TRUONG::xuat(){
	cout<<"\nMa Truong: "<<MaTruong;
	cout<<"\nTen Truong: "<<TenTruong;
	cout<<"\nDia chi: "<<DiaChi;
}

class TRUONGDH : public TRUONG
{
	private:
		int n;
		int m;
		KHOA x[100];
		BAN y[100];
	public:
		void nhap();
		void xuat();
		friend void XOA(TRUONGDH &k);
};

void TRUONGDH::nhap(){
	TRUONG::nhap();
	cout<<"\nNhap so khoa: "; cin>>n;
	for(int i=0;i<n;i++){
		cout<<"\nNhap thong tin khoa thu "<<i<<": ";
		cout<<"\nNhap ma khoa: "; fflush(stdin); gets(x[i].MaKhoa);
		cout<<"\nNhap ten khoa: "; fflush(stdin); gets(x[i].TenKhoa);
		cout<<"\nNhap truong khoa: "; fflush(stdin); gets(x[i].TruongKhoa);
	}
	cout<<"\nNhap so ban: "; cin>>m;
	for(int i=0;i<m;i++){
		cout<<"\nNhap thong tin cho ban thu "<<i<<" : ";
		cout<<"\nNhap ma ban: "; fflush(stdin); gets(y[i].MaBan);
		cout<<"\nNhap ten ban: "; fflush(stdin); gets(y[i].TenBan);
		cout<<"\nNhap ngay thanh lap: "; fflush(stdin); gets(y[i].NgayTL);
	}
}

void TRUONGDH::xuat(){
	TRUONG::xuat();
		for(int i=0;i<n;i++){
		cout<<"\nThong tin khoa thu "<<i<<": ";
		cout<<"\nMa khoa: "<<x[i].MaKhoa;
		cout<<"\nTen khoa: "<<x[i].TenKhoa;
		cout<<"\nTruong khoa: "<<x[i].TruongKhoa;
	}
	cout<<"\nNhap so ban: "; cin>>m;
	for(int i=0;i<m;i++){
		cout<<"\nThong tin cho ban thu "<<i<<" : ";
		cout<<"\nMa ban: "<<y[i].MaBan;
		cout<<"\nTen ban: "<<y[i].TenBan;
		cout<<"\nNgay thanh lap: "<<y[i].NgayTL;
	}
}

//bonus1:
void XOA(TRUONGDH &k){
	int VT = -1;
	for(int i=0;i<k.n;i++){
		if(strcmp(k.x[i].MaKhoa,"KH01")==0){
			VT = i;
			break;
		}
	}
	
	if(VT == -1){
		cout<<"\nKhong co ma khoa KH01";
	}else{
		for(int i=VT;i<k.n-1;i++){
			k.x[i] = k.x[i+1];	//dich trai
		}
	}
	
	k.n--;
}
int main(){
	TRUONGDH k;
	k.nhap();
	k.xuat();
	
	XOA(k);
	k.xuat(); 
}
