#define mod 1000000007
#define ull unsigned long long
#define ll long long
#define cy cout<<"YES"<<endl
#define cn cout<<"NO"<<endl
#define hai cout<<-1<<endl
#define pb push_back
#define ff first
#define ss second
bool isprime(ll n){if (n <= 1)  return 0; if (n <= 3)  return 1; if (n%2 == 0 || n%3 == 0) return 0; for (int i=5; i*i<=n; i=i+6) if (n%i == 0 || n%(i+2) == 0) return 0; return 1;}
#include<bits/stdc++.h>
using namespace std;
vector<vector<ll>> up(2e5+5,vector<ll> (20,-1));
void binary_lifting(ll node,ll parent,vector<vector<ll>> &adj){
    up[node][0]=parent;
    for(ll i=1;i<20;i++){
        ll mid_node=up[node][i-1];
        if(mid_node!=-1){
            up[node][i]=up[mid_node][i-1];
        }else {
            up[node][i]=-1;
        }
    }
    for(auto it : adj[node]){
        if(it!=parent){
            binary_lifting(it,node,adj);
        }
    }
}
ll query(ll node,ll jump){
    ll curr_node=node;
    for(ll i=19;i>=0;i--){
        if((jump>>i)&1){
            curr_node=up[curr_node][i];
            jump-=(ll)(1<<i);
        }
        if(jump==0 || curr_node==-1){
            return curr_node;
        }
    }
    return curr_node;
}
void dfs(ll node,ll parent,vector<vector<ll>> &adj,vector<ll> &level){
    for(auto it : adj[node]){
        if(it!=parent){
            level[it]=level[node]+1;
            dfs(it,node,adj,level);
        }
    }
}
void solve()
{
    ll n,q;
    cin>>n>>q;
    vector<vector<ll>> adj(n+1);
    for(ll i=2;i<=n;i++){
        ll u;
        cin>>u;
        adj[u].pb(i);
        adj[i].pb(u);
    }
    vector<ll> level(n+1,1);
    dfs(1,0,adj,level);
    binary_lifting(1,-1,adj);
    while(q--){
        ll x,y;
        cin>>x>>y;
        if(level[x]<level[y]){
            swap(x,y);
        }
        // cout<<x<<" "<<level[x]<<endl;
        // cout<<y<<" "<<level[y]<<endl;
        ll jump_req=level[x]-level[y];
        ll new_x=query(x,jump_req);
        // cout<<new_x<<" "<<x<<" "<<y<<endl;
        x=new_x;
        ll LCA=1;
        if(x==y){
            LCA=x;
            cout<<x<<endl;
            continue;
        }
        // cout<<new_x<<" "<<"new_x"<<endl;
        for(ll i=19;i>=0;i--){
            if(up[x][i]!=up[y][i] && up[x][i]!=-1 && up[y][i]!=-1){
                x=up[x][i];
                y=up[y][i];
                // cerr<<x<<" "<<y<<endl;
            }
        }
        // cout<<prev_x<<endl;
        // prev_x and prev_y both are nodes that are below LCA, jump one from any of one gives LCA
        LCA=query(x,1);
        cout<<LCA<<endl;
    }
}
int32_t main()
{
ios::sync_with_stdio(0);
cin.tie(0);
cout.tie(0);
int t=1;
// cin>>t;
solve();
  return 0;
}


//      1
//     2   3
//       4   5


//                   1
//          2        3            5
//        6   7    4   9       8
//                       10