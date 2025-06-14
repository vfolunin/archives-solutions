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
    long long res = 0;

    for (int i = 0; i < size; i++) {
        int value;
        cin >> value;

        if (auto it = count.find(2022 - value); it != count.end())
            res += it->second;

        count[value]++;
    }

    cout << res;
}