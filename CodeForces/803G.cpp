#include<bits/stdc++.h>
using namespace std;
#define pll pair<long long, long long>

const int maxn = (1<<17), maxm = (1<<30);
int n, k, table[20][maxn], wp[maxn];
int getMinB(int lo, int hi){ // inklusif
    //cout << "lohi " << lo << "-" << hi << endl;
    int pw = wp[hi-lo+1];
    //cout << pw << " " << hi+1-(1<<pw) << endl;
    //cout << "min " << table[pw][lo] << " " << table[pw][hi+1-(1<<pw)] << endl;
    return min(table[pw][lo], table[pw][hi+1-(1<<pw)]);
}

int segtree[maxn*64][2], child[maxn*64][2], range[maxn*64][2], nbnodes=0;
void createNode(int lo, int hi){ // inklusif
    if(hi-lo+1 >= n){
        segtree[nbnodes][0] = getMinB(0, n-1);
        //cout << "bikin " << lo << "-" << hi << " " << segtree[nbnodes][0] << endl;
    }else if(hi%n >= lo%n){
        segtree[nbnodes][0] = getMinB(lo%n, hi%n);
    }else{
        segtree[nbnodes][0] = min(getMinB(0, hi%n), getMinB(lo%n, n-1));
    }
    segtree[nbnodes][1] = maxm;
    child[nbnodes][0] = -1; child[nbnodes][1] = -1;
    range[nbnodes][0] = lo; range[nbnodes][1] = hi;
    nbnodes++;
}

void diligent(int node){
    int mid = (range[node][0] + range[node][1])/2;
    if(child[node][0] < 0){
        child[node][0] = nbnodes; createNode(range[node][0], mid);
    }
    if(child[node][1] < 0){
        child[node][1] = nbnodes; createNode(mid+1, range[node][1]);
    }
    if(segtree[node][1] < maxm){ // nurunin lazy
        segtree[node][0] = segtree[node][1];
        segtree[child[node][0]][1] = segtree[node][1];
        segtree[child[node][1]][1] = segtree[node][1];
        segtree[node][1] = maxm;
    }
}
void update(int node, int lo, int hi, int val){
    if(lo==range[node][0] && hi==range[node][1]){
        segtree[node][1] = val;
        return;
    }
    diligent(node);
    int mid = (range[node][0] + range[node][1])/2;
    if(lo<=mid){
        update(child[node][0], lo, min(hi, mid), val);
    }
    if(mid<hi){
        update(child[node][1], max(mid+1, lo), hi, val);
    }
    segtree[node][0] = min(
        segtree[child[node][0]][segtree[child[node][0]][1] < maxm],
        segtree[child[node][1]][segtree[child[node][1]][1] < maxm]
    );
}
int query(int node, int lo, int hi){
    if(lo==range[node][0] && hi==range[node][1]){
        if(segtree[node][1] < maxm){
            return segtree[node][1];
        }else{
            return segtree[node][0];
        }
    }
    diligent(node);
    int mid = (range[node][0] + range[node][1])/2, ret = maxm;
    if(lo<=mid){
        ret = min(query(child[node][0], lo, min(hi, mid)), ret);
    }
    if(mid<hi){
        ret = min(query(child[node][1], max(mid+1, lo), hi), ret);
    }
    return ret;
}

int q, t, x, y, z;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n >> k;
    for(int i=0; i<n; i++){
        cin >> table[0][i];
    }
    wp[1] = 0;
    for(int i=1; i<17; i++){
        for(int j=0; j+(1<<i) <= n; j++){
            table[i][j] = min(table[i-1][j], table[i-1][(1<<(i-1))+j]);
        }
        for(int j=(1<<i); j<(1<<(i+1)); j++){
            wp[j] = i;
        }
    }
    /*for(int i=1; i<=16; i++){
        cout << wp[i] << ' ';
    } cout << "wp" << endl;*/
    createNode(0, maxm);
    cin >> q;
    while(q--){
        cin >> t >> x >> y; t--; x--; y--;
        if(t){
            cout << query(0, x, y) << endl;
        }else{
            cin >> z;
            update(0, x, y, z);
        }
    }
}