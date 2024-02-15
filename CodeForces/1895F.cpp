#include<bits/stdc++.h>
using namespace std;
#define pll pair<long long, long long>

const long long mod = 1e9+7;
long long t, n, x, k, ans;
long long expo[32][64][64], except[32][50];

long long pangkat(long long a, long long b){
    a %= mod; b %= mod-1;
    long long ret = 1;
    while(b>0){
        if(b%2){ret = ret * a % mod;}
        a = a * a % mod; b /= 2;
    }
    return ret;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--){
        cin >> n >> x >> k; n--;
        ans = (x + k) * pangkat(k*2+1, n) % mod;

        for(int i=0; i<x; i++){
            for(int j=0; j<x; j++){
                expo[0][i][j] = (abs(j-i) <= k);
            }
        }
        
        for(int i=0; i<x; i++){
            except[0][i] = 1;
        }
        for(int i=1; i<=31; i++){
            if(n % 2){
                for(int p=0; p<x; p++){
                    except[i][p] = 0;
                    for(int q=0; q<x; q++){
                        except[i][p] = (expo[i-1][p][q] * except[i-1][q] + except[i][p]) % mod;
                    }
                }
            }else{
                for(int j=0; j<x; j++){
                    except[i][j] = except[i-1][j];
                }
            } n /= 2;
            /*cout << "except:";
            for(int j=0; j<x; j++){
                cout << ' ' << except[i][j];
            } cout << endl;*/
            // itung expo
            for(int p=0; p<x; p++){
                for(int q=0; q<x; q++){
                    expo[i][p][q] = 0;
                    for(int r=0; r<x; r++){
                        expo[i][p][q] = (expo[i-1][p][r] * expo[i-1][r][q] + expo[i][p][q]) % mod;
                    }
                }
            }
        }
        for(int i=0; i<x; i++){
            ans = (ans + mod - except[31][i]) % mod;
        }
        cout << ans << endl;
    }
}