#include <iostream>
using namespace std;
class MATRIX{
	private:
		int n;
		int m;
		double a[100][100];
	public:
	friend istream& operator>>(istream& in, MATRIX &x);	
	friend ostream& operator<<(ostream& out, MATRIX x);
	MATRIX operator -();
	MATRIX operator / (MATRIX x);
	MATRIX operator + (MATRIX x); 
	
};

istream& operator>>(istream& in, MATRIX &x)
{
	cout<<"\nNhap n: "; in>>x.n;
	cout<<"\nNhap m: "; in>>x.m;
	//x.a[x.n][x.m];
	cout<<"\nNhap gia tri cho ma tran: "<<endl;
	for(int i=0;i<x.n;i++){
		for(int j=0;j<x.m;j++){
			in>>x.a[i][j];
		}
	}
	
	return in;
}

ostream& operator<<(ostream& out, MATRIX x){
	for(int i =0;i<x.n;i++){
		for(int j=0;j<x.m;j++){
			out<<x.a[i][j]<<"\t"; 
		}
		out<<"\n";
	}
	return out;
}

MATRIX MATRIX::operator -(){
	MATRIX temp;
	temp.n = n;
	temp.m = m;
	for(int i = 0;i<n;i++){
		for(int j=0;j<m;j++){
			temp.a[i][j] = -a[i][j];
		}
	}
	return temp;
}

MATRIX MATRIX::operator +(MATRIX x){
	MATRIX z;
	z.n = n;
	z.m = m;
	for(int i = 0;i<n;i++){
		for(int j=0;j<m;j++){
			z.a[i][j] = a[i][j] + x.a[i][j];
		}
	}
	return z;
}

MATRIX MATRIX::operator /(MATRIX x){
	MATRIX q;
	q.n = n;
	q.m = m;
	for(int i = 0;i<n;i++){
		for(int j=0;j<m;j++){
			q.a[i][j] = a[i][j] - x.a[i][j];
		}
	}
	return q;
}


int main(){
	MATRIX k;
	MATRIX t;
	cout<<"\nNhap ma tran thu 1"<<endl;
	cin>>k;
	cout<<"\nNhap ma tran thu 2"<<endl;
	cin>>t;
	cout<<"\nMa tran 1 sau khi nhap"<<endl;
	cout<<k;
	cout<<"\nMa tran 2 sau khi nhap"<<endl;
	cout<<t;
	
	MATRIX el = -k; //doi dau ma tran thu 1
	MATRIX es = -t; //doi dau ma tran thu 2
	
	cout<<"\nMa tran 1 sau khi doi dau"<<endl;
	cout<<el;
	cout<<"\nMa tran 2 sau khi doi dau"<<endl;
	cout<<es;
	
	//Cong 2 ma tran
	cout<<"\nCong 2 ma tran"<<endl;
	cout<<k + t<<endl;
	//TRU 2 ma tran
	cout<<"\nTru 2 ma tran"<<endl;
	cout<<k / t<<endl;
	
	//neu muon cong 2 ma tran sau khi doi dau thi thay k va t => el va es
	
	return 0;
}
