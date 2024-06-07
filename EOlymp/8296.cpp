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

    vector<int> a(size);
    int average = 0;

    for (int &value : a) {
        cin >> value;
        average += value;
    }

    if (average % a.size()) {
        cout << -1;
        return 0;
    }

    average /= a.size();
    int res = 0;

    for (int value : a)
        if (value > average)
            res += value - average;

    cout << res;
}