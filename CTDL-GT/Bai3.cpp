/*
#include <iostream>
#include <algorithm>
using namespace std;

//Binary_search : do phuc tap O(logN) (Tim kiem cho mang tang dan)
//linear search (tim kiem tuan tu trong mang co chua ptu nao do khong (khi bi sx ltinh) )
int main(){
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	sort(a, a+n); //sx tang dan de dung binary sort
	if(binary_search(a,a+n,3)){
		cout<<"YES\n";
	}
	else{
		cout<<"NO\n";
	}
}
*/

/*
#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

//set : CTDL : O(logN)
//Uu diem: Tim kiem nhanh, Xoa nhanh

int main(){
/*
	//khai bao
	set<int> se;
	
	//Ham insert: Them 1 ptu trong set
	se.insert(5);
	se.insert(3);
	se.insert(2);
	se.insert(4);
	se.insert(5); //ptu trung nhau
	//set no se tu sx tang dan
//t/c: set Khong luu dc cac ptu trung nhau -> cac ptu trong set phai khac nhau	

	cout<<se.size() <<endl;
	
	for(int x : se){
		cout<<x<<" ";  
	}
*/
	
	//vd de bai y/c: Cho mang a[], co bnhieu gia tri khac nhau?
/*
	set<int> se;
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		int x;
		cin>>x;
		se.insert(x);
	}
	//boi vi no sx va loai cac ptu giong nhau -> tim dc sl ptu khac nhau
	cout<<se.size()<<endl;
*/	

/*
	//Ham find: ktra su ton tai cua 1 ptu nao do trong set, day la 1 ham dc sd rat nhieu trong set

//auto it = find(v.begin(), v.end(), 30)  -> Tim phan tu co gia tri 30 trong vector
-> tra ve iterator tro toi phan tu do

	set<int> se;
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		int x;
		cin>>x;
		se.insert(x);
	}
	
	//set tim gia tri dc nhung ma trong vector thi khong the find(gtri)
	
	auto it = se.find(5);  //auto it: de trinh bien dich tu dong suy ra kieu du lieu cua it 
	//(o day chinh la kieu iterator tuong ung voi container se).
	
	if(it == se.end()){  //it tro toi vtri se.find()
		cout<<"NOT FOUND\n";
	}
	else
	{
		cout<<*it<<endl;  //xuat ra gtri
	}
}

//tom lai: 
//auto it = se.find(gtri)  (voi set)
//auto it = find(v.begin(), v.end(), 30)   (voi vector)

*/
/*	
	//Ham count thay cho ham find cung dc
	//Ham nay dung de dem so lan xuat hien cua 1 phan tu trong set, doi voi set thi
	//1 ptu se xh 1 hoac 0 lan  //vi trong set thi moi ptu chi dc xh 1 lan or 0 lan
	set<int> se;
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		int x;
		cin>>x;
		se.insert(x);
	}
	if(se.count(3) != 0){
		cout<<"Tim Thay";
	}else{
		cout<<"Khong tim thay";
	}
*/

/*	
	//Ham erase: Xoa 1 ptu khoi set, truoc khi su dung ham erase hay dam bao ptu ban can xoa
	//ton tai trong set neu khong se xra loi runtime error
	set<int> se;
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		int x;
		cin>>x;
		se.insert(x);
	}
	
	se.erase(3);  //xoa so 3 trong set
	//vector thi chi xoa dc vi tri khong xoa dc gia tri nhu set 
	for(int x : se){
		cout<< x <<" ";
	}
*/

/*	
	//vidu: Quiz 1:
	int a[7] = {5, 5, 1, 2, 3, 5, 4};
	set<int> se(a, a+7); //lay 7 ptu dau cua mang a //truyen vao set 1 mang a
	auto it = se.find(7);  //do mang dc sx la 1 2 3 4 5 ->it se tro vao end vi kh tim thay 7
	it--;  //dich sang trai 1 dvi -> tro vao 5
	cout<< *it <<endl; //output = 5
*/

/*	
	//vidu: Quiz 2:
	int a[7] = {5, 5, 1, 2, 3, 5, 4};
	set<int> se(a, a+7);  //truyen vao set 1 mang a
	auto it = se.find(4); 
	it = it-2;  //set no chi ho tro -- voi ++ -> ERROR
	cout<< *it <<endl;
*/
	//muon xuat ra ptu nho nhat: cout<< *se.begin() <<endl;
	//muon xuat ra ptu lon nhat: cout<< *se.rbegin() <<endl;
/*			  
}
*/




//Bai1: Cho day so a[] gom co n ptu, ban hay trl cac truy van de xd xem ptu X nao do co nam trong
//mang hay khong ? Ban hay thu giai bai nay bang 3 cach:  Set, Map, Binary Search
/*
input:
-Dong dau tien la so nguyen n
-Dong thu 2 gom n so nguyen a[i]
-Dong thu 3 la so luong truy van Q
-Q dong tiep theo moi dong la 1 so nguyen X
output:
Doi voi moi truy van in ra YES neu ptu X xh trong mang, nguoc lai in ra NO
*/


/*
#include <iostream>
#include <algorithm>
#include <set>
using namespace std;
int main(){
	//neu dung thuat toan tim kiem tuan tu (linear search) thi se bi runtime error
//cach 1: dung binary_search	
/*
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	
	sort(a, a+n); //sx tang dan de co the dung binary_search
	
	int q;
	cin>>q;
	while(q--){
		cout<<"\ncheck lan thu"<<q<<endl;
		int x;
		cin>>x;
		if(binary_search(a, a+n, x)){
			cout<<"YES\n";
		}else{
			cout<<"NO\n";
		}
	}
*/	

/*
//cach 2: dung set

	int n;
	cin>>n;
	set<int> se;
	for(int i=0;i<n;i++){
		int x;
		cin>>x;
		se.insert(x);
	}
	int q;
	cin>>q;
	while(q--){
		int x;
		cin>>x;
		if(se.find(x) == se.end()){
			cout<<"NO\n";
		}else{
			cout<<"YES\n";
		}
	}
*/
	
//}


/*
//Bai 2: Cho day so a[] gom co n ptu, ban hay liet ke cac gia tri xh trong day theo thu tu xh,
//moi gtri chi lke 1 lan
/*
input: 
6
6 1 2 1 4 5
output:
6 1 2 4 5
*/
/*
#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
using namespace std;
int main(){
	int n;
	cin>>n;
	set<int> se;
	vector<int> v;
	int dem = 0;
	for(int i=0;i<n;i++){
		int x;
		cin>>x;
		
		if(se.find(x) == se.end())  //lan dau gap thi cho vao insert luon
		//neu no != se.end() -> thoat if
		{
//			cout<<x<<" "<<endl;  //nhap den dau xh den do luon
			se.insert(x);  //bo vao se.insert de tiep tuc ktra  
			v.push_back(x);
			dem++;
		}
		
	}
	cout<<"\n";
		for(int i=0;i<dem;i++){
			cout<<v[i]<<" ";
		}
	
}

*/


//Ham multiset sx cac ptu nma van co cac ptu trung nhau
//co the luu cac ptu trung nhau -> khong loai bo trung
/*
#include <iostream>
#include <algorithm>
#include <set>
using namespace std;
int main(){
	int n;
	cin>>n;
	multiset<int> se;
	for(int i=0;i<n;i++){
		int x;
		cin>>x;
		se.insert(x);
	}
	
	//find
	auto it = se.find(2); //tra ve iterator dau tien khi tim thay, con kh thim thay thi tra ve se.end()
	//se.erase(2) //xoa TAT CA cac ptu do
	//muon xoa 1 thang thi xoa thong qua iterator
	se.erase(it);
	for(int x : se){
		cout<<x<<" ";
	}
}
*/

//Bai 3: Cho day so a[] gom co n ptu, co 3 thao tac nhu sau: 
/*
-Thao tac 1: Them 1 ptu X vao mang
-Thao tac 2: Xoa 1 ptu X khoi mang. Trong truong hop ptu X khong xh trong mang, se khong thuc hien xoa
, neu trong mang co nhieu ptu X thi chi xoa di 1 ptu X trong mang.
-Thao tac 3: Truy van xem ptu X co xh trong mang hay khong ?
Ban dau mang A co n ptu, voi cac truy van ptu X trong mang, in ra YES neu X xh trong mang, ngc lai in ra NO
*/

/*
#include <iostream>
#include <algorithm>
#include <set>
using namespace std;


int main(){
	int n;
	cin>>n;

	multiset<int> ms;
	for(int i=0;i<n;i++){
		int x;
		cin>>x;
		ms.insert(x);
	}
	
	int q;
	cin>>q;
	
	while(q--){
		int tt, x;  //x(gtri) o day la ptu xoa, chen, tim kiem
		cin>>tt>>x;
		if(tt == 1)
		{
			ms.insert(x);
		}else if(tt == 2){
			auto it = ms.find(x);  //tro vao ptu tim thay dau tien
			if(it != ms.end()) //co ptu do trong set hay kh (khi xoa ptu trong set phai ktra xem no co trong set hay kh)
		 (neu kh thi se bi runtime error)
			{
				ms.erase(it);  //neu muon xoa toan bo ptu x thi ta dung: ms.erase(x)
			}
		}else //thao tac 3
		{
			if(ms.count(x)) //count tra ve 0 or 1
			{
				cout<<"YES\n";
			}else
			{
				cout<<"NO\n";
			}
		}
	}	
}
*/



//MAP
/*
t/c:
Cac key trong map la nhung gia tri rieng biet, khong co 2 key nao co gtri giong nhau, value thi co
the trung nhau.
Cac cap ptu trong MAP dc sx theo thu tu tang dan cua key
Moi ptu trong map thuc chat la mot pair, voi first luu key va second luu value

Them mot ptu vao trong map:
-Dung ham insert
map<int, int> mp;
mp.insert({1,2});
mp.insert({1,3});
mp.insert({2,4}); 
->{(1,2) , (2,4)}; //2 phan tu

cout<<mp.size()<<endl;
-> 2

mp[5] = 10  //khi key 5 chua xh
->{(1,2) , (2,4), (5,10)};

mp[5] = 20  //khi key 5 co xh
->{(1,2) , (2,4), (5,20)};

//duyet map
//moi ptu trong map la 1 cai pair
c1:
for(pair<int, int> it : mp) or (auto it :mp)
{
	cout<<it.first<<" "<<it.second<<endl;
}
c2:
for(auto it = mp.begin(); it != mp.end(); it++){
	cout<< (*it).first<<" "<<(*it).second<<endl;
	    //dai tham chieu 
}

//tim kiem key (k tim kiem dc value)
if(mp.find(2) != mp.end()){
	cout<<"FOUND\n";
}

//erase key thi xoa luon ca cap

*/


//Cac bai toan lien quan toi tan suat, danh dau => map
/*
#include <iostream>
#include <map>
using namespace std;
int main(){
	map<int, int> mp;
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		int x;
		cin>>x;
		mp[x]++;  //dem so key xh (1:18:40 ytb)
	}
	for(auto it : mp)
	{
		cout<< it.first<<" "<<it.second<<endl;
	}
}
*/


//Bai tap: Cho mang so nguyen a[] gom n phan tu, hay liet ke cac gia tri xh trong mang theo thu tu
//xuat hien trong mang kem theo tan suat cua no, moi gtri chi liet ke 1 lan

//theo thu tu tu be den lon => duyet map (map tu luu key theo tt tang dan)
//duyet theo tt xh => duyet mang 

//Duyet mang -> in ra ptu kem theo tan suat ->cho tan suat ve 0
/*
#include <iostream>
#include <map>
using namespace std;
int main(){
	map<int, int> mp;
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
		mp[a[i]]++;    //mp[key] = value;
	}
	
	for(int i=0;i<n;i++){
		if(mp[a[i]]!=0){
			cout<<a[i]<<" "<<mp[a[i]]<<endl;
			mp[a[i]] = 0;  //gan tan suat = 0 de lan sau gap lai se khong in nua, vi no check key
		}
	}
	
}
*/

