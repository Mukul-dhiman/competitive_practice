#include <bits/stdc++.h>
using namespace std;
typedef  long long int ll;
#define endl "\n"
#define mp make_pair
#define pb push_back   
#define ff first
#define ss second
#define imin INT_MIN
#define imax INT_MAX
#define loop(i,n) for(int i=0;i<n;i++)
#define iloop(a,i,n) for(int i=a;i<=n;i++)
#define bug(i) cout<<"debug "<<i<<endl
#define out(i) cout<<i<<endl;
#define mod1 995244353
#define mod2 1000000007 //10e9+7
#define mod3 10000007 //10e7+7;

//calculating Prime using Sieve Of Eratosthenes
bool prime[200000 + 1];
void SieveOfEratosthenes(){
    memset(prime, true, sizeof(prime));
    prime[1] = false;
    for (int p = 2; p * p <= 200000; p++){
        if (prime[p] == true){
            for (int i = p * 2; i <= 200000; i += p)    prime[i] = false;
        }
    }
}

//power  (x^y)%inf1
ll  power(ll  x, ll  y,ll inf1){
    ll  temp;
    if(y == 0)  return 1ll;
    temp = power(x, y / 2,inf1)%inf1;;
    if (y % 2 == 0) return (temp* temp%inf1);
    else{
        if(y > 0)   return ((x * temp %inf1* temp)%inf1);
        else    return ((temp %inf1* temp)%inf1) / x;
    }
}

//power x^y
ll powerm(ll  x, ll  y){
    ll  temp;
    if(y == 0)  return 1;
    temp = powerm(x, y / 2);
    if (y % 2 == 0) return (temp* temp);
    else{
        if(y > 0)   return (x * temp * temp);
        else    return (temp * temp) / x;
    }
}

//calculating hash value of a string
long long compute_hash(string const& s) {
    const int p = 31;
    const int m = 1e9 + 9;
    long long hash_value = 0;
    long long p_pow = 1;
    for (char c : s) {
        hash_value = (hash_value + (c - 'a' + 1) * p_pow) % m;
        p_pow = (p_pow * p) % m;
    }
    return hash_value;
}

// linear-diophantine-equation. to find integral 
// solution of ax + by = c https://cp-algorithms.com/algebra/linear-diophantine-equation.html


//  calculate number of factors
int least_factor[200000 + 1];
void least_factor_call(){
    least_factor[1] = 1;
    for (int p = 2; p * p <= 200000; p++){
        if (least_factor[p]==0){
            for (int i = p ; i <= 200000; i += p)    if(least_factor[i]==0) least_factor[i] = p;
        }
    }
}
vector<int> give_all_factors(int n){
    vector<int> ret;
    while(n!=least_factor[n]){
        if(least_factor[n]==0)  least_factor[n]=n;  
        ret.pb(least_factor[n]);
        n=n/least_factor[n];
    }
    if(n>1) ret.pb(n);
    return ret;
}

// binomial cofficieant
ll fac[MAX_K];
void factorial(ll k,ll mod){ 
    fac[0] = 1; 
    for (int i = 1; i <= k + 1; i++) { 
        fac[i] = (i * fac[i - 1])%mod; 
    } 
} 
ll bin(ll a, ll b,ll mod){
    ll ans = ((fac[a]) / (fac[a - b] * fac[b]))%mod; 
    return ans; 
}

ll fac[MAX_K];
void factorial(ll k,ll mod){ 
    fac[0] = 1; 
    for (int i = 1; i <= k + 1; i++)    fac[i] = (i * fac[i - 1])%mod;
} 
ll bin(ll a, ll b,ll mod){
    ll ans = ((fac[a]) / (fac[a - b] * fac[b]))%mod; 
    return ans; 
}
ll a[100001];
int seg[200002];
void build(int si,int st,int se){
    if(st==se){
        seg[si]=a[st];
        return;
    }
    int mid = (st+se)/2;
    build(2*si,st,mid);
    build(2*si+1,mid+1,se);
    seg[si]= min(seg[2*si],seg[(2*si+1)]);
    return;
}
int query(int si,int st,int se,int left,int right){
    if(right < st || left >se){
        return INT_MAX;
    }
    if(st==left && se==right){
        return seg[si];
    }
    int mid = (st+se)/2;
    return min(query(2*si,st,mid,left,min(mid,right)),query(2*si+1,mid+1,se,max(mid+1,left),right));
}


const int MAX_K = 1000001; 
bool prime[200000 + 1];
void SieveOfEratosthenes(){
    memset(prime, true, sizeof(prime));
    prime[1] = false;
    for (int p = 2; p * p <= 200000; p++){
        if (prime[p] == true){
            for (int i = p * 2; i <= 200000; i += p)    prime[i] = false;
        }
    }
}
int least_factor[200000 + 1];
void least_factor_call(){
    least_factor[1] = 1;
    for (int p = 2; p * p <= 200000; p++){
        if (least_factor[p]==0){
            for (int i = p ; i <= 200000; i += p)    if(least_factor[i]==0) least_factor[i] = p;
        }
    }
}
vector<int> give_all_factors(int n){
    vector<int> ret;
    while(n!=least_factor[n]){
        if(least_factor[n]==0)  least_factor[n]=n;  
        ret.pb(least_factor[n]);
        n=n/least_factor[n];
    }
    if(n>1) ret.pb(n);
    return ret;
}


ll  power(ll  x, ll  y,ll inf1){
    ll  temp;
    if(y == 0)  return 1ll;
    temp = power(x, y / 2,inf1)%inf1;;
    if (y % 2 == 0) return (temp* temp%inf1);
    else{
        if(y > 0)   return ((x * temp %inf1* temp)%inf1);
        else    return ((temp %inf1* temp)%inf1) / x;
    }
}
ll powerm(ll  x, ll  y){
    ll  temp;
    if(y == 0)  return 1;
    temp = powerm(x, y / 2);
    if (y % 2 == 0) return (temp* temp);
    else{
        if(y > 0)   return (x * temp * temp);
        else    return (temp * temp) / x;
    }
}
ll modInverse(ll a, ll m){
    ll g = __gcd(a, m); 
    if (g != 1) return -1; 
    else    return power(a, m-2, m);
}