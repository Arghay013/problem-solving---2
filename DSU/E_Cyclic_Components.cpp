#include <bits/stdc++.h>
using namespace std;

struct DSU {
   vector<int> par, rnk, siz;
   int c;
   DSU(int n) : par(n + 1, -1), rnk(n + 1, 0), siz(n + 1, 1), c(n) {
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
      if ((u = find(u)) == (v = find(v))) {
         return;
      } else {
         c--;
      }

      if (rnk[u] > rnk[v]) {
         swap(u, v);
      } else if (rnk[u] == rnk[v]) {
         rnk[v]++;
      }
      par[u] = par[v];
      siz[v] += siz[u];
   }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    DSU dsu(n);
    vector<vector<int>> adj(n + 1);

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        dsu.merge(u, v);
    }

    // component অনুযায়ী nodes ভাগ করে নিচ্ছি
    vector<vector<int>> comp(n + 1);
    for (int i = 1; i <= n; i++) {
        comp[dsu.find(i)].push_back(i);
    }

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (!comp[i].empty()) {
            bool ok = true;
            if ((int)comp[i].size() >= 3) {
                for (int v : comp[i]) {
                    if ((int)adj[v].size() != 2) {
                        ok = false;
                        break;
                    }
                }
                if (ok) ans++;
            }
        }
    }

    cout << ans << "\n";

    return 0;
}
