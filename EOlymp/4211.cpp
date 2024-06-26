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

    int len, size;
    cin >> len >> size;

    vector<int> a(size);
    for (int &value : a)
        cin >> value;

    sort(a.begin(), a.end());

    double res = (len + a.front() - a.back()) / 2.0;
    for (int i = 1; i < a.size(); i++)
        res = max(res, (a[i] - a[i - 1]) / 2.0);

    cout.precision(1);
    cout << fixed << res;
}