#include<bits/stdc++.h>
using namespace std;
#define pll pair<long long, long long>

int t, n, a[256];

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--){
        cin >> n;
        for(int i=0; i<n*2; i++){
            cin >> a[i];
        }
        sort(a, a+n*2);
        cout << a[n-1]-a[0] + a[n*2-1]-a[n] << endl;
        for(int i=0; i<n; i++){
            cout << a[i] << ' ' << a[n+i] << endl;
        }
    }
}
