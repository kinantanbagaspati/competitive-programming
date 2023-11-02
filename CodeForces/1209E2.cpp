#include<bits/stdc++.h>
using namespace std;
#define p4 pair<pair<long long, long long>, pair<long long, long long>>
#define fi first 
#define se second

long long t, n, m, a[2048][16], pwn;
pair<p4, long long> srt[2048];
long long ans[16][(1<<16)];

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--){
        cin >> n >> m; pwn = (1<<n);
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                cin >> a[j][i];
            }
        }
        for(int i=0; i<m; i++){
            for(int j=n; j<16; j++){
                a[i][j] = 0;
            }
        }
        for(int i=0; i<=n; i++){
            for(int j=0; j<pwn; j++){
                ans[i][j] = 0;
            }
        }
        for(int i=0; i<m; i++){
            sort(a[i], a[i]+n);
            srt[i].fi.fi.fi = - (a[i][11] * 1e12 + a[i][10] * 1e6 + a[i][9]);
            srt[i].fi.fi.se = - (a[i][8] * 1e12 + a[i][7] * 1e6 + a[i][6]);
            srt[i].fi.se.fi = - (a[i][5] * 1e12 + a[i][4] * 1e6 + a[i][3]);
            srt[i].fi.se.se = - (a[i][2] * 1e12 + a[i][1] * 1e6 + a[i][0]);
            srt[i].se = i;
        }
        sort(srt, srt + m);
        //cout << srt[0].fi.fi.fi << " " << srt[0].fi.fi.se << " " << srt[0].fi.se.fi << " " << srt[0].fi.se.se << " " << srt[0].se << endl;
        //cout << "ans" << endl;
        for(int i=0; i<min(n, m); i++){
            for(int j=0; j<pwn; j++){
                long long sum = 0, cpy = j;
                for(int k=0; k<n; k++){
                    if(cpy%2) sum += a[srt[i].se][k];
                    cpy /= 2;
                } cpy = pwn-1-j;
                for(int k=cpy; k>0; k=((k-1) & cpy)){
                    ans[i+1][k+j] = max(sum + ans[i][k], ans[i+1][k+j]);
                }
                ans[i+1][j] = max(sum, ans[i+1][j]);
            }
            for(int j=0; j<pwn; j++){
                long long cpy = j;
                for(int k=0; k<n; k++){
                    cpy = ((cpy%2)*pwn + cpy)/2;
                    ans[i+1][j] = max(ans[i+1][cpy], ans[i+1][j]);
                }
                //cout << ans[i+1][j] << " ";
            }//cout << endl;
        }
        cout << ans[min(n, m)][pwn-1] << endl;
    }
}