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

    unordered_set<int> used;
    unordered_map<int, int> factor;
    for (int i = 0; i < size; i++) {
        int value;
        cin >> value;

        while (used.count(++factor[value] * value));
        used.insert(factor[value] * value);

        cout << factor[value] * value << "\n";
    }
}