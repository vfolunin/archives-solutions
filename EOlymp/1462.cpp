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

    sort(a.begin(), a.end(), [](int lhs, int rhs) {
        if (lhs % 10 != rhs % 10)
            return lhs % 10 < rhs % 10;
        return lhs < rhs;
    });

    for (int value : a)
        cout << value << " ";
}