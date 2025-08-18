#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 9;

long long a[MAXN], t[MAXN * 4], lazy[MAXN * 4];

void push(int n, int b, int e) {
    if (lazy[n] == 0) return; // no pending OR
    t[n] |= lazy[n];
    if (b != e) {
        int l = n * 2, r = n * 2 + 1;
        lazy[l] |= lazy[n];
        lazy[r] |= lazy[n];
    }
    lazy[n] = 0;
}

void build(int n, int b, int e) {
    lazy[n] = 0;
    if (b == e) {
        t[n] = a[b];
        return;
    }
    int mid = (b + e) / 2;
    build(n * 2, b, mid);
    build(n * 2 + 1, mid + 1, e);
    t[n] = t[n * 2] & t[n * 2 + 1];
}

void update(int n, int b, int e, int i, int j, long long v) {
    push(n, b, e);
    if (e < i || j < b) return;
    if (i <= b && e <= j) {
        lazy[n] |= v;
        push(n, b, e);
        return;
    }
    int mid = (b + e) / 2;
    update(n * 2, b, mid, i, j, v);
    update(n * 2 + 1, mid + 1, e, i, j, v);
    t[n] = t[n * 2] & t[n * 2 + 1];
}

long long query(int n, int b, int e, int i, int j) {
    push(n, b, e);
    if (e < i || j < b) return (1LL << 31) - 1; // all bits set
    if (i <= b && e <= j) return t[n];
    int mid = (b + e) / 2;
    return query(n * 2, b, mid, i, j) & query(n * 2 + 1, mid + 1, e, i, j);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    build(1, 0, n - 1);

    while (m--) {
        int type;
        cin >> type;
        if (type == 1) {
            int l, r;
            long long v;
            cin >> l >> r >> v;
            update(1, 0, n - 1, l, r - 1, v);
        } else {
            int l, r;
            cin >> l >> r;
            cout << query(1, 0, n - 1, l, r - 1) << "\n";
        }
    }
    return 0;
}
