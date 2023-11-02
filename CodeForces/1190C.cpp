#include<bits/stdc++.h>
using namespace std;
#define pll pair<long long, long long>

const int maxn = 131072;
int n, k, temp, terkiri, terkanan, cek[2];
char cur;
string s, t;
pll templl;
set<pll> batasKiri, batasKanan;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n >> k >> s;
    cur = s[0]; temp = 0;
    bool isFirst = true;
    for(int i=1; i<n; i++){
        if(s[i] != cur){
            batasKiri.insert({-temp, cur});
            batasKanan.insert({i-1, cur});
            if(isFirst){
                terkiri = i-1; isFirst = false;
            }
            cur = s[i];
            temp = i;
        }
    }
    batasKiri.insert({-temp, cur});
    batasKanan.insert({n-1, cur});
    terkanan = temp;
    bool menang2 = true;

    for(int i=0; i<=n-k; i++){
        //i sampai i+k-1
        int kiri = terkiri, kanan = terkanan;

        // masukin 0
        //cout << i << " " << kiri+1 << endl;
        if(i <= kiri+1){
            if(s[0] == '0' || i == 0){
                templl = *(batasKanan.lower_bound({i+k, 0}));
                if(templl.second == '0'){
                    kiri = templl.first;
                }else{
                    kiri = i+k-1;
                }
            }else{
                kiri = i-1;
            }
        }
        if(i+k-1 >= kanan-1){
            if(s[n-1] == '0' || i == n-k){
                templl = *(batasKiri.lower_bound({-i+1, 0}));
                if(templl.second == '0'){
                    kanan = -templl.first;
                }else{
                    kanan = i;
                }
            }else{
                kanan = i+k;
            }
        }
        //cout << "0-kiri-kanan: " << kiri << " " << kanan << endl;
        cek[0] = 0; cek[1] = 0;
        if(i==0){
            cek[0] += kiri+1;
        }else{
            cek[s[0]-'0'] += kiri+1;
        }
        if(i==n-k){
            cek[0] += n-kanan;
        }else{
            cek[s[n-1]-'0'] += n-kanan;
        }
        if(max(cek[0],cek[1]) >= n){
            cout << "tokitsukaze" << endl;
            return 0;
        }
        menang2 = menang2 && (max(cek[0],cek[1]) >= n-k);

        // masukin 1
        if(i <= kiri+1){
            if(s[0] == '1' || i == 0){
                templl = *(batasKanan.lower_bound({i+k, 0}));
                if(templl.second == '1'){
                    kiri = templl.first;
                }else{
                    kiri = i+k-1;
                }
            }else{
                kiri = i-1;
            }
        }
        if(i+k-1 >= kanan-1){
            if(s[n-1] == '1' || i == n-k){
                templl = *(batasKiri.lower_bound({-i+1, 0}));
                if(templl.second == '1'){
                    kanan = -templl.first;
                }else{
                    kanan = i;
                }
            }else{
                kanan = i+k;
            }
        }
        //cout << "1-kiri-kanan: " << kiri << " " << kanan << endl;
        cek[0] = 0; cek[1] = 0;
        if(i==0){
            cek[1] += kiri+1;
        }else{
            cek[s[0]-'0'] += kiri+1;
        }
        if(i==n-k){
            cek[1] += n-kanan;
        }else{
            cek[s[n-1]-'0'] += n-kanan;
        }
        if(max(cek[0],cek[1]) >= n){
            cout << "tokitsukaze" << endl;
            return 0;
        }
        menang2 = menang2 && (max(cek[0],cek[1]) >= n-k);
    }
    if(menang2){
        cout << "quailty" << endl;
    }else{
        cout << "once again" << endl;
    }
}