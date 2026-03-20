#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

struct TwoMap {
    map<int, int> l, r;
    int mid = 0;
    long long  lCount = 0, lSum = 0, rCount = 0, rSum = 0;

    void insert(int value) {
        if (value < mid) {
            l[value]++;
            lCount++;
            lSum += value;
        } else {
            r[value]++;
            rCount++;
            rSum += value;
        }
    }

    void incMid() {
        lCount += r[mid];
        lSum += r[mid] * mid;
        rCount -= r[mid];
        rSum -= r[mid] * mid;
        if (r[mid])
            l[mid] = r[mid];
        r.erase(mid);
        mid++;
    }

    void decMid() {
        rCount += l[mid];
        rSum += l[mid] * mid;
        lCount -= l[mid];
        lSum -= l[mid] * mid;
        if (l[mid])
            r[mid] = l[mid];
        l.erase(mid);
        mid--;
    }

    long long getDist() {
        return rSum - mid * rCount + mid * lCount - lSum;
    }
};

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int pointCount, moveCount;
    cin >> pointCount >> moveCount;

    TwoMap xs, ys;
    for (int i = 0; i < pointCount; i++) {
        int x, y;
        cin >> x >> y;

        xs.insert(x);
        ys.insert(y);
    }

    string moves;
    cin >> moves;

    for (char c : moves) {
        if (c == 'N')
            ys.incMid();
        else if (c == 'E')
            xs.incMid();
        else if (c == 'S')
            ys.decMid();
        else
            xs.decMid();

        cout << ys.getDist() + xs.getDist() << "\n";
    }
}