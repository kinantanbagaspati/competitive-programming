#include <bits/stdc++.h>
using namespace std;

const int maxn = 65536;
int n, u, v, w, q;
char c;
vector<int> al[maxn];
int depth[maxn], subtree[maxn], maxchild[maxn], parent[maxn];
void dfsTree(int node, int par){
    subtree[node] = 1;
    maxchild[node] = -1;
    parent[node] = par;
    for(int i=0; i<al[node].size(); i++){
        int to = al[node][i];
        if(to != par){
            depth[to] = depth[node] + 1;
            dfsTree(to, node);
            if(maxchild[node] < 0 || subtree[maxchild[node]] < subtree[to]){
                maxchild[node] = to;
            }
            subtree[node] += subtree[to];
        }
    }
}

int ordNode[maxn], nodeChain[maxn], chainPar[maxn], curOrd, curChain;
int nodeRange[maxn][2], chainRange[maxn][2];
void dfsHLD(int node, int par){
    ordNode[curOrd] = node;
    nodeChain[node] = curChain;
    nodeRange[node][0] = curOrd;
    if(maxchild[node] < 0){ // leaf node
        chainRange[curChain][1] = curOrd;
    }else{
        curOrd++;
        dfsHLD(maxchild[node], node);
        for(int i=0; i<al[node].size(); i++){
            int to = al[node][i];
            if(to != par && to != maxchild[node]){
                curOrd++; curChain++;
                chainRange[curChain][0] = curOrd;
                chainPar[curChain] = node;
                dfsHLD(to, node);
            }
        }
    }
    nodeRange[node][1] = curOrd;
}
void printHLD(){
    cout << "ordNode:";
    for(int i=0; i<n; i++){
        cout << ' ' << ordNode[i];
    } cout << endl;
    cout << "chains:" << endl;
    for(int i=0; i<=curChain; i++){
        cout << i << ": " << chainRange[i][0] << '-' << chainRange[i][1] << " dari " << chainPar[i] << endl;
    }
}

// segtree
int segtree[maxn*2][2]; //gcd, sum
void buildTree(){
    // input
    for(int i=0; i<n; i++){
        cin >> segtree[nodeRange[i][0] + maxn][0];
    }
    // delta
    for(int i=0; i<=curChain; i++){
        for(int j=chainRange[i][0]+1; j<=chainRange[i][1]; j++){
            segtree[maxn+j][0] -= segtree[maxn+j-1][0];
        }
    }
    for(int i=0; i<n; i++){
        segtree[maxn + i][1] = segtree[maxn + i][0];
    }
    // build
    for(int i=maxn-1; i>0; i--){
        segtree[i][0] = __gcd(segtree[i*2][0], segtree[i*2+1][0]);
        segtree[i][1] = segtree[i*2][1] + segtree[i*2+1][1];
    }
}
void printTree(){
    int lo = maxn, hi = n-1 + maxn;
    cout << "printTree" << endl;
    while(lo < hi){
        for(int i=lo; i<=hi; i++){
            cout << segtree[i][0] << ',' << segtree[i][1] << ' ';
        }cout << endl;
        lo /= 2; hi /= 2;
    }
}
void updateTree(int node, int val){
    node += maxn; 
    segtree[node][0] += val;
    segtree[node][1] += val;
    node /= 2;
    while(node > 0){
        segtree[node][0] = __gcd(segtree[node*2][0], segtree[node*2+1][0]);
        segtree[node][1] = segtree[node*2][1] + segtree[node*2+1][1];
        node /= 2;
    }
}
int queryGCD(int lo, int hi){
    //cout << "queryGCD " << lo << ' ' << hi << endl;
    lo += maxn; hi += maxn;
    int ret = 0;
    while(lo <= hi){
        if(lo % 2 == 1){
            ret = __gcd(segtree[lo][0], ret);
        } lo = (lo+1) / 2;
        if(hi % 2 == 0){
            ret = __gcd(segtree[hi][0], ret);
        } hi = (hi-1) / 2;
    }
    return ret;
}
int querySum(int lo, int hi){
    lo += maxn; hi += maxn;
    int ret = 0;
    while(lo <= hi){
        if(lo % 2 == 1){
            ret += segtree[lo][1];
        } lo = (lo+1) / 2;
        if(hi % 2 == 0){
            ret += segtree[hi][1];
        } hi = (hi-1) / 2;
    }
    return ret;
}

void updateHLD(int a, int b, int val){
    while(nodeChain[a] != nodeChain[b]){
        //cout << "a b " << a << ' ' << b << endl;
        if(nodeChain[a] < nodeChain[b]){
            if(nodeRange[b][0] < nodeRange[b][1]){ // b bukan leaf
                updateTree(nodeRange[b][0] + 1, -val);
            }
            updateTree(chainRange[nodeChain[b]][0], val);
            b = chainPar[nodeChain[b]];
        }else{
            if(nodeRange[a][0] < nodeRange[a][1]){ // a bukan leaf
                updateTree(nodeRange[a][0] + 1, -val);
            }
            updateTree(chainRange[nodeChain[a]][0], val);
            a = chainPar[nodeChain[a]];
        }
    }
    if(depth[b] < depth[a]){
        int c = a; a = b; b = c;
    } // jamin depth[a] < depth[b]
    //cout << "a b " << a << ' ' << b << endl;
    if(nodeRange[b][0] < nodeRange[b][1]){ // b bukan leaf
        updateTree(nodeRange[b][0] + 1, -val);
    }
    updateTree(nodeRange[a][0], val);
}
int queryHLD(int a, int b){
    int ret = 0;
    while(nodeChain[a] != nodeChain[b]){
        //cout << "a b " << a << ' ' << b << endl;
        if(nodeChain[a] < nodeChain[b]){
            ret = __gcd(queryGCD(chainRange[nodeChain[b]][0], nodeRange[b][0]), ret);
            b = chainPar[nodeChain[b]];
        }else{
            ret = __gcd(queryGCD(chainRange[nodeChain[a]][0], nodeRange[a][0]), ret);
            a = chainPar[nodeChain[a]];
        }
    }
    if(depth[b] < depth[a]){
        int c = a; a = b; b = c;
    } // jamin depth[a] < depth[b]
    //cout << "a b " << a << ' ' << b << endl;
    ret = __gcd(queryGCD(nodeRange[a][0] + 1, nodeRange[b][0]), ret);
    return abs(__gcd(querySum(chainRange[nodeChain[a]][0], nodeRange[a][0]), ret));
}

int main(){
    cin >> n;
    for(int i=1; i<n; i++){
        cin >> u >> v;
        al[u].push_back(v);
        al[v].push_back(u);
    }
    dfsTree(0, -1);
    chainPar[0] = -1;
    dfsHLD(0, -1);
    //printHLD();
    buildTree();
    //printTree();

    cin >> q;
    while(q--){
        cin >> c >> u >> v;
        if(c == 'F'){
            cout << queryHLD(u, v) << endl;
        }else{
            cin >> w;
            updateHLD(u, v, w);
            //printTree();
        }
    }
}