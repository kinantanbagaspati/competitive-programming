#include <bits/stdc++.h>

using namespace std;
#define pii pair<int, int>

const long long mod = 1e9+7;
long long t, n, curpow, ans, mul;
long long ongoings, ongoing, toAdd, toDec;
long long nb3, nb3add;

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin >> t;
    for(int tt=1; tt<=t; tt++){
        cout << "Case " << tt << ": ";
        cin >> n; ans = 0;
        if(n < 7){
            cout << 0 << endl; continue;
        }
        curpow = 7; ans = 0;
        while(curpow * 7 <= n){
            curpow *= 7;
        }
        //cout << "curpow " << curpow << endl;
        ongoings = 0; nb3 = 0;
        while(curpow > 1){
            mul = curpow % mod;
            mul = mul * (mul-1) / 2 % mod;
            ongoing = n / curpow % mod;
            //cout << "mul, ongoing: " << mul << " " << ongoing << endl;

            toAdd = ongoing * (ongoing+1) / 2 % mod;

            //cout << "nb3 sebelum: " << nb3 << endl;
            nb3add = nb3 * 21 % mod;
            ans = (ans + nb3add * mul) % mod;
            nb3add = (nb3add + toAdd * (ongoings+1)) % mod;
            nb3 = (7*nb3 + nb3add) % mod;
            //cout << "nb3 sesudah: " << nb3 << endl;

            toAdd = toAdd * mul % mod;
            toDec = (curpow-1 - n%curpow) % mod;
            toDec = toDec * (toDec-1) / 2 % mod;
            toDec = toDec * ongoing % mod;
            //cout << "add, dec: " << toAdd << " " << toDec << endl;
            toAdd = (toAdd + mod - toDec) % mod;

            ans += (ongoings+1) * toAdd;
            ans %= mod;
            ongoings += (ongoings+1) * ongoing;
            ongoings %= mod;
            //cout << "ans, ongoings: " << ans << " " << ongoings << endl;
            n %= curpow;
            curpow /= 7;
            //cout << "n, curpow: " << n << " " << curpow << endl;
        }
        cout << ans << endl;
    }
}
