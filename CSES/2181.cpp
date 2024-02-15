#include <bits/stdc++.h>
using namespace std;

const long long maxnm = 1024, mod = 1e9+7;
long long n, m, dp[maxnm][maxnm];
vector<long long> al[maxnm];

void recAL(int startval, int prvbit){
    for(int i=startval; i<=n-2; i++){
        int bitval = prvbit + (1<<i) + (1<<(i+1));
        for(int j=0; j<(1<<n); j++){
            if((bitval & j) == 0){
                al[j].push_back((1<<n)-1-bitval-j);
            }
        }
        recAL(i+2, bitval);
    }
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n >> m;

    recAL(0, 0);

    // no vertikal
    for(int i=0; i<(1<<n); i++){
        al[i].push_back((1<<n)-1-i);
        /* debug
        cout << i << ':';
        for(int j=0; j<al[i].size(); j++){
            cout << ' ' << al[i][j];
        } cout << endl;*/
    }
    //cout << endl;

    // ngitung dp
    dp[0][0] = 1;
    for(int i=0; i<m; i++){
        for(int j=0; j<(1<<n); j++){
            for(int k=0; k<al[j].size(); k++){
                dp[i+1][al[j][k]] = (dp[i+1][al[j][k]] + dp[i][j]) % mod;
            }
        }
        /*for(int j=0; j<(1<<n); j++){
            cout << dp[i+1][j] << ' ';
        }cout << endl;*/
    }
    //cout << endl;
    cout << dp[m][0] << endl;
}
