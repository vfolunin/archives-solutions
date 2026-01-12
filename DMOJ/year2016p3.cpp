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

    int res = 0;
    for (int i = 0; i < a.size(); i++)
        for (int j = i + 1; j < a.size(); j++)
            if (binary_search(a.begin() + j + 1, a.end(), a[j] + a[j] - a[i]))
                res = max(res, a[j] * 3);

    cout << res;
}