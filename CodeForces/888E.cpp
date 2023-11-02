#include<bits/stdc++.h>
using namespace std;
#define pll pair<long long, long long>

const long long maxn = 36;
long long n, m, a[maxn], kiri[1<<(maxn/2)], kanan[1<<(maxn/2)];

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n >> m;
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    long long nkiri = (1<<(n/2));
    for(int i=0; i<nkiri; i++){
        int cpy = i;
        long long sum = 0;
        for(int j=0; j<n/2; j++){
            if(cpy%2){
                sum = (sum + a[j]) % m;
            }
            cpy /= 2;
        }
        kiri[i] = sum;
        //cout << "kiri " << i << ": " << sum << endl;
    }
    sort(kiri, kiri + nkiri);
    long long nkanan = (1<<((n+1)/2));
    for(int i=0; i<nkanan; i++){
        int cpy = i;
        long long sum = 0;
        for(int j=n/2; j<n; j++){
            if(cpy%2){
                sum = (sum + a[j]) % m;
            }
            cpy /= 2;
        }
        kanan[i] = sum;
        //cout << "kanan " << i << ": " << sum << endl;
    }
    sort(kanan, kanan + nkanan);

    long long ans = (kiri[nkiri-1] + kanan[nkanan-1]) % m;
    nkanan--;
    for(int i=0; i<nkiri && nkanan>=0; i++){
        while(nkanan>=0 && kiri[i] + kanan[nkanan] >= m){
            nkanan--;
        }
        if(nkanan>=0){
            ans = max(kiri[i] + kanan[nkanan], ans);
        }
    }
    cout << ans << endl;
}