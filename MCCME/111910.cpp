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

    vector<int> b(size);
    for (int &value : b)
        cin >> value;

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    double res = 0;
    for (int i = 0; i < a.size(); i++)
        res += abs(a[i] - b[i]);
    res /= size;

    cout << fixed << res;
}