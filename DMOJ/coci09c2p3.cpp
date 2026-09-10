#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <numeric>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int angleCount, queryCount;
    cin >> angleCount >> queryCount;

    int angleGcd = 360;

    for (int i = 0; i < angleCount; i++) {
        int angle;
        cin >> angle;
        angleGcd = gcd(angleGcd, angle);
    }

    for (int i = 0; i < queryCount; i++) {
        int angle;
        cin >> angle;
        cout << (angle % angleGcd == 0 ? "YES\n" : "NO\n");
    }
}