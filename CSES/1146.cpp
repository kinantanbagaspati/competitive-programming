#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    long long m, ans=0;
    cin >> m;
    for(long long div=1; div<=m; div*=2){
        ans += m/(2*div)*div;
        ans += max(0ll, m%(2*div)-div+1);
    }
    cout << ans << endl;
}
