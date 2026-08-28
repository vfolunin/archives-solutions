#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve(int test) {
    vector<int> weight = { 1, 2, 3, 3, 4, 10, -1, -2, -2, -2, -3, -5, -10 };
    int sum = 0;

    for (int &weight : weight) {
        int count;
        cin >> count;
        sum += weight * count;
    }

    cout << "Battle " << test << ": ";
    if (sum > 0)
        cout << "Good triumphs over Evil\n";
    else if (sum == 0)
        cout << "No victor on this battle field\n";
    else
        cout << "Evil eradicates all trace of Good\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int testCount;
    cin >> testCount;

    for (int test = 1; test <= testCount; test++)
        solve(test);
}