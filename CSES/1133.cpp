#include <bits/stdc++.h>
using namespace std;

vector<long long> al[200069], anak[200069];
long long dp[2000069], ans[2000069], n;

void init(){
    long long a, b;
    for(int i=1; i<n; i++){
        cin >> a >> b;
        al[a].push_back(b);
        al[b].push_back(a);
    }
}

long long caldp(long long node, long long parent){
    long long ret = 1;
    ans[node] = 0;
    for(int i=0; i<al[node].size(); i++){
        if(al[node][i] != parent){
            anak[node].push_back(al[node][i]);
            ret += caldp(al[node][i], node);
            ans[node] += ans[al[node][i]];
            ans[node] += dp[al[node][i]];
        }
    }
    dp[node] = ret;
    return ret;
}

void calans(long long node, long long par){
    ans[node] = ans[par] - dp[node] + n - dp[node];
    for(int i=0; i<anak[node].size(); i++){
        calans(anak[node][i], node);
    }
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n;
    init();
    caldp(1, 0);
    for(int i=0; i<anak[1].size(); i++){
        calans(anak[1][i], 1);
    }
    for(int i=1; i<=n; i++){
        cout << ans[i] << " ";
    }cout << endl;
}
