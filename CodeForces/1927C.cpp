#include<bits/stdc++.h>
using namespace std;
#define pll pair<long long, long long>

int t, n, m, k, a[262144], b[262144], c, d, e;
bool fa[1048576], fb[1048576];
string s;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--){
        cin >> n >> m >> k;
        for(int i=0; i<n; i++){
            cin >> a[i]; fa[a[i]] = true;
        }
        for(int i=0; i<m; i++){
            cin >> b[i]; fb[b[i]] = true;
        }
        c = 0; d = 0; e = 0;
        for(int i=1; i<=k; i++){
            c += fa[i]; d += fb[i]; e += (fa[i] || fb[i]);
        }
        if(e==k && c>=k/2 && d>=k/2){
            cout << "YES" << endl;
        }else{
            cout << "NO" << endl;
        }

        for(int i=0; i<n; i++){
            fa[a[i]] = false;
        }
        for(int i=0; i<m; i++){
            fb[b[i]] = false;
        }
    }
}