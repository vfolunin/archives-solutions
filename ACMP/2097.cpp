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

    int size, divisor;
    cin >> size >> divisor;

    vector<int> a(size);
    for (int &value : a)
        cin >> value;

    int res1 = 0;
    sort(a.rbegin(), a.rend());
    for (int i = 0; i < a.size(); i++)
        res1 += i % divisor == divisor - 1 ? a[i] / 2 : a[i];

    int res2 = 0;
    reverse(a.begin(), a.end());
    for (int i = 0; i < a.size(); i++)
        res2 += i < a.size() / divisor ? a[i] / 2 : a[i];

    cout << res1 << " " << res2;
}