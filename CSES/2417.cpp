#include <bits/stdc++.h>
using namespace std;

bool sv[1000069];
vector<int> primes;
void init(){
    //cout << "halo" << endl;
    for(int i=2; i<1000069; i++){
        //cout << i << endl;
        if(!sv[i]){
            primes.push_back(i);
            for(int j=i; j<1000069; j+=i){
                sv[j] = true;
            }
        }
    }
    //cout << "halo" << endl;
    /*
    for(int i=0; i<20; i++){
        cout << primes[i] << endl;
    }
    */
}

int n, x, akar, freq[1000069];

int squarefree(int x){
    int ret = 0;
    for(int i=0; primes[i]*primes[i]<=x; i++){
        int pw = 0;
        while(!(x%primes[i])){
            pw++; x/=primes[i];
        }
        if(pw>1){return 0;}
        if(pw==1){ret++;}
    }
    if(x>1){ret++;}
    return ret;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    init();
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
    long long ans = (long long)freq[1]*(freq[1]-1)/2, deg;
    for(int i=2; i<1000069; i++){
        deg = squarefree(i);
        if(deg>0){
            if(deg%2){
                ans -= (long long)freq[i]*(freq[i]-1)/2;
            }else{
                ans += (long long)freq[i]*(freq[i]-1)/2;
            }
        }
    }
    cout << ans << endl;
}
