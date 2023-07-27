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

    vector<int> a(size);
    for (int &value : a)
        cin >> value;

    double res = 0;
    for (int i = 0; i + 1 < a.size(); i++)
        res += (a[i] + a[i + 1]) / 2.0;
    res /= a.size() - 1;

    cout << fixed << res;
}