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

    double distance, speedA;
    cin >> distance >> speedA;

    double res = 0;
    for (int i = 0; i < 3; i++) {
        double speedB;
        cin >> speedB;

        double time = distance / (speedA + speedB);
        res += time * speedB * 2;
    }

    cout << (int)round(res);
}