/*
{
   author : hem_patel_02
}
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
vector<vector<ll>> distinct_prime(1e6+5);
vector<bool> is_prime(1e6+5,true);
void func(){
    is_prime[0]=false;
    is_prime[1]=false;
    for(ll i=2;i<distinct_prime.size();i++){
        if(is_prime[i]){
            distinct_prime[i].pb(i);
            for(ll j=2*i;j<distinct_prime.size();j+=i){
                is_prime[j]=false;
                distinct_prime[j].pb(i);
            }
        }
    }
} 
void solve()
{
    ll n;
    cin>>n;
    vector<ll> v(n);
    ll maxi=-1;
    for(ll i=0;i<n;i++){
        cin>>v[i];
        maxi=max(maxi,v[i]);
    }
    vector<ll> divisible_by_me(1e6+5,0);
    for(ll i=0;i<n;i++){
        ll pow=distinct_prime[v[i]].size();
        for(ll j=1;j<((ll)1<<pow);j++){
            ll value=1;
            ll count=0;
            for(ll k=0;k<pow;k++){
                if((j>>k)&1){
                    value=value*distinct_prime[v[i]][k];
                    count++;
                }
            }
            divisible_by_me[value]++;
        }
    }
    ll ans=0;
    for(ll i=2;i<=maxi;i++){
        if(divisible_by_me[i]){
            ll cnt = divisible_by_me[i];
            ll pairs = (cnt*(cnt-1))/2;
            if(distinct_prime[i].size() % 2 == 1){
                ans += pairs;
            }else{
                ans -= pairs;
            }
        }
    }
    cout<<((n)*(n-1)/2)-ans<<endl;
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
