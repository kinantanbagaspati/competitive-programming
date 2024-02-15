#include<bits/stdc++.h>
using namespace std;
#define pll pair<long long, long long>

const long long maxn = 262144;
long long n, add[16][16][64], ans = 0, sum, cur, len;
string s[maxn];

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n;
    for(long long i=0; i<n; i++){
        cin >> s[i];
        sum = 0; len = s[i].length();
        for(long long j=0; j<len; j++){
            sum += (s[i][j] - '0');
        }
        cur = 0;
        for(long long j=1; j<=5; j++){
            if(j <= len){
                cur += (s[i][len-j] - '0');
            }
            if(j*2 > len && 2*cur > sum){
                add[j][len][2*cur - sum]++;
            }
        }
    }

    for(long long i=0; i<n; i++){
        sum = 0; len = s[i].length();
        for(long long j=0; j<len; j++){
            sum += (s[i][j] - '0');
        }
        cur = 0;
        for(long long j=1; j<=5; j++){
            if(j<=len){
                cur += (s[i][j-1] - '0');
            }
            if(j*2 > len && 2*cur > sum){
                ans += add[j][2*j - len][2*cur - sum];
            }
        }
    }

    cout << ans << endl;
}
