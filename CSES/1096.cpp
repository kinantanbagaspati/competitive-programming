#include <bits/stdc++.h>
using namespace std;

long long mod = 1000000007;
long long pangkat(long long a, long long b){
    long long res = 1;
    b %= (mod-1);
    while(b>0){
        if(b%2){res = res*a%mod;}
        a = a*a%mod; b /= 2;
    }
    return res;
}
long long inv(long long a){
    return pangkat(a, mod-2);
}

vector<long long> al[101];
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
        al[u].push_back(v);
        precomp[0][u][v] += 1;
    }
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n >> m >> k;
    init(n, m);
    for(int nn=1; nn<30; nn++){
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                precomp[nn][i][j] = 0;
                for(int mm=1; mm<=n; mm++){
                    precomp[nn][i][j] += precomp[nn-1][i][mm]*precomp[nn-1][mm][j];
                    precomp[nn][i][j] %= mod;
                }
            }
        }
    }
    long long ans[n+1][n+1], cpy[n+1][n+1], idx=0;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){ans[i][j] = (i==j);}
    }
    while(k>0){
        if(k%2){
            for(int i=1; i<=n; i++){
                for(int j=1; j<=n; j++){
                    cpy[i][j] = 0;
                    for(int mm=1; mm<=n; mm++){
                        cpy[i][j] += ans[i][mm]*precomp[idx][mm][j];
                        cpy[i][j] %= mod;
                    }
                }
            }
            for(int i=1; i<=n; i++){
                for(int j=1; j<=n; j++){ans[i][j] = cpy[i][j];}
            }
        }
        k /= 2;
        idx++;
    }
    cout << ans[1][n] << endl;
}
