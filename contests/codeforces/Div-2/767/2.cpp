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
    int l,r,k;
    cin>>l>>r>>k;
    int ans = 0; 
    if(l==1 and r ==1 ){
        ans = 0;
    }
    else if(l==r){
        ans=1;
    }
    else{
        if(r-l+1<=k){
            ans=1;
        }
        else{
            if((r-l+1)%2==0){
                if((r-l+1)/2<=k){
                    ans=1;
                }
                else{
                    ans=0;
                }
            }
            else{
                if(l%2!=0){
                    if((r-l+1)/2+1<=k){
                        ans=1;
                    }
                    else{
                        ans=0;
                    }
                }
                else{
                    if((r-l+1)/2<=k){
                        ans=1;
                    }
                    else{
                        ans=0;
                    }
                }
            }
        }
    }
    if(ans==1){
        out("YES");
    }
    else{
        out("NO");
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
    test();
    // solve();
    return 0;
}