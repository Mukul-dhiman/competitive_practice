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
    ll n;
    cin>>n;
    if(n==1){
        out("1");
    }
    else if(n<=3){
        out("NO SOLUTION");
    }
    else{
        if(n==4){
            out("3 1 4 2");
        }
        else{
            int t=n/2;
            if(n%2==0){
                t++;
            }
            else{
                t+=2;
            }
            int i=1,j=t;
            bool turn = true;
            while(i<t or j<=n){
                if(turn){
                    cout<<i<<" ";
                    i++;
                    turn=false;
                }
                else{
                    cout<<j<<" ";
                    j++;
                    turn=true;
                }
            }
            cout<<endl;
        }
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