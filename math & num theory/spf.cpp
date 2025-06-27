#include <bits/stdc++.h>
using namespace std;
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
int main() {
    optimize();
    int n;
    cin >> n;
    map<int, int> cnt;
    for(int i=2; i*i <= n; i++){
        if(n%i == 0){
            while(n%i == 0){
                cnt[i]++;
                n/=i;
            }
        }
    }
    if(n>1){
        cnt[n]++;
    }
    for(auto u:cnt){
        cout << u.first << " -> " << u.second << '\n';
    }
    
    return 0;
}