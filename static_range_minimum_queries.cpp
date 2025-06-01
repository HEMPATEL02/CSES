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
void segment_tree(ll index,ll low,ll high,vector<ll> &v,vector<ll> &seg){
    if(low==high){
        seg[index]=v[low];
    }
    else{
        ll mid=low+(high-low)/2;

        segment_tree(2*index+1,low,mid,v,seg);
        segment_tree(2*index+2,mid+1,high,v,seg);

        seg[index]=min(seg[2*index+1],seg[2*index+2]);
    }
}
ll query(ll idx,ll low,ll high,ll l,ll r,vector<ll> &seg){
    // low and high inside l<=low<=high<=r
    if(l<=low && high<=r){
        return seg[idx];
    }
    // l<r<low<high || low<high<l<r
    if(low>r || high<l){
        return 1e10;
    }
    ll mid=low+(high-low)/2;
    ll left=query(2*idx+1,low,mid,l,r,seg);
    ll right=query(2*idx+2,mid+1,high,l,r,seg);
    return min(left,right);
}
// update ---> not required
void update(ll idx,ll node,ll value,ll low,ll high,vector<ll> &seg){
    if(low==high){
        seg[idx]=value;    
    }else{
        ll mid=low+(high-low)/2;
        if(low<=node && mid>=node){
            update(2*idx+1,node,value,low,mid,seg);
        }else{
            update(2*idx+2,node,value,mid+1,high,seg);
        }
        seg[idx]=min(seg[2*idx+1],seg[2*idx+2]);
    }
}
void solve()
{
    ll n,q;
    cin>>n>>q;
    vector<ll> v(n);
    for(ll i=0;i<n;i++){
        cin>>v[i];
    }
    vector<ll> seg(4*n,0);
    segment_tree(0,0,n-1,v,seg);
    while(q--){
        ll left,right;
        cin>>left>>right;
        left--,right--;
        cout<<query(0,0,n-1,left,right,seg)<<endl;
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