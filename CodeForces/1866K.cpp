#include<bits/stdc++.h>
using namespace std;
#define pii pair<int, int>
#define fi first
#define se second

const int maxn = 131072;
long long n, q, depth[maxn], farthest[maxn][4]; // id turun 1, turun 1, turun 2, naik
vector<long long> al[maxn], weight[maxn];

void dfsDown(long long node, long long par){
    depth[node] = depth[par] + 1;
    
}

void dfsUp(){
    
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n;
    for(int i=1; i<n; i++){
        long long u, v, w;
        cin >> u >> v >> w;
        al[u].push_back(v); weight[u].push_back(w);
        al[v].push_back(u); weight[v].push_back(w);
    }

}
