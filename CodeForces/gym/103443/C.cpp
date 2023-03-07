#include <bits/stdc++.h>
using namespace std;
#define pll pair<long long, long long>

const int maxn = 1024;
int t, n, dp[maxn][maxn], sumdp[maxn][maxn], sum, cursum;
int kiri, kanan, maxsum;
string atas, bawah;

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--){
        cin >> n;
        cin >> atas >> bawah;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                dp[i][j] = (atas[i] == bawah[j]);
                sumdp[i][j] = dp[i][j];
                if(i>0 && j<n-1){
                    sumdp[i][j] += sumdp[i-1][j+1];
                }
                //cout << dp[i][j] << ":" << sumdp[i][j] << " ";
            }//cout << endl;
        }
        maxsum = 0;
        for(int i=0; i<n; i++){
            sum = 0;
            for(int j=i; j<n; j++){
                sum += dp[j][j];
                cursum = sumdp[j][i];
                if(i>0 && j<n-1){
                    cursum -= sumdp[i-1][j+1];
                }
                if(maxsum < cursum-sum){
                    maxsum = cursum-sum;
                    kiri = i; kanan = j;
                    //cout << "cursum, sum " << cursum << " " << sum << endl;
                    //cout << "batas " << kiri << " " << kanan << endl;
                }else if(maxsum == cursum-sum){
                    if(j-i < kanan-kiri){
                        kiri = i; kanan = j;
                    }
                }
            }
        }
        sum = 0;
        for(int i=0; i<n; i++){
            sum += dp[i][i];
        }

        cout << sum << " " << sum+maxsum << " " << kiri+1 << " " << kanan+1 << endl;
    }
}
