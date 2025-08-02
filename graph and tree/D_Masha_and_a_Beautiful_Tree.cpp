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

int solve(const vi& v, int n, int cnt, int ans){
    if(v.size() == 1)return ans;
    vi u;
    for(int i=0; i<n; i+=2){
        if(v[i] > v[i+1]){
            if(v[i]-v[i+1] != cnt)return -1;
            else {
                ans++;
                u.push_back(v[i]);       
            }
        }else if(v[i+1]-v[i] != cnt)return -1;
        else u.push_back(v[i+1]);
    }
    return solve(u, u.size(), cnt*2, ans);
}
int main() {
    optimize();
    int t;
    cin >> t;
    for(ll cs = 1; cs <= t; cs++){
        int n;
        cin >> n;
        vi v(n);
        for(int i=0; i<n; i++){
            cin >> v[i];
        }
        cout << solve(v, n, 1, 0)<<'\n';
    }
    return 0;
}