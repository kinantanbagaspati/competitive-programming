#include<bits/stdc++.h>
using namespace std;
#define pll pair<long long, long long>

const int maxn = 131072;
int n, a;
vector<int> v;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> a;
        if(v.size() == 0 || v[v.size()-1] < a){
            v.push_back(a);
        }
        int lo = -1, hi = v.size()-1;
        while(hi-lo>1){
            int mid = (lo+hi)/2;
            if(v[mid] < a){
                lo = mid;
            }else{
                hi = mid;
            }
        }
        v[hi] = a;
    }
    cout << v.size() << endl;
}