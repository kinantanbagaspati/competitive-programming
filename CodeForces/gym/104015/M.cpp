#include <bits/stdc++.h>
using namespace std;
#define pll pair<long long, long long>

const long long maxn = 1024, mod[3] = {1e9+7, 998244353, 104206969};
string str, xtr;
long long pw10[maxn][3], inv10[maxn][3], prefix[maxn][3];
long long x[3], len, n;
map<long long, int> m[3];
long long comp[2], idx;

long long pangkat(long long a, long long b, long long m){
    long long res = 1;
    while(b>0){
        if(b%2){res = res*a%m;}
        a = a*a%m; b /= 2;
    }
    return res;
}
long long inv(long long a, long long m){
    return pangkat(a, m-2, m);
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin >> str; n = str.length();
    for(int i=0; i<3; i++){
        pw10[0][i] = 1; inv10[0][i] = 1;
        prefix[n][i] = 0; x[i] = 0;
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<3; j++){
            pw10[i+1][j] = 10 * pw10[i][j] % mod[j];
            inv10[i+1][j] = inv(pw10[i+1][j], mod[j]);
            prefix[n-1-i][j] = (pw10[i][j] * (str[n-1-i] - '0') + prefix[n-i][j]) % mod[j];
            //cout << prefix[n-1-i][j] << " ";
        }//cout << endl;
    }

    cin >> xtr;
    len = xtr.length();
    for(int i=0; i<len; i++){
        for(int j=0; j<3; j++){
            x[j] = (10 * x[j] + (xtr[i] - '0')) % mod[j];
            //cout << x[j] << " ";
        }//cout << endl;
    }
    bool nemu;
    for(int i=1; i<n; i++){

        if(i >= len){
            nemu = true;
            for(int j=0; j<3; j++){
                comp[0] = (prefix[i-len][j]+mod[j]-prefix[i][j]) % mod[j] * inv10[n-i][j] % mod[j];

                comp[0] = (x[j]+mod[j]-comp[0]) % mod[j];

                nemu = nemu && m[j].count(comp[0]);
            }
            if(nemu){
                cout << i-len << " " << i << endl;
                cout << i+1 << " " << m[2][comp[0]] << endl;
            }
        }
        if(n-i >= len){
            nemu = true;

            for(int j=0; j<3 && nemu; j++){
                comp[1] = prefix[i] * pw10[len] % mod[j];
                comp[1] = (prefix[i+len] + mod[j] - comp[1]) % mod[j];
                comp[1] = (x[j]+mod[j]-comp[1]) % mod[j];

                nemu = nemu && m[j].count(comp[1]);
                //nemu = nemu && m[j][(x[j]+mod[j]-comp[1]) % mod[j]] ==
            }
            if(nemu){
                cout << m[2][comp[1]]+1 << " " << i << endl;
                cout << i+1 << " " << i+len << endl;
            }
        }
        if(len > 1 && i >= len-1 && n-i >= len-1){
            nemu = true;
            for(int j=0; j<3; j++){
                comp[0] = prefix[i-len+1] * pw10[len-1] % mod[j];
                comp[0] = (prefix[i] + mod[j] - comp[0]) % mod[j];
                comp[1] = prefix[i] * pw10[len-1] % mod[j];
                comp[1] = (prefix[i+len-1] + mod[j] - comp[1]) % mod[j];
                nemu = nemu && ((comp[0]+comp[1]) % mod[j] == x[j]);
            }
            if(nemu){
                cout << i-len+2 << " " << i << endl;
                cout << i+1 << " " << i+len-1 << endl;
                return 0;
            }
        }

    }
}
