/*
#include <iostream>
#include <vector> //khai bao thu vien vector
using namespace std;

//vector <int>v(5) la vector v = {0,0,0,0,0} rong
//vector <int>v[5] la 1 mang vector v co kdl la int 

int main(){
/*	//tao 1 vecto so nguyen v 
	vector<int> v;
	
	//khai bao vector voi n phan tu: vector <int>v(n)
	
	//day cac phan tu vao cuoi vec to
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	
//vector<int> v;
//v.push_back(10);
//v.push_back(20);
//Sau do v = {10, 20}

cout << v[1] << endl; -> xuat so 20 


int n = 3;
vector<int> v[3]; // mang gom 3 vector<int> v

v[0].push_back(10); // push vào vector thu 0
v[1].push_back(20); // push vào vector thu 1
v[2].push_back(30); // push vào vector thu 2
Ket qua:

v[0] = {10}

v[1] = {20}

v[2] = {30}
neu minh dung v[0].push_back(11) -> v[0] = {10,11}, neu muon truy xuat -> v[0][1]


//Neu v la vector<int> -> v[1] là mot so nguyen, kong dung push_back.
//Neu v là vector<vector<int>> -> v[1] la mot vector<int>, có the push_back.

vector<vector<int>> v;
v.push_back({1, 2, 3});   // them mot hang [1,2,3]   v = {(1,2,4)}
v.push_back({4, 5});      // them mot hang [4,5]     v = {(1,2,4),(4,5)}

cout << v[0][1]; // in ra 2
cout << v[1][0]; // in ra 4

Neu ban muon so hang cung thay doi duoc -> dùng vector<vector<int>>.
Neu ban biet so hang co dinh tu dau -> dung vector<int> v[n] (hoac vector<int> v[1000] neu gioi han hang toi da).

	//xuat kich thuoc vecto
	cout<<v.size()<<endl;
	
	//xuat tung phan tu cua vecto tu 0->n-1
	for(int i=0 ; i < v.size() ; i++){
		cout<<v[i]<<" ";
	}
	
	//cach xuat khac la no gan tung phan tu v vao x roi xuat
	//for-each
	for(int x : v){
		
		cout<<x<<" ";
	}
	cout<<"\n"; 
*/
	
/*	
	//mot cach khac la dung iterator
	vector<int>::iterator it; //khai bao 1 iterator
	
//v.end() la tro vao sau phan tu cuoi cung -> khi no tro vao v.end thi sai dkien ->dung
	for(it = v.begin();it != v.end();it++) 
	{
		cout<<*it<<" ";
		//toan tu giai tham chieu *
	}
*/	
	
	//cach nhap tung ptu tu ban phim vao vector
	//cach 1:
/*	int n;
	cin>>n;
	vector<int> v;
	for(int i=0;i<n;i++)
	{
		int t ;
		cin>>t;
		v.push_back(t);
	}
	
	for(int x : v){
		cout<<x<<" ";
	}
*/	
	//cach 2:
/*	int k;
	cin>>k;
	vector<int> v(k);
	for(int i=0;i<k;i++)
	{
		cin>>v[i];
	}
	for(int x : v){
		cout<<x<<" ";
	}
*/

//cach nhap cho mang vector
/*
 int m;
    cin >> m;   // so phan tu moi hang
    vector<int> v[3];  // mang gom 3 vector<int>

    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < m; j++) {
            int x;
            cin >> x;
            v[i].push_back(x);   // them phan tu vao vector thu i
        }
    }

    // Xuat ra
    for(int i = 0; i < 3; i++) {
        for(int x : v[i]) cout << x << " ";
        cout << "\n";
    } 
    
    //Cach khoi tao truc tiep
    vector<int> v[3] = {
    {1, 2, 3},   // hàng 0
    {4, 5},      // hàng 1
    {6, 7, 8, 9} // hàng 2
	};
*

/*
	//Ham insert
	//Chuc nang: chen 1 ptu vao vtri bki trong vector thong qua iterator
	//Cu phap: v.insert(Vtri iterator, val)
	int n;
	cin>>n;
	vector <int>v(n);
	for(int i=0;i<n;i++)
	{
		cin>>v[i];
	}
	vector<int>::iterator it = v.begin()+3; //iterator tro to ptu chi so 3 trong mang
	cout<<*it<<endl;
	
	//chen ptu vao vtri

	v.insert(v.begin()+3, 100); //v.insert(it, 100); it chi vtri chen *it chi gtri o vtri do
	
	cout<<"\nMang sau khi chen"<<endl;
	for(int i=0;i<n;i++)
	{
		cout<<v[i]<<" ";
	}
}
*/	
	//Ham erase
	//Chuc nang: Xoa 1 ptu trong vector thong qua iterator
	//Cu phap: v.erase(Vtri iterator)  //tim kiem vtri cua no bang cach dung iterator kh xoa truc tiep gtri dc
	
	//xoa ptu o chi so 3
	//v.erase(v.begin()+3); //auto it = v.find(v.begin(), v.end(), 3) (tim so 3 trong vector va tro toi vtri so 3)
	
	
	//Ham pop_back
	//Chuc nang: Xoa ptu cuoi cung trong vector
	//Cu phap: v.pop_back();
	
	//Ham assign
	//Chuc nang: Gan cac phan tu trong vector voi cung 1 gia tri
	//Cu phap: v.assign(so ptu,val);
//	vector<int> v;
//	v.assign(5,100);
//	->output: 100 100 100 100 100
	
	//Ham resize
	//Chuc nang: Thay doi kich thuoc cua vector
	//Cu phap: v.resize(n);  





//Pair 
/*
#include <iostream>
#include <vector>
using namespace std;
int main(){
/*	//thanh phan thu 1(first) co kdl la int, 2(second) la int
	pair<int,int> p;
	
	p.first = 100;
	p.second = 200;
	//no co hinh dang nhu nay -> p = {100,200}
	cout<<p.first<<" "<<p.second<<endl;
//gan cho thang p
	pair<int,int>p = make_pair(100,200);
	pair<int,int>p ={100,200};
/*	
//cach tao 1 mang pair de luu toa do
	int n;
	cin>>n;
	pair<int,int>a[n];
	for(int i=0;i<n;i++){
		cin>>a[i].first;
		cin>>a[i].second;
	}
*/
/*
//khong thich luu vao trong mang pair thi co dung vector pair
 	vector< pair<int,int> >v;
 	for(int i=0;i<n;i++){
 		int x, y;
 		cin>>x>>y;
 		v.push_back({x,y}); //v[i] = ({x,y},{z,t},...) 
	}
	
	//duyet mang vector pair
	for(int i=0;i<n;i++)
	{
		cout<<v[i].first<<" "<<v[i].second<<endl;
	}


}

*/




/*
//Sort voi vector va mang	
#include <iostream>
#include <algorithm>
using namespace std;
int main(){
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	
	//sx mang a tang dan
	sort(a, a+n); //no nam trong thu vien <algorithm>
	//sx giam dan 
//	sort(a, a+n, greater<int>());
	
	for(int i=0;i<n;i++)
	{
		cout<<a[i]<<" ";
	}
	
	//neu la vector de sx : sort(v.begin(), v.end());
}

*/



/*
#include <iostream>
#include <algorithm>
using namespace std;

//comparison function : ham so sanh
//--x la ptu dung truoc, y la ptu dung sau
//--neu x va y da dung thu tu ma ban muon sx => tra ve true
//--neu x va y nguoc thu tu ma ban muon sx => tra ve false

//ham tinh tong cac so cua 1 so 
int tong(int n){
	int sum = 0;
	while(n){  //voi so nguyen khac 0 thi la true, bang 0 thi la false 
		sum += n%10;  //sum = 0 + 3 = 3
		n/=10;  //n = 123/10 = 12
	}
	return sum;    //123 = 1+2+3
}

bool comp(int x, int y){
	if(x < y) //x>y ->sx giam dan
	{
		return true;
	}
	else
	{
		return false;
	}
	
	//hoac ta co the sx tong chu so tang dan
//	if(tong(x) < tong(y)) 
//	{
//		return true;
//	}
//	else
//	{
//		return false;
//	}
} 
int main(){
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	
	sort(a,a+n,comp);  //greater<int>() von no da dc d/n la sx giam dan
	
//khi sx tong chu so tang dan neu co tieu chi hoi la th nao xh truoc thi se in ra truoc
//vd: input 62 3 4 26 511 300 111 30 ->output 3 300 111 30 4 511 62 26
//ta thay sort -> stable_sort  (A 30), (B, 29) , (C, 30) -> (B,29), (A,30), (C,30)
	for(int i=0;i<n;i++){
		cout<<a[i]<<" ";
	}
}
*/


//Bai1:
/*
Cho Mang a[] gom n phan tu, ban hay sx cac ptu trong mang theo y/c sau
+) Sx sluong chu so chan xuat hien trong so tang dan, neu 2 so con cung sl chu so chan thi so nho hon in truoc
+) Sx theo sluong chu so le xh trong so ban dau tang dan, neu 2 so co cung so luong chu so le thi so nao xh trc
thi se in ra truoc
*/
/*
#include <iostream>
using namespace std;

//ham tra ve sl so chan
int chan(int n){
	int cn=0;
	//vd 1234 = 2 & 4 =>  dem = 2
	while(n){
		if(n%10%2==0) //check chu so cuoi cung
		{
			cn++;
		}
		n/=10;
	}
	return cn;
}

bool comp(int a, int b){
//ktra sl chu so chan 
	if(chan(a) != chan(b)){
		return chan(a) < chan(b); //khac sl => sx theo sl
	}
	else //TH: co cung so luong
	{
		return a < b ; //sx tang dan th nao nho hon thi in ra truoc
	}
	
}

int le(int n){  //dem sl chu so le nhu bth
	int dem = 0;
	while(n){
		if(n%10%2 ==1){
			dem++;
		}
		n/=10;
	}
	return dem;
}

bool comp2(int a, int b){
	return le(a) < le(b);  //sx theo sl
}
int main(){
	int n;
	cin>>n;
	int a[n];
	int b[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
		b[i] = a[i];
	}
	
	//tieu chi 1
	sort(a,a+n,comp);
	for(int i=0;i<n;i++){
		cout<<a[i]<<" ";
	}
	
	// khi sort tieu chi 1 thi mang da bi lon tung pheo -> sao chep sang mang b
	
	cout<<"\n";
	//tieuchi 2
	stable_sort(b,b+n,comp2); 
		for(int i=0;i<n;i++){
		cout<<b[i]<<" ";
	}

}
*/

