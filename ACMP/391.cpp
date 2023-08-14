#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool rec(int base, int mod, int targetSum, string &s, int factor, int sum) {
    if (sum == targetSum)
        return 1;

    if (s.size() == 4)
        return 0;

    s.push_back('0');
    for (; s.back() <= '9'; s.back()++)
        if (rec(base, mod, targetSum, s, factor * base % mod, (sum + (s.back() - '0') * factor) % mod))
            return 1;

    s.pop_back();
    return 0;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int base, mod, size, targetSum;
    cin >> base >> mod >> size >> targetSum;

    string s;
    rec(base, mod, targetSum, s, 1, 0);

    cout << s << string(size - s.size(), '0');
}