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
vector<ll> fact(1e6+1,0);
void func(){
    fact[0]=1;
    for(ll i=1;i<fact.size();i++){
        fact[i]=(fact[i-1]%mod*i%mod)%mod;
    }
}
ll power(ll a,ll b){
    ll res=1;
    while(b){
        if(b&1){
            res=(res%mod*a%mod)%mod;
        }
        b=b>>1;
        a=(a%mod*a%mod)%mod;
    }
    return res;
}

void solve()
{
    ll b,a;
    cin>>a>>b;
    ll ans=fact[a];
    ll ans1=(fact[a-b]%mod*fact[b]%mod)%mod;
    ans1=power(ans1,mod-2);
    ans=(ans%mod*ans1%mod)%mod;
    cout<<ans<<endl;
}
int32_t main()
{
ios::sync_with_stdio(0);
cin.tie(0);
cout.tie(0);
int t=1;
func();
cin>>t;
while(t--){
solve();
}
  return 0;
}