#include <bits/stdc++.h>
using namespace std;
#define pll pair<long long, long long>

const int maxn = 524288;
int n, g[maxn], h[maxn], ord[maxn], curcomp;
pair<int, int> sorter[maxn];
vector<int> awal[maxn], akhir[maxn];
// linked list
int kiri[maxn], kanan[maxn], ans[maxn][2];
long long nbans;
int temp;

void tuker(int from, int to){
    awal[g[from]][ord[from]] = to;
    awal[g[to]][ord[to]] = from;
    temp = g[from]; g[from] = g[to]; g[to] = temp;
    temp = ord[from]; ord[from] = ord[to]; ord[to] = temp;
    ans[nbans][0] = from; ans[nbans][1] = to;
    nbans++;
}

void buang(int idx){
    if(kiri[idx]>=0){
        kanan[kiri[idx]] = kanan[idx];
    }
    if(kanan[idx]<n){
        kiri[kanan[idx]] = kiri[idx];
    }
}

int segtree[2*maxn], toDif[maxn];

void build(){
    for(int i=0; i<2*maxn; i++){
        segtree[i] = 0;
    }
}
void update(int idx){
    idx += maxn;
    while(idx>0){
        segtree[idx]++; idx/=2;
    }
}
int query(int lo, int hi){
    lo += maxn; hi += maxn;
    int res = 0;
    while(lo <= hi){
        if(lo%2){
            res += segtree[lo];
        } lo = (lo+1)/2;
        if(!(hi%2)){
            res += segtree[hi];
        } hi = (hi-1)/2;
    }
    return res;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin >> n;
    // compress g
    for(int i=0; i<n; i++){
        cin >> sorter[i].first; sorter[i].second = i;
    }
    sort(sorter, sorter+n);

    build();
    for(int i=n-1; i>=0; i--){
        toDif[i] = query(sorter[i].second, n-1);
        update(sorter[i].second);
    }

    curcomp = 0;
    g[sorter[0].second] = 0;
    for(int i=1; i<n; i++){
        if(sorter[i].first > sorter[i-1].first){
            curcomp++;
        }
        g[sorter[i].second] = curcomp;
    }
    // compress h
    for(int i=0; i<n; i++){
        cin >> sorter[i].first; sorter[i].second = i;
    }
    sort(sorter, sorter+n);

    build();
    nbans = 0;
    for(int i=n-1; i>=0; i--){
        nbans = nbans + abs(query(sorter[i].second, n-1) - toDif[i]);
        update(sorter[i].second);
    }
    cout << nbans << endl;

    curcomp = 0;
    h[sorter[0].second] = 0;
    for(int i=1; i<n; i++){
        if(sorter[i].first > sorter[i-1].first){
            curcomp++;
        }
        h[sorter[i].second] = curcomp;
    }
     /* cek compress
    for(int i=0; i<n; i++){
        cout << g[i] << " " << h[i] << endl;
    }*/

    // init posisi, ord dan linked list
    for(int i=0; i<n; i++){
        ord[i] = awal[g[i]].size();
        awal[g[i]].push_back(i);
        akhir[h[i]].push_back(i);
        kiri[i] = i-1; kanan[i] = i+1;
    }

    nbans = 0;
    for(int i=0; awal[i].size() > 0 && nbans < 2e5; i++){
        // hapus yg udh bener
        for(int j=0; j<awal[i].size(); j++){
            if(awal[i][j] == akhir[i][j]){
                buang(awal[i][j]);
            }
        }

        // buang yg geser kiri
        for(int j=0; j<awal[i].size() && nbans < 2e5; j++){
            bool hapus = awal[i][j] > akhir[i][j];
            while(awal[i][j] > akhir[i][j] && nbans < 2e5){
                tuker(awal[i][j], kiri[awal[i][j]]);
            }
            if(hapus){
                buang(awal[i][j]);
            }
        }
        // buang yg geser kanan
        for(int j=awal[i].size()-1; j>=0 && nbans < 2e5; j--){
            bool hapus = awal[i][j] < akhir[i][j];
            while(awal[i][j] < akhir[i][j] && nbans < 2e5){
                tuker(awal[i][j], kanan[awal[i][j]]);
            }
            if(hapus){
                buang(awal[i][j]);
            }
        }
    }

    // keluarin ans
    // cout << nbans << endl;
    for(int i=0; i<nbans; i++){
        cout << ans[i][0]+1 << " " << ans[i][1]+1 << "\n";
    }cout << endl;
}
