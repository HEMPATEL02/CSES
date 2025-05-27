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
void solve()
{
  ll n,m;
  cin>>n>>m;
  vector<vector<char>> grid(n,vector<char> (m));
  pair<ll,ll> start,end;
  for(ll i=0;i<n;i++){
    for(ll j=0;j<m;j++){
      cin>>grid[i][j];
      if(grid[i][j]=='A'){
        start={i,j};
        continue;
      }
      if(grid[i][j]=='B'){
        end={i,j};
      }
    }
  }
  vector<pair<char,pair<ll,ll>>> dir={{'D',{-1,0}},{'U',{1,0}},{'R',{0,-1}},{'L',{0,1}}};
  vector<vector<bool>> vis(n,vector<bool> (m,false));
  vector<vector<pair<ll,ll>>> parent(n,vector<pair<ll,ll>> (m));
  queue<pair<ll,ll>> q;
  q.push(start);
  while(!q.empty()){
    pair<ll,ll> p=q.front();
    q.pop();
    ll x=p.ff,y=p.ss;
    if(x==end.ff && y==end.ss){
      break;
    }
    vis[x][y]=true;
    for(auto it : dir){
      ll nx=x+it.ss.ff;
      ll ny=y+it.ss.ss;
      if(nx>=0 && nx<n && ny>=0 && ny<m && grid[nx][ny]!='#' && !vis[nx][ny]){
        vis[nx][ny]=true;
        parent[nx][ny]={x,y};
        q.push({nx,ny});
      }
    }
  }
  if(!vis[end.ff][end.ss]){
    cn;
    return;
  }
  cy;
  pair<ll,ll> curr=end;
  string ans;
  while(true){
    pair<ll,ll> pw=parent[curr.ff][curr.ss];
    for(auto it : dir){
      ll nx=curr.ff+it.ss.ff;
      ll ny=curr.ss+it.ss.ss;
      if(nx>=0 && nx<n && ny>=0 && ny<m){
        if(nx==pw.ff && ny==pw.ss){
          ans+=it.ff;
          break;
        }
      }
    }
    if(pw==start){
      break;
    }
    curr=pw;
  }
  reverse(ans.begin(),ans.end());
  cout<<ans.size()<<endl;
  cout<<ans<<endl;
}
int32_t main()
{
ios::sync_with_stdio(0);
cin.tie(0);
cout.tie(0);
// int t=1;
// cin>>t;
solve();
  return 0;
}