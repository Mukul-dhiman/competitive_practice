#include <bits/stdc++.h>
using namespace std;
typedef  long long int ll;
#define TEZ ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"
#define pb push_back
#define loop(i,n) for(int i=0;i<n;i++)
#define iloop(a,i,n) for(int i=a;i<=n;i++)
#define bug(i) cout<<"debug "<<i<<endl
#define out(i) cout<<i<<endl
#define mod 1000000007 //10e9+7
void solve(){
    int n;
	ll k,s,e;
	cin>>n>>k;
	map<ll,ll> m;
	loop(i,n){
		cin>>s>>e;
		if(m.find(s)==m.end()){
			m[s]=e;
		}
		else{
			m[s]=max(m[s],e);
		}
	}
	ll c=1,ans=0;
	for(auto x:m){
		if(x.first<c and x.second<c){
			continue;
		}
		if(x.first<c){
			if((x.second-c)%k==0){
				ans+=(x.second-c)/k;
				c=x.second;
			}
			else{
				ans+=(x.second-c)/k;
				ans++;
				c+=((x.second-c)/k)*k;
				c+=k;
			}
		}
		else if(x.first>=c){
			c=x.first;
			if((x.second-c)%k==0){
				ans+=(x.second-c)/k;
				c=x.second;
			}
			else{
				ans+=(x.second-c)/k;
				ans++;
				c+=((x.second-c)/k)*k;
				c+=k;
			}
		}
	}
	cout<<ans<<endl;
    return;
}
void test(){
	int t;
	cin>>t;
	iloop(1,i,t){
	    cout<<"Case #"<<i<<": ";
	    solve();
	}	
	return;
}
int main(){
	TEZ;
    test();
    // solve();
    return 0;
}