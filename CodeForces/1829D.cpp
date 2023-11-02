#include<bits/stdc++.h>
using namespace std;

int t, n, m;
char c;

void solve(int n, int m){
    int g = __gcd(n, m), p2 = 0, p3 = 0;
    n /= g; m /= g;
    while(n > 1){
        if(n % 3 == 0){
            p3++; n /= 3;
        }else{
            cout << "NO" << endl;
            return;
        }
    }
    while(m > 1){
        if(m % 2 == 0){
            p2++; m /= 2;
        }else{
            cout << "NO" << endl;
            return;
        }
    }
    if(p3 >= p2){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
    }
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--){
        cin >> n >> m;
        solve(n, m);
    }
}