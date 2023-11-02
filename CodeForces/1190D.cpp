#include<bits/stdc++.h>
using namespace std;
#define pll pair<long long, long long>
 
const long long maxn = 262144, maxm = (1<<30);
long long n, cpy, ans, segtree[maxn*2];
pair<long long, long long> xy[maxn];
set<long long> s, compset;
map<long long, long long> compmap;

void update(long long idx, long long val){
    idx += maxn;
    while(idx>0){
        segtree[idx] += val; idx /= 2;
    }
}
long long query(long long lo, long long hi){
    lo += maxn; hi += maxn;
    long long res = 0;
    while(lo <= hi){
        if(lo%2 == 1){
            res += segtree[lo];
        } lo = (lo+1)/2;
        if(hi%2 == 0){
            res += segtree[hi];
        } hi = (hi-1)/2;
    }
    return res;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> xy[i].second >> xy[i].first;
        xy[i].first *= -1;
        compset.insert(xy[i].second);
    }
    compset.insert(1); compset.insert(maxm);
    long long idx = 0;
    while(!(compset.empty())){
        cpy = *(compset.begin());
        compset.erase(cpy);
        compmap[cpy] = idx; idx++;
    }
    sort(xy, xy+n);

    for(int i=0; i<n; i++){
        cpy = i; 
        long long prev = compmap[1], between;
        while(i<n && xy[i].first == xy[cpy].first){
            //cout << "masuk while" << endl;
            between = query(prev, compmap[xy[i].second]-1);
            ans -= between * (between+1) / 2;
            prev =  compmap[xy[i].second] + 1;
            if(*(s.lower_bound(xy[i].second)) != xy[i].second){
                update(compmap[xy[i].second], 1);
                s.insert(xy[i].second);
            } i++;
        } i--;
        between = query(prev, compmap[maxm]);
        ans -= between * (between+1) / 2;
 
        //cout << "between " << between << endl;
        //cout << "sz " << s.size() << endl;
        between = s.size();
        ans += between * (between+1) / 2;
        //cout << "ans " << ans << endl << endl;
    }
    cout << ans << endl;
}