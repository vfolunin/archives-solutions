#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    int n;
    cin >> n;

    if (!n)
        return 0;

    unsigned long long sum = 0;
    vector<int> count(10);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        sum += x;
        count[x]++;
    }

    vector<unsigned long long> fact(13);
    fact[0] = 1;
    for (int i = 1; i < fact.size(); i++)
        fact[i] = fact[i - 1] * i;

    unsigned long long permutationCount = fact[n];
    for (int i = 0; i < 10; i++)
        permutationCount /= fact[count[i]];

    unsigned long long base = 0;
    for (int i = 0; i < n; i++)
        base = base * 10 + 1;

    cout << sum * permutationCount / n * base << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}