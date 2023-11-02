#include<bits/stdc++.h>
using namespace std;
#define pll pair<long long, long long>

long long t, n, a[16], ans;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--){
        cin >> n; 
        for(int i=0; i<n; i++){
            cin >> a[i];
        }
        sort(a, a+n);
        ans = a[0]+1;
        for(int i=1; i<n; i++){
            ans *= a[i];
        }
        cout << ans << endl;
    }
}