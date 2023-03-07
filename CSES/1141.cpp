#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    long long n, ans=0;
    cin >> n;
    long long k[n], idx=0, cur=0;
    set<long long> s;
    for(int i=0; i<n; i++){
        cin >> k[i];
        if(s.count(k[i])>0){
            while(k[idx] != k[i]){
                s.erase(k[idx]);
                cur--;
                idx++;
            }idx++;
        }else{
            s.insert(k[i]);
            cur++;
        }
        ans = max(ans, cur);
    }
    cout << ans << endl;
}
