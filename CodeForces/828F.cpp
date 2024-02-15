#include<bits/stdc++.h>
using namespace std;
#define pii pair<int, int>
#define fi first
#define se second

const int maxn = 262144;
int n, m, edges[maxn][3], ans[maxn];
pair<pii, pii> toSort[maxn];
// buat MST
int card[maxn], par[maxn];
bool kepake[maxn];
vector<int> al[maxn], e[maxn];
void initDSU(){
    for(int i=1; i<=n; i++){
        card[i] = 1; par[i] = i;
    }
}
int getAncestor(int x){
    while(x != par[x]){
        int nxt = par[x];
        par[x] = par[par[x]];
        x = nxt;
    }
    return x;
}
void joinAncestor(int a, int b){
    if(card[a] < card[b]){
        par[a] = b; card[b] += card[a];
    }else{
        par[b] = a; card[a] += card[b];
    }
}

// buat HLD
int depth[maxn], subtree[maxn], maxchild[maxn], nodeEdge[maxn];
void dfsTree(int node, int par){
    depth[node] = depth[par] + 1;
    subtree[node] = 1;
    for(int i=0; i<al[node].size(); i++){
        int to = al[node][i];
        if(to != par){
            nodeEdge[to] = e[node][i];
            dfsTree(to, node);
            subtree[node] += subtree[to];
            if(subtree[to] > subtree[maxchild[node]]){
                maxchild[node] = to;
            }
        }
    }
}
void printTree(){
    cout << "printTree" << endl;
    for(int i=1; i<=n; i++){
        cout << i << ": " << depth[i] << " " << subtree[i] << " " << maxchild[i] << endl;
    }
    cout << endl;
}
int ordNode[maxn], nodeChain[maxn], curOrd = 0, curChain = 0;
int nodeRange[maxn][2], chainRange[maxn][2], chainPar[maxn];
void dfsHLD(int node, int par){
    ordNode[curOrd] = node;
    nodeRange[node][0] = curOrd;
    nodeChain[node] = curChain;
    if(maxchild[node] != 0){ // nonleaf
        curOrd++;
        dfsHLD(maxchild[node], node);
        for(int i=0; i<al[node].size(); i++){
            int to = al[node][i];
            if(to != par && to != maxchild[node]){
                curOrd++; curChain++;
                chainPar[curChain] = node;
                chainRange[curChain][0] = curOrd;
                dfsHLD(to, node);
            }
        }
    }else{ // leaf
        chainRange[curChain][1] = curOrd;
    }
    nodeRange[node][1] = curOrd;
}
void printHLD(){
    cout << "ada " << curOrd << " node:";
    for(int i=0; i<curOrd; i++){
        cout << ordNode[i] << ' ';
    }cout << endl;
    cout << "nodeInfo: ";
    for(int i=1; i<=n; i++){
        cout << nodeChain[i] << '(' << nodeRange[i][0] << '-' << nodeRange[i][1] << ") ";
    }cout << endl;
    cout << "chains: ";
    for(int i=0; i<curChain; i++){
        cout << chainPar[i] << '(' << chainRange[i][0] << '-' << chainRange[i][1] << ") ";
    } cout << endl;
}

vector<pii> paths, rangeSort;
multiset<int> weights;
void pathHLD(int x, int y){
    //cout << "cari " << x << "->" << y << endl;
    paths.clear();
    while(nodeChain[x] != nodeChain[y]){
        if(depth[chainPar[nodeChain[x]]] > depth[chainPar[nodeChain[y]]]){
            paths.push_back({chainRange[nodeChain[x]][0], nodeRange[x][0]});
            x = chainPar[nodeChain[x]];
        }else{
            paths.push_back({chainRange[nodeChain[y]][0], nodeRange[y][0]});
            y = chainPar[nodeChain[y]];
        }
        //cout << "cari " << x << "->" << y << endl;
    }
    if(min(nodeRange[x][0], nodeRange[y][0]) < max(nodeRange[x][0], nodeRange[y][0])){
        paths.push_back({min(nodeRange[x][0], nodeRange[y][0])+1, max(nodeRange[x][0], nodeRange[y][0])});
    }
    //cout << "jadi ada " << paths.size() << " ranges" << endl;
}

// buat yg flatten
int segtree[maxn*2];
void buildTree(){
    //cout << "buildTree" << endl;
    for(int i=0; i<n; i++){
        segtree[maxn + i] = edges[nodeEdge[ordNode[i]]][2];
        //cout << i << ": " << ordNode[i] << " beratnya " << segtree[maxn + i] << endl;
    }
    for(int i=maxn-1; i>0; i--){
        segtree[i] = max(segtree[i*2], segtree[i*2+1]);
    }
}
int queryTree(int lo, int hi){
    lo += maxn; hi += maxn;
    int res = 0;
    while(lo <= hi){
        if(lo%2 == 1){
            res = max(segtree[lo], res);
        } lo = (lo+1)/2;
        if(hi%2 == 0){
            res = max(segtree[hi], res);
        } hi = (hi-1)/2;
    }
    //cout << "balik " << res << ", ";
    return res;
}


int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n >> m;
    for(int i=0; i<m; i++){
        cin >> edges[i][0] >> edges[i][1] >> edges[i][2];
        toSort[i].fi = {edges[i][2], i};
        toSort[i].se = {edges[i][0], edges[i][1]};
    }
    // DSU Stuff
    initDSU();
    sort(toSort, toSort + m);
    for(int i=0; i<m; i++){
        //cout << "cek " << toSort[i].se.fi << ' ' << toSort[i].se.se << endl;
        int a = getAncestor(toSort[i].se.fi), b = getAncestor(toSort[i].se.se);
        if(a != b){
            kepake[toSort[i].fi.se] = true;
            //cout << "kepake " << toSort[i].fi.se << ": " << toSort[i].se.fi << " " << toSort[i].se.se << " " << toSort[i].fi.fi << endl;
            joinAncestor(a, b);
            al[toSort[i].se.fi].push_back(toSort[i].se.se);
            al[toSort[i].se.se].push_back(toSort[i].se.fi);
            e[toSort[i].se.fi].push_back(toSort[i].fi.se);
            e[toSort[i].se.se].push_back(toSort[i].fi.se);
        }
    }
    // Construct HLD
    dfsTree(1, 0);
    //printTree();
    dfsHLD(1, 0);
    //printHLD();
    buildTree();

    // Jawabin yg bukan MST
    for(int i=0; i<m; i++){
        if(!kepake[i]){
            pathHLD(edges[i][0], edges[i][1]);
            ans[i] = 0;
            for(int j=0; j<paths.size(); j++){
                //cout << paths[j].fi << "-" << paths[j].se << ", ";
                ans[i] = max(queryTree(paths[j].fi, paths[j].se)-1, ans[i]);
                rangeSort.push_back({paths[j].fi, -edges[i][2]});
                rangeSort.push_back({paths[j].se, edges[i][2]});
            }
            //cout << endl;
        }
    }
    //cout << "kelar nonMST" << endl;

    // Jawabin yg MST
    sort(rangeSort.begin(), rangeSort.end());
    /*for(int i=0; i<rangeSort.size(); i++){
        cout << "(" << rangeSort[i].fi << "," << rangeSort[i].se << ") ";
    } cout << endl;*/
    int idx = 0;
    for(int i=1; i<n; i++){
        while(idx < rangeSort.size() && rangeSort[idx].fi == i && rangeSort[idx].se < 0){
            weights.insert(-rangeSort[idx].se); idx++;
        }
        if(weights.empty()){
            ans[nodeEdge[ordNode[i]]] = -1;
        }else{
            ans[nodeEdge[ordNode[i]]] = *(weights.begin())-1;
        }
        while(idx < rangeSort.size() && rangeSort[idx].fi == i){
            weights.erase(weights.lower_bound(rangeSort[idx].se)); idx++;
        }
    }

    for(int i=0; i<m; i++){
        cout << ans[i] << ' ';
    }cout << endl;
}
