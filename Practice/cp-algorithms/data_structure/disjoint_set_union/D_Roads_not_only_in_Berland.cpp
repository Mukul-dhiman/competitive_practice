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
    int n;
    cin>>n;
    npair=n;
    stack<pair<int,int>> can_close,new_build;
    int a,b;
    for(int i=0;i<n-1;i++){
        cin>>a>>b;
        if(find_set(a)==find_set(b)){
            can_close.push(make_pair(a,b));
        }
        else{
            union_sets(a,b);
        }
    }



    for(int i=2;i<=n;i++){
        if(find_set(1)!=find_set(i)){;
            new_build.push(make_pair(1,i));
            union_sets(1,i);
        }
    }

    pair<int,int> temp;
    cout<<new_build.size()<<endl;
    while(!new_build.empty()){
        temp = can_close.top();
        can_close.pop();
        cout<<temp.first<<" "<<temp.second<<" ";
        temp = new_build.top();
        new_build.pop();
        cout<<temp.first<<" "<<temp.second<<endl;
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