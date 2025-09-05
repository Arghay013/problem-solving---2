#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
template <typename T> using pbds = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
using ll = long long;
#define sz(yo) (ll)yo.size()

struct DSU {
   vector<int> par, rnk, siz;
   int c;
   DSU(int n) : par(n + 1), rnk(n + 1, 0), siz(n + 1, 1), c(n) {
      for (int i = 1; i <= n;i++) {
         par[i] = i;
      }
   }
   int find(int i) {
      return (par[i] == i ? i : (par[i] = find(par[i])));
   }
   bool same(int i, int j) {
      return find(i) == find(j);
   }
   int get_size(int i) {
      return siz[find(i)];
   }
   int count() {
      return c;
   }
   void merge(int u, int v) {
      if ((u = find(u)) != (v = find(v))) {
         c--;
      }
      if (rnk[u] > rnk[v]) {
         swap(u, v);
      }
      else if (rnk[u] == rnk[v]) {
         rnk[u]++;
      }
      par[u] = par[v];
      siz[v] += siz[u];
   }
};

void solve() {
   int n, m1, m2;
   cin >> n >> m1 >> m2;
   vector<pair<int, int>> edgeList1, edgeList2;
   for (int i = 1;i <= m1;i++) {
      int u, v;
      cin >> u >> v;
      edgeList1.push_back({ u,v });
   }
   for (int i = 1;i <= m2;i++) {
      int u, v;
      cin >> u >> v;
      edgeList2.push_back({ u,v });
   }

   DSU F(n), G(n);
   for (int i = 0;i < m2;i++) {
      G.merge(edgeList2[i].first, edgeList2[i].second);
   }

   int ans = 0;
   for (int i = 0;i < m1;i++) {
      if (G.same(edgeList1[i].first, edgeList1[i].second)) {
         F.merge(edgeList1[i].first, edgeList1[i].second);
      }
      else {
         ans++;
      }
   }

   cout << ans + (F.count() - G.count()) << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    t = 1;
    cin >> t;
    for (int cs = 1; cs <= t; cs++) {
        // cout << "Case " << cs << ": ";
        solve();
    }
   return 0;
}