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

    for (a[i] = 1; a[i] <= maxValue; a[i]++)
        rec(a, i + 1, maxValue);
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int size, maxValue;
    cin >> size >> maxValue;

    vector<int> a(size);
    rec(a, 0, maxValue);
}