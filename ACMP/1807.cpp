#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

long long getTime(long long floorCount, long long tUp, long long tDown, long long tLift, long long liftFloor) {
    return max((liftFloor - 1) * tDown, (floorCount - liftFloor) * tUp) + liftFloor * tLift;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    long long floorCount, tUp, tDown, tLift;
    cin >> floorCount >> tUp >> tDown >> tLift;

    long long l = 1, r = floorCount;
    while (l + 10 < r) {
        long long m1 = l + (r - l) / 3;
        long long m2 = r - (r - l) / 3;
        
        long long t1 = getTime(floorCount, tUp, tDown, tLift, m1);
        long long t2 = getTime(floorCount, tUp, tDown, tLift, m2);

        if (t1 <= t2)
            r = m2;
        else
            l = m1;
    }

    long long resT = 9e18, res;
    for (long long m = l; m <= r; m++) {
        long long t = getTime(floorCount, tUp, tDown, tLift, m);
        if (resT > t) {
            resT = t;
            res = m;
        }
    }

    cout << res;
}