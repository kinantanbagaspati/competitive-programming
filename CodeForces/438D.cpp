#include<bits/stdc++.h>
using namespace std;
#define pii pair<int, int>

const int maxn = 131072;
int n, m, a[maxn], kiri, kanan, x;
long long sumtree[maxn*2];
set<pii> settree[maxn*2];

void update(int idx, int val){
    // hapus dlu
    for(int i=idx+maxn; i>0; i/=2){
        sumtree[i] -= a[idx];
        settree[i].erase({a[idx], idx});
    }
    a[idx] = val;
    // masukin
    for(int i=idx+maxn; i>0; i/=2){
        sumtree[i] += a[idx];
        settree[i].insert({a[idx], idx});
    }
}

vector<int> toChange;
void search(int lo, int hi, int mod){
    lo += maxn; hi += maxn;
    toChange.clear();
    while(lo <= hi){
        if(lo%2 == 1){
            for(set<pii>::iterator itr = settree[lo].lower_bound({mod, -1}); itr != settree[lo].end(); itr++){
                toChange.push_back(itr->second);
            }
        } lo = (lo+1)/2;
        if(hi%2 == 0){
            for(set<pii>::iterator itr = settree[hi].lower_bound({mod, -1}); itr != settree[hi].end(); itr++){
                toChange.push_back(itr->second);
            }
        } hi = (hi-1)/2;
    }
    for(int i=0; i<toChange.size(); i++){ 
        update(toChange[i], a[toChange[i]] % mod);
    }
}

long long query(int lo, int hi){
    lo += maxn; hi += maxn;
    long long ans = 0;
    while(lo <= hi){
        if(lo%2 == 1){
            ans += sumtree[lo];
        } lo = (lo+1)/2;
        if(hi%2 == 0){
            ans += sumtree[hi];
        } hi = (hi-1)/2;
    }
    return ans;
}

void debug(){
    cout << "debug";
    for(int i=0; i<n; i++){
        cout << ' ' << query(i, i);
    } cout << endl;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n >> m;
    for(int i=0; i<n; i++){
        cin >> x;
        update(i, x);
    }
    //debug();
    while(m--){
        cin >> x;
        if(x == 1){
            cin >> kiri >> kanan;
            cout << query(kiri-1, kanan-1) << '\n';
        }else if(x == 2){
            cin >> kiri >> kanan >> x;
            search(kiri-1, kanan-1, x);
        }else if(x == 3){
            cin >> kiri >> kanan;
            update(kiri-1, kanan);
        }
        //debug();
    }
}
