#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll  maxN = 1e5 + 9, inf = 1e9 + 9;
ll a[maxN], t[maxN * 4];

void build(ll n, ll b, ll e) {
   if (b == e) {
      t[n] = a[b];
      return;
   }
   ll mid = (b + e) / 2, l = (2 * n), r = (2 * n) + 1;
   build(l, b, mid);
   build(r, mid + 1, e);
   t[n] = __gcd(t[l], t[r]); // change this
}

void update(ll n, ll b, ll e, ll i, ll v) {
   if (i<b || i>e) {
      return;
   }
   if (b == e) {
      t[n] = v;
      return;
   }
   ll mid = (b + e) / 2, l = (2 * n), r = (2 * n) + 1;
   update(l, b, mid, i, v);
   update(r, mid + 1, e, i, v);
   t[n] = min(t[l], t[r]);  // change this
}

ll query(ll n, ll b, ll e, ll i, ll j) {
   if (e < i || j < b) {
      return 0; // return right value
   }
   if (b >= i && e <= j) {
      return t[n];
   }
   ll mid = (b + e) / 2, l = (2 * n), r = (2 * n) + 1;
   return __gcd(query(l, b, mid, i, j), query(r, mid + 1, e, i, j)); // change this
}

int main() {
   ios::sync_with_stdio(false);
   cin.tie(nullptr);

    ll n;
    cin >> n;
    
    for(int i=1; i<=n; i++)cin >> a[i];
    for(int i=1; i<=n; i++){
        if(a[i]==1){
            cout << 1 <<'\n';
            return 0;
        }
    }
    build(1, 1, n);
    ll ans = LONG_LONG_MAX;
    ll l=1;
    for(int r=1; r<=n; r++){
        while(l<=r){
            ll cur_gcd = query(1, 1, n, l, r);
            if(cur_gcd == 1){
                ans = min( ans, r-l+1);
                l++;
            }else{
                break;
            }
        }
    }
    if(ans == LONG_LONG_MAX){
        cout << -1 << '\n';
    }
    else cout << ans << '\n';

   return 0;
}