#include <bits/stdc++.h>
using namespace std;
#define pll pair<long long, long long>

const long long maxn = 131072;
long long n;
string atas, bawah;

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin >> n >> atas >> bawah;
    for(int i=0; i<n; i++){
        if(atas[i] == '1' && bawah[i] == '1'){
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
}

/*
1->2: 0 1
2->3: 0 1
3->4: 1 0
4->5: 1 0
*/
