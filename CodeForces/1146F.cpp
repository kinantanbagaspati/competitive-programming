#include<bits/stdc++.h>
using namespace std;

const long long mod = 998244353, maxn = 262144;
long long n, par[maxn], dp[maxn][3];
vector<long long> child[maxn];

long long pangkat(long long a, long long b){
    a %= mod; b %= (mod-1);
    long long ret = 1;
    while(b>0){
        if(b%2){
            ret = ret*a%mod;   
        }
        a = a*a%mod; b/=2;
    }
    return ret;
}
long long inverse(long long a){
    return pangkat(a, mod-2);
}

void dfs(long long node){
    if(child[node].size() == 0){
        dp[node][0] = 1;
        dp[node][1] = 1;
        dp[node][2] = 2;
        return;    
    }
    dp[node][0] = 1;
    dp[node][1] = 0;
    dp[node][2] = 1;
    for(int i=0; i<child[node].size(); i++){
        int to = child[node][i];
        dfs(to);
        dp[node][0] = dp[node][0] * (dp[to][2] + mod - dp[to][1]) % mod;
        dp[node][1] = ((dp[to][2] + mod - dp[to][0]) * inverse(dp[to][2] + mod - dp[to][1]) + dp[node][1]) % mod;
        dp[node][2] = (dp[to][2]*2 + mod*2 - dp[to][0] - dp[to][1]) % mod * dp[node][2] % mod;
        //cout << node << "-" << to << ": " << dp[node][0] << " " << dp[node][1] << " " << dp[node][2] << endl;
    }
    dp[node][1] = dp[node][0] * dp[node][1] % mod;
    //cout << node << ": " << dp[node][0] << " " << dp[node][1] << " " << dp[node][2] << endl;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n;
    for(int i=2; i<=n; i++){
        cin >> par[i]; child[par[i]].push_back(i);
    }
    dfs(1);
    cout << (dp[1][2] + mod - dp[1][1]) % mod << endl;
}

