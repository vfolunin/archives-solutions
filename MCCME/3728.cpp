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
    for (int &value : a)
        cin >> value;

    int queryCount;
    cin >> queryCount;

    for (int i = 0; i < queryCount; i++) {
        int value;
        cin >> value;

        auto [lIt, rIt] = equal_range(a.begin(), a.end(), value);
        cout << rIt - lIt << "\n";
    }
}