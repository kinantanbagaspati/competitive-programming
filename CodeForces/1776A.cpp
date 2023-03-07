#include<bits/stdc++.h>
using namespace std;
#define pll pair<long long, long long>

long long t, n, prv, nxt, jalan;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    // tes fft
    cin >> t;
    while(t--){
        cin >> n;
        prv = 0; jalan = 0;
        for(int i=0; i<n; i++){
            cin >> nxt;
            jalan += (nxt-prv)/120;
            prv = nxt;
        }
        jalan += (1440-prv)/120;
        if(jalan >= 2){
            cout << "YES" << endl;
        }else{
            cout << "NO" << endl;
        }
    }
}
