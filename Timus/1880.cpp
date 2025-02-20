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

    unordered_map<int, int> count;
    for (int i = 0; i < 3; i++) {
        int size;
        cin >> size;

        for (int j = 0; j < size; j++) {
            int value;
            cin >> value;

            count[value]++;
        }
    }

    int res = 0;
    for (auto &[value, count] : count)
        res += count == 3;

    cout << res;
}