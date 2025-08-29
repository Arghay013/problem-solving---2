#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 9;
const long long NO_LAZY = -1; // means no assignment pending

long long t[MAXN * 4], lazy[MAXN * 4];

void apply(int n, int b, int e, long long v) {
    t[n] = v;   // since assignment, entire segment becomes v
    lazy[n] = v;
}

void push(int n, int b, int e) {
    if (lazy[n] == NO_LAZY) return;
    if (b != e) { // propagate to children
        int l = n * 2, r = n * 2 + 1;
        apply(l, b, (b+e)/2, lazy[n]);
        apply(r, (b+e)/2 + 1, e, lazy[n]);
    }
    lazy[n] = NO_LAZY;
}

void build(int n, int b, int e) {
    lazy[n] = NO_LAZY;
    if (b == e) {
        t[n] = 0; // initially all zeros
        return;
    }
    int mid = (b + e) / 2;
    build(n*2, b, mid);
    build(n*2+1, mid+1, e);
    t[n] = min(t[n*2], t[n*2+1]);
}

void update(int n, int b, int e, int i, int j, long long v) {
    push(n, b, e);
    if (e < i || j < b) return;
    if (i <= b && e <= j) {
        apply(n, b, e, v);
        return;
    }
    int mid = (b + e) / 2;
    update(n*2, b, mid, i, j, v);
    update(n*2+1, mid+1, e, i, j, v);
    t[n] = min(t[n*2], t[n*2+1]);
}

long long query(int n, int b, int e, int i, int j) {
    push(n, b, e);
    if (e < i || j < b) return LLONG_MAX; // no overlap
    if (i <= b && e <= j) return t[n];
    int mid = (b + e) / 2;
    return min(query(n*2, b, mid, i, j),
               query(n*2+1, mid+1, e, i, j));
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
