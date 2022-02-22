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

    vector<int> values(size);
    for (int &value : values)
        cin >> value;

    set<int> left, right(values.begin(), values.end());
    int res = 0;
    for (int value : values) {
        left.insert(value);
        res += *--left.end() <= value && value <= *right.begin();
        right.erase(value);
    }

    cout << res;
}