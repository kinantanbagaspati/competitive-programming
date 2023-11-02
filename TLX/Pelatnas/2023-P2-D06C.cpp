#include <bits/stdc++.h>
using namespace std;

const int maxn = 131072;
int n, m, q, edges[maxn][2];
// dsu
int card[maxn], par[maxn];
void init(){
    for(int i=1; i<=n; i++){
        card[i] = 1; par[i] = i;
    }
}
int getPar(int node){
    while(par[node] != node){
        int nxt = par[node];
        par[node] = par[nxt];
        node = nxt;
    }
    return node;
}
void join(int a, int b){
    a = getPar(a);
    b = getPar(b);
    if(a == b){return;}
    if(card[a] < card[b]){
        par[a] = b;
        card[b] += card[a];
    }else{
        par[b] = a;
        card[a] += card[b];
    }
}

// paralel binser
pair<pair<int, int>, int> ranges[maxn];
int xyz[maxn][3], ans[maxn];

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    // input
    cin >> n >> m;
    for(int i=1; i<=m; i++){
        cin >> edges[i][0] >> edges[i][1];
    }
    cin >> q;
    for(int i=0; i<q; i++){
        cin >> xyz[i][0] >> xyz[i][1] >> xyz[i][2];
        ranges[i] = {{0, n}, i};
    }

    // paralel binser
    for(int i=0; i<18; i++){
        init();
        int idx = 0;
        // cout << ranges[idx].first.first << ":" << ranges[idx].first.second << endl;
        for(int j=0; j<=m; j++){
            if(j){
                join(edges[j][0], edges[j][1]);
            }
            while(idx <= q && (ranges[idx].first.first + ranges[idx].first.second)/2 == j){
                //cout << "(j=" << j << ") ";
                //cout << ranges[idx].second << ": " << getPar(getPar(xyz[ranges[idx].second][0])) << "," << getPar(xyz[ranges[idx].second][1]);
                //cout << "-" << card[getPar(xyz[ranges[idx].second][0])] << "," << card[getPar(xyz[ranges[idx].second][1])] << endl;
                int par0 = getPar(xyz[ranges[idx].second][0]), par1 = getPar(xyz[ranges[idx].second][1]);
                if(par0 == par1){
                    if(card[par0] >= xyz[ranges[idx].second][2]){
                        ranges[idx].first.second = j;
                    }else{
                        ranges[idx].first.first = j;
                    }    
                }else if(card[getPar(xyz[ranges[idx].second][0])] + card[getPar(xyz[ranges[idx].second][1])] >= xyz[ranges[idx].second][2]){
                    ranges[idx].first.second = j;
                }else{
                    ranges[idx].first.first = j;
                }
                idx++;
            }
        }
        sort(ranges, ranges+q);
    }

    // jawab
    for(int i=0; i<q; i++){
        ans[ranges[i].second] = ranges[i].first.second;
    }
    for(int i=0; i<q; i++){
        cout << ans[i] << endl;
    }
}