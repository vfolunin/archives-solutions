#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve(int test) {
    int doorCount, memSize;
    cin >> doorCount >> memSize;

    double aDoorCount = 0, aDoorSum = 0;
    double bDoorCount = 0, bDoorSum = 0;

    for (int i = 0; i < doorCount; i++) {
        double d;
        cin >> d;

        if (d > 0) {
            aDoorCount++;
            aDoorSum += d;
        } else {
            bDoorCount++;
            bDoorSum -= d;
        }
    }

    if (!aDoorCount) {
        cout << "Case " << test << ": -1.000\n";
        return;
    }

    vector<double> res(memSize + 1);
    res[0] = (aDoorSum + bDoorSum) / aDoorCount;
    double num = bDoorSum, den = doorCount * aDoorCount;

    for (int i = 1; i <= memSize; i++) {
        res[i] = res[i - 1] - num / den;
        num *= bDoorCount - i;
        den *= doorCount - i;
    }

    cout.precision(3);
    cout << "Case " << test << ": " << fixed << res.back() << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int test = 1; test <= n; test++)
        solve(test);
}