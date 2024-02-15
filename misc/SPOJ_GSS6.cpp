#include <bits/stdc++.h>
using namespace std;

const int maxn = 131072;
int rootNode = -1, curNode = 0; // treeSize bisa dari infoTree[rootNode][0]
int infoTree[maxn*4][5]; // kiriID, kananID, parent, size, depth
int infoVal[maxn*4][4]; // sum, kiri, tengah, kanan

bool isLeaf(int node){
    return infoTree[node][0] < 0 && infoTree[node][1] < 0;
}
void updateNode(int node){ // assuming not a leaf
    int kiri = infoTree[node][0], kanan = infoTree[node][1];
    // update tree
    infoTree[node][3] = infoTree[kiri][3] + infoTree[kanan][3];
    infoTree[node][4] = 1 + max(infoTree[kiri][4], infoTree[kanan][4]);
    // update val
    infoVal[node][0] = infoVal[kiri][0] + infoVal[kanan][0];
    infoVal[node][1] = max(infoVal[kiri][1], infoVal[kiri][0] + infoVal[kanan][1]);
    infoVal[node][2] = max(max(infoVal[kiri][2], infoVal[kanan][2]), infoVal[kiri][3] + infoVal[kanan][1]);
    infoVal[node][3] = max(infoVal[kanan][3], infoVal[kiri][3] + infoVal[kanan][0]);
}
void rotate(int z, bool isLeft){
    int par = infoTree[z][2];
    int t1 = infoTree[z][!isLeft], y = infoTree[z][isLeft];
    int t2 = infoTree[y][!isLeft], x = infoTree[y][isLeft];
    int t3 = infoTree[x][!isLeft], t4 = infoTree[x][isLeft];
    //cout << "rotate " << z << (isLeft? " left" : " right") << endl;
    //cout << "xy: " << x << ' ' << y << endl;
    //cout << "t: " << t1 << ' ' << t2 << ' ' << t3 << ' ' << t4 << endl;
    // ubah child
    if(par < 0){
        rootNode = y;
    }else{
        infoTree[par][(infoTree[par][1] == z)] = y;
    }
    infoTree[x][!isLeft] = t3; infoTree[x][isLeft] = t4;
    infoTree[y][!isLeft] = z; infoTree[y][isLeft] = x;
    infoTree[z][!isLeft] = t1; infoTree[z][isLeft] = t2;
    // ubah parent
    infoTree[t1][2] = z; infoTree[t2][2] = z;
    infoTree[t3][2] = x; infoTree[t4][2] = x;
    infoTree[x][2] = y; infoTree[y][2] = par; infoTree[z][2] = y;
    // ubah info
    updateNode(x); updateNode(z); updateNode(y);
}

void addLeaf(int parent, int val){
    infoTree[curNode][0] = -1; infoTree[curNode][1] = -1; infoTree[curNode][2] = parent;
    infoTree[curNode][3] = 1; infoTree[curNode][4] = 0;
    infoVal[curNode][0] = val; 
    infoVal[curNode][1] = val; infoVal[curNode][2] = val; infoVal[curNode][3] = val;
    curNode++;
}
int getNodefromID(int id){
    int node = rootNode;
    while(!isLeaf(node)){
        int kiri = infoTree[node][0], kanan = infoTree[node][1];
        //cout << "nlr " << node << ' ' << kiri << ' ' << kanan << endl;
        if(id < infoTree[kiri][3]){
            node = kiri;
        }else{
            id -= infoTree[kiri][3];
            node = kanan;
        }
    }
    return node;
}
void balancefromLeaf(int node){
    while(node >= 0){
        //cout << "balancefromLeaf " << node << endl;
        int kiri = infoTree[node][0], kanan = infoTree[node][1], par = infoTree[node][2];
        if(infoTree[kiri][4] - infoTree[kanan][4] > 1){ // berat di kiri
            if(infoTree[infoTree[kiri][1]][4] - infoTree[infoTree[kiri][0]][4] > 1){ // berat di kanan
                rotate(kiri, true);
            }
            rotate(node, false);
        }else if(infoTree[kanan][4] - infoTree[kiri][4] > 1){ // berat di kanan
            if(infoTree[infoTree[kanan][0]][4] - infoTree[infoTree[kanan][1]][4] > 1){ // berat di kiri
                rotate(kanan, false);
            }
            rotate(node, true);
        }else{
            updateNode(node);
        } node = par;
    }
}
void addAVL(int id, int val){
    //cout << "addAVL " << id << ' ' << val << endl;
    if(rootNode < 0){
        rootNode = curNode; addLeaf(-1, val);
        return;
    }
    int node = getNodefromID(id);
    
    infoTree[node][!(id < infoTree[rootNode][3])] = curNode;
    addLeaf(node, val);
    infoTree[node][(id < infoTree[rootNode][3])] = curNode;
    addLeaf(node, infoVal[node][0]);

    balancefromLeaf(node);
}
void delAVL(int id){
    if(isLeaf(rootNode)){
        rootNode = -1; return;
    }
    int node = getNodefromID(id);

    int par = infoTree[node][2], gpar = infoTree[par][2];
    int bro = infoTree[par][!(infoTree[par][1] == node)];
    infoTree[gpar][(infoTree[gpar][1] == par)] = bro;
    infoTree[bro][2] = gpar;

    balancefromLeaf(gpar);
}
void updAVL(int id, int val){
    int node = getNodefromID(id);
    infoVal[node][0] = val; 
    infoVal[node][1] = val; infoVal[node][2] = val; infoVal[node][3] = val;
    balancefromLeaf(infoTree[node][2]);
}
int query(int node, int type, int lo, int hi){ // assuming masuk berarti lohi valid
    if((lo == 0) && (hi+1 == infoTree[node][3])){
        return infoVal[node][type];
    }
    int ans = -2e9, kiri = infoTree[node][0], kanan = infoTree[node][1];
    if(lo < infoTree[kiri][3] && type < 3){
        ans = max(query(kiri, type, lo, min(infoTree[kiri][3]-1, hi)), ans);
    }
    if(hi >= infoTree[kiri][3] && type > 1){
        ans = max(query(kanan, type, max(lo-infoTree[kiri][3], 0), hi-infoTree[kiri][3]), ans);
    }
    if(lo < infoTree[kiri][3] && infoTree[kiri][3] <= hi){
        if(type == 1){
            ans = max(query(kanan, type, 0, hi-infoTree[kiri][3]) + infoVal[kiri][0], ans);
        }else if(type == 3){
            ans = max(query(kiri, type, lo, infoTree[kiri][3]-1) + infoVal[kanan][0], ans);
        }else{
            ans = max(query(kiri, 3, lo, infoTree[kiri][3]-1) + query(kanan, 1, 0, hi-infoTree[kiri][3]), ans);
        }
    }
    return ans;
}
void printTree(int node, int depth){
    if(node < 0){return;}

    for(int i=0; i<depth; i++){
        cout << "  ";
    } cout << "infoTree " << node << ':';
    for(int i=0; i<5; i++){
        cout << ' ' << infoTree[node][i];
    } cout << endl;

    for(int i=0; i<depth; i++){
        cout << "  ";
    } cout << "infoVal " << node << ':';
    for(int i=0; i<4; i++){
        cout << ' ' << infoVal[node][i];
    } cout << endl;

    printTree(infoTree[node][0], depth+1);
    printTree(infoTree[node][1], depth+1);
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n, a;
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> a;
        addAVL(i, a);
        //printTree(rootNode, 0);
    }
    char ch;
    int q, x, y;
    cin >> q;
    while(q--){
        cin >> ch;
        if(ch == 'I'){
            cin >> x >> y;
            addAVL(x-1, y);
        }else if(ch == 'D'){
            cin >> x;
            delAVL(x-1);
        }else if(ch == 'R'){
            cin >> x >> y;
            updAVL(x-1, y);
        }else if(ch == 'Q'){
            cin >> x >> y;
            cout << max(query(rootNode, 2, x-1, y-1), 0) << endl;
        }
        //printTree(rootNode, 0);
    }
}