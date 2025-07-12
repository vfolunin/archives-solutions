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

    double value;
    long long size;
    cin >> value >> size;

    double res = value;
    for (int i = 0; i < size && i < 100; i++) {
        value /= 2;
        res += value;
    }

    cout << fixed << res;
}