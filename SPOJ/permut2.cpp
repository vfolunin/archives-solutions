#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    int size;
    cin >> size;

    if (!size)
        return 0;

    vector<int> p(size);
    for (int &x : p) {
        cin >> x;
        x--;
    }

    bool ambiguous = 1;
    for (int i = 0; i < size; i++)
        ambiguous &= p[p[i]] == i;

    cout << (ambiguous ? "ambiguous\n" : "not ambiguous\n");
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}