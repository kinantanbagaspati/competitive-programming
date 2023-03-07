#include <bits/stdc++.h>
using namespace std;
#define pll pair<long long, long long>

const long long maxn = 262144, mod = 1e9+7;
long long n, a, ans, cur, cpy;
map<long long, long long> freq;

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin >> n;
    ans = 0;
    for(int i=0; i<n; i++){
        cin >> a; freq[a]++;
        ans = max(ans, a);
    }
    for(int i=2; i<maxn/4; i++){
        cur = 0;
        cpy = i;
        while(cpy < mod){
            cur += freq[cpy]*cpy; cpy *= i;
        }
        ans = max(ans, cur);
    }
    cout << max(ans, freq[1]) << endl;
    return 0;
}

/*
1->2: 0 1
2->3: 0 1
3->4: 1 0
4->5: 1 0
*/
