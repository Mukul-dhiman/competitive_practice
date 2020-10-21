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
void solve(){
    int n;
	cin>>n;
	int temp,ans=0,c=0;
	bool s=false;
	vector<int> v;
	loop(i,n){
		cin>>temp;
		if(temp==1){
			s=true;
		}
		if(s){
			if(temp==0){
				c++;
			}
			else{
				ans+=c;
				c=0;
			}
		}
	}out(ans);
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
    test();
    // solve();
    return 0;
}