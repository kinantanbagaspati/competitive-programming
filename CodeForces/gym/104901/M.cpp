#include<bits/stdc++.h>
using namespace std;
#define pdl pair<double, long long>
#define pll pair<long long, long long>

const long long maxn = 2048;
double PI = acos(-1);
long long n, szb, szt, sza, ans;
pll points[maxn], bawah[maxn], tengah[maxn], atas[maxn];
pdl srt[maxn];

double getArg(pll a, pll b){
    return atan2(b.second-a.second, b.first-a.first);
}
long long area(pll x, pll y, pll z){
    return abs(
        x.first*y.second + y.first*z.second + z.first*x.second
        - x.second*y.first - y.second*z.first - z.second*x.first
    );
}
bool isInside(pll p, pll x, pll y, pll z){
    return (area(p,x,y)+area(p,y,z)+area(p,z,x) == area(x,y,z));
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //cout << isInside({1,1}, {0,0}, {3,-2}, {2,3}) << endl;
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> points[i].first >> points[i].second;
    }
    sort(points, points+n);
    bawah[0] = points[0]; szb = 1;
    atas[0] = points[0]; sza = 1;
    for(int i=1; i<n; i++){
        //cout << points[i].first << "," << points[i].second << endl;
        //cout << getArg(bawah[szb-1], bawah[szb-2]) << " > " << getArg(points[i], bawah[szb-1]) << endl;
        while(szb>1 && getArg(bawah[szb-2], bawah[szb-1]) > getArg(bawah[szb-1], points[i])){
            szb--;
        }
        bawah[szb] = points[i]; szb++;
        while(sza>1 && getArg(atas[sza-2], atas[sza-1]) < getArg(atas[sza-1], points[i])){
            sza--;
        }
        atas[sza] = points[i]; sza++;
    }
    int idxa=1, idxb=1; szt=0;
    for(int i=1; i<n; i++){
        bool masuk = true;
        while(idxa<sza && atas[idxa] == points[i]){
            masuk = false; idxa++;
        }
        while(idxb<szb && bawah[idxb] == points[i]){
            masuk = false; idxb++;
        }
        if(masuk){
            tengah[szt] = points[i]; szt++;
        }
    }
    /*cout << "tengah:";
    for(int i=0; i<szt; i++){
        cout << " (" << tengah[i].first << "," << tengah[i].second << ")";
    } cout << endl << "bawah:"; 
    for(int i=0; i<szb; i++){
        cout << " (" << bawah[i].first << "," << bawah[i].second << ")";
    } cout << endl << "atas";
    for(int i=0; i<sza; i++){
        cout << " (" << atas[i].first << "," << atas[i].second << ")";
    } cout << endl;*/

    for(int i=sza-2; i>=0; i--){
        bawah[szb] = atas[i]; szb++;
    }

    ans = 1;
    for(int i=1; i<szb; i++){
        double arg = getArg(bawah[i-1], bawah[i]);
        for(int j=0; j<szt; j++){
            double angle = arg - getArg(tengah[j], bawah[i]);
            if(angle<0){
                angle += PI*2;
            }
            srt[j] = {angle, j};
        }
        sort(srt, srt + szt);
        ans += (szt>0);
        pll last = tengah[srt[0].second];
        for(int j=1; j<szt; j++){
            if(!isInside(last, bawah[i-1], bawah[i], tengah[srt[j].second])){
                last = tengah[srt[j].second]; ans++;
            }
        }
    }
    cout << ans << endl;
}
