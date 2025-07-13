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
    int n;
    cin >> n;
    int a[n];
    int maxi=0;
    for(int i=0; i<n; i++){
        cin >> a[i];
        // maxi = max(maxi, a[i]);
    }
    for(int i=1; i<n; i++){
        maxi = max(maxi,a[i]);
    }
    int fc = maxi-a[0];
    int mn = INT_MAX;
    for(int i=0; i<n-1; i++){
        mn = min(a[i], mn);
    }
    int lc = a[n-1] - mn;
    int pa=0;
    for(int i=0; i<n-1; i++){
        if(a[i] - a[i+1] > pa){
            pa = a[i] - a[i+1];
        }
    }
    cout << max({pa,fc, lc}) << '\n';

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