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
    size++;

    vector<int> a(size);
    for (int i = 1; i < a.size(); i++)
        cin >> a[i];

    vector<int> maxCost(a.size());
    vector<int> from(a.size());
    for (int i = 1; i < a.size(); i++) {
        maxCost[i] = maxCost[i - 1] + a[i];
        from[i] = i - 1;

        if (i >= 2 && maxCost[i] < maxCost[i - 2] + a[i]) {
            maxCost[i] = maxCost[i - 2] + a[i];
            from[i] = i - 2;
        }
    }

    vector<int> path;
    for (int i = a.size() - 1; i; i = from[i])
        path.push_back(i);
    reverse(path.begin(), path.end());

    cout << maxCost.back() << "\n";
    for (int i : path)
        cout << i << " ";
}