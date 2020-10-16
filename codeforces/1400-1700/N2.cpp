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

// https://codeforces.com/problemset/problem/1395/C

bool check(ll a[],ll b[],int n,int m,int v){
    loop(i,n){
        bool c=false;
        loop(j,m){
            // cout<<a[i]<<" "<<b[j]<<" "<<(a[i]&b[j])<<" "<<((a[i]&b[j])|v)<<" "<<v<<endl;
            if(((a[i]&b[j])|v)==v){
                c=true;
                break;
            }
        }
        if(!c){
            return false;
        }
    }
    return true;
}
void solve(){
    int n,m;
    cin>>n>>m;
    ll a[n],b[m];
    loop(i,n)   cin>>a[i];
    loop(i,m)   cin>>b[i];
    loop(i,pow(2,9)){
        if(check(a,b,n,m,i)){
            out(i);
            return;
        }
    }
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