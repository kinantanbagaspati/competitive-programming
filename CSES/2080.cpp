#include <bits/stdc++.h>
using namespace std;

const int maxn = 262144;
bool visited[maxn], decomposed[maxn];
vector<int> adjacencyList[maxn];
int n, subtree[maxn], maxSubtree[maxn];

void initTree(){
    for(int i=1; i<=n; i++){
        visited[i] = false;
        decomposed[i] = false;
    }
    int u, v;
    for(int i=1; i<n; i++){
        cin >> u >> v;
        adjacencyList[u].push_back(v);
        adjacencyList[v].push_back(u);
    }
}



int countSubtree(int node, int nbNodes){
    visited[node] = !visited[node];
    subtree[node] = 1;
    maxSubtree[node] = 0;
    int returned, centroid = -1;
    for(int i=0; i < adjacencyList[node].size(); i++){
        int to = adjacencyList[node][i];
        if(visited[to] != visited[node] && decomposed[to] == decomposed[node]){
            returned = countSubtree(to, nbNodes);
            if(centroid < 0 || maxSubtree[returned] < maxSubtree[centroid]){
                centroid = returned;
            }
            subtree[node] += subtree[to];
            maxSubtree[node] = max(maxSubtree[node], subtree[to]);
        }
    }
    maxSubtree[node] = max(maxSubtree[node], nbNodes - subtree[node]);
    //cout << "node, subtree, maxsubtree: " << node << "," << subtree[node] << "," << maxSubtree[node] << endl;
    if(centroid < 0 || maxSubtree[node] < maxSubtree[centroid]){
        centroid = node;
    }
    return centroid;
}

int maxDepth;
long long nbDepth[maxn];
void countDepth(int node, int currentDepth){
    if(maxDepth < currentDepth){
        maxDepth++; nbDepth[currentDepth] = 0;
    }
    nbDepth[currentDepth]++;
    visited[node] = !visited[node];
    for(int i=0; i<adjacencyList[node].size(); i++){
        int to = adjacencyList[node][i];
        if(visited[to] != visited[node] & decomposed[to] == decomposed[node]){
            countDepth(to, currentDepth+1);
        }
    }
}

int k;
long long ans = 0;
void centroidDecomp(int root, int nbNodes, int currentDepth){
    // Mencari centroid
    int centroid = countSubtree(root, nbNodes);
    // Hitung depth
    maxDepth = -1;
    countDepth(centroid, 0);
    //cout << endl << "Ngitung centroid " << centroid << endl;
    for(int i=max(k-maxDepth, 0); i<=min(k, maxDepth); i++){
        ans += nbDepth[i] * nbDepth[k-i];
        //cout << i << "," << k-i << ": " << nbDepth[i] << "," << nbDepth[k-i] << endl;
    }
    decomposed[centroid] = !decomposed[centroid];
    for(int i=0; i<adjacencyList[centroid].size(); i++){
        int to = adjacencyList[centroid][i];
        if(decomposed[to] != decomposed[centroid]){
            maxDepth = -1;
            countDepth(to, 0);
            //cout << "Ngitung to " << to << endl;
            for(int j=max(k-2-maxDepth, 0); j<=min(k-2, maxDepth); j++){
                ans -= nbDepth[j] * nbDepth[k-2-j];
                //cout << j << "," << k-2-j << ": " << nbDepth[j] << "," << nbDepth[k-2-j] << endl;
            }
        }
    }
    // Rekursi
    //cout << "Dekomposisi node " << centroid << " pada depth " << currentDepth << endl;
    for(int i=0; i < adjacencyList[centroid].size(); i++){
        int to = adjacencyList[centroid][i];

        if(decomposed[to] != decomposed[centroid]){
            if(subtree[to] > subtree[centroid]){
                // i ditelusuri lebih dulu dari centroid saat countSubtree
                centroidDecomp(to, nbNodes - subtree[centroid], currentDepth+1);
            }else{
                centroidDecomp(to, subtree[to], currentDepth+1);
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n >> k;
    initTree();
    centroidDecomp(1, n, 0);
    cout << ans/2 << endl;
}
