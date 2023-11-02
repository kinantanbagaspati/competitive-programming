#include <bits/stdc++.h>
using namespace std;

int n, m, k, pow2;
int ans[128][2];

int main(){
    cin >> k;
    ans[0][0] = 3; ans[0][1] = 2;
    ans[1][0] = 4; ans[1][1] = 2;
    n = 4; m = 2;
    while(k>0){
        if(k%2){
            ans[m][0] = 1;
            ans[m][1] = n;
            m++;
        }
        k /= 2;
        if(k>0){
            m+=4;
            ans[m-4][0] = n+1; ans[m-4][1] = n;
            ans[m-3][0] = n+1; ans[m-3][1] = n-1;
            ans[m-2][0] = n+2; ans[m-2][1] = n;
            ans[m-1][0] = n+2; ans[m-1][1] = n-1;
            n += 2;
        } 
    }
    cout << n << ' ' << m << endl;
    for(int i=0; i<m; i++){
        cout << ans[i][0] << ' ' << ans[i][1] << endl;
    }
}