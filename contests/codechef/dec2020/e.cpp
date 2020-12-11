#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define FAST_IO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"
#define loop(i, n) for (int i = 0; i < n; i++)
#define iloop(a, i, n) for (int i = a; i <= n; i++)
#define bug(i) cout << "debug at:" << __LINE__ << " " << i << endl
#define out(i) cout << i << endl
#define mod 1000000007 //10e9+7
bool submit;
void pre()
{
    FAST_IO;
    //code for pre celculations
}
unsigned int n, y, temp, curr;
void solve(){
    cin>>n>>y;
    vector<int> arr(n);
    vector<queue<int>> vec_q(32);
    loop(i, n)  cin >> arr[i];
    loop(i, n){
        temp = arr[i];
        curr = 0;
        while (temp){
            if (temp & 1){
                vec_q[curr].push(i);
            }
            curr += 1;
            temp >>= 1;
        }
    }
    int p = arr[n - 2] & 1, q = arr[n - 1] & 1, temp1 = 1 << 29;
    for (int i = 0; i < n - 1 && y > 0; i++){
        temp = temp1, curr = 29;
        while (arr[i] && y){
            if (arr[i] & temp){
                arr[i] ^= temp;
                vec_q[curr].pop();
                if (vec_q[curr].empty()){
                    iloop(1,i,1){
                        arr[n - 1] ^= temp;
                    }
                }
                else{
                    if(true){
                        arr[vec_q[curr].front()] ^= temp;
                        vec_q[curr].pop();
                    }
                }
                y--;
            }
            temp >>= 1;
            curr -= 1;
        }
    }
    if(n == 2){
        iloop(1,i,2){
            arr[n-i] ^= (y%2);
        }
    }
    else if (y == 1){
        if(arr[n - 1] & 1 == 0){
            if(arr[n - 2] & 1 == 0){
                if((p == 0 && q == 0) || (p == 1 && q == 1)){
                    iloop(1,i,2){
                        arr[n-i] += 1;
                    }
                }
            }
        }
        else if(arr[n - 1] & 1 == 1){
            if(arr[n - 2] & 1 == 0){
                if(!((p == 0 && q == 0) || (p == 1 && q == 1))){
                    arr[n - 2] = 1;
                    arr[n - 1] -= 1;
                }
            }
        }
    }
    loop(i, n)  cout << arr[i] << ' ';
    cout<<endl;
    return;
}
void test()
{
    int t;
    cin >> t;
    iloop(1, i, t)
    {
        // cout<<"Case #"<<i<<": ";
        solve();
    }
    return;
}
int main()
{
    // std::cout << std::fixed;
    // std::cout << std::setprecision(10);
    submit = 0;
    pre();
    test();
    // solve();
    return 0;
}
