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

    vector<double> a(size);
    for (double &value : a)
        cin >> value;

    sort(a.begin(), a.end());

    double res = 1e9;
    for (int i = 1; i + 1 < a.size(); i++)
        res = min(res, (a[i + 1] - a[i - 1]) / 2);

    cout.precision(1);
    cout << fixed << res;
}