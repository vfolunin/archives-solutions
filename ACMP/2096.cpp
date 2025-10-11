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

    int size, delta;
    cin >> size >> delta;

    vector<int> a(size);
    for (int &value : a)
        cin >> value;

    sort(a.rbegin(), a.rend());

    vector<int> ldsSize(a.size(), 1);
    for (int i = 1; i < a.size(); i++)
        for (int j = 0; j < i && a[j] - delta >= a[i]; j++)
            if (a[j] % 2 != a[i] % 2)
                ldsSize[i] = max(ldsSize[i], ldsSize[j] + 1);

    int res = max_element(ldsSize.begin(), ldsSize.end()) - ldsSize.begin();

    cout << ldsSize[res] << " " << a[res];
}