#include<bits/stdc++.h>
using namespace std;
#define pll pair<long long, long long>
#define pdl pair<double, long long>

const long long maxn = 262144;
int n, idx, iidx, totp, p[maxn], w;
long long t[maxn];
double sz[maxn], curt, curmul, ans[maxn], nxt;
pll toSort[maxn];
multiset<pdl> ms;
multiset<pdl>::iterator itr;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n >> w;
    for(int i=0; i<n; i++){
        cin >> t[i] >> sz[i] >> p[i];
        sz[i] = sz[i] / p[i] / w;
        toSort[i] = {t[i], i};
    }
    sort(toSort, toSort + n);
    idx = 0; totp = 0;
    curt = 0; curmul = 0;
    while(idx < n || !ms.empty()){
        if(ms.empty()){ //idx < n, masukin
            iidx = toSort[idx].second;
            curt = toSort[idx].first;
            // curmul ga diupdate
            totp += p[iidx];
            ms.insert({curmul + sz[iidx], iidx});
            idx++;
        }else {
            itr = ms.begin();
            nxt = curt + (itr->first - curmul) * totp;
            if(idx < n && nxt > (double) toSort[idx].first){
                // masukin
                iidx = toSort[idx].second;
                nxt = toSort[idx].first;
                curmul += (nxt - curt) / totp;
                curt = nxt;
                totp += p[iidx];
                ms.insert({curmul + sz[iidx], iidx});
                idx++;
            }else{
                // keluarin
                iidx = itr->second;
                curmul = itr->first;
                curt = nxt;
                totp -= p[iidx];
                ms.erase(itr);
                ans[iidx] = nxt;
            }
        }
    }
    for(int i=0; i<n; i++){
        cout << fixed << setprecision(9) << ans[i] << endl;
    }
}