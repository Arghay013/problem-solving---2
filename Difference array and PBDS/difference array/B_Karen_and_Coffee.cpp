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
const ll N = 200007;
ll p[N+2],c[N+2],d[N+2];
void solve(){
    memset(p, 0, sizeof(p));
    memset(c, 0, sizeof(c));
    ll n,k,q;
    cin >> n >> k >> q;
    for(ll i=0; i<n; i++){
        ll a,b;
        cin >> a >> b;
        p[a]++;
        p[b+1]--;
    }
    for(ll i=1; i<N; i++){
        p[i] += p[i-1];
        c[i] += c[i-1] + (p[i] >= k);
    }
    for(ll i=0; i<q; i++){
        ll x,y;
        cin >> x >> y;
        cout << c[y] - c[x-1] << '\n';
    }
}
int main() {
    optimize();
    int t=1;
    for(ll cs = 1; cs <= t; cs++){
     // cout << "Case " << cs << ": ";
        solve();
    }
    return 0;
}