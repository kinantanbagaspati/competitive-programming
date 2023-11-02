#include <bits/stdc++.h>
using namespace std;

const long long maxn = 262144;
long long n, q;
bool isB[maxn];
vector<long long> al[maxn];
//preorder purposes
long long depth[maxn], range[maxn][2], curRange = 0;
//binary lifting
long long parent[20][maxn];

void init(){
    for(int i=1; i<=n; i++){
        cin >> isB[i];
        range[i][0] = -1; //vis=false
    }
    long long u, v;
    for(int i=1; i<n; i++){
        cin >> u >> v;
        al[u].push_back(v);
        al[v].push_back(u);
    }
}
void dfs(long long node, long long d){
    range[node][0] = curRange;
    depth[node] = d;
    curRange++;
    for(int i=0; i<al[node].size(); i++){
        long long expand = al[node][i];
        if(range[expand][0]<0){//belom di visit
            parent[0][expand] = node;
            dfs(expand, d+1);
        }
    }
    range[node][1] = curRange-1;
}
void binary_lifting(){
    for(int i=1; i<20; i++){
        for(int j=0; j<=maxn; j++){
            parent[i][j] = parent[i-1][parent[i-1][j]];
        }
    }
}
long long getParent(long long node, long long x){
    for(int i=0; x>0; i++){
        if(x%2){
            node = parent[i][node];
        }
        x/=2;
    }
    return node;
}
bool isAncestor(long long x, long long y){
    return (range[x][0] <= range[y][0]) && (range[x][1] >= range[y][1]);
}

void print_range(){
    for(int i=1; i<=n; i++){
        cout << i << " " << range[i][0] << " " << range[i][1] << endl;
    }
}
void print_bl(long long d){
    for(int i=0; i<d; i++){
        for(int j=0; j<=n; j++){
            cout << parent[i][j] << " ";
        }cout << endl;
    }
}

//segtree purposes: [A, B][nb(X), path(X), sum(nb(X) to root)]
long long segtree[6][2*maxn];
void update(long long id, long long node, long long addval){
    node += maxn;
    while(node>0){
        segtree[id][node] += addval; node/=2;
    }
}
long long query(long long id, long long lo, long long hi){
    lo += maxn; hi += maxn;
    long long res = 0;
    while(lo<=hi){
        if(lo%2){res += segtree[id][lo];}
        lo = (lo+1)/2;
        if(hi%2==0){res += segtree[id][hi];}
        hi = (hi-1)/2;
    }
    return res;
}

/*
HLD
cara pake:
1. isi build, update, sama query segtree hld
2. panggil compute_sez_dfs(), build_chain(), sama build_hld_segtrees()
3. panggil update_hld() sama query_hld() untuk njawab operasi soal
*/

int sez[maxn], chainpos[maxn], chainid[maxn];
vector<vector<int>> chain = {{}};
vector<vector<vector<long long>>> tree; // segtree di dalem hld
vector<vector<vector<long long>>> lazy; // lazy di dalem hld

// panggil untuk ngisi array sez (ukuran subtree tiap node)
void compute_sez_dfs(int u, int p){
    sez[u] = 1;
    for (int v : al[u]){
        if (v == p) continue;
        compute_sez_dfs(v, u);
        sez[u] += sez[v];
    }
}

// panggil untuk bikin chain hld: ngisi chain, chainpos, chainid
void build_chain(int u, int p){
    int sz = chain.size();
    chain[sz-1].push_back(u);
    int heavy = -1, mx = -1;
    for (int v : al[u]){
        if (v == p) continue;
        if (sez[v] > mx){
            mx = sez[v];
            heavy = v;
        }
    }
    if (heavy != -1) build_chain(heavy, u);
    for (int v : al[u]){
        if (v == heavy || v == p) continue;
        chain.push_back({});
        build_chain(v, u);
    }
}
 
// build segtree chain ke-i hld, ganti rekursif kalo mau
// note: current segment itu node chain[i][l] sampe node chain[i][r]
// void build_hld_segtree(int i, int l, int r, int v){
    
// }
 
void build_hld_segtrees(){
    tree.resize(2);
    lazy.resize(2);
    for (int k=0; k<2; k++){
        tree[k].resize(chain.size());
        lazy[k].resize(chain.size());
        for (int i=0; i<(int)chain.size(); i++){
            for (int j=0; j<(int)chain[i].size(); j++){
                chainid[chain[i][j]] = i;
                chainpos[chain[i][j]] = j;
            }
            // panggil fungsi build_hld_segtree ke-i di sini
            tree[k][i].assign(4 * chain[i].size(), 0);
            lazy[k][i].assign(4 * chain[i].size(), 0);
            // build_hld_segtree(i, 0, (int)chain[i].size()-1, 1); // rekursif
        }
    }
}

void push(int k, int i, int l, int r, int v){
    int mid = (l+r)/2;
    tree[k][i][v*2] += lazy[k][i][v] * (mid - l + 1);
    tree[k][i][v*2+1] += lazy[k][i][v] * (r - mid);
    lazy[k][i][v*2] += lazy[k][i][v];
    lazy[k][i][v*2+1] += lazy[k][i][v];
    lazy[k][i][v] = 0;
}

// update segtree chain ke-i hld, ganti rekursif kalo mau
void update_hld_segtree(int k, int i, int l, int r, int v, int lb, int rb, long long val){
    if (r < lb || l > rb) return;
    if (l >= lb && r <= rb) tree[k][i][v] += val * (r-l+1), lazy[k][i][v] += val;
    else{
        push(k, i, l, r, v);
        int mid = (l+r)/2;
        update_hld_segtree(k, i, l, mid, v*2, lb, rb, val);
        update_hld_segtree(k, i, mid+1, r, v*2+1, lb, rb, val);
        tree[k][i][v] = tree[k][i][v*2] + tree[k][i][v*2+1];
    }
}

// query segtree chain ke-i hld, ganti rekursif kalo mau
long long query_hld_segtree(int k, int i, int l, int r, int v, int lb, int rb){
    if (r < lb || l > rb) return 0;
    if (l >= lb && r <= rb) return tree[k][i][v];
    push(k, i, l, r, v);
    int mid = (l+r)/2;
    return query_hld_segtree(k, i, l, mid, v*2, lb, rb) + query_hld_segtree(k, i, mid+1, r, v*2+1, lb, rb);
}

// update path dari root ke node u pake value val
void update_hld(int k, int u, long long val){
    int uchain = chainid[u];
    while (uchain != 0){
        update_hld_segtree(k, uchain, 0, chain[uchain].size()-1, 1, 0, chainpos[u], val);
        u = chain[uchain][0];
        u = parent[0][u];
        uchain = chainid[u];
    }
    update_hld_segtree(k, uchain, 0, chain[uchain].size()-1, 1, 0, chainpos[u], val);
}

// query nilai dari root ke node u
long long query_hld(int k, int u){
    long long ret = 0;
    int uchain = chainid[u];
    while (uchain != 0){
        ret += query_hld_segtree(k, uchain, 0, chain[uchain].size()-1, 1, 0, chainpos[u]);
        u = chain[uchain][0];
        u = parent[0][u];
        uchain = chainid[u];
    }
    ret += query_hld_segtree(k, uchain, 0, chain[uchain].size()-1, 1, 0, chainpos[u]);
    return ret;
}

/* END OF HLD */

long long nb(long long node, bool isA){
    return query(3*(!isA), range[node][0], range[node][1]);
}
long long path(long long node, bool isA){
    return query(3*(!isA) +1, range[node][0], range[node][1]) - depth[node]*nb(node, isA);
}
long long nbs(long long node, bool isA){
    return query_hld(!isA, node);
}
void updateNode(long long node, long long val){
    update(3*isB[node], range[node][0], val);
    update(3*isB[node]+1, range[node][0], val*depth[node]);
    update_hld(isB[node], node, val);
}
void updateNode2(long long node, long long val){
    cout << "update2 ";
    long long save = nb(node, 1);
    cout << save << " ";
    update(2, range[node][0], val*save);
    update(2, range[node][1]+1, -val*save);
    save = nb(node, 0);
    cout << save << endl;
    update(5, range[node][0], val*save);
    update(5, range[node][1]+1, -val*save);
}
void print_prefix(){
    for(int i=0; i<=n; i++){
        cout << segtree[2][maxn+i] << " ";
    }cout << endl;
    for(int i=0; i<=n; i++){
        cout << segtree[5][maxn+i] << " ";
    }cout << endl;
}
void build(){
    //gatau perlu atau engga
    for(int id=0; id<6; id++){
        for(int i=0; i<2*maxn; i++){
            segtree[id][i] = 0;
        }
    }
    for(int node=1; node<=n; node++){
        // cout << node << ' ' << nbs(node, 1) << ' ' << nbs(node, 0) << ' ';
        updateNode(node, 1);
        // cout << nbs(node, 1) << ' ' << nbs(node, 0) << '\n';
        // for (int i=1; i<=n; i++) cout << query_hld_segtree(0, chainid[i], 0, chain[chainid[i]].size()-1, 1, chainpos[i], chainpos[i]) << ' ';
        // cout << '\n';
    }
}
long long print_segtree(){
    for(int i=1; i<=n; i++){
        cout << i << " " << nb(i, 1) << " " << path(i, 1) << " " << nbs(i, 1) << " " << nb(i, 0) << " " << path(i, 0) << " " << nbs(i, 0) << endl;
    }
}

const double eps = 1e-8;
#define endl '\n'

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    init();
    dfs(1, 0);
    compute_sez_dfs(1, 0);
    build_chain(1, 0);
    build_hld_segtrees();
    //cout << "range" << endl;
    // print_range();
    binary_lifting();
    //cout << "bl" << endl;
    //print_bl(4);
    build();
    // print_segtree();
    // for (int i=1; i<=n; i++) cout << query_hld_segtree(0, chainid[i], 0, chain[chainid[i]].size()-1, 1, 0, chainpos[i]) << ' ';
    // cout << '\n';
    // cout << nbs(2, 1) << '\n';
    // for (int i=1; i<=n; i++) cout << chainid[i] << ' ' << chainpos[i] << '\n';
    cin >> q;
    long long a, b, c, d; //d itu anak parent yg ngarah ke child
    while(q--){
        cin >> a;
        if(a==1){
            cin >> b;
            // print_prefix();
            // print_segtree();
            updateNode(b,-1);
            // cout << endl;
            // print_prefix();
            // print_segtree();
            // cout << endl;
            isB[b] = !isB[b];
            updateNode(b, 1);
            // print_prefix();
            // print_segtree();
        }else{
            cin >> b >> c;
            if(depth[b]>depth[c]){
                d = b;
                b = c;
                c = d;
            }
            // cout << b << " " << c << endl;
            double A[2][2], B[2][2];
            if(isAncestor(b, c)){

                d = getParent(c, depth[c]-depth[b]-1);
                // cout << d << endl << endl;
                // cout << path(1, 1) << endl;
                // cout << path(d, 1) << endl;
                // cout << depth[b]+2 << endl;
                // cout << nb(1, 1) << endl;
                // cout << nbs(b, 1) << endl;
                // cout << nb(d, 1) << endl;
                A[0][0] = path(1, 1) - path(d, 1) + (depth[b]+2)*nb(1, 1) - 2*nbs(b, 1) - nb(d, 1);
                A[0][1] = path(c, 1);
                A[1][0] = nb(1, 1) - nb(d, 1);
                A[1][1] = nb(c, 1);

                B[0][0] = path(1, 0) - path(d, 0) + (depth[b]+2)*nb(1, 0) - 2*nbs(b, 0) - nb(d, 0);
                B[0][1] = path(c, 0);
                B[1][0] = nb(1, 0) - nb(d, 0);
                B[1][1] = nb(c, 0);
            }else{
                A[0][0] = path(b, 1);
                A[0][1] = path(c, 1);
                A[1][0] = nb(b, 1);
                A[1][1] = nb(c, 1);
                B[0][0] = path(b, 0);
                B[0][1] = path(c, 0);
                B[1][0] = nb(b, 0);
                B[1][1] = nb(c, 0);
            }
            if(fabs(A[1][0]*A[1][1]) < eps){
                if(fabs(B[1][0]*B[1][1]) < eps){
                    cout << "TIE" << endl;
                }else{
                    cout << "B" << endl;
                }
            }else if(fabs(B[1][0]*B[1][1]) < eps){
                cout << "A" << endl;
            }else{
                double ansA = A[0][0]/A[1][0] + A[0][1]/A[1][1];
                double ansB = B[0][0]/B[1][0] + B[0][1]/B[1][1];
                if(fabs(ansA - ansB) < eps){
                    cout << "TIE" << endl;
                }else if(ansA>ansB){
                    cout << "B" << endl;
                }else if(ansA<ansB){
                    cout << "A" << endl;
                }else{
                    cout << "TIE" << endl;
                }
            }
            // cout << A[0][0] << "/" << A[1][0] << " " << A[0][1] << "/" << A[1][1] << endl;
            // cout << B[0][0] << "/" << B[1][0] << " " << B[0][1] << "/" << B[1][1] << endl;
            // cout << ansA << " " << ansB << endl;
        }
    }
}