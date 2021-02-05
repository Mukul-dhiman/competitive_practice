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
void solve(){
    int n,m;
    cin>>n>>m;
    vector<vector<char>> v(n+1,vector<char>(n+1,0));
    iloop(1,i,n){
        string s;
        cin>>s;
        loop(j,n){
            v[i][j]=s[j];
        }
    }
    if(m%2==1){
        out("YES");
        loop(i,m+1){
            if(i%2==0)  cout<<"1";
            else cout<<"2";
        }
    }
    else{
        
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
