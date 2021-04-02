#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int rec(int count, int sum, int from) {
    if (count < 0 || count >= 27 || sum < 0 || sum >= 1000 || from >= 27)
        return 0;

    static vector<vector<vector<int>>> memo(27, vector<vector<int>>(1000, vector<int>(27, -1)));
    if (memo[count][sum][from] != -1)
        return memo[count][sum][from];

    if (count == 1)
        return memo[count][sum][from] = (from <= sum && sum <= 26);

    memo[count][sum][from] = 0;
    for (int last = from; last <= 26; last++)
        memo[count][sum][from] += rec(count - 1, sum - last, last + 1);
    return memo[count][sum][from];
}

bool solve(int test) {
    int count, sum;
    cin >> count >> sum;

    if (!count && !sum)
        return 0;

    cout << "Case " << test << ": " << rec(count, sum, 1) << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    for (int test = 1; solve(test); test++);
}