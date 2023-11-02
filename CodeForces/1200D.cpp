#include<bits/stdc++.h>
using namespace std;

const int maxn = 2048;
int n, k, row[maxn][2], col[maxn][2];
int kiri, kanan, atas, bawah;
int dp[maxn][maxn], ans[maxn][maxn], maxans;
char c;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n >> k;
    for(int i=0; i<n; i++){
        row[i][0] = n; row[i][1] = -1;
        col[i][0] = n; col[i][1] = -1;
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> c;
            if(c == 'B'){
                row[i][0] = min(row[i][0], j); row[i][1] = max(row[i][1], j);
                col[j][0] = min(col[j][0], i); col[j][1] = max(col[j][1], i);
            }
        }
    }
    for(int i=0; i<n; i++){
        //cout << "row " << i << ": " << row[i][0] << "-" << row[i][1] << endl;
        if(row[i][0] == n && row[i][1] == -1){
            dp[0][0]++;
        }else{
            kiri = max(row[i][1]-k+1, 0); kanan = row[i][0];
            atas = max(i-k+1, 0); bawah = i;
            //cout << "kiri kanan atas bawah row " << i << endl;
            //cout << kiri << " " << kanan << " " << atas << " " << bawah << endl;
            if(kiri <= kanan){
                dp[atas][kiri]++; dp[bawah+1][kanan+1]++;
                dp[atas][kanan+1]--; dp[bawah+1][kiri]--;
            }
        }
        //cout << "col" << i << ": " << col[i][0] << "-" << col[i][1] << endl;
        if(col[i][0] == n && col[i][1] == -1){
            dp[0][0]++;
        }else{
            kiri = max(i-k+1, 0); kanan = i;
            atas = max(col[i][1]-k+1, 0); bawah = col[i][0];
            //cout << "kiri kanan atas bawah col " << i << endl;
            //cout << kiri << " " << kanan << " " << atas << " " << bawah << endl;
            if(atas <= bawah){
                dp[atas][kiri]++; dp[bawah+1][kanan+1]++;
                dp[atas][kanan+1]--; dp[bawah+1][kiri]--;
            }
        }
    }
    /*for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout << dp[i][j] << " ";
        } cout << endl;
    }
    cout << endl;*/
    maxans = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            ans[i][j] = dp[i][j];
            if(i>0){ans[i][j] += ans[i-1][j];}
            if(j>0){ans[i][j] += ans[i][j-1];}
            if(i>0 && j>0){ans[i][j] -= ans[i-1][j-1];}
            maxans = max(ans[i][j], maxans);
            //cout << ans[i][j] << " ";
        }//cout << endl;
    }
    cout << maxans << endl;
}