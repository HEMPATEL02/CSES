/*
  {
    author: hem_patel_02
  }
*/ 
#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007
#define ull unsigned long long
#define ll long long
#define cy cout<<"YES"<<endl
#define cn cout<<"NO"<<endl
#define hai cout<<-1<<endl
#define pb push_back
#define ff first
#define ss second

bool isprime(ll n){
    if (n <= 1) return 0;
    if (n <= 3) return 1;
    if (n % 2 == 0 || n % 3 == 0) return 0;
    for (int i = 5; i * i <= n; i += 6)
        if (n % i == 0 || n % (i + 2) == 0) return 0;
    return 1;
}

void func(const vector<ll> &v, vector<ll> &v1, ll x) {
    ll n = v.size();
    for (ll i = 0; i < (1LL << n); i++) {
        ll sum = 0;
        bool ff = true;
        for (ll j = 0; j < n; j++) {
            if (i & (1LL << j)) {
                if (sum > x - v[j]) {
                    ff = false;
                    break;
                }
                sum += v[j];
            }
        }
        if (ff){
            v1.pb(sum);
        }
    }
}

void solve() {
    ll n, x;
    cin >> n >> x;
    vector<ll> v, v1, v2;
    
    for (ll i = 0; i < n; i++) {
        ll y;
        cin >> y;
        if (y <= x) {
            v2.pb(y);
        }
    }

    ll n1 = v2.size();
    for (ll i = 0; i < n1 / 2; i++) {
        v.pb(v2[i]);
    }
    for (ll i = n1 / 2; i < n1; i++) {
        v1.pb(v2[i]);
    }

    vector<ll> ans, ans1;
    func(v, ans, x);
    func(v1, ans1, x);

    sort(ans1.begin(), ans1.end());

    ll ans2 = 0;
    for (auto it : ans) {
        ll value = x - it;
        auto it2=upper_bound(ans1.begin(), ans1.end(), value)-ans1.begin();
        auto it3=lower_bound(ans1.begin(), ans1.end(), value)-ans1.begin();
        ans2+=(it2-it3);
    }

    cout << ans2 << endl;
}

int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}
