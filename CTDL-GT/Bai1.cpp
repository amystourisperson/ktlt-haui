/*
#include <iostream>
#include <math.h>
using namespace std;
bool snt(int k);
int main(){
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		if(snt(i))
		{
			cout<<i<<" ";
		}
	}
}

bool snt(int k)
{
	if(k<=2)
	{
		return false;
	}
	for(int i=2;i<=sqrt(k);i++)
	{
		if(k%i==0)
		{
			return false;
		}
	}
	return true;
}

//boi cua 1 so nguyen to -> khong phai la snt   (vd: snt la 3 thi boi cua no la 6 9 12 15 ko phai la snt) 
*/

/*
//-Dieu kien: gioi han sang <=10^7
#include <iostream>
#include <math.h>
using namespace std;
bool p[1000001];

//ham sang snt
void sang_snt(){
	
	//Ban dau coi tat ca cac so tu 0 -> n deu la snt
	for(int i=0;i<=100000;i++)
	{
		p[i]=true;
	}
	//loai thu cong cho 2 so dau kh phai la snt
	p[0]=false;
	p[1]=false;
	for(int i=2;i<=sqrt(1000000);i++)
	{
		//neu i la snt =>loai boi cua i (boi cua i thi no kh phai la snt)
		if(p[i]){
			//bat dau tu boi i*i 
			//vd tu 2 -> 4 , 3 -> 9 (bo qua 6 vi i=2 no da duyet qua roi)
			//roi no cu nhay dup (j=9, j=9+3=12, j=12+3=15..)  //duyet cac boi cua no 
			for(int j=i*i;j<=1000000;j+=i) //tai sao j chay toi 1tr ? -> i chay toi 1000 ->1000*1000 =1tr
			{
				p[j]=false;
			}
		}
	}
}

int main(){
	sang_snt();
	//kiem tra xem so 17 co phai la snt khong
	if(p[17]){
		cout<<"\n OK !\n";
	}	
}
*/

/*
//cach sang khac la sang tu l - r (vd:10->20)
//dkien: r-l <= 10^7 (k/c giua 2 so)

#include <iostream>
#include <math.h>
#include <cstring>
using namespace std;

void sang(int l, int r){
	bool p[r-l+1];
	memset(p,true,sizeof(p)); //gan cho mang p = true
	for(int i=2;i<=sqrt(r);i++)
	{
		//thay vi duyet tu 4,6,8 ta dung cthuc nay de duyet tu l -> r 
		//vd: 505->1000, ta chi duyet tu 506,...
		for(int j=max(i*i,(l+i-1)/i *i);j<=r;j+=i){
		//j=11, l=10  (10->20) 
			p[j-l] = false; //neu la p[j] thi mang ban co co la r vi no chay den r
			//p[0] = p[10] = false
			//p[1] = p[11] = true
			//p[2] = p[12] = false
		}
	}
	for(int i=l;i<=r;i++)  //duyet tu l -> r
	{
		if(p[i-l]) //neu la true thi cout 
		{
			cout<<i<<" ";
		}
	}
}

int main(){
	sang(100,5000);
	
	
	return 0;
}
*/


//Ly thuyet dong du
//Cong thuc: 
/*
su dung khi bi tran bo nho 
(A+B)%C = ((A%C) + (B%C))%C
(A-B)%C = ((A%C) - (B%C))%C
(A*B)%C = ((A%C) * (B%C))%C
(A/B)%C = ((A%C) * (B^-1%C))%C  (B^-1 la nghich dao modul cua B)
*/
/*
#include <iostream>
#include <math.h>
using namespace std;
//1e16 = 1*10^16
int main(){
	//cout<< (((long long)1e16 % 7)*((long long)1e13 % 7)) % 7;
	int n;
	cin>>n;
	long long gt = 1;
	//cung dung ly thuyet dong du (cai duoi nay la ly thuyet dong du)
	//nhan den dau chia du den day -> tranh tran
//bai la tinh n! chia du cho 10^9+7
	for(int i=1;i<=n;i++)
	{
		gt*=i;
		gt%=1000000007;
	}
	cout<<gt%1000000007<<endl;
	//(3*4*5*6%7)  = ((3%7)*(4%7)..)%7
	//khoi tao res = 1
	//res *3  = 3 roi chia du cho 7 =3
	//res dc luu la 3 ->3*4 = 12%7 = 5*5(5 la 3*4*5*6) =25%7=4*6=24%7 = 3
	
}
*/




//Luy thua nhi phan
/*
de tinh a^b ta co the tinh dua vao 3 cach
+)
    a = 1 neu b = 0
+)
    a^(b/2) * a^(b/2) neu b chan
+)  
	a^(b/2) * a^(b/2) * a neu b le    
*/
#include <iostream>
using namespace std;
long long binPow(long long a, long long b){
	if(b==0)
	{
		return 1;
	}
	long long x = binPow(a,b/2);  //x = a^(b/2)
	
	if(b%2==1)
	{
		return x*x*a;
	}
	else
	{
		return x*x;
	}
}
int main(){
	cout<<binPow(2,10); 
}	
//co anh giai thich trong zalo 
