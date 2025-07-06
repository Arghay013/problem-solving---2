#include <bits/stdc++.h>
using namespace std;
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
int main() {
    optimize();
    int n;
    cin >> n;
    vector<pair<int, int>> times;
    while(n--){
        int a,b;
        cin >> a >> b;
        times.push_back({a,1});
        times.push_back({b,-1});
    }
    sort(times.begin(), times.end());
    int sum=0,ans=0;
    for(auto u:times){
        sum += u.second;
        ans = max(sum,ans);
    }
    cout << ans << '\n';
    return 0;
}