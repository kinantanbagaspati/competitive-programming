#include <bits/stdc++.h>
using namespace std;

long long t, n, k, m[101];
bool ans[1000069];

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n >> k;
    for(int i=0; i<k; i++){
        cin >> m[i];
    }
    for(int i=0; i<=n; i++){
        for(int j=0; j<k; j++){
            if(i >= m[j] && !ans[i-m[j]]){
                ans[i] = true;
            }
        }
        if(i>0){
            if(ans[i]){cout << 'W';}
            else{cout << 'L';}
        }
    }
}
