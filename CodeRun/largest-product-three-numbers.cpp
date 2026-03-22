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

    vector<int> a;
    int value;
    while (cin >> value)
        a.push_back(value);

    sort(a.begin(), a.end());

    if (1LL * a[0] * a[1] * a[a.size() - 1] > 1LL * a[a.size() - 3] * a[a.size() - 2] * a[a.size() - 1])
        cout << a[0] << " " << a[1] << " " << a[a.size() - 1];
    else
        cout << a[a.size() - 3] << " " << a[a.size() - 2] << " " << a[a.size() - 1];
}