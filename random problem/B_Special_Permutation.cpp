#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;

#define PB push_back
#define F first
#define S second
#define MP make_pair
#define endl '\n'
#define yes   cout<<"YES"<<endl
#define no   cout<<"NO"<<endl
#define all(a) (a).begin(),(a).end()

#define mid(l,r) ((r+l)/2)
#define mx_int_prime 999999937

const double PI = acos(-1);

#define mem(a,b) memset(a, b, sizeof(a) )
#define GCD(a,b) __gcd(a,b)
#define LCM(a,b) ((a)/__gcd(a,b))*b

#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

int dx[] = {0, 0, +1, -1};
int dy[] = {+1, -1, 0, 0};
//int dx[] = {+1, 0, -1, 0, +1, +1, -1, -1};
//int dy[] = {0, +1, 0, -1, +1, -1, +1, -1};


// ceil value x = (n+(m-1))/m

void solve() {
    int n, a, b;
    cin >> n >> a >> b;

    int half = n / 2;
    vector<int> left, right;

    left.push_back(a);
    right.push_back(b);

    set<int> used;
    used.insert(a);
    used.insert(b);

    for (int i = n; i >= 1 && left.size() < half; i--) {
        if (used.count(i) || i < a) continue;
        left.push_back(i);
        used.insert(i);
    }

    for (int i = 1; i <= n && right.size() < half; i++) {
        if (used.count(i) || i > b) continue;
        right.push_back(i);
        used.insert(i);
    }

    if (left.size() != half || right.size() != half) {
        cout << -1 << endl;
        return;
    }

    for (int x : left) cout << x << " ";
    for (int x : right) cout << x << " ";
    cout << endl;
}

int main() {
    optimize();
    int t;
    cin >> t;
    for(ll cs = 1; cs <= t; cs++){
     // cout << "Case " << cs << ": ";
        solve();
    }
    return 0;
}