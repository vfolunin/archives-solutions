#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve(int test) {
    int marbleCount, queryCount;
    cin >> marbleCount >> queryCount;

    if (!marbleCount && !queryCount)
        return 0;

    vector<int> marble(marbleCount);
    for (int &x : marble)
        cin >> x;
    sort(marble.begin(), marble.end());

    map<int, int> indexOf;
    for (int i = marbleCount - 1; i >= 0; i--)
        indexOf[marble[i]] = i + 1;

    cout << "CASE# " << test << ":\n";
    for (int i = 0; i < queryCount; i++) {
        int x;
        cin >> x;
        if (indexOf.count(x))
            cout << x << " found at " << indexOf[x] << "\n";
        else
            cout << x << " not found\n";
    }
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    for (int test = 1; solve(test); test++);
}