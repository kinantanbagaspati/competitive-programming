#include<bits/stdc++.h>
using namespace std;
#define pll pair<long long, long long>

const int maxn = 262144;
int n, pw2[32], freq[maxn][32], bitval[maxn], bitsum;
string s;
map<int, int> m;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> s;
        bitval[i] = 0;
        for(int j=0; j<s.length(); j++){
            freq[i][s[j]-'a']++;
            bitval[i] ^= (1 << (s[j]-'a'));
        }
    }
    long long ans = 0;
    for(int i=0; i<26; i++){
        bitsum = (1 << 26) - 1 - (1 << i);
        m.clear();
        for(int j=0; j<n; j++){
            if(freq[j][i] == 0){
                ans = ans + m[bitsum ^ bitval[j]];
                m[bitval[j]]++;
            }
        }
    }
    cout << ans << endl;
}
