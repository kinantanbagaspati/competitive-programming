#include<bits/stdc++.h>
using namespace std;
#define pll pair<long long, long long>

const long long maxn = 262144;
long long t, n, m, kiri, kanan, sama;
pll toSort[maxn];

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--){
        cin >> n >> m;
        sama = 0;
        for(int i=0; i<m*2; i++){
            cin >> kiri >> kanan;
            kiri--; kanan--;
            if(kiri < kanan){
                toSort[sama] = {kanan - kiri + 1, kanan};
                sama++;
            }
        }
        if(sama < m){
            cout << -1 << endl;
        }else if(sama == m){
            for(int i=0; i<n; i++){
                cout << "1 ";
            }cout << endl;
        }else{
            sort(toSort, toSort + sama);
            long long batas = toSort[sama - m - 1].second;
            long long mod = toSort[sama - m - 1].first;
            //cout << "batas mod: " << batas << ' ' << mod << endl;
            for(int i=0; i<n; i++){
                if(i > batas){
                    cout << mod - 1 - (i - 1 - batas) % (mod - 1) << ' ';
                }else{
                    cout << (batas - i) % mod + 1 << ' ';
                }
            } cout << endl;
        }
    }
}