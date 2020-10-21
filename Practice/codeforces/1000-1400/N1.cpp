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

// https://codeforces.com/contest/1326/problem/A 

void solve(){
    int n;
    cin>>n;
    if(n==1){
        out(-1);
    }
    else{
        cout<<"2";
        n-=1;
        while(n>0){
            cout<<"3";
            n-=1;
        }
        cout<<endl;
    }
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