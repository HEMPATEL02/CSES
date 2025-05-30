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
void solve()
{
    ull n,k;
    cin>>n>>k;
    vector<ull> v(k);
    for(ull i=0;i<k;i++){
        cin>>v[i];
    }
    sort(v.begin(),v.end());
    ull ans=0;
    for(ull i=1;i<((ull)1<<k);i++){
        ull pro=1;
        bool ff=true;
        for(ull j=0;j<k;j++){
            if((i>>j)&1){
                if(pro>n/v[j]){
                ff=false;
                break;
               }
               pro=pro*v[j];
            }
        }
        if(ff){
        ull count=__builtin_popcount(i);
        ull number_of_elements_divisible_by_pro=n/pro;
        (count%2==1) ? ans+=number_of_elements_divisible_by_pro : ans-=number_of_elements_divisible_by_pro;
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