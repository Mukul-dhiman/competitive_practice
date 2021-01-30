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
struct color
{
    int count = 0;
    char value;
};

void solve()
{
    int n, m, r, g, b;
    cin >> n >> m >> r >> g >> b;
    struct color c1, c2, c3;
    c1.count = r;
    c1.value = 'R';
    c2.value = 'G';
    c2.count = g;
    c3.count = b;
    c3.value = 'B';
    int t = 0;
    if (c1.count < c2.count)
    {
        swap(c1, c2);
    }
    if (c1.count < c3.count)
    {
        swap(c1, c3);
    }
    loop(i, n)
    {
        loop(j, m)
        {
            t=i+j;
            if (t % 2 == 0)
            {
                if (c2.count > 0)
                {
                    cout << c2.value;
                    c2.count--;
                }
                else
                {
                    cout << c1.value;
                    c1.count--;
                }
            }
            else
            {
                if (c3.count > 0)
                {
                    cout << c3.value;
                    c3.count--;
                }
                else
                {
                    cout << c1.value;
                    c1.count--;
                }
            }
        }
        cout << endl;
    }
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