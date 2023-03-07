#include <bits/stdc++.h>
using namespace std;
#define pll pair<long long,long long>

const long long xmax = 1e9;

bool isColinear(pll p0, pll p1, pll p2){
    // (p2.y - p0.y)/(p2.x - p0.x) = (p1.y - p0.y)/(p1.x - p0.x)
    return (p2.second - p0.second) * (p1.first - p0.first)
        == (p2.first - p0.first) * (p1.second - p0.second);
}

bool isInLine(pll p0, pll p1, pll p2){
    return min(p0.first, p1.first) <= p2.first
        && p2.first <= max(p0.first, p1.first)
        && min(p0.second, p1.second) <= p2.second
        && p2.second <= max(p0.second, p1.second);
}

bool isParalel(pll p0, pll p1, pll p2, pll p3){
    // (p1.y-p0.y)/(p1.x-p0.x) == (p3.y-p2.y)/(p3.x-p2.x)
    return (p1.second-p0.second) * (p3.first-p2.first)
        == (p1.first-p0.first) * (p3.second-p2.second);
}

bool isBetween01(long long num, long long den){
    //cout << num << " " << den << endl;
    return (num == 0)
        || ((abs(num)/num == abs(den)/den)
        && abs(num) <= abs(den));
}

bool isIntersect (pll p0, pll p1, pll p2, pll p3){
    if(isParalel(p0, p1, p2, p3)){
        return (isColinear(p0, p1, p2) && isInLine(p0, p1, p2))
            || (isColinear(p0, p1, p3) && isInLine(p0, p1, p3))
            || (isColinear(p2, p3, p0) && isInLine(p2, p3, p0))
            || (isColinear(p2, p3, p1) && isInLine(p2, p3, p1));
    }else{
        long long tnum = (p0.first-p2.first)*(p2.second-p3.second) - (p0.second-p2.second)*(p2.first-p3.first);
        long long unum = (p0.first-p2.first)*(p0.second-p1.second) - (p0.second-p2.second)*(p0.first-p1.first);
        long long den = (p0.first-p1.first)*(p2.second-p3.second) - (p0.second-p1.second)*(p2.first-p3.first);
        //cout << tnum << " " << unum << " " << den << endl;
        return isBetween01(tnum, den) && isBetween01(unum, den);
    }
}

int isInside(vector<pll>& polygon, pll point){
    // Return -1 outside, 0 on line, 1 inside
    int sz = polygon.size();
    for(int i=0; i<sz; i++){
        if(isColinear(polygon[i], polygon[(i+1)%sz], point)
           && isInLine(polygon[i], polygon[(i+1)%sz], point)){
            return 0;
        }
    }
    // Dijamin point, farRight gada titik didalem garis ini
    pll farRight;
    farRight.first = point.first + 2*xmax + 1;
    farRight.second = point.second + 1;
    int toReturn = -1;
    for(int i=0; i<sz; i++){
        if(isIntersect(point, farRight, polygon[i], polygon[(i+1)%sz])){
            toReturn *= -1;
        }
    }
    return toReturn;
}

vector<pll> polygon;
pll point;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    long long n, m;
    cin >> n >> m;
    while(n--){
        cin >> point.first >> point.second;
        polygon.push_back(point);
    }
    while(m--){
        cin >> point.first >> point.second;
        int code = isInside(polygon, point);
        //cout << code << " ";
        if(code < 0){
            cout << "OUTSIDE" << endl;
        }else if(code > 0){
            cout << "INSIDE" << endl;
        }else{
            cout << "BOUNDARY" << endl;
        }
    }
}
