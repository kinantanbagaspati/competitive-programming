#include<bits/stdc++.h>
using namespace std;
#define ppll pair<long long, long long>

const long long maxn = 262144, mod = 998244353;
long long n, u, v, ans = 0; 
long long a[maxn], depth[maxn], subtree[maxn], maxchild[maxn];
vector<long long> al[maxn];
map<long long, long long> info[32][4]; // 0 buat jml, 1 buat sigma depth, 2 buat sigma Y path

void dfsTree(long long node, long long par){
    depth[node] = depth[par] + 1;
    subtree[node] = 1;
    for(int i=0; i<al[node].size(); i++){
        long long to = al[node][i];
        if(to != par){
            dfsTree(to, node);
            subtree[node] += subtree[to];
            if(subtree[to] > subtree[maxchild[node]]){
                maxchild[node] = to;
            }
        }
    }
}

void calcAns(long long node, long long stid){
    //cout << "calcAns " << node << ' ' << stid << " dari " << ans << endl;
    long long pkiri, pkanan, qkiri, qkanan;
    //cout << "sebelum" << endl;
    for(map<long long, long long>::iterator itr=info[stid+1][0].begin(); itr!=info[stid+1][0].end(); itr++){
        // primanya itr->first
        /*cout << itr->first << ": (";
        cout << info[stid][0][itr->first] << ", " << info[stid][1][itr->first] << ", " << info[stid][2][itr->first];
        cout << ") vs (";
        cout << info[stid+1][0][itr->first] << ", " << info[stid+1][1][itr->first] << ", " << info[stid+1][2][itr->first];
        cout << ")" << endl;*/
        pkiri = info[stid][0][itr->first]; pkanan = itr->second;
        qkiri = pkiri * (pkiri-1) / 2 % mod; qkanan = pkanan * (pkanan-1) / 2 % mod;
        ans += (info[stid][2][itr->first] + (mod-depth[node]) * qkiri) % mod * pkanan % mod;
        ans += (info[stid+1][1][itr->first] + (mod-depth[node]) * pkanan) % mod * qkiri % mod;
        ans += (info[stid][1][itr->first] + (mod-depth[node]) * pkiri) % mod * qkanan % mod;
        ans += (info[stid+1][2][itr->first] + (mod-depth[node]) * qkanan) % mod * pkiri % mod;
        ans %= mod;
    }
    //cout << "sesudah" << endl;
    for(map<long long, long long>::iterator itr=info[stid+1][0].begin(); itr!=info[stid+1][0].end(); itr++){
        pkiri = info[stid][0][itr->first]; pkanan = itr->second;
        info[stid][2][itr->first] += info[stid+1][2][itr->first];
        info[stid][2][itr->first] += info[stid][1][itr->first] * pkanan % mod;
        info[stid][2][itr->first] += info[stid+1][1][itr->first] * pkiri % mod;
        info[stid][2][itr->first] += pkiri * pkanan % mod * (mod-depth[node]) % mod;
        info[stid][2][itr->first] %= mod;
        info[stid][1][itr->first] = (info[stid][1][itr->first] + info[stid+1][1][itr->first]) % mod;
        info[stid][0][itr->first] = (info[stid][0][itr->first] + pkanan) % mod;
        /*cout << itr->first << ": (";
        cout << info[stid][0][itr->first] << ", " << info[stid][1][itr->first] << ", " << info[stid][2][itr->first];
        cout << ")" << endl;*/
    }
    info[stid+1][0].clear();
    info[stid+1][1].clear();
    info[stid+1][2].clear();
    //cout << "jadi " << ans << endl << endl;
}

void dfStL(long long node, long long par, long long stid){
    if(maxchild[node] > 0){ // bukan leaf node
        dfStL(maxchild[node], node, stid);
        for(int i=0; i<al[node].size(); i++){
            long long to = al[node][i];
            if(to != par && to != maxchild[node]){
                dfStL(to, node, stid+1);
                calcAns(node, stid);
            }
        }
    }
    for(int i=2; i*i<=a[node]; i++){
        if(a[node]%i == 0){
            info[stid+1][0][i] = 1;
            info[stid+1][1][i] = depth[node];
            info[stid+1][2][i] = 0;
        }
        while(a[node]%i == 0){
            a[node] /= i;
        }
    }
    if(a[node] > 1){
        info[stid+1][0][a[node]] = 1;
        info[stid+1][1][a[node]] = depth[node];
        info[stid+1][2][a[node]] = 0;
    }
    //cout << node << ": " << ans << " -> ";
    calcAns(node, stid);
    //cout << ans << endl;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> a[i];
    }
    for(int i=1; i<n; i++){
        cin >> u >> v;
        al[u].push_back(v);
        al[v].push_back(u);
    }
    dfsTree(1, 0);
    dfStL(1, 0, 0);
    cout << ans << endl;
}
