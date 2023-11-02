#include <bits/stdc++.h>
using namespace std;

const long long maxn = 262144;
long long n, q, t[maxn];
long long segtree[2*maxn], lazy[2*maxn][2], range[2*maxn][2];

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    build();
    cin >> n >> q;
    long long t, a, b, c;

    for(int i=0; i<n; i++){
        cin >> t;
        update(0,1,i,i,t);
        //print(65536);
        //cout << endl;
    }
    while(q--){
        cin >> t >> a >> b; a--; b--;
        if(t == 3){
            update(0,1,a,b,0);
            cout << query(1,a,b) << endl;
        }else{
            cin >> c;
            update(t-1,1,a,b,c);
        }
    }
}
