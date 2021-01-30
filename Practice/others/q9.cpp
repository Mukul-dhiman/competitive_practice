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
float maxf(float a,float b){
    if(a>b) return a;
    return b;
}
void solve(){
    int n,k;
    cin>>n>>k;
    vector<int> a(n+1);
    std::cout << std::setprecision(6);
    a[0]=-1;
    iloop(1,i,n)    cin>>a[i];
    int start=1,end=k,sum=0,currlen=k;
    float ans = 0.0,right,left,both,rc,lc,bc;
    iloop(start,i,end)  sum+=a[i];
    ans=maxf(ans,1.0*sum/currlen);
    while(start<=n-k+1){
        if(end==n){
            sum=sum-a[start];
            start++;
            currlen--;
        }
        else{
            right = sum + a[end+1],rc=1.0*(sum + a[end+1])/(currlen+1);
            left = sum - a[start],lc=1.0*(sum - a[start])/(currlen-1);
            both = sum + a[end+1] - a[start],bc=1.0*(sum + a[end+1] - a[start])/(currlen);
            if(lc >= rc && lc >= bc){
                if(currlen<=k){
                    if(bc>=rc){
                        start++;
                        end++;
                        sum=both;
                    }
                    else{
                        end++;
                        sum=right;
                        currlen++;
                    }
                }
                else{
                    start++;
                    sum=left;
                    currlen--;
                }
            }
            else if(bc>=lc && bc>=rc){
                start++;
                end++;
                sum=both;
            }
            else{
                end++;
                sum=right;
                currlen++;
            }
        }
        ans=maxf(ans,1.0*sum/currlen);
    }
    out(ans);
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