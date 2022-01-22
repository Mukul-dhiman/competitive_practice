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

bool ispal(string s){
    string t=s;
    reverse(s.begin(),s.end());
    if(s==t){
        return true;
    }
    return false;
}

void solve(){
    int n;
    cin>>n;
    string s;
    unordered_map<string,int>m;
    bool ans = false;
    loop(i,n){
        cin>>s;
        if(ans==false){
        if(ispal(s)==true){
            ans=true;
        }
        else{
            if(s.length()==2){
                string t=s;
                reverse(t.begin(),t.end());
                if(m.find(t)!=m.end()){
                    ans=true;
                }
                m[s]=1;
            }
            else{
                string t=s.substr(0,2);
                reverse(t.begin(),t.end());
                if(m.find(t)!=m.end()){
                    ans=true;
                }
                string t1=s.substr(1,2);
                reverse(t1.begin(),t1.end());
                if(m.find(t1)!=m.end()){
                    ans=true;
                }
                m[t]=1;
                m[t1]=1;
            }
        }
        }
    }
    if(ans==true){
        out("YES");
        return;
    }
    out("NO");
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