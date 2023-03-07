#include <bits/stdc++.h>
using namespace std;
#define pll pair<long long, long long>

long long pw[16], ki, kj, kanan;

long long dummy[16];
long long singleBrute(long long k){
    long long res = 0;
    for(int i=0; i<16 && k>0; i++){
        dummy[i] = k%10;
        for(int j=0; j<i; j++){
            res += (dummy[j] > dummy[i]);
        }
        k /= 10;
    }
    return res;
}
long long batchBrute(long long k){
    long long res = 0;
    for(int i=1; i<=k; i++){
        res += singleBrute(i);
    }
    return res;
}

long long ngitung(long long k){
    long long res = 0;
    for(int i=1; pw[i] <= k; i++){
        ki = k / pw[i] % 10;
        //cout << "ki " << ki << endl;
        kanan = k % pw[i];
        //2 2 nya bebas
        res += k / pw[i+1] * 45 * pw[i-1] * i;

        //cout << "res0 " << res << endl;
        // pilihan kanannya bebas
        if(k >= pw[i+1] && ki == 0){
            res -= 9 * pw[i-1] * i;
        }
        //cout << "res1 " << res << endl;
        for(int j=1; j<ki; j++){
            res += pw[i-1] * (9-j) * i;
        }
        //cout << "res2 " << res << endl;
        // pilihan kiri pasti ki
        for(int j=0; j<i; j++){
            kj = k / pw[j] % 10;
            //cout << "kj " << kj << endl;
            // pilihan kanan masih bebas
            res += kanan / pw[j+1] * (9-ki) * pw[j];
            // pilihan kanan udh ga bebas
            res += max(0ll, kj-1-ki) * pw[j];
            // pilihan kanan fix kj
            if(kj > ki){
                res += kanan % pw[j] + 1;
            }
        }
    }
    return res;
}

long long t, x, y;

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    pw[0] = 1;
    for(int i=1; i<16; i++){
        pw[i] = 10*pw[i-1];
    }


    //cout << ngitung(199) << endl;
    //cout << ngitung(200) << endl;

    for(int i=995; i<1005; i++){
         //cout << i << ": " << ngitung(i) << " " << batchBrute(i) << endl;
    }
    //cout << "99: " << ngitung(99) << endl;

    cin >> t;
    for(int tt=1; tt<=t; tt++){
        cin >> x >> y;
        cout << "Case " << tt << ": " << ngitung(y) - ngitung(x-1) << endl;
    }
}
