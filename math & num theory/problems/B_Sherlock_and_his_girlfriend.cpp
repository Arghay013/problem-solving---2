#include <bits/stdc++.h>
using namespace std;
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
const int N = 1e6 + 5;
vector<bool> is_prime(N, true);
int main() {
    optimize();
    int n;
    cin >> n;
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i * i <= N; ++i) {
        if (is_prime[i]) {
            for (int j = 2 * i; j <= N; j += i)
                is_prime[j] = false;
        }
    }
    if(n>2)
		cout<<"2\n";
	else
		cout<<"1\n";
    for(int i=2; i<=n+1; i++){
        if(is_prime[i]){
            cout << "1 ";
        }else{
            cout<<"2 ";
        }
    }
    return 0;
}