#include <bits/stdc++.h>
using namespace std;

const long long maxn = 200069;
long long n, m, cap[maxn];
multiset<pair<long long, long long> > ms;

long long segtree[30*maxn], child[30*maxn][2], range[30*maxn][2], nbnodes;

void createnode(long long lo, long long hi){
    segtree[nbnodes] = 1e9;
    child[nbnodes][0] = -1;
    child[nbnodes][1] = -1;
    range[nbnodes][0] = lo;
    range[nbnodes][1] = hi;
    nbnodes++;
}
void build(){
    nbnodes = 0;
    createnode(1, 1e9);
}
void update(long long node, long long pos, long long val){
    if(range[node][0] == range[node][1]){
        segtree[node] = val; return;
    }
    long long mid = (range[node][0] + range[node][1])/2;
    if(pos <= mid){
        if(child[node][0] < 0){
            child[node][0] = nbnodes; createnode(range[node][0], mid);
        }
        update(child[node][0], pos, val);
    }else{
        if(child[node][1] < 1){
            child[node][1] = nbnodes; createnode(mid+1, range[node][1]);
        }
        update(child[node][1], pos, val);
    }
    segtree[node] = 1e9;
    for(int i=0; i<2; i++){
        if(child[node][i]>=0){segtree[node] = min(segtree[child[node][i]], segtree[node]);}
    }
}
long long query(long long node, long long lo, long long hi){
    if(range[node][0] == lo && range[node][1] == hi){
        return segtree[node];
    }
    long long ret = 1e9, mid = (range[node][0] + range[node][1])/2;
    if(child[node][0] >= 0 && lo <= mid){
        ret = min(query(child[node][0], lo, min(mid, hi)), ret);
    }
    if(child[node][1] >= 0 && mid < hi){
        ret = min(query(child[node][1], max(mid+1, lo), hi), ret);
    }
    return ret;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n >> m;
    for(int i=0; i<n; i++){
        cin >> cap[i];
        ms.insert({cap[i], i});
    }
    build();
    for(int i=n-1; i>=0; i--){
        update(0, cap[i], i);
    }
    long long r, ans;
    pair<long long, long long> p;
    while(m--){
        cin >> r;
        ans = query(0, r, 1e9);
        if(ans == 1e9){
            cout << 0 << " ";
        }else{
            cout << ans+1 << " ";
            ms.erase({cap[ans], ans});
            p = *(ms.upper_bound({cap[ans], ans}));
            if(p.first == cap[ans]){
                update(0, cap[ans], p.second);
            }else{
                update(0, cap[ans], 1e9);
            }
            cap[ans] -= r;
            if(cap[ans] > 0){
                ms.insert({cap[ans], ans});
                p = *(ms.lower_bound({cap[ans], 0}));
                if(p.second == ans){
                    update(0, cap[ans], ans);
                }
            }
        }
    }
}
