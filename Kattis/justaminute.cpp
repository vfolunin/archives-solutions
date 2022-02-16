#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int measureCount;
    cin >> measureCount;

    double num = 0, den = 0;
    for (int i = 0; i < measureCount; i++) {
        double min, sec;
        cin >> min >> sec;
        num += sec;
        den += min * 60;
    }

    if (num <= den + 1e-9) {
        cout << "measurement error";
    } else {
        cout.precision(8);
        cout << fixed << num / den;
    }
}