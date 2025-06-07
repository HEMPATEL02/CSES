/*
   {
     author:hem_patel_02  
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
void solve()
{
    ll n,k;
    cin>>n>>k;
    ll x,a,b,c;
    cin>>x>>a>>b>>c;
    vector<ll> v(n);
    vector<ll> v1(31,0);
    v[0]=x;
    for(ll i=1;i<n;i++){
        v[i]=((a%c*v[i-1]%c)%c+b%c)%c;
    }
    ll left=0;
    ll ans=0;
    ll xor1=0;
    for(ll i=0;i<n;i++){
        if(i<k-1){
            ll x1=v[i];
            ll count1=0;
            while(x1){
                if(x1&1){
                    v1[count1]++;
                }
                count1++;
                x1=x1>>1;
            }
        }
        else{
            ll c2=0;
            ll x2=v[i];
            while(x2){
                if(x2&1){
                    v1[c2]++;
                }
                c2++;
                x2=x2>>1;
            }
            ll ww=0;
            ll pow=1;
            for(ll j=0;j<=30;j++){
                if(v1[j]>0){
                    ww+=pow;
                }
                pow=2*pow;
            }
            ans=ans^ww;
            ll x3=v[left];
            ll c3=0;
            while(x3){
                if(x3&1){
                    v1[c3]--;
                }
                x3=x3>>1;
                c3++;
            }
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