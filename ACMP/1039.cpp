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

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int targetValue, size;
    cin >> targetValue >> size;

    map<int, int> count;
    for (int i = 0; i < size; i++) {
        int x;
        cin >> x;
        count[x]++;
    }

    int res = 0;
    for (auto &[value, count] : count)
        if (value <= targetValue && count >= 2)
            res = value;

    cout << res;
}