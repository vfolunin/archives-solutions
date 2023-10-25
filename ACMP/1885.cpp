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

    map<int, int> seen;
    set<int> res;

    for (int i = 0; i < size; i++) {
        int value;
        cin >> value;

        if (size == 1 || seen.count(value) && i - seen[value] <= 2)
            res.insert(value);

        seen[value] = i;
    }

    cout << res.size() << "\n";
    for (int value : res)
        cout << value << " ";
}