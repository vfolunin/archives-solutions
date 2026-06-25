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

    int size, queryCount;
    cin >> size >> queryCount;

    vector<int> used(size);
    for (int i = 0; i < queryCount; i++) {
        int value;
        cin >> value;

        if (used[value % used.size()]) {
            cout << i + 1;
            return 0;
        }

        used[value % used.size()] = 1;
    }

    cout << -1;
}