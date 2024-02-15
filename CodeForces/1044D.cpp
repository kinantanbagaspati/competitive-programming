#include<bits/stdc++.h>
using namespace std;

const int maxn = 262144;
int q, t, a, b, x, cur=0;
map<int, int> card, par, dis;

pair<int, int> getAncestor(int node){
    pair<int, int> res = {node, 0};
    while(res.first != par[res.first]){
        res.second ^= dis[res.first];
        res.first = par[res.first];
    }
    //cout << "return " << res.first << "," << res.second << endl;
    return res;
}
void join(int a, int b, int x){
    if(card[a] > card[b]){
        card[a] += card[b]; par[b] = a; dis[b] = x;
    }else{
        card[b] += card[a]; par[a] = b; dis[a] = x;
    }
}


int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> q;
    //cout << "HAI" << endl;
    // initDSU();
    int last = 0;
    for(int i=0; i<q; i++){
        cin >> t >> a >> b; 
        a ^= last; b^= last; 
        if(a > b) swap(a, b);
        //cout << "query " << t << " " << a << " " << b << endl;
        b++;
        if(card.count(a) == 0){
            card[a] = 1; par[a] = a; dis[a] = 0;
        }
        if(card.count(b) == 0){
            card[b] = 1; par[b] = b; dis[b] = 0;
        }
        //cout << "HAI" << endl;
        pair<int, int> temp1 = getAncestor(a), temp2 = getAncestor(b);
        //cout << "HAI" << endl;
        if(t == 1){
            cin >> x; x ^= last;
            //cout << a << b << x << endl;
            if(temp1.first != temp2.first){
                join(temp1.first, temp2.first, (x ^ temp1.second ^ temp2.second));
            }
        }else{
            if(temp1.first == temp2.first){
                cout << (temp1.second ^ temp2.second) << endl;
                last = (temp1.second ^ temp2.second);
            }else{
                cout << -1 << endl;
                last = 1;
            }
        }
    }
}

