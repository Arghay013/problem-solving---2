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
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;


template <typename T> using pbds = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

int dx[] = {0, 0, +1, -1};
int dy[] = {+1, -1, 0, 0};
//int dx[] = {+1, 0, -1, 0, +1, +1, -1, -1};
//int dy[] = {0, +1, 0, -1, +1, -1, +1, -1};


// ceil value x = (n+(m-1))/m

void solve(){
    ll n;
    cin >> n;
    vector< pair<ll, ll> > v;
    for(int i=0; i<n; i++){
        ll a,b;
        cin >> a >> b;
        v.push_back({b,a});
    }
    sort(all(v));
    ll ans=0;
    pbds<ll> pb;
    for(int i=n-1; i>=0; i--){
        ll a = v[i].second;
        ll b = v[i].first;
        ans += pb.order_of_key(a);
        pb.insert(a);
    }
    cout <<ans << '\n';

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