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
string ret;
unordered_map<string,bool> mpp;
int n,m,u,v;
int check(int c, vector<int> adj[]){
    set<int> a,b;
    int ac=adj[c].size();
    for(auto x:adj[c]){
        b.insert(x);
    }
    iloop(1,i,n){
        if(b.find(i)==b.end()){
            a.insert(i);
        }
    }
    string temp="";
    for(auto x:b){
        temp+=to_string(x) + '-';
    }
    // out(temp);
    if(mpp.find(temp)!=mpp.end()){
        return 0;
    }
    for(auto x:a){
        // cout<<x<<" "<<ac<<" "<<adj[x].size()<<" ff ";
        if(adj[x].size()!=ac){
            mpp[temp]=true;
            return 0;
        }
        for(auto y:adj[x]){
            if(a.find(y)!=a.end()){
                mpp[temp]=true;
                return 0;
            }
        }
    }
    for(auto x:a){
        // cout<<x<<" ";
        ret[x]='1';
    }
    mpp[temp]=true;
    return 1;
}
void solve(){
    cin>>n>>m;
    ret=string(n,'0');
    mpp.clear();
    vector<int> adj[n+1];
    loop(i,m){
        cin>>u>>v;
        adj[u].push_back(v);adj[v].push_back(u);
    }
    int ans=0;
    iloop(1,i,n){
        ans+=check(i,adj);
    }
    out(ans);
    out(ret);
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