#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define FAST_IO                       \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
#define endl "\n"
#define pb push_back
#define loop(i, n) for (int i = 0; i < n; i++)
#define iloop(a, i, n) for (int i = a; i <= n; i++)
#define bug(i) cout << "debug at:" << __LINE__ << " " << i << endl
#define out(i) cout << i << endl
#define mod 1000000007 //10e9+7
void pre()
{
    FAST_IO;
    //code for pre celculations
}
void solve()
{
    int n;
    string s;
    cin >> n;
    cin >> s;
    stack<int> sta;
    int temp, ans = 0;
    loop(i,n)
    {
        temp = s[i] - '0';
        if (temp == 1)
            sta.push(1);
        else
        {
            if (sta.empty())    sta.push(0);
            else if(sta.top() == 1){
                sta.pop();
                ans++;
            }
            else    sta.push(0);
        }
    }
    out(ans);
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
    pre();
    test();
    // solve();
    return 0;
}