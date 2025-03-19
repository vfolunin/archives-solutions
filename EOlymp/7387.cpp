#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <unordered_map>
#include <string>
using namespace std;

bool solve(int test) {
    int size;
    cin >> size;

    if (!size)
        return 0;

    vector<string> a(size);
    unordered_map<string, int> pos;
    for (int i = 0; i < a.size(); i++) {
        cin >> a[i];
        pos[a[i]] = i;
    }

    sort(a.begin(), a.end());

    int res = 0;
    for (int i = 0; i < a.size(); i++)
        res += abs(i - pos[a[i]]);

    cout << "Site " << test << ": " << res << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    for (int test = 1; solve(test); test++);
}