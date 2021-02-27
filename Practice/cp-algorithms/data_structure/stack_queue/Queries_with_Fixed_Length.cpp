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
unordered_map<int,int> resultdddd;
int fun(vector<int> v,int d,int n){
    if(resultdddd.find(d)!=resultdddd.end()){
        return resultdddd[d];
    }
    int ret=INT_MAX;
    priority_queue<pair<int,int>> q;
    for(int i=0;i<min(n,d);i++){
        q.push(make_pair(v[i],i));
    }
    ret = min(ret,q.top().first);
    out(d);
    for(int i=d;i<n;i++){
        cout<<"rrrrrr";out(i);
        while(q.top().second<i-d){
            cout<<q.top().first<<" "<<q.top().second<<endl;
            q.pop();       
        }
        q.push(make_pair(v[i],i));
        ret=min(ret,q.top().first);
    }
    resultdddd[d]=ret;
    return ret;
}

// Complete the solve function below.
vector<int> solve(vector<int> arr, vector<int> queries) {

    vector<int> ans;
    int d,n = arr.size(),q_size = queries.size();
    for(int i=0;i<q_size;i++){
        d=queries[i];
        ans.push_back(fun(arr,d,n));
    }
    return ans;
}

void solve1(){
    int n,q,temp;
    cin>>n>>q;
    vector<int> arr,qu;
    loop(i,n){
        cin>>temp;
        arr.push_back(temp);
    }   
    loop(i,q){
        cin>>temp;
        qu.push_back(temp);
    }
    vector<int> ans = solve(arr,qu);
    loop(i,q){
        out(arr[i]);
    }
    return; 
}
void test(){
	int t;
	cin>>t;
	iloop(1,i,t){
	    // cout<<"Case #"<<i<<": ";
	    solve1();
	}	
	return;
}
int main(){
	// std::cout << std::fixed;
    // std::cout << std::setprecision(10);
    pre();
    // test();
    solve1();
    return 0;
}