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

    int type, size;
    cin >> type >> size;

    vector<int> a(size);
    for (int &value : a)
        cin >> value;

    vector<int> b(size);
    for (int &value : b)
        cin >> value;

    sort(a.begin(), a.end());
    if (type == 1)
        sort(b.begin(), b.end());
    else
        sort(b.rbegin(), b.rend());

    int res = 0;
    for (int i = 0; i < a.size(); i++)
        res += max(a[i], b[i]);

    cout << res;
}