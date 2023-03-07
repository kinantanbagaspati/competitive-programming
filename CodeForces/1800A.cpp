#include<bits/stdc++.h>
using namespace std;
#define pll pair<long long, long long>

long long t, n;
string text, pat, add;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--){
        cin >> n >> text;
        add = "m"; pat = "";
        for(int i=0; i<n; i++){
            if(text[i] >= 'a'){
                if(text[i] != add[0]){
                    pat += add; add[0] = text[i];
                }
            }else{
                if(text[i] != add[0] + ('A'-'a')){
                    pat += add; add[0] = text[i] + ('a'-'A');
                }
            }
        }
        //cout << pat + add << endl;
        if(pat + add == "meow"){
            cout << "YES" << endl;
        }else{
            cout << "NO" << endl;
        }
    }
}
