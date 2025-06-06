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
    ll sum=(n*(n+1))/2;
    if(sum&1){
        cn;
        return;
    }
    if(n%4!=3 && n%4!=0){
        return;
    }
    vector<ll> fir,sec;
    for(ll i=1;i<=n;i++){
        if(i<=2 && n%4==3){
            fir.pb(i);
            // i++;
        }else if(i<=3 && n%4==3){
            sec.pb(i);
            // i++;
        }else{
            fir.pb(i);
            fir.pb(i+3);
            sec.pb(i+1);
            sec.pb(i+2);
            i+=3;
        }
    }
    
    sort(fir.begin(),fir.end());
    sort(sec.begin(),sec.end());
    cy;
    cout<<sec.size()<<endl;
    for(ll i=sec.size()-1;i>=0;i--){
        cout<<sec[i]<<" ";
    }
    cout<<endl;
    cout<<fir.size()<<endl;
    for(ll i=fir.size()-1;i>=0;i--){
        cout<<fir[i]<<" ";
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


// 5
// 1,2,3,4,5
//4----> ((4)*(5))/2
// 8
// 1,2,3,4,5,6,7,8
// 1,2,3,4,5,6
// 1,2,3,4,5