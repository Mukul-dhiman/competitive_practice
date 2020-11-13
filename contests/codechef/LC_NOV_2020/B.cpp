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
    //code your pre celculations
}
struct pipe{
    int first_index,last;
    map<int,int> arr;
    map<int,int> c_max;
    void add(int index,int val){
        if(val>last){
            arr[index]=arr[index-1]+1;
        }
        else{
            arr[index]=arr[index-1];
        }
        last=max(last,val);
        c_max[index]=last;
    }
};
struct hash_pair { 
    template <class T1, class T2> 
    size_t operator()(const pair<T1, T2>& p) const
    { 
        auto hash1 = hash<T1>{}(p.first); 
        auto hash2 = hash<T2>{}(p.second); 
        return hash1 ^ hash2; 
    } 
};
vector<int> h;
class ans{
    private:
        int size;
        bool check;
        int pipe_number;
        unordered_map<int,int> in;
        unordered_map<int,pipe> m;
        unordered_map<pair<int,int>,int,hash_pair> repeated;
        vector<int> slope,slope2;
        struct point_pipe_mng{
            unordered_map<int,vector<pair<int,int>>> pipes;
            void psort(int i){
                for(auto x:pipes){
                    sort(x.second.begin(),x.second.end());
                }
            }
        };
        unordered_map<int,point_pipe_mng> pipe_mng;
        void make_pipe_mng(){
            unordered_map<int,int> temp;
            for(auto x:m){
                temp[x.second.first_index]=(x.first);
            }
            vector<int> c;
            loop(i,size){
                if(temp[i]){
                    c.push_back(temp[i]);
                }
                for(auto x:c){
                    pipe_mng[i].pipes[m[x].c_max[i]].push_back(make_pair(m[x].arr[i],x));
                }
                pipe_mng[i].psort(i);
            }
        }
        void create_pipe(int index){
            pipe temp;
            temp.first_index=index;
            temp.arr[index]=1;
            temp.c_max[index]=h[index];
            temp.last=h[index];
            m[pipe_number]=temp;
            pipe_number++;
        }
        void cal(){
            bool new_pipe;
            loop(j,size){
                new_pipe=true;
                for(int i=1;i<pipe_number;i++){
                    if(m[i].last<=h[j]){
                        new_pipe=false;
                    }
                    m[i].add(j,h[j]);
                }
                if(new_pipe){
                    if(submit){
                        bug(j);
                    }
                    create_pipe(j);
                }
                in[j]=pipe_number-1;
            }
            int f_slope=1,f_slope2=1;
            slope.push_back(f_slope);
            slope2.push_back(f_slope2);
            loop(i,size){
                if(h[i]<=h[i+1]){
                    f_slope++;
                }
                if(h[i]<h[i+1]){
                    f_slope2++;
                }
                slope.push_back(f_slope);
                slope2.push_back(f_slope2);
            }
            make_pipe_mng();
        }
    public:
        ans(){
            m.clear();
            repeated.clear();
            pipe_number=1;
            size=h.size();
            check=true;
            loop(i,size-1){
                if(h[i]<h[i+1]){
                    check=false;
                }
            }
            if(!check) cal();
        }
        int fun(int l,int r){
            int ret=1;
            if(repeated[make_pair(l,r)]){
                return repeated[make_pair(l,r)];
            }
            if(check or (l==r) or slope[l]==slope[r]){
                ret=1;
            }
            // slope concept is wrong 
            else if(slope2[r]-slope2[l]==r-l){
                ret=(r-l+1);
            }
            else{
                for(int i=in[l];i<=in[r];i++){
                    int c_pipe_v=1+m[i].arr[max(r,m[i].first_index)]-m[i].arr[max(l,m[i].first_index)];
                    if(ret<=c_pipe_v){
                        ret=c_pipe_v;
                    }
                }
            }
            repeated[make_pair(l,r)]=ret;
            return ret;
        }
        void show(){
            for(int i=1;i<pipe_number;i++){
                out(i);
                for(auto y:m[i].arr){
                    cout<<y.first<<" "<<y.second<<" "<<m[i].c_max[y.first]<<endl;
                }
            }
            bug("for in");
            loop(i,size){
                cout<<i<<" "<<in[i]<<endl;
            }
            bug("for slope");
            loop(i,size){
                out(slope[i]);
            }
            bug("for pipe management");
            loop(i,size){
                out(i);
                for(auto x:pipe_mng[i].pipes){
                    cout<<"value "<<x.first<<"-> ";
                    for(auto y:x.second){
                        cout<<y.second<<" ";
                    }
                }
                cout<<endl;
            }
        }
};
void solve(){
    int n,q,s,temp,last=0,x,y,mx,mn;
    cin>>n>>q>>s;
    h.clear();
    loop(i,n){
        cin>>temp;
        h.push_back(temp);
    }
    ans obj;
    if(submit){
        obj.show();
        bug("q");
    }
    loop(i,q){
        cin>>x>>y;
        x=(x+(s*last)-1)%n;
        y=(y+(s*last)-1)%n;
        mx=max(x,y);
        mn=min(x,y);
        x=mn;
        y=mx;
        last=obj.fun(x,y);
        if(submit){
            cout<<x<<" "<<y<<" -> ";
        }
        out(last);
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
    submit=1;
    pre();
    // test();
    solve();
    return 0;
}