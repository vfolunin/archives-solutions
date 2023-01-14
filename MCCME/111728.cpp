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

    int size, queryCount;
    cin >> size >> queryCount;

    vector<int> a(size);
    for (int &value : a)
        cin >> value;

    for (int i = 0; i < queryCount; i++) {
        int value;
        cin >> value;

        auto [lIt, rIt] = equal_range(a.begin(), a.end(), value);
        if (lIt != rIt)
            cout << lIt - a.begin() + 1 << " " << rIt - a.begin() << "\n";
        else
            cout << "0\n";
    }
}