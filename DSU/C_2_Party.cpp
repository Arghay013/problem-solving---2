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

int main() {
   ios::sync_with_stdio(false);
   cin.tie(nullptr);

   int n; 
   cin >> n;

   int k; 
   cin >> k; // friendship pairs
   DSU D(n);

   for (int i = 0; i < k; i++) {
      int u, v;
      cin >> u >> v;
      D.merge(u, v);
   }

   int m; 
   cin >> m; // dislike pairs
   set<int> bad; // invalid components

   for (int i = 0; i < m; i++) {
      int u, v;
      cin >> u >> v;
      if (D.same(u, v)) {
         bad.insert(D.find(u)); // এই component invalid
      }
   }

   vector<int> compSize(n + 1, 0);
   for (int i = 1; i <= n; i++) {
      int root = D.find(i);
      if (bad.find(root) == bad.end()) {
         compSize[root]++;
      }
   }

   int ans = 0;
   for (int i = 1; i <= n; i++) {
      ans = max(ans, compSize[i]);
   }

   cout << ans << "\n";
   return 0;
}
