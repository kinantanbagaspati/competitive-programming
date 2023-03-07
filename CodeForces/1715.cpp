#include<bits/stdc++.h>
using namespace std;
#define pll pair<long long, long long>

const long long maxn = 131072;
long long n, m, k, dis[maxn];
long long cht[maxn], cons[maxn], kiri[maxn], sz;
vector<long long> al[maxn], weight[maxn];
multiset<pll> ms;
pll temp;
long long u, v, w, to, curw;

long long realCeil(long long x, long long y){
    if(y<0){
        x *= -1; y *= -1;
    }
    if(x<0){
        return x/y;
    }else{
        return (x+y-1)/y;
    }
}

void dijkstra(){
    while(!ms.empty()){
        temp = *(ms.begin());
        ms.erase(temp);
        for(int i=0; i<al[temp.second].size(); i++){
            to = al[temp.second][i];
            curw = weight[temp.second][i];
            if(temp.first + curw < dis[to]){
                ms.erase({dis[to], to});
                dis[to] = temp.first + curw;
                ms.insert({dis[to], to});
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n >> m >> k;
    for(int i=1; i<=n; i++){
        dis[i] = 1e18;
    }
    while(m--){
        cin >> u >> v >> w;
        al[u].push_back(v);
        al[v].push_back(u);
        weight[u].push_back(w);
        weight[v].push_back(w);
    }

    dis[1] = 0;
    ms.insert({0, 1});
    dijkstra();
    /*
    cout << "cek dis" << endl;
    for(int i=1; i<=n; i++){
        cout << dis[i] << " ";
    }cout << endl;
    */
    while(k--){
        // cht
        sz = 0;
        for(long long j=1; j<=n; j++){
            if(dis[j] < 1e18){
                while(sz>0 && - kiri[sz-1]*j*2 + dis[j] + j*j <= - kiri[sz-1]*cht[sz-1]*2 + cons[sz-1]){
                    sz--;
                }
                //masukin
                cons[sz] = dis[j] + j*j;
                cht[sz] = j;
                if(sz>0){
                    // intersect, cari x terkecil sehingga
                    //-2*j*x + dis[j] + j*j <= -2*cht[sz-1]*x + dis[cht[sz-1]] + cht[sz-1]*cht[sz-1]
                    //2*(j-cht[sz-1])*x >= dis[j] + j*j - dis[cht[sz-1]] - cht[sz-1]*cht[sz-1]
                    kiri[sz] = realCeil(cons[sz] - cons[sz-1], (j-cht[sz-1])*2);
                    if(kiri[sz] > 1e9){
                        sz--;
                    }
                }else{
                    kiri[sz] = -1e9;
                }
                sz++;
            }
        }
        kiri[sz] = 1e9;
        /*
        cout << "cek cht" << endl;
        for(int i=0; i<sz; i++){
            cout << i << ": " << kiri[i] << " " << cht[i] << " " << dis[cht[i]] + cht[i]*cht[i] << endl;
        }
        */
        // update dis
        sz = 0; //cout << "cek dis" << endl;
        for(long long i=1; i<=n; i++){
            if(kiri[sz+1] == i){
                sz++;
            }
            dis[i] = cons[sz] - i*cht[sz]*2 + i*i;
            if(dis[i] < 0){
                cout << "negatif habis cht pas k=" << k << " nilai dis-" << i  << endl;
            }
            ms.insert({dis[i], i});
        }//cout << endl;

        // dijkstra lagi
        dijkstra();
    }

    for(int i=1; i<=n; i++){
        cout << dis[i] << " ";
    }cout << endl;
}
