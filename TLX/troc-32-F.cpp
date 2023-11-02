#include <bits/stdc++.h>
using namespace std;
 
const long long nmax = 262144;
 
long long node = 0, rootVersion[nmax];
long long segtree[32*nmax], range[32*nmax][2], childID[32*nmax][2];
 
 
void create(long long l, long long r){
    range[node][0] = l;
    range[node][1] = r;
    segtree[node] = 0;
    childID[node][0] = -1;
    childID[node][1] = -1;
    node++;
}
 
void update(long long node, long long k, long long val){
    long long curnode = 0;
    while(range[curnode][0] < range[curnode][1]){
        segtree[curnode] += val;
        long long mid = (range[curnode][0] + range[curnode][1])/2;
        long long child = 0, l = range[curnode][0], r = mid;
        if(k>mid){
            child = 1;
            l = mid+1;
            r = range[curnode][1];
        }
        if(childID[curnode][child] < 0){
            childID[curnode][child] = node;
            create(l, r);
        }
        curnode = childID[curnode][child];
    }
    segtree[curnode] += val;
}
 
long long query(long long node, long long l, long long r){
    //cout << "queried" << node << " " << l << " " << r << endl;
    if(l == range[node][0] && r == range[node][1]){
        return segtree[node];
    }
 
    long long toReturn = 0;
    long long mid = (range[node][0] + range[node][1])/2;
    if(childID[node][0] >= 0 && l<=mid){
        toReturn += query(childID[node][0], l, min(mid, r));
    }
    if(childID[node][1] >= 0 && r>mid){
        toReturn += query(childID[node][1], max(mid+1, l), r);
    }
    return toReturn;
}

long long n, 
 
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
 
    create(1, 1e9);
 
    
}