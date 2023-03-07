#include <bits/stdc++.h>
using namespace std;

const long long maxn = 100069, mod = 1e9+7;
long long n, m;
long long in[maxn], dp[maxn];
queue<long long> q;
vector<long long> al[maxn];

void init(){
    cin >> n >> m;
    dp[1] = 1;
    long long u, v;
    while(m--){
        cin >> u >> v;
        al[u].push_back(v);
        in[v]++;
    }
}

void dpdag(){
    for(int i=1; i<=n; i++){
        if(in[i] == 0){
            q.push(i);
        }
    }
    while(!(q.empty())){
        long long h = q.front(); q.pop();
        for(int i=0; i<al[h].size(); i++){
            long long x = al[h][i];
            dp[x] = (dp[x] + dp[h]) % mod;
            in[x]--;
            if(in[x] == 0){
                q.push(x);
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    init();
    dpdag();
    cout << dp[n] << endl;
}
