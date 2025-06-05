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
    ll n,k;
    cin>>n>>k;
    vector<ll> v(n);
    for(ll i=0;i<n;i++){
        string s;
        cin>>s;
        ll pow=1;
        for(ll j=0;j<min((ll)30,k);j++){
            ll bit=s[j]-'0';
            if(bit){
                v[i]+=pow;
            }
            pow=2*pow;
        }
    }
    ll ans=1e5;
    for(ll i=0;i<n-1;i++){
        for(ll j=i+1;j<n;j++){
            ll xor1=v[i]^v[j];
            ll count=__builtin_popcount(xor1);
            ans=min(ans,count);
        }
    }
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