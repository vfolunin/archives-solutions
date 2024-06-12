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

    vector<int> a(3);
    int average = 0;

    for (int &value : a) {
        cin >> value;
        average += value;
    }

    if (average % a.size()) {
        cout << "IMPOSSIBLE";
        return 0;
    }

    average /= a.size();

    int res = 0;
    for (int value : a)
        res += max(value - average, 0);

    cout << res;
}