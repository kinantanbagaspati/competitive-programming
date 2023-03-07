#include <bits/stdc++.h>
using namespace std;

bool sieve[1000069];

void init(){
    sieve[0] = false;
    sieve[1] = false;
    for(int i=2; i<1000069; i++){
        sieve[i] = true;
    }

    for(long long i=2; i<1000069; i++){
        if(sieve[i]){
            for(long long j=i; i*j<1000069; j++){
                sieve[i*j] = false;
            }
        }
    }
}

long long nbdiv(long long x){
    long long res = 1, cur;
    for(int i=2; i*i<=x; i++){
        cur = 0;
        if(sieve[i]){
            while(x%i == 0){
                cur++;
                x/=i;
            }
            res *= (cur+1);
        }
    }
    if(x>1){res *= 2;}
    return res;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    init();
    long long n, x;
    cin >> n;
    while(n--){
        cin >> x;
        cout << nbdiv(x) << endl;
    }
}
