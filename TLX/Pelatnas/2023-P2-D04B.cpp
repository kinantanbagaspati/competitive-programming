#include <bits/stdc++.h>
using namespace std;

const int maxn = 131072, maxm = (1 << 30);
int n, u, v, w, nbNodes = 1, ansMin = maxm, ansMax = -maxm;
vector<int> adjl[maxn], weight[maxn];
int nodeXOR[maxn], childID[maxn * 32][2];

void dfsTree(int par, int node, int curXOR){
    nodeXOR[node] = curXOR;
    for(int i=0; i<adjl[node].size(); i++){
        if(adjl[node][i] != par){
            dfsTree(node, adjl[node][i], curXOR ^ weight[node][i]);
        }
    }
}

void traverseMin(int valXOR){
    int valBit = (1 << 29), curID = 0, curXOR = 0;
    while(valBit){
        if(valBit & valXOR){
            if(childID[curID][1]){
                curID = childID[curID][1];
            }else{
                curID = childID[curID][0];
                curXOR += valBit;
            }
        }else{
            if(childID[curID][0]){
                curID = childID[curID][0];
            }else{
                curID = childID[curID][1];
                curXOR += valBit;
            }
        }
        valBit /= 2;
    }
    ansMin = min(curXOR, ansMin);
}
void traverseMax(int valXOR){
    int valBit = (1 << 29), curID = 0, curXOR = 0;
    while(valBit){
        if(valBit & valXOR){
            if(childID[curID][0]){
                curID = childID[curID][0];
                curXOR += valBit;
            }else{
                curID = childID[curID][1];
            }
        }else{
            if(childID[curID][1]){
                curID = childID[curID][1];
                curXOR += valBit;
            }else{
                curID = childID[curID][0];
            }
        }
        valBit /= 2;
    }
    ansMax = max(curXOR, ansMax);
}
void addLeaf(int valXOR){
    int valBit = (1 << 29), curID = 0;
    while(valBit){
        bool nyala = (valBit & valXOR) > 0;
        if(!childID[curID][nyala]){
            childID[curID][nyala] = nbNodes; nbNodes++;
        }
        curID = childID[curID][nyala];
        valBit /= 2;
    }
}

int main(){
    cin >> n;
    for(int i=1; i<n; i++){
        cin >> u >> v >> w;
        adjl[u].push_back(v);
        weight[u].push_back(w);
        adjl[v].push_back(u);
        weight[v].push_back(w);
    }
    dfsTree(0, 1, 0);
    for(int i=1; i<=n; i++){
        traverseMin(nodeXOR[i]);
        traverseMax(nodeXOR[i]);
        addLeaf(nodeXOR[i]);
    }
    cout << ansMin << " " << ansMax << endl;
}