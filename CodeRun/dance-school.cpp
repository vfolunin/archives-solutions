#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <unordered_map>
#include <string>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    string s;
    cin >> s >> s;

    unordered_map<int, int> seen = { { 0, 1 } };
    int balance = 0;
    long long res = 0;

    for (char c : s) {
        if (c == 'a')
            balance++;
        else
            balance--;

        res += seen[balance];
        seen[balance]++;
    }

    cout << res;
}