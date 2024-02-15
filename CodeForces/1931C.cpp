#include<bits/stdc++.h>
using namespace std;
#define pll pair<long long, long long>

const long long maxn = 262144;
long long t, n, a[maxn], kiri, kanan;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--){
        cin >> n;
        for(int i=0; i<n; i++){
            cin >> a[i]; 
        }
        kiri = 0;
        while(kiri<n && a[kiri] == a[0]) kiri++;
        kanan = n-1;
        while(kanan>=0 && a[kanan] ==  a[n-1]) kanan--; 
        
        //cout << "hei " << kiri << " " << kanan << endl;
        if(a[0] != a[n-1]){
            cout << min(n-kiri, kanan+1) << endl;
        }else if(kanan < 0){
            cout << 0 << endl;
        }else{
            cout << kanan-kiri+1 << endl;
        }
    }
}