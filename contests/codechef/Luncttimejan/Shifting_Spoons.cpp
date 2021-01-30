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
typedef pair<ll, int> pi; 
void pre(){
	FAST_IO;
    //code for pre celculations

}
void solve(){
    int n;
    cin>>n;
    ll f,temp;
    cin>>f;
    priority_queue<pi, vector<pi>, greater<pi> > pq; 
    vector<pi> ans;
    pi t;
    iloop(2,i,n){
        cin>>temp;
        pq.push(make_pair(temp,i));
    }
    while(!pq.empty()){
        t = pq.top();
        pq.pop();
        if(f>=t.first){
            ans.pb(t);
            f+=t.first;
        }
        else{
            out("-1");
            return;
        }
    }
    out(ans.size());
    for(auto x:ans){
        cout<<x.second<<" "<<"1 "<<x.first<<endl;
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
    pre();
    test();
    // solve();
    return 0;
}