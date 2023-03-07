#include<bits/stdc++.h>
using namespace std;
#define pll pair<long long, long long>

const long long maxn = 262144;
long long t, n, a, curval, curidx;
// linked list
long long kiri[maxn], kanan[maxn], value[maxn];
set<pll> s;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--){
        cin >> n;
        curval = 0; curidx = 1;
        while(n--){
            cin >> a;
            if((a<0 && 0<curval) || (a>0 && 0>curval)){
                value[curidx] = abs(curval);
                curval = 0; curidx++;
            }
            curval += a;
        }
        n = curidx;
        value[n] = abs(curval);
        s.clear();
        //cout << "value:";
        for(int i=1; i<=n; i++){
            kiri[i] = i-1;
            s.insert({value[i], i});
            //cout << " " << value[i];
            kanan[i] = i+1;
        }
        //cout << endl;
        curval = 0;
        while(s.size() > 1){
            curval = (*s.begin()).first;
            curidx = (*s.begin()).second;
            //cout << "head: " << curval << " " << curidx << endl;
            s.erase(s.begin());
            if(kiri[curidx] == 0){
                //kanan[curidx] <= n
                kiri[kanan[curidx]] = 0;
            }else if(kanan[curidx] == n+1){
                //kiri[curidx] > 0
                kanan[kiri[curidx]] = n+1;
            }else{
                s.erase({value[kanan[curidx]], kanan[curidx]});
                s.erase({value[kiri[curidx]], kiri[curidx]});
                value[kiri[curidx]] += value[kanan[curidx]] - curval;
                kanan[kiri[curidx]] = kanan[kanan[curidx]];
                kiri[kanan[kanan[curidx]]] = kiri[curidx];
                //cout << "masuk " << value[kiri[curidx]] << " " << kiri[curidx] << endl;
                s.insert({value[kiri[curidx]], kiri[curidx]});
            }
        }
        cout << (*s.begin()).first << endl;
    }
}
