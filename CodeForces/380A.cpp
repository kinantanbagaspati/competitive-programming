#include<bits/stdc++.h>
using namespace std;

const long long maxn = 131072;
long long m, n, arr[maxn], info[maxn][3];
long long t, a, b, len=0, nbinfo=0, curinfo=0;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> m;
    while(m--){
        cin >> t >> a; t--;
        if(!t){
            if(len < maxn){
                arr[len] = a;
            }else{
                info[nbinfo][0] = 0; info[nbinfo][1] = len; info[nbinfo][2] = a;
                nbinfo++;
            }
            len++;
        }else{
            cin >> b;
            long long sampe = len + a*b;
            for(long long i=len; i<min(sampe, maxn); i++){
                arr[i] = arr[(i-len)%a];
            }
            if(sampe > maxn){
                info[nbinfo][0] = 1; info[nbinfo][1] = len; info[nbinfo][2] = a;
                nbinfo++;
            }
            len = sampe;
        }
    }
    cin >> n;
    while(n--){
        cin >> a; a--;
        if(a < maxn){
            cout << arr[a] << ' ';
        }else{
            while(curinfo < nbinfo-1 && info[curinfo+1][1] <= a){
                curinfo++;
            }
            if(info[curinfo][0]){
                cout << arr[(a-info[curinfo][1]) % info[curinfo][2]] << ' ';
            }else{
                cout << info[curinfo][2] << ' ';
            }
        }
    }
    cout << endl;

}

