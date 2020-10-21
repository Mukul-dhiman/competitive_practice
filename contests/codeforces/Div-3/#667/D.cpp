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
void solve(){
    int n;
	cin>>n;
	ll a[n],f=-1,s=-1;
	bool no=true;
	unordered_map<ll,vector<int>> mp;
	loop(i,n){
		cin>>a[i];
		if(f==-1){
			f=a[i];
		}
		if(s==-1 and a[i]!=f){
			s=a[i];
		}
		mp[a[i]].push_back(i);
		if(a[0]!=a[i]){
			no=false;
		}
	}
	if(no){
		out("NO");
	}
	else{
		out("YES");
		for(auto x:mp){
			if(x.first!=f){
				for(auto y:x.second){
					cout<<mp[f][0]+1<<" "<<y+1<<endl;
				}
			}
		}
		for(int i=1;i<mp[f].size();i++){
			cout<<mp[s][0]+1<<" "<<mp[f][i]+1<<endl;
		}
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