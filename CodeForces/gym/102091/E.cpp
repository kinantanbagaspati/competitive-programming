#include <bits/stdc++.h>
using namespace std;
#define pll pair<long long, long long>

const long long maxn = 128;
int t, a[maxn], n;
int batas[maxn][2], nbcc=0;
bool geser[maxn][2];

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin >> t;
    for(int tt=1; tt<=t; tt++){
        cin >> n;
        for(int i=0; i<n; i++){
            cin >> a[i];
        }
        sort(a, a+n);
        batas[0][0] = 0; nbcc = 1;
        for(int i=1; i<n; i++){
            if(a[i] - a[i-1] > 2){
                batas[nbcc-1][1] = i-1;
                batas[nbcc][0] = i;
                nbcc++;
            }
        }
        batas[nbcc-1][1] = n-1;

        for(int i=0; i<nbcc; i++){
            geser[i][0] = (batas[i][1] - batas[i][0] == 0) || (a[batas[i][0]+1] - a[batas[i][0]] == 1);
            geser[i][1] = (batas[i][1] - batas[i][0] == 0) || (a[batas[i][1]] - a[batas[i][1]-1] == 1);
        }

        int ans = 0;
        for(int i=0; i<nbcc; i++){
            cout << batas[i][0] << " " << batas[i][1] << endl;
            if(i<nbcc){
                if(geser){ // bisa geser kanan
                    if(a[batas[i+1][0]] - a[batas[i][1]] == 3){ // udah konek

                    }else if(){

                    }
                }
            }
            if(i>0){
                if(a[batas[i][0]] - a[batas[i-1][1]] == 3){

                }
            }
            if(0<i && i < nbcc-1){

            }
        }
    }
}

/*
1->2: 0 1
2->3: 0 1
3->4: 1 0
4->5: 1 0
*/
