#include <bits/stdc++.h>
using namespace std;

long long mod = 1000000007;
long long n, m, k;
long long precomp[30][101][101];

void init(long long n, long long m){
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            precomp[0][i][j] = 0;
        }
    }
    long long u, v;
    while(m--){
        cin >> u >> v;
        precomp[0][u][v] += 1;
    }
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n >> m >> k;
    init(n, m);
    long long cur;
    for(int nn=1; nn<30; nn++){
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                cur = 0;
                for(int mm=1; mm<=n; mm++){
                    cur += precomp[nn-1][i][mm]*precomp[nn-1][mm][j];
                    if(cur > 75 * 1e17){cur %= mod;}
                }
                precomp[nn][i][j] = cur%mod;
            }
        }
    }
    long long ans[n+1], cpy[n+1], idx=0;
    ans[1] = 1;
    for(int i=2; i<=n; i++){ans[i] = 0;}
    while(k>0){
        if(k%2){
            for(int i=1; i<=n; i++){
                cpy[i] = 0;
                for(int mm=1; mm<=n; mm++){
                    cpy[i] += ans[mm] * precomp[idx][mm][i];
                    cpy[i] %= mod;
                }

            }
            for(int i=1; i<=n; i++){ans[i] = cpy[i];}
        }
        k /= 2;
        idx++;
    }
    cout << ans[n] << endl;
}
