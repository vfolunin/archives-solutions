#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <unordered_map>
#include <string>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int threshold, size;
    cin >> threshold >> size;

    unordered_map<int, int> count;
    for (int i = 0; i < size; i++) {
        int value;
        cin >> value;
        count[value]++;
    }

    vector<int> res;
    for (auto &[value, count] : count)
        if (count >= threshold)
            res.push_back(value);

    cout << res.size() << "\n";
    for (int value : res)
        cout << value << " ";
}