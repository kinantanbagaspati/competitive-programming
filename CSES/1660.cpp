#include <bits/stdc++.h>
using namespace std;

const long long maxn = 200069;
long long n, x, a[maxn];
long long sum = 0, ans = 0;
map<long long, long long> m;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n >> x;
    m[0] = 1;
    for(int i=0; i<n; i++){
        cin >> a[i];
        sum += a[i];
        ans += m[sum-x];
        m[sum]++;
    }
    cout << ans << endl;
}
