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

const ll M = 1e18 + 7;
const int N = 1e5 + 7;
const int MOD = 1e9 + 7;
 
vector<int> adj[N];
int dp[N] = {1};
 
void dfs(int node, int par) {
    for(auto it: adj[node]) {
        if(it==par) continue;
 
        dfs(it,node);
        dp[node]+=dp[it];
    }
    
}
 
void solve(){
    int n;
    cin >> n;
    for(int i = 0; i < n-1; i++) {
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
 
    if(n&1) {
        cout << -1 << endl;
        return;
    }
 
    // for(int i=1; i<n; i++) cout << i << " : " << dp[i] << endl;
    for(int i=1; i<=n; i++) {
        dp[i]++;
    }
    dfs(1,-1);

    int ans = 0;
    for(int i=1; i<=n; i++) {
        if(dp[i]%2==0) ans++;
 
        // cout << i << " : " << dp[i] << endl;
    }
 
    cout << ans-1 << endl;
    
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