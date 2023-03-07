#include<bits/stdc++.h>
using namespace std;
#define pll pair<long long, long long>

const long long mod = 1e9+7, nxm = 1<<21, maxn = 262144;
long long dp[nxm], t, n, m, a[maxn];
long long children[maxn][2];
set<pll> kanan;
pll toSort[maxn], par;
long long batas[maxn][2], node, sum[2];

void ngitung(long long now){
    if(children[now][0] >= 0){
        ngitung(children[now][0]);
    }
    if(children[now][1] >= 0){
        ngitung(children[now][1]);
    }

    if(children[now][0] < 0){
        if(children[now][1] < 0){ // leaf
            for(int i=0; i<m; i++){
                dp[now*m + i] = 1;
            }
        }else{
            sum[1] = 0;
            for(int i=0; i<m; i++){
                sum[1] += dp[children[now][1] * m + i];
                sum[1] %= mod;
                dp[now*m+i] = sum[1];
            }
        }
    }else{
        if(children[now][1] < 0){ // leaf
            sum[0] = 0;
            dp[now*m] = 0;
            for(int i=1; i<m; i++){
                sum[0] += dp[children[now][0] * m + i-1];
                sum[0] %= mod;
                dp[now*m+i] = sum[0];
            }
        }else{
            dp[now*m] = 0;
            sum[0] = 0;
            sum[1] = dp[children[now][1] * m];
            for(int i=1; i<m; i++){
                sum[0] += dp[children[now][0] * m + i-1];
                sum[0] %= mod;
                sum[1] += dp[children[now][1] * m + i];
                sum[1] %= mod;
                dp[now*m+i] = sum[0] * sum[1] % mod;
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--){
        cin >> n >> m;
        for(int i=0; i<n; i++){
            cin >> a[i];
            toSort[i].first = -a[i];
            toSort[i].second = i;
            children[i][0] = -1;
            children[i][1] = -1;
        }

        sort(toSort, toSort+n);
        kanan.clear();
        kanan.insert({n, toSort[0].second});
        batas[toSort[0].second][0] = 0;
        batas[toSort[0].second][1] = n;

        for(int i=1; i<n; i++){
            node = toSort[i].second;
            par = *(kanan.lower_bound({node, 0}));

            if(node < par.second){
                children[par.second][0] = node;
                batas[node][0] = batas[par.second][0];
                batas[node][1] = par.second;
                if(batas[par.second][1] == par.second){
                    kanan.erase(par);
                }else{
                    batas[par.second][0] = par.second+1;
                }
                kanan.insert({batas[node][1], node});
            }else{
                children[par.second][1] = node;
                batas[node][0] = par.second+1;
                batas[node][1] = batas[par.second][1];
                if(batas[par.second][0] == par.second+1){
                    kanan.erase(par);
                    kanan.insert({batas[node][1], node});
                }else{
                    batas[par.second][1] = par.second;
                    kanan.erase(par);
                    kanan.insert({par.second, par.second});
                }
                kanan.insert({batas[node][1], node});
            }
        }

        /*
        for(int i=0; i<n; i++){
            cout << i << ": " << children[i][0] << " " << children[i][1] << endl;
        }
        */
        ngitung(toSort[0].second);
        long long ans = 0;
        for(int i=0; i<m; i++){
            ans = (ans + dp[toSort[0].second * m + i]) % mod;
        }
        cout << ans << endl;
        //cout << dp[toSort[0].second][m] << endl;
    }
}
