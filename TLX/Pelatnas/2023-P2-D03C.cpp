#include <bits/stdc++.h>
using namespace std;

const int maxn = 131072, maxm = (1 << 30);
long long ans = 0;
int n, toAdd; 
int m[maxn], childID[maxn * 32][2], nbNodes = 1;
bool lowEx, highEx;

int traverseMin(int valXOR){
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
    return curXOR;
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
    for(int i=0; i<n; i++){
        cin >> m[i];
    }
    sort(m, m+n);
    int valBit = (1 << 29); toAdd = (1 << 30);
    while(valBit > 1){
        // bersihin
        while(nbNodes > 1){
            nbNodes--;
            childID[nbNodes][0] = 0;
            childID[nbNodes][1] = 0;
        }
        childID[0][0] = 0; childID[0][1] = 0;

        // masukin
        if(m[0]%valBit < valBit/2){
            addLeaf(m[0]);
        }else if(nbNodes > 1){
            toAdd = min(traverseMin(m[0]), toAdd);
        }

        for(int i=1; i<n; i++){
            if(m[i]/valBit != m[i-1]/valBit){
                // tambahin
                if(toAdd != (1 << 30)){
                    ans += toAdd; toAdd = (1 << 30);
                }
                // bersihin
                while(nbNodes > 1){
                    nbNodes--;
                    childID[nbNodes][0] = 0;
                    childID[nbNodes][1] = 0;
                }
                childID[0][0] = 0; childID[0][1] = 0;
            }
            // masukin
            if(m[i]%valBit < valBit/2){
                addLeaf(m[i]);
            }else if(nbNodes > 1){
                toAdd = min(traverseMin(m[i]), toAdd);
            }
        }
        // tambahin
        if(toAdd != (1 << 30)){
            ans = ans + toAdd; toAdd = (1 << 30);
        }

        valBit /= 2;
    }
    cout << ans << endl;
}