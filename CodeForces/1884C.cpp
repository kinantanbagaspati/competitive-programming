#include<bits/stdc++.h>
using namespace std;
#define pll pair<long long, long long>

const long long maxn = 131072;
long long t, n, m, batas[maxn][2];
long long toSort[maxn*2], segtree[maxn*2][2];
map<long long, long long> comp;
vector<long long> lo[maxn], hi[maxn];

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--){
        cin >> n >> m;
        for(int i=0; i<n; i++){
            cin >> batas[i][0] >> batas[i][1];
            batas[i][0]--;
            toSort[i*2] = batas[i][0];
            toSort[i*2 + 1] = batas[i][1];
        }
        // compress
        sort(toSort, toSort + n*2);
        long long curIdx = 1;
        comp[toSort[0]] = 0;
        for(int i=1; i<n*2; i++){
            if(toSort[i] != toSort[i-1]){
                comp[toSort[i]] = curIdx;
                curIdx++;
            }
        }
        // masukin batas
        for(int i=0; i<n; i++){
            lo[batas[1]].push_back([])
        }

        // bersihin
        comp.clear();
        for(int i=0; i<n*2; i++){
            lo[i].clear(); hi[i].clear();
        }
    }
}
