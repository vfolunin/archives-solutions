#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool isPalindrome(string &s, int l, int r) {
    for ( ; l < r; l++, r--)
        if (s[l] != s[r])
            return 0;
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    string s;
    cin >> s;

    vector<int> res(s.size() + 1, 1e9);
    res[0] = 0;

    for (int size = 1; size <= s.size(); size++)
        for (int partSize = 1; partSize <= size; partSize++)
            if (isPalindrome(s, size - partSize, size - 1))
                res[size] = min(res[size], res[size - partSize] + 1);

    cout << res.back() - 1;
}