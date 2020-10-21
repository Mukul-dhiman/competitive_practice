#include <bits/stdc++.h>
using namespace std;
typedef  long long int ll;
#define FAST_IO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"
#define loop(i,n) for(int i=0;i<n;i++)
#define iloop(a,i,n) for(int i=a;i<=n;i++)
#define bug(i) cout<<"debug "<<i<<endl
#define out(i) cout<<i<<endl
#define mod 1000000007 //10e9+7
bool possible(int total,vector<int> a,int m){
	if(a.size()==0 or m==0){
		return false;
	}
	if(total==a[0]){
		return true;
	}
	int f=a[0];
	if(a[0]>total){
		return possible(total,a,m-1);
	}
	a.erase(a.begin()+1);
	return possible(total-f,a,m-1) or possible(total,a,m-1);
}
int fun(vector<int> a,int m,int k){
	int total = m*70/k;
	total*=k;
	if(m%2==0){
		m/=2;
	}
	else{
		m/=2;
		m++;
	}
	cout<<"f";
	while(!possible(total,a,m) and total>0){
		cout<<"he";
		total-=k;
	}
	return max(0,total*k);
}
void solve(){
    int n,m,k,ans=0;
	vector<int> a(m);
	loop(i,n){
		loop(j,m){
			cin>>a[j];
		}
		ans+=fun(a,m,k);
	}
	out(ans);
    return; 
}
void test(){
	int t;
	cin>>t;
	iloop(1,i,t){
	    // cout<<"Case #"<<i<<": ";
	    solve();
	}	
	return;
}
int main(){
	// std::cout << std::fixed;
    // std::cout << std::setprecision(10);
	FAST_IO;
    // test();
    solve();
    return 0;
}