#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool compare(int a, int b) {
    return a > b;
}

bool solve(int test) {
    vector<int> a;
    while (1) {
        int x;
        cin >> x;
        if (x != -1)
            a.push_back(x);
        else
            break;
    }

    if (a.empty())
        return 0;

    vector<int> last = { (int)1e9 };
    for (int x : a) {
        int pos = upper_bound(last.begin(), last.end(), x, compare) - last.begin();
        if (pos == last.size())
            last.emplace_back();
        last[pos] = x;
    }

    if (test > 1)
        cout << "\n";
    cout << "Test #" << test << ":\n";
    cout << "  maximum possible interceptions: " << last.size() - 1 << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    for (int test = 1; solve(test); test++);
}