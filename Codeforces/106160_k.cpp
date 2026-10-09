#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    double hAngle, mAngle;
    cin >> hAngle >> mAngle;

    hAngle -= mAngle / 12;
    if (hAngle < -1e-9) {
        cout << "no";
        return 0;
    }

    cout << (fmod(hAngle, 30) < 1e-9 ? "yes" : "no");
}