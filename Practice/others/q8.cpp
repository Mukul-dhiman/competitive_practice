#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define loop(i,n) for(int i=0;i<n;i++)
#define loop1(i,k,n) for(int i=k;i<n;i++)
#define pb push_back
typedef long long int ll;
int en_code(int x){
    return x^(x>>1);
}
int de_code(int g){
    for(int x = 1<<30; x>1; x>>=1){
        if(g&x){
            g^=(x>>1);
        }
    }
    return g;
}
int main(){
    string s;
    int n;
    cin>>s>>n;
    bool b;
    if(s=="true"){
        cout<<en_code(n);
    }   
    else{
        cout<<de_code(n);
    }
    cout<<endl;
    return 0;
}