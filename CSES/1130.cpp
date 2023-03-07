#include <bits/stdc++.h>
using namespace std;

vector<long long> al[200069], anak[200069];
long long dp[2000069];

void init(long long n){
    dp[n] = -1;
    long long a, b;
    for(int i=1; i<n; i++){
        cin >> a >> b;
        al[a].push_back(b);
        al[b].push_back(a);
        dp[i] = -1;
    }
}

void dfs(long long node, long long parent){
    for(int i=0; i<al[node].size(); i++){
        if(al[node][i] != parent){
            anak[node].push_back(al[node][i]);
            dfs(al[node][i], node);
        }
    }
}

long long getdp(long long node){
    if(dp[node]>=0){//visited
        return dp[node];
    }
    if(anak[node].size()==0){
        return 0;
    }
    long long ret = 0;
    long long ad = 0;
    for(int i=0; i<anak[node].size(); i++){
        long long expand = anak[node][i];
        ret += getdp(expand);
        long long cur = 1;
        for(int j=0; j<anak[expand].size(); j++){
            cur += getdp(anak[expand][j]);
        }
        ad = max(ad, cur-getdp(expand));
    }
    dp[node] = ret + ad;
    return ret + ad;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    long long n;
    cin >> n;
    init(n);
    dfs(1, 0);
    cout << getdp(1) << endl;
}
