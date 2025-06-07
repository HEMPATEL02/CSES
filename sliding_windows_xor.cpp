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
    ll x,a,b,c;
    cin>>x>>a>>b>>c;
    vector<ll> v(n);
    v[0]=x;
    for(ll i=1;i<n;i++){
        v[i]=((a%c*v[i-1]%c)%c+b%c)%c;
    }
    ll left=0;
    ll ans=0;
    ll xor1=0;
    for(ll i=0;i<n;i++){
        if(i<k-1){
            xor1=xor1^v[i];
        }
        else{
            xor1=xor1^v[i];
            ans=ans^xor1;
            xor1=xor1^v[left];
            left++;
        }
    }
    cout<<ans<<endl;
}
int32_t main()
{
ios::sync_with_stdio(0);
cin.tie(0);
cout.tie(0);
solve();
  return 0;
}