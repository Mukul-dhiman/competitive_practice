#include <bits/stdc++.h>
using namespace std;
typedef  long long int ll;
#define FAST_IO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"
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
void solve(){
    string s,sub;
    int k,q;
    int l[k];
    cin>>s;
    int len=s.size();
    int aq[len]={0},temp;
    cin>>k;
    loop(i,k){
        cin>>l[i];
    }
    cin>>q;
    loop(i,q){
        cin>>temp;
        aq[temp]=1;
    }
    int solved=0,le;
    unordered_map<string,int> m;
    bool restore;
    for(int i=0;i<k;i++){
        le=l[i];
        m.clear();
        restore=false;
        int q_count=0;
        for(int j=0;j<le;j++){
            q_count+=aq[i];
        }
        for(int j=le;j<len;j++){
            if(q_count==0){
                sub=s.substr(j-le,le);
                if(m[sub]){
                    restore=true;
                }
                m[sub]++;
            }
            q_count+=aq[j];
            q_count-=aq[j-le];
        }
        cout<<le<<" ";
        if(restore){
            out("Restored");
            solved++;
        }
        else{
            out("Not Restored");
        }
    }
    if(solved>=k/2){
        out("Saved");
    }
    else{
        out("Not Saved");
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
	submit=0;
    pre();
    // test();
    solve();
    return 0;
}