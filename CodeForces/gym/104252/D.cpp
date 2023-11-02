#include<bits/stdc++.h>
using namespace std;

int n, h, w;
char c;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n >> h >> w;
    while(n--){
        cin >> c;
        if(c == 'Y'){
            cout << "Y ";
            h--; w++;
        }else if(w == 0){
            cout << "Y ";
            h--; w++;
        }else{
            cout << "N ";
        }
        cin >> c;
        if(c == 'Y'){
            cout << "Y" << endl;
            w--; h++;
        }else if(h == 0){
            cout << "Y" << endl;
            w--; h++;
        }else{
            cout << "N" << endl;
        }
    }
}