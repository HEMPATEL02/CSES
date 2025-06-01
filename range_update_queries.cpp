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
#include<bits/stdc++.h>
using namespace std;

void segment_tree(ll index, ll low, ll high, vector<ll> &v, vector<ll> &seg) {
    if (low == high) {
        seg[index] = v[low];
    } else {
        ll mid = (low + high) / 2;
        segment_tree(2 * index + 1, low, mid, v, seg);
        segment_tree(2 * index + 2, mid + 1, high, v, seg);
        seg[index] = seg[2 * index + 1] + seg[2 * index + 2];
    }
}

void range_update(ll ind, ll low, ll high, ll l, ll r, ll value, vector<ll> &seg, vector<ll> &lazy) {
    if (lazy[ind] != 0) {
        seg[ind] += (high - low + 1) * lazy[ind];
        if (low != high) {
            lazy[2 * ind + 1] += lazy[ind];
            lazy[2 * ind + 2] += lazy[ind];
        }
        lazy[ind] = 0;
    }
    if (r < low || high < l || low > high) {
        return;
    }
    if (low >= l && high <= r) {
        seg[ind] += (high - low + 1) * value;
        if (low != high) {
            lazy[2 * ind + 1] += value;
            lazy[2 * ind + 2] += value;
        }
        return;
    }
    ll mid = (low + high) / 2;
    range_update(2 * ind + 1, low, mid, l, r, value, seg, lazy);
    range_update(2 * ind + 2, mid + 1, high, l, r, value, seg, lazy);
    seg[ind] = seg[2 * ind + 1] + seg[2 * ind + 2];
}

ll querySumlazy(ll ind, ll low, ll high, ll l, ll r, vector<ll> &lazy, vector<ll> &seg) {
    if (lazy[ind] != 0) {
        seg[ind] += (high - low + 1) * lazy[ind];
        if (low != high) {
            lazy[2 * ind + 1] += lazy[ind];
            lazy[2 * ind + 2] += lazy[ind];
        }
        lazy[ind] = 0;
    }
    if (r < low || l > high || low > high) {
        return 0;
    }
    if (low >= l && high <= r) {
        return seg[ind];
    }
    ll mid = (low + high) / 2;
    return querySumlazy(2 * ind + 1, low, mid, l, r, lazy, seg) +
           querySumlazy(2 * ind + 2, mid + 1, high, l, r, lazy, seg);
}

void solve() {
    ll n, q;
    cin >> n >> q;
    vector<ll> v(n);
    vector<ll> seg(4 * n, 0), lazy(6 * n, 0);
    for (ll i = 0; i < n; i++){
         cin >> v[i];
    }
    segment_tree(0, 0, n - 1, v, seg);
    while (q--) {
        ll value;
        cin >> value;
        if (value == 2) {
            ll k;
            cin >> k;
            k--;
            cout << querySumlazy(0, 0, n - 1, k, k, lazy, seg) << endl;
        } else {
            ll a, b, u;
            cin >> a >> b >> u;
            a--, b--;
            range_update(0, 0, n - 1, a, b, u, seg, lazy);
        }
    }
}

int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}
