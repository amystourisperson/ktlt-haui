#include <iostream>
#include <string.h>
using namespace std;
class BENHNHAN;
class NGUOI{
	protected:
		char HOTEN[30];
		int TUOI;
	public:
		void nhap();
		void xuat();
		friend void CHANGE(BENHNHAN k[], int n);
};

void NGUOI::nhap(){
	cout<<"\nNhap ho ten: "; fflush(stdin); gets(HOTEN);
	cout<<"\nNhap tuoi: "; cin>>TUOI;
}

void NGUOI::xuat(){
	cout<<"\nHo ten: "<<HOTEN<<endl;
	cout<<"\nTuoi: "<<TUOI<<endl;
}

class BENHVIEN{
	private:
		char TENBV[30];
		char DIACHI[30];
		char GIAMDOC[30];
	public:
		friend class BENHNHAN;
	
	
};

class BENHNHAN : public NGUOI{
	private:
		char MA[30];
		char TIENSU[30];
		char CHUANDOAN[30];
		BENHVIEN x;
	public:
		void nhap();
		void xuat();
		friend void KiemTra(BENHNHAN k[], int n);
		friend void CHANGE(BENHNHAN k[], int n);
};

void BENHNHAN::nhap(){
	cout<<"\nNhap ma benh nhan: "; fflush(stdin); gets(MA);
	cout<<"\nNhap tien su benh nhan: "; fflush(stdin); gets(TIENSU);
	cout<<"\nChuan doan: "; fflush(stdin); gets(CHUANDOAN);
	
	cout<<"\n---Nhap thong tin benh vien---\n ";
	
	cout<<"\nNhap ten benh vien: "; fflush(stdin); gets(x.TENBV);
	cout<<"\nNhap dia chi: "; fflush(stdin); gets(x.DIACHI);
	cout<<"\nNhap giam doc: "; fflush(stdin); gets(x.GIAMDOC);
	
	NGUOI::nhap();
}

void BENHNHAN::xuat(){
	cout<<"\nMa benh nhan: "<<MA;
	cout<<"\nTien su benh nhan: "<<TIENSU;
	cout<<"\nChuan doan: "<<CHUANDOAN;
	
	cout<<"\n---Thong tin benh vien---\n ";
	
	cout<<"\nTen benh vien: "<<x.TENBV;
	cout<<"\nDia chi: "<<x.DIACHI;
	cout<<"\nGiam doc: "<<x.GIAMDOC;
	
	NGUOI::xuat();
}

//bonus1:
void KiemTra(BENHNHAN k[], int n){
	int dem = 0;
	for(int i=0;i<n;i++){
		if(k[i].TUOI > 30){
			dem ++; 
		}
	}
	cout<<"\nCo "<<dem <<" benh nhan lon hon 30 tuoi"<<endl;
}

//bonus2:
void CHANGE(BENHNHAN k[], int n){
	int dembn=0;
	for(int i=0;i<n;i++){
		if(strcmp(k[i].MA,"BN01")==0){
			k[i].TUOI  = 20;
			break;
		}else{
			dembn++;
		}
	}
	if(dembn==n-1){
		cout<<"\nKhong co benh nhan nao co ma la BN01"<<endl;
	}
}
int main(){
	int n;
	cout<<"\nNhap so luong benh nhan: "; cin>>n;
	BENHNHAN k[n];
	for(int i=0;i<n;i++){
		k[i].nhap();
	}

	cout<<"\n------THONG TIN VUA NHAP--------\n";
	for(int i=0;i<n;i++){
		k[i].xuat();
	}
	
	KiemTra(k,n);
	CHANGE(k,n);
	
	
	return 0; 
	
	
}
