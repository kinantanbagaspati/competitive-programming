#include <bits/stdc++.h>
using namespace std;
#define pll pair<long long, long long>

const long long mod = 78294349, maxn = 256;

long long ans;
int t, n, m;
unsigned short nbcolor, board[maxn][maxn], to[maxn*maxn], pangkat[maxn*maxn];
void printBoard(){
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cout << board[i][j] << " ";
        }cout << endl;
    }cout << endl;
}
char c;
unsigned short factors[maxn*maxn][16], power[maxn*maxn][16], nbfactors[maxn*maxn];

void init(){
    for(int i=1; i<maxn*maxn; i++){
        int cpy = i;
        for(int j=2; j*j <= cpy; j++){
            if(cpy % j == 0){
                factors[i][(int) nbfactors[i]] = j;
                int pw = 0;
                while(cpy % j == 0){
                    cpy /= j; pw++;
                }
                power[i][nbfactors[i]] = pw;
                nbfactors[i]++;
            }
        }
        if(cpy > 1){
            factors[i][nbfactors[i]] = cpy;
            power[i][nbfactors[i]] = 1;
            nbfactors[i]++;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    init();
    cin >> t;
    for(int tt=1; tt<=t; tt++){
        cin >> n >> m;
        nbcolor = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                cin >> c;
                if(c == '#'){
                    nbcolor++; board[i][j] = nbcolor;
                }else{
                    board[i][j] = 0;
                }
            }
        }
        //printBoard();

        // atas
        for(int j=0; j<m; j++){
            int idx = 0;
            for(int i=0; i<n; i++){
                if(board[i][j]>0){
                    board[idx][j] = board[i][j]; idx++;
                }
            }
            while(idx<n){
                board[idx][j] = 0; idx++;
            }
        }
        //printBoard();

        // kanan
        for(int i=0; i<n; i++){
            int idx = m-1;
            for(int j=m-1; j>=0; j--){
                if(board[i][j]>0){
                    board[i][idx] = board[i][j]; idx--;
                }
            }
            while(idx>=0){
                board[i][idx] = 0; idx--;
            }
        }
        //printBoard();

        // bawah
        for(int j=0; j<m; j++){
            int idx = n-1;
            for(int i=n-1; i>=0; i--){
                if(board[i][j]>0){
                    board[idx][j] = board[i][j]; idx--;
                }
            }
            while(idx>=0){
                board[idx][j] = 0; idx--;
            }
        }
        //printBoard();

        // kiri
        for(int i=0; i<n; i++){
            int idx = 0;
            for(int j=0; j<m; j++){
                if(board[i][j]>0){
                    board[i][idx] = board[i][j]; idx++;
                }
            }
            while(idx<m){
                board[i][idx] = 0; idx++;
            }
        }
        //printBoard();

        nbcolor = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(board[i][j] > 0){
                    nbcolor++; to[nbcolor] = board[i][j];
                }
            }
        }
        int cur, idx, prv;
        for(int i=2; i<=nbcolor; i++){
            pangkat[i] = 0;
        }
        ans = 1;
        for(int i=1; i<=nbcolor; i++){
            if(to[i] > 0){
                cur = 1; idx = to[i]; to[i] = 0;
                while(idx != i){
                    cur++;
                    prv = idx;
                    idx = to[idx];
                    to[prv] = 0;
                }
                // cout << "cur " << cur << " " << factors[cur].size() << endl;
                for(int j=0; j<nbfactors[cur]; j++){
                    while(pangkat[factors[cur][j]] < power[cur][j]){
                        pangkat[factors[cur][j]]++;
                        ans = ans * factors[cur][j] % mod;
                    }
                }
            }
        }
        cout << "Case " << tt << ": " << ans << '\n';
    }
}
