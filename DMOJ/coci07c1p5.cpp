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

    int size, targetMedian;
    cin >> size >> targetMedian;

    vector<int> a(size);
    for (int &value : a)
        cin >> value;

    int targetMedianPos = find(a.begin(), a.end(), targetMedian) - a.begin();

    map<int, int> left;
    int less = 0, greater = 0;
    for (int i = targetMedianPos; i >= 0; i--) {
        less += a[i] < targetMedian;
        greater += a[i] > targetMedian;
        left[less - greater]++;
    }

    map<int, int> right;
    less = greater = 0;
    for (int i = targetMedianPos; i < a.size(); i++) {
        less += a[i] < targetMedian;
        greater += a[i] > targetMedian;
        right[less - greater]++;
    }

    int res = 0;
    for (auto &[balance, count] : left)
        res += count * right[-balance];

    cout << res;
}