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

    vector<int> marbles(marbleCount);
    for (int &marble : marbles)
        cin >> marble;
    sort(marbles.begin(), marbles.end());

    cout << "CASE# " << test << ":\n";

    for (int i = 0; i < queryCount; i++) {
        int marble;
        cin >> marble;

        auto [l, r] = equal_range(marbles.begin(), marbles.end(), marble);
        if (l != r)
            cout << marble << " found at " << l - marbles.begin() + 1 << "\n";
        else
            cout << marble << " not found\n";
    }

    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    for (int test = 1; solve(test); test++);
}