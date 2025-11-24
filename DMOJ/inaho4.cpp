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

    vector<double> a(size);
    for (double &value : a)
        cin >> value;

    vector<double> b(size);
    for (double &value : b)
        cin >> value;

    double res = 0;
    for (int i = 0; i < a.size(); i++)
        res += (a[i] - b[i]) * (a[i] - b[i]);
    res = sqrt(res);

    cout << fixed << res;
}