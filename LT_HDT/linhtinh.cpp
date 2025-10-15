#include <iostream>
#include <math.h>
using namespace std;
int main(){
	int n;
	cout<<"\nNhap so luong phan tu: ";
	cin>>n;
	int a[n];

	
	cout<<"\n---liet ke ----\n";
	for(int i=0;i<n;i++){
		cout<<"\nNhap gia tri cho phan tu thu "<<(i+1)<<": ";
		cin>>a[i];
	}
	cout<<"\nTap R = {";
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(a[i]%a[j] == 0){
				cout<<"("<<a[i]<<","<<a[j]<<")"<<" ";
			}
		}
	}
	cout<<"}";
}
