#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <map>
#include <string>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    unordered_map<int, int> count;
    for (int i = 0; i < 4; i++) {
        int value;
        cin >> value;

        if (value)
            count[value]++;
    }

    int res = 0;
    for (auto &[value, count] : count)
        res += count - 1;

    cout << res;
}