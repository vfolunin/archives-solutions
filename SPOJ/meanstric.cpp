#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    int size;
    cin >> size;

    double sum = 0, product = 1, hSum = 0;
    for (int i = 0; i < size; i++) {
        double value;
        cin >> value;

        sum += value;
        product *= value;
        hSum += 1 / value;
    }

    cout.precision(9);
    cout << fixed << sum / size << " ";
    cout << fixed << pow(product, 1.0 / size) << " ";
    cout << fixed << size / hSum << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}