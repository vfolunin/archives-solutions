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

    int aSize, bSize;
    cin >> aSize >> bSize;

    vector<int> a(aSize);
    for (int &value : a)
        cin >> value;
    sort(a.begin(), a.end());

    vector<int> b(bSize);
    for (int &value : b)
        cin >> value;
    sort(b.rbegin(), b.rend());

    long long res = 0;
    for (int i = 0; i < a.size() && i < b.size() && a[i] < b[i]; i++)
        res += b[i] - a[i];

    cout << res;
}