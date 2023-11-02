#include<bits/stdc++.h>
using namespace std;
#define pll pair<long long, long long>

const int maxn = 524288;
long long n, m, q, a[maxn], x, segtree[maxn*2];
long long qidx, cura, nexta, ans[maxn];
pair<long long, long long> queries[maxn];
vector<long long> inva[maxn];

void update(long long idx, long long val){
    //cout << "updating " << idx << " " << val << endl;
    idx += maxn;
    while(idx > 0){
        segtree[idx] += val; idx /= 2;
    }
}

long long query(long long val){
    long long node = 1;
    while(node < maxn){
        //cout << val << " vs " << segtree[2*node] << endl;
        if(val > segtree[2*node]){
            val -= segtree[2*node]; node = 2*node+1;
        }else{
            node = 2*node;
        }
    }
    return node - maxn;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //input
    cin >> n >> m >> q; cura = n;
    while(n--){
        cin >> x; a[x]++;
    }
    for(int i=1; i<=m; i++){
        inva[a[i]].push_back(i);
    }
    for(int i=0; i<q; i++){
        cin >> queries[i].first;
        queries[i].second = i;
    }
    sort(queries, queries+q);

    x = 0; qidx = 0;
    for(int i=0; i<maxn; i++){
        x += inva[i].size();
        for(int j=0; j<inva[i].size(); j++){
            update(inva[i][j], 1);
        }
        nexta = cura + x;
        while(qidx < q && queries[qidx].first <= nexta){
            //cout << "querying " << queries[qidx].second << ": " << queries[qidx].first << endl;
            //cout << "cura: " << cura << endl;
            ans[queries[qidx].second] = query(queries[qidx].first - cura);
            qidx++;
        }
        cura = nexta;
    }
    while(qidx < q){
        ans[queries[qidx].second] = (queries[qidx].first-cura-1) % m + 1;
        qidx++;
    }

    //output
    for(int i=0; i<q; i++){
        cout << ans[i] << endl;
    }
}