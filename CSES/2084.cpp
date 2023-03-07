#include <bits/stdc++.h>
using namespace std;

long long n, nblines = 1;
long long m[200069], c[200069], starts[200069];
long long s, f, a[200069], b[200069];

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    c[0] = 0;
    starts[0] = 0;
    cin >> n >> m[0];

    for(int nn=0; nn<n; nn++){
        cin >> a[nn];
    }
    for(int nn=0; nn<n; nn++){
        cin >> b[nn];
    }

    for(int nn=0; nn<n-1; nn++){
        s = a[nn];
        f = b[nn];
        long long mid, lo = 0, hi = nblines;
        while(hi-lo>1){
            mid = (lo+hi)/2;
            if(s < starts[mid]){
                hi = mid;
            }else{
                lo = mid;
            }
        }

        m[nblines] = f;
        c[nblines] = m[lo] * s + c[lo];
        //cout << c[nblines] << endl;
        while(m[nblines]*starts[nblines-1] + c[nblines] < m[nblines-1]*starts[nblines-1] + c[nblines-1]){
            m[nblines-1] = m[nblines];
            c[nblines-1] = c[nblines];
            nblines--;
        }
        if(m[nblines] < m[nblines-1]){
            starts[nblines] = (c[nblines] - c[nblines-1] + m[nblines-1] - m[nblines] - 1)/(m[nblines-1] - m[nblines]);
            nblines++;
        }
    }
    s = a[n-1];
    f = b[n-1];
    long long mid, lo = 0, hi = nblines;
    while(hi-lo>1){
        mid = (lo+hi)/2;
        if(s < starts[mid]){
            hi = mid;
        }else{
            lo = mid;
        }
    }
    cout << m[lo] * s + c[lo] << endl;
}
