#include<bits/stdc++.h>
using namespace std;
#define pll pair<long long, long long>

int t, n, k, a[262144];

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--){
        cin >> n >> k;
        int cur = 1;
        for(int i=0; i<k; i++){
            for(int j=i; j<n; j+=k){
                a[j] = cur; cur++;
            }
        }
        for(int i=0; i<n; i++){
            cout << a[i] << ' ';
        } cout << endl;
    }
}