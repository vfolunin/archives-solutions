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

    int size, queryCount;
    cin >> size >> queryCount;

    vector<string> a(size);
    for (string &s : a)
        cin >> s;

    for (int i = 0; i < queryCount; i++) {
        int y, x;
        cin >> y >> x;

        cout << a[y - 1][x];
    }
}