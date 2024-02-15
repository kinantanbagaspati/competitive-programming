#include<bits/stdc++.h>
using namespace std;
#define pll pair<long long, long long>

const int maxn = 262144;
int n, q, m, b;
int a[maxn], info[maxn][3];

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n >> q >> m;
    for(int i=1; i<=n; i++){
        cin >> a[i];
    }
    for(int i=0; i<q; i++){
        cin >> info[i][0] >> info[i][1] >> info[i][2];
    }
    for(int i=0; i<m; i++){
        cin >> b;
        //cout << b;
        for(int j=q-1; j>=0; j--){
            if(info[j][1] <= b && b <= info[j][2]){
                if(info[j][0] > 1){
                    b = info[j][2] - b + info[j][1];
                }else if(info[j][1] < b){
                    b--;
                }else{
                    b = info[j][2];
                }
            }
            //cout << " -> " << b;
        }
        //cout << endl << "ans " << a[b] << endl;;
        cout << a[b] << ' ';
    } cout << endl;
}