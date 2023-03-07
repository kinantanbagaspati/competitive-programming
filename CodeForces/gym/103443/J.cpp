#include <bits/stdc++.h>
using namespace std;
#define pll pair<long long, long long>

long long l, n, s, p, ans;

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin >> l;
    while(l--){
        cin >> n >> s >> p;
        for(int i=0; i<s; i++){
            cin >> ans;
        }
        ans = 0;
        ans += (p-s)*(n-1)*2;
        ans += (s-1)*(n-1);
        ans += p*(n-p);
        ans += (n-p-1)*(n-1);
        cout << 2*ans << endl;
    }
}
