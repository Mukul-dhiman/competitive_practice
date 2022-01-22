#include <bits/stdc++.h>
using namespace std;

typedef  long long int ll;
typedef vector<int> vi; 
typedef pair<int,int> pi;

#define FAST_IO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define endl "\n"
#define loop(i,n) for(int i=0;i<n;i++)
#define iloop(a,i,n) for(int i=a;i<=n;i++)
#define bug(i) cout<<"debug "<<i<<endl
#define out(i) cout<<i<<"\n"
#define mod 1000000009 //10e9+9
#define F first 
#define S second 
#define PB push_back 
#define MP make_pair
#define SQ(a) (a)*(a)

void fun(ll n){
    if(n==1){
        cout<<"1"<<endl;
        return;
    }
    cout<<n<<" ";
    if(n%2==0){
        fun(n/2);
    }
    else{
        fun(3*n+1);
    }
    return;
}

void solve(){
    ll x;
    cin>>x;
    fun(x);
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
	FAST_IO;
    // test();
    solve();
    return 0;
}