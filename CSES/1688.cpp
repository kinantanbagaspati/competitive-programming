#include <bits/stdc++.h>
using namespace std;

long long p[200069][20], depth[200069];

void init(long long n){
    p[0][0] = 0;
    p[1][0] = 0;
    depth[1] = 0;
    for(int i=2; i<=n; i++){
        cin >> p[i][0];
        depth[i] = -1;
    }
    for(int j=1; j<20; j++){
        for(int i=0; i<=n; i++){
            p[i][j] = p[p[i][j-1]][j-1];
        }
    }
}
long long getdepth(long long node){
    if(depth[node]<0){
        depth[node] = getdepth(p[node][0])+1;
    }
    return depth[node];
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    long long n, q;
    cin >> n >> q;
    init(n);
    depth[1] = 0;
    for(int i=2; i<=n; i++){
        getdepth(i);
    }
    long long a, b, c, idx;
    while(q--){
        cin >> a >> b;
        c = depth[a]-depth[b]; idx = 0;
        while(c>0){
            if(c%2){a = p[a][idx];}
            c/=2; idx++;
        }
        c = depth[b]-depth[a]; idx=0;
        while(c>0){
            if(c%2){b = p[b][idx];}
            c/=2; idx++;
        }
        while(a!=b){
            idx=1;
            while(p[a][idx] != p[b][idx]){idx++;}
            a = p[a][idx-1]; b = p[b][idx-1];
        }
        cout << a << endl;
    }
}
