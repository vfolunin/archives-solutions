#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_set>
#include <map>
#include <string>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    unordered_set<int> values;
    for (int i = 0; i < 4; i++) {
        int value;
        cin >> value;

        values.insert(value);
    }

    cout << 4 - values.size();
}