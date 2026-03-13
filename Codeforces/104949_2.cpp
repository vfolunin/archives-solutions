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

    vector<int> l(a.size(), 1);
    for (int i = 1; i < a.size(); i++)
        if (a[i - 1] < a[i])
            l[i] += l[i - 1];

    vector<int> r(a.size(), 1);
    for (int i = (int)a.size() - 2; i >= 0; i--)
        if (a[i] > a[i + 1])
            r[i] += r[i + 1];

    long long res = 0;
    for (int i = 0; i < a.size(); i++)
        res += 1LL * l[i] * r[i];

    cout << res;
}