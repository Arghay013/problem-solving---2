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

ll sum(ll mid, ll k, ll p){
    ll l = (mid*(mid+1)/2) - (k*(k-1)/2);
    ll r = (p*(p+1)/2) - (mid*(mid+1)/2);
    return l-r;
}
 
void solve(){
    ll n,k;
    cin >> n >> k;
 
    ll lo=k, hi=k+n-1, ans;
    while(lo<=hi){
        ll mid = lo+(hi-lo)/2;
        if(sum(mid,k,k+n-1)<0) lo=mid+1;
        else hi=mid-1;
    }
    
    ans = min(abs(sum(lo,k,k+n-1)), abs(sum(hi,k,k+n-1)));
    cout << ans << endl;
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