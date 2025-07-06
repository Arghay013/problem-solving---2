#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
   ios::sync_with_stdio(false);
   cin.tie(nullptr);

   int n, q;
   cin >> n >> q;
   vector<int> a(n);
   for (int i = 0;i < n;i++) {
      cin >> a[i];
   }

   vector<int> d(n+1);
   for (int i = 0;i < q;i++) {
      int l, r;
      cin >> l >> r;l--;r--;
      d[l] += 1;
      d[r + 1] -= 1;
   }

   for (int i = 1;i <= n;i++) {
      d[i] =  d[i]+d[i-1];
   }
//    for (int i = 1;i < n;i++) {
//       cout << d[i]<< ' ';
//    }
   sort(a.rbegin(),a.rend());
   sort(d.rbegin(),d.rend());
//    for(int i=0; i<n; i++){
//     cout << a[i] << ' ';
//    }
//    cout << '\n';
//    for(int i=0; i<n; i++){
//     cout << d[i] << ' ';
//    }
//    cout << '\n';
   ll sum = 0;
   for (int i = 0;i < n;i++) {
      sum += (1LL*a[i]*d[i]);
   }
   cout << sum;

   return 0;
}