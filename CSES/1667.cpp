#include <bits/stdc++.h>
using namespace std;

vector<long long> al[100069];
long long backtrack[100069];

void init(long long n, long long m){
    long long u, v;
    for(int i=1; i<=n; i++){
        backtrack[i] = -1;
    }
    while(m--){
        cin >> u >> v;
        al[u].push_back(v);
        al[v].push_back(u);
    }
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    long long n, m;
    cin >> n >> m;
    init(n,m);
    queue<long long> q;
    q.push(1);
    backtrack[1] = 0;
    bool done = false;
    while(!done && !q.empty()){
        long long head = q.front();
        q.pop();
        for(int i=0; i<al[head].size(); i++){
            if(backtrack[al[head][i]]<0){
                backtrack[al[head][i]] = head;
                q.push(al[head][i]);
            }
            if(al[head][i] == n){
                done = true;
            }
        }
    }
    vector<long long> path;
    long long cur = n;
    path.push_back(cur);
    while(cur>1){
        cur = backtrack[cur];
        path.push_back(cur);
    }
    if(done){
        cout << path.size() << endl;
        for(int i=path.size()-1; i>=0; i--){
            cout << path[i] << " ";
        }cout << endl;
    }else{
        cout << "IMPOSSIBLE" << endl;
    }
}
