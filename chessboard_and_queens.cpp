#define mod 1000000007
#define ull unsigned long long
#define ll long long
#define cy cout<<"YES"<<endl
#define cn cout<<"NO"<<endl
#define hai cout<<-1<<endl
#define pb push_back
#define ff first
#define ss secondbool isprime(ll n){if (n <= 1)  return 0; if (n <= 3)  return 1; if (n%2 == 0 || n%3 == 0) return 0; for (int i=5; i*i<=n; i=i+6) if (n%i == 0 || n%(i+2) == 0) return 0; return 1;}
#include<bits/stdc++.h>
using namespace std;
bool func(ll level,ll col,vector<string> &v,vector<ll> &queen){
    if(v[level][col]=='*'){
        return false;
    }
    for(ll i=0;i<level;i++){
        ll prev_row=i;
        ll prev_col=queen[i];
        if(prev_col==-1 || prev_col==col || abs(prev_row-level)==abs(prev_col-col)){
            return false;
        }
    }
    return true;
}
void func1(ll level,vector<string> &v,ll &ans,vector<ll> &queen){
    if(level==8){
        ans++;
        return;
    }
    for(ll col=0;col<8;col++){
        if(func(level,col,v,queen)){
            queen[level]=col;
            func1(level+1,v,ans,queen);
            queen[level]=-1;
        }
    }
}
void solve()
{
    vector<string> v(8);
    for(ll i=0;i<v.size();i++){
        cin>>v[i];
    }
    vector<ll> queen_level(8,-1);
    ll ans=0;
    func1(0,v,ans,queen_level);
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