#include <bits/stdc++.h>
using namespace std;

long long n, x, a[1010], ans[4];
map<long long, pair<long long, long long> > mp;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n >> x;
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            if(mp.count(x - a[i] - a[j]) > 0){
                ans[0] = mp[x-a[i]-a[j]].first+1;
                ans[1] = mp[x-a[i]-a[j]].second+1;
                ans[2] = i+1;
                ans[3] = j+1;
            }
        }
        for(int j=0; j<i; j++){
            mp[a[i] + a[j]] = {j, i};
        }
    }
    if(ans[0] == 0){
        cout << "IMPOSSIBLE" << endl;
    }else{
        cout << ans[0] << " " << ans[1] << " " << ans[2] << " " << ans[3] << endl;
    }
}
