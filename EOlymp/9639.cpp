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

    vector<pair<int, int>> a(size);
    for (auto &[count, value] : a)
        cin >> count >> value;

    long long index;
    cin >> index;

    sort(a.begin(), a.end(), [](auto &lhs, auto &rhs) {
        return lhs.second < rhs.second;
    });

    for (auto &[count, value] : a) {
        if (index <= count) {
            cout << value;
            break;
        } else {
            index -= count;
        }
    }
}