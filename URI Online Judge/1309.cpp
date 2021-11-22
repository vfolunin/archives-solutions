#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    string a, b;
    if (!(cin >> a >> b))
        return 0;

    cout << "$";
    for (int i = 0; i < a.size(); i++) {
        cout << a[i];
        if (i + 1 < a.size() && (a.size() - i - 1) % 3 == 0)
            cout << ",";
    }
    cout << "." << string(2 - b.size(), '0') << b << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}