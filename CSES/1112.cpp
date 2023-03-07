#include <bits/stdc++.h>
using namespace std;

const long long mod = 1e9+7;
long long n, m, k, to[101][26], dp[1010][101];
string s, t;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n >> s;
    m = s.length();
    for(int i=0; i<m; i++){
        t = s.substr(0,i) + "A";
        for(int j=0; j<26; j++){
            to[i][j] = 0;
            k = i+1;
            while(!to[i][j] && k > 0){
                if(t.substr(i+1-k, k) == s.substr(0,k)){
                    to[i][j] = k;
                }else{k--;}
            }
            //cout << to[i][j] << " ";
            t[i]++;
        }//cout << endl;
    }
    for(int i=0; i<26; i++){
        to[m][i] = m;
    }
    dp[0][0] = 1;
    for(int i=1; i<=m; i++){
        dp[0][i] = 0;
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<=m; j++){
            //cout << dp[i][j] << " ";
            for(int l=0; l<26; l++){
                dp[i+1][to[j][l]] += dp[i][j];
                dp[i+1][to[j][l]] %= mod;
            }
        }//cout << endl;
    }
    cout << dp[n][m] << endl;
}
