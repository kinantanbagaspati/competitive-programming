#include <bits/stdc++.h>
using namespace std;

const int maxn = 65536, sqrtn = 256, maxm = 524288;
int n, m, q;
int edgeinfo[maxm][2][2]; // nyimpen edge, id dalam vector
vector<int> edgelist[maxn], prv[maxn], nxt[maxn]; // vector linkedlist

int main(){
    cout << n;
    for(int i=n-1; i>0; i--){
        cout << endl << 1;
        for(int j=1; j<i; j++){
            cout << " 100";
        }
    }
}