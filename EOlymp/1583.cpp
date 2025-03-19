#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    int percentage;
    if (!(cin >> percentage))
        return 0;

    double missProbability = 1 - percentage / 100.0;
    int res = 0;

    for (double probability = missProbability; probability > 0.5; probability *= missProbability)
        res++;

    cout << res << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}