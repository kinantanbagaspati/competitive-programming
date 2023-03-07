#include<bits/stdc++.h>
using namespace std;
#define pll pair<long long, long long>

const long long maxn = 262144;
long long t, n, pq[2][maxn], temp, ans;
long long idx[2], lo[2], hi[2], mul[2];

long long choose2(long long x){
    return x*(x-1)/2;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n;
    for(int i=0; i<2; i++){
        for(int j=0; j<n; j++){
            cin >> temp;
            pq[i][temp] = i;
        }
    }
    idx[0] = pq[0][1];
    idx[1] = pq[1][1];
    ans = choose2(min(idx[0], idx[1]) + 1);
    ans += choose2(max(idx[0], idx[1]) - min(idx[0], idx[1]));
    ans += choose2(n - max(idx[0], idx[1]));
    //cout << ans << endl;
    for(int i=0; i<2; i++){
        lo[i] = idx[i]; hi[i] = idx[i];
    }

    for(int i=2; i<=n; i++){
        idx[0] = pq[0][i];
        idx[1] = pq[1][i];
        if(idx[0] < lo[0]){
            if(idx[1] < lo[1]){
                mul[0] = min(lo[0], lo[1]) - max(idx[0], idx[1]);
                mul[1] = n - max(hi[0], hi[1]);
                if(mul[0] > 0 && mul[1] > 0){
                    ans += mul[0]*mul[1];
                }
            }else if(idx[1] > hi[1]){
                mul[0] = min(lo[0], lo[1]) - idx[0];
                mul[1] = idx[1] - max(hi[0], hi[1]);
                if(mul[0] > 0 && mul[1] > 0){
                    ans += mul[0]*mul[1];
                }
            }
        }else if(idx[0] > hi[0]){
            if(idx[1] < lo[1]){
                mul[0] = min(lo[0], lo[1]) - idx[1];
                mul[1] = idx[0] - max(hi[0], hi[1]);
                if(mul[0] > 0 && mul[1] > 0){
                    ans += mul[0]*mul[1];
                }
            }else if(idx[1] > hi[1]){
                mul[0] = min(lo[0], lo[1]) + 1;
                mul[1] = min(idx[0], idx[1]) - max(hi[0], hi[1]);
                if(mul[0] > 0 && mul[1] > 0){
                    ans += mul[0]*mul[1];
                }
            }
        }

        for(int i=0; i<2; i++){
            lo[i] = idx[i]; hi[i] = idx[i];
        }
    }
    cout << ans+1 << endl;
}
