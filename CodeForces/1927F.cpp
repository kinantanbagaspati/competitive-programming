#include<bits/stdc++.h>
using namespace std;
#define pll pair<long long, long long>

int t, n, m, b, k;
int par[262144], card[262144];

void initDSU(){
    for(int i=1; i<=n; i++){
        par[i] = i;
        card[i] = 1;
    }
}

vector<int> path[2];
int getAncestor(int x, bool isi, int pid){
    if(isi){
        path[pid].clear();
        path[pid].push_back(x);
    }
    while(par[x] != x){
        x = par[x];
        if(isi){
            path[pid].push_back(x);
        }
    }
    return x;
}
void join(int a, int b){
    if(card[a] < card[b]){
        par[a] = b;
        card[b] += card[a];
    }else{
        par[b] = a;
        card[a] += card[b];
    }
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--){
        cin >> n >> m;
        initDSU();
        b = 1e9;
        while(m--){
            int x, y, z;
            cin >> x >> y >> z;
            if(getAncestor(x, false, -1) == getAncestor(y, false, -1)){
                if(z < b){
                    getAncestor(x, true, 0);
                    getAncestor(y, true, 1);
                    b = z;
                }
            }else{
                join(getAncestor(x, false, -1), getAncestor(y, false, -1));
            }
        }
        cout << b << ' ' << (path[0].size() + path[1].size()) << endl;
        for(int i=0; i<path[0].size(); i++){
            cout << path[0][i] << ' ';
        }
        for(int i=path[1].size()-1; i>=0; i--){
            cout << path[1][i] << ' ';
        } cout << endl;
    }
}