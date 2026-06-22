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

    int size;
    cin >> size;

    vector<int> count(1e6 + 1);
    int res = 0;

    for (int i = 0; i < size; i++) {
        int value;
        cin >> value;

        res = max(res, ++count[value]);
        for (int multiple = value + value; multiple < count.size(); multiple += value)
            count[multiple] = max(count[multiple], count[value]);
    }

    cout << res;
}