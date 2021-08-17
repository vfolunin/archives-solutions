#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve(int test) {
    vector<int> count(7);
    int sum = 0;
    for (int i = 1; i <= 6; i++) {
        cin >> count[i];
        if (count[i] > 10)
            count[i] = 10 + count[i] % 2;
        sum += count[i] * i;
    }

    if (!sum)
        return 0;

    cout << "Collection #" << test << ":\n";

    if (sum % 2) {
        cout << "Can't be divided.\n\n";
        return 1;
    }
    
    int maxSum = sum / 2;

    vector<vector<int>> can(7, vector<int>(maxSum + 1));
    can[0][0] = 1;
    for (int i = 1; i <= 6; i++)
        for (int sum = 0; sum <= maxSum; sum++)
            for (int delta = 0; delta <= count[i] * i && delta <= sum; delta += i)
                can[i][sum] |= can[i - 1][sum - delta];
    
    cout << (can[6][maxSum] ? "Can" : "Can't") << " be divided.\n\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    for (int test = 1; solve(test); test++);
}