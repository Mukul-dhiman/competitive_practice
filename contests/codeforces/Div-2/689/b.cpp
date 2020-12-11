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
bool submit;
void pre(){
	FAST_IO;
    //code for pre celculations

}
vector<string> v(500);
vector<vector<int>> ans(500,vector<int>(500,0));
void solve(){
    int n,m;
    cin>>n>>m;
    loop(i,n){
        cin>>v[i];
    }
    for(int i=n-1;i>=0;i--){
        loop(j,m){
            if(i==n-1){
                
                if(v[i][j]=='*'){
                    ans[i][j]=1;
                }
                else{
                    ans[i][j]=0;
                }
            }
            else{
                if(v[i][j]=='*'){
                    if(j==0 || j==m-1){
                        ans[i][j]=1;
                    }
                    else{
                        ans[i][j]=1+min(ans[i+1][j],min(ans[i+1][j-1],ans[i+1][j+1]));
                    }
                }
                else{
                    ans[i][j]=0;
                }
            }
        }
    }
    int ret=0;
    loop(i,n){
        loop(j,m){
            ret+=ans[i][j];
        }
    }
    out(ret);
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
	// std::cout << std::fixed;
    // std::cout << std::setprecision(10);
	submit=0;
    pre();
    test();
    // solve();
    return 0;
}