#include<bits/stdc++.h>
using namespace std;
#define pll pair<long long, long long>
#define x first
#define y second 

const long long maxn = 131072;
long long segtree[4*maxn]; // bisa ada 2maxn nilai y
void update(long long idx, long long val){
    idx += 2*maxn;
    while(idx > 0){
        segtree[idx] += val; idx /= 2;
    }
}
long long query(long long lo, long long hi){
    long long ret = 0; lo += 2*maxn; hi += 2*maxn;
    while(lo <= hi){
        if(lo%2){ret += segtree[lo];} lo = (lo+1)/2;
        if(!(hi%2)){ret += segtree[hi];} hi = (hi-1)/2;
    }
    return ret;
}

long long n, to = 0, ans = 0, colidx = 0, rowidx = 0, curx;
pll xy[2];
set<long long> xvals, yvals;
map<long long, long long> xmp, ymp;
pair<long long, pll> plpll;
vector<pair<long long, pll> > rows0, rows1, cols0, cols1;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    // input
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> xy[0].x >> xy[0].y >> xy[1].x >> xy[1].y;
        xvals.insert(xy[0].x); xvals.insert(xy[1].x);
        yvals.insert(xy[0].y); yvals.insert(xy[1].y);
        if(xy[0].x == xy[1].x){ // column
            cols0.push_back({xy[0].x, {min(xy[0].y, xy[1].y), max(xy[0].y, xy[1].y)}});
        }else{ // row
            rows0.push_back({xy[0].y, {min(xy[0].x, xy[1].x), max(xy[0].x, xy[1].x)}});
        }
    }
    //cout << "bikin mapping" << endl;
    to = 0;
    while(yvals.size()){
        ymp[*(yvals.begin())] = to;
        yvals.erase(yvals.begin()); to++;
    }
    //cout << "gabungin row-row atau col-col" << endl;
    ans = 0;
    if(cols0.size()){
        sort(cols0.begin(), cols0.end());
        plpll = cols0[0];
        for(int i=1; i<cols0.size(); i++){
            if(plpll.x == cols0[i].x && plpll.y.y >= cols0[i].y.x){
                plpll.y.y = max(plpll.y.y, cols0[i].y.y);
            }else{
                ans += plpll.y.y - plpll.y.x + 1;
                cols1.push_back({plpll.x, {ymp[plpll.y.x], ymp[plpll.y.y]}});
                plpll = cols0[i];
            }
        }
        ans += plpll.y.y - plpll.y.x + 1;
        cols1.push_back({plpll.x, {ymp[plpll.y.x], ymp[plpll.y.y]}});
    }
    if(rows0.size()){
        sort(rows0.begin(), rows0.end());
        plpll = rows0[0];
        for(int i=1; i<rows0.size(); i++){
            if(plpll.x == rows0[i].x && plpll.y.y >= rows0[i].y.x){
                plpll.y.y = max(plpll.y.y, rows0[i].y.y);
            }else{
                ans += plpll.y.y - plpll.y.x + 1;
                rows1.push_back({plpll.y.x, {ymp[plpll.x], -1}}); // delta minus
                rows1.push_back({plpll.y.y + 1, {ymp[plpll.x], 1}}); // delta plus
                plpll = rows0[i];
            }
        }
        ans += plpll.y.y - plpll.y.x + 1;
        rows1.push_back({plpll.y.x, {ymp[plpll.x], -1}}); // delta minus
        rows1.push_back({plpll.y.y + 1, {ymp[plpll.x], 1}}); // delta plus
    }
    //cout << "intersect" << endl;
    sort(cols1.begin(), cols1.end());
    sort(rows1.begin(), rows1.end());
    while(colidx < cols1.size() && rowidx < rows1.size()){
        if(cols1[colidx].x < rows1[rowidx].x){
            ans += query(cols1[colidx].y.x, cols1[colidx].y.y); colidx++;
        }else{
            update(rows1[rowidx].y.x, rows1[rowidx].y.y); rowidx++;
        }
    }
    cout << ans << endl;
}