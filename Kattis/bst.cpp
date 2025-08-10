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

    map<int, int> depth;
    long long res = 0;

    for (int i = 0; i < size; i++) {
        int value;
        cin >> value;

        auto it = depth.lower_bound(value);
        if (it != depth.begin())
            depth[value] = max(depth[value], prev(it)->second + 1);
        if (it != depth.end())
            depth[value] = max(depth[value], it->second + 1);
        
        res += depth[value];

        cout << res << "\n";
    }
}