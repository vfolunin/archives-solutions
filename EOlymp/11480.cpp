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

    vector<int> r = a;
    for (int i = (int)r.size() - 2; i >= 0; i--)
        r[i] = max(r[i], r[i + 1]);

    long long res = 0;
    for (int i = 0; i < a.size(); i++)
        res += max(r[i] - a[i], 0);

    cout << res;
}