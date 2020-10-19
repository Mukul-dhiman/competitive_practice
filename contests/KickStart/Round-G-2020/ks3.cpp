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
    ll n,w;
    unordered_map<ll,ll> mp;
    ll forn(ll i){
        ll ret=0;
        for(auto x:mp){
            ret+=x.second*min(abs(x.first-i),abs(n-x.first+i));
        }
        return ret;
    }
    unordered_map<ll,ll> store;
    ll val(ll i){
        if(store[i]){
            return store[i];
        }
        store[i]=forn(i);
        return store[i];
    }
    ll fromone(ll s,ll n){
        
    }
    void solve(){
        ll temp;
        mp.clear();
        loop(i,w){
            cin>>temp;
            mp[temp]++;
        }
        ll ans=INT_MAX;
        ans=min(ans,fromone(1,n));
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
        // std::cout << std::fixed;
        // std::cout << std::setprecision(10);
        FAST_IO;
        test();
        // solve();
        return 0;
    }