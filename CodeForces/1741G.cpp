#include<bits/stdc++.h>
using namespace std;
#define pll pair<long long, long long>

const int maxn = 16384;
bool vis[maxn], car[maxn], dps[maxn][2][64], sack[2][64];
int t, n, m, dp[maxn], depth[maxn], ans;
int u, v, f, k, h[maxn];
vector<int> al[maxn];
queue<int> q;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> t;
    for(int tt=0; tt<t; tt++){
        cin >> n >> m;
        for(int i=1; i<=n; i++){
            vis[i] = false;
            dp[i] = 0;
            al[i].clear();
            for(int j=0; j<64; j++){
                dps[i][0][j] = false;
                dps[i][1][j] = false;
            }
        }
        while(m--){
            cin >> u >> v;
            al[u].push_back(v);
            al[v].push_back(u);
        }
        cin >> f;
        for(int i=0; i<f; i++){
            cin >> h[i]; car[i] = true;
        }
        cin >> k;
        v = 1;
        for(int i=0; i<k; i++){
            cin >> u; u--;
            car[u] = false;
            dp[h[u]] = dp[h[u]] | v;
            v *= 2;
        }
        vis[1] = true;
        depth[1] = 0;
        dps[1][0][0] = true;
        //cout << q.size() << endl;
        q.push(1);

        //cout << "kelar input " << q.size()<< endl;
        while(!q.empty()){
            u = q.front();
            q.pop();
            // benerin dp u
            //cout << "masuk " << u << ":";
            for(int i=0; i<64; i++){
                if(dps[u][0][i]){
                    //cout << " " << i;
                    dps[u][1][i | dp[u]] = true;
                }
            }//cout << endl;
            // bfs
            for(int i=0; i<al[u].size(); i++){
                v = al[u][i];
                //cout << "u v: " << u << " " << v << endl;
                if(!vis[v]){
                    vis[v] = true;
                    depth[v] = depth[u]+1;
                    q.push(v);
                }
                if(depth[v] > depth[u]){
                    for(int j=0; j<64; j++){
                        if(dps[u][1][j]){
                            dps[v][0][j] = true;
                        }
                    }
                }
            }
        }
        //cout << "kelar bfs" << endl;
        // knapsack
        sack[0][0] = true;
        for(int i=1; i<64; i++){
            sack[0][i] = false;
        }
        m = 0;
        for(int i=0; i<f; i++){
            if(car[i]){
                m = !m;
                for(int j=0; j<64; j++){
                    sack[m][j] = false;
                }
                for(int j=0; j<64; j++){
                    if(sack[!m][j]){
                        for(int d=0; d<64; d++){
                            if(dps[h[i]][1][d]){
                                sack[m][j | d] = true;
                            }
                        }
                    }
                }
            }
        }

        ans = k;
        //cout << "sack: " << ans << endl;
        for(int i=0; i<64; i++){
            if(sack[m][i]){
                //cout << "masuk " << i << endl;
                u = i; v = 0;
                while(u>0){
                    v += u%2; u /= 2;
                }
                ans = min(k - v, ans);
                //cout << i << " " << onbt[i] << " " << ans << endl;
            }
        }//cout << endl;
        cout << ans << endl << endl;
    }
}
