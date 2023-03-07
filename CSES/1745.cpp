#include <bits/stdc++.h>
using namespace std;

bool ans[100001];
long long cnt = 0;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ans[0] = true;
    for(int i=0; i<100000; i++){
        ans[i+1] = false;
    }
    long long n, x;
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> x;
        for(int j=100000; j>=x; j--){
            if(ans[j-x] && !ans[j]){ans[j] = true; cnt++;}
        }
    }
    cout << cnt << endl;
    for(int i=1; i<100001; i++){
        if(ans[i]){cout << i << " ";}
    }cout << endl;
}
