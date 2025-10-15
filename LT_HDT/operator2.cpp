//Bai 1:
#include <iostream>
#include <string.h>
#include <iomanip>
#include <math.h>
using namespace std;
class BAIXE;
class PHUONGTIEN{
	protected:
		char MaPT[30];
		char LOAI[30];
		int GIA;
		char HANG_SX[20];
	public:
		void nhap();
		void xuat();
};

void PHUONGTIEN::nhap(){
	cout<<"\nNhap ma phuong tien: "; fflush(stdin); gets(MaPT);
	cout<<"\nNhap loai xe: "; fflush(stdin); gets(LOAI);
	cout<<"\nNhap gia: "; cin>>GIA;
	cout<<"\nNhap hang san xuat: "; fflush(stdin); gets(HANG_SX);
}

void PHUONGTIEN::xuat(){
    cout<<"\nMa PT: "<<MaPT;
    cout<<"\nLoai: "<<LOAI;
    cout<<"\nGia: "<<GIA;
    cout<<"\nHang San Xuat: "<<HANG_SX;
}

class XEMAY : public PHUONGTIEN
{
    private:
    char MAXE[30];
    char TENXE[30];
    int DUNGTICH;
    char BIENSO[30];
    public:
    void nhap();
    void xuat();
    friend void SORT_BX(BAIXE k);
    friend void chenMon(BAIXE &k);
    friend void xoaXE(BAIXE &k, const char *delete_name);
};

void XEMAY::nhap(){
	PHUONGTIEN::nhap();
	cout<<"\nNhap ma xe: "; fflush(stdin); gets(MAXE);
	cout<<"\nNhap ten xe: "; fflush(stdin); gets(TENXE);
	cout<<"\nNhap dung tich: "; cin>>DUNGTICH;
	cout<<"\nNhap bien so: "; fflush(stdin); gets(BIENSO);
}

void XEMAY::xuat(){
	PHUONGTIEN::xuat();
	cout<<"\nMa xe: "<<MAXE<<setw(15)<<"Ten Xe: "<<TENXE<<endl;
	cout<<"\nDung tich: "<<DUNGTICH<<setw(15)<<"Bien So: "<<BIENSO<<endl;
}

class BAIXE{
	private:
		char MABX[30];
		char TENBX[30];
		int DIENTICH;
		int n;
		XEMAY x[100];
	public:
		void nhap();
		void xuat();
		friend void CHANGE_NAME(BAIXE &k);
		friend void SORT_BX(BAIXE k);
		friend void chenXE(BAIXE &k);
		friend void xoaXE(BAIXE &k, const char *delete_name);
};

void BAIXE::nhap(){
	cout<<"\nNhap ma bai xe: "; fflush(stdin); gets(MABX);
	cout<<"\nNhap ten bai xe: "; fflush(stdin); gets(TENBX);
	cout<<"\nNhap dien tich bai xe: "; cin>>DIENTICH;
	cout<<"\nTot lam ! Vay bai xe cua ban co bao nhieu chiec: "; cin>>n;
	
	for(int i=0;i<n;i++){
		cout<<"\nNhap thong tin cho xe thu "<<(i+1)<<endl;
		x[i].nhap();
	}
}

void BAIXE::xuat(){
	cout<<"\n----Bai Xe----\n";
	cout<<"\nMa bai xe: "<<MABX;
	cout<<"\nTen bai xe: "<<TENBX;
	cout<<"\nDien tich bai xe: "<<DIENTICH;
	cout<<"\n-----Thong tin cac xe trong bai----\n";
	
	for(int i=0;i<n;i++){
		cout<<"\nThong tin xe thu "<<(i+1)<<endl;
		x[i].xuat();
	}
}

//bonus1: re_name
void CHANGE_NAME(BAIXE &k){
	strcpy(k.TENBX, "MAI DICH");
}

//bonus2: sxep
void SORT_BX(BAIXE k){
	for(int i=0;i<k.n-1;i++){
		for(int j=i+1;j<k.n;j++){
			if(k.x[i].DUNGTICH > k.x[j].DUNGTICH){
				XEMAY temp = k.x[i];
				k.x[i] = k.x[j];
				k.x[j] = temp;
			}
		}
	}
}

//bonus3:  chen
void chenXE(BAIXE &k){
	cout<<"\nNhap thong tin can chen: ";
	XEMAY m;
	m.nhap();
	k.x[k.n] = m;  // chen vao cuoi
	k.n++;         // tang so luong môn
}

//bonus4:  xoa
void xoaXE(BAIXE &k, const char *delete_name){
	//tim vi tri de xoa
	int VT = -1;
	for(int i=0;i<k.n;i++){
		if(strcpy(k.x[i].TENXE,delete_name)==0){
			VT = i;
			break;
		}
	}
	
	//thuc hien xoa
	if(VT == -1){
		cout<<"\nKhong tim thay xe can xoa"<<endl;
	}else{
		for(int i = VT;i<k.n-1;i++){
			k.x[i] = k.x[i+1]; //dich trai
		}
		k.n--;
		cout<<"\nDa Xoa Thanh Cong !"<<endl;
	} 
	
}


int main(){
	BAIXE k;
	k.nhap();
	k.xuat();
	CHANGE_NAME(k);
	SORT_BX(k);
	k.xuat();
	chenXE(k);
	k.xuat();  
	
	xoaXE(k,"Honda");
	k.xuat(); 
	
	return 0;  
}
