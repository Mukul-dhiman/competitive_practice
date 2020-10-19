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
ll occur(string s){
    vector<ll> v;
    string s1="KICK",s2="START";
    int k=0;
    bool b=true;
    for(ll i=0;i<s.length();i++){
        b=true;
        k=0;
        if(s[i]==s1[0]){
            for(ll j=i;j<i+4;j++){
                if(s[j]!=s1[k]){
                    b=false;
                    break;
                }
                k++;
            }
            if(b){
                v.push_back(1);
            }
        }
        else if(s[i]==s2[0]){
            for(ll j=i;j<i+5;j++){
                if(s[j]!=s2[k]){
                    b=false;
                    break;
                }
                k++;
            }
            if(b){
                v.push_back(0);
            }
        }
    }
    ll count=0;
    for(ll i=0;i<v.size();i++){
        if(v[i]&&i!=v.size()-1){
            for(ll j=i+1;j<v.size();j++){
                if(!v[j]){
                    count++;
                }
            }
        }
    }
    return count;
}
int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    ll t,ans;
    string s;
    cin>>t;
    // vector<int> v;
    loop(i,t){
        cin>>s;
        ans=0;
        ans=occur(s);
        cout<<"Case #"<<i+1<<": "<<ans<<endl;
    }
    return 0;
}
   