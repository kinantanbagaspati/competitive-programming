#include <bits/stdc++.h>
using namespace std;

vector<long long> al[200069];
long long par[200069], dis[200069];

void init(long long n){
    long long a, b;
    par[n] = 0;
    dis[n] = -1;
    for(int i=1; i<n; i++){
        cin >> a >> b;
        al[a].push_back(b);
        al[b].push_back(a);
        par[i] = 0;
        dis[i] = -1;
    }
}
void dfs(long long node){
    for(int i=0; i<al[node].size(); i++){
        if(dis[al[node][i]]<0){
            dis[al[node][i]] = dis[node]+1;
            dfs(al[node][i]);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    long long n;
    cin >> n;
    init(n);
    queue<long long> q;
    q.push(1);
    par[1] = -1;
    long long x = 1;
    while(!q.empty()){
        long long head = q.front();
        q.pop();
        for(int i=0; i<al[head].size(); i++){
            if(!par[al[head][i]]){
                q.push(al[head][i]);
                par[al[head][i]] = -1;
                x = al[head][i];
            }
        }
    }
    q.push(x);
    par[x] = 0;
    dis[x] = 0;
    long long diameter = 0;
    while(!q.empty()){
        long long head = q.front();
        q.pop();
        for(int i=0; i<al[head].size(); i++){
            if(dis[al[head][i]]<0){
                q.push(al[head][i]);
                par[al[head][i]] = head;
                dis[al[head][i]] = dis[head]+1;
                x = al[head][i];
                diameter = dis[al[head][i]];
            }
        }
    }

    for(int i=1; i<=n; i++){
        dis[i] = -1;
    }
    long long cur=x;
    for(long long i=0; i<=diameter; i++){
        dis[cur] = max(diameter-i, i);
        cur = par[cur];
    }
    cur = x;
    for(int i=0; i<=diameter; i++){
        dfs(cur);
        cur = par[cur];
    }
    for(int i=1; i<=n; i++){
        cout << dis[i] << " ";
    }cout << endl;
}
