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

// https://codeforces.com/problemset/problem/1420/B 

void solve(){
    ll n,temp;
    cin>>n;
    int b;
    vector<ll> bit(32,0);
    loop(i,n){
        cin>>temp;
        b=-1;
        while(temp){
            b++;
            temp/=2;
        }
        bit[b]++;
    }
    ll ans=0;
    loop(i,32){
        // cout<<i<<" "<<bit[i]<<" | ";
        ans+=(bit[i]*(bit[i]-1))/2;
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
    test();
    // solve();
    return 0;
}