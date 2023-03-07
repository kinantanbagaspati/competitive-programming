#include <bits/stdc++.h>
using namespace std;
#define pii pair<int, int>
#define pli pair<long long, int>
#define plii pair<long long, pii>

const int maxn = 2048, maxm = 262144;
int n, q, a[maxn], nbsums, qidx;
int segtree[2*maxn][2*maxn], pqs;
long long dp[maxn], ans[maxm], queries[maxm][3];
pli pq[maxm];
plii sums[maxn * maxn];

void build(){
    for(int i=1; i<2*maxn; i++){
        for(int j=1; j<2*maxn; j++){
            segtree[i][j] = -1;
        }
    }
}

void update(int x, int y, int val){
    for(int i=x+maxn; i>0; i/=2){
        for(int j=y+maxn; j>0; j/=2){
            segtree[i][j] = val;
        }
    }
}

int temp[30], nbtemp;
int query(int lo, int hi){
    int res = -1;
    nbtemp = 0; lo += maxn; hi += maxn;
    while(lo <= hi){
        if(lo%2){
            temp[nbtemp] = lo; nbtemp++;
        } lo = (lo+1)/2;
        if(hi%2==0){
            temp[nbtemp] = hi; nbtemp++;
        } hi = (hi-1)/2;
    }
    for(int i=0; i<nbtemp; i++){
        for(int j=0; j<nbtemp; j++){
            res = max(res, segtree[temp[i]][temp[j]]);
        }
    }
    return res;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin >> n >> q;
    dp[0] = 0;
    nbsums = 0;
    //cout << "sums" << endl;
    for(int i=0; i<n; i++){
        cin >> a[i];
        dp[i+1] = dp[i] + a[i];
        for(int j=0; j<=i; j++){
            sums[nbsums].first = dp[i+1]-dp[j];
            sums[nbsums].second.first = j;
            sums[nbsums].second.second = i;
            //cout << dp[i+1]-dp[j] << "," << j << "," << i << endl;
            nbsums++;
        }
    }
    sort(sums, sums+nbsums);
    for(int i=0; i<q; i++){
        cin >> queries[i][0] >> queries[i][1] >> queries[i][2];
        pq[i].first = queries[i][2];
        pq[i].second = i;
    }
    sort(pq, pq+q);
    build();
    qidx = 0;
    for(int i=0; i<nbsums; i++){
        while(qidx < q && pq[qidx].first < sums[i].first){
            pqs = pq[qidx].second;
            ans[pqs] = query(queries[pqs][0]-1, queries[pqs][1]-1);
            qidx++;
        }
        if(qidx < q){
            update(sums[i].second.first, sums[i].second.second, i);
        }
    }
    while(qidx < q){
        pqs = pq[qidx].second;
        ans[pqs] = query(queries[pqs][0]-1, queries[pqs][1]-1);
        qidx++;
    }
    for(int i=0; i<q; i++){
        //cout << ans[i] << ": ";
        if(ans[i] < 0){
            cout << "NONE\n";
        }else{
            cout << sums[ans[i]].first << '\n';
        }
    }
}
