#include<bits/stdc++.h>
using namespace std;
#define pll pair<long long, long long>

long long t, n, k;

long long sumDigit(long long x){
    long long ret = 0;
    while(x>0){
        ret += x%10; x/=10;
    }
    return ret;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--){
        cin >> n >> k;
        while(sumDigit(n)%k){
            n++;
        }
        cout << n << endl;
    }
}
