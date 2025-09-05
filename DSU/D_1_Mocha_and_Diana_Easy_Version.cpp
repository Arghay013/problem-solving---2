#include <bits/stdc++.h>
using namespace std;

struct DSU {
   vector<int> par, rnk, siz;
   int c;
   DSU(int n) :par(n + 1, -1), rnk(n + 1, 0), siz(n + 1, 1), c(n) {
      for (int i = 1;i <= n;i++) {
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
      }
      else {
         c--;
      }

      if (rnk[u] > rnk[v]) {
         swap(u, v);
      }
      else if (rnk[u] == rnk[v]) {
         rnk[v]++;
      }
      par[u] = par[v];
      siz[v] += siz[u];
   }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m1,m2;
    cin >> n >> m1 >> m2;
    DSU d1(n),d2(n);
    while(m1--){
        int u,v;
        cin >> u >> v;
        d1.merge(u,v);
    }
    while(m2--){
        int u,v;
        cin >> u >> v;
        d2.merge(u,v);
    }
    vector<pair<int,int>> v;
    // set<int> vec;
    // for(int i=1; i<=n; i++){
    //     vec.insert(d.find(i));
    // }
    
    // if(vec.size()==1){
    //     cout << 0 << '\n';
    //     return 0;
    // }
    // cout << vec.size()-1<<'\n';
    // vector<int> ans(vec.begin(),vec.end());
    for(int i=1; i<n; i++){
        for(int j=i+1; j<=n; j++){
            if(!d1.same(i,j) and !d2.same(i,j)){
                v.push_back({i,j});
                d1.merge(i,j);
                d2.merge(i,j);
            }
        }
    }
    cout << v.size() << '\n';
    for(auto u:v){
        cout << u.first << ' ' << u.second<<'\n';
    }
    cout << '\n';

    return 0;
}