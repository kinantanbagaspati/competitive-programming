#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    long long n, q;
    cin >> n >> q;
    long long x[n], pos[n+1];
    for(int i=0; i<n; i++){
        cin >> x[i];
        pos[x[i]] = i;
    }
    long long ans = 1;
    for(int i=1; i<n; i++){
        ans += pos[i]>pos[i+1];
    }
    long long a, b, c;
    while(q--){
        cin >> a >> b;
        a--;b--;
        c = x[a];
        x[a] = x[b];
        x[b] = c;
        a = x[a];
        b = x[b];
        ans -= a>1 && pos[a]<pos[a-1];
        ans -= a<n && pos[a]>pos[a+1];
        ans -= b>1 && pos[b]<pos[b-1];
        ans -= b<n && pos[b]>pos[b+1];
        ans += (b-a==1) && pos[a]>pos[b];
        ans += (a-b==1) && pos[b]>pos[a];
        c = pos[a];
        pos[a] = pos[b];
        pos[b] = c;
        ans += a>1 && pos[a]<pos[a-1];
        ans += a<n && pos[a]>pos[a+1];
        ans += b>1 && pos[b]<pos[b-1];
        ans += b<n && pos[b]>pos[b+1];
        ans -= (b-a==1) && pos[a]>pos[b];
        ans -= (a-b==1) && pos[b]>pos[a];
        cout << ans << endl;
    }
}
