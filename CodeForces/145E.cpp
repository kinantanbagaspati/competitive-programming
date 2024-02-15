#include<bits/stdc++.h>
using namespace std;
#define pll pair<long long, long long>

const int maxn=(1<<20);
int n, m;
bool lazy[maxn*2];
int segtree[maxn*2][4], range[maxn*2][2];

void build(){
    char c;
    for(int i=0; i<n; i++){
        cin >> c;
        if(c=='4'){
            segtree[maxn+i][0] = 1; //bawah
            segtree[maxn+i][1] = 1; //naik
            segtree[maxn+i][2] = 1; //turun
            segtree[maxn+i][3] = 0; //atas
        }else{
            segtree[maxn+i][0] = 0; //bawah
            segtree[maxn+i][1] = 1; //naik
            segtree[maxn+i][2] = 1; //turun
            segtree[maxn+i][3] = 1; //atas
        }
    }
    for(int i=0; i<maxn; i++){
        range[maxn+i][0] = i; range[maxn+i][1] = i;
    }
    for(int i=maxn-1; i>0; i--){
        segtree[i][0] = segtree[i*2][0] + segtree[i*2+1][0]; //bawah
        segtree[i][1] = max(segtree[i*2][0] + segtree[i*2+1][1], segtree[i*2][1] + segtree[i*2+1][3]); //naik
        segtree[i][2] = max(segtree[i*2][2] + segtree[i*2+1][0], segtree[i*2][3] + segtree[i*2+1][2]); //turun
        segtree[i][3] = segtree[i*2][3] + segtree[i*2+1][3]; //atas
        range[i][0] = range[i*2][0]; range[i][1] = range[i*2+1][1];
    }
}

void unlazy(int node){
    if(!lazy[node]){
        return;
    } // pasti lazy
    lazy[node] = false;
    int temp = segtree[node][0]; segtree[node][0] = segtree[node][3]; segtree[node][3] = temp;
    temp = segtree[node][1]; segtree[node][1] = segtree[node][2]; segtree[node][2] = temp;
    if(node<maxn){
        lazy[node*2] = !lazy[node*2];
        lazy[node*2+1] = !lazy[node*2+1];
    }
}

void update(int node, int lo, int hi){
    if(range[node][0] == lo && range[node][1] == hi){
        lazy[node] = !lazy[node];
        return;
    }
    unlazy(node);
    int mid = (range[node][0]+range[node][1])/2;
    if(lo<=mid){
        update(node*2, lo, min(mid, hi));
    }
    if(hi>mid){
        update(node*2+1, max(lo, mid+1), hi);
    }
    unlazy(node*2); unlazy(node*2+1);
    segtree[node][0] = segtree[node*2][0] + segtree[node*2+1][0]; //bawah
    segtree[node][1] = max(segtree[node*2][0] + segtree[node*2+1][1], segtree[node*2][1] + segtree[node*2+1][3]); //naik
    segtree[node][2] = max(segtree[node*2][2] + segtree[node*2+1][0], segtree[node*2][3] + segtree[node*2+1][2]); //turun
    segtree[node][3] = segtree[node*2][3] + segtree[node*2+1][3]; //atas
}

int x, y;
string s;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n >> m;
    build();
    for(int i=0; i<m; i++){
        cin >> s;
        if(s[0] == 'c'){
            cout << segtree[1][1] << endl;
        }else{
            cin >> x >> y; x--; y--;
            update(1, x, y);
        }
    }
}