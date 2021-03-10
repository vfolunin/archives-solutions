#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve(int test) {
    int a, b;
    if (!(cin >> a >> b))
        return 0;

    map<int, int> frequency;
    int maxFrequency = 0;
    for (int i = 1; i <= a; i++) {
        for (int j = 1; j <= b; j++) {
            frequency[i + j]++;
            maxFrequency = max(maxFrequency, frequency[i + j]);
        }
    }

    if (test)
        cout << "\n";
    for (auto &[sum, freq] : frequency)
        if (freq == maxFrequency)
            cout << sum << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    for (int i = 0; solve(i); i++);
}