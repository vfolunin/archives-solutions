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

    int size, target;
    cin >> size >> target;

    vector<double> a(size);
    for (double &value : a)
        cin >> value;

    double cur = 0;
    for (double value : a)
        cur += value * value / a.size();

    for (double value : a)
        cout << fixed << (cur ? value * sqrt(target / cur) : 0) << " ";
}