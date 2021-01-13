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
int parent[100001],Rank[100001];


void pre(){
	FAST_IO;
    //code for pre celculations
    for(int i = 1;i<100001;i++){
        parent[i] = i;
        Rank[i] = 0;
    }
}

int find_set(int v) {
    if (v == parent[v])
        return v;
    return find_set(parent[v]);
}

int npair=0;

void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        npair--;
        if (Rank[a] < Rank[b])
            swap(a, b);
        parent[b] = a;
        if (Rank[a] == Rank[b])
            Rank[a]++;
    }
}

void solve(){
    int n,m;
    cin>>n>>m;
    npair = n;
    vector<pair<int,int>> ml;
    ml.pb(make_pair(0,0));

    int temp_x,temp_y;
    for(int i=0;i<m;i++){
        cin>>temp_x>>temp_y;
        ml.pb(make_pair(temp_x,temp_y));
    }

    int temp,q;
    cin>>q;
    int q_arr[q+1];
    unordered_map<int,bool> mp;

    for(int i=1;i<=q;i++){
        cin>>temp;
        q_arr[i]=temp;
        mp[temp] = true;
    }

    for(int i=1;i<=m;i++){
        if(!mp[i]){
            union_sets(ml[i].first,ml[i].second);
        }
    }

    int ans[q+1];

    for(int i=q;i>=1;i--){
        ans[i] = npair;
        union_sets(ml[q_arr[i]].first,ml[q_arr[i]].second);
    }

    for(int i=1;i<=q;i++){
        cout<<ans[i]<<" ";
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
    // test();
    solve();
    return 0;
}