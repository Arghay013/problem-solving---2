#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define sz(yo) (ll)yo.size()

const ll maxN = 2e5 + 9;
ll a[maxN], t[maxN * 4];

void build(ll n, ll b, ll e)
{
    if (b == e)
    {
        t[n] = a[b];
        return;
    }
    ll mid = (b + e) / 2, l = (2 * n), r = (2 * n) + 1;
    build(l, b, mid);
    build(r, mid + 1, e);
    t[n] = t[l] & t[r];
}

ll query(ll n, ll b, ll e, ll i, ll j)
{
    if (e < i or j < b)
        return (1LL << 30) - 1;
    if (b >= i and e <= j)
        return t[n];
    ll mid = (b + e) / 2, l = (2 * n), r = (2 * n) + 1;
    return query(l, b, mid, i, j) & query(r, mid + 1, e, i, j);
}

void solve()
{
    ll n;
    cin >> n;
    for (ll i = 1;i <= n;i++)
        cin >> a[i];
    build(1, 1, n);
    ll q;
    cin >> q;
    while (q--)
    {
        ll L, K, l, r, mid, ans = -1;
        cin >> L >> K;

        auto ok = [&](ll mid)
            {
                return query(1, 1, n, L, mid) >= K;
            };

        l = L, r = n;
        while (l <= r)
        {
            mid = l + (r - l) / 2;
            if (ok(mid))
            {
                ans = mid;
                l = mid + 1;
            }
            else
                r = mid - 1;
        }
        cout << ans << " ";
    }
    cout << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t;
    t = 1;
    cin >> t;
    for (ll cs = 1; cs <= t; cs++)
    {
        // cout << "Case " << cs << ": ";
        solve();
    }
    return 0;
}

