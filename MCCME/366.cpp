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

    int n;
    cin >> n;

    vector<int> wins(n + 1);
    wins[0] = 2;

    for (int i = 1; i <= n; i++) {
        if (i % 3 == 0 && (wins[i - 1] == 2 || i >= 2 && wins[i - 2] == 2) ||
            i % 3 == 1 && (wins[i - 1] == 2 || i >= 3 && wins[i - 3] == 2) ||
            i % 3 == 2 && (wins[i - 1] == 2 || i >= 2 && wins[i - 2] == 2 || i >= 3 && wins[i - 3] == 2))
            wins[i] = 1;
        else
            wins[i] = 2;
    }

    cout << wins[n];
}