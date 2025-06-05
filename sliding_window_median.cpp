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
    ll n,k;
    cin>>n>>k;
    vector<ll> v(n);
    multiset<ll> st;
    for(ll i=0;i<n;i++){
        cin>>v[i];
        if(i<k){
            st.insert(v[i]);
        }
    }   
    auto it=st.begin();
    for(ll i=0;i<(k-1)/2;i++){
        it++;
    }
    ll left=0;
    for(ll i=k;i<=n;i++){
        auto it1=it;
        it1++;
        ll median=(k%2==0) ? min(*it,*it1): *it;
        // if(*it>=*it1){
        //     it++;
        // }

        cout<<median<<" ";
        if(i==n){
            break;
        }
        st.insert(v[i]);        
        if(v[i]<(*it)){
            it--;
        }
        if(v[left]<=(*it)){
            it++;
        }
        auto it2=st.lower_bound(v[left]);
        if(it2!=st.end()){
            st.erase(it2);
        }
        left++;
    }
}
int32_t main()
{
ios::sync_with_stdio(0);
cin.tie(0);
cout.tie(0);
solve();
  return 0;
}