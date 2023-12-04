#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int size;
    cin >> size;

    map<int, int> count;
    for (int i = 0; i < size; i++) {
        int value;
        cin >> value;
        count[value]++;
    }

    for (auto l = count.begin(), r = next(count.begin()); r != count.end(); l++, r++)
        if (l->first + 1 == r->first)
            l->second += r->second;

    int res = 0;
    for (auto &[value, count] : count)
        res = max(res, count);

    cout << res;
}