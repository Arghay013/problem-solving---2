#include <bits/stdc++.h>
using namespace std;
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
const int N = 1e6 + 5;
vector<bool> is_prime(N, true);
vector<int> primes;

void sieve(int n = N) {
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i * i <= n; ++i) {
        if (is_prime[i]) {
            for (int j = i + i; j <= n; j += i)
                is_prime[j] = false;
        }
    }
    for (int i = 2; i <= n; ++i) {
        if (is_prime[i]) primes.push_back(i);
    }
}
int main() {
    optimize();
    sieve();
    // for(auto u:primes)cout << u << '\n';
    int n;
    cin >> n;
    map<int, int> cnt;
    int idx=0;
    while(n>1){
        while(true){
            if(n%primes[idx] != 0)break;
            cnt[primes[idx]]++;
            n/=primes[idx];
        }
        idx++;
    }
    for(auto u:cnt)cout << u.first << " -> " << u.second << '\n';
    return 0;
}