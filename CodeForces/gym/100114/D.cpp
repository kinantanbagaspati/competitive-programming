#include <bits/stdc++.h>
using namespace std;

const int maxlen = 131072;
int len, ans[maxlen][2], nbLeft=0, nbRight=maxlen-1;
string s;

int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> len >> s; len++; s += ".";

    bool isShift = false;
    for(int i=0; i<len; i++){
        if(isShift){
            if(s[i] == '.'){
                if(ans[nbLeft-1][1] == i-1){
                    isShift = false;
                }else if(i < len-1 && s[i+1] == '*'){
                    ans[nbRight][1] = i;
                    nbRight--;
                }else{
                    ans[nbLeft][0] = 1;
                    ans[nbLeft][1] = i-1;
                    nbLeft++; isShift = false;
                }
            }
        }else if(s[i] == '*'){
            ans[nbLeft][0] = 0;
            ans[nbLeft][1] = i;
            nbLeft++; isShift = true;
        }
    }
    cout << nbLeft + maxlen-1-nbRight << endl;
    for(int i=0; i<nbLeft; i++){
        if(ans[i][0]){
            cout << "Shift+" << ans[i][1] + 1 << endl;
        }else{
            cout << "Ctrl+" << ans[i][1] + 1 << endl;
        }
    }
    for(int i=maxlen-1; i>nbRight; i--){
        cout << "Ctrl+" << ans[i][1]+1 << endl;
    }
}
