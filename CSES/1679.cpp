#include <bits/stdc++.h>
using namespace std;

long long n, m;
vector<long long> preq[100069], ans;
long long deg[100069];

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n >> m;
    long long a, b;
    while(m--){
        cin >> a >> b;
        preq[a].push_back(b);
        deg[b]++;
    }
    for(int i=1; i<=n; i++){
        if(deg[i] == 0){ans.push_back(i);}
    }
    long long idx = 0;
    while(idx < ans.size()){
        for(int i=0; i<preq[ans[idx]].size(); i++){
            long long cur = preq[ans[idx]][i];
            deg[cur]--;
            if(deg[cur] == 0){
                ans.push_back(cur);
            }
        }idx++;
    }
    if(idx == n){
        for(int i=0; i<n; i++){
            cout << ans[i] << " ";
        }cout << endl;
    }else{
        cout << "IMPOSSIBLE" << endl;
    }
}
