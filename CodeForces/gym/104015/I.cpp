#include <bits/stdc++.h>
using namespace std;
#define pll pair<long long, long long>

const long long maxn = 262144;
long long n, u, v, pecah = 0;
vector<long long> al[maxn];
bool ans[maxn];

long long dfs(long long node, long long par){
    long long res = 1;
    for(int i=0; i<al[node].size(); i++){
        if(al[node][i] != par){
            res += dfs(al[node][i], node);
        }
    }
    if(2*res == n){
        pecah = node;
    }
    return res;
}

long long dfs2(long long node, long long par){
    if(node == pecah){
        ans[node] = true;
    }
    for(int i=0; i<al[node].size(); i++){
        long long to = al[node][i];
        if(to != par){
            ans[to] = ans[node];
            dfs2(to, node);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin >> n;
    for(int i=1; i<n; i++){
        cin >> u >> v;
        al[u].push_back(v);
        al[v].push_back(u);
    }
    dfs(1, 0);
    if(pecah > 0){
        cout << "YES" << endl;
        dfs2(1, 0);
        for(int i=1; i<=n; i++){
            cout << ans[i] << ' ';
        }
        cout << endl;
    }else{
        cout << "NO" << endl;
    }
}

/*
1->2: 0 1
2->3: 0 1
3->4: 1 0
4->5: 1 0
*/
