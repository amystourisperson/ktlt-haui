/*
#include <iostream>
#include <string.h>
#include <string>
#include <iomanip>
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
};

void PHUONGTIEN::nhap(){
    
    cout<<"\nMa PT: "; fflush(stdin); gets(MAPT);
    cout<<"\nLoai: "; fflush(stdin); gets(LOAI);
    cout<<"\nGia: "; cin>>GIA;
    cout<<"\nHang sx: "; fflush(stdin); gets(HANG_SX);
    
}

void PHUONGTIEN::xuat(){
    
    cout<<MAPT<<setw(15)<<LOAI<<setw(15)<<GIA<<setw(15)<<HANG_SX<<endl;
  
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
    friend void Sort(BAIXE &k);
    
};

void XEMAY::nhap()
{
    PHUONGTIEN::nhap();
    cout<<"\nMa Xe: "; fflush(stdin); gets(MAXE);
    cout<<"\nTen xe: "; fflush(stdin); gets(TENXE);
    cout<<"\nDung tich: "; cin>>DUNGTICH;
    cout<<"\nBien so: "; fflush(stdin); gets(BIENSO);
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
    friend void Sort(BAIXE &k);
    
};

void BAIXE::nhap()
{
    cout<<"\nMa BX: "; fflush(stdin);  gets(MABX);
    cout<<"\nTen BX: "; fflush(stdin); gets(TENBX);
    cout<<"\nDien tich: "; cin>>DIENTICH;
    cout<<"\nNhap so luong xe: ";
    cin>>n;
    
    x=new XEMAY[n];
    for(int i=0;i<n;i++)
    {
        x[i].nhap();
    }
    
}

void BAIXE::xuat()
{
    cout<<"\n----BAI XE-----\n";
    cout<<"\nMa BX: "<<MABX<<endl;
    cout<<"\nTen BX: "<<TENBX<<endl;
    cout<<"\nDien tich: "<<DIENTICH<<endl;
    cout<<"Ma Xe"<<setw(15)<<"Ten Xe"<<setw(15)<<"Dung Tich"<<setw(15)<<"Bien So"<<endl;
    for(int i=0;i<n;i++)
    {
        x[i].xuat();
    }
    
}

//sua ten

void SUA(BAIXE &k){
    strcpy(k.TENBX, "MAI DICH" );
}

void Sort(BAIXE &k){
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
    cout<<"\nBai xe cua ban sau khi sx"<<endl;
    Sort(k);
    k.xuat();
    
    return 0;
    
}
*/



//bai 2

// bai 2

#include <iostream>
#include <string>
#include <string.h>
#include <math.h>
#include <fstream>
using namespace std;

class BINHCHUA
{
    float dai, rong, cao;
    public:
    //phuong thuc khoi tao co do & khong doi
    BINHCHUA();
    BINHCHUA(float a, float b, float c);
    
    //ham toan tu
    
    bool operator-(BINHCHUA y);
    bool operator++();
    
    friend istream& operator>>(istream &x, BINHCHUA &y);
    friend ostream& operator>>(ostream &x, BINHCHUA &y);


    
};
//KHOI TAO KHONG DOI
BINHCHUA::BINHCHUA()
{
    dai=rong=cao=0;
    //if la con tro thi = NULL
}
//KHOI TAO CO DOI
BINHCHUA::BINHCHUA(float a, float b, float c)
{
    dai = a;
    rong = b;
    cao  = c;
}


istream& operator>>(istream &x, BINHCHUA &y)
{
    //o day x = cin 
    cout<<"\nNhap chieu dai: "; x>>y.dai;
        cout<<"\nNhap chieu rong: "; x>>y.rong;
    cout<<"\nNhap chieu cao: "; x>>y.cao;
    return x; // important !
}

ostream& operator>>(ostream &x, BINHCHUA &y)
{
     x<<"\nchieu dai: "<<y.dai<<endl;
        x<<"\nchieu rong: "<<y.rong<<endl;
    x<<"\nchieu cao: "<<y.cao<<endl;
}

bool BINHCHUA::operator-(BINHCHUA y)
{
    if(dai*rong*cao == y.dai*y.rong*y.cao)
    {
        return true;
    }
    return false;
}

bool BINHCHUA::operator++(){
    if(dai==rong && rong == cao && cao ==dai)
    {
        return true;
    }
    return false;
}

int main(){
    //khoi tao 2 binh chua
    BINHCHUA P, Q;
    cout<<"\nNhap thong tin binh chua thu 1: ";
    cin>>P;
    cout<<"\nNhap thong tin binh chua thu 2: ";
    cin>>Q;
    
    //tao tep
    ofstream f("BINHCHUA.txt", ios::app);
    if((P-Q)==true)
    {
        cout<<"\nHai binh chua co the tich bang nhau !"<<endl;
                f<<"\nHai binh chua co the tich bang nhau !"<<endl;
    }else
    {
              cout<<"\nHai binh chua khong co the tich bang nhau !"<<endl;
                f<<"\nHai binh chua khong co the tich bang nhau !"<<endl;
    }
    
    
    if(++P == true)
    {
        cout<<"\nBinh chua P la hinh lap phuong"<<endl;
                f<<"\nBinh chua P la hinh lap phuong"<<endl;
    }else
    {
        cout<<"\nBinh chua P  khong la hinh lap phuong"<<endl;
                f<<"\nBinh chua P khong la hinh lap phuong"<<endl;
    }
    
    return 0;
    
}

