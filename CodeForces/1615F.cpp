#include<bits/stdc++.h>
using namespace std;
#define pii pair<int, int>

const long long maxn = 2024, mod = 1e9+7;
long long fac[maxn * 2], invfac[maxn * 2];
long long t, n, ans;
long long afix[2][maxn], apot[2][maxn], bfix[2][maxn], bpot[2][maxn];
char c;
string atas, bawah;

long long pangkat(long long a, long long b) {
    a %= mod; b %= mod - 1;
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

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    // Ngitung fac
    fac[0] = 1; invfac[0] = 1;
    for(int i=1; i<maxn; i++){
        fac[i] = fac[i-1] * i % mod;
        invfac[i] = invfac[i-1] * pangkat(i, mod-2) % mod;
    }

    cin >> t;
    while(t--){
        cin >> n >> atas >> bawah;
        for(int i=0; i<n; i++){
            if(i%2){
                c = atas[i]; atas[i] = bawah[i]; bawah[i] = c;
            }
        }
        //cout << "ab " << atas << ' ' << bawah << endl;

        afix[1][n-1] = 0; apot[1][n-1] = 0;
        bfix[1][n-1] = 0; bpot[1][n-1] = 0;
        for(int i=1; i<n; i++){
            // ke kanan
            afix[0][i] = afix[0][i-1] + (atas[i-1] == '1');
            apot[0][i] = apot[0][i-1] + (atas[i-1] == '?');
            bfix[0][i] = bfix[0][i-1] + (bawah[i-1] == '1');
            bpot[0][i] = bpot[0][i-1] + (bawah[i-1] == '?');
            // ke kiri
            afix[1][n-1-i] = afix[1][n-i] + (atas[n-i] == '1');
            apot[1][n-1-i] = apot[1][n-i] + (atas[n-i] == '?');
            bfix[1][n-1-i] = bfix[1][n-i] + (bawah[n-i] == '1');
            bpot[1][n-1-i] = bpot[1][n-i] + (bawah[n-i] == '?');
        }
        ans = 0;
        for(long long i=0; i<n; i++){
            for(long long j=0; j<n; j++){
                if(atas[i] != '0' && bawah[j] != '0'){ // bisa nambahin ke ans
                    //cout << "masuk " << i << ' ' << j << endl;
                    //cout << '(' << apot[0][i] + bpot[0][j] << ' ' << bpot[0][j] + bfix[0][j] - afix[0][i] << ") (";
                    //cout << apot[1][i] + bpot[1][j] << ' ' << bpot[1][j] + bfix[1][j] - afix[1][i] << ')' << endl;
                    //cout << "jb " << j << ' ' << bfix[1][j] << endl;
                    ans = (
                        choose(apot[0][i] + bpot[0][j], bpot[0][j] + bfix[0][j] - afix[0][i])
                        * choose(apot[1][i] + bpot[1][j], bpot[1][j] + bfix[1][j] - afix[1][i])
                        % mod * abs(i-j) + ans) % mod;
                }
            }
        }
        cout << ans << endl;
    }
    
}
