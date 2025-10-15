
//Chua BTap

//Bai 1: Kiem tra mang tang dan
/*
Kiem tra xem mang da cho co tang chat hay khong, tuc la cac phan tu dung sau luon
lon hon phan tu dung truoc no
*/

/*
#include <iostream>
using namespace std;
int main(){
	int n;
	cin>>n;
	int a[n];
	
	for(int &x : a){
		cin>>x;
	}
	
	for(int i = 1; i<= n ;i++){
		if(a[i] <= a[i-1]){
			cout<<"\nNO";
			return 0;
		}
	}
	cout<<"\YES";
}
*/

//Bai 2: So lon hon cac so dung truoc
/*
Cho mot day so nguyen duong co n phan tu. Hay liet ke so cac phan tu trong day lon hon
tat ca cac so dung truoc no (Phan tu dau tien duoc coi la 1 ptu thoa man)
*/
/*
#include <iostream>
using namespace std;
int main(){
	int n;
	cin>>n;
	int a[n];
	
	for(int &x : a){
		cin>>x;
	}
	
	int max_value = a[0];
	cout<<a[0]<<" ";
	for(int i = 1; i<= n;i++){
		if(a[i] > max_value)
		{
			cout<<a[i];
			max_value = a[i]<<" ";
		}
	}
}

*/

//Bai 3: Die Hard
/*
Bo phim "Die Hard" vua moi phat hanh. Co n nguoi tai phong ve rap chieu phim dung thanh mot hang
lon. Moi nguoi trong so ho co mot to tien menh gia 100, 50 hoac 25. Mot ve "Die Hard" co gia 25
Nhan vien dat phong co the ban ve cho moi nguoi va tra tien thua neu ban dau anh ta khong co tien
va ban ve theo dung thu tu moi nguoi trong hang khong
input: 
Dong dau tien chua cac so nguyen n - so nguoi trong hang. Dong tiep theo chua n so nguyen, 
moi so bang 25,50 hoac 100 - gia tri cua cac to tien ma moi nguoi co
output: 
in YES neu nguoi ban hang co the ban va tra tien thua cho moi nguoi trong hang, nguoc lai in NO
5
25 25 25 50 50 -> YES
*/

/*
#include <iostream>

bool check (int a[], int n){
	//khong can quan tam trong tay anh ta co bao nhieu to 100 vi 100 khong de tra lai tien gi duoc
	int dem25 = 0, dem50 = 0;
	for(int i =0;i<n;i++){
		if(a[i] == 25){  //truong hop dua to 25
			dem25++;
		}else if(a[i] == 50){  //truong hop dua to 50
			if(dem25 == 0){
				return false; //khong co tien 25 tra lai
			}
			else
			{
				dem25 --;
				dem50++;
			}
		}else{  //truong hop dua to 100
			if(dem25 == 0 || dem25*25 + dem50 *50 < 75)  //khi khong co to 25 thi 100 to 50 cung kh giai quye dc vde
			{
				return false;
			}else if(dem50 != 0){ //khi co to 50 thi se tra bang 1 to 50 va 1 to 25
				dem50--;
				dem25--;
			}else{ ///khong co to 50 nao
				dem25 = dem25 - 3;
			}
		}
	}
	return true;
}
using namespace std;
int main(){
	int n;
	cin>>n;
	int a[n];
	
	for(int &x : a){
		cin>>x;
	}
	if(check(a,n)){
		cout<<"YES";
	}
	else{
		cout<<"NO";
	}
}
*/

//Bai 4: Dem cap so nguyen to cung nhau
/*
Cho mot day so nguyen duong co n phan tu. Hay dem cac cap so nguyen to cung nhau trong mang
5
2 4 8 3 6
->3
*/

/*
#include <iostream>
#include <algorithm>
using namespace std;
int main(){
	int n;
	cin>>n;
	int a[n];
	
	for(int &x : a){
		cin>>x;
	}
//UCLN cua 2 so nguyen a va b la so nguyen duong lon nhat ma ca a va b deu chia het cho no	
//Hai so nguyen goi la nguyen to cung nhau neu UCLN cua chung bang 1
//Hai so nguyen duong dgl cap so nguyen to cung nhau neu UCLN cua chung bang 1
//Noi cach khac: Chung khong co uoc chung nao khac ngoai 1
//vd: (8,15):
//Uoc cua 8 = {1,2,4,8}
//Uoc cua 15 = {1,3,5,15}
//->UCLNN la 1 -> gcd(8,15) == 1 ->nguyen to cung nhau

	int ans = 0;
	for(int i =0; i<n;i++){
		for(int j = i+1;j<n;j++){
			if(__gcd(a[i], a[j]) == 1)
			{
				ans++;
			}
		}
	}
	cout<<ans<<endl;
}
*/



//Bai 5: Sx chan le
/*
Cho mot mang cac so nguyen, sx cac phan tu trong mang sao cho, cac phan tu le dung truoc va giam dan
cac phan tu chan dung sau va tang dan
*/

//cach 1:
/*
#include <iostream>
using namespace std;
int main(){
	int n;
	cin>>n;
	vector<int> chan, le;
	for(itn i = 0; i<=n;i++){
		int tmp;
		cin>>tmp;
		if(tmp%2==0){
			chan.push_back(tmp);
		}
		else
		{
			le.push_back(tmp);
		}
	}
	
	sort(chan.begin(), chan.end());
	sort(le.begin(), le.end(), greater<int>());
	for(int x: le) cout<<x<<" ";
	for(int x: chan) cout<<x<<" ";
}
*/



//cach 2:
/*
#include <iostream>
#include <algorithm>

//giai thich chut ve ham sort

//cmp(a, b) tra ve true neu muon a dung truoc b trong mang da sap xep.
//Neu tra ve false, thi a se dunng sau b.

bool cmp(int a, int b){
	int r1 = a%2, r2 = b %2; 
	if(r1 != r2){  //khac nhau ve tinh chan le
		if(r1 == 1 && r2 == 0) //neu thang dung trc la le, dung sau la chan
		{
			return true; // a dunng truoc b
		}
		else
		{
			return false; //a chan, b le -> a dung sau b
		}
	}else
	{
		if(r1 == 1 && r2 == 1){
			return a>b; //so le lon hon dung truoc (giam dan)
		}
		else
		{
			return a<b; //// so chan nho hon dunng truoc (tang dan)
		}
	}
}


using namespace std;
int main(){
	int n;
	cin>>n;
	int a[n];
	for(int i = 0; i <= n; i++){
		cin>>a[i];
	}
	sort(a, a+n, cmp);
	for(int x : a){
		cout<<x<<" ";
	}
}

*/

//Bai 6: Tron 2 day da sap xep
/*
Cho 2 mang da duoc sap xep tang dan, thuc hien tron 2 day tren thanh 1 day duoc sx
*/

/*
#include <iostream>
using namespace std;
int main(){
	int n,m;
	cin>>n>>m;
	int a[n], b[m];
	for(int &x : a){
		cin>>x;
	}
	for(int &x : b){
		cin>>x;
	}
	int i = 0; //chay cho mang a
	int j = 0; //chay cho mang b
	while(i<n && j<m){
		if(a[i] <= b[j]){
			cout<<a[i]<<" ";
			i++;
		}else
		{
			cout<<b[j]<<" ";
			j++;
		}
	}
	//khi ma 1 trong 2 mang van con ptu
	while( i < n){
		cout<<a[i]<<" ";
		i++;
	}
	while(j<m){
		cout<<b[j]<<" ";
		j++;
	}
}

*/


//Bai 7: Dem tan suat
/*
Cho mang cac so nguyen khong am gom n phan tu, thuc hien dem tan suat xuat hien cua cac phan tu
va in theo mau
*/

//cach 1:
/*
#include <iostream>
using namespace std;
int main(){
	int n;
	cin>>n;
	map<int,int> mp;
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
		mp[a[i]]++;
	}
	
	//duyet theo thu tu tu be den lon
	for(auto it : mp){   
		cout<<it.first<<" "<<it.second<<endl;
	}
	
//	for(auto it = mp.begin(); it != mp.end(); it++){
//		cout<<(*it).first<<" "<<(*it).second<<endl;
//	}
	
	//duyet theo thu tu xuat hien
	for(int i= 0 ; i < n;i++){
		if(mp[a[i]] != 0){
			cout<<a[i]<<" "<<mp[a[i]]<<endl;
			mp[a[i]] = 0;
		}
	}
}
*/

//cach 2: dung mang danh dau
#include <iostream>

using namespace std;

int cnt[10000001] = {0};  //0->10^7

int main(){
	int n;
	cin>>n;
	int a[n];
	int max_val = -10e9;
	for(int i = 0;i<n;i++){
		cin>>a[i];
		cnt[a[i]]++;
		max_val = max(max_val, a[i]);
	}
	
	//in ra cac ptu theo tt tu be den lon
	for(int i =0 ;i<=max_val;i++){
		if(cnt[i] != 0){
			cout<<i<<" "<<cnt[i]<<endl;
		}
	}
	
	//in theo thu tu xuat hien
	for(int i =0;i<n;i++){
		if(cnt[a[i]] != 0){
			cout<<a[i]<<" "<<cnt[i]<,endl;
			cnt[a[i]] = 0;
		}
	}
}

