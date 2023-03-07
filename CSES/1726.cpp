#include <bits/stdc++.h>
using namespace std;

const long long maxn = 200069;
long long n, a, b, ans = -1e18;
long long presum[maxn], x;
multiset<long long> s;
multiset<long long> :: iterator itr;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n >> a >> b;
    presum[0] = 0;
    for(int i=1; i<=n; i++){
        cin >> x;
        presum[i] = presum[i-1] + x;
    }
    for(int i=0; i<=n; i++){
        if(i-b > 0){
            itr = s.lower_bound(presum[i-b-1]);
            s.erase(itr);
        }
        if(i-a >= 0){s.insert(presum[i-a]);}
        if(!(s.empty())){
            ans = max(ans, presum[i] - *(s.begin()));
        }
    }
    cout << ans << endl;
}
