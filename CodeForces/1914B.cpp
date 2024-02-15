#include<bits/stdc++.h>
using namespace std;
#define pll pair<long long, long long>

int t, n, k;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--){
        cin >> n >> k;
        while(n>k+1){
            cout << n << ' '; n--;
        }
        for(int i=1; i<=k+1; i++){
            cout << i << ' ';
        }
        cout << endl;
    }
}