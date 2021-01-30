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
typedef pair<ll, int> pi; 
void pre(){
	FAST_IO;
    //code for pre celculations

}
struct Test{ 
   int x, y;
   ll z; 
};
void solve(){
    int n;
    cin>>n;
    ll f,temp;
    cin>>f;
    priority_queue<pi, vector<pi>, greater<pi> > pq; 
    vector<Test> ans;
    pi t;
    iloop(2,i,n){
        cin>>temp;
        pq.push(make_pair(temp,i));
    }
    int count=0;
    Test next;
    while(!pq.empty()){
        count++;
        t = pq.top();
        pq.pop();
        if(f>=t.first){
            next.x=t.second;
            next.y=1;
            next.z=t.first;
            ans.pb(next);
            f+=t.first;
        }
        else{
            if(pq.empty()){
                count=2*n;
            }
            else{
                pi nt = pq.top();
                pq.pop();
                ll dif = t.first - f;
                t.first -= dif;
                nt.first += dif;
                f+=t.first;
                next.x=t.second;
                next.y=nt.second;
                next.z=dif;
                ans.pb(next);

                next.x=t.second;
                next.y=1;
                next.z=t.first;
                ans.pb(next);
                pq.push(nt);
            }
        }
        if(count>=2*n){
            out("-1");
            return;
        }
    }
    out(ans.size());
    for(auto l:ans){
        cout<<l.x<<" "<<l.y<<" "<<l.z<<endl;
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