#include<bits/stdc++.h>
using namespace std;
#define pll pair<long long, long long>

const int maxn = 1024, maxm = 1024;
const long long mod = 998244353, inv2 = (mod+1)/2;
int n, a[maxn], maxchild[maxn], nbm;
vector<int> child[maxn], factors[maxn], al[maxn];
long long dp[maxn][2][maxm];

void sieve(){
    nbm = 0;
    for(int i=2; i<maxn; i++){
        if(factors[i].size() == 0){ // i prima
            for(int j=i; j<maxn; j+=i){
                factors[j].push_back(nbm);
            }
            nbm++;
        }
    }
    /*
    for(int i=0; i<20; i++){
        cout << i << ":";
        for(int j=0; j<factors[i].size(); j++){
            cout << " " << factors[i][j];
        }cout << endl;
    }
    */
}

void initTree(){
    cin >> n;
    int u, v;
    for(int i=1; i<=n; i++){
        cin >> a[i];
    }
    for(int i=1; i<n; i++){
        cin >> u >> v;
        al[u].push_back(v);
        al[v].push_back(u);
    }
}
int dfsTree(int par, int node){
    int to, maxdp = 0, curdp, res = 0;
    for(int i=0; i<al[node].size(); i++){
        to = al[node][i];
        if(par != to){
            child[node].push_back(to);
            curdp = dfsTree(node, to);
            res += curdp;
            if(curdp > maxdp){
                maxdp = curdp;
                maxchild[node] = to;
            }
        }
    }
    return res;
}

long long ans = 0, cur;
void dfsNgitung(int node, bool nambah){
    // ngitung par
    for(int i=0; i<factors[a[node]].size(); i++){
        dp[node][0][factors[a[node]][i]]++;
    }
    for(int i=0; i<child[node].size(); i++){
        int to = child[node][i];
        dfsNgitung(to, false);
        for(int j=0; j<maxm; j++){
            dp[node][0][j] += dp[to][0][j];
            dp[node][1][j] = (dp[node][1][j] + dp[to][0][j] + dp[to][1][j]) % mod;
        }
    }
    cout << "kelar ngitung " << node << endl;
    for(int i=0; i<5; i++){
        cout << i << ": " << dp[node][0][i] << dp[node][1][i] << endl;
    }
    for(int i=0; i<child[node].size(); i++){
        int to = child[node][i];
        for(int j=0; j<maxm; j++){
            cur = (dp[node][0][j] + mod - dp[to][0][j]) % mod;
            cur = (cur * (cur-1) / 2) % mod;
            cur = cur * (dp[to][0][j] + dp[to][1][j]) % mod;
            ans = (ans + cur) % mod;

            cur = (dp[to][1][j] + dp[to][0][j] * inv2) % mod;
            cur = cur * (dp[node][0][j] + mod - dp[to][0][j]) % mod;
            ans = (ans + cur) % mod;
        }
    }
    cout << "ans: " << ans << endl << endl;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    sieve();
    initTree();
    int dummy = dfsTree(0, 1);
    // tes maxchild
    for(int i=1; i<=n; i++){
        cout << maxchild[i] << " ";
    }cout << endl;

    dfsNgitung(1, false);
    cout << ans << endl;
}
