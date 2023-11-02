#include<bits/stdc++.h>
using namespace std;

const int maxn = 300300;
int segtree[maxn*40], childID[maxn*40][2][2], range[maxn*40][2][3], nbNodes;

void createNode(int lx, int rx, int ly, int ry){
    range[nbNodes][0][0] = lx; range[nbNodes][0][1] = rx;
    range[nbNodes][0][2] = (lx+rx)/2;
    range[nbNodes][1][0] = ly; range[nbNodes][1][1] = ry;
    range[nbNodes][1][2] = (ly+ry)/2;
    for(int i=0; i<4; i++){
        childID[nbNodes][i/2][i%2] = -1;
    }
    nbNodes++;
}

void update(int x, int y, int val){
    //cout << "node " << node << endl;
    //cout << range[node][0][0] << "-" << range[node][0][1] << ":";
    //cout << range[node][1][0] << "-" << range[node][1][1] << endl;
    int node = 0;
    for(int i=0; i<20; i++){
        //cout << "node " << node << endl;
        //cout << range[node][0][0] << "-" << range[node][0][1] << " vs " << x << " | ";
        //cout << range[node][1][0] << "-" << range[node][1][1] << " vs " << y << endl;
        segtree[node] += val;
        int xID = (x > range[node][0][2]), yID = (y > range[node][1][2]);
        if(childID[node][xID][yID] < 0){
            childID[node][xID][yID] = nbNodes;
            int lx = range[node][0][0], rx = range[node][0][1];
            int ly = range[node][1][0], ry = range[node][1][1];
            if(xID){
                lx = range[node][0][2]+1;
            }else{
                rx = range[node][0][2];
            }
            if(yID){
                ly = range[node][1][2]+1;
            }else{
                ry = range[node][1][2];
            }
            createNode(lx, rx, ly, ry);
        }
        node = childID[node][xID][yID];
    }
    //cout << "node " << node << endl;
    //cout << range[node][0][0] << "-" << range[node][0][1] << " vs " << x << " | ";
    //cout << range[node][1][0] << "-" << range[node][1][1] << " vs " << y << endl;
    segtree[node] += val;
}

int query(int node, int lx, int rx, int ly, int ry){
    if(node < 0) return 0;
    if(range[node][0][0] == lx && range[node][0][1] == rx){
        if(range[node][1][0] == ly && range[node][1][1] == ry){
            return segtree[node];
        }
    }
    int result = 0;
    if(lx <= range[node][0][2]){
        if(ly <= range[node][1][2]){
            result += query(childID[node][0][0], lx, min(range[node][0][2], rx), ly, min(range[node][1][2], ry));
        }
        if(ry > range[node][1][2]){
            result += query(childID[node][0][1], lx, min(range[node][0][2], rx), max(ly, range[node][1][2]+1), ry);
        }
    }
    if(rx > range[node][0][2]){
        if(ly <= range[node][1][2]){
            result += query(childID[node][1][0], max(lx, range[node][0][2]+1), rx, ly, min(range[node][1][2], ry));
        }
        if(ry > range[node][1][2]){
            result += query(childID[node][1][1], max(lx, range[node][0][2]+1), rx, max(ly, range[node][1][2]+1), ry);
        }
    }
    return result;
}

int n, m, lo, hi, k, p, q, ans;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n >> m;
    createNode(0, (1<<20)-1, 0, (1<<20)-1);
    for(int i=0; i<n; i++){
        cin >> lo >> hi;
        update(lo, hi, 1);
    }
    for(int i=0; i<m; i++){
        cin >> k; q = 1; ans = n;
        while(k--){
            cin >> p;
            if(q <= p-1){
                ans -= query(0, q, p-1, q, p-1);
            }
            q = p+1;
        }
        cout << ans - query(0, q, (1<<20)-1, q, (1<<20)-1) << endl;
    }
}