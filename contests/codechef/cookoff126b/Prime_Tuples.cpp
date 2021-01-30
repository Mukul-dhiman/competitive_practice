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
int ans[1000001]={0};
void SieveOfEratosthenes(int n){

    bool prime[n + 1];
    memset(prime, true, sizeof(prime));

    vector<int> primev;
    for (int p = 2; p * p <= n; p++){
        if (prime[p] == true) 
        {
            for (int i = p * p; i <= n; i += p)
                prime[i] = false;
        }
    }
    for(int i=2;i<=n;i++){
        if(prime[i]){
            primev.pb(i);
        }
    }
    // cout<<primev.size()<<endl;
    int sz=primev.size();
    for(int i=0;i<sz;i++){
            if(primev[i]+2<=n){
                if(prime[primev[i]+2]){
                    ans[primev[i]+2]+=1;
                }
            }
    }
    for(int i=1;i<=n;i++){
        ans[i]+=ans[i-1];
    }
}
void pre(){
	FAST_IO;
    //code for pre celculations
    SieveOfEratosthenes(1000000);
}
void solve(){
    int n;
    cin>>n;
    out(ans[n]);
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