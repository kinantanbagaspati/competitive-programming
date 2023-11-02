#include<bits/stdc++.h>
using namespace std;
#define pll pair<long long, long long>

long long getLen(long long x){
    long long pw10 = 10, pw = 1, ans = 0;
    while(pw10 <= x){
        ans += (x + 1 - pw10/10 + x + 2 - pw10) * pw10 / 20 * 9 * pw;
        pw10 *= 10; pw++;
    } // pw10/10 <= x < pw10
    x -= pw10/10 -1;
    return ans + x * (x+1) / 2 * pw;
}
long long getDigit(long long x){
    long long lo = 1, hi = 10, digit = 1;
    while(x > (hi-lo)*digit){
        x -= (hi-lo)*digit;
        lo *= 10; hi *= 10; digit++;
    }
    long long num = lo + (x-1)/digit;
    x = (x-1) % digit + 1;
    x = digit - x;
    while(x > 0){
        num /= 10; x--;
    }
    return num % 10;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    long long t, x;
    cin >> t;
    while(t--){
        cin >> x;
        long long lo = 0, hi = 500000000, mid;
        while(hi-lo > 1){
            mid = (lo+hi)/2;
            //cout << mid << ": " << getLen(mid) << endl;
            if(getLen(mid) < x){
                lo = mid;
            }else{
                hi = mid;
            }
        }
        //cout << "lo hi " << lo << " " << hi << endl;
        x -= getLen(lo);
        //cout << "x " << x << endl;
        cout << getDigit(x) << endl;
    }
}