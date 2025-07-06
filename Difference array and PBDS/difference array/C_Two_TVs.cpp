#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
int main() {
    optimize();
    ll n;
    cin >> n;
    map<int, int> mp;
    for(int i=0; i<n; i++){
        int l,r;
        cin >> l >> r;
        mp[l] += 1;
        mp[r+1] -= 1;
    }
    ll sum=0;
    for(auto u:mp){
        sum += u.second;
        if(sum > 2){
            cout << "NO\n";
            return 0;
        }
    }
    cout << "YES\n";
    return 0;
}