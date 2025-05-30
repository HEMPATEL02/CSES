/*
{
   author: hem_patel_02
}
*/
#define mod 1000000007
#define ull unsigned long long
#define ll long long
#define cy cout << "YES" << endl
#define cn cout << "NO" << endl
#define hai cout << -1 << endl
#define pb push_back
#define ff first
#define ss second
bool isprime(ll n)
{
    if (n <= 1)
        return 0;
    if (n <= 3)
        return 1;
    if (n % 2 == 0 || n % 3 == 0)
        return 0;
    for (int i = 5; i * i <= n; i = i + 6)
        if (n % i == 0 || n % (i + 2) == 0)
            return 0;
    return 1;
}
#include <bits/stdc++.h>
using namespace std;
vector<bool> is_prime(1e6 + 5, true);
vector<ll> v1;
void func()
{
    is_prime[0] = false;
    is_prime[1] = false;
    for (ll i = 2; i <= 1e6; i++)
    {
        if (is_prime[i])
        {
            v1.pb(i);
            for (ll j = 2 * i; j <= 1e6; j += i)
            {
                is_prime[j] = false;
            }
        }
    }
}
void solve()
{
    ll n;
    cin >> n;
    vector<bool> v(1200, true);
    ll limit = n + 1150;
    ll i = 0;
    while (i < v1.size() && v1[i] * v1[i] <= limit)
    {
        ll prime = v1[i];
        ll start = max(prime * prime, ((n + 1 + prime - 1) / prime) * prime);
        for (ll j = start; j <= limit; j += prime)
        {
            v[j - (n + 1)] = false;
        }
        i++;
    }
    for (ll i = 0; i < v.size(); i++)
    {
        if (v[i])
        {
            cout << i + n + 1 << endl;
            return;
        }
    }
}

int32_t main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    func();
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}