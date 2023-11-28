#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    int size;
    cin >> size;

    int sum = 0, maxValue = -1;
    vector<int> maxIndexes;

    for (int i = 0; i < size; i++) {
        int value;
        cin >> value;

        sum += value;
        if (maxValue < value) {
            maxValue = value;
            maxIndexes = { i };
        } else if (maxValue == value) {
            maxIndexes.push_back(i);
        }
    }

    if (maxIndexes.size() > 1)
        cout << "no winner\n";
    else if (maxValue * 2 > sum)
        cout << "majority winner " << maxIndexes[0] + 1 << "\n";
    else
        cout << "minority winner " << maxIndexes[0] + 1 << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}