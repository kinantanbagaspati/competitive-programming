#include <bits/stdc++.h>
using namespace std;
#define pll pair<long long, long long>

const long long maxn = 131072;

long long n, a;
bool bisa = true, dp[2][4];

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin >> n >> a;
    for(int j=0; j<4; j++){
        dp[0][j] = false;
    }
    if(a >= 2){
        bisa = false;
    }else if(a){
        dp[0][1] = true;
        dp[0][2] = true;
    }else{
        dp[0][0] = true;
        dp[0][3] = true;
    }
    for(int i=1; i<n-1; i++){
        for(int j=0; j<4; j++){
            dp[i%2][j] = false;
        }
        cin >> a;
        if(a > 2){
            bisa = false;
        }else if(a==2){
            dp[i%2][2] |= dp[(i+1)%2][1];
            dp[i%2][1] |= dp[(i+1)%2][2];
        }else if(a==1){
            dp[i%2][0] |= dp[(i+1)%2][1] | dp[(i+1)%2][2];
            dp[i%2][1] |= dp[(i+1)%2][0] | dp[(i+1)%2][3];
            dp[i%2][2] |= dp[(i+1)%2][3] | dp[(i+1)%2][0];
            dp[i%2][3] |= dp[(i+1)%2][2] | dp[(i+1)%2][1];
        }else{//a == 0
            dp[i%2][0] |= dp[(i+1)%2][0] | dp[(i+1)%2][3];
            dp[i%2][1] |= dp[(i+1)%2][1];
            dp[i%2][2] |= dp[(i+1)%2][2];
            dp[i%2][3] |= dp[(i+1)%2][0] | dp[(i+1)%2][3];
        }
    }
    cin >> a;
    if(a >= 2){
        bisa = false;
    }else if(a){
        if(!(dp[n%2][1] || dp[n%2][2])){
            bisa = false;
        }
    }else{
        if(!(dp[n%2][0] || dp[n%2][3])){
            bisa = false;
        }
    }
    if(bisa){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
    }
}

/*
1->2: 0 1
2->3: 0 1
3->4: 1 0
4->5: 1 0
*/
