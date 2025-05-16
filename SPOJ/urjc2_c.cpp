#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    int size, limit;
    cin >> size >> limit;

    for (int i = 0; i < size; i++) {
        int value;
        cin >> value;

        if (value < limit)
            cout << "Yes, it blends!\n";
        else
            cout << "Well, it mostly blended\n";
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}