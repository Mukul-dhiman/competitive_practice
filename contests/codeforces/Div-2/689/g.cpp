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

class tree{
    int n;
    vector<int> par;
    vector<int> lvsv[1000][1000];
    tree(int n,int par[]){
        this.n = n;
        this.par = par;
    }

    vector<int> lvs_c(int i,int j){
        
    }
    
    void lvs(){
        iloop(i,n){
            iloop(j,n){
                lvsv[i][j] = lvs_c(i,j);
            }
        }
    }
};

void solve(){
    int n,p;
    cin>>n>>p;
    vector<int> par(n+1);
    iloop(2,i,n){
        cin>>par[i];
    }
    tree obj(n,par);
    int c[n+1];
    iloop(1,i,n)    cin>>c[i];
    tree.lvs();
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