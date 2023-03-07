#include <bits/stdc++.h>
using namespace std;
#define pll pair<long long, long long>

const long long maxn = 131072;
long long t, n[3], x[3], mn, ans;

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--){
        cin >> n[0] >> n[1] >> n[2];
        mn = min(min(n[0], n[1]), n[2]);
        cin >> x[0] >> x[1] >> x[2];
        for(long long i=0; i<mn; i++){
            long long i3 = i*i*i;
            bool nemu = true;
            for(int j=0; j<3; j++){
                nemu = nemu && (i3%n[j] == x[j]);
            }
            if(nemu){
                ans = i;
            }
        }
        cout << ans << endl;
    }
}

/*
1->2: 0 1
2->3: 0 1
3->4: 1 0
4->5: 1 0
*/
