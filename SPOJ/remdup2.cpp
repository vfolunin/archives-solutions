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
    vector<int> res;

    for (int i = 0; i < size; i++) {
        int value;
        cin >> value;

        if (!seen.count(value))
            res.push_back(value);
        seen.insert(value);
    }

    for (int value : res)
        cout << value << " ";
    cout << "\n";
    for (int i = res.size() - 1; i >= 0; i--)
        cout << res[i] << " ";

}