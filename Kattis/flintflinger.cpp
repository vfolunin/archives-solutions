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

    vector<double> x(size), y(size), radius(size);
    for (int i = 0; i < size; i++)
        cin >> x[i] >> y[i] >> radius[i];

    for (int i = 0; i < size; i++) {
        int res = 0;

        for (int j = 0; j < size; j++)
            res += i != j && hypot(x[i] - x[j], y[i] - y[j]) <= radius[j] + 1e-9;

        cout << res << "\n";
    }
}