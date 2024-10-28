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

    int limit;
    cin >> limit;

    vector<pair<int, int>> a = { { 0, 0 } };
    for (int value; cin >> value && value != 2; ) {
        if (a.back().first == value)
            a.back().second++;
        else
            a.push_back({ value, 1 });
    }

    for (auto &[value, count] : a) {
        while (count > limit) {
            cout << limit << " 0 ";
            count -= limit;
        }
        cout << count << " ";
    }
}