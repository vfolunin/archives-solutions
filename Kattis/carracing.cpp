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

    vector<pair<int, int>> fraction(5);
    for (int i = 0; i < size; i++) {
        int index, value;
        cin >> index >> value;
        index--;

        fraction[index].first += value;
        fraction[index].second++;
    }

    int index = min_element(fraction.begin(), fraction.end(), [](auto &a, auto &b) {
        return a.first * b.second < b.first * a.second;
    }) - fraction.begin();

    cout << index + 1 << "\n" << fraction[index].first / fraction[index].second;
}