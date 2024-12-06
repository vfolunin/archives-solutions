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

    int sum;
    cin >> sum;

    long long res = 0;
    for (auto &[a, countA] : count) {
        int b = sum - a;
        if (a < b && count.count(b))
            res += 1LL * countA * count[b];
        else if (a == b)
            res += countA * (countA - 1LL) / 2;
    }

    cout << res;
}