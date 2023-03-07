#include <bits/stdc++.h>
using namespace std;

const long long maxn = 200069;
long long n, k, ans = 0;
pair<long long, long long> bys[maxn], p;
multiset<long long> done;
multiset<long long> :: iterator itr;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n >> k;
    long long a, b;
    for(int i=0; i<n; i++){
        cin >> a >> b;
        bys[i] = {b,a};
    }
    for(int i=0; i<k; i++){
        done.insert(0);
    }
    sort(bys, bys+n);
    for(int i=0; i<n; i++){
        //cout << bys[i].first << " " << bys[i].second << endl;
        itr = done.lower_bound(-bys[i].second);
        //cout << *itr << endl;
        if(itr != done.end()){
            ans++;
            done.erase(itr);
            done.insert(-bys[i].first);
        }
    }
    cout << ans << endl;
}
