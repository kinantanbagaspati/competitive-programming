#include<bits/stdc++.h>
using namespace std;
#define pll pair<long long, long long>

const long long maxn = 300069, mod = 998244353, inv2 = (mod+1)/2;

long long pangkat(long long a, long long b){
    long long res = 1;
    while(b>0){
        if(b%2){res = res*a%mod;}
        a = a*a%mod; b /= 2;
    }
    return res;
}
long long inv(long long a){
    return pangkat(a, mod-2);
}

long long n, k, invkc2, a, u, v, ans = 0;
long long val[maxn], delta, prob, subval[maxn];
vector<long long> al[maxn];
long long edges[maxn][2], depth[maxn];

void dfs(int par, int node){
    depth[node] = depth[par] + 1;
    subval[node] = val[node];
    for(int i=0; i<al[node].size(); i++){
        int to = al[node][i];
        if(to != par){
            dfs(node, to);
            subval[node] += subval[to];
        }
    }
    //cout << "subval " << node << ": " << subval[node] << endl;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n >> k;
    //cout << "invkc2 " << invkc2 << endl;
    for(int i=0; i<k; i++){
        cin >> a; val[a]++;
    }
    for(int i=1; i<n; i++){
        cin >> u >> v;
        al[u].push_back(v);
        al[v].push_back(u);
        edges[i][0] = u; edges[i][1] = v;
    }
    dfs(0, 1);
    ans = 0;
    for(int i=1; i<n; i++){
        u = edges[i][0]; v = edges[i][1];
        if(depth[u] > depth[v]){
            a = u; u = v; v = a;
        }
        // u parent dari v
        ans = (subval[v] * (k-subval[v]) + ans) % mod;
        // dari u ke v
        delta = (subval[v]+1) * (k-subval[v]-1) - subval[v] * (k-subval[v]);
        delta = (delta % mod + mod) % mod;
        prob = val[u] * (mod+1-val[v]) % mod * inv2 % mod;
        ans = (delta * prob + ans) % mod;
        // dari v ke u
        delta = (subval[v]-1) * (k-subval[v]+1) - subval[v] * (k-subval[v]);
        delta = (delta % mod + mod) % mod;
        prob = val[v] * (mod+1-val[u]) % mod * inv2 % mod;
        ans = (delta * prob + ans) % mod;

        // update val
        prob = (1-val[u]) * val[v] - val[u] * (1-val[v]);
        prob = (prob % mod + mod) * inv2 % mod;
        val[u] = (val[u] + prob) % mod;
        val[v] = (val[v] + mod - prob) % mod;
    }

    invkc2 = (k * (k-1) / 2) % mod;
    invkc2 = inv(invkc2);
    cout << ans * invkc2 % mod << endl;
}
