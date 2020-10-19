#include <bits/stdc++.h>
using namespace std;
typedef  double ll;
#define FAST_IO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"
#define loop(i,n) for(int i=0;i<n;i++)
#define iloop(a,i,n) for(int i=a;i<=n;i++)
#define bug(i) cout<<"debug "<<i<<endl
#define out(i) cout<<i<<endl
#define mod 1000000007 //10e9+7
vector<vector<ll>> k(5001,vector<ll>(5001,0));
void cal(int n){
    iloop(1,i,n){
        if(i==1){
            k[n][i]=n*k[n-1][i];
        }
        else if(i==n){
            k[n][i]=n*k[n-1][n-1];
        }
        else{
            k[n][i]=i*k[n-1][i-1]+(n-i+1)*k[n-1][i];
        }
    }
}
vector<ll> total(5001,0);
void pre(){
    total[1]=0;total[2]=1;
    iloop(3,i,5000){
        total[i]=total[i-1]*(i-1);
    }
    k[2][1]=1;k[2][2]=1;
    iloop(3,i,5000){
        cal(i);
    }
    return;
}
ll a[5001];
void solve(){
    int n;
    cin>>n;
    iloop(1,i,n){
        cin>>a[i];
    }
    ll ans=0;
    iloop(1,i,n){
        // cout<<"("<<k[n][i]<<"*"<<a[i]<<") ";
        ans+=k[n][i]*a[i];
    }
    out(ans/total[n]);
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
	std::cout << std::fixed;
    std::cout << std::setprecision(7);
	FAST_IO;
    pre();
    test();
    // solve();
    return 0;
}