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

    int amount, size;
    cin >> amount >> size;

    for (int i = 0; i < size; i++) {
        int l, r;
        cin >> l >> r;

        cout << amount / (l + r) * 2 + (amount % (l + r) >= l) << " ";
    }
}