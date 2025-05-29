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
vector<ll> v(1e6+5,0);
void func(){
    for(ll i=1;i<v.size();i++){
        for(ll j=i;j<v.size();j+=i){
            v[j]++;
        }
    }
}
void solve()
{
    ll n;
    cin>>n;
    ll ans=v[n];
    cout<<ans<<endl;
}
int32_t main()
{
ios::sync_with_stdio(0);
cin.tie(0);
cout.tie(0);
func();
int t=1;
cin>>t;
while(t--){
solve();
}
  return 0;
}