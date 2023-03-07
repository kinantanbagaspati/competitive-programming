#include <bits/stdc++.h>
using namespace std;

long long spars[20][200069];

long long query(long long l, long long r){
    if(l>r){
        return 1e18;
    }
    long long pow=0;
    while((r-l+1)%(1<<(pow+1)) == 0){
        pow++;
    }
    return min(spars[pow][l], query(l+(1<<pow), r));
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    long long n, q;
    cin >> n >> q;
    for(int i=0; i<n; i++){
        cin >> spars[0][i];
    }
    for(int i=1; (1<<i)<=n; i++){
        for(int j=0; j<=n-(1<<i); j++){
            spars[i][j] = min(spars[i-1][j], spars[i-1][j+(1<<(i-1))]);
        }
    }
    long long l, r;
    while(q--){
        cin >> l >> r;
        cout << query(l-1, r-1) << endl;
    }
}
