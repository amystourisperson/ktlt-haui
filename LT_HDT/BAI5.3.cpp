#include <iostream>
using namespace std;

class TAMTHUC {
private:
    float a, b, c; // h? s? a, b, c
public:
    TAMTHUC(float x = 0, float y = 0, float z = 0) {
        a = x;
        b = y;
        c = z;
    }

    // Nap chong toan tu xuat
    friend ostream& operator<<(ostream& out, TAMTHUC t) {
        out << t.a << "x^2 ";
        if (t.b >= 0) out << "+ " << t.b << "x ";
        else out << "- " << -t.b << "x ";

        if (t.c >= 0) out << "+ " << t.c;
        else out << "- " << -t.c;

        return out;
    }

   //doi dau 2 tam thuc
    TAMTHUC operator-() {
        TAMTHUC temp;
        temp.a = -a;
        temp.b = -b;
        temp.c = -c;
        return temp;
    }

   
    TAMTHUC operator+(TAMTHUC x) {
        TAMTHUC k;
        k.a = a + x.a;
        k.b = b + x.b;
        k.c = c + x.c;
        return k;
    }

    TAMTHUC operator-(TAMTHUC x) {
        TAMTHUC k;
        k.a = a - x.a;
        k.b = b - x.b;
        k.c = c - x.c;
        return k;
    }
};

int main() {
    TAMTHUC t1(2, -3, 5);
    TAMTHUC t2(-1, 4, -2);

    cout << "Tam thuc 1: " << t1 << endl;
    cout << "Tam thuc 2: " << t2 << endl;

    // Ðoi dau hai tam thuc
    TAMTHUC dt1 = -t1;
    TAMTHUC dt2 = -t2;

    cout << "\nSau khi doi dau: " << endl;
    cout << "Tam thuc 1 (doi dau): " << dt1 << endl;
    cout << "Tam thuc 2 (doi dau): " << dt2 << endl;

    
    TAMTHUC tong = dt1 + dt2;
    TAMTHUC hieu = dt1 - dt2;

    cout << "\nTong hai tam thuc da doi dau: " << tong << endl;
    cout << "Hieu hai tam thuc da doi dau: " << hieu << endl;

    return 0;
}

