#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve(int test) {
    int n;
    if (!(cin >> n))
        return 0;

    vector<int> left;
    int sum = 0;
    for (int i = 1; sum + i <= n; i++) {
        left.push_back(i);
        sum += i;
    }
    left.back() += n - sum;

    cout << "Tower #" << test << "\n";

    for (int i = 0; i < left.size(); i++) {
        for (int j = 0; j < left[i]; j++) {
            cout << string(2 * (left.size() - 1 - i), ' ');
            cout << (j ? "#.." : "#**");
            cout << string(2 * i, '.');
            cout << string(2 * min<int>(i, left.size() - 2), '.');
            cout << (i + 1 == left.size() || j ? "..#\n" : "**#\n");
        }
    }

    cout << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    for (int test = 1; solve(test); test++);
}