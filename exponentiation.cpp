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
ll power(ll a,ll b,ll mod1){
    if((b==0 && a==0) || a==1){
        return 1;
    }
    ll res=1;
    while(b){
        if(b&1){
             res=(res%mod1*a%mod1)%mod1;
        }
        b=b>>1;
        a=(a%mod1*a%mod1)%mod1;
    }
    return res%mod1;
}
void solve()
{
    ll a,b;
    cin>>a>>b;
    ll mod1=1e9+7;
    ll ans=power(a,b,mod1);
    cout<<ans<<endl;
}
int32_t main()
{
ios::sync_with_stdio(0);
cin.tie(0);
cout.tie(0);
int t=1;
cin>>t;
while(t--){
solve();
}
  return 0;
}