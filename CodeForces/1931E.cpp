#include<bits/stdc++.h>
using namespace std;
#define pll pair<long long, long long>

const long long maxn = 262144;
int t, n, m, sum, trail[maxn];
string s;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--){
        cin >> n >> m; sum=0;
        for(int i=0; i<n; i++){
            cin >> s; sum += s.length();
            trail[i] = 0;
            for(int j=0; j<s.length(); j++){
                trail[i] += (s[j]=='0');
                if(s[j]!='0') trail[i]=0;
            }
        }
        sort(trail, trail+n);
        for(int i=n-1; i>=0; i--){
            if((n-i)%2){
                sum -= trail[i];
            }
        }
        if(sum > m){
            cout << "Sasha" << endl;
        }else{
            cout << "Anna" << endl;
        }
    }
}