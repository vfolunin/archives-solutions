#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    vector<int> starCount;
    while (1) {
        string line;
        if (!getline(cin, line) || line.empty())
            break;
        starCount.push_back(count(line.begin(), line.end(), '*'));
    }

    if (starCount.empty())
        return 0;

    int left = 0, right = 0;
    for (int count : starCount)
        left += count;

    for (int count : starCount) {
        left -= count;
        cout << string(left, '.') << string(count, '*') << string(right, '.') << "\n";
        right += count;
    }

    cout << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}