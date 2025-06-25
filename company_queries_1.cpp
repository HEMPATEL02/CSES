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
        if(up[node][i-1]!=-1){
            ll mid_node=up[node][i-1];
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
            jump-=(ll)1<<i;
        }
        if(jump==0 || curr_node==-1){
            return curr_node;
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
        adj[i].pb(u);
        adj[u].pb(i);
    }
    binary_lifting(1,-1,adj);
    while(q--){
        ll x,y;
        cin>>x>>y;
        ll ans=query(x,y);
        cout<<ans<<endl;
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