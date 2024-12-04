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

    int l, r, size;
    cin >> l >> r >> size;

    for (int i = l; i <= r; i++) {
        long long from = i * (i - 1LL) / 2 + 1;
        for (int j = 0; j < i && j < size; j++)
            cout << from + j << " ";
        cout << "\n";
    }
}