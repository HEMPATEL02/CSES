/*
 author:hem_patel_02
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
void dfs(vector<vector<ll>> &adj,ll node ,ll parent,vector<ll> &through_me,vector<ll> &v){
    ll max1=0;
    ll max2=-1;
    for(auto it : adj[node]){
        if(it==parent){
            continue;
        }
        dfs(adj,it,node,through_me,v);
        if(max1<v[it]){
            max2=max1;
            max1=v[it];
        }
        else if(max2<v[it]){
            max2=v[it];
        }
    }
    v[node]=max1+1;
    if(max2!=-1){
    through_me[node]=1+max1+max2;
    }else{
        through_me[node]=max1+1;
    }
}
void solve()
{
    ll n;
    cin>>n;
    vector<vector<ll>> adj(n+1);
    for(ll i=1;i<n;i++){
        ll x,y;
        cin>>x>>y;
        adj[x].pb(y);
        adj[y].pb(x);
    }
    vector<ll> through_me(n+1,1);
    vector<ll> v(n+1,1);
    dfs(adj,1,0,through_me,v);
    ll ans=0;
    for(ll i=1;i<=n;i++){
        ans=max(ans,through_me[i]);
    }
    cout<<ans-1<<endl;
}
int32_t main()
{
ios::sync_with_stdio(0);
cin.tie(0);
cout.tie(0);
solve();
  return 0;
}