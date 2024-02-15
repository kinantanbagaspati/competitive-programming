#include<bits/stdc++.h>
using namespace std;
#define pll pair<long long, long long>

const int maxn = 262144;
int n, a[maxn], freq[maxn*2], cur, ans;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n;
    cur = 0; freq[cur]++;
    for(int i=1; i<n; i++){
        cin >> a[i];
        cur ^= a[i];
        freq[cur]++;
        //cout << "cur " << cur << endl;
    }
    cur = 1;
    while(cur <= n){
        cur *= 2;
    }
    ans = cur-1;
    while(freq[ans] == 1){
        ans--;
    }
    ans = cur-1-ans;
    cout << ans;
    for(int i=1; i<n; i++){
        ans = ans ^ a[i];
        cout << ' ' << ans;
    } cout << endl;
}

/*
0 1 2 3 4 5
1 0 3 2 5 4
2 3 0 1 6 7
3 2 1 0 7 6
4 5 6 7 0 1
5 4 7 6 1 0
6 7 4 5 2 3
*/