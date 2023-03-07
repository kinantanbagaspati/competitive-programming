#include <bits/stdc++.h>
using namespace std;

vector<long long> al[100069];
long long team[100069];

void init(long long n, long long m){
    long long u, v;
    for(int i=1; i<=n; i++){
        team[i] = -1;
    }
    while(m--){
        cin >> u >> v;
        al[u].push_back(v);
        al[v].push_back(u);
    }
}

bool dfs(long long node, bool is1){
    team[node] = is1;
    bool ret = true;
    for(int i=0; i<al[node].size(); i++){
        if(team[al[node][i]]<0){
            ret = ret && dfs(al[node][i], !is1);
        }else if(team[al[node][i]] == is1){
            return false;
        }
    }
    return ret;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    long long n, m;
    cin >> n >> m;
    init(n,m);

    bool done = true;
    for(int i=1; done && i<=n; i++){
        if(team[i]<0){
            done = dfs(i, true);
        }
    }

    if(done){
        for(int i=1; i<=n; i++){
            cout << team[i]+1 <<  " ";
        }cout << endl;
    }else{
        cout << "IMPOSSIBLE" << endl;
    }
}
