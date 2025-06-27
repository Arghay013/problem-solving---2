#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define yes cout << "YES" << endl
#define no cout << "NO" << endl

const int N = 1e7 + 9;

bool is_prime[N];
vector<int> primes;

void sieve() {
    fill(is_prime, is_prime + N, true);
    is_prime[0] = is_prime[1] = false;

    for (int i = 2; i < N; i++) {
        if (is_prime[i]) {
            primes.push_back(i);
            for (int j = i * 2; j < N; j += i) {
                is_prime[j] = false;
            }
        }
    }
}

ll co(ll n) {
    ll count = 0;
    
    for (ll i = 0; ; i++) {
        if(primes[i] > n)break;
        // cout << "n/p -> "<<n/primes[i] << '\n';
        count += int(n/primes[i]);
    }
    
    return count;
}

int main() {
    sieve();
    
    ll t;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;
        cout << co(n) << endl;
    }

    return 0;
}
