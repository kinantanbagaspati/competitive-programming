#include <bits/stdc++.h>
using namespace std;
#define pii pair<int, int>

const int maxn = 1e4+10;
int n, amin, amax, a[maxn];
int dp[2][maxn];
int nbstack[2], pos[2][maxn], dpval[2][maxn];
// utils
int curmax;

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    cin >> n;
    amin = 1e9; amax = -1e9;
    for(int i=0; i<n; i++){
        cin >> a[i];
        amin = min(amin, a[i]);
        amax = max(amax, a[i]);
        dp[0][i] = amax - amin;
    }
    cout << dp[0][n-1] << endl;
    for(int i=1; i<n; i++){
        // kosonging stacknya
        nbstack[0] = 0;
        nbstack[1] = 0;

        cout << "ngitung " << i+1 << ": " << endl;
        for(int j=0; j<n; j++){
            dp[i%2][j] = 0;

            // stack 0 isinya convex hull lower
            curmax = dp[(i+1)%2][j] + a[j];
            while(nbstack[0] > 0 && a[pos[0][nbstack[0]-1]] > a[j]){
                nbstack[0]--; //keluarin stacknya
                // yg disimpen di dpval itu max dari dp + a[pos] nya
                dp[i%2][j] = max(dpval[0][nbstack[0]] - a[j], dp[i%2][j]);
                curmax = max(dpval[0][nbstack[0]] + a[j] - a[pos[0][nbstack[0]]], curmax);
            }
            // masukin hull
            cout << "masukin " << pos[0]
            pos[0][nbstack[0]] = j;
            dpval[0][nbstack[0]] = curmax;
            nbstack[0]++;

            // stack 1 isinya convex hull upper
            curmax = dp[(i+1)%2][j] - a[j];
            while(nbstack[1] > 0 && a[pos[1][nbstack[1]]] < a[j]){
                nbstack[1]--;
                // yg disimpen di dpval itu max dari dp + a[pos] nya
                dp[i%2][j] = max(dpval[1][nbstack[1]] + a[j], dp[i%2][j]);
                curmax = max(dpval[1][nbstack[1]] + a[pos[1][nbstack[1]]] - a[j], curmax);
            }
            // masukin hull
            pos[1][nbstack[1]] = j;
            dpval[1][nbstack[1]] = curmax;
            nbstack[1]++;

            cout << dp[i%2][j] << " ";
        }
        cout << endl;
    }

}
