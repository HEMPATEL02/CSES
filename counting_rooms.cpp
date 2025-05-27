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
void bfs(ll i,ll j,vector<vector<char>> &grid,vector<vector<bool>> &vis){
    queue<pair<ll,ll>> q;
    vector<pair<ll,ll>> dir={{-1,0},{1,0},{0,-1},{0,1}};
    q.push({i,j});
    ll n=grid.size();
    ll m=grid[0].size();
    while(!q.empty()){
        pair<ll,ll> p=q.front();
        q.pop();
        ll x=p.ff;
        ll y=p.ss;
        vis[x][y]=true;
        for(ll k=0;k<dir.size();k++){
            ll nx=x+dir[k].ff;
            ll ny=y+dir[k].ss;
            if(nx>=0 && nx<n && ny>=0 && ny<m && grid[nx][ny]=='.' && !vis[nx][ny]){
                q.push({nx,ny});
                vis[nx][ny]=true;
            }
        }
    }
}
void solve()
{
    ll n,m;
    cin>>n>>m;
    vector<vector<char>> grid(n,vector<char> (m));
    for(ll i=0;i<n;i++){
        for(ll j=0;j<m;j++){
            cin>>grid[i][j];
        }
    }   
    vector<vector<bool>> vis(n,vector<bool> (m,false));
    ll ans=0;
    for(ll i=0;i<n;i++){
        for(ll j=0;j<m;j++){
            if(grid[i][j]=='.' && !vis[i][j]){
                ans++;
                bfs(i,j,grid,vis);
            }
        }
    }
    cout<<ans<<endl;
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