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

    int size;
    cin >> size;

    unordered_set<int> seen;
    for (int i = 0; i < size; i++) {
        int value;
        cin >> value;

        if (seen.count(value)) {
            cout << "NO";
            return 0;
        }

        seen.insert(value);
    }

    cout << "YES";
}