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

    unordered_map<char, int> count, den = {
        { 'S', 6 }, { 'M', 8 }, { 'L', 12 }
    };
    for (int i = 0; i < size; i++) {
        char type;
        int value;
        cin >> type >> value;

        count[type] += value;
    }

    int res = 0;
    for (auto &[type, num] : count)
        res += (num + den[type] - 1) / den[type];

    cout << res;
}