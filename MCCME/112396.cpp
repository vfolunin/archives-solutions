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

    vector<int> a;
    int value;

    while (cin >> value)
        a.push_back(value);

    stable_sort(a.begin(), a.end(), [](int lhs, int rhs) {
        return lhs % 10 < rhs % 10;
    });

    for (int value : a)
        cout << value << "\n";
}