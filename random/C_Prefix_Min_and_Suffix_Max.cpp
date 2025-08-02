#include<bits/stdc++.h>
using namespace std;
#define ll  long long
#define pb  push_back
#define all(x) (x).begin(), (x).end()
#define  gcd(a,b)  __gcd(a,b)
#define    lcm(a,b)  (a*b)/__gcd(a,b)
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

void solve(){
    ll n; cin>>n;
    vector<ll>v(n),mn(n),mx(n);
    ll a=1e18, b=0;
    for(ll i=0; i<n; i++){
        cin>>v[i];
        a=min(a,v[i]);
        mn[i]=a;
    }
    for(ll i=n-1; i>=0; i--){
        b=max(b,v[i]);
        mx[i]=b;
    }
    string ans="";
    for(ll i=0; i<n; i++){
        if(v[i]==mn[i] || v[i]==mx[i]) ans+='1';
        else ans+='0';
    }
    cout<<ans<<endl;
}

signed main()
{
    optimize();
    ll t=1;
    cin>>t;
    while(t--) solve();
    return 0;
}