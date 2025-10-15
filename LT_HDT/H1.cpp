#include <iostream>
#include <string>
using namespace std;
class TRUONG;  // Forward declaration of TRUONG class
class LOP
{
    char TENLOP[30];
    int MALOP;  
    int SOHSV;
    public:
    friend class TRUONG;  // Allow TRUONG to access private members of LOP
    friend void SAPXEP(TRUONG k); 
};

class TRUONG
{
    char TENTRUONG[30];
    char DIACHI[30];
    int MATRUONG;
    LOP *x;
    int n;  
public:
    void Nhap();    
    void Xuat();
    friend void SAPXEP(TRUONG k);  // Allow SAPXEP to access private members of TRUONG
};

void TRUONG::Nhap() {
    // Function to input data for TRUONG
    cout << "Nhap ten truong: ";
    fflush(stdin);
    gets(TENTRUONG);
    cout << "Nhap dia chi: ";
    fflush(stdin);
    gets(DIACHI);
    cout << "Nhap ma truong (numbers): ";
    fflush(stdin);
    cin >> MATRUONG;
    cout << "Nhap so lop (number): ";
    cin >> n;
    x = new LOP[n];
    for (int i = 0; i < n; i++) {
        cout << "Nhap thong tin lop thu " << i + 1 << ": " << endl;
        cout << "Nhap ten lop: ";
        fflush(stdin);  
        gets(x[i].TENLOP);
        cout << "Nhap ma lop (number): ";
        cin >> x[i].MALOP;
        cout << "Nhap so hoc sinh: ";
        fflush(stdin);
        cin>> x[i].SOHSV;  
        // Assuming LOP has a method to input its data
        // x[i].Nhap();
    }
}

void TRUONG::Xuat() {
    // Function to output data for TRUONG
    cout << "Ten truong: " << TENTRUONG << endl;
    cout << "Dia chi: " << DIACHI << endl;
    cout << "Ma truong: " << MATRUONG << endl;
    cout << "So lop: " << n << endl;
    for (int i = 0; i < n; i++) {
        cout << "Thong tin lop thu " << i + 1 << ": " << endl;
        cout << "Ten lop: " << x[i].TENLOP << endl;
        cout << "Ma lop: " << x[i].MALOP << endl;
        cout << "So hoc sinh: " << x[i].SOHSV << endl;
        // Assuming LOP has a method to output its data
        // x[i].Xuat();
    }
}

// Main function to demonstrate the usage of TRUONG class
// Note: The LOP class should also have methods for input and output if needed.
void SAPXEP(TRUONG k){
    for(int i=0;i<k.n;i++)
    {
        for(int j=i+1;j<k.n;j++)
        {
            if(k.x[i].SOHSV > k.x[j].SOHSV)  // Assuming SOHSV is an integer
            {
                swap(k.x[i], k.x[j]);  // Swap the LOP objects
                // Alternatively, you can implement a custom swap function if needed
            }
        }
    }
}

int main(){
    TRUONG k;
    k.Nhap();
    k.Xuat();
    // Clean up dynamically allocated memory if necessary
    SAPXEP(k);
    cout << "After sorting by number of students:" << endl;
    k.Xuat();








    delete[] k.x;  // Free the dynamically allocated memory for LOP array
    return 0;
}
