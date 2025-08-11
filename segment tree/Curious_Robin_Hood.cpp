#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

const int maxN = 1e5 + 123;
ll a[maxN], tree[4 * maxN];

void build(int n, int b, int e) {
    if (b == e) {
        tree[n] = a[b];
        return;
    }
    int mid = (b + e) / 2;
    int l = n * 2, r = n * 2 + 1;
    build(l, b, mid);
    build(r, mid + 1, e);
    tree[n] = tree[l] + tree[r];
}

void update(int n, int b, int e, int i, int v) {
    if (i > e || i < b) {
        return;
    }
    if (b == e) {
        tree[n] = v;
        return;
    }
    int mid = (b + e) / 2;
    int l = n * 2, r = n * 2 + 1;
    update(l, b, mid, i, v);
    update(r, mid + 1, e, i, v);
    tree[n] = tree[l] + tree[r];
}

ll query(int n, int b, int e, int i, int j) {
    if (e < i || b > j) {
        return 0;
    }
    if (b >= i && e <= j) {
        return tree[n];
    }
    int mid = (b + e) / 2;
    int l = n * 2, r = n * 2 + 1;
    return query(l, b, mid, i, j) + query(r, mid + 1, e, i, j);
}

int main() {
    optimize();
    int T;
    cin >> T;
    for (int tc = 1; tc <= T; ++tc) {
        cout << "Case " << tc << ":\n";
        int n, q;
        cin >> n >> q;
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
        }
        build(1, 1, n);
        while (q--) {
            int type;
            cin >> type;
            if (type == 1) {
                int i;
                cin >> i;
                i++; 
                ll val = query(1, 1, n, i, i);
                update(1, 1, n, i, 0);
                cout << val << '\n';
            } else if (type == 2) {
                int i, v;
                cin >> i >> v;
                i++; 
                ll current = query(1, 1, n, i, i);
                update(1, 1, n, i, current + v);
            } else if (type == 3) {
                int i, j;
                cin >> i >> j;
                i++; j++; 
                cout << query(1, 1, n, i, j) << '\n';
            }
        }
    }
    return 0;
}