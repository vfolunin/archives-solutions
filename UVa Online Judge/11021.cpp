#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve(int test) {
    int childrenLimit, startCount, dayCount;
    cin >> childrenLimit >> startCount >> dayCount;

    vector<double> p(childrenLimit);
    for (double &p : p)
        cin >> p;

    vector<double> resP(dayCount + 1);
    for (int day = 1; day <= dayCount; day++)
        for (int children = 0; children < childrenLimit; children++)
            resP[day] += p[children] * pow(resP[day - 1], children);

    cout << "Case #" << test << ": ";
    cout.precision(7);
    cout << fixed << (startCount ? pow(resP.back(), startCount) : 0.0) << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int test = 1; test <= n; test++)
        solve(test);
}