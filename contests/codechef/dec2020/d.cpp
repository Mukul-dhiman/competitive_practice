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
int n,k;
void solve(){
     cin >> n >> k;
    int tmp = 0;
    vector<int> A(n+4);
    loop(i,n-n%4){
        if(tmp == k){
            A[i] = -i-1;
        } 
        else if(n-i+tmp == k){
            A[i] = i+1;
            tmp +=1;
        }
        else if(tmp+n-i-3>=k){
            A[i] = i+1;
            A[i+1] = -(i+2);
            A[i+2] = -i-3;
            A[i+3] = i+4;
            i +=3;
            tmp +=1;
        }
        else if(tmp+n-i-3 == k - 1){
            A[i] = -i-1;
            A[i+1] = i+2;
            A[i+2] = i+3;
            A[i+3] = -i-4;
            i +=3;
            tmp +=2;
        }
        else if(tmp+n-i-3 == k-2){
            A[i] = i+1;
            A[i+1] = -i-2;
            A[i+2] = i+3;
            A[i+3] = i+4;
            i +=3;
            tmp +=3;
        }
          
    }
    int sw = n%4;
    switch (sw){
        case 1:
            if(k != tmp) A[n-1] = n;
            else
            {
                A[n-1] = -n;
            }
            break;
        case 2:
            if( k == tmp){
                A[n-2] = -n+1;
                A[n-1] = -n;
            }
            else if(k == tmp+1){
                A[n-2] = -n+1;
                A[n-1] = n;
            }
            else{
                A[n-2] = n-1;
                A[n-1] = n;
            }
            break;
        case 3:
            if(k == tmp){
                A[n-3] = -n+2;
                A[n-2] = -n+1;
                A[n-1] = -n;
            }
            else if(k == tmp+1){
                A[n-3] = n-2;
                A[n-2] = -n+1;
                A[n-1] = -n;
            }
            else if(k == tmp+2){
                A[n-3] = n-2;
                A[n-2] = -n+1;
                A[n-1] = n;
            }
            else{
                A[n-3] = n-2;
                A[n-2] = n-1;
                A[n-1] = n;
            }
            break;
    }
    loop(i,n){
        cout<<A[i]<<' ';
    }
    cout<<endl;
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