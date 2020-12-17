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
bool submit;
void pre(){
	FAST_IO;
    //code for pre celculations

}
vector<int> fun(vector<int> cur, vector<int> next){
    vector<int> ret;
    int cn=cur.size(),nn=next.size();
    unordered_map<int,bool> mp;
    loop(i,cn){
        mp[cur[i]]=true;
    }
    loop(i,nn){
        if(mp.find(next[i])==mp.end()){
            mp[next[i]]=true;
        }
        else{
            mp[next[i]]=false;
        }
    }
    for(auto i:mp){
        if(i.second)    ret.push_back(i.first);
    }
    return ret;
}

void solve(){
    ll n,t1,temp;
    vector<int> cur,next;
    cin>>n;
    cin>>t1;
    loop(i,t1){
        cin>>temp;
        cur.push_back(temp);
    }
    loop(j,n-1){
        cin>>t1;
        next.clear();
        loop(i,t1){
            cin>>temp;
            next.push_back(temp);
        }
        cur = fun(cur,next);
    }
    sort(cur.begin(),cur.end());
    if(cur.size()==0){
        out(-1);
    }
    else{
        loop(i,cur.size()){
            cout<<cur[i]<<" ";
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
	submit=0;
    pre();
    // test();
    solve();
    return 0;
}