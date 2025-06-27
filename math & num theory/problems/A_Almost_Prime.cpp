#include <bits/stdc++.h>
using namespace std;
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
int main() {
    optimize();
    int n;
    cin >> n;
    vector<int> ans;
    for(int x=1; x<=n; x++){
        int digit = x;
        map<int, int> cnt;
        for(int i=2; i*i <= digit; i++){
            if(digit%i == 0){
                while(digit%i == 0){
                    cnt[i]++;
                    digit/=i;
                }
            }
        }
        if(digit>1){
            cnt[digit]++;
        }
        if(cnt.size()==2)ans.push_back(x);
    }


    cout << ans.size() << '\n';
    
    return 0;
}