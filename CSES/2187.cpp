#include <bits/stdc++.h>
using namespace std;

const long long maxn = (1<<20), mod = 1e9+7;
long long n, m=0;
long long fac[maxn * 2], invfac[maxn * 2];
string s;

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
    if (a < b || b < 0) {
        return 0;
    }
    return fac[a] * invfac[b] % mod * invfac[a - b] % mod;
}

long long datalan(long long cols, long long rows, long diag){
    return (choose(cols + rows, rows) - choose(cols + rows, diag-1) + mod) % mod;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    // Ngitung fac
    fac[0] = 1; invfac[0] = 1;
    for(int i=1; i<maxn; i++){
        fac[i] = fac[i-1] * i % mod;
        invfac[i] = invfac[i-1] * pangkat(i, mod-2) % mod;
    }

    cin >> n >> s;
    if(n%2){
        cout << 0 << endl; return 0;
    }
    n -= s.length();
    for(int i=0; i<s.length(); i++){
        if(s[i] == '('){
            m++;
        }else{
            m--;
        }
        if(m < 0){
            cout << 0 << endl; return 0;
        }   
    }
    cout << datalan((n+m)/2, (n-m)/2, (n-m)/2) << endl;
}
