#include <bits/stdc++.h>
using namespace std;

vector<long long> al[200069];
long long dis[200069];

void init(long long n){
    long long a, b;
    dis[n] = -1;
    for(int i=1; i<n; i++){
        cin >> a >> b;
        al[a].push_back(b);
        al[b].push_back(a);
        dis[i] = -1;
    }
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    long long n;
    cin >> n;
    init(n);
    queue<long long> q;
    q.push(1);
    dis[1] = 0;
    long long x = 1;
    while(!q.empty()){
        long long head = q.front();
        q.pop();
        for(int i=0; i<al[head].size(); i++){
            if(dis[al[head][i]]<0){
                q.push(al[head][i]);
                dis[al[head][i]] = dis[head] + 1;
                x = al[head][i];
            }
        }
    }
    for(int i=1; i<=n; i++){
        dis[i] = -1;
    }
    q.push(x);
    dis[x] = 0;
    long long ans = 0;
    while(!q.empty()){
        long long head = q.front();
        q.pop();
        for(int i=0; i<al[head].size(); i++){
            if(dis[al[head][i]]<0){
                q.push(al[head][i]);
                dis[al[head][i]] = dis[head] + 1;
                ans = dis[al[head][i]];
            }
        }
    }
    cout << ans << endl;
}
