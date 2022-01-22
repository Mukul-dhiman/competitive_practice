#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define loop(i,n) for(ll i=0;i<n;i++)
#define loop1(i,k,n) for(ll i=k;i<n;i++)
#define pb push_back
#define debug cout<<(_LINE_)
typedef long long int ll;

bool checkPalindromePair(vector<string> &v,unordered_map<string,int> &mp){
    for(int i=0;i<v.size();i++){
        string s=v[i];
        reverse(s.begin(),s.end());
        // cout<<v[i]<<endl;
        for(int j=0;j<26;j++){
            // cout<<char(i+'A')<<" | ";
            string t = char(j+'a')+s;
            // cout<<t<<" | \n";
            if(mp.find(t)!=mp.end()){
                if(mp[t]>i+1) return true;
            }
        }
    }
    return false;
}
void solve(){
    ll n;
    unordered_map<string,int> mp;
    vector<string> v;
    cin>>n;
    string s,t;
    bool b=true;
    loop(i,n){
        cin>>s;
        if(b){
            if(s.length()==1){
                b=false;
                continue;
            }
            t=s;
            reverse(t.begin(),t.end());
            if(s==t){
                b=false;
                continue;
            }
            if(mp.find(t)!=mp.end()){
                b=false;
                continue;
            }
            mp[s]=i+1;
            v.pb(s);
        }
    }
    if(b==false){
        cout<<"YES\n";
    }
    else{
        if(checkPalindromePair(v,mp)) cout<<"YES\n";
        else cout<<"NO\n";
    }
}
int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    ll t;
    cin>>t;
    // while(t--){
        // solve();
    // }
    for(ll i=1;i<=t;i++){
        // cout<<"Case #"<<i<<": ";
        solve();
    }
    return 0;
}