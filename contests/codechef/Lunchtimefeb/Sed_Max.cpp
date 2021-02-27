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
int pairs(vector<int>& arr){
    stack<int> st;
    set<int> pairs;
    st.push(arr[0]);
 
    for (int i = 1; i < arr.size(); ++i) {
        while (!st.empty() && arr[i] > st.top()) {
            pairs.insert(abs(st.top()-arr[i]));
            st.pop();
        }
        if (!st.empty()) {
            pairs.insert(abs(st.top()-arr[i]));
        }
        st.push(arr[i]);
    }
    return pairs.size();
}
void solve(){
    int n;
    cin >>n;
    vector<int> A(n);
    loop(i,n) cin >>A[i];
    out(pairs(A));
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