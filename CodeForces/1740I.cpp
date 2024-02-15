#include<bits/stdc++.h>
using namespace std;
#define pll pair<long long, long long>

const long long maxn = 1048576;
long long n, m, k, a[maxn], b[maxn];
long long g, h;
long long dp[2][maxn], dxs[maxn];
multiset<long long> ms;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n >> m >> k;
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    g = __gcd(n, k);
    // pindahin semua ke crystal 0-(g-1)
    for(int i=0; i<g; i++){
        for(int j=i+k; j!=i; j=(j+k)%n){
            b[j] -= a[j];
            b[(j+1)%n] += a[j];
            a[(j+k)%n] = (a[(j+k)%n] + a[j]) % m;
            a[j] = 0;
        }
    }
    /*for(int i=0; i<n; i++){
        cout << b[i] << ' ';
    } cout << endl;*/

    // crystal 0-(g-1) harus sama semua
    for(int i=0; i<g; i++){
        if(a[i] != a[0]){
            cout << -1 << endl; return 0;
        }
    }
    // bagi dari g ke k
    for(int i=0; i<k && a[0]%(k/g) > 0; i++){
        a[0] += m;
    }
    if(a[0] % (k/g) > 0){
        cout << -1 << endl; return 0;
    }
    long long tinggal = a[0] / (k/g);
    for(int i=0; i<g; i++){
        long long sisa = a[0];
        for(int j=i; sisa>0; j=(j+k)%n){
            if(j<k){sisa -= tinggal;}
            b[j] -= sisa;
            b[(j+1)%n] += sisa;
        }
    }
    b[0] -= tinggal;
    for(int i=0; i<n; i++){
        b[i] = (b[i] % m + m) % m;
        //cout << b[i] << ' ';
    } //cout << endl;

    for(int i=1; i<m; i++){
        dp[0][i] = 1e18;
    }
    for(int i=0; i<g; i++){
        // reset
        for(int j=0; j<m; j++){
            dxs[j] = 0;
            dp[(i+1)%2][j] = 1e18;
        }
        // itung dxs
        for(int j=i; j<n; j+=g){
            for(int o=0; o<m; o++){
                dxs[o] += min({abs(b[j] - o), abs(b[j] - o - m), abs(b[j] - o + m)});
            }
        }
        /*for(int j=0; j<m; j++){
            cout << dxs[j] << ' ';
        }cout << endl;*/
        long long offset = 0;
        for(int j=1; j<m; j++){
            if(j == m-1 || dxs[j]-dxs[j-1] != dxs[j+1]-dxs[j]){
                long long gradien = dxs[j]-dxs[j-1], panjang = j-offset;
                //cout << "line " << offset << ' ' << panjang << " - " << dxs[offset] << ' ' << gradien << endl;
                // isi ms
                ms.clear();
                for(int o=-panjang; o<m; o++){
                    ms.insert(dp[i%2][(m+o)%m] + dxs[offset] - o*gradien);
                    dp[(i+1)%2][(o+offset)%m] = min(dp[(i+1)%2][(o+offset)%m], *(ms.begin()) + o*gradien);
                    if(o>=0){
                        long long hapus = dp[i%2][(m+o-panjang)%m] + dxs[offset] - (o-panjang)*gradien;
                        ms.erase(ms.lower_bound(hapus));
                    } 
                }
                offset = j;
            }
        }
        /*for(int j=0; j<m; j++){
            cout << dp[(i+1)%2][j] << ' ';
        }cout << endl;*/
    }
    long long ans = 1e18;
    h = m / __gcd(m, k/g);
    for(int i=0; i<m; i+=h){
        ans = min(dp[g%2][i], ans);
    }
    cout << ans << endl;
}

//0 1 2 3 4 5 6 7 8
//4 4 3 2 1 0 1 2 3