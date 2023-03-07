#include<bits/stdc++.h>
using namespace std;
#define pll pair<long long, long long>

long long t, n, k, freq[32][2];
long long minsum, allsum;
string s;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--){
        cin >> n >> k >> s;
        for(int i=0; i<32; i++){
            freq[i][0] = 0; freq[i][1] = 0;
        }
        for(int i=0; i<n; i++){
            freq[(int) s[i] % 32][s[i] < 'a']++;
        }
        minsum = 0; allsum = 0;
        for(int i=0; i<32; i++){
            minsum += min(freq[i][0], freq[i][1]);
            allsum += (freq[i][0] + freq[i][1])/2;
        }
        cout << min(minsum+k, allsum) << endl;
    }
}
