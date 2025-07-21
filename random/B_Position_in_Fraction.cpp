#include <bits/stdc++.h>
using namespace std;
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
int main() {
    optimize();
    double a,b,c;
    cin >> a >> b >> c;
    double x = a/b;
    string s = to_string(x);
    cout << s << '\n';
    return 0;
}