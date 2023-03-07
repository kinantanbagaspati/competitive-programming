#include <bits/stdc++.h>
using namespace std;

long long p[200069][20];

void init(long long n){
    p[0][0] = 0;
    p[1][0] = 0;
    for(int i=2; i<=n; i++){
        cin >> p[i][0];
    }
    for(int j=1; j<20; j++){
        for(int i=0; i<=n; i++){
            p[i][j] = p[p[i][j-1]][j-1];
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    long long n, q;
    cin >> n >> q;
    init(n);
    long long a, b, c;
    while(q--){
        cin >> a >> b;
        c = 0;
        while(b>0){
            if(b%2){
                a = p[a][c];
            }
            c++;
            b/=2;
        }
        if(a==0){
            cout << -1 << endl;
        }else{
            cout << a << endl;
        }
    }
}
