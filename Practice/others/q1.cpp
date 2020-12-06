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
typedef pair<int, int> pi;
bool submit;
void pre(){
	FAST_IO;
    //code for pre celculations

}
// int MAXN = 10001;
// pair<int, int> t[40004];
// pair<int, int> combine(pair<int, int> a, pair<int, int> b) {
//     if (a.first > b.first) 
//         return a;
//     if (b.first > a.first)
//         return b;
//     return make_pair(a.first, min(a.second, b.second));
// }
// void build(int a[], int v, int tl, int tr) {
//     if (tl == tr) {
//         t[v] = make_pair(0, INT_MAX);
//     } else {
//         int tm = (tl + tr) / 2;
//         build(a, v*2, tl, tm);
//         build(a, v*2+1, tm+1, tr);
//         t[v] = combine(t[v*2], t[v*2+1]);
//     }
// }
// pair<int, int> get_max(int v, int tl, int tr, int l, int r) {
//     if (l > r)
//         return make_pair(INT_MIN, 0);
//     if (l == tl && r == tr)
//         return t[v];
//     int tm = (tl + tr) / 2;
//     return combine(get_max(v*2, tl, tm, l, min(r, tm)), 
//                    get_max(v*2+1, tm+1, tr, max(l, tm+1), r));
// }
// void update(int v, int tl, int tr, int pos, int new_val) {
//     if (tl == tr) {
//         t[v] = make_pair(new_val, 1);
//     } else {
//         int tm = (tl + tr) / 2;
//         if (pos <= tm)
//             update(v*2, tl, tm, pos, new_val);
//         else
//             update(v*2+1, tm+1, tr, pos, new_val);
//         t[v] = combine(t[v*2], t[v*2+1]);
//     }
// }
// void solve1(){
//     int n,m;
//     cin>>n>>m;
//     int a[n];
//     bool same=true;
//     priority_queue<pi,vector<pi>,greater<pi>> pq;
//     loop(i,n){
//         cin>>a[i];
//         pq.push(make_pair(a[i],i));
//         if(a[i]!=a[0]){
//             same=false;
//         }
//     }

//     if(same==true){
//         out(1);
//         return;
//     }
//     build(a,1,0,n-1);
//     int ans[n]={0};
//     pair<int,int> top,gm;
//     int temp,temp1;
//     while(pq.size()!=0){
//         top = pq.top();
//         pq.pop();
//         gm = get_max(1,0,n-1,max(0,top.second-m),min(n-1,top.second+m));
//         temp=gm.first+1;
//         temp1=0;
//         if(a[top.second]==gm.second){
//             for(int i=max(top.second-m,0);i<min(top.second+m,n-1);i++){
//                 if(a[i]<top.first){
//                     temp1=max(temp1,ans[i]);
//                 }
//             }
//             temp=temp1; 
//         }
//         update(1,0,n-1,top.second,temp);
//         ans[top.second]=temp;
//         cout<<top.first<<" "<< top.second<<endl;
//         loop(i,n){
//             cout<<ans[i]<<" ";
//         }
//         cout<<endl;
//     }
//     int finl=1;
//     loop(i,n){
//         finl=max(finl,ans[i]);
//     }
//     out(finl);
//     return; 
// }
void solve(){
    int n,m;
    cin>>n>>m;
    int a[n];
    bool same=true;
    priority_queue<pi,vector<pi>,greater<pi>> pq;
    loop(i,n){
        cin>>a[i];
        pq.push(make_pair(a[i],i));
        if(a[i]!=a[0]){
            same=false;
        }
    }
    if(same==true){
        out(1);
        return;
    }
    int ans[n]={0},temp;
    pair<int,int> top,gm;
    while(pq.size()!=0){
        top = pq.top();
        pq.pop();
        temp=1;
        for(int i=max(top.second-1,0);i>=max(0,top.second-m);i--){
            if(top.first<a[i]){
                break;
            }
            if(top.first>a[i]){
                temp=max(temp,ans[i]+1);
            }
        }
        for(int i=min(top.second+1,n-1);i<=min(n-1,top.second+m);i++){
            if(top.first<a[i]){
                break;
            }
            if(top.first>a[i]){
                temp=max(temp,ans[i]+1);
            }
        }
        ans[top.second]=temp;
        // cout<<top.first<<" "<< top.second<<endl;
        // loop(i,n){
        //     cout<<ans[i]<<" ";
        // }
        // cout<<endl;
    }
    int finl=1;
    loop(i,n){
        finl=max(finl,ans[i]);
    }
    out(finl);
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