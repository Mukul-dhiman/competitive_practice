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
bool find(vector<int> sum,vector<int> v,int s,int e,int tar,int n){
    int array_sum=sum[e]-sum[s]+v[s];
    // cout<<"||||"<<array_sum<<endl;
    if(array_sum==tar){
        // cout<<s<<" | "<<" "<<e<<endl;
        // bug('s');
        return true;
    }
    if(e<=s || v[s]==v[e]){
        return false;
    }
    if(array_sum>tar){
        int mid = (v[e]+v[s])/2;
        // cout<<s<<" "<<mid<<" "<<e<<endl;
        int idx = upper_bound(v.begin()+s,v.begin()+e,mid)-v.begin();
        if(idx==e-s+1){
            return false;
        }
        else{
            return find(sum,v,s,idx-1,tar,n) | find(sum,v,idx,e,tar,n);
        }
    }
    else{
        return false;
    }
}
void solve(){
    int n,q;
    cin>>n>>q;
    vector<int> v(n),sum(n,0);
    loop(i,n){
       cin>>v[i];
       sum[i]=v[i];
    }    
    sort(v.begin(),v.end());
    sort(sum.begin(),sum.end());
    iloop(1,i,n-1){
        sum[i]+=sum[i-1];
    }
    int s;
    loop(i,q){
        cin>>s;
        if(find(sum,v,0,n-1,s,n))   out("Yes");
        else    out("No");
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
    test();
    // solve();
    return 0;
}