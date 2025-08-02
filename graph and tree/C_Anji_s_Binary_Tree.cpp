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
const int maxN = 3e5+123;
vector<int> g[maxN];
vector<int> ans(maxN);
string s;

void dfs(int u){
    int v;
    if(g[u][0] != 0){
        v = g[u][0];
        if(s[u-1] != 'L'){
            ans[v] = ans[u]+1;
        }else if(s[u-1] == 'L'){
            ans[v] = ans[u];
        }
        dfs(v);
    }

    if(g[u][1] != 0){
        v = g[u][1];
        if(s[u-1] != 'R'){
            ans[v] = ans[u]+1;
        }else if(s[u-1] == 'R'){
            ans[v] =ans[u];
        }
        dfs(v);
    }
}

void solve(){
    int n;
    cin >> n;
    cin >> s;
    for(int i=1; i<=n; i++){
        int l,r;
        cin >> l >> r;
        g[i].push_back(l);
        g[i].push_back(r);
    }
    dfs(1);
    int res = INT_MAX;
    for(int i=1; i<=n; i++){
        if(g[i][0] == 0 && g[i][1] == 0){
            res = min(res,ans[i]);
        }
    }
    cout << res << '\n';
    for(int i=0; i<=n; i++)g[i].clear();
    for(int i=0; i<=n; i++)ans[i]=0;
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