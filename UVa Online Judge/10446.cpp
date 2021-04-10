#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

unsigned long long f(int n, int back) {
    if (n <= 0)
        return 1;

    static vector<vector<unsigned long long>> memo(70, vector<unsigned long long>(70));
    if (memo[n][back])
        return memo[n][back];

    if (n == 1)
        return memo[n][back] = 1;

    memo[n][back] = 1;
    for (int i = 1; i <= back; i++)
        memo[n][back] += f(n - i, back);

    return memo[n][back];
}

bool solve(int test) {
    int n, back;
    cin >> n >> back;

    if (n > 60)
        return 0;

    cout << "Case " << test << ": " << f(n, back) << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    for (int test = 1; solve(test); test++);
}