#include <bits/stdc++.h>
using namespace std;
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
int main() {
    optimize();
    int n;
    cin >> n;
    if(n==2){
        cout << 1 << '\n' << 2 << '\n';return 0;
    }else if(n==3){
        cout << 1 << '\n' << 3 << '\n';return 0;
    }
    cout << n/2 << '\n';
    if(n&1){
        int x = n/2;
        cout << 3 << ' ';
        x-=1;
        while(x>0){
            cout << 2 << ' ';
            x--;
        }
    }else{
        int y = n/2;
        while(y > 0){
            cout << 2 << ' ';
            y--;
        }
    }
    return 0;
}