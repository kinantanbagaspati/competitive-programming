#include <bits/stdc++.h>
using namespace std;

vector<long long> anak[200069];
long long subs[2000069];

void init(long long n){
    long long p;
    for(int i=2; i<=n; i++){
        cin >> p;
        anak[p].push_back(i);
    }
}

void dfs(long long node){
    subs[node] = anak[node].size();
    for(int i=0; i<anak[node].size(); i++){
        dfs(anak[node][i]);
        subs[node] += subs[anak[node][i]];
    }
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    long long n;
    cin >> n;
    init(n);
    dfs(1);
    for(int i=1; i<=n; i++){
        cout << subs[i] << " ";
    }cout << endl;
}
