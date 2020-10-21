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
    int n,ans=-1;
	cin>>n;
	ll a[n],mx=INT_MIN;
	loop(i,n){
		cin>>a[i];
		mx=max(mx,a[i]);
	}
	vector<int> itr;
	loop(i,n){
		if(a[i]==mx){
			if(i==0){
				if(a[i+1]!=mx){
					ans=i+1;
					break;
				}
			}
			else if(i==n-1){
				if(a[i-1]!=mx){
					ans=i+1;
					break;
				}
			}
			else{
				if(a[i-1]!=mx or a[i+1]!=mx){
					ans=i+1;
					break;
				}
			}
		}
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
	FAST_IO;
    test();
    // solve();
    return 0;
}