#include <bits/stdc++.h>
using namespace std;

int n, x, akar, freq[1000069];

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n;
    while(n--){
        cin >> x;
        akar = sqrt(x);
        for(int i=1; i <= akar; i++){
            if(!(x%i)){
                freq[i]++;
                freq[x/i]++;
            }
        }
        if(akar*akar == x){
            freq[akar]--;
        }
    }
    for(int i=1000068; i>=0; i--){
        if(freq[i] > 1){
            cout << i << endl;
            return 0;
        }
    }
}
