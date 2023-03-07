#include <bits/stdc++.h>
using namespace std;
#define pll pair<long long, long long>

long long a, b, c, k, u, v, w;
long long ans[128][3], sisa, bagi;

void printAns(int nbtitik){
    cout << nbtitik << endl;
    for(int i=0; i<nbtitik; i++){
        cout << ans[i][0] << " " << ans[i][1] << " " << ans[i][2] << endl;
    }
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin >> a >> b >> c >> k;
    if(k == 1){
        cout << 4 << endl;
        cout << "0 0 0" << endl;
        cout << "1 0 0" << endl;
        cout << "0 1 0" << endl;
        cout << "0 0 1" << endl;
        return 0;
    }
    if(k <= 6){
        ans[0][0] = 0; ans[0][1] = 0; ans[0][2] = 0;

        ans[1][0] = 0; ans[1][1] = 1; ans[1][2] = 1;
        ans[2][0] = 1; ans[2][1] = 0; ans[2][2] = 1;
        ans[3][0] = 1; ans[3][1] = 1; ans[3][2] = 0;

        ans[4][0] = 0; ans[4][1] = 0; ans[4][2] = 1;
        ans[5][0] = 0; ans[5][1] = 1; ans[5][2] = 0;
        ans[6][0] = 1; ans[6][1] = 0; ans[6][2] = 0;

        ans[7][0] = 1; ans[7][1] = 1; ans[7][2] = 1;
        printAns(2+k);
        return 0;
    }
    cout << 16 << endl;
    u = 1; v = 1; w = 1;
    if(a>1 && u*v*w*8 >= k){
        000, 200, 0v0, 00w
        cout << "2 0 0" << endl;
        cout << "0 " << v << " 0" << endl;
        cout << "0 0 " << w << endl;
        cout << "1 " << v << " " << w << endl;

        sisa = u*v*w*8 - k;

        bagi = sisa / (u*v*w);

        sisa %= (u*v*w);

        bagi = sisa / (v*w);

        sisa %= (v*w);


        return 0;
    }
    while(u*v*w*6 < k && u<a){
        u++;
    }
    if(u*v*w*6 >= k){
        return 0;
    }

}
