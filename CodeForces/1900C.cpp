#include<bits/stdc++.h>
using namespace std;
#define pll pair<long long, long long>

const int maxn = 524288;
long long t, n, child[maxn][2];
string s;

int dfs(int node){
    int ret = 1e9;
    if(child[node][0] > 0){
        ret = min(dfs(child[node][0]) + (s[node-1] != 'L'), ret);
    }
    if(child[node][1] > 0){
        ret = min(dfs(child[node][1]) + (s[node-1] != 'R'), ret);
    }
    if(ret == 1e9){
        return 0;
    }else{
        return ret;
    }
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--){
        cin >> n >> s;
        for(int i=1; i<=n; i++){
            cin >> child[i][0] >> child[i][1];
        }
        cout << dfs(1) << endl;
        for(int i=1; i<=n; i++){
            child[i][0] = 0; child[i][1] = 0;
        }
    } 
}