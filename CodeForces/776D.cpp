#include<bits/stdc++.h>
using namespace std;
#define pll pair<long long, long long>

const long long maxn = 131072;
long long n, m, x, u, warna[maxn];
bool nyala[maxn];
vector<long long> nyambung[maxn], al[maxn];
vector<bool> beda[maxn];

bool dfs(long long node){
    for(int i=0; i<al[node].size(); i++){
        long long to = al[node][i];
        if(beda[node][i]){
            if(warna[to] == 0){
                warna[to] = -warna[node];
                if(!dfs(to)){
                    return false;
                }
            }else if(warna[to] == warna[node]){
                return false;
            }
        }else{
            if(warna[to] == 0){
                warna[to] = warna[node];
                if(!dfs(to)){
                    return false;
                }
            }else if(warna[to] != warna[node]){
                return false;
            }
        }
    }
    return true;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n >> m;
    for(int i=0; i<n; i++){
        cin >> nyala[i]; nyala[i] = !nyala[i];
    }
    for(int i=0; i<m; i++){
        cin >> x;
        while(x--){
            cin >> u; u--;
            nyambung[u].push_back(i);
        }
    }
    for(int i=0; i<n; i++){
        al[nyambung[i][0]].push_back(nyambung[i][1]);
        beda[nyambung[i][0]].push_back(nyala[i]);

        al[nyambung[i][1]].push_back(nyambung[i][0]);
        beda[nyambung[i][1]].push_back(nyala[i]);

    }
    for(int i=0; i<m; i++){
        if(warna[i] == 0){
            warna[i] = 1;
            if(!dfs(i)){
                cout << "NO" << endl; return 0;
            }
        }
        //cout << "warna " << i << ": " << warna[i] << endl;
    }
    cout << "YES" << endl; return 0;
}
