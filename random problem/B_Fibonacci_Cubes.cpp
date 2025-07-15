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
    int n,m;
    cin >> n >> m;
    int tmp=m;
    vector<pair<int, int>> v;
    while(tmp--){
        int x,y,z;
        cin >> x >> y >> z;
        int p = max({x,y,z});
        int q = min({x,y,z});
        v.push_back(make_pair(p,q));
    }
    int fib[12] ={
        0, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89,144
    };
    int c=0;
    for(auto u:v){
        int mini = u.second;
        int maxi = u.first;
        if(mini>=fib[n] && maxi >= fib[n+1]){
            cout << "1";
        }else{
            cout << "0";
        }
    }
    cout << '\n';
    

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