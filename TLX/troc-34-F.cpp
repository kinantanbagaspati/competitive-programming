#include <bits/stdc++.h>
using namespace std;
 
const long long maxn = 1048576, mod = 1e9+7;
long long n, k, ans = 0, cur;
long long fac[maxn], invfac[maxn]; 

long long pangkat(long long a, long long b) {
    a %= mod;
    b %= mod - 1;
    long long res = 1;
    while (b > 0) {
        if (b % 2) {
            res = res * a % mod;
        }
        a = a * a % mod;
        b /= 2;
    }
    return res;
}
long long choose(long long a, long long b) {
    if (a < b) {
        return 0;
    }
    return fac[a] * invfac[b] % mod * invfac[a - b] % mod;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    fac[0] = 1;
    invfac[0] = 1;
    for (long long i = 1; i < maxn * 2; i++) {
        fac[i] = fac[i - 1] * i % mod;
        invfac[i] = invfac[i - 1] * pangkat(i, mod - 2) % mod;
    }

    cin >> n >> k; ans = 0;
    // ga ketambah
    ans += n * (n-1) % mod * fac[n-2] % mod * choose(n-2, k) % mod;
    ans += n * (n-1) * (n-2) / 3 % mod * (n-2) % mod * fac[n-3] % mod * choose(n-3, k) % mod;

    // sekali ketambah
    ans += n * (n-1) * 2 % mod * fac[n-2] % mod * choose(n-2, k-1) % mod;
    ans += mod - n 
    ans += n * (n-2) * (n-3) % mod * (n-2) % mod * fac[n-3] % mod * choose(n-3, k-1) % mod;
    ans 

    // dua kali ketambah
    ans += n * (n-1) * 2 % mod * fac[n-2] % mod * choose(n-2, k-1) % mod;
    ans += n * (n-2) * (n-3) % mod * (n-2) % mod * fac[n-3] % mod * choose(n-3, k-2) % mod;

    // 3 kali ketambah
    ans += n * (n-2) * (n-3) / 3 % mod * (n-2) % mod * fac[n-3] % mod * choose(n-3, k-3) % mod;

    cout << ans % mod << endl;
}