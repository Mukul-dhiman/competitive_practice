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
void pre(){
	FAST_IO;
    //code for pre celculations

}
vector<vector<int>> v(15,vector<int>(15,0));
void solve(){
    int n,m;
    string temp;
    cin>>n>>m;
    loop(i,n){
        cin>>temp;
        loop(j,m){
            if(temp[j]=='*'){
                v[i][j]=1;
            }
            else{
                v[i][j]=0;
            }
        }
    }
    int x=0,y=0;
    loop(i,n){
        loop(j,m){
            if((i+j)%2==0){
                x+=v[i][j]^1;
                y+=v[i][j]^0;
            }
            else{
                x+=v[i][j]^0;
                y+=v[i][j]^1;
            }
        }
    }
    if((n%2)&&(m%2)){
        out(x);
    }
    else{
        out(min(x,y));
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
	// std::cout << std::fixed;
    // std::cout << std::setprecision(10);
    pre();
    test();
    // solve();
    return 0;
}