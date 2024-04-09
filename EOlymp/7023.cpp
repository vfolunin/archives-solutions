#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    int size, queryCount;
    cin >> size >> queryCount;

    if (!size)
        return 0;

    vector<int> a(size);
    for (int i = 0; i < size; i++)
        a[i] = size - i;

    for (int i = 0; i < queryCount; i++) {
        int from, count;
        cin >> from >> count;
        from--;

        reverse(a.begin(), a.begin() + from + count);
        reverse(a.begin(), a.begin() + count);
        reverse(a.begin() + count, a.begin() + from + count);
    }

    cout << a[0] << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}