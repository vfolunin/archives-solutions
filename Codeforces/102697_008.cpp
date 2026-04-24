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

    int size;
    cin >> size;

    double res = 0;
    for (int i = 0; i < size; i++) {
        double a, b;
        cin >> a >> b;

        res += (a - b) * (a - b);
    }

    cout.precision(10);
    cout << fixed << sqrt(res);
}