#include <bits/stdc++.h>
using namespace std;
typedef  long long int ll;
#define FAST_IO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"
#define loop(i,n) for(int i=0;i<n;i++)
#define iloop(a,i,n) for(int i=a;i<=n;i++)
#define bug(i) cout<<"debug at:"<<__LINE__<<" "<<i<<endl
#define out(i) cout<<i<<endl
#define mod 1000000007 //10e9+7

bool prime[1500000 + 1];
vector<ll> v;
void SieveOfEratosthenes(int n){
    memset(prime, true, sizeof(prime));
    prime[1] = false;
    for (int p = 2; p * p <= n; p++){
        if (prime[p] == true){
            for (int i = p * 2; i <= n; i += p)    prime[i] = false;
        }
    }
}
void pre(){
    FAST_IO;
    //code your pre celculations
    SieveOfEratosthenes(1500000);
    int i=1,c=2;
    while(i<=100005){
        if(prime[c]==true){
            v.push_back(c);
            i++;
        }
        c++;
    }
}
void solve(){
    int n,temp;
    cin>>n;
    iloop(1,i,n){
        cin>>temp;
        if(i!=temp){
            cout<<v[temp]<<" ";
        }
        else{
            cout<<v[i]<<" ";
        }
    }
    cout<<endl;
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