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
    int a[n+1];
    int x=0;
    for(int i=1; i<=n; i++)cin >> a[i];
    for(int i=1; i<=n; i++){
        if(a[1]!=a[i]){
            yes;
            x=1;
            break;
        }
    }
    if(x==0){
        no;return;
    }
    for(int i=2; i<=n; i++){
        if(a[1]!=a[i]){
            cout << 1 << ' ' << i << '\n';
            x=i;
        }
    }
    for(int i=2; i<=n; i++){
        if(a[i]==a[1])cout << x << ' ' << i << '\n';
    }
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