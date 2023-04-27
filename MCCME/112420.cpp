#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <numeric>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    vector<int> count(10);
    for (char c; cin >> c; )
        if (isdigit(c))
            count[c - '0']++;

    vector<int> digits(10);
    iota(digits.begin(), digits.end(), 0);
    stable_sort(digits.begin(), digits.end(), [&](int a, int b) {
        return count[a] < count[b];
    });

    for (int digit : digits)
        if (count[digit])
            cout << digit;
}