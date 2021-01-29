#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve(int test) {
    int stackCount;
    cin >> stackCount;

    if (!stackCount)
        return 0;

    vector<int> stackSize(stackCount);
    int averageSize = 0;
    for (int &size : stackSize) {
        cin >> size;
        averageSize += size;
    }
    averageSize /= stackCount;

    int res = 0;
    for (int size : stackSize)
        res += max(0, size - averageSize);

    cout << "Set #" << test << "\nThe minimum number of moves is " << res << ".\n\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    for (int test = 1; solve(test); test++);
}