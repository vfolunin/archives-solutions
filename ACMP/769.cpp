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

    vector<string> a(size);
    for (string &s : a)
        cin >> s;

    sort(a.begin(), a.end());

    int res = 1;
    for (int i = 1; i < a.size(); i++)
        res += a[i - 1].size() > a[i].size() || a[i - 1] != a[i].substr(0, a[i - 1].size());

    cout << res;
}