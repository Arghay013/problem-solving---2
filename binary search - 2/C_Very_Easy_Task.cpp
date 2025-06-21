#include <bits/stdc++.h>
using namespace std;
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
int main() {
    optimize();
    int n, x, y;
    cin >> n >> x >> y;
    int l=0,r = n*(min(x,y));
    auto ok = [&](int time){
        if(time < min(x,y))return false;
        time -= (min(x,y));
        int first = time/x;
        int second = time/y;
        return first+second+1 >= n;
    };
    int ans;
    while(l<=r){
        int mid = l + (r-l)/2;
        if(ok(mid)){
            ans = mid;
            r = mid-1;
        }else{
            l = mid+1;
        }
    }
    cout << ans << '\n';
    return 0;
}