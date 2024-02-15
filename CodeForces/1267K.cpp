#include<bits/stdc++.h>
using namespace std;
#define pll pair<long long, long long>

long long t, k, n, idx, sum, cur0, cur1;
long long freq[32], c[32][32];
void init(){
    for(int i=0; i<16; i++){
        c[i][0] = 1; c[i][i] = 1;
        for(int j=0; j<i; j++){
            c[i][j] = c[i-1][j-1] + c[i-1][j];
        }
    }
}
long long choose(long long a, long long b){
    //cout << a << " choose " << b << endl;
    if(b<0 || a<b){
        return 0;
    } return c[a][b];
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    init();
    cin >> t;
    while(t--){
        cin >> k;
        for(idx=2; k>0; idx++){
            //cout << "dibagi " << i << ": " << k/i << " sisa " << k%i << endl;
            freq[k%idx]++; k/=idx;
        }
        //cout << idx << endl;
        idx--; cur0 = 1; sum = 0;
        for(int i=idx-1; i>0; i--){
            cur0 *= choose(idx-i-sum, freq[i]);
            sum += freq[i];
        }
        //cout << "cur0 " << cur0 << endl;
        cur1 = 1; sum = 0;
        for(int i=idx-1; i>0; i--){
            cur1 *= choose(idx-i-1-sum, freq[i]);
            sum += freq[i];
        }
        //cout << "cur1 " << cur1 << endl;
        cout << cur0-cur1-1 << endl;
        for(int i=0; i<=idx; i++){
            freq[i] = 0;
        }
    }
}