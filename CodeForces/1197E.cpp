#include<bits/stdc++.h>
using namespace std;
#define pll pair<long long, long long>
 
const long long maxn = 262144, mod = 1e9+7;
long long n, u, v, x, maxto = 0;
pair<long long, long long> edges[maxn];
set<long long> xs;
map<long long, long long> cnt, ans;
 
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> edges[i].first >> edges[i].second;
        xs.insert(-edges[i].first);
        //cout << "masukin " << -edges[i].first << endl;
        maxto = max(maxto, edges[i].second);
    }
    sort(edges, edges+n);
    
    cnt[1] = 1;
    ans[1] = 1;
    xs.insert(-1);
    for(int i=0; i<n; i++){
        //cout << "masuk " << -edges[i].first+1 << endl;
        x = -*(xs.lower_bound(-edges[i].first+1));
        //cout << "x: " << x << endl;
        if(cnt.find(edges[i].first) == cnt.end()){
            cnt[edges[i].first] = edges[i].first - x + cnt[x];
            ans[edges[i].first] = ans[x];
            //cout << "masuk " << cnt[edges[i].first] << " " << ans[edges[i].first] << endl;
        }
        x = -*(xs.lower_bound(-edges[i].second));
        //cout << edges[i].first << " " << edges[i].second << " " << x << endl;
        //cout << edges[i].second - x + cnt[x] << " " << cnt[edges[i].first] << endl;
        if(edges[i].second - x + cnt[x] < cnt[edges[i].first]){
            //cout << "masuk"
            cnt[edges[i].first] = edges[i].second - x + cnt[x];
            ans[edges[i].first] = ans[x];
        }else if(edges[i].second - x + cnt[x] == cnt[edges[i].first]){
            //cout << "masuk" << endl;
            ans[edges[i].first] = (ans[edges[i].first] + ans[x]) % mod;
        }
        //cout << edges[i].first << ": " << cnt[edges[i].first] << " " << ans[edges[i].first] << endl;
    }
    long long sumans = 0, sumcnt = 1e18;
    for(map<long long, long long>::iterator itr = ans.begin(); itr != ans.end(); itr++){
        if(itr->first > maxto && cnt[itr->first] < sumcnt){
            sumcnt = cnt[itr->first];
            sumans = itr->second;
        }else if(itr->first > maxto && cnt[itr->first] == sumcnt){
            sumans = (sumans + itr->second) % mod;
        }
    }
    cout << sumans << endl;
}