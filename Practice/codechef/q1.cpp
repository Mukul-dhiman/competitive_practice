#include <bits/stdc++.h>
using namespace std;
typedef  long long int ll;
#define FAST_IO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"
#define loop(i,n) for(int i=0;i<n;i++)
#define iloop(a,i,n) for(int i=a;i<=n;i++)
#define bug(i) cout<<"debug "<<i<<endl
#define out(i) cout<<i<<endl
#define mod 1000000009 //10e9+9

// https://www.codechef.com/LRNDSA07/problems/CDQU5

int a[1000001]={0};
void pre(){
	FAST_IO;
    a[0]=0;
    a[1]=0;
    a[2]=1;
    a[3]=1;
    iloop(4,i,1000000){
        a[i]=(a[i-2]+a[i-3])%mod;
    }
    return; 
}
void solve(){
    int x;
    cin>>x;
    out(a[x]);
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
    pre();
    test();
    // solve();
    return 0;
}