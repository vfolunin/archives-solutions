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
    int maxCount = 0;
    for (int i = 0; i < size; i++) {
        int value;
        cin >> value;
        maxCount = max(maxCount, ++count[value]);
    }

    double average = 0;
    for (auto &[value, _] : count)
        average += value;
    average /= count.size();

    int res = -1;
    for (auto &[value, _] : count)
        if (res == -1 ||
            count[res] < count[value] ||
            count[res] == count[value] && abs(res - average) > abs(value - average) ||
            count[res] == count[value] && abs(res - average) == abs(value - average) && res > value)
            res = value;
    
    cout << res;
}