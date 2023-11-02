#include <bits/stdc++.h>
using namespace std;
#define pll pair<long long, long long>

const long long maxn = 65536;
long long m, lo, hi, dp[maxn][4];
char c;
string ord = "ATGC", s;
pll srt[4];

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin >> s >> m;
    for(int i=0; i<4; i++){
        dp[0][i] = 0;
    }
    for(int i=0; i<s.length(); i++){
        for(int j=0; j<4; j++){
            dp[i+1][j] = dp[i][j] + (s[i] == ord[j]);
        }
    }
    while(m--){
        cin >> lo >> hi;
        for(int i=0; i<4; i++){
            srt[i] = {dp[lo-1][i] - dp[hi][i], i};
        }
        sort(srt, srt+4);
        for(int i=0; i<4; i++){
            cout << ord[srt[i].second];
        }cout << endl;
    }
}
