#include <bits/stdc++.h>
using namespace std;


int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    long long n, q;
    cin >> n >> q;
    long long x[n], pre[n+1];
    pre[0] = 0;
    for(int i=0; i<n; i++){
        cin >> x[i];
        pre[i+1] = pre[i] + x[i];
    }
    long long a, b;
    while(q--){
        cin >> a >> b;
        cout << pre[b] - pre[a-1] << endl;
    }
}
