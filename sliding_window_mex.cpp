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
vector<ll> mp(2*1e5+10,0);
void solve()
{
    ll n,k;
    cin>>n>>k;
    ll left=0;
    vector<ll> v(n);
    set<ll> st;
    for(ll i=0;i<n;i++){
        cin>>v[i];
        if(i<k && v[i]<=n+2){
            mp[v[i]]++;
        }
        if(i<=k){
            st.insert(i);
        }
    }
    for(ll i=k;i>=0;i--){
        if(mp[i]!=0){
            auto it1=st.find(i);
            if(it1!=st.end()){
                st.erase(it1);
            }
        }
    }
    cout<<*st.begin()<<" ";
    for(ll i=k;i<n;i++){
        ll x1=v[left];
        if(x1<=n+1){
        mp[x1]--;
        if(mp[x1]==0){
            st.insert(x1);
        }
      }
        if(v[i]<=n+1){
        mp[v[i]]++;
        auto it1=st.find(v[i]);
        if(it1!=st.end()){
            st.erase(it1);
        }
    }
        left++;
        cout<<*st.begin()<<" ";
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