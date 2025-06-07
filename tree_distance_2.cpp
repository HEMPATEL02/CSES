/*
  {
     author:hem_patel_02
  }
*/
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
void func(ll node,ll parent,vector<vector<ll>> &adj,vector<ll> &count,vector<ll> &dist_sum){
    for(auto it : adj[node]){
        if(it==parent){
            continue;
        }
        func(it,node,adj,count,dist_sum);
        count[node]+=count[it];
        dist_sum[node]+=count[it]+dist_sum[it];
    }
}
// void func1(ll node,ll parent,vector<vector<ll>> &adj,vector<ll> &count,vector<ll> &dist_sum){
//     for(auto it : adj[node]){
//         if(it==parent){
//             continue;
//         }
//         func1(it,node,adj,count,dist_sum);
//         dist_sum[node]+=count[it]+dist_sum[it];
//     }
// }
void solve()
{
    ll n;
    cin>>n;
    vector<vector<ll>> adj(n+1);
    for(ll i=0;i<n-1;i++){
        ll x,y;
        cin>>x>>y;
        adj[x].pb(y);
        adj[y].pb(x);
    }
    vector<ll> dist_sum(n+1,0);
    vector<ll> count(n+1,1);
    func(1,0,adj,count,dist_sum);
    // for(ll i=0;i<=n;i++){
    //     cout<<count[i]<<" ";
    // }
    // cout<<endl;
    // for(ll i=0;i<=n;i++){
    //     cout<<dist_sum[i]<<" ";
    // }
    // cout<<endl;
    vector<ll> ans(n+1,0);
    queue<pair<ll,ll>> q;
    q.push({1,0});
    while(!q.empty()){
        pair<ll,ll> p=q.front();
        ll node=p.ff;
        ll parent=p.ss;
        q.pop();
        for(auto it : adj[node]){
            if(it==parent){
                continue;
            }
            dist_sum[it]=dist_sum[node]+n-2*count[it];
            q.push({it,node});
        }
    }
    for(ll i=1;i<=n;i++){
        cout<<dist_sum[i]<<" ";
    }
    cout<<endl;
}
int32_t main()
{
ios::sync_with_stdio(0);
cin.tie(0);
cout.tie(0);
solve();
  return 0;
}