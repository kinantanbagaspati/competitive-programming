#include <bits/stdc++.h>
using namespace std;
#define pll pair<long long, long long>

const long long maxn = 131072;

long long n, k;
vector<long long> al[maxn];
long long dp[maxn], krg = 0;

void init(){
    cin >> n >> k;
    dp[n] = 0;
    long long u, v, w;
    for(int i=1; i<n; i++){
        cin >> u >> v >> w;
        al[u].push_back(v);
        al[v].push_back(u);
        dp[i] = 0;
    }
    while(k--){
        cin >> w;
        dp[w]++;
    }
}

void dfs(long long node, long long par){
    bool spec = (dp[node] > 0);
    long long anakpos = 0;
    for(int i=0; i<al[node].size(); i++){
        long long to = al[node][i];
        if(par != to){
            dfs(to, node);
            anakpos += (dp[to] > 0);
            dp[node] += dp[to];
        }
    }
    if(!spec){
        if(anakpos == 1){
            dp[node]++; krg++;
        }else if(anakpos > 1){
            dp[node]++; krg = 0;
        }
        // do nothing
    }else{
        krg = 0;
    }
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    init();
    dfs(1, 0);
    cout << dp[1] - krg << endl;
}
