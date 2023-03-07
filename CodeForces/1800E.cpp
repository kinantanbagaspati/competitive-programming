#include<bits/stdc++.h>
using namespace std;
#define pll pair<long long, long long>

long long t, n, k;
string atas, bawah;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--){
        cin >> n >> k >> atas >> bawah;
        bool ans = true;
        for(int i=max(0LL,n-k); i<min(n,k); i++){
            ans = (atas[i] == bawah[i]) && ans;
        }
        sort(atas.begin(), atas.end());
        sort(bawah.begin(), bawah.end());
        if(ans && (atas == bawah)){
            cout << "YES" << endl;
        }else{
            cout << "NO" << endl;
        }

    }
}
