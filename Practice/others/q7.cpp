#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define loop(i,n) for(int i=0;i<n;i++)
#define loop1(i,k,n) for(int i=k;i<n;i++)
#define pb push_back
typedef long long int ll;
int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    int t,n;
    cin>>t;
    map<int,int>mp,mp2;
    loop(tl,t){
        mp2.clear();
        cin>>n;
        int a[n];
        loop(i,n){
            cin>>a[i];
            mp2[a[i]]++;
        }
        for(auto x: mp2){
            if(mp[x.first])
                mp[x.first]=0;
            else
                mp[x.first]++;
        }
    }
    for(auto x:mp){
        if(x.second!=0) cout<<x.first<<" ";
    }
    cout<<endl;
    return 0;
}