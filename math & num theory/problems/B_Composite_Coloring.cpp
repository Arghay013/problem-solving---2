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
int primes[11] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31};
void solve(){
    int n;
    cin >> n;
    int a[n];
    for(int i=0; i<n; i++)cin >> a[i];
    map<int, vector<int> > mp;
    for(int i=0; i<n; i++){
        for(int j=0; j<11; j++){
            if(a[i]%primes[j] == 0){
                mp[j].push_back(i);
                break;
            }
        }
    }
    cout << mp.size()<< '\n';
    int colour = 1;
    int ans[n];
    for(auto u:mp){
        // cout << u.first<<" -> ";
        for(auto v:u.second){
            ans[v] = colour;
        }
        colour++;
    }
    for(auto u : ans)cout << u << ' ';
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