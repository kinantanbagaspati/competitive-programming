#include<bits/stdc++.h>
using namespace std;

const int maxn = 1024;
int wp[maxn];
int n, m, dp[maxn][maxn], table[10][10][maxn][maxn];
int t, atas, kiri, bawah, kanan;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    for(int i=0; i<10; i++){
        for(int j=(1<<i); j<(1<<(i+1)); j++){
            wp[j] = i;
        }
    }
    // input
    cin >> n >> m;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            cin >> dp[i][j];
            dp[i][j] += dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1];
        }
    }
    // precompute jawaban
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            int lo = 0, hi = maxn;
            while(hi-lo>1){
                int mid = (lo+hi)/2;
                if(i+mid<=n && j+mid<=m && dp[i+mid][j+mid] - dp[i+mid][j] - dp[i][j+mid] + dp[i][j] == mid*mid){
                    lo = mid;
                }else{
                    hi = mid;
                }
            }
            table[0][0][i][j] = lo;
            //cout << table[0][0][i][j] << " ";
        } //cout << endl;
    }
    // precompute sparse table
    for(int b=1; b<10; b++){
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                table[0][b][i][j] = max(table[0][b-1][i][j], table[0][b-1][i][min((1<<(b-1))+j, maxn-1)]);
            }
        }
    }
    for(int a=1; a<10; a++){
        for(int b=0; b<10; b++){
            for(int i=0; i<n; i++){
                for(int j=0; j<m; j++){
                    table[a][b][i][j] = max(table[a-1][b][i][j], table[a-1][b][min((1<<(a-1))+i, maxn-1)][j]);
                }
            }
        }
    }
    /*cout << "sparse 2" << endl;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cout << table[1][1][i][j] << " ";
        } cout << endl;
    }*/
    cin >> t;
    while(t--){
        cin >> atas >> kiri >> bawah >> kanan; 
        atas--; kiri--;
        int lo = 0, hi = min(bawah-atas, kanan-kiri)+1;
        while(hi-lo>1){
            int mid = (lo+hi)/2;
            int wpx = wp[bawah-atas-mid+1];
            int wpy = wp[kanan-kiri-mid+1];
            int maxsz = max({
                table[wpx][wpy][atas][kiri],
                table[wpx][wpy][atas][kanan-mid+1-(1<<wpy)],
                table[wpx][wpy][bawah-mid+1-(1<<wpx)][kiri],
                table[wpx][wpy][bawah-mid+1-(1<<wpx)][kanan-mid+1-(1<<wpy)]
            });
            if(maxsz >= mid){
                lo = mid;
            }else{
                hi = mid;
            }
        }
        cout << lo << endl;
    }
}

