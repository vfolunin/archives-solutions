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

    int size;
    cin >> size;

    double res = 0;
    for (int i = 0; i < size; i++) {
        double value;
        cin >> value;

        res = max(res, abs(value));
    }

    cout.precision(2);
    cout << fixed << res;
}