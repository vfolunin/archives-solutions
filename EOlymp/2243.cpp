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
    sort(a.begin(), a.end());
    a.erase(unique(a.begin(), a.end()), a.end());

    vector<int> b(size);
    for (int &value : b)
        cin >> value;
    sort(b.begin(), b.end());
    b.erase(unique(b.begin(), b.end()), b.end());

    int res = 0;
    for (int value : a)
        res += binary_search(b.begin(), b.end(), value);

    cout << res;
}