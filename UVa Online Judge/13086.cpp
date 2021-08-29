#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve(int test) {
    int islandCount, smallIslandCount;
    cin >> islandCount >> smallIslandCount;

    long long a, b, c;
    cin >> a >> b >> c;

    vector<long long> population(islandCount);
    for (int i = 0; i < islandCount; i++)
        population[i] = (a * (i + 1) * (i + 1) + b * (i + 1) + c) % 1000007;

    cin >> a >> b >> c;

    vector<bool> isSmall(islandCount);
    for (int i = 0; i < smallIslandCount; i++)
        isSmall[(a * (i + 1) * (i + 1) + b * (i + 1) + c) % islandCount] = 1;

    int m = -1;
    for (int i = 0; i < islandCount; i++)
        if (!isSmall[i] && (m == -1 || population[m] > population[i]))
            m = i;

    long long res = 0;
    for (int i = 0; i < islandCount; i++)
        if (i != m)
            res += population[i] * population[m];

    cout << "Case " << test << ": " << res << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int test = 1; test <= n; test++)
        solve(test);
}