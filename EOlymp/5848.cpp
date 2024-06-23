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

    vector<int> cost(size, 1e9);
    cost[0] = 0;
    vector<int> from(size, -1);

    for (int i = 1; i < cost.size(); i++) {
        cost[i] = cost[i - 1] + abs(a[i - 1] - a[i]);
        from[i] = i - 1;

        if (i >= 2 && cost[i] > cost[i - 2] + abs(a[i - 2] - a[i]) * 3) {
            cost[i] = cost[i - 2] + abs(a[i - 2] - a[i]) * 3;
            from[i] = i - 2;
        }
    }

    vector<int> path;
    for (int i = a.size() - 1; i != -1; i = from[i])
        path.push_back(i);
    reverse(path.begin(), path.end());

    cout << cost.back() << "\n" << path.size() << "\n";
    for (int i : path)
        cout << i + 1 << " ";
}