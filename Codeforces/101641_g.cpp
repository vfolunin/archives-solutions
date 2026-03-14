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

    int size;
    cin >> size;

    unordered_map<int, int> count;
    for (int i = 0; i < size; i++) {
        int value;
        cin >> value;

        count[value]++;
    }

    vector<int> counts;
    for (auto &[value, count] : count)
        counts.push_back(count);

    sort(counts.begin(), counts.end());

    if (counts.back() <= size - counts.back() + 1)
        cout << size;
    else
        cout << (size - counts.back()) * 2 + 1;
}