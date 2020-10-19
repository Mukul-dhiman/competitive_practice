#include <bits/stdc++.h>
using namespace std;
typedef  long long int ll;
#define TEZ ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"
#define pb push_back
#define loop(i,n) for(int i=0;i<n;i++)
#define iloop(a,i,n) for(int i=a;i<=n;i++)
#define bug(i) cout<<"debug "<<i<<endl
#define out(i) cout<<i<<endl
#define mod 1000000007 //10e9+7
void solve(){
    int n;
	ll x,temp,layer;
	cin>>n>>x;
	map<ll,vector<int>> m;
	loop(i,n){
		cin>>temp;
		layer=temp/x;
		if(temp%x==0){
			layer--;
		}
		if(m.find(layer)==m.end()){
			m[layer]={i+1};
		}
		else{
			m[layer].push_back(i+1);
		}
	}
	for(auto x:m){
		for(auto y:x.second){
			cout<<y<<" ";
		}
	}
	cout<<endl;
    return;
}
void test(){
	int t;
	cin>>t;
	iloop(1,i,t){
	    cout<<"Case #"<<i<<": ";
	    solve();
	}	
	return;
}
int main(){
	TEZ;
    test();
    // solve();
    return 0;
}