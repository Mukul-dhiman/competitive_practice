#include <bits/stdc++.h>
using namespace std;

typedef  long long int ll;
typedef vector<int> vi; 
typedef pair<int,int> pi;

#define FAST_IO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define endl "\n"
#define loop(i,n) for(int i=0;i<n;i++)
#define iloop(a,i,n) for(int i=a;i<=n;i++)
#define bug(i) cout<<"debug "<<i<<endl
#define out(i) cout<<i<<"\n"
#define mod 1000000009 //10e9+9
#define F first 
#define S second 
#define PB push_back 
#define MP make_pair
#define SQ(a) (a)*(a)


void solve(){
    int n;
    cin>>n;
    int a[n];
    vector<int> b;
    loop(i,n){
        cin>>a[i];
    }
    vector<int> rmix;
    unordered_map<int,int> m;
    m.clear();
    int mix=0;
    for(int i=n-1;i>=0;i--){
        m[a[i]]=1;
        while(m.find(mix)!=m.end()){
            mix++;
        }
        rmix.PB(mix);
    }
    reverse(rmix.begin(),rmix.end());
    m.clear();
    int tmix=rmix[0],cmix=0;
    for(int i=0;i<n;i++){
        m[a[i]]=1;
        while(m.find(cmix)!=m.end()){
            cmix++;
        }
        if(tmix==cmix){
            b.PB(tmix);
            tmix=rmix[i+1];
            cmix=0;
            m.clear();
        }
    }
    out(b.size());
    loop(i,b.size()){
        cout<<b[i]<<" ";
    }
    cout<<endl;
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
	FAST_IO;
    test();
    // solve();
    return 0;
}