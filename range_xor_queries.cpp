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
void update(ll idx,ll value,ll n,vector<ll> &bit){
    ll index=idx;
    for(;index<=n;index+=(index&-index)){
      bit[index]^=value;
    }
}
ll xor1(ll idx,ll n,vector<ll>  &bit){
  ll index=idx;
  ll xor2=0;
  for(;index>=1;index-=(index&-index)){
        xor2^=bit[index];
    }
    return xor2;
}
void solve()
{
    ll n,q;
    cin>>n>>q;
    vector<ll> v(n+1);
    vector<ll> bit(n+1,0);
    for(ll i=1;i<=n;i++){
      cin>>v[i];
      update(i,v[i],n,bit);
    }
    while(q--){
      ll a,b;
      cin>>a>>b;
      ll ans=xor1(b,n,bit)^xor1(a-1,n,bit);
      cout<<ans<<endl;
    }
}
int32_t main()
{
ios::sync_with_stdio(0);
cin.tie(0);
cout.tie(0);
solve();
  return 0;
}