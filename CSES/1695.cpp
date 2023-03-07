#include <bits/stdc++.h>
using namespace std;

const long long maxn = 505, maxm = 1010;
long long n, m, source, sink;
long long el[2*maxm][3], nbedge = 0;
vector<long long> al[maxn];
long long depth[maxn], pointer[maxn];

void addedge(long long u, long long v, long long c){
    el[nbedge][0] = u; el[nbedge][1] = v; el[nbedge][2] = c;
    el[nbedge+1][0] = v; el[nbedge+1][1] = u; el[nbedge+1][2] = c;
    al[u].push_back(nbedge);
    al[v].push_back(nbedge+1);
    nbedge += 2;
}
void init(){
    cin >> n >> m;
    long long u, v;
    while(m--){
        cin >> u >> v;
        addedge(u, v, 1);
    }
    source = 1; sink = n;
}
bool bfs(){
    queue<long long> q;
    depth[source] = 1;
    q.push(source);
    while(!(q.empty())){
        long long head = q.front(); q.pop();
        for(int i=0; i<al[head].size(); i++){
            long long id = al[head][i];
            if(depth[el[id][1]] == 0 && el[id][2] > 0){
                q.push(el[id][1]);
                depth[el[id][1]] = depth[head] + 1;
            }
        }
    }
    return depth[sink] > 0;
}
long long dfs(long long node, long long pushed){
    //cout << node << " " << pushed << endl;
    if(pushed == 0){
        return 0;
    }
    if(node == sink){
        return pushed;
    }
    for(int i; pointer[node]<al[node].size(); pointer[node]++){
        i = pointer[node];
        long long id = al[node][i];
        if(depth[node]+1 == depth[el[id][1]]){
            if(el[id][2] > 0){
                long long ret = dfs(el[id][1], min(el[id][2], pushed));
                if(ret > 0){
                    el[id][2] -= ret;
                    el[id^1][2] += ret;
                    return ret;
                }
            }
        }
    }
    return 0;
}

long long maxflow(){
    //reset
    long long ret = 0;
    for(int i=1; i<=n; i++){
        depth[i] = 0;
        pointer[i] = 0;
    }
    while(bfs()){
        ret += dfs(source, 1e18);
        //cout << ret << endl;
        for(int i=1; i<=n; i++){
            depth[i] = 0;
            pointer[i] = 0;
        }
    }
    return ret;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    init();
    cout << maxflow() << endl;
    for(int i=0; i<nbedge; i+=2){
        if(depth[el[i][0]] > 0 && depth[el[i][1]] == 0){
            cout << el[i][0] << " " << el[i][1] << endl;
        }
    }
}
