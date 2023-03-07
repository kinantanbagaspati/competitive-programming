#include <bits/stdc++.h>
using namespace std;

// buat input
const int maxn = 524288;
int n, edges[maxn][3]; // awal, akhir, berat
vector<int> adjl[maxn];

void init(){ // input
    cin >> n;
    for(int i=1; i<n; i++){
        cin >> edges[i][0] >> edges[i][1] >> edges[i][2];
        adjl[edges[i][0]].push_back(i);
        adjl[edges[i][1]].push_back(i);
    }
}

// buat bikin pohon
int depth[maxn], subtree[maxn], maxchild[maxn];
vector<int> children[maxn];
bool isNodeOdd[maxn];

void dfsTree(int par, int node){
    depth[node] = depth[par]+1;
    subtree[node] = 1;
    maxchild[node] = -1;
    for(int i=0; i<adjl[node].size(); i++){
        // cari to
        int to = adjl[node][i];
        bool v = (edges[to][2]%2);
        if(edges[to][0] == node){
            to = edges[to][1];
        }else{
            to = edges[to][0];
        }
        if(to != par){ // to itu anak
            children[node].push_back(to);
            isNodeOdd[to] = v;
            dfsTree(node, to);
            subtree[node] += subtree[to];
            if(maxchild[node] < 0 || subtree[maxchild[node]] < subtree[to]){
                maxchild[node] = to;
            }
        }
    }
}
void printTree(){
    for(int i=1; i<=n; i++){
        cout << "node, val: " << i << " " << isNodeOdd[i] <<endl;
        cout << "depth, subtree, maxchild: " << depth[i] << " " << subtree[i] << " " << maxchild[i] << endl;
        cout << "children:";
        for(int j=0; j<children[i].size(); j++){
            cout << " " << children[i][j];
        }cout << endl << endl;
    }
}

// buat hld
int hldid[maxn], hldord[maxn]; // dimiliki tiap node
int hldpar[maxn], sizes[maxn], nbhld; // dimiliki tiap segmen
vector<int> hldnodes[maxn];
vector<bool> segtrees[maxn];

void dfsHld(int node){
    hldid[node] = nbhld;
    hldord[node] = hldnodes[nbhld].size();
    hldnodes[nbhld].push_back(node);
    if(children[node].size() == 0){
        return;
    }

    dfsHld(maxchild[node]);
    for(int i=0; i<children[node].size(); i++){
        int to = children[node][i];
        if(to != maxchild[node]){
            nbhld++;
            hldpar[nbhld] = node;
            dfsHld(to);
        }
    }
}
void printHld(){
    for(int i=0; i<=nbhld; i++){
        cout << "hld ke-" << i << " (" << hldpar[i] << "):";
        for(int j=0; j<hldnodes[i].size(); j++){
            cout << " " << hldnodes[i][j];
        }cout << endl;
    }
}
// buat segree
void build(int id){
    sizes[id] = 1;
    while(sizes[id] < hldnodes[id].size()){
        sizes[id] *= 2;
    }
    segtrees[id].resize(sizes[id]*2);
    for(int i=0; i<sizes[id]; i++){
        if(i < hldnodes[id].size()){
            segtrees[id][sizes[id]+i] = isNodeOdd[hldnodes[id][i]];
        }else{
            segtrees[id][sizes[id]+i] = false;
        }
    }
    for(int i=sizes[id]-1; i>0; i--){
        segtrees[id][i] = segtrees[id][2*i] ^ segtrees[id][2*i+1];
    }
}
void buildHld(){
    nbhld = 0;
    hldpar[nbhld] = 0;
    dfsHld(1);
    //printHld();
    for(int i=0; i<=nbhld; i++){
        build(i);
    }
}
void update(int node, bool baru){
    int id = hldid[node], ord = hldord[node] + sizes[id];
    isNodeOdd[node] = baru;
    segtrees[id][ord] = baru; ord /= 2;
    while(ord > 0){
        segtrees[id][ord] = segtrees[id][2*ord] ^ segtrees[id][2*ord+1];
        ord /= 2;
    }
}
bool query(int id, int lo, int hi){
    lo += sizes[id]; hi += sizes[id];
    bool ret = false;
    while(lo <= hi){
        if(lo%2){
            ret ^= segtrees[id][lo];
        } lo = (lo+1)/2;
        if(hi%2 == 0){
            ret ^= segtrees[id][hi];
        } hi = (hi-1)/2;
    }
    return ret;
}

// buat query
bool queryRoot(int node){
    bool ret = false;
    while(node > 0){
        ret ^= query(hldid[node], 0, hldord[node]);
        node = hldpar[hldid[node]];
    }
    return ret;
}

int qs, type, riot, target;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    init();
    dfsTree(0, 1);
    //printTree();

    buildHld();

    cin >> qs;
    while(qs--){
        cin >> type >> riot >> target;
        if(type == 1){
            if(queryRoot(riot) ^ queryRoot(target)){
                cout << "WE NEED BLACK PANDA\n";
            }else{
                cout << "JAKANDA FOREVER\n";
            }
        }else{
            edges[riot][2] = target;
            int maxId = (depth[edges[riot][0]] < depth[edges[riot][1]]);
            update(edges[riot][maxId], target%2);
        }
    }
}
