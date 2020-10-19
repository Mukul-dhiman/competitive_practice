#include <bits/stdc++.h>
using namespace std;
typedef  long long int ll;
#define TEZ ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"
#define loop(i,n) for(int i=0;i<n;i++)
#define iloop(a,i,n) for(int i=a;i<=n;i++)
#define bug(i) cout<<"debug "<<i<<endl
#define out(i) cout<<i<<endl
#define mod 1000000007 //10e9+7
vector<vector<bool>> pir(7,vector<bool>(7,true));
int s;
int call(int r,int p){
    int temp=0;
    if(pir[r][p]==true){
		temp++;
        pir[r][p]=false;
        if(p%2==0){
            if(r-1>=1){
                temp+=call(r-1,p-1);
            }
        }
        else{
            if(r+1<=s){
                temp+=call(r+1,p+1);
            }
        }
        if(p-1>=1){
            temp+=call(r,p-1);
        }
        if(p+1<=2*r-1){
            temp+=call(r,p+1);
        }
    }
    return temp;
}
void solve(){
    int ra,pa,rb,pb,c,r,p,ans=0;
	cin>>s>>ra>>pa>>rb>>pb>>c;
    iloop(1,i,s){
        iloop(1,j,2*i-1){
            pir[i][j]=true;
        }
    }
	loop(i,c){
		cin>>r>>p;
		pir[r][p]=false;
	}
	pir[rb][pb]=false;
	ans=call(ra,pa);	
	pir[rb][pb]=true;
	ans-=call(rb,pb);
	out(ans);
    return;
}
void test(){
	int t;
	cin>>t;
	iloop(1,i,t){
	    cout<<"Case #"<<i<<": ";
	    solve();
	}	
	return;
}
int main(){
	TEZ;
    test();
    // solve();
    return 0;
}