#include <bits/stdc++.h>
using namespace std;
typedef  long long int ll;
#define FAST_IO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"
#define pb push_back
#define loop(i,n) for(int i=0;i<n;i++)
#define iloop(a,i,n) for(int i=a;i<=n;i++)
#define bug(i) cout<<"debug at:"<<__LINE__<<" "<<i<<endl
#define out(i) cout<<i<<endl
#define mod 1000000007 //10e9+7
void pre(){
	FAST_IO;
    //code for pre celculations

}
int h[101]={0};
int fun(int h[],int n){
    iloop(1,i,n-1){
        if(h[i]<h[i+1]){
            h[i]++;
            return i;
        }
    }
    return -1;
}
void solve(){
    int n;
    ll k;
    cin>>n>>k;
    iloop(1,i,n)   cin>>h[i];
    int ans=1;
    while(ans>0 && k>0){
        ans = fun(h,n);
        k--;
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
    pre();
    test();
    // solve();
    return 0;
}
