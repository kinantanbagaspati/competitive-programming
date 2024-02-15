#include<bits/stdc++.h>
using namespace std;
#define p4 pair<pair<long long, long long>, pair<long long, long long>>
#define fi first 
#define se second

long long t, n, m, a[2048][16], b[16], pwn;
pair<p4, long long> srt[2048];
long long ans[3][(1<<12)];
vector<int> disjoint[(1<<12)];

int shift(int x){
    x += (x%2) * (1<<n);
    return x/2;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    for(int i=0; i<(1<<12); i++){
        for(int j=0; j<(1<<12); j++){
            if((i&j)==0){
                disjoint[i].push_back(j);
            }
        }
    }
    cin >> t;
    while(t--){
        cin >> n >> m; pwn = (1<<n);
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                cin >> a[j][i];
            }
        }
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                b[j] = a[i][j];
            }
            for(int j=n; j<16; j++){
                b[j] = 0;
            }
            sort(b, b+n);
            srt[i].fi.fi.fi = - (b[11] * 1e12 + b[10] * 1e6 + b[9]);
            srt[i].fi.fi.se = - (b[8] * 1e12 + b[7] * 1e6 + b[6]);
            srt[i].fi.se.fi = - (b[5] * 1e12 + b[4] * 1e6 + b[3]);
            srt[i].fi.se.se = - (b[2] * 1e12 + b[1] * 1e6 + b[0]);
            srt[i].se = i;
        }
        sort(srt, srt + m);
        
        m = min(m, n); // take only m
        for(int i=0; i<pwn; i++){
            ans[0][i] = 0;
        }
        for(int i=0; i<m; i++){
            // kosongin
            for(int j=0; j<pwn; j++){
                ans[(i+1)%2][j] = 0;
                ans[2][j] = 0;
            }
            // masukin 2
            for(int j=0; j<pwn; j++){
                int cpy = j;
                long long sum = 0;
                for(int k=0; k<n; k++){
                    if(cpy%2){
                        sum += a[srt[i].se][k];
                    } cpy /= 2;
                }
                ans[2][j] = max(ans[2][j], sum);
                cpy = shift(j);
                while(cpy != j){
                    ans[2][cpy] = max(ans[2][cpy], sum);
                    cpy = shift(cpy);
                }
            }
            // tambahin
            for(int j=0; j<pwn; j++){
                for(int k=0; k<disjoint[j].size() && j+disjoint[j][k]<pwn; k++){
                    int temp = j+disjoint[j][k];
                    ans[(i+1)%2][temp] = max(ans[(i+1)%2][temp], ans[i%2][j] + ans[2][disjoint[j][k]]);
                }
            }
        }
        cout << ans[m%2][pwn-1] << endl;
    }
}