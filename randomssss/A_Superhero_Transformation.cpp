#include <bits/stdc++.h>
using namespace std;
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

int main() {
    optimize();
    string s, t;
    cin >> s >> t;

    if (s.size() != t.size()) {
        cout << "No\n";
        return 0;
    }

    set<char> v = {'a', 'e', 'i', 'o', 'u'};

    for (int i = 0; i < s.size(); i++) {
        bool vs = (v.count(s[i]) > 0);
        bool vt = (v.count(t[i]) > 0);

        if (vs != vt) { 
            cout << "No\n";
            return 0;
        }
    }

    cout << "Yes\n";
    return 0;
}
