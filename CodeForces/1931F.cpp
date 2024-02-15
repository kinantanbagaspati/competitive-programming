#include<bits/stdc++.h>
using namespace std;
#define pll pair<long long, long long>

const long long maxn = 262144;
int t, n, k, prv, nxt, indeg[maxn];
int q[maxn], qhead, qtail;
vector<int> al[maxn];

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--){
        cin >> n >> k;
        for(int i=0; i<k; i++){
            cin >> prv;
            for(int j=1; j<n; j++){
                cin >> nxt;
                if(j>1){
                    al[prv].push_back(nxt); indeg[nxt]++;
                }
                prv = nxt;
            }
        }
        qhead = 0; qtail = 0;
        for(int i=1; i<=n; i++){
            if(indeg[i] == 0){
                q[qtail] = i; qtail++;
            }
        }
        while(qhead < qtail){
            //cout << "expand " << q[qhead] << endl;
            for(int i=0; i<al[q[qhead]].size(); i++){
                int to = al[q[qhead]][i];
                indeg[to]--;
                if(!indeg[to]){
                    q[qtail] = to; qtail++;
                }
            }
            qhead++;
        }
        if(qtail < n){
            cout << "NO" << endl;
        }else{
            cout << "YES" << endl;
        }
        for(int i=0; i<=n; i++){
            indeg[i] = 0; al[i].clear();
        }
    }
}