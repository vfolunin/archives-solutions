#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

vector<int> prepare() {
    vector<int> first = { 0, 0, 1, 1, 2 };
    vector<int> total = { 0, 0, 1, 1, 3 };

    for (int i = 5; i <= 1e5; i++) {
        first.push_back(1 + first[i - 1]);
        total.push_back(first.back() + total[first.back()]);

        if (total.back() > 1 + first[i - 2] + total[1 + first[i - 2]]) {
            first.back() = 1 + first[i - 2];
            total.back() = first.back() + total[first.back()];
        }

        if (total.back() > 1 + first[i - 3] + total[1 + first[i - 3]]) {
            first.back() = 1 + first[i - 3];
            total.back() = first.back() + total[first.back()];
        }
    }

    return total;
}

bool solve() {
    int n;
    cin >> n;

    if (!n)
        return 0;

    static vector<int> rounds = prepare();

    cout << rounds[n] << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}