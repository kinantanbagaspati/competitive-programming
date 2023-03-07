#include<bits/stdc++.h>
using namespace std;
#define pll pair<long long, long long>

const long long mod = 998244353;
const long long root = 15311432;
const long long root_1 = 469870224;
const long long root_pw = 1 << 23;

long long pangkat(long long a, long long b){
    long long res = 1;
    while(b>0){
        if(b%2){res = res*a%mod;}
        a = a*a%mod; b /= 2;
    }
    return res;
}
long long inverse(long long a){
    return pangkat(a, mod-2);
}

void fft(vector<long long> & a, bool invert) {
    int n = a.size();

    for (int i = 1, j = 0; i < n; i++) {
        int bit = n >> 1;
        for (; j & bit; bit >>= 1)
            j ^= bit;
        j ^= bit;

        if (i < j)
            swap(a[i], a[j]);
    }

    for (int len = 2; len <= n; len <<= 1) {
        int wlen = invert ? root_1 : root;
        for (int i = len; i < root_pw; i <<= 1)
            wlen = (int)(1LL * wlen * wlen % mod);

        for (int i = 0; i < n; i += len) {
            int w = 1;
            for (int j = 0; j < len / 2; j++) {
                int u = a[i+j], v = (int)(1LL * a[i+j+len/2] * w % mod);
                a[i+j] = u + v < mod ? u + v : u + v - mod;
                a[i+j+len/2] = u - v >= 0 ? u - v : u - v + mod;
                w = (int)(1LL * w * wlen % mod);
            }
        }
    }

    if (invert) {
        int n_1 = inverse(n);
        for(int i=0; i<n; i++){
            a[i] = 1LL * a[i] * n_1 % mod;
        }
    }
}

void multiply(vector<long long>& a, vector<long long>& b, vector<long long>& c) {
    long long n = 1;
    while (n < a.size() + b.size())
        n <<= 1;
    a.resize(n);
    b.resize(n);

    fft(a, false);
    fft(b, false);

    c.clear();
    for (int i = 0; i < n; i++)
        c.push_back(a[i] * b[i] % mod);

    fft(c, true);
}

void square(vector<long long>& a, vector<long long>& res){
    long long n = 1;
    while (n < a.size() + a.size())
        n <<= 1;
    a.resize(n);

    fft(a, false);
    res.clear();
    for (int i = 0; i < n; i++)
        res.push_back(a[i] * a[i] % mod);

    fft(res, true);
}


long long n, k, f, sum;
vector<long long> atas, bawah;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    /*tes fft
    pa.push_back(0);
    pa.push_back(1);
    pa.push_back(2);
    pb.push_back(2);
    pb.push_back(3);
    pb.push_back(4);

    multiply(pa, pb, pc);
    for(int i=0; i<pc.size(); i++){
        cout << pc[i] << " ";
    }cout << endl;
    */
    cin >> n >> k >> f;
    atas.assign(k+1, 1);

    square(atas, bawah);
    //cout << bawah[f] << endl;
    n--;
    while(n--){
        //cout << "masuk while" << endl;
        atas.resize(k+1);
        //cout << "kelar assign" << endl;
        sum = 0;
        for(int i=bawah.size()-1; i>k; i--){
            sum = (sum + bawah[i]) % mod;
        }
        for(int i=k; i>=0; i--){
            atas[i] = (bawah[i]*(k+1-i) + sum) % mod;
            sum = (sum + bawah[i]) % mod;
        }

        //cout << "multiply saat n=" << n << endl;
        square(atas, bawah);
    }
    if(f < bawah.size()){
        cout << bawah[f] << endl;
    }else{
        cout << 0 << endl;
    }
}

/*
x 0 1 2 3 4 5
0 0 0 0 0 0 0
1 0 1 1 1 1 1
2 0 1 2 2 2 2
3 0 1 2 3 3 3
*/
