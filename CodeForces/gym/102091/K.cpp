#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define pii pair<int, int>

typedef tree<pii,null_type,less<pii>,rb_tree_tag,tree_order_statistics_node_update> order_set;

const int maxe = 131072;
int t, e, infos[maxe][3];
int tipe, curt, v, endt;
order_set os;
multiset<pii> expt;

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin >> t;
    for(int tt=1; tt<=t; tt++){
        cout << "Case " << tt << ":\n";
        cin >> e;
        os.clear();
        expt.clear();
        for(int i=0; i<e; i++){
            cin >> tipe >> curt >> v; tipe--;
            if(tipe){
                bool udh = false;
                while(!(expt.empty()) && !udh){
                    pii depan = *(expt.begin());
                    //cout << "mau dihapus: " << depan.first << " " << depan.second << endl;
                    udh = depan.first >= curt;
                    if(!udh){
                        //cout << "hapus " << depan.second << endl;
                        expt.erase(depan);
                        os.erase({infos[depan.second][1], depan.second});
                    }
                }
                //cout << "sizes: " << expt.size() << " " << os.size() << endl;
                v--;
                if(v < expt.size()){
                    cout << (*(os.find_by_order(v))).first << '\n';
                }else{
                    cout << "-1\n";
                }
            }else{
                cin >> endt;
                infos[i][0] = curt; infos[i][1] = v; infos[i][2] = endt;
                expt.insert({endt, i});
                os.insert({v, i});
            }
        }
    }
}
