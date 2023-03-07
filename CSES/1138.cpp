#include <bits/stdc++.h>
using namespace std;

const int maxn = (1 << 18);
vector<long long> al[200069];
long long p[200069][20], depth[200069];
long long prefix_tree[2*maxn], range_subtree[200069][2];


long long weight[200069];
void init(long long n){
    for(int i=1; i<=n; i++){
        cin >> weight[i];
    }
    long long u, v;
    for(int i=1; i<n; i++){
        cin >> u >> v;
        al[u].push_back(v);
        al[v].push_back(u);
    }
    for(int i=1; i<2*maxn; i++){
        prefix_tree[i] = 0;
    }
}

void update(long long node, long long addval){
    node += maxn;
    while(node>0){
        prefix_tree[node] += addval; node/=2;
    }
}

long long query(long long left, long long right){
    left += maxn; right += maxn;
    long long res = 0;
    while(left<=right){
        if(left%2){res += prefix_tree[left];}
        left = (left+1)/2;
        if(right%2==0){res += prefix_tree[right];}
        right = (right-1)/2;
    }
    return res;
}

long long gidx = 0;
void dfs(long long node){
    long long c;
    range_subtree[node][0] = gidx;
    gidx++;
    for(int i=0; i<al[node].size(); i++){
        c = al[node][i];
        if(c!=p[node][0]){
            p[c][0] = node;
            depth[c] = depth[node]+1;
            dfs(c);
        }
    }
    range_subtree[node][1] = gidx-1;
}
void lca(long long n){
    for(int j=1; j<20; j++){
        for(int i=0; i<=n; i++){
            p[i][j] = p[p[i][j-1]][j-1];
        }
    }
}

void dis(long long a, long long b){
    update(range_subtree[a][0], 1);
    update(range_subtree[b][0], 1);

    long long c, idx;
    c = depth[a]-depth[b]; idx = 0;
    while(c>0){
        if(c%2){a = p[a][idx];}
        c/=2; idx++;
    }
    c = depth[b]-depth[a]; idx=0;
    while(c>0){
        if(c%2){b = p[b][idx];}
        c/=2; idx++;
    }
    while(a!=b){
        idx=1;
        while(p[a][idx] != p[b][idx]){idx++;}
        a = p[a][idx-1]; b = p[b][idx-1];
    }
    update(range_subtree[a][0], -1);
    update(range_subtree[p[a][0]][0], -1);
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    long long n, q;
    cin >> n >> q;
    init(n);
    p[0][0] = 0;
    p[1][0] = 0;
    depth[0] = 0;

    range_subtree[0][0] = gidx;
    gidx++;
    dfs(1);
    range_subtree[0][1] = gidx;

    lca(n);
    for(int i=1; i<=n; i++){
        update(range_subtree[i][0], weight[i]);
        update(range_subtree[i][1]+1, -weight[i]);
    }
    long long type, s, x;
    while(q--){
        cin >> type;
        if(type==1){
            cin >> s >> x;
            update(range_subtree[s][0], x - weight[s]);
            update(range_subtree[s][1]+1, - x + weight[s]);
            weight[s] = x;
        }else{
            cin >> s;
            cout << query(0, range_subtree[s][0]) << endl;
        }
    }
}
