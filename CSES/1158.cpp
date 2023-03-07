#include <bits/stdc++.h>
using namespace std;

long long ans[100069];
void init(){
    for(int i=0; i<100069; i++){
        ans[i] = 0;
    }
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    long long n, x;
    cin >> n >> x;
    long long h[n], s[n];
    for(int i=0; i<n; i++){
        cin >> h[i];
    }
    init();
    for(int i=0; i<n; i++){
        cin >> s[i];
        for(int j=x; j>=h[i]; j--){
            ans[j] = max(ans[j], ans[j-h[i]] + s[i]);
        }
    }
    cout << ans[x] << endl;
}
