#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void rec(vector<int> &a, int i, int maxValue) {
    if (i == a.size()) {
        for (int value : a)
            cout << value << " ";
        cout << "\n";
        return;
    }

    for (a[i] = max(1, (int)a.size() - i); a[i] <= maxValue; a[i]++)
        rec(a, i + 1, a[i] - 1);
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int maxValue, size;
    cin >> maxValue >> size;

    vector<int> a(size);
    rec(a, 0, maxValue);
}