#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define FAST_IO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"
#define pb push_back
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
void solve()
{
    ll ans;
    string s;
    cin >> s;
    int len = s.size();
    vector<int> vec;
    for( int i=0; i<len;i++)    if(s[i] == '1')    vec.pb(i);
    if(vec.empty())    ans = len;
    else{
        vector<int> from_last(len);
        int temp = 0;
        ans = 0;
        for( int i=0; i<len;i++){
            if (vec[temp] == i)
                temp++;
            from_last[i] = temp - 1;
        }
        temp = 0;
        int from_first[len];
        for( int i=0; i<len;i++){
            from_first[i] = temp;
            if (vec[temp] == i)
                temp++;
        }
        int f1, l1,sum_1[vec.size()] = {0}, sum_2[vec.size()] = {0};
        sum_1[0] = vec[0];
        iloop(1,i,vec.size()){
            if (i & 1)
            {
                sum_2[i] = sum_2[i - 1] + vec[i] - vec[i - 1] - 1;
                sum_1[i] = sum_1[i - 1];
            }
            else
            {
                sum_1[i] = sum_1[i - 1] + vec[i] - vec[i - 1] - 1;
                sum_2[i] = sum_2[i - 1];
            }
        }
        iloop(1,size,len){
            set<pair<int, int>> setp;
            int number_0 = 0, number_1 = 0;
            loop(j,len-size+1){
                f1 = from_first[j];
                l1 = from_last[j + size - 1];
                number_1 = l1 - f1 + 1;
                if (l1 < f1){
                    number_0 = size;
                    number_1 = 0;
                    setp.insert({number_0, number_1});
                }
                else{
                    number_0 = vec[f1] - j;
                    if (f1 & 1)
                    {
                        number_0 += sum_2[l1] - sum_2[f1];
                    }
                    else
                    {
                        number_0 += sum_1[l1] - sum_1[f1];
                    }
                    if (!(number_1 & 1))
                    {
                        number_0 += j + size - vec[l1] - 1;
                    }
                    setp.insert({number_0, number_1});
                }
            }
            ans += setp.size();
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
    submit = 0;
    pre();
    test();
    // solve();
    return 0;
}
