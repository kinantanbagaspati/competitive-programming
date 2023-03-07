#include<bits/stdc++.h>
using namespace std;
#define pll pair<long long, long long>

long long t, n, m, a, b;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--){
        cin >> a >> b >> n >> m;
        cout << min(n*b, n/(m+1)*m*a + n%(m+1)*min(a, b)) << endl;
    }
}
