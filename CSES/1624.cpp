#include <bits/stdc++.h>
using namespace std;

string board[8];

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    for(int i=0; i<8; i++){
        cin >> board[i];
    }
    long long perm[8] = {0,1,2,3,4,5,6,7};
    long long ans = 0, fac=1*2*3*4*5*6*7*8;
    for(int i=0; i<fac; i++){
        bool valid = true;
        for(int j=0; j<8; j++){
            if(board[j][perm[j]] == '*'){
                valid = false;
            }
            for(int k=j+1; k<8; k++){
                if(abs(perm[j]-perm[k])==k-j){
                    valid = false;
                }
            }
        }
        ans += valid;
        next_permutation(perm, perm+8);
    }
    cout << ans << endl;
}
