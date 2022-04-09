#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve(int test) {
    int letterLimit, keyCount, letterCount;
    cin >> letterLimit >> keyCount >> letterCount;

    vector<int> frequency(letterCount);
    for (int &f : frequency)
        cin >> f;

    sort(frequency.rbegin(), frequency.rend());

    long long res = 0;
    for (int i = 0; i < letterCount; i++)
        res += frequency[i] * (i / keyCount + 1);

    cout << "Case #" << test << ": " << res << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int test = 1; test <= n; test++)
        solve(test);
}