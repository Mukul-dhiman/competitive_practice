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
    string s;
    cin>>s;
    int l = s.length();
    char c=s[0];
    int mx=1,cmax=1;
    iloop(1,i,l-1){
        if(s[i]==c){
            cmax++;
            mx=max(mx,cmax);
        }
        else{
            c=s[i];
            cmax=1;
        }
    }
    out(mx);
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
    // test();
    solve();
    return 0;
}