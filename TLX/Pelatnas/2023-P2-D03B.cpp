#include <bits/stdc++.h>
using namespace std;
#define ull unsigned long long
#define pll pair<ull, ull>

const int maxn = 200000;
ull n, q, p, v, szd = 0, nbLines;
pll ori[maxn], lines[maxn];
bool x;
ull chd[maxn], kiri[maxn], times[maxn];

ull getY(pll mc, ull x){
    return mc.first * x + mc.second;
}
ull getX(pll gradLo, pll gradHi){
    // x bil terkecil shg gradLo.first * x + gradLo.second < gradHi.first * x + gradHi.second
    return (gradLo.second - gradHi.second) / (gradHi.first - gradLo.first) + 1;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin >> n >> q >> x;
    for(int i=0; i<n; i++){
        cin >> v;
        ori[i].first = v; ori[i].second = 0;
        lines[i].first = v; lines[i].second = 0;
    }
    nbLines = n;
    for(int i=0; i<q; i++){
        cin >> p >> times[i] >> v; p--;
        ori[p].second = getY(ori[p], times[i]);
        ori[p].first -= v;
        ori[p].second -= times[i]*ori[p].first;
        lines[nbLines] = ori[p]; nbLines++;
    }
    // masukin convex hull
    // cout << nbLines << ":" << endl;
    sort(lines, lines+nbLines);
    /*
    for(int i=0; i<nbLines; i++){
        cout << "(" << lines[i].first << "," << lines[i].second << ")" << endl;
    }
    */

    for(int i=nbLines-1; i>=0; i--){
        while(szd && getY(lines[i], kiri[szd-1]) < getY(lines[chd[szd-1]], kiri[szd-1])){
            szd--;
            //cout << "hapus (" << lines[chd[szd]].first << "," << lines[chd[szd]].second << ") sejak " << kiri[szd] << endl;
        }
        if(szd){ //stackny gaabis
            kiri[szd] = getX(lines[i], lines[chd[szd-1]]);
        }else{ //stackny abis
            kiri[0] = 0;
        }
        chd[szd] = i; szd++;
        //cout << "masukin (" << lines[chd[szd-1]].first << "," << lines[chd[szd-1]].second << ") sejak " << kiri[szd-1] << endl;
    }
    //cout << "hull akhir:" << endl;
    for(int i=0; i<szd; i++){
        //cout << "(" << lines[chd[i]].first << ", " << lines[chd[i]].second << ") berlaku sejak " << kiri[i] << endl;
    }

    // query convex hull
    int curID = 0;
    for(int i=0; i<q; i++){
        while(curID < szd && kiri[curID+1] < times[i]){
            curID++;
        }
        cout << getY(lines[chd[curID]], times[i]) << endl;
    }
    return 0;
}