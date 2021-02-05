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
void PrintStack(stack<int> s)
{
    // If stack is empty then return
    if (s.empty()) 
        return;
     
 
    int x = s.top();
 
    // Pop the top element of the stack
    s.pop();
 
    // Recursively call the function PrintStack
    PrintStack(s);
 
    // Print the stack element starting
    // from the bottom
    cout << x << " ";
 
    // Push the same element onto the stack
    // to preserve the order
    s.push(x);
}
void solve(){
    int n,m;
    cin>>n>>m;
    unordered_map<int,stack<int>> mp;
    unordered_map<int,int> color;
    stack<int> temp;
    int a[n+1],b[n+1],c[m+1],x[m+1];
    iloop(1,i,n)    cin>>a[i];
    // out("********0");
    // for(auto p:mp){
    //     cout<<p.first<<endl;
    //     PrintStack(p.second);
    //     cout<<endl;
    // }
    // out("-------0");
    iloop(1,i,n){
        cin>>b[i];
        color[b[i]]=i;
        if(b[i]!=a[i]){
            if(mp.find(b[i])==mp.end()){
                while(!temp.empty())   temp.pop();
                temp.push(i);
                mp[b[i]]=temp;
            }
            else{
                // out("sssss");
                // out(b[i]);
                // PrintStack(mp[b[i]]);
                // out("sssss2");
                mp[b[i]].push(i);
                // PrintStack(mp[b[i]]);
                // out("sssss3");
            }
        }
    }
    // out("********");
    // for(auto p:mp){
    //     cout<<p.first<<endl;
    //     PrintStack(p.second);
    //     cout<<endl;
    // }
    // out("-------");
    iloop(1,i,m)    cin>>c[i];
    int last=-1;
    bool ans=true;
    for(int i=m;i>0;i--){
        if(mp.find(c[i])==mp.end()){
            if(color.find(c[i])==color.end()){
                if(last==-1)    ans=false;
                else{
                    x[i]=last;
                }
            }
            else{
                x[i]=color[c[i]];
                last=color[c[i]];
            }
        }
        else{
            if(mp[c[i]].size()==0){
                if(color.find(c[i])==color.end()){
                    if(last==-1)    ans=false;
                    else{
                        x[i]=last;
                    }
                }
                else{
                    x[i]=color[c[i]];
                    last=color[c[i]];
                }
            }
            else{
                x[i]=mp[c[i]].top();
                last=mp[c[i]].top();
                mp[c[i]].pop();
            }
        }
    }
    // out("********2");
    // for(auto p:mp){
    //     cout<<p.first<<endl;
    //     PrintStack(p.second);
    //     cout<<endl;
    // }
    // out("-------2");
    for(auto p:mp){
        if(p.second.size()!=0){
            ans=false;
        }
    }
    if(ans){
        cout<<"Yes"<<endl;
        iloop(1,i,m)    cout<<x[i]<<" ";
        cout<<endl;
    }
    else{
        out("NO");
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