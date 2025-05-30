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
vector<ll> fact(1e6+1);
void func(){
    fact[0]=1;
    for(ll i=1;i<=1e6;i++){
        fact[i]=(fact[i-1]%mod*i%mod)%mod;
    }
}
ll power(ll a,ll b)
{
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
    string s;
    cin>>s;
    ll n=s.size();
    vector<ll> v(26,0);
    for(ll i=0;i<n;i++){
        ll x=s[i]-'a';
        v[x]++;
    }
    ll ans=fact[n];
    ll ans1=1;
    for(auto it : v){
        ans1=(ans1%mod*fact[it]%mod)%mod;
    }
    ans=(ans%mod*power(ans1,mod-2)%mod)%mod;
    cout<<ans<<endl;
}
int32_t main()
{
ios::sync_with_stdio(0);
cin.tie(0);
cout.tie(0);
func();
solve();
  return 0;
}