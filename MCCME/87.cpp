#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void rec(vector<int> &a, int i, int minValue, int maxValue) {
    if (i == a.size()) {
        for (int value : a)
            cout << value << " ";
        cout << "\n";
        return;
    }

    for (a[i] = minValue; a[i] + a.size() - 1 - i <= maxValue; a[i]++)
        rec(a, i + 1, a[i] + 1, maxValue);
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int maxValue, size;
    cin >> maxValue >> size;

    vector<int> a(size);
    rec(a, 0, 1, maxValue);
}