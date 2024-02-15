#include<bits/stdc++.h>
using namespace std;

const int maxn = 5050;
int n, m=0, a[maxn], dp[maxn][maxn];

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> a[i];
        for(int j=0; j<i; j++){
            dp[i][j] = (a[i] < a[j])*2 - 1;
            m += (a[i] < a[j]);
        }
    }
    for(int i=0; i<n; i++){
        // kiri
        int cur = 0;
        for(int j=i-2; j>=0; j--){
            cur += (a[i] < a[j+1])*2 - 1;
            dp[i][j] += cur;
        }
        // kanan
        cur = 0;
        for(int j=i+2; j<n; j++){
            cur += (a[i] > a[j-1])*2 - 1;
            dp[j][i] += cur;
        }
    }
    int nb = m, cnt = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<i; j++){
            if(m - dp[i][j] < nb){
                nb = m - dp[i][j]; cnt = 1;
            }else if(m - dp[i][j] == nb){
                cnt++;
            }
        }
    }
    cout << nb << " " << cnt << endl;
}