#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    long long n, a, b;
    cin >> n;
    pair<long long, long long> srt[n];
    for(int i=0; i<n; i++){
        cin >> a >> b;
        srt[i] = {b,a};
    }
    sort(srt, srt+n);
    long long ans=0, idx=0, cur=0;
    while(idx<n){
        if(srt[idx].second >= cur){
            ans++;
            cur = srt[idx].first;
        }idx++;
    }
    cout << ans << endl;
}
