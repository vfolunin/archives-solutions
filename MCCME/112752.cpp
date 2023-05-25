#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void rec(int i, vector<int> &a) {
    if (i == a.size()) {
        for (int value : a)
            cout << value << " ";
        cout << "\n";
        return;
    }

    for (a[i] = 1; a[i] <= i + 1; a[i]++)
        rec(i + 1, a);
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int size;
    cin >> size;

    vector<int> a(size);
    rec(0, a);
}