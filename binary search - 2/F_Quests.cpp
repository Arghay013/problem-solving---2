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

void solve(){
    ll n,c,d;
    cin >> n >> c >> d;
    vl a(n);
    for(int i=0; i<n; i++)cin >> a[i];
    sort(a.rbegin(), a.rend());
    // for(auto u:a)cout << u << ' ';cout << '\n';
    if(*a.begin()*d < c){
        cout <<"Impossible\n";return;
    }
    ll s = 0;
    for(int i=0; i<min(n,d); i++)s+=a[i];
    if(c<=s){
        cout << "Infinity\n";return;
    }
    auto ok = [&](ll mid){
        ll sum = 0;
        ll front=0;
        for(int i=0; i<d; i++){
            if(front < n) sum += a[front];
            front++;
            if(front > mid){
                front=0;
            }
        }
        return sum >= c;
    };
    ll l=0, r=d, mid, ans=-1;
    while(l<=r){
        mid = l + (r-l)/2;
        if(ok(mid)){
            ans = mid;
            l = mid+1;
        }else{
            r = mid-1;
        }
    }
    if(ans==-1){
        cout << "Impossible\n";return;
    }
    cout << ans << '\n';
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