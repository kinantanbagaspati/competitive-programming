#include <bits/stdc++.h>
using namespace std;


int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    long long q, n, k;
    cin >> q;
    long long elim, off, rest, round;
    bool skip;
    while(q--){
        cin >> n >> k;
        elim = n/2;
        off = 0;
        rest = n;
        round = 0;
        skip = true;
        while(k > elim){
            k -= elim;
            if(!skip){
                off += (1<<round);
            }
            skip = (rest%2) ^ skip;
            rest -= elim;

            elim = (rest + !skip)/2;
            round++;
        }
        cout << (off + (k-1)*2*(1<<round) + skip*(1<<round))%n + 1 << endl;
    }
}
