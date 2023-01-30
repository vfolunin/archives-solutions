#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <string>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int size;
    cin >> size;

    vector<int> a(size);
    unordered_map<int, int> count;
    for (int &value : a) {
        cin >> value;
        count[value]++;
    }

    unordered_set<int> seen;
    for (int value : a) {
        if (count[value] > 1 && !seen.count(value)) {
            cout << value << " ";
            seen.insert(value);
        }
    }

    if (seen.empty())
        cout << 0;
}