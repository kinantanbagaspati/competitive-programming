#include <bits/stdc++.h>
using namespace std;
#define pll pair<long long, long long>

string s;
long long n, h1, m1, s1, h2, m2, s2, ans;

long long subuh = 8*3600 + 30*60, pagi = 9*3600 + 30*60, siang = 12*3600 + 30*60;
long long masuk, keluar;

long long toSec(long long h, long long m, long long s){
    return 3600*h + 60*m + s;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin >> n;
    while(n > 0){
        ans = 0;
        while(n--){
            cin >> s;
            int idx = 2;
            h1 = s[idx] - '0'; idx++;
            if(s[idx] != ':'){
                h1 = 10*h1 + s[idx] - '0'; idx++;
            }
            m1 = 10*(s[idx+1]-'0') + (s[idx+2]-'0');
            s1 = 10*(s[idx+4]-'0') + (s[idx+5]-'0');
            idx += 7;
            masuk = toSec(h1, m1, s1);

            h2 = s[idx] - '0'; idx++;
            if(s[idx] != ':'){
                h2 = 10*h2 + s[idx] - '0'; idx++;
            }
            m2 = 10*(s[idx+1]-'0') + (s[idx+2]-'0');
            s2 = 10*(s[idx+4]-'0') + (s[idx+5]-'0');
            idx += 7;
            keluar = toSec(h2, m2, s2);

            //cout << h1 << " " << m1 << " " << s1 << endl;
            //cout << h2 << " " << m2 << " " << s2 << endl;

            if(s[0] == 'D'){
                if(masuk > pagi || keluar - max(subuh, masuk) < 8*3600){
                    ans++;
                }
            }else{
                if(masuk > siang || keluar - max(subuh, masuk) < 9*3600){
                    ans++;
                }
            }
        }
        if(ans == 0){
            cout << "All OK\n";
        }else if(ans > 3){
            cout << "Issue Show Cause Letter\n";
        }else{
            cout << ans << " Point(s) Deducted\n";
        }
        cin >> n;
    }
}
