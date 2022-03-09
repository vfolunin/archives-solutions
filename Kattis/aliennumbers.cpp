#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve(int test) {
    string numA, langA, langB;
    cin >> numA >> langA >> langB;

    long long value = 0;
    for (char d : numA)
        value = value * langA.size() + langA.find(d);

    string numB;
    while (value >= langB.size()) {
        numB += langB[value % langB.size()];
        value /= langB.size();
    }
    numB += langB[value];
    reverse(numB.begin(), numB.end());

    cout << "Case #" << test << ": " << numB << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int test = 1; test <= n; test++)
        solve(test);
}