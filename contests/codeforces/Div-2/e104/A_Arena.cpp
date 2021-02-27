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
unordered_map<int,int> mp_temp;
bool possible(int f){
    for(auto x:mp_temp){
        if(f>x.first){
            mp_temp[x.first]--;
            return possible(f+1);
        }
    }
    return false;
}
void solve(){
    int n,temp;
    cin>>n;
    unordered_map<int,int> mp;
    loop(i,n){
        cin>>temp;
        if(mp.find(temp)==mp.end()){
            mp.insert({temp,1});
        }
        else    mp[temp]++;
    }
    int ans=0;
    for(auto x:mp){
        mp_temp = mp;
        mp_temp[x.first]--;
        if(possible(x.first))    ans+=x.second;
        mp_temp[x.first]++;
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
    pre();
    test();
    // solve();
    return 0;
}