#include <bits/stdc++.h>
using namespace std;

long long com[2000000];

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    long long n, k, p, pow=1;
    cin >> n >> k;
    com[0] = -n;
    long long ans = 0;
    for(int i=0; i<k; i++){
        cin >> p;
        for(int j=0; j<pow; j++){
            com[j+pow] = -com[j]/p;
            ans += com[j+pow];
        }
        pow *= 2;
    }
    cout << ans << endl;
}
