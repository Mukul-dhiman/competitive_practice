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
    ll ans=0;
    ll i=1;
    while(i<=n){
        if(i==1){
            out("0");
        }
        else if(i==2){
            out("6");
        }
        else if(i==3){
            out("28");
        }
        else if(i==4){
            out("96");
        }
        else{
            ans=4*(SQ(i)-2-1);
            ans+=8*(SQ(i)-3-1);
            ans+=(4*(i-4)+4)*(SQ(i)-4-1);
            ans+=(4*(i-4))*(SQ(i)-6-1);
            ans+=(SQ(i-4))*(SQ(i)-8-1);
            out(ans/2);
        }
        i++;
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
	FAST_IO;
    // test();
    solve();
    return 0;
}