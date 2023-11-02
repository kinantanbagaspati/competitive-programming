#include<bits/stdc++.h>
using namespace std;

const long long maxn = 256;
long long t, n, m, deg[maxn], x, y, f1, fx, fy;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--){
        cin >> n >> m;
        for(int i=1; i<=n; i++){
            deg[i] = 0;
        }
        while(m--){
            cin >> x >> y; deg[x]++; deg[y]++;
        }
        x = -1; y = -1;
        f1 = 0; fx = 0; fy = 0;
        for(int i=1; i<=n; i++){
            if(deg[i] == 1){
                f1++;
            }else if(x == -1 || x == deg[i]){
                x = deg[i];
                fx++;
            }else{
                y = deg[i];
                fy++;
            }
        }
        if(fx == 1){
            cout << x << " " << y-1 << endl;
        }else if(fy == 1){
            cout << y << " " << x-1 << endl;
        }else{ // fy == 0
            cout << x << " " << x-1 << endl;
        }
    }
}