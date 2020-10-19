    #include <bits/stdc++.h>
    using namespace std;
    typedef  long long int ll;
    #define FAST_IO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    #define endl "\n"
    #define loop(i,n) for(int i=0;i<n;i++)
    #define iloop(a,i,n) for(int i=a;i<=n;i++)
    #define bug(i) cout<<"debug "<<i<<endl
    #define out(i) cout<<i<<endl
    #define mod 1000000007 //10e9+7

    void solve(){
        int n;
        cin>>n;
        vector<vector<int>> v(n+1,vector<int>(n+1,0));
        iloop(1,i,n){
            iloop(1,j,n){
                cin>>v[i][j];
            }
        }
        int ans=INT_MIN,temp,k,temp1;
        for(int i=1;i<=n;i++){
            temp=0;temp1=0;
            k=0;
            while(k<=n and (i+k)<=n){
                temp+=v[i+k][k+1];
                temp1+=v[k+1][i+k];k++;
            }
            ans=max(ans,max(temp1,temp));
        }
        out(ans);
        return; 
    }
    void test(){
        int t;
        cin>>t;
        iloop(1,i,t){
            cout<<"Case #"<<i<<": ";
            solve();
        }	
        return;
    }
    int main(){
        // std::cout << std::fixed;
        // std::cout << std::setprecision(10);
        FAST_IO;
        test();
        // solve();
        return 0;
    }