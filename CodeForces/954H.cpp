#include<bits/stdc++.h>
using namespace std;

const long long mod = 1e9+7, maxn = 5005;
long long n, a[maxn], pra[maxn];
int dp[maxn*2][maxn];
long long ans[maxn*2];

long long pangkat(long long a, long long b){
    long long ret = 1;
    while(b>0){
        if(b%2){
            ret = ret*a%mod;   
        }
        a = a*a%mod; b/=2;
    }
    return ret;
}
long long inverse(long long a){
    return pangkat(a, mod-2);
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n;
    pra[0] = 1;
    // premul
    for(int i=1; i<n; i++){
        cin >> a[i];
        pra[i] = pra[i-1] * a[i] % mod;
    }
    // kali buat presum
    for(int i=1; i<n; i++){
        for(int j=1; j<n; j++){
            dp[i+j][i] = pra[i] * pra[j] % mod;
        }
    }
    //cout << "DP" << endl;
    for(int i=2; i<=n*2-2; i++){
        //cout << i << ":";
        for(int j=1; j<min(i, (int)n); j++){
            //cout << " " << dp[i][j];
            dp[i][j] = (dp[i][j] + dp[i][j-1]) % mod;
        } //cout << endl;
    } //cout << endl;
    // ngitung jawaban
    for(int i=1; i<n; i++){
        //cout << i << ":" << endl;
        for(int j=i; j<n; j++){
            ans[j-i+1] = (ans[j-i+1] + pra[j]) % mod;
        }
        long long inv = inverse(pra[i]);
        for(int j=2; j<=(n-i)*2; j++){
            long long tambah = (long long) (dp[i*2+j-2][min(i+j-2, (int)n-1)] + mod - dp[i*2+j-2][i-1]) * inv % mod * (a[i]-1) % mod;
            //cout << i << "-" << j << " " << i+j-2 << "-" << i-1 << endl;
            //cout << dp[i*2+j-2][i+j-2] << " - " << dp[i*2+j-2][i-1] << " / " << pra[i] << " * " << a[i]-1 << endl;
            //cout << "nambah " << tambah << endl;
            if(tambah%2) tambah += mod;
            ans[j] = (ans[j] + tambah/2) % mod;
        }
        //cout << endl;
    }
    
    for(int i=1; i<=n*2-2; i++){
        cout << ans[i] << ' ';
    } cout << endl;
}

