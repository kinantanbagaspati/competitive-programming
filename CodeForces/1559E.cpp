#include<bits/stdc++.h>
using namespace std;
#define pll pair<long long, long long>

const long long maxn = 69, maxm = 100069, mod = 998244353;
long long n, m, batas[maxn][2], sack[2][maxm];
int mobius[maxm];
bool isComp[maxm];

void sieve(){
    mobius[0] = 0;
    for(long long i=1; i<maxm; i++){
        mobius[i] = 1;
    }

    isComp[0] = true; isComp[1] = true;
    for(long long i=2; i<maxm; i++){
        if(!isComp[i]){ // i prima
            for(long long j=i; j<maxm; j+=i){
                isComp[j] = (j>i);
                mobius[j] *= -1;
            }
            for(long long j=i*i; j<maxm; j+=i*i){
                mobius[j] = 0;
            }
        }
    }
    /*
    for(int i=1; i<=30; i++){
        cout << i << ": " << mobius[i] << endl;
    }
    */
}

void knapsack(int bawah, int atas, int jum){
    //cout << "knapsack " << bawah << "-" << atas << ": " << jum << endl;
    for(int i=0; i<=jum; i++){
        sack[0][i] = (sack[1][max(0, i-bawah+1)] + mod - sack[1][max(0, i-atas)]) % mod;
    }
    sack[1][0] = 0;
    for(int i=0; i<=jum; i++){
        sack[1][i+1] = (sack[1][i] + sack[0][i]) % mod;
    }
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    sieve();
    cin >> n >> m;
    for(int i=0; i<n; i++){
        cin >> batas[i][0] >> batas[i][1];
    }

    long long ans = 0;
    for(int i=1; i<=m; i++){
        int mi = m/i;

        sack[0][0] = 1;
        for(int j=1; j<=mi; j++){
            sack[0][j] = 0;
        }
        sack[1][0] = 0;
        for(int j=0; j<=mi; j++){
            sack[1][j+1] = 1;
        }

        for(int j=0; j<n; j++){
            knapsack((batas[j][0]+i-1)/i, batas[j][1]/i, mi);
        }
        ans = (ans + mod + sack[1][mi+1] * mobius[i]) % mod;

    }
    cout << ans << endl;
}
