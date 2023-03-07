#include <bits/stdc++.h>
using namespace std;


int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    long long q, k;
    cin >> q;
    while(q--){
        cin >> k;
        long long mul = 9, digs = 1;
        while(k > mul*digs){
            k -= mul*digs;
            mul *= 10;
            digs++;
        }
        mul /=9;
        long long ans = mul;
        ans += (k-1)/digs;
        for(int i=0; i<(k-1)%digs; i++){
            mul /= 10;
        }
        cout << ans/mul%10 << endl;
    }
}
