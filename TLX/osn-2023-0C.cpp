#include<bits/stdc++.h>
using namespace std;

long long n, ma = 0, mb = 0, mc = 0, md = 0;

int main(){
    cin >> n;

    for(long long a = max(sqrt(n)-40, (double)0); a <= sqrt(n)+1; a++){
        if(a*a >= n){
            if(abs(a*a - n) < abs(ma*ma + mb*mb + mc*mc + md*md - n)){
                ma = a; mb = 0; mc = 0; md = 0;
            }
            continue;
        }
        for(long long b = max(sqrt(n-a*a)-40, (double)0); b <= sqrt(n-a*a)+1; b++){
            if(a*a + b*b >= n){
                if(abs(a*a + b*b - n) < abs(ma*ma + mb*mb + mc*mc + md*md - n)){
                    ma = a; mb = b; mc = 0; md = 0;
                }
                continue;
            }
            for(long long c = max(sqrt(n-a*a-b*b)-40, (double)0); c <= sqrt(n-a*a-c*c)+1; c++){
                if(a*a + b*b + c*c >= n){
                    if(abs(a*a + b*b + c*c - n) < abs(ma*ma + mb*mb + mc*mc + md*md - n)){
                        ma = a; mb = b; mc = c; md = 0;
                    }
                    continue;
                }
                for(long long d = max(sqrt(n-a*a-b*b-c*c)-40, (double)0); d <= sqrt(n-a*a-b*b-c*c)+1; d++){
                    if(abs(a*a + b*b +c*c + d*d - n) < abs(ma*ma + mb*mb + mc*mc + md*md - n)){
                        ma = a; mb = b; mc = c; md = d;
                    }
                }
            }
        }
    }

    cout << ma << " " << mb << " " << mc << " " << md << endl;
}