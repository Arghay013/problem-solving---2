#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
int main() {
    optimize();
    int n,k;
    cin >> n >> k;
    ll a[k];
    for(int i=0; i<k; i++)cin >> a[i];
    // for(int i=0; i<n; i++)cout << a[i] << ' ';
    auto ok = [&](ll member){
        ll sum = 0;
        for(int i=0; i<k; i++)sum+=min(member,a[i]);
        return sum >= (member*n);
    };
    ll l=0,r=1e17,ans=0;
    while(l<=r){
        ll mid = l + (r-l)/2;
        if(ok(mid)){
            ans = mid;
            l = mid + 1;
        }else{
            r = mid-1;
        }
    }
    cout << ans << '\n';
    return 0;
}