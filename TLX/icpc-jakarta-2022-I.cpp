#include<bits/stdc++.h>
using namespace std;

const int maxn = 131072;
int n, a, b, c, akiri, kiri, kanan, akanan;
int edge[maxn][2], ans[maxn][2];
vector<int> al[maxn], id[maxn];

void dfs(int node, int par, int anc){
    for(int i=0; i<al[node].size(); i++){
        int to = al[node][i];
        if(to != par){
            dfs(to, node, anc);
            if(node == kiri){
                akiri = to; a = id[node][i];
            }else if(node == kanan){
                akanan = to; c = id[node][i];
            }
        }else{
            ans[id[node][i]][0] = node;
            ans[id[node][i]][1] = anc;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n;
    for(int i=1; i<n; i++){
        cin >> edge[i][0] >> edge[i][1];
        al[edge[i][0]].push_back(edge[i][1]);
        al[edge[i][1]].push_back(edge[i][0]);
        id[edge[i][0]].push_back(i); id[edge[i][1]].push_back(i);
    }
    for(int i=1; i<n; i++){
        if(al[edge[i][0]].size() > 1 && al[edge[i][1]].size() > 1){
            b = i;
        }
    }
    if(b == 0){
        cout << -1 << endl; return 0;
    }
    kiri = edge[b][0]; kanan = edge[b][1];
    dfs(kiri, kanan, kanan);
    dfs(kanan, kiri, kiri);
    if(min({a, b, c}) == a){
        ans[a][0] = akiri; ans[a][1] = akanan;
        ans[b][0] = kiri; ans[b][1] = akanan;
        ans[c][0] = akiri; ans[c][1] = kanan;
    }else if(min({a, b, c}) == c){
        ans[c][0] = akiri; ans[c][1] = akanan;
        ans[b][0] = akiri; ans[b][1] = kanan;
        ans[a][0] = kiri; ans[a][1] = akanan;
    }else{
        ans[a][0] = kiri; ans[a][1] = akanan;
        ans[b][0] = akiri; ans[b][1] = akanan;
        ans[c][0] = akiri; ans[c][1] = kanan;
    }
    
    for(int i=1; i<n; i++){
        cout << ans[i][0] << ' ' << ans[i][1] << endl;
    }
}