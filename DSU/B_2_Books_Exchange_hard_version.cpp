#include <bits/stdc++.h>
using namespace std;

struct DSU {
   vector<int> par, rnk, siz;
   int c;
   DSU(int n) :par(n + 1, -1), rnk(n + 1, 0), siz(n + 1, 1), c(n) {
      for (int i = 1; i <= n; i++) {
         par[i] = i;
      }
   }
   int find(int i) {
      return (par[i] == i ? i : (par[i] = find(par[i])));
   }
   bool same(int u, int v) {
      return find(u) == find(v);
   }
   int getSize(int u) {
      return siz[find(u)];
   }
   int cnt() {
      return c;
   }
   void merge(int u, int v) {
      u = find(u);
      v = find(v);
      if (u == v) return;
      c--;
      if (rnk[u] > rnk[v]) swap(u, v);
      else if (rnk[u] == rnk[v]) rnk[v]++;
      par[u] = v;
      siz[v] += siz[u];
   }
};
void solve(){
    int n;
    cin >> n;
    int a[n+1];
    DSU d(n);
    for(int i=1; i<=n; i++){
        cin >> a[i];
        d.merge(i,a[i]);
    }
    // vector<int> c(n+1,0);
    // for(int i=1; i<=n; i++){
    //     c[d.find(a[i])]++;
    // }
    // for(int i=1; i<=n; i++){
    //     cout << c[i] << ' ';
    // }
    for(int i=1; i<=n; i++)cout << d.getSize(i) << ' ';
    cout << '\n';

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int q;
    cin >> q;
    while(q--){
        solve();
    }
    return 0;
}
