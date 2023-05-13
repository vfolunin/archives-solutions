#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void rec(int maxValue, int size, int value, vector<int> &subset) {
    if (subset.size() == size) {
        for (int value : subset)
            cout << value << " ";
        cout << "\n";
        return;
    }

    if (value > maxValue)
        return;

    subset.push_back(value);
    rec(maxValue, size, value + 1, subset);
    subset.pop_back();
    rec(maxValue, size, value + 1, subset);
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int maxValue, size;
    cin >> maxValue >> size;

    vector<int> subset;
    rec(maxValue, size, 1, subset);
}