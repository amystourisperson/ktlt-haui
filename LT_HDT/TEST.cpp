#include <iostream>
#include <string>
using namespace std;
class SINHVIEN;
class KHOA
{
    char TENLOP[20];
    int SISO;
    char MALOP[10];
    public:
    friend class SINHVIEN; // Allow SINHVIEN to access private members of KHOA
    friend void SAPXEP(SINHVIEN k);
};

class SINHVIEN
{
    char HOTEN[20];
    int SOHSH;
    int TUOI;
    char MSSV[10];
    KHOA *x; // Pointer to an array of KHOA objects
    int n;
    public:
    void Nhap();
    void Xuat();
    friend void SAPXEP(SINHVIEN k);
   
};

void SINHVIEN::Nhap() {
    cout << "Nhap ho ten: ";
    fflush(stdin);
    gets(HOTEN);
    cout << "Nhap so hsh: ";
        fflush(stdin);
    cin >> SOHSH;
    cout << "Nhap tuoi: ";
        fflush(stdin); 
    cin >> TUOI;
    cout << "Nhap MSSV (so  + chu): ";
        fflush(stdin);
    gets(MSSV);
    cout<<"\nNhap n: ";
    cin>>n;
        x=new KHOA[n];
    for(int i=0; i<n; i++) {
        cout << "Nhap ten lop: ";
        fflush(stdin);
        gets(x[i].TENLOP);
        cout << "Nhap so si so: ";
        cin >> x[i].SISO;
        cout << "Nhap ma lop: ";
        fflush(stdin);
        gets(x[i].MALOP);
    }
}

void SINHVIEN::Xuat() {
    cout << "Ho ten: " << HOTEN << endl;
    cout << "So hsh: " << SOHSH << endl;    
    cout << "Tuoi: " << TUOI << endl;
    cout << "MSSV: " << MSSV << endl;   
    // Xuat thong tin khoa
    for(int i=0; i<n; i++) {
        // Assuming KHOA has a method to display its information
        cout << "Thong tin lop thu " << i+1 << ":" << "Ten lop: " << x[i].TENLOP << "So si so: " << x[i].SISO<<"Ma lop: " << x[i].MALOP << endl;

    }
}

// Example usage -> sx 

void SAPXEP(SINHVIEN k) {
    for(int i=0; i<k.n; i++) {
        for(int j=i+1; j<k.n; j++) {
            if(k.x[i].SISO > k.x[j].SISO) {
                // Assuming KHOA has a method to swap its elements -> not defined in the original code
                // Here we will just swap the elements directly
               swap(k.x[i], k.x[j]);
            }
        }
    }
}
int main(){
    SINHVIEN k;
    k.Nhap();
    k.Xuat();
    SAPXEP(k);
    cout << "Sau khi sap xep:\n";
    cout<<"\n---------------------------------\n";
    k.Xuat();
}
