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
void pre()
{
    FAST_IO;
    //code for pre celculations
}
void solve()
{
    string s;
    unordered_map<char,int> a;
    ll e=0,o=0,od=0;
    cin>>s;
    for(int i=0;i<s.length();i++){
        a[s[i]]++;
    }
    for(auto x:a){
        if(x.second==1) o++;
        else if(x.second%2==0){
            if(x.second==2) e++;
            else e=e+x.second/2;
        }
        else if(x.second>3) od = od + (x.second-3)/2;
    }
    if(od+e>=o) out("YES");
    else out("NO");
    return;
}
void test()
{
    int t;
    cin >> t;
    iloop(1, i, t)
    {
        // cout<<"Case #"<<i<<": ";
        solve();
    }
    return;
}
int main()
{
    // std::cout << std::fixed;
    // std::cout << std::setprecision(10);
    pre();
    test();
    // solve();
    return 0;
}