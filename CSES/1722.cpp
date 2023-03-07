#include <bits/stdc++.h>
using namespace std;

long long mod = 1000000007;
long long pangkat(long long a, long long b){
    long long res = 1;
    b %= (mod-1);
    while(b>0){
        if(b%2){res = res*a%mod;}
        a = a*a%mod; b /= 2;
    }
    return res;
}
long long inv(long long a){
    return pangkat(a, mod-2);
}

long long precomp[100][4];

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    precomp[0][0] = 1;
    precomp[0][1] = 1;
    precomp[0][2] = 1;
    precomp[0][3] = 0;
    for(int i=1; i<100; i++){
        precomp[i][0] = (precomp[i-1][0]*precomp[i-1][0] + precomp[i-1][1]*precomp[i-1][2])%mod;
        precomp[i][1] = (precomp[i-1][0]*precomp[i-1][1] + precomp[i-1][1]*precomp[i-1][3])%mod;
        precomp[i][2] = (precomp[i-1][2]*precomp[i-1][0] + precomp[i-1][3]*precomp[i-1][2])%mod;
        precomp[i][3] = (precomp[i-1][2]*precomp[i-1][1] + precomp[i-1][3]*precomp[i-1][3])%mod;
    }
    long long n, ans[4] = {1,0,0,1}, cpy[4], idx=0;
    cin >> n;
    n--;
    while(n>0){
        if(n%2){
            cpy[0] = (ans[0]*precomp[idx][0] + ans[1]*precomp[idx][2])%mod;
            cpy[1] = (ans[0]*precomp[idx][1] + ans[1]*precomp[idx][3])%mod;
            cpy[2] = (ans[2]*precomp[idx][0] + ans[3]*precomp[idx][2])%mod;
            cpy[3] = (ans[2]*precomp[idx][1] + ans[3]*precomp[idx][3])%mod;
            for(int i=0; i<4; i++){ans[i] = cpy[i];}
        }
        idx++;
        n /= 2;
    }
    if(n<0){
        cout << 0 << endl;
    }else{
        cout << ans[0] << endl;
    }
}
