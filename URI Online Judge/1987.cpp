#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    string num;
    if (!(cin >> num >> num))
        return 0;

    int sum = 0;
    for (char c : num)
        sum += c - '0';

    cout << sum << (sum % 3 ? " nao\n" : " sim\n");
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}