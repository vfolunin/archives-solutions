#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    int test, size;
    cin >> test >> size;

    vector<int> values(size);
    for (int &value : values)
        cin >> value;

    vector<int> sortedValues = values;
    sort(sortedValues.begin(), sortedValues.end());

    int commonCount = 0;
    for (int value : values)
        commonCount += value == sortedValues[commonCount];

    cout << test << " " << size - commonCount << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}