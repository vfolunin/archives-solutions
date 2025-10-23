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

    int factor;
    cin >> factor;

    vector<string> a = { "*x*", " xx", "* *" };

    for (int y = 0; y < a.size() * factor; y++) {
        for (int x = 0; x < a.size() * factor; x++)
            cout << a[y / factor][x / factor];
        cout << "\n";
    }
}