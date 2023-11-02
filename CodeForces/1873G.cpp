#include<bits/stdc++.h>
using namespace std;
#define pll pair<long long, long long>

long long t, srt[262144], as, bs, kiri, ans;
string s;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--){
        cin >> s; kiri = -1; ans = 0;
        as = 0; bs = 0;
        for(int i=0; i<s.length(); i++){
            if(s[i] == 'B'){
                if(i-kiri-1 > 0){
                    srt[as] = i-kiri-1; as++;   
                }
                bs++; kiri = i;
            }
        }
        if(kiri < s.length()-1){
            srt[as] = s.length() - kiri - 1; as++;
        }
        sort(srt, srt + as);
        for(int i=as-1; i>=0 && bs>0; i--){
            ans += srt[i]; bs--;
        }
        cout << ans << endl;
    }
}