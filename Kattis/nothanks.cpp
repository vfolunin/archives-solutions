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

    int res = a[0];
    for (int i = 1; i < a.size(); i++)
        if (a[i - 1] + 1 != a[i])
            res += a[i];

    cout << res;
}