#include <bits/stdc++.h>
using namespace std;

const long long maxn = 200069;
long long n, q;
long long parent[maxn], val[maxn], nbdesc[maxn], depth[maxn], maxchild[maxn];
bool vis[maxn];
vector<long long> al[maxn], children[maxn];

void init(){
    cin >> n >> q;
    for(int i=1; i<=n; i++){
        cin >> val[i];
        vis[i] = false;
    }
    long long u, v;
    for(int i=1; i<n; i++){
        cin >> u >> v;
        al[u].push_back(v);
        al[v].push_back(u);
    }
}
void dfstree(long long node){
    vis[node] = true;
    depth[node] = depth[parent[node]] + 1;
    nbdesc[node] = 1;
    maxchild[node] = 0;
    long long maxval = 0;
    for(int i=0; i<al[node].size(); i++){
        long long ex = al[node][i];
        if(!vis[ex]){
            children[node].push_back(ex);
            parent[ex] = node;
            dfstree(ex);
            nbdesc[node] += nbdesc[ex];
            if(nbdesc[ex] > maxval){
                maxchild[node] = ex;
                maxval = nbdesc[ex];
            }
        }
    }
}

void printtree(){
    for(int i=1; i<=n; i++){
        cout << i << " " << depth[i] << " " << nbdesc[i] << endl;
        for(int j=0; j<children[i].size(); j++){
            cout << children[i][j] << " ";
        }cout << endl;
    }
}

long long hldpar[maxn], segtreesize[maxn];
long long hldid[maxn], hldord[maxn], curid = 0;
vector<long long> hldnodes[maxn], segtrees[maxn];

void dfshld(long long node){
    hldid[node] = curid;
    hldord[node] = hldnodes[curid].size();
    hldnodes[curid].push_back(node);
    if(nbdesc[node] == 1){return;}
    dfshld(maxchild[node]);
    for(int i=0; i<children[node].size(); i++){
        long long ex = children[node][i];
        if(ex != maxchild[node]){
            curid++;
            hldpar[curid] = node;
            dfshld(ex);
        }
    }
}
void printhld(){
    for(int i=0; i<=curid; i++){
        for(int j=0; j<hldnodes[i].size(); j++){
            cout << hldnodes[i][j] << " ";
        }cout << endl;
    }
    for(int i=1; i<=n; i++){
        cout << i << ": " << hldid[i] << " " << hldord[i] << endl;
    }
}

void build(){
    for(int i=0; i<=curid; i++){
        segtreesize[i] = 1;
        while(segtreesize[i] <= hldnodes[i].size()){segtreesize[i] *= 2;}
        for(int j=0; j< 2*segtreesize[i]; j++){
            segtrees[i].push_back(0);
        }
    }
}
void update(long long id, long long ord, long long v){
    ord += segtreesize[id];
    segtrees[id][ord] = v;
    ord /= 2;
    while(ord>0){
        segtrees[id][ord] = max(segtrees[id][2*ord], segtrees[id][2*ord+1]);
        ord /= 2;
    }
}
long long query(long long id, long long lo, long long hi){
    long long ret = 0;
    lo += segtreesize[id];
    hi += segtreesize[id];
    while(lo <= hi){
        if(lo%2){
            ret = max(segtrees[id][lo], ret);
        }lo = (lo+1)/2;
        if(!(hi%2)){
            ret = max(segtrees[id][hi], ret);
        }hi = (hi-1)/2;
    }
    return ret;
}

long long solve(long long node0, long long node1){
    long long ret = 0;
    while(hldid[node0] != hldid[node1]){
        long long p0 = hldpar[hldid[node0]];
        long long p1 = hldpar[hldid[node1]];
        if(depth[p0] < depth[p1]){
            ret = max(query(hldid[node1], 0, hldord[node1]), ret);
            node1 = p1;
        }else{
            ret = max(query(hldid[node0], 0, hldord[node0]), ret);
            node0 = p0;
        }
    }
    long long lo = min(hldord[node0], hldord[node1]);
    long long hi = max(hldord[node0], hldord[node1]);
    ret = max(query(hldid[node0], lo, hi), ret);
    return ret;
}

vector<long long> ans;
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    init();
    parent[1] = 0;
    depth[0] = -1;
    dfstree(1);
    //printtree();
    hldpar[0] = 0;
    dfshld(1);
    //printhld();
    build();
    for(int i=1; i<=n; i++){
        update(hldid[i], hldord[i], val[i]);
    }
    //cout << "halo" << endl;
    long long a, b, c;
    while(q--){
        cin >> a >> b >> c;
        if(a == 1){
            update(hldid[b], hldord[b], c);
        }else{
            ans.push_back(solve(b, c));
        }
    }
    for(int i=0; i<ans.size(); i++){
        cout << ans[i] << " ";
    }cout << endl;
}
