/* 
   {  
     author: hem_patel_02
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
    ll n;
    cin>>n;
    if(n==1){
        cout<<1<<endl;
        return;
    }
    if(n<=3){
        cout<<"NO SOLUTION"<<endl;
        return;
    }
    if(n==4){
        cout<<"3 1 4 2"<<endl;
        return;
    }
    for(ll i=1;i<=n/2;i++){
        cout<<i<<" "<<i+n/2+n%2<<" ";
    }
    if(n&1){
        cout<<n/2+n%2;
    }
    cout<<endl;
}
int32_t main()
{
ios::sync_with_stdio(0);
cin.tie(0);
cout.tie(0);
solve();
  return 0;
}